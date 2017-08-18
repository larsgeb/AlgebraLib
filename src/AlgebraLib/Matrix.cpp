//
// Created by Lars Gebraad on 16-8-17.
//

#include <cmath>
#include "Matrix.hpp"

namespace AlgebraLib {
    Matrix::Matrix(unsigned long rows, unsigned long columns) {
        _rows = rows;
        _columns = columns;
        _matrixContents =
                std::vector<AlgebraLib::Vector>(_rows, AlgebraLib::Vector(_columns, false));
    }

    Matrix::Matrix() {
        _rows = 2;
        _columns = 2;
        _matrixContents = std::vector<AlgebraLib::Vector>(2, AlgebraLib::Vector(2, false));
    }

    Vector &Matrix::operator[](int i) {
        if (i < 0) {
            throw std::out_of_range("Out of natural range for vectors.");
        } else if (i >= _rows) {
            throw std::out_of_range("Exceeded amount of elements.");
        }

        return _matrixContents[i];
    }

    const Vector &Matrix::operator[](int i) const {
        if (i < 0) {
            throw std::out_of_range("Out of natural range for vectors.");
        } else if (i >= _rows) {
            throw std::out_of_range("Exceeded amount of elements.");
        }

        return _matrixContents[i];
    }

    Vector &Matrix::operator()(int i) {
        if (i - 1 < 0) {
            throw std::out_of_range("Out of natural range for vectors.");
        } else if (i - 1 >= _rows) {
            throw std::out_of_range("Exceeded amount of elements.");
        }

        return _matrixContents[i];
    }

    const Vector &Matrix::operator()(int i) const {
        if (i - 1 < 0) {
            throw std::out_of_range("Out of natural range for vectors.");
        } else if (i - 1 >= _rows) {
            throw std::out_of_range("Exceeded amount of elements.");
        }

        return _matrixContents[i];
    }

    Vector Matrix::getColumn(int i) {
        Vector Column(rows(), true);
        int row = 0;
        for (auto &&item : (*this)) {
            Column[row] = item[i];
            row++;
        }
        return Column;
    }

    const Vector Matrix::getColumn(int i) const {
        Vector Column(rows(), true);
        int row = 0;
        for (auto &&item : (*this)) {
            Column[row] = item[i];
            row++;
        }
        return Column;
    }

    contentVectorVector::iterator Matrix::begin() {
        return _matrixContents.begin();
    }

    contentVectorVector::iterator Matrix::end() {
        return _matrixContents.end();
    }

    contentVectorVector::const_iterator Matrix::begin() const {
        return _matrixContents.begin();
    }

    contentVectorVector::const_iterator Matrix::end() const {
        return _matrixContents.end();
    }

    contentVectorVector::reverse_iterator Matrix::rbegin() {
        return _matrixContents.rbegin();
    }

    contentVectorVector::reverse_iterator Matrix::rend() {
        return _matrixContents.rend();
    }

    contentVectorVector::const_iterator Matrix::cbegin() const noexcept {
        return _matrixContents.cbegin();
    }

    contentVectorVector::const_iterator Matrix::cend() const noexcept {
        return _matrixContents.cend();
    }

    contentVectorVector::const_reverse_iterator Matrix::crbegin() const noexcept {
        return _matrixContents.crbegin();
    }

    contentVectorVector::const_reverse_iterator Matrix::crend() const noexcept {
        return _matrixContents.crend();
    }

    Matrix Matrix::InvertMatrixElements(bool preserveZero) const {
        Matrix iM = (*this);
        for (auto &&row : iM) {
            for (auto &&element : row) {
                if (!(preserveZero and element == 0))
                    element = 1.0 / element;
            }
        }
        return iM;
    }

    Matrix Matrix::InvertMatrixElements(bool preserveZero) {
        return static_cast<Matrix>(static_cast<const Matrix *>(this)->InvertMatrixElements(preserveZero));
    }

    Matrix &Matrix::InvertMatrixElementsSelf(bool preserveZero) {
        (*this) = (*this).InvertMatrixElements(preserveZero);
        return (*this);
    }

    Matrix Matrix::Transpose() {
        // Rather nice, isn't it?
        return static_cast<Matrix>(static_cast<const Matrix *>(this)->Transpose());
    }

