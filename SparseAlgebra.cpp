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
        return _entries.find(i)->second;

    }

    double &operator[](int i) override {
        if (i >= _numElements) throw std::out_of_range("Exceeded number of columns");
        return _entries.find(i)->second;
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
        return _entries.find(i)->second;
    }

    double &operator[](int i) override {
        if (i >= _numElements)
            throw std::out_of_range("Exceeded number of rows");
        return _entries.find(i)->second;
    }
};*/

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


