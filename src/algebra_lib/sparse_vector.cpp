//
// Created by Lars Gebraad on 14-8-17.
//

#include "sparse_vector.hpp"

namespace algebra_lib {
    sparse_vector::sparse_vector() {
        _numElements = 0;
        _isColumn = true;
    };

    sparse_vector::sparse_vector(int numElements) {
        _numElements = numElements;
        _isColumn = true;
    };

    sparse_vector::sparse_vector(int numElements, bool row) {
        _numElements = numElements;
        _isColumn = row;
    }

    double sparse_vector::operator[](int i) {
        return (static_cast<const sparse_vector *>(this)->operator[](i));
    }

    const double sparse_vector::operator[](int i) const {
        if (i < 0) {
            throw std::out_of_range("Exceeded natural range for indices");
        } else if (i >= _numElements)
            throw std::out_of_range("Exceeded number of elements");

        double val = 0.0;
        try {
            return  _vectorMap.at(i);
        } catch (std::out_of_range & e){
            val = 0.0;
        }
        return val;
    }

    double &sparse_vector::operator()(int i) {
        if (i < 0) {
            throw std::out_of_range("Exceeded natural range for indices");
        } else if (i >= _numElements)
            throw std::out_of_range("Exceeded number of elements");

        // Try to find current key in sparse vector, if it does not exist, we get iterator at end of map.
        const std::map<int, double>::iterator &lookup = _vectorMap.find(i);
        if (lookup != _vectorMap.end()) {
            return lookup->second;
        }
        return _vectorMap[i];
    }

    const double sparse_vector::operator()(int i) const {
        return (this)->operator[](i);
    }

    sparse_vector sparse_vector::Transpose() {
        sparse_vector T(_numElements, !_isColumn);
        T._vectorMap = _vectorMap;
        return T;
    }

    sparse_vector sparse_vector::TransposeSelf() {
        // Does provide performance increase//less required memory over
        // SparseVector = SparseVector::Transpose().
        _isColumn = !_isColumn;
        return (*this);
    }

    sparseVectorContentDouble::const_iterator sparse_vector::begin() const {
        return _vectorMap.begin();
    }

    sparseVectorContentDouble::const_iterator sparse_vector::end() const {
        return _vectorMap.end();
    }

    sparseVectorContentDouble::reverse_iterator sparse_vector::rbegin() {
        return _vectorMap.rbegin();
    }

    sparseVectorContentDouble::reverse_iterator sparse_vector::rend() {
        return _vectorMap.rend();
    }

    sparseVectorContentDouble::const_iterator sparse_vector::cbegin() const noexcept {
        return _vectorMap.cbegin();
    }

    sparseVectorContentDouble::const_iterator sparse_vector::cend() const noexcept {
        return _vectorMap.cend();
    }

    sparseVectorContentDouble::const_reverse_iterator sparse_vector::crbegin() const noexcept {
        return _vectorMap.crbegin();
    }

    sparseVectorContentDouble::const_reverse_iterator sparse_vector::crend() const noexcept {
        return _vectorMap.crend();
    }
}
// --- end of class ---
