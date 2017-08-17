//
// Created by Lars Gebraad on 16-8-17.
//

#include "FullAlgebra.hpp"
#include <cmath>
#include "Vector.hpp"

namespace AlgebraLib {
    Vector::Vector(unsigned long elements, bool isColumn) {
        _isColumn = isColumn;
        _elements = elements;
        _vectorContents = std::vector<double>(_elements, 0.0);
    };

    Vector::Vector(unsigned long elements) {
        _isColumn = true;
        _elements = elements;
        _vectorContents = std::vector<double>(_elements, 0.0);

    };

    Vector::Vector() {
        _isColumn = true;
        _elements = 2;
        _vectorContents = std::vector<double>(_elements, 0.0);
    };

    Vector::Vector(bool isColumn) {
        _isColumn = isColumn;
        _elements = 2;
        _vectorContents = std::vector<double>(_elements, 0.0);
    };

    double &Vector::operator[](int i) {
        if (i < 0) {
            throw std::out_of_range("Out of natural range for vectors.");
        } else if (i >= _elements) {
            throw std::out_of_range("Exceeded amount of elements.");
        }

        return _vectorContents[i];
    }

    const double &Vector::operator[](int i) const {
        if (i < 0) {
            throw std::out_of_range("Out of natural range for vectors.");
        } else if (i >= _elements) {
            throw std::out_of_range("Exceeded amount of elements.");
        }

        return _vectorContents[i];
    }

    double &Vector::operator()(int i) {
        if (i - 1 < 0) {
            throw std::out_of_range("Out of natural range for vectors.");
        } else if (i - 1 >= _elements) {
            throw std::out_of_range("Exceeded amount of elements.");
        }

        return _vectorContents[i - 1];
    }

    const double &Vector::operator()(int i) const {
        if (i - 1 < 0) {
            throw std::out_of_range("Out of natural range for vectors.");
        } else if (i - 1 >= _elements) {
            throw std::out_of_range("Exceeded amount of elements.");
        }

        return _vectorContents[i - 1];
    }

    contentVectorDouble::iterator Vector::begin() {
        return _vectorContents.begin();
    }

    contentVectorDouble::iterator Vector::end() {
        return _vectorContents.end();
    }

    contentVectorDouble::const_iterator Vector::begin() const {
        return _vectorContents.begin();
    }

    contentVectorDouble::const_iterator Vector::end() const {
        return _vectorContents.end();
    }

    contentVectorDouble::reverse_iterator Vector::rbegin() {
        return _vectorContents.rbegin();
    }

    contentVectorDouble::reverse_iterator Vector::rend() {
        return _vectorContents.rend();
    }

    contentVectorDouble::const_iterator Vector::cbegin() const noexcept {
        return _vectorContents.cbegin();
    }

    contentVectorDouble::const_iterator Vector::cend() const noexcept {
        return _vectorContents.cend();
    }

    contentVectorDouble::const_reverse_iterator Vector::crbegin() const noexcept {
        return _vectorContents.crbegin();
    }

    contentVectorDouble::const_reverse_iterator Vector::crend() const noexcept {
        return _vectorContents.crend();
    }

    Vector Vector::Transpose() {
        return static_cast<Vector>(static_cast<const Vector *>(this)->Transpose());
    }

    Vector Vector::Transpose() const {
        Vector Ut = (*this);
        Ut._isColumn = !_isColumn;
        return Ut;
    }

    Vector &Vector::TransposeSelf() {
        _isColumn = !_isColumn;
        return (*this);
    }

    Vector Vector::Normalize() {
        return static_cast<Vector>(static_cast<const Vector *>(this)->Normalize());
    }

    Vector Vector::Normalize() const {
        return (*this)/sqrt((*this) * (*this));
    }

    Vector &Vector::NormalizeSelf() {
        (*this) = (*this).Normalize();
        return (*this);
    }
}
