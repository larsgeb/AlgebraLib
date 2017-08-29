//
// Created by Lars Gebraad on 16-8-17.
//

#include <cmath>
#include "matrix.hpp"

namespace algebra_lib {
    matrix::matrix(unsigned long rows, unsigned long columns) {
        _rows = rows;
        _columns = columns;
        _matrixContents =
                std::vector<algebra_lib::vector>(_rows, algebra_lib::vector(_columns, false));
    }

    matrix::matrix() {
        _rows = 2;
        _columns = 2;
        _matrixContents = std::vector<algebra_lib::vector>(2, algebra_lib::vector(2, false));
    }

    vector &matrix::operator[](int i) {
        if (i < 0) {
            throw std::out_of_range("Out of natural range for vectors.");
        } else if (i >= _rows) {
            throw std::out_of_range("Exceeded amount of elements.");
        }

        return _matrixContents[i];
    }

    const vector &matrix::operator[](int i) const {
        if (i < 0) {
            throw std::out_of_range("Out of natural range for vectors.");
        } else if (i >= _rows) {
            throw std::out_of_range("Exceeded amount of elements.");
        }

        return _matrixContents[i];
    }

    vector &matrix::operator()(int i) {
        if (i - 1 < 0) {
            throw std::out_of_range("Out of natural range for vectors.");
        } else if (i - 1 >= _rows) {
            throw std::out_of_range("Exceeded amount of elements.");
        }

        return _matrixContents[i];
    }

    const vector &matrix::operator()(int i) const {
        if (i - 1 < 0) {
            throw std::out_of_range("Out of natural range for vectors.");
        } else if (i - 1 >= _rows) {
            throw std::out_of_range("Exceeded amount of elements.");
        }

        return _matrixContents[i];
    }

    vector matrix::getColumn(int i) {
        vector Column(rows(), true);
        int row = 0;
        for (auto &&item : (*this)) {
            Column[row] = item[i];
            row++;
        }
        return Column;
    }

    const vector matrix::getColumn(int i) const {
        vector Column(rows(), true);
        int row = 0;
        for (auto &&item : (*this)) {
            Column[row] = item[i];
            row++;
        }
        return Column;
    }

    contentVectorVector::iterator matrix::begin() {
        return _matrixContents.begin();
    }

    contentVectorVector::iterator matrix::end() {
        return _matrixContents.end();
    }

    contentVectorVector::const_iterator matrix::begin() const {
        return _matrixContents.begin();
    }

    contentVectorVector::const_iterator matrix::end() const {
        return _matrixContents.end();
    }

    contentVectorVector::reverse_iterator matrix::rbegin() {
        return _matrixContents.rbegin();
    }

    contentVectorVector::reverse_iterator matrix::rend() {
        return _matrixContents.rend();
    }

    contentVectorVector::const_iterator matrix::cbegin() const noexcept {
        return _matrixContents.cbegin();
    }

    contentVectorVector::const_iterator matrix::cend() const noexcept {
        return _matrixContents.cend();
    }

    contentVectorVector::const_reverse_iterator matrix::crbegin() const noexcept {
        return _matrixContents.crbegin();
    }

    contentVectorVector::const_reverse_iterator matrix::crend() const noexcept {
        return _matrixContents.crend();
    }

    matrix matrix::InvertMatrixElements(bool preserveZero) const {
        matrix iM = (*this);
        for (auto &&row : iM) {
            for (auto &&element : row) {
                if (!(preserveZero and element == 0))
                    element = 1.0 / element;
            }
        }
        return iM;
    }

    matrix matrix::InvertMatrixElements(bool preserveZero) {
        return static_cast<const matrix *>(this)->InvertMatrixElements(preserveZero);
    }

    matrix &matrix::InvertMatrixElementsSelf(bool preserveZero) {
        (*this) = (*this).InvertMatrixElements(preserveZero);
        return (*this);
    }

    matrix matrix::Transpose() {
        // Rather nice, isn't it?
        return static_cast<matrix>(static_cast<const matrix *>(this)->Transpose());
    }

    matrix matrix::Transpose() const {
        matrix Mt(columns(), rows());

        for (int rowMt = 0; rowMt < Mt.rows(); ++rowMt) {
            Mt[rowMt] = (*this).getColumn(rowMt);
        }
        return Mt;
    }

    matrix &matrix::TransposeSelf() {
        (*this) = (*this).Transpose();
        return (*this);
    }

    matrix matrix::setColumn(int i, vector Vector) {
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

    matrix matrix::CholeskyDecompose() {
        return static_cast<const matrix *>(this)->CholeskyDecompose();
    }

    matrix matrix::CholeskyDecompose() const {
        if (rows() != columns()) {
            throw std::length_error("Cholesky decomposition: matrix is not square.");
        }

        matrix LowerCholesky(rows(), columns());

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

    vector matrix::Trace(int offset) {
        return static_cast<const matrix *>(this)->Trace(offset);
    }

    vector matrix::Trace(int offset) const {
        if (rows() != columns()) {
            throw std::length_error("Matrix trace: matrix is not square.");
        } else if (abs(offset) >= rows()) {
            throw std::out_of_range("Exceeded matrix bounds");
        }
        vector Trace(rows() - abs(offset));

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

    vector matrix::SolveLowerTriangular(algebra_lib::vector &Y) {
        return static_cast<const matrix *>(this)->SolveLowerTriangular(Y);
    }

    vector matrix::SolveLowerTriangular(algebra_lib::vector &Y) const {
        if (rows() != columns()) {
            throw std::length_error("Solving lower triangular matrix: matrix is not square.");
        }

        vector X(columns(), true);

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

    matrix matrix::InvertLowerTriangular() {
        return static_cast<matrix>(static_cast<const matrix *>(this)->InvertLowerTriangular());
    }

    matrix matrix::InvertLowerTriangular() const {
        if (rows() != columns()) {
            throw std::length_error("matrix trace: matrix is not square.");
        }

        matrix Inverse(rows(), columns());

        for (int column = 0; column < Inverse.columns(); ++column) {
            vector RHS(Inverse.rows(), true);
            RHS[column] = 1.0;

            Inverse.setColumn(column, (*this).SolveLowerTriangular(RHS));
        }
        return Inverse;
    }

    matrix &matrix::Unit() {
        for (auto it = (*this).begin(); it != (*this).end(); ++it){
            (*it) = vector(columns(), false);
            (*it)[it - (*this).begin()] = 1.0;
        }
        return (*this);
    }
}