    Matrix Matrix::Transpose() const {
        Matrix Mt(columns(), rows());

        for (int rowMt = 0; rowMt < Mt.rows(); ++rowMt) {
            Mt[rowMt] = (*this).getColumn(rowMt);
        }
        return Mt;
    }

    Matrix &Matrix::TransposeSelf() {
        (*this) = (*this).Transpose();
        return (*this);
    }

    Matrix Matrix::setColumn(int i, Vector Vector) {
        if (rows() != Vector.size()) {
            throw std::length_error(
                    "Column assignment: vector and matrix are not compatible in dimension");
        } else if (!Vector.isColumn()) {
            throw std::invalid_argument(
                    "Column assignment: vector is not a column vector! First transpose it for goodness' sake.");
        }

        unsigned int vectorElement = 0;
        for (auto &&row : (*this)) {
            row[i] = Vector[vectorElement];
            vectorElement++;
        }

        return (*this);
    }

    Matrix Matrix::CholeskyDecompose() {
        return static_cast<Matrix>(static_cast<const Matrix *>(this)->CholeskyDecompose());
    }

    Matrix Matrix::CholeskyDecompose() const {
        if (rows() != columns()) {
            throw std::length_error("Matrix trace: matrix is not square.");
        }

        Matrix LowerCholesky(rows(), columns());

        LowerCholesky[0][0] = sqrt((*this)[0][0]);

        for (int row = 1; row < rows(); ++row) {
            for (int column = 0; column <= row; ++column) {

                double sum = 0;
                for (int k = 0; k < column; k++) {
                    sum += LowerCholesky[row][k] * LowerCholesky[column][k];
                }

                if (column == row) {
                    LowerCholesky[row][column] = sqrt((*this)[row][column] - sum);
                } else {
                    LowerCholesky[row][column] = (1 / LowerCholesky[column][column]) * ((*this)[row][column] - sum);
                }
            }
        }

        return LowerCholesky;


    }

    Vector Matrix::Trace(int offset) {
        return static_cast<Vector>(static_cast<const Matrix *>(this)->Trace(offset));
    }

    Vector Matrix::Trace(int offset) const {
        if (rows() != columns()) {
            throw std::length_error("Matrix trace: matrix is not square.");
        } else if (abs(offset) >= rows()) {
            throw std::out_of_range("Exceeded matrix bounds");
        }
        Vector Trace(rows() - abs(offset));

        if (offset > 0) {
            for (int element = 0; element < Trace.size(); ++element) {
                Trace[element] = (*this)[element + offset][element];
            }
        } else {
            for (int element = 0; element < Trace.size(); ++element) {
                Trace[element] = (*this)[element][element - offset];
            }
        }
        return Trace;
    }

    Vector Matrix::SolveLowerTriangular(AlgebraLib::Vector &Y) {
        return static_cast<Vector>(static_cast<const Matrix *>(this)->SolveLowerTriangular(Y));
    }

    Vector Matrix::SolveLowerTriangular(AlgebraLib::Vector &Y) const {
        if (rows() != columns()) {
            throw std::length_error("Matrix trace: matrix is not square.");
        }

        Vector X(columns(), true);

        X[0] = (Y[0] / (*this)[0][0]);

        for (int i = 1; i < X.size(); ++i) {
            double sum = 0.0;

            for (int j = 0; j < i; ++j) {
                sum += (*this)[i][j] * X[j];
            }

            X[i] = (Y[i] - sum) / (*this)[i][i];
        }
        return X;
    }

    Matrix Matrix::InvertLowerTriangular() {
        return static_cast<Matrix>(static_cast<const Matrix *>(this)->InvertLowerTriangular());
    }

    Matrix Matrix::InvertLowerTriangular() const {
        if (rows() != columns()) {
            throw std::length_error("Matrix trace: matrix is not square.");
        }

        Matrix Inverse(rows(), columns());

        for (int column = 0; column < Inverse.columns(); ++column) {
            Vector RHS(Inverse.rows(), true);
            RHS[column] = 1.0;

            Inverse.setColumn(column, (*this).SolveLowerTriangular(RHS));
        }
        return Inverse;
    }

    Matrix &Matrix::Unit() {
        for (auto it = (*this).begin(); it != (*this).end(); ++it){
            (*it) = Vector(columns(), false);
            (*it)[it - (*this).begin()] = 1.0;
        }
        return (*this);
    }
}