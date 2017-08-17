//
// Created by Lars Gebraad on 16-8-17.
//

#include <iomanip>
#include "Globals.hpp"
#include "FullAlgebra.hpp"

namespace AlgebraLib {

    /*!
     * \brief A natural way to output vector to console.
     * @param stream I/O stream.
     * @param Matrix Any instance of AlgebraLib::Vector
     * @return Same stream
     */
    std::ostream &operator<<(std::ostream &stream, const Vector &Vector) {
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
    std::ostream &operator<<(std::ostream &stream, const AlgebraLib::Matrix &Matrix) {
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

    Matrix operator*(const Matrix &A, const Matrix &B) {

        if (A.columns() != B.rows()) {
            throw std::length_error("Matrix multiplication: matrices are not compatible in dimension");
        }

        Matrix Product(A.rows(), B.columns());

        for (int row = 0; row < Product.rows(); ++row) {
            for (int column = 0; column < Product.columns(); ++column) {
                Product[row][column] = A[row] * B.getColumn(column);
            }
        }

        return Product;

    }

    Matrix operator+(const Matrix &A, const Matrix &B) {
        if (A.columns() != B.columns() or A.rows() != B.rows()) {
            throw std::length_error("Matrix arithmetic: matrices are not compatible in dimension");
        }

        Matrix Sum(A.rows(), A.columns());

        for (int row = 0; row < Sum.rows(); ++row) {
            Sum[row] = A[row] + B[row];
        }

        return Sum;
    }

    Matrix operator-(const Matrix &A, const Matrix &B) {
        if (A.columns() != B.columns() or A.rows() != B.rows()) {
            throw std::length_error("Matrix arithmetic: matrices are not compatible in dimension");
        }

        Matrix Sum(A.rows(), A.columns());

        for (int row = 0; row < Sum.rows(); ++row) {
            Sum[row] = A[row] - B[row];
        }

        return Sum;

    }

    Vector operator*(const Matrix &A, const Vector &U) {
        if (A.columns() != U.elements()) {
            throw std::length_error(
                    "Left multiplication with matrix: vector and matrix are not compatible in dimension");
        } else if (!U.isColumn()) {
            throw std::invalid_argument(
                    "Left multiplication with matrix: vector is not a column vector! First transpose it for goodness' sake.");
        }

        Vector Product(A.rows(), true);

        for (int i = 0; i < U.elements(); ++i) {
            Product[i] = A[i] * U;
        }
        return Product;
    }

    Vector operator*(const Vector &U, const Matrix &A) {
        if (A.rows() != U.elements()) {
            throw std::length_error(
                    "Right multiplication with matrix: vector and matrix are not compatible in dimension");
        } else if (U.isColumn()) {
            throw std::invalid_argument(
                    "Right multiplication with matrix: vector is not a row vector! First transpose it for goodness' "
                            "sake.");
        }

        Vector Product(A.columns(), false);

        for (int i = 0; i < U.elements(); ++i) {
            Product[i] = A.getColumn(i) * U;
        }

        return Product;
    }

    double operator*(const Vector &U, const Vector &V) {
        if (U.elements() != V.elements()) throw std::length_error("Vectors are not the same dimension");

        double inProduct = 0.0;
        for (int element = 0; element < U.elements(); ++element) {
            inProduct += U[element] * V[element];
        }
        return inProduct;
    }

    Vector operator+(const Vector &U, const Vector &V) {
        if (U.elements() != V.elements()) throw std::length_error("Vectors are not the same dimension");

        Vector Sum(U.elements(), U.isColumn());

        for (int element = 0; element < U.elements(); ++element) {
            Sum[element] = U[element] + V[element];
        }
        return Sum;
    }

    Vector operator-(const Vector &U, const Vector &V) {
        if (U.elements() != V.elements()) throw std::length_error("Vectors are not the same dimension");

        Vector Difference(U.elements(), U.isColumn());

        for (int element = 0; element < U.elements(); ++element) {
            Difference[element] = U[element] - V[element];
        }
        return Difference;
    }

    Vector operator*(const Vector &U, double m) {

        Vector Product(U.elements(), U.isColumn());

        for (int element = 0; element < U.elements(); ++element) {
            Product[element] = U[element] * m;
        }

        return Product;
    }

    Vector operator*(double m, const Vector &U) {
        return U * m;
    }

    Vector operator/(const Vector &U, double m) {
        return U * (1.0 / m);
    }

    Matrix VectorToDiagonal(Vector &U, int offset) {
        return static_cast<Matrix>(VectorToDiagonal(static_cast<const Vector>(U), offset));
    }

    Matrix VectorToDiagonal(const Vector &U, int offset) {
        Matrix Diagonal(U.elements() + abs(offset), U.elements() + abs(offset));

        if (offset > 0) {
            for (int i = 0; i < U.elements(); ++i) {
                Diagonal[i + offset][i] = U[i];
            }
        } else {
            for (int i = 0; i < U.elements(); ++i) {
                Diagonal[i][i - offset] = U[i];
            }
        }

        return Diagonal;
    }

    Matrix operator*(const Matrix &A, const double &b) {
        Matrix Product(A.rows(), A.columns());

        for (int row = 0; row < A.rows(); ++row) {
            Product[row] = A[row].Transpose() * b;
        }

        return Product;
    }

    Matrix operator*(const double &b, const Matrix &A) {
        return A * b;
    }

    Matrix ReadMatrix(const char *filename) {
        double element;
        unsigned long rows;
        unsigned long columns;

        std::ifstream infile(filename);

        // Ignore first lines
        infile.ignore(500, '\n');
        infile.ignore(500, '\n');
        infile.ignore(500, '\n');

        infile >> rows;
        infile >> columns;

        Matrix ReadMatrix(rows, columns);


        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                infile >> element;
                ReadMatrix[i][j] = element;
            }
        }

        infile.close();

        return ReadMatrix;
    }

    void WriteMatrix(Matrix M, const char *filename) {
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

    Vector ReadVector(const char *filename) {
        double element;
        unsigned long columns;

        std::ifstream infile(filename);

        // Ignore first lines
        infile.ignore(500, '\n');
        infile.ignore(500, '\n');
        infile.ignore(500, '\n');

        infile >> columns;

        Vector ReadVector(columns, true);

        for (int i = 0; i < columns; i++) {
            infile >> element;
            ReadVector[i] = element;
        }

        infile.close();

        return ReadVector;
    }

    void WriteVector(Vector U, const char *filename) {
        std::ofstream outfile;
        outfile.open(filename);

        outfile << std::setprecision(9);
        outfile << "# Written vector" << std::endl;
        outfile << "# " << std::endl;
        outfile << "# " << std::endl;

        outfile << U.elements() << std::endl;
        for (int i = 0; i < U.elements(); i++) {
            outfile << U[i] << " ";
        }
        outfile.close();
    }

}