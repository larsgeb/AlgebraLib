//
// Created by Lars Gebraad on 14-8-17.
//

#include "SparseVector.hpp"


SparseVector::SparseVector() {
    _numElements = 0;
    _isColumn = true;
};

SparseVector::SparseVector(int numElements) {
    _numElements = numElements;
    _isColumn = true;
};

/*const double operator[](int i) const {
    if (i >= _numElements)
        throw std::out_of_range("Exceeded number of elements");

    const std::map<int, double>::const_iterator lookup = _entries.find(i);

    if (lookup != _entries.end()) {
        return lookup->second;
    }
    return 0;
}*/

double &SparseVector::operator[](int i) {
    if (i < 0) {
        throw std::out_of_range("Exceeded natural range for indices");
    } else if (i >= _numElements)
        throw std::out_of_range("Exceeded number of elements");

    // Try to find current key in sparse vector, if it does not exist, we get iterator at end of map.
    const std::map<int, double>::iterator &lookup = _entries.find(i);
    if (lookup != _entries.end()) {
        return lookup->second;
    }
    return _entries[i];

}

double &SparseVector::operator()(int i) {
    if (i < 1) {
        throw std::out_of_range("Exceeded natural range for indices");
    } else if (i > _numElements)
        throw std::out_of_range("Exceeded number of elements");

    // Try to find current key in sparse vector, if it does not exist, we get iterator at end of map.
    const std::map<int, double>::iterator &lookup = _entries.find(i - 1);
    if (lookup != _entries.end()) {
        return lookup->second;
    }
    return _entries[i - 1];

}

// --- end of class ---
