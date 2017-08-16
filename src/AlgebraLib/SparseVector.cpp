//
// Created by Lars Gebraad on 14-8-17.
//

#include "SparseVector.hpp"

namespace AlgebraLib {
    SparseVector::SparseVector() {
        _numElements = 0;
        _isColumn = true;
    };

    SparseVector::SparseVector(int numElements) {
        _numElements = numElements;
        _isColumn = true;
    };

    SparseVector::SparseVector(int numElements, bool row) {
        _numElements = numElements;
        _isColumn = row;
    }

// Indexing using operators on mutable and constant instantiations.
    double &SparseVector::operator[](int i) {
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

    const double &SparseVector::operator[](int i) const {
        if (i < 0) {
            throw std::out_of_range("Exceeded natural range for indices");
        } else if (i >= _numElements)
            throw std::out_of_range("Exceeded number of elements");

        /*
        // Try to find current key in sparse vector, if it does not exist, we get iterator at end of map.
        auto lookup = _vectorMap.find(i);
        if (lookup != _vectorMap.end()) {
            return lookup->second;
        }

        // Very bad below!
        const double &a = 0.0;
            return a;
        */

        return _vectorMap.at(i);
    }

    double &SparseVector::operator()(int i) {
        if (i < 1) {
            throw std::out_of_range("Exceeded natural range for indices");
        } else if (i > _numElements)
            throw std::out_of_range("Exceeded number of elements");

        // Try to find current key in sparse vector, if it does not exist, we get iterator at end of map.
        const std::map<int, double>::iterator &lookup = _vectorMap.find(i - 1);
        if (lookup != _vectorMap.end()) {
            return lookup->second;
        }
        return _vectorMap[i - 1];
    }

    const double &SparseVector::operator()(int i) const {
        if (i < 1) {
            throw std::out_of_range("Exceeded natural range for indices");
        } else if (i > _numElements)
            throw std::out_of_range("Exceeded number of elements");

        /*
        // Try to find current key in sparse vector, if it does not exist, we get iterator at end of map.
        auto lookup = _vectorMap.find(i);
        if (lookup != _vectorMap.end()) {
            return lookup->second;
        }

        // Very bad below
        const double &a = 0.0;
            return a;
        */

        return _vectorMap.at(i - 1);

    }

    SparseVector SparseVector::Transpose() {
        SparseVector T(_numElements, !_isColumn);
        T._vectorMap = _vectorMap;
        return T;
    }

    SparseVector SparseVector::TransposeSelf() {
        // Does provide performance increase//less required memory over
        // SparseVector = SparseVector::Transpose().
        _isColumn = !_isColumn;
        return (*this);
    }

    /*SparseVector::SparseVector(const SparseVector &rhs) {
        _isColumn = rhs._isColumn;
        _numElements = rhs._numElements;
        _vectorMap = rhs._vectorMap;
    }*/
}
// --- end of class ---
