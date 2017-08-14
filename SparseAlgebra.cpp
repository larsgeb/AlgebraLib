//
// Created by lars on 14-8-17.
//

#include "SparseAlgebra.hpp"
#include <thread>
#include <vector>
#include <future>
#include <algorithm>
// --- SparseVector class ---

SparseVector::SparseVector() {
    _numElements = 0;
};

SparseVector::SparseVector(int columns) {
    _numElements = columns;
};

/*const double operator[](int i) const {
    if (i >= _numElements)
        throw std::out_of_range("Exceeded number of elements");

    const std::map<int, double>::const_iterator lookup = _entries.find(i);

    if (lookup != _entries.end()) {
        return lookup->second;
    }
    return 0;
}*/

double &SparseVector::operator[](int i) {
    if (i < 0) {
        throw std::out_of_range("Exceeded natural range for indices");
    } else if (i >= _numElements)
        throw std::out_of_range("Exceeded number of elements");

    // Try to find current key in sparse vector, if it does not exist, we get iterator at end of map.
    const std::map<int, double>::iterator &lookup = _entries.find(i);
    if (lookup != _entries.end()) {
        return lookup->second;
    }
    return _entries[i];

}

double &SparseVector::operator()(int i) {
    if (i < 1) {
        throw std::out_of_range("Exceeded natural range for indices");
    } else if (i > _numElements)
        throw std::out_of_range("Exceeded number of elements");

    // Try to find current key in sparse vector, if it does not exist, we get iterator at end of map.
    const std::map<int, double>::iterator &lookup = _entries.find(i - 1);
    if (lookup != _entries.end()) {
        return lookup->second;
    }
    return _entries[i - 1];

}

// --- end of class ---

//class SparseRow : public SparseVector {
//public:
//    SparseRow() {
//        _numElements = 0;
//    }
//
//    explicit SparseRow(int numColumns) {
//        _numElements = numColumns;
//    }
//
//    const double operator[](int i) const override {
//        if (i >= _numElements)
//            throw std::out_of_range("Exceeded number of columns");
//        return _entries.find(i)->second;
//
//    }
//
//    double &operator[](int i) override {
//        if (i >= _numElements) throw std::out_of_range("Exceeded number of columns");
//        return _entries.find(i)->second;
//    }
//};

//class SparseColumn : public SparseVector {
//public:
//    SparseColumn() {
//        _numElements = 0;
//    }
//
//    explicit SparseColumn(int numRows) {
//        _numElements = numRows;
//    }
//
//    const double operator[](int i) const override {
//        if (i >= _numElements)
//            throw std::out_of_range("Exceeded number of rows");
//        return _entries.find(i)->second;
//    }
//
//    double &operator[](int i) override {
//        if (i >= _numElements)
//            throw std::out_of_range("Exceeded number of rows");
//        return _entries.find(i)->second;
//    }
//};

// --- SparseMatrix class ---

SparseMatrix::SparseMatrix(int rows, int columns) {
    _rows = rows;
    _columns = columns;
}

/*const SparseVector operator[](int i) const {
    *//*
         * Because std::maps []-operator is not declared as const, this alternative is used.
         * Of course, stack overflow helps:
         * https://stackoverflow.com/questions/262853/c-map-access-discards-qualifiers-const
         *//*
        if (i >= _rows) throw std::out_of_range("Exceeded number of rows");

        return _M.find(i)->second;
    }

    const SparseVector operator()(int i) const {
        if (i > _rows) throw std::out_of_range("Exceeded number of rows");

        return _M.find(i - 1)->second;
    }*/

SparseVector &SparseMatrix::operator[](int i) {
    // Check if within matrix size
    if (i < 0) {
        throw std::out_of_range("Exceeded natural range for indices");
    } else if (i >= _rows) {
        throw std::out_of_range("Exceeded number of rows");
    }

    // Does the sparse row already contain something?
    if (_M.find(i) == _M.end())
        // If not, make empty row.
        _M[i] = SparseVector(_columns);

    _M[i]._numElements = _columns;
    return _M[i];
}

SparseVector &SparseMatrix::operator()(int i) {
    if (i < 1) {
        throw std::out_of_range("Exceeded natural range for indices");
    } else if (i > _rows) {
        throw std::out_of_range("Exceeded number of rows");
    }

    if (_M.find(i - 1) == _M.end())
        _M[i - 1] = SparseVector(_columns);

    _M[i - 1]._numElements = _columns;
    return _M[i - 1];
}


int SparseMatrix::GetRows() { return _rows; }

int SparseMatrix::GetColumns() { return _columns; }

// --- end of class ---

// --- Algebra functions

SparseMatrix MatrixMultiplication(const SparseMatrix &A, const SparseMatrix &B) {

}

SparseVector operator*(const SparseMatrix &A, const SparseVector &U) {
    if (A._columns != U._numElements) {
        throw std::length_error("Vector and matrix are not compatible in dimension");
    }
    SparseVector P(A._rows);

    for (auto const &rowA : A._M) {
        P[rowA.first] = rowA.second * U;
    }
    return P;
}

SparseVector ParallelMatrixVector(const SparseMatrix &A, const SparseVector &U) {
    if (A._columns != U._numElements) {
        throw std::length_error("Vector and matrix are not compatible in dimension");
    }
    SparseVector P(A._rows);

    std::vector<std::thread> workers;
    int j = 0;
    for (auto const &rowM : A._M) {
        workers.emplace_back(std::thread([](int i, const SparseVector &row, const SparseVector &rhs, double &pElement) {
            pElement = row * rhs;
        }, j++, std::ref(rowM.second), std::ref(U), std::ref(P[rowM.first])));
    }
    std::cout << "Main thread!" << std::endl;
    for (std::thread &e : workers) {
        e.join();
    }

    return P;
}

double operator*(const SparseVector &U, const SparseVector &V) {
    if (U._numElements != V._numElements) throw std::length_error("Vectors are not the same dimension");
    double sum = 0.0;
    for (auto const &entryU : U._entries) {
        auto lookup = V._entries.find(entryU.first);
        if (lookup != V._entries.end()) {
            sum += entryU.second * lookup->second;
        }
    }
    return sum;
}

SparseVector operator+(const SparseVector &U, const SparseVector &V) {
    if (U._numElements != V._numElements) throw std::length_error("Vectors are not the same dimension");
    SparseVector S = U;
    for (auto const &entryV : V._entries) {
        S[entryV.first] += entryV.second;
    }
    return S;
}

SparseVector operator-(const SparseVector &U, const SparseVector &V) {
    if (U._numElements != V._numElements) throw std::length_error("Vectors are not the same dimension");
    SparseVector S = U;
    for (auto const &entryV : V._entries) {
        S[entryV.first] -= entryV.second;
    }
    return S;
}

SparseVector operator*(const SparseVector &U, const double m) {
    SparseVector V = U;
    for (std::pair<const int, double> &entry : V._entries) {
        entry.second = entry.second / m;
    }
    return V;
}

SparseVector operator*(const double m, const SparseVector &U) {
    return U * m;
}

SparseVector operator/(const SparseVector &U, const double m) {
    SparseVector V = U;
    for (std::pair<const int, double> &entry : V._entries) {
        entry.second = entry.second / m;
    }
    return V;
}

std::ostream &operator<<(std::ostream &stream, const SparseVector &SparseVector) {
    stream << "Sparse vector of dimension " << SparseVector._numElements
           << ", displaying non-zero elements (zero-based indices):"
           << std::endl;
    for (auto const &entry : SparseVector._entries) {
        stream << "\tElement " << entry.first << ": " << entry.second << std::endl;
    }
    return stream;
}


