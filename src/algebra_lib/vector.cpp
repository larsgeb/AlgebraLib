//
// Created by Lars Gebraad on 16-8-17.
//

#include "full_algebra.hpp"
#include <cmath>
#include "vector.hpp"

namespace algebra_lib {
    vector::vector(unsigned long elements, bool isColumn) {
        _isColumn = isColumn;
        _elements = elements;
        _vectorContents = std::vector<double>(_elements, 0.0);
    };

    vector::vector(unsigned long elements) {
        _isColumn = true;
        _elements = elements;
        _vectorContents = std::vector<double>(_elements, 0.0);

    };

    vector::vector() {
        _isColumn = true;
        _elements = 2;
        _vectorContents = std::vector<double>(_elements, 0.0);
    };

    vector::vector(bool isColumn) {
        _isColumn = isColumn;
        _elements = 2;
        _vectorContents = std::vector<double>(_elements, 0.0);
    };

    double &vector::operator[](int i) {
        if (i < 0) {
            throw std::out_of_range("Out of natural range for vectors.");
        } else if (i >= _elements) {
            throw std::out_of_range("Exceeded amount of elements.");
        }

        return _vectorContents[i];
    }

    const double &vector::operator[](int i) const {
        if (i < 0) {
            throw std::out_of_range("Out of natural range for vectors.");
        } else if (i >= _elements) {
            throw std::out_of_range("Exceeded amount of elements.");
        }

        return _vectorContents[i];
    }

    double &vector::operator()(int i) {
        if (i - 1 < 0) {
            throw std::out_of_range("Out of natural range for vectors.");
        } else if (i - 1 >= _elements) {
            throw std::out_of_range("Exceeded amount of elements.");
        }

        return _vectorContents[i - 1];
    }

    const double &vector::operator()(int i) const {
        if (i - 1 < 0) {
            throw std::out_of_range("Out of natural range for vectors.");
        } else if (i - 1 >= _elements) {
            throw std::out_of_range("Exceeded amount of elements.");
        }

        return _vectorContents[i - 1];
    }

    contentVectorDouble::iterator vector::begin() {
        return _vectorContents.begin();
    }

    contentVectorDouble::iterator vector::end() {
        return _vectorContents.end();
    }

    contentVectorDouble::const_iterator vector::begin() const {
        return _vectorContents.begin();
    }

    contentVectorDouble::const_iterator vector::end() const {
        return _vectorContents.end();
    }

    contentVectorDouble::reverse_iterator vector::rbegin() {
        return _vectorContents.rbegin();
    }

    contentVectorDouble::reverse_iterator vector::rend() {
        return _vectorContents.rend();
    }

    contentVectorDouble::const_iterator vector::cbegin() const noexcept {
        return _vectorContents.cbegin();
    }

    contentVectorDouble::const_iterator vector::cend() const noexcept {
        return _vectorContents.cend();
    }

    contentVectorDouble::const_reverse_iterator vector::crbegin() const noexcept {
        return _vectorContents.crbegin();
    }

    contentVectorDouble::const_reverse_iterator vector::crend() const noexcept {
        return _vectorContents.crend();
    }

    vector vector::Transpose() {
        return static_cast<vector>(static_cast<const vector *>(this)->Transpose());
    }

    vector vector::Transpose() const {
        vector Ut = (*this);
        Ut._isColumn = !_isColumn;
        return Ut;
    }

    vector &vector::TransposeSelf() {
        _isColumn = !_isColumn;
        return (*this);
    }

    vector vector::Normalize() {
        return static_cast<vector>(static_cast<const vector *>(this)->Normalize());
    }

    vector vector::Normalize() const {
        return (*this) / sqrt((*this) * (*this));
    }

    vector &vector::NormalizeSelf() {
        (*this) = (*this).Normalize();
        return (*this);
    }
}
