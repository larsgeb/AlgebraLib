#ifndef LINEARALGEBRA_SPARSEVECTOR_H
#define LINEARALGEBRA_SPARSEVECTOR_H

#include "globals.hpp"

namespace algebra_lib {
    /*!
     * \brief Class for sparse vectors.
     */
    class SparseVector {
    public:
        // Type definitions
        typedef std::map<int, double> VectorMap;

        // Fields
        VectorMap _vectorMap;
        int _numElements;
        bool _isColumn;

        // Constructors
        SparseVector();

//        SparseVector(const SparseVector &rhs);

        explicit SparseVector(int numElements);

        SparseVector(int numElements, bool isColumn);

        // Getters and setters using operators
        double &operator[](int i);

        const double &operator[](int i) const;

        double &operator()(int i);

        const double &operator()(int i) const;

        // Member functions
        SparseVector Transpose();

        SparseVector TransposeSelf();

        // Friend functions
        friend std::ostream &operator<<(std::ostream &stream, const SparseVector &SparseVector);
    };
}


#endif //LINEARALGEBRA_SPARSEVECTOR_H
