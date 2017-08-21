#ifndef LINEARALGEBRA_SPARSEVECTOR_H
#define LINEARALGEBRA_SPARSEVECTOR_H

#include "globals.hpp"

namespace algebra_lib {
    /*!
     * \brief Class for sparse vectors.
     */
    class sparse_vector {
    public:
        // Type definitions
        typedef std::map<int, double> VectorMap;

        // Fields
        VectorMap _vectorMap;
        int _numElements;
        bool _isColumn;

        // Constructors
        explicit sparse_vector();

//        SparseVector(const SparseVector &rhs);

        explicit sparse_vector(int numElements);

        sparse_vector(int numElements, bool isColumn);

        // Getters and setters using operators
        double &operator[](int i);

        const double &operator[](int i) const;

        double &operator()(int i);

        const double &operator()(int i) const;

        // Member functions
        sparse_vector Transpose();

        sparse_vector TransposeSelf();

        // Friend functions
        friend std::ostream &operator<<(std::ostream &stream, const sparse_vector &SparseVector);
    };
}


#endif //LINEARALGEBRA_SPARSEVECTOR_H
