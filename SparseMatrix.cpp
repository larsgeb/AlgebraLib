//
// Created by Lars Gebraad on 14-8-17.
//

#include "SparseMatrix.hpp"

// --- SparseMatrix class ---

SparseMatrix::SparseMatrix(int rows, int columns) {
    _rows = rows;
    _columns = columns;
}

/*const SparseVector operator[](int i) const {
    *//*
         * Because std::maps []-operator is not declared as const, this alternative is used.
         * Of course, stack overflow helps:
         * https://stackoverflow.com/questions/262853/c-map-access-discards-qualifiers-const
         *//*
        if (i >= _rows) throw std::out_of_range("Exceeded number of rows");

        return _M.find(i)->second;
    }

    const SparseVector operator()(int i) const {
        if (i > _rows) throw std::out_of_range("Exceeded number of rows");

        return _M.find(i - 1)->second;
    }*/

SparseVector &SparseMatrix::operator[](int i) {
    // Check if within matrix size
    if (i < 0) {
        throw std::out_of_range("Exceeded natural range for indices");
    } else if (i >= _rows) {
        throw std::out_of_range("Exceeded number of rows");
    }

    // Does the sparse row already contain something?
    if (_M.find(i) == _M.end())
        // If not, make empty row.
        _M[i] = SparseVector(_columns);

    _M[i]._numElements = _columns;
    return _M[i];
}

SparseVector &SparseMatrix::operator()(int i) {
    if (i < 1) {
        throw std::out_of_range("Exceeded natural range for indices");
    } else if (i > _rows) {
        throw std::out_of_range("Exceeded number of rows");
    }

    if (_M.find(i - 1) == _M.end())
        _M[i - 1] = SparseVector(_columns);

    _M[i - 1]._numElements = _columns;
    return _M[i - 1];
}


int SparseMatrix::GetRows() { return _rows; }

int SparseMatrix::GetColumns() { return _columns; }

// --- end of class ---