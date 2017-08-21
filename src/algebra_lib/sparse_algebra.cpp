//
// Created by Lars Gebraad on 14-8-17.
//

#include <iostream>
#include "sparse_algebra.hpp"

// --- Algebra functions
namespace algebra_lib {



/// \todo Create non-zero column index in SparseMatrix to speed up the iterations here, possibly during reference access.
    SparseMatrix operator*(const SparseMatrix &A, const SparseMatrix &B) {

        if (A._columns != B._rows) {
            throw std::length_error("matrix multiplication: matrices are not compatible in dimension");
        }

        SparseMatrix P(A._rows, B._columns);
        for (int columnB = 0; columnB < B._columns; ++columnB) {
            SparseVector p = A * B.GetSparseColumn(columnB);
            for (auto pi : p._vectorMap) {
                if (pi.second != 0) {
                    P[pi.first][columnB] = pi.second;
                }
            }
        }
        return P;
    }

    SparseVector operator*(const SparseMatrix &A, const SparseVector &U) {
        if (A._columns != U._numElements) {
            throw std::length_error(
                    "Left multiplication with matrix: vector and matrix are not compatible in dimension");
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
        for (auto const &entryU : U._vectorMap) {
            auto lookup = V._vectorMap.find(entryU.first);
            if (lookup != V._vectorMap.end()) {
                sum += entryU.second * lookup->second;
            }
        }
        return sum;
    }

    SparseVector operator+(const SparseVector &U, const SparseVector &V) {
        if (U._numElements != V._numElements) throw std::length_error("Vectors are not the same dimension");
        SparseVector S = U;
        for (auto const &entryV : V._vectorMap) {
            S[entryV.first] += entryV.second;
        }
        return S;
    }

    SparseVector operator-(const SparseVector &U, const SparseVector &V) {
        if (U._numElements != V._numElements) throw std::length_error("Vectors are not the same dimension");
        SparseVector S = U;
        for (auto const &entryV : V._vectorMap) {
            S[entryV.first] -= entryV.second;
        }
        return S;
    }

    SparseVector operator*(const SparseVector &U, const double m) {
        SparseVector V = U;
        for (std::pair<const int, double> &entry : V._vectorMap) {
            entry.second = entry.second / m;
        }
        return V;
    }

    SparseVector operator*(const double m, const SparseVector &U) {
        return U * m;
    }

    SparseVector operator/(const SparseVector &U, const double m) {
        SparseVector V = U;
        for (std::pair<const int, double> &entry : V._vectorMap) {
            entry.second = entry.second / m;
        }
        return V;
    }

    std::ostream &operator<<(std::ostream &stream, const SparseVector &SparseVector) {
        stream << "Sparse " << (SparseVector._isColumn ? "column" : "row") << " vector of dimension "
               << SparseVector._numElements
               << ", displaying non-zero elements (zero-based indices):"
               << std::endl;
        for (auto const &entry : SparseVector._vectorMap) {
            stream << "\tElement " << entry.first << ": " << entry.second << std::endl;
        }
        return stream;
    }

    std::ostream &operator<<(std::ostream &stream, const SparseMatrix &SparseMatrix) {
        stream << "Sparse matrix of dimension " << SparseMatrix._rows << "x" << SparseMatrix._columns
               << ", displaying non-zero elements (zero-based indices):"
               << std::endl;
        for (auto const &row : SparseMatrix._matrixMap) {
            for (auto const &entry: row.second._vectorMap) {
                stream << "\tElement [" << row.first << "," << entry.first << "]: " << entry.second << std::endl;
            }
        }
        return stream;
    }

}