//
// Created by Lars Gebraad on 14-8-17.
//

#include <iostream>
#include "sparse_matrix.hpp"

namespace algebra_lib {

    sparse_matrix::sparse_matrix() {
        _rows = 2;
        _columns = 2;
    }

    sparse_matrix::sparse_matrix(unsigned int rows, unsigned int columns) {
        _rows = rows;
        _columns = columns;
    }

    sparse_vector sparse_matrix::operator[](unsigned int i) {
        return (static_cast<const sparse_matrix *>(this)->operator[](i));
    }

    const sparse_vector sparse_matrix::operator[](unsigned int i) const {
        // Check if within matrix size
        if (i < 0) {
            throw std::out_of_range("Exceeded natural range for indices");
        } else if (i >= rows()) {
            throw std::out_of_range("Exceeded number of rows");
        }

        try {
            return _matrixMap.at(i);
        } catch (std::out_of_range &e) {
            return sparse_vector(columns(), false);
        }
    }

    sparse_vector &sparse_matrix::operator()(unsigned int i) {
        if (i < 0) {
            throw std::out_of_range("Exceeded natural range for indices");
        } else if (i >= rows()) {
            throw std::out_of_range("Exceeded number of rows");
        }

        // Row doesn't exist, accessing for assignment, so create the row.
        if (_matrixMap.find(i) == _matrixMap.end())
            _matrixMap[i] = sparse_vector(columns(), false);

        return _matrixMap[i];
    }

    const sparse_vector sparse_matrix::operator()(unsigned int i) const {
        return (this)->operator[](i);
    }

    unsigned int sparse_matrix::rows() const { return _rows; }

    unsigned int sparse_matrix::columns() const { return _columns; }

    sparse_vector sparse_matrix::GetSparseColumn(unsigned int column) {
        return static_cast<const sparse_matrix>(*this).GetSparseColumn(column);
    }

    const sparse_vector sparse_matrix::GetSparseColumn(unsigned int column) const {
        sparse_vector P(rows(), true);
        for (auto &row : _matrixMap) {
            try {
                double entry = row.second[column];
                if (entry != 0)
                    P(row.first) = entry;
            } catch (const std::exception &e) {
                /*
                 * Nothing fancy, we're trying to acces a const matrix. Right.. So what happens if we don't know which
                 * getColumn entries are exactly non-zero and we have to iterate? Well, normally, map[] would create a new map
                 * entry, but that is not allowed for a const! So we try to acces it with map::at(), which return an
                 * exception when an element is non-existent in map. Here we catch it and we... don't do anything with it!
                 * This happens occasionally if we are not quite sure of the contents of our matrix, for example with
                 * matrix multiplication.
                 *
                 * You could verify it with uncommenting the next line (given that iostream is included).
                 *
                 */
                // std::cout << e.what() << std::endl;
            }
        }
        return P;
    }

    sparse_matrix sparse_matrix::Transpose() {
        sparse_matrix T(columns(), rows());

        for (auto row: _matrixMap) {
            for (auto column: row.second) {
                if (column.second != 0)
                    T(column.first)(row.first) = column.second;
            }
        }

        return T;
    }

    const sparse_matrix sparse_matrix::Transpose() const {
        sparse_matrix T(columns(), rows());

        for (auto row: _matrixMap) {
            for (auto column: row.second) {
                if (column.second != 0)
                    T(column.first)(row.first) = column.second;
            }
        }

        return T;
    }

    sparse_matrix sparse_matrix::TransposeSelf() {
        // Does not provide performance increase//less required memory over
        // sparse_matrix = sparse_matrix::Transpose().
        sparse_matrix T(columns(), rows());
        for (auto row: _matrixMap) {
            for (auto column: row.second) {
                if (column.second != 0)
                    T(column.first)(row.first) = column.second;
            }
        }
        (*this) = T;
        return (*this);
    }

    sparse_matrix sparse_matrix::SetSparseColumnSelf(sparse_vector Vector, unsigned int column) {
        // Does provide performance increase//less required memory over
        // sparse_matrix = sparse_matrix::SetSparseColumn().
        for (auto &&item : Vector) {
            if (item.second != 0) {
                (*this)(item.first)(column) = item.second;
            } else {
//                (*this)(item.first)._vectorMap.erase(column);
                (*this)(item.first).eraseEntry(column);
            }
        }
        return (*this);
    }

    sparse_matrix sparse_matrix::SetSparseColumn(sparse_vector Vector, unsigned int column) {
        sparse_matrix VectorModified = (*this);
        for (auto &&item : Vector) {
            if (item.second != 0) {
                VectorModified(item.first)(column) = item.second;
            } else {
                VectorModified(item.first).eraseEntry(column);
            }
        }
        return VectorModified;
    }

    sparseContentMatrixDouble::const_iterator sparse_matrix::begin() const {
        return _matrixMap.begin();
    }

    sparseContentMatrixDouble::const_iterator sparse_matrix::end() const {
        return _matrixMap.end();
    }

    sparseContentMatrixDouble::reverse_iterator sparse_matrix::rbegin() {
        return _matrixMap.rbegin();
    }

    sparseContentMatrixDouble::reverse_iterator sparse_matrix::rend() {
        return _matrixMap.rend();
    }

    sparseContentMatrixDouble::const_iterator sparse_matrix::cbegin() const noexcept {
        return _matrixMap.cbegin();
    }

    sparseContentMatrixDouble::const_iterator sparse_matrix::cend() const noexcept {
        return _matrixMap.cend();
    }

    sparseContentMatrixDouble::const_reverse_iterator sparse_matrix::crbegin() const noexcept {
        return _matrixMap.crbegin();
    }

    sparseContentMatrixDouble::const_reverse_iterator sparse_matrix::crend() const noexcept {
        return _matrixMap.crend();
    }

//    sparse_matrix sparse_matrix::InvertLowerTriangular() {
//        return sparse_matrix();
//    }
//
//    sparse_matrix sparse_matrix::InvertLowerTriangular() const {
//        return sparse_matrix();
//    }
//
//    sparse_matrix sparse_matrix::InvertMatrixElements(bool preserveZero) {
//        return sparse_matrix();
//    }
//
//    sparse_matrix sparse_matrix::InvertMatrixElements(bool preserveZero) const {
//        return sparse_matrix();
//    }
//
//    sparse_matrix &sparse_matrix::InvertMatrixElementsSelf(bool preserveZero) {
//        return <#initializer#>;
//    }
//
//    sparse_vector sparse_matrix::Trace(int offset) {
//        return sparse_vector();
//    }
//
//    sparse_vector sparse_matrix::Trace(int offset) const {
//        return sparse_vector();
//    }
//
//    sparse_matrix sparse_matrix::CholeskyDecompose() {
//        return sparse_matrix();
//    }
//
//    sparse_matrix sparse_matrix::CholeskyDecompose() const {
//        return sparse_matrix();
//    }
//
//    sparse_vector sparse_matrix::SolveLowerTriangular(sparse_vector &Y) {
//        return sparse_vector();
//    }
//
//    sparse_vector sparse_matrix::SolveLowerTriangular(sparse_vector &Y) const {
//        return sparse_vector();
//    }
//
//    sparse_matrix &sparse_matrix::Unit() {
//        return <#initializer#>;
//    }


}

// --- end of class ---