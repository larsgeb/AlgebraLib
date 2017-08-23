//
// Created by Lars Gebraad on 16-8-17.
//

#include <iomanip>
#include "globals.hpp"
#include "full_algebra.hpp"

namespace algebra_lib {

    /*!
     * \brief A natural way to output vector to console.
     * @param stream I/O stream.
     * @param Matrix Any instance of AlgebraLib::Vector
     * @return Same stream
     */
    std::ostream &operator<<(std::ostream &stream, const vector &Vector) {
        stream << "Full " << (Vector._isColumn ? "column" : "row");
        stream << " vector of dimension " << Vector._elements << ":"
               << std::endl;
        for (auto &&element : Vector) {
            stream << "\t" << element;
            if (Vector._isColumn)
                stream << std::endl;
        }
        stream << std::endl;
        return stream;
    }

    /*!
     * \brief A natural way to output matrix to console.
     * @param stream I/O stream.
     * @param Matrix Any instance of AlgebraLib::Matrix
     * @return Same stream
     */
    std::ostream &operator<<(std::ostream &stream, const algebra_lib::matrix &Matrix) {
        int rowIt = 1;
        stream << "Full matrix of dimension " << Matrix.rows() << "x";
        stream << Matrix.columns() << ":" << std::endl;
        for (auto &&row : Matrix) {
            stream << "row\t" << rowIt << "\t|\t";
            for (auto &&column : row) {
                stream << column << "\t";
            }
            stream << std::endl;
            rowIt++;
        }
        return stream;
    }

    matrix operator*(const matrix &A, const matrix &B) {

        if (A.columns() != B.rows()) {
            throw std::length_error("matrix multiplication: matrices are not compatible in dimension");
        }

        matrix Product(A.rows(), B.columns());

        for (int row = 0; row < Product.rows(); ++row) {
            for (int column = 0; column < Product.columns(); ++column) {
                Product[row][column] = A[row] * B.getColumn(column);
            }
        }

        return Product;

    }

    matrix operator+(const matrix &A, const matrix &B) {
        if (A.columns() != B.columns() or A.rows() != B.rows()) {
            throw std::length_error("matrix arithmetic: matrices are not compatible in dimension");
        }

        matrix Sum(A.rows(), A.columns());

        for (int row = 0; row < Sum.rows(); ++row) {
            Sum[row] = A[row] + B[row];
        }

        return Sum;
    }

    matrix operator-(const matrix &A, const matrix &B) {
        if (A.columns() != B.columns() or A.rows() != B.rows()) {
            throw std::length_error("matrix arithmetic: matrices are not compatible in dimension");
        }

        matrix Sum(A.rows(), A.columns());

        for (int row = 0; row < Sum.rows(); ++row) {
            Sum[row] = A[row] - B[row];
        }

        return Sum;

    }

    vector operator*(const matrix &A, const vector &U) {
        if (A.columns() != U.size()) {
            throw std::length_error(
                    "Left multiplication with matrix: vector and matrix are not compatible in dimension");
        } else if (!U.isColumn()) {
            throw std::invalid_argument(
                    "Left multiplication with matrix: vector is not a column vector! First transpose it for goodness' sake.");
        }

        vector Product(A.rows(), true);

        for (int i = 0; i < U.size(); ++i) {
            Product[i] = A[i] * U;
        }
        return Product;
    }

    vector operator*(const vector &U, const matrix &A) {
        if (A.rows() != U.size()) {
            throw std::length_error(
                    "Right multiplication with matrix: vector and matrix are not compatible in dimension");
        } else if (U.isColumn()) {
            throw std::invalid_argument(
                    "Right multiplication with matrix: vector is not a row vector! First transpose it for goodness' "
                            "sake.");
        }

        vector Product(A.columns(), false);

        for (int i = 0; i < U.size(); ++i) {
            Product[i] = A.getColumn(i) * U;
        }

        return Product;
    }

    double operator*(const vector &U, const vector &V) {
        if (U.size() != V.size()) throw std::length_error("Vectors are not the same dimension");

        double inProduct = 0.0;
        for (int element = 0; element < U.size(); ++element) {
            inProduct += U[element] * V[element];
        }
        return inProduct;
    }

    vector operator+(const vector &U, const vector &V) {
        if (U.size() != V.size()) throw std::length_error("Vectors are not the same dimension");

        vector Sum(U.size(), U.isColumn());

        for (int element = 0; element < U.size(); ++element) {
            Sum[element] = U[element] + V[element];
        }
        return Sum;
    }

    vector operator-(const vector &U, const vector &V) {
        if (U.size() != V.size()) throw std::length_error("Vectors are not the same dimension");

        vector Difference(U.size(), U.isColumn());

        for (int element = 0; element < U.size(); ++element) {
            Difference[element] = U[element] - V[element];
        }
        return Difference;
    }

    vector operator*(const vector &U, double m) {

        vector Product(U.size(), U.isColumn());

        for (int element = 0; element < U.size(); ++element) {
            Product[element] = U[element] * m;
        }

        return Product;
    }

    vector operator*(double m, const vector &U) {
        return U * m;
    }

    vector operator/(const vector &U, double m) {
        return U * (1.0 / m);
    }

    matrix VectorToDiagonal(vector &U, int offset) {
        return static_cast<matrix>(VectorToDiagonal(static_cast<const vector>(U), offset));
    }

    matrix VectorToDiagonal(const vector &U, int offset) {
        matrix Diagonal(U.size() + abs(offset), U.size() + abs(offset));

        if (offset > 0) {
            for (int i = 0; i < U.size(); ++i) {
                Diagonal[i + offset][i] = U[i];
            }
        } else {
            for (int i = 0; i < U.size(); ++i) {
                Diagonal[i][i - offset] = U[i];
            }
        }

        return Diagonal;
    }

    matrix operator*(const matrix &A, const double &b) {
        matrix Product(A.rows(), A.columns());

        for (int row = 0; row < A.rows(); ++row) {
            Product[row] = A[row].Transpose() * b;
        }

        return Product;
    }

    matrix operator*(const double &b, const matrix &A) {
        return A * b;
    }

    matrix ReadMatrix(const char *filename) {
        double element;
        unsigned long rows;
        unsigned long columns;

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

        matrix ReadMatrix(rows, columns);


        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                infile >> element;
                ReadMatrix[i][j] = element;
            }
        }

        infile.close();

        return ReadMatrix;
    }

    void WriteMatrix(matrix M, const char *filename) {
        std::ofstream outfile;
        outfile.open(filename);

        outfile << std::setprecision(9);
        outfile << "# Written matrix" << std::endl;
        outfile << "# " << std::endl;
        outfile << "# " << std::endl;

        outfile << M.rows() << " " << M.columns() << std::endl;
        for (auto &&row : M) {
            for (auto &&element : row) {
                outfile << element << " ";
            }
            outfile << std::endl;
        }
        outfile.close();
    }

    vector ReadVector(const char *filename) {
        double element;
        unsigned long columns;

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

        vector ReadVector(columns, true);

        for (int i = 0; i < columns; i++) {
            infile >> element;
            ReadVector[i] = element;
        }

        infile.close();

        return ReadVector;
    }

    void WriteVector(vector U, const char *filename) {
        std::ofstream outfile;
        outfile.open(filename);

        outfile << std::setprecision(9);
        outfile << "# Written vector" << std::endl;
        outfile << "# " << std::endl;
        outfile << "# " << std::endl;

        outfile << U.size() << std::endl;
        for (double &i : U) {
            outfile << i << " ";
        }
        outfile.close();
    }

    vector ElementWiseMultiplication(const vector &U, const vector &V) {
        if (U.size() != V.size()) throw std::length_error("Vectors are not the same dimension");

        vector Product = U;

        for (auto iterator = Product.begin(); iterator != Product.end(); iterator++) {
            (*iterator) *= V[iterator - Product.begin()];
        }

        return Product;
    }

    vector ElementWiseDivision(double d, const vector &V, bool preserveZero) {

        vector Division = V;

        for (auto &&iterator = Division.begin(); iterator != Division.end(); iterator++) {
            if ((*iterator) != 0)
                (*iterator) = d / V[iterator - Division.begin()];
        }

        return Division;
    }

    matrix ElementWiseDivision(double d, const matrix &V, bool preserveZero) {

        matrix Division = V;

        for (auto &&iterator = Division.begin(); iterator != Division.end(); iterator++) {
            (*iterator) = algebra_lib::ElementWiseDivision(d, *iterator, preserveZero);
        }

        return Division;
    }

}