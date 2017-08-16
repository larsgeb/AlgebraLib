//
// Created by Lars Gebraad on 16-8-17.
//

#include <iostream>
#include "Matrix.hpp"

namespace AlgebraLib {
    Matrix::Matrix(unsigned long rows, unsigned long columns) {
        _rows = rows;
        _columns = columns;
        _data = std::vector<AlgebraLib::Vector>(_rows, AlgebraLib::Vector(_columns, false));
    }

    Matrix::Matrix() {
        _rows = 2;
        _columns = 2;
        _data = std::vector<AlgebraLib::Vector>(2, AlgebraLib::Vector(2, false));
    }

    Vector &Matrix::operator[](int i) {
        if (i < 0) {
            throw std::out_of_range("Out of natural range for vectors.");
        } else if (i >= _rows) {
            throw std::out_of_range("Exceeded amount of elements.");
        }

        return _data[i];
    }

    const Vector &Matrix::operator[](int i) const {
        if (i < 0) {
            throw std::out_of_range("Out of natural range for vectors.");
        } else if (i >= _rows) {
            throw std::out_of_range("Exceeded amount of elements.");
        }

        return _data[i];
    }

    Vector &Matrix::operator()(int i) {
        if (i - 1 < 0) {
            throw std::out_of_range("Out of natural range for vectors.");
        } else if (i - 1 >= _rows) {
            throw std::out_of_range("Exceeded amount of elements.");
        }

        return _data[i];
    }

    const Vector &Matrix::operator()(int i) const {
        if (i - 1 < 0) {
            throw std::out_of_range("Out of natural range for vectors.");
        } else if (i - 1 >= _rows) {
            throw std::out_of_range("Exceeded amount of elements.");
        }

        return _data[i];
    }
}