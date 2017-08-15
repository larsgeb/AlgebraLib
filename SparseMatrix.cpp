//
// Created by Lars Gebraad on 14-8-17.
//

#include <iostream>
#include "SparseMatrix.hpp"

// --- SparseMatrix class ---

SparseMatrix::SparseMatrix(int rows, int columns) {
    _rows = rows;
    _columns = columns;
}

SparseVector &SparseMatrix::operator[](int i) {
    // Check if within matrix size
    if (i < 0) {
        throw std::out_of_range("Exceeded natural range for indices");
    } else if (i >= _rows) {
        throw std::out_of_range("Exceeded number of rows");
    }

    // Does the sparse row already contain something?
    if (_matrixMap.find(i) == _matrixMap.end())
        // If not, make empty row.
        _matrixMap[i] = SparseVector(_columns, false);

    _matrixMap[i]._numElements = _columns;
    return _matrixMap[i];
}

const SparseVector &SparseMatrix::operator[](int i) const {
    // Check if within matrix size
    if (i < 0) {
        throw std::out_of_range("Exceeded natural range for indices");
    } else if (i >= _rows) {
        throw std::out_of_range("Exceeded number of rows");
    }

    const std::map<int, SparseVector>::const_iterator &row = _matrixMap.find(i);

    if (row != _matrixMap.end()) {
        // Do we have entries in the constant matrix?
        return row->second;
    }

    // If not, we're not allowed to make them, so we return empty const SparseVector.
    const SparseVector A(_columns, false);
    return A;

}

SparseVector &SparseMatrix::operator()(int i) {
    if (i < 1) {
        throw std::out_of_range("Exceeded natural range for indices");
    } else if (i > _rows) {
        throw std::out_of_range("Exceeded number of rows");
    }

    if (_matrixMap.find(i - 1) == _matrixMap.end())
        _matrixMap[i - 1] = SparseVector(_columns, false);

    _matrixMap[i - 1]._numElements = _columns;
    return _matrixMap[i - 1];
}

const SparseVector &SparseMatrix::operator()(int i) const {
    // Check if within matrix size
    if (i < 1) {
        throw std::out_of_range("Exceeded natural range for indices");
    } else if (i > _rows) {
        throw std::out_of_range("Exceeded number of rows");
    }

    const std::map<int, SparseVector>::const_iterator &row = _matrixMap.find(i);

    if (row != _matrixMap.end()) {
        // Do we have entries in the constant matrix?
        return row->second;
    }

    // If not, we're not allowed to make them, so we return empty const SparseVector.
    const SparseVector A(_columns, false);
    return A;

}

int SparseMatrix::GetRows() { return _rows; }

int SparseMatrix::GetColumns() { return _columns; }

SparseVector SparseMatrix::GetSparseColumn(int column) {
    SparseVector P(_rows, true);
    for (auto &row : _matrixMap) {
        double entry = row.second[column];
        if (entry != 0)
            P[row.first] = entry;
    }
    return P;
}

const SparseVector SparseMatrix::GetSparseColumn(int column) const {
    SparseVector P(_rows, true);
    for (auto &row : _matrixMap) {
        double entry = row.second[column];
        if (entry != 0)
            P[row.first] = entry;
    }
    return P;
}

SparseMatrix SparseMatrix::Transpose() {
    SparseMatrix T(_columns, _rows);

    for (auto row: _matrixMap) {
        for (auto column: row.second.vectorMap) {
            if (column.second != 0)
                T[column.first][row.first] = column.second;
        }
    }

    return T;
}

SparseMatrix SparseMatrix::TransposeSelf() {
    // Does not provide performance increase//less required memory over
    // SparseMatrix = SparseMatrix::Transpose().
    SparseMatrix T(_columns, _rows);
    for (auto row: _matrixMap) {
        for (auto column: row.second.vectorMap) {
            if (column.second != 0)
                T[column.first][row.first] = column.second;
        }
    }
    (*this) = T;
    return (*this);
}


SparseMatrix SparseMatrix::SetOwnSparseColumn(SparseVector Vector, int column) {
    // Does provide performance increase//less required memory over
    // SparseMatrix = SparseMatrix::SetSparseColumn().
    for (auto &&item : Vector.vectorMap) {
        if (item.second != 0) {
            (*this)[item.first][column] = item.second;
        }else{
            (*this)[item.first].vectorMap.erase(column);
        }
    }
    return (*this);
}

SparseMatrix SparseMatrix::SetSparseColumn(SparseVector Vector, int column) {
    SparseMatrix VectorModified = (*this);
    for (auto &&item : Vector.vectorMap) {
        if (item.second != 0) {
            VectorModified[item.first][column] = item.second;
        }else{
            VectorModified[item.first].vectorMap.erase(column);
        }
    }
    return VectorModified;
}


// --- end of class ---