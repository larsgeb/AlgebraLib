//
// Created by Lars Gebraad on 14-8-17.
//

#ifndef LINEARALGEBRA_SPARSEVECTOR_H
#define LINEARALGEBRA_SPARSEVECTOR_H


#include <map>

class SparseVector {
public:
    std::map<int, double> _entries;
    int _numElements;
    bool _isColumn;

    SparseVector();

    explicit SparseVector(int numElements);

    // Getters and setters using operators
    double &operator[](int i);

    double &operator()(int i);

    // Output operator overload
    friend std::ostream &operator<<(std::ostream &stream, const SparseVector &SparseVector);
};



#endif //LINEARALGEBRA_SPARSEVECTOR_H
