//
// Created by Lars Gebraad on 16-8-17.
//

#include "Vector.hpp"

namespace AlgebraLib {
    Vector::Vector(unsigned long elements, bool isColumn) {
        _isColumn = isColumn;
        _elements = elements;
        _data = std::vector<double>(_elements, 0.0);
    };

    Vector::Vector(unsigned long elements) {
        _isColumn = true;
        _elements = elements;
        _data = std::vector<double>(_elements, 0.0);

    };

    Vector::Vector() {
        _isColumn = true;
        _elements = 2;
        _data = std::vector<double>(_elements, 0.0);
    };

    Vector::Vector(bool isColumn) {
        _isColumn = isColumn;
        _elements = 2;
        _data = std::vector<double>(_elements, 0.0);
    };

    double &Vector::operator[](int i) {
        if (i < 0) {
            throw std::out_of_range("Out of natural range for vectors.");
        } else if (i >= _elements) {
            throw std::out_of_range("Exceeded amount of elements.");
        }

        return _data[i];
    }

    const double &Vector::operator[](int i) const {
        if (i < 0) {
            throw std::out_of_range("Out of natural range for vectors.");
        } else if (i >= _elements) {
            throw std::out_of_range("Exceeded amount of elements.");
        }

        return _data[i];
    }

    double &Vector::operator()(int i) {
        if (i - 1 < 0) {
            throw std::out_of_range("Out of natural range for vectors.");
        } else if (i - 1 >= _elements) {
            throw std::out_of_range("Exceeded amount of elements.");
        }

        return _data[i - 1];
    }

    const double &Vector::operator()(int i) const {
        if (i - 1 < 0) {
            throw std::out_of_range("Out of natural range for vectors.");
        } else if (i - 1 >= _elements) {
            throw std::out_of_range("Exceeded amount of elements.");
        }

        return _data[i - 1];
    }


}
