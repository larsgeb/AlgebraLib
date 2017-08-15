//
// Created by Lars Gebraad on 14-8-17.
//

#include "SparseAlgebra.hpp"
#include <vector>
#include <algorithm>

/*class SparseRow : public SparseVector {
public:
    SparseRow() {
        _numElements = 0;
    }

    explicit SparseRow(int numColumns) {
        _numElements = numColumns;
    }

    const double operator[](int i) const override {
        if (i >= _numElements)
            throw std::out_of_range("Exceeded number of columns");
        return vectorMap.find(i)->second;

    }

    double &operator[](int i) override {
        if (i >= _numElements) throw std::out_of_range("Exceeded number of columns");
        return vectorMap.find(i)->second;
    }
};

class SparseColumn : public SparseVector {
public:
    SparseColumn() {
        _numElements = 0;
    }

    explicit SparseColumn(int numRows) {
        _numElements = numRows;
    }

    const double operator[](int i) const override {
        if (i >= _numElements)
            throw std::out_of_range("Exceeded number of rows");
        return vectorMap.find(i)->second;
    }

    double &operator[](int i) override {
        if (i >= _numElements)
            throw std::out_of_range("Exceeded number of rows");
        return vectorMap.find(i)->second;
    }
};*/

// --- Algebra functions

SparseMatrix operator*(const SparseMatrix &A, const SparseMatrix &B) {

    if (A._columns != B._rows) {
        throw std::length_error("Matrix multiplication: matrices are not compatible in dimension");
    }

    SparseMatrix P(A._rows, B._columns);
    for (int columnB = 0; columnB < B._columns; ++columnB) {
        SparseVector p = A * B.GetSparseColumn(columnB);
        for (auto pi : p.vectorMap) {
            if (pi.second != 0) {
                P[pi.first][columnB] = pi.second;
            }
        }
    }
    return P;
}

SparseVector operator*(const SparseMatrix &A, const SparseVector &U) {
    if (A._columns != U._numElements) {
        throw std::length_error("Left multiplication with matrix: vector and matrix are not compatible in dimension");
    } else if (!U._isColumn) {
        throw std::invalid_argument(
                "Left multiplication with matrix: vector is not a column vector! First transpose it for goodness' sake.");
    }
    SparseVector P(A._rows);

    for (auto const &rowA : A._matrixMap) {
        double result = rowA.second * U;
        if (result != 0)
            P[rowA.first] = result;
    }
    P._numElements = A._rows;
    return P;
}

double operator*(const SparseVector &U, const SparseVector &V) {
    if (U._numElements != V._numElements) throw std::length_error("Vectors are not the same dimension");
    double sum = 0.0;
    for (auto const &entryU : U.vectorMap) {
        auto lookup = V.vectorMap.find(entryU.first);
        if (lookup != V.vectorMap.end()) {
            sum += entryU.second * lookup->second;
        }
    }
    return sum;
}

SparseVector operator+(const SparseVector &U, const SparseVector &V) {
    if (U._numElements != V._numElements) throw std::length_error("Vectors are not the same dimension");
    SparseVector S = U;
    for (auto const &entryV : V.vectorMap) {
        S[entryV.first] += entryV.second;
    }
    return S;
}

SparseVector operator-(const SparseVector &U, const SparseVector &V) {
    if (U._numElements != V._numElements) throw std::length_error("Vectors are not the same dimension");
    SparseVector S = U;
    for (auto const &entryV : V.vectorMap) {
        S[entryV.first] -= entryV.second;
    }
    return S;
}

SparseVector operator*(const SparseVector &U, const double m) {
    SparseVector V = U;
    for (std::pair<const int, double> &entry : V.vectorMap) {
        entry.second = entry.second / m;
    }
    return V;
}

SparseVector operator*(const double m, const SparseVector &U) {
    return U * m;
}

SparseVector operator/(const SparseVector &U, const double m) {
    SparseVector V = U;
    for (std::pair<const int, double> &entry : V.vectorMap) {
        entry.second = entry.second / m;
    }
    return V;
}

std::ostream &operator<<(std::ostream &stream, const SparseVector &SparseVector) {
    stream << "Sparse " << (SparseVector._isColumn ? "column" : "row") << " vector of dimension " << SparseVector._numElements
           << ", displaying non-zero elements (zero-based indices):"
           << std::endl;
    for (auto const &entry : SparseVector.vectorMap) {
        stream << "\tElement " << entry.first << ": " << entry.second << std::endl;
    }
    return stream;
}

std::ostream &operator<<(std::ostream &stream, const SparseMatrix &SparseMatrix) {
    stream << "Sparse Matrix of dimension " << SparseMatrix._rows << "x" << SparseMatrix._columns
           << ", displaying non-zero elements (zero-based indices):"
           << std::endl;
    for (auto const &row : SparseMatrix._matrixMap) {
        for (auto const &entry: row.second.vectorMap) {
            stream << "\tElement [" << row.first << "," << entry.first << "]: " << entry.second << std::endl;
        }
    }
    return stream;
}

