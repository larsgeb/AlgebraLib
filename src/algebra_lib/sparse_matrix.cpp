//
// Created by Lars Gebraad on 14-8-17.
//

#include <iostream>
#include "sparse_matrix.hpp"

namespace algebra_lib {
    sparse_matrix::sparse_matrix(int rows, int columns) {
        _rows = rows;
        _columns = columns;
    }

    sparse_vector sparse_matrix::operator[](int i) {
        return (static_cast<const sparse_matrix *>(this)->operator[](i));
    }

    const sparse_vector &sparse_matrix::operator[](int i) const {
        // Check if within matrix size
        if (i < 0) {
            throw std::out_of_range("Exceeded natural range for indices");
        } else if (i >= _rows) {
            throw std::out_of_range("Exceeded number of rows");
        }

        return _matrixMap.at(i);

    }

    sparse_vector &sparse_matrix::operator()(int i) {
        if (i < 1) {
            throw std::out_of_range("Exceeded natural range for indices");
        } else if (i > _rows) {
            throw std::out_of_range("Exceeded number of rows");
        }

        if (_matrixMap.find(i - 1) == _matrixMap.end())
            _matrixMap[i - 1] = sparse_vector(_columns, false);

        _matrixMap[i - 1]._numElements = _columns;
        return _matrixMap[i - 1];
    }

    const sparse_vector &sparse_matrix::operator()(int i) const {
        // Check if within matrix size
        if (i < 1) {
            throw std::out_of_range("Exceeded natural range for indices");
        } else if (i > _rows) {
            throw std::out_of_range("Exceeded number of rows");
        }

        /*
        const std::map<int, SparseVector>::const_iterator &row = _matrixMap.find(i);

        if (row != _matrixMap.end()) {
            // Do we have entries in the constant matrix?
            return row->second;
        }

        // If not, we're not allowed to make them, so we return empty const SparseVector.
        const SparseVector A(_columns, false);
        return A;
         */

        return _matrixMap.at(i - 1);

    }

    int sparse_matrix::GetRows() { return _rows; }

    int sparse_matrix::GetColumns() { return _columns; }

    sparse_vector sparse_matrix::GetSparseColumn(int column) {
        sparse_vector P(_rows, true);
        for (auto &row : _matrixMap) {
            double entry = row.second[column];
            if (entry != 0)
                P[row.first] = entry;
        }
        return P;
    }

    const sparse_vector sparse_matrix::GetSparseColumn(int column) const {
        sparse_vector P(_rows, true);
        for (auto &row : _matrixMap) {
            try {
                double entry = row.second[column];
                if (entry != 0)
                    P[row.first] = entry;
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
        sparse_matrix T(_columns, _rows);

        for (auto row: _matrixMap) {
            for (auto column: row.second._vectorMap) {
                if (column.second != 0)
                    T[column.first][row.first] = column.second;
            }
        }

        return T;
    }

    sparse_matrix sparse_matrix::TransposeSelf() {
        // Does not provide performance increase//less required memory over
        // sparse_matrix = sparse_matrix::Transpose().
        sparse_matrix T(_columns, _rows);
        for (auto row: _matrixMap) {
            for (auto column: row.second._vectorMap) {
                if (column.second != 0)
                    T[column.first][row.first] = column.second;
            }
        }
        (*this) = T;
        return (*this);
    }

    sparse_matrix sparse_matrix::SetSparseColumnSelf(sparse_vector Vector, int column) {
        // Does provide performance increase//less required memory over
        // sparse_matrix = sparse_matrix::SetSparseColumn().
        for (auto &&item : Vector._vectorMap) {
            if (item.second != 0) {
                (*this)[item.first][column] = item.second;
            } else {
                (*this)[item.first]._vectorMap.erase(column);
            }
        }
        return (*this);
    }

    sparse_matrix sparse_matrix::SetSparseColumn(sparse_vector Vector, int column) {
        sparse_matrix VectorModified = (*this);
        for (auto &&item : Vector._vectorMap) {
            if (item.second != 0) {
                VectorModified[item.first][column] = item.second;
            } else {
                VectorModified[item.first]._vectorMap.erase(column);
            }
        }
        return VectorModified;
    }

}

// --- end of class ---