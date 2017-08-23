//
// Created by Lars Gebraad on 14-8-17.
//

#include <iostream>
#include <iomanip>
#include "sparse_algebra.hpp"

// --- Algebra functions
namespace algebra_lib {

    sparse_matrix operator*(const sparse_matrix &A, const sparse_matrix &B) {

        if (A.columns() != B.rows()) {
            throw std::length_error("Matrix multiplication: matrices are not compatible in dimension");
        }

        sparse_matrix P(A.rows(), B.columns());
        for (int columnB = 0; columnB < B.columns(); ++columnB) {
            sparse_vector p = A * B.GetSparseColumn(columnB);
            for (auto pi : p._vectorMap) {
                if (pi.second != 0) {
                    P(pi.first)(columnB) = pi.second;
                }
            }
        }
        return P;
    }

    sparse_vector operator*(const sparse_matrix &A, const sparse_vector &U) {
        if (A.columns() != U.size()) {
            throw std::length_error(
                    "Left multiplication with matrix: vector and matrix are not compatible in dimension");
        } else if (!U._isColumn) {
            throw std::invalid_argument(
                    "Left multiplication with matrix: vector is not a column vector! First transpose it for goodness' sake.");
        }
        sparse_vector P(A.rows(), true);

        for (auto const &rowA : A) {
            double result = rowA.second * U;
            if (result != 0)
                P(rowA.first) = result;
        }
        // P.elements() = A._rows; // todo look at this (should be okay I think, requires testing).
        return P;
    }

    double operator*(const sparse_vector &U, const sparse_vector &V) {
        if (U.size() != V.size()) throw std::length_error("Vectors are not the same dimension");
        double sum = 0.0;
        for (auto const &entryU : U._vectorMap) {
            auto lookup = V._vectorMap.find(entryU.first);
            if (lookup != V._vectorMap.end()) {
                sum += entryU.second * lookup->second;
            }
        }
        return sum;
    }

    sparse_vector operator+(const sparse_vector &U, const sparse_vector &V) {
        if (U.size() != V.size()) throw std::length_error("Vectors are not the same dimension");
        sparse_vector S = U;
        for (auto const &entryV : V._vectorMap) {
            S(entryV.first) += entryV.second;
        }
        return S;
    }

    sparse_vector operator-(const sparse_vector &U, const sparse_vector &V) {
        if (U.size() != V.size()) throw std::length_error("Vectors are not the same dimension");
        sparse_vector S = U;
        for (auto const &entryV : V._vectorMap) {
            S(entryV.first) -= entryV.second;
        }
        return S;
    }

    sparse_vector operator*(const sparse_vector &U, const double m) {
        sparse_vector V = U;
        for (std::pair<const int, double> &entry : V._vectorMap) {
            entry.second = entry.second / m;
        }
        return V;
    }

    sparse_vector operator*(const double m, const sparse_vector &U) {
        return U * m;
    }

    sparse_vector operator/(const sparse_vector &U, const double m) {
        sparse_vector V = U;
        for (std::pair<const int, double> &entry : V._vectorMap) {
            entry.second = entry.second / m;
        }
        return V;
    }

    // todo test everything below
    sparse_vector operator*(const sparse_vector &U, const sparse_matrix &A) {
        if (A.rows() != U.size()) {
            throw std::length_error(
                    "Right multiplication with matrix: vector and matrix are not compatible in dimension");
        } else if (U._isColumn) {
            throw std::invalid_argument(
                    "Right multiplication with matrix: vector is not a row vector! First transpose it for goodness' "
                            "sake.");
        }
        sparse_vector P(A.columns(), false);

        for (int columnA = 0; columnA < A.columns(); columnA++) {
            P(columnA) = U * A.GetSparseColumn(columnA);
        }

        return P;
    }

    sparse_matrix operator*(const sparse_matrix &A, const double &b) {
        sparse_matrix B = A;

        for (auto &&row : B) {
            for (auto element : row.second) {
                element.second *= b;
            }
        }

        return B;
    }

    sparse_matrix operator*(const double &b, const sparse_matrix &A) {
        return A * b;
    }

    sparse_matrix operator+(const sparse_matrix &A, const sparse_matrix &B) {
        if (A.columns() != B.columns() or A.rows() != B.rows()) {
            throw std::length_error("Matrix arithmetic: matrices are not compatible in dimension");
        }
        sparse_matrix S = A;

        for (auto &&row : B) {
            for (auto &&element : row.second) {
                S(row.first)(element.first) += element.second;
                if (S[row.first][element.first] == 0)
                    S(row.first)._vectorMap.erase(element.first);
            }
        }

        return S;
    }

    sparse_matrix operator-(const sparse_matrix &A, const sparse_matrix &B) {
        if (A.columns() != B.columns() or A.rows() != B.rows()) {
            throw std::length_error("Matrix arithmetic: matrices are not compatible in dimension");
        }
        sparse_matrix D = A;

        for (auto &&row : B) {
            for (auto &&element : row.second) {
                D(row.first)(element.first) -= element.second;
                if (D[row.first][element.first] == 0)
                    D(row.first)._vectorMap.erase(element.first);
            }
        }

        return D;
    }

    sparse_vector ElementWiseMultiplication(const sparse_vector &U, const sparse_vector &V) {
        if (U.size() != V.size()) throw std::length_error("Vectors are not the same dimension");

        sparse_vector P = U;

        for (auto &&element : P) {
            P(element.first) *= V[element.first];
            if (P[element.first] == 0)
                P._vectorMap.erase(element.first);
        }

        return P;
    }

    sparse_vector ElementWiseDivision(double d, const sparse_vector &V, bool preserveZero) {
        sparse_vector P = V;

        for (auto &&element : P) {
            if (P[element.first] == 0 and preserveZero) {

            } else {
                P(element.first) = P[element.first] / d;
            }


        }

        return P;
    }

    sparse_matrix ElementWiseDivision(double d, const sparse_matrix &V, bool preserveZero) {
        sparse_matrix P = V;

        for (auto &&row : P) {
            for (auto &&element : row.second) {
                if (P[row.first][element.first] == 0 and preserveZero) {

                } else {
                    P(row.first)(element.first) = P(row.first)(element.first) / d;
                }
            }
        }

        return P;
    }

    sparse_matrix VectorToDiagonal(sparse_vector &U, int offset) {
        return VectorToDiagonal(static_cast<const sparse_vector>(U), offset);
    }

    sparse_matrix VectorToDiagonal(const sparse_vector &U, int offset) {
        sparse_matrix Diagonal(U.size() + abs(offset), U.size() + abs(offset));

        if (offset > 0) {
            for (auto &&row : U) {
                Diagonal(row.first + offset)(row.first) = row.second;
            }
        } else {
            for (auto &&row : U) {
                Diagonal(row.first)(row.first - offset) = row.second;
            }
        }

        return Diagonal;
    }

    sparse_matrix ReadSparseMatrix(const char *filename) {
        double element;
        int rows;
        int columns;

        std::ifstream infile(filename);

        if (!infile.is_open()) {
            throw std::invalid_argument(
                    std::string("File ") + std::string(filename) + std::string(" doesn't exist! Terminating..."));
        }

        // Ignore first lines
        infile.ignore(500, '\n');
        infile.ignore(500, '\n');
        infile.ignore(500, '\n');

        infile >> rows;
        infile >> columns;

        sparse_matrix ReadMatrix(rows, static_cast<int>(columns));


        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                infile >> element;
                if (element != 0.0)
                    ReadMatrix(i)(j) = element;
            }
        }

        infile.close();

        return ReadMatrix;
    }

    void WriteMatrix(sparse_matrix M, const char *filename) {
        std::ofstream outfile;
        outfile.open(filename);

        outfile << std::setprecision(9);
        outfile << "# Written matrix" << std::endl;
        outfile << "# " << std::endl;
        outfile << "# " << std::endl;

        outfile << M.rows() << " " << M.columns() << std::endl;
        for (int row = 0; row < M.rows(); row++) {
            for (int column = 0; row < M.columns(); column++) {
                outfile << M[row][column] << " ";
            }
            outfile << std::endl;
        }
        outfile.close();
    }

    sparse_vector ReadSparseVector(const char *filename) {
        double element;
        int columns;

        std::ifstream infile(filename);

        if (!infile.is_open()) {
            throw std::invalid_argument(
                    std::string("File ") + std::string(filename) + std::string(" doesn't exist! Terminating..."));
        }

        // Ignore first lines
        infile.ignore(500, '\n');
        infile.ignore(500, '\n');
        infile.ignore(500, '\n');

        infile >> columns;

        sparse_vector ReadVector(columns, true);

        for (int i = 0; i < columns; i++) {
            infile >> element;
            if (element != 0)
                ReadVector(i) = element;
        }

        infile.close();

        return ReadVector;
    }

    void WriteVector(sparse_vector U, const char *filename) {
        std::ofstream outfile;
        outfile.open(filename);

        outfile << std::setprecision(9);
        outfile << "# Written vector" << std::endl;
        outfile << "# " << std::endl;
        outfile << "# " << std::endl;

        outfile << U.size() << std::endl;
        for (int i = 0; i < U.size(); i++) {
            outfile << U[i] << " ";
        }
        outfile.close();
    }

    std::ostream &operator<<(std::ostream &stream, const sparse_vector &SparseVector) {
        stream << "Sparse " << (SparseVector._isColumn ? "column" : "row") << " vector of dimension "
               << SparseVector._numElements
               << ", displaying non-zero elements (zero-based indices):"
               << std::endl;
        stream << "- start -" << std::endl;
        for (auto const &entry : SparseVector._vectorMap) {
            stream << "\tElement " << entry.first << ": " << entry.second << std::endl;
        }
        stream << "-- end --" << std::endl;
        return stream;
    }

    std::ostream &operator<<(std::ostream &stream, const sparse_matrix &sparse_matrix) {
        stream << "Sparse matrix of dimension " << sparse_matrix._rows << "x" << sparse_matrix._columns
               << ", displaying non-zero elements (zero-based indices):"
               << std::endl;
        stream << "- start -" << std::endl;
        for (auto const &row : sparse_matrix._matrixMap) {
            for (auto const &entry: row.second._vectorMap) {
                stream << "\tElement [" << row.first << "," << entry.first << "]: " << entry.second << std::endl;
            }
        }
        stream << "-- end --" << std::endl;
        return stream;
    }

}