#ifndef LINEARALGEBRA_SPARSEVECTOR_H
#define LINEARALGEBRA_SPARSEVECTOR_H

#include "globals.hpp"

namespace algebra_lib {
    /*!
     * \brief Class for sparse vectors.
     */
    // Type definitions
    typedef std::map<int, double> sparseVectorContentDouble;

    class sparse_vector {
    public:
        // Fields
        sparseVectorContentDouble _vectorMap;

        bool _isColumn;

        // Constructors
        explicit sparse_vector();

        explicit sparse_vector(int numElements);

        sparse_vector(int numElements, bool isColumn);

        // Getters and setters using operators
        double operator[](int i);

        const double operator[](int i) const;

        double &operator()(int i);

        const double operator()(int i) const;

        sparseVectorContentDouble::const_iterator begin() const;

        sparseVectorContentDouble::const_iterator end() const;

        sparseVectorContentDouble::reverse_iterator rbegin();

        sparseVectorContentDouble::reverse_iterator rend();

        sparseVectorContentDouble::const_iterator cbegin() const noexcept;

        sparseVectorContentDouble::const_iterator cend() const noexcept;

        sparseVectorContentDouble::const_reverse_iterator crbegin() const noexcept;

        sparseVectorContentDouble::const_reverse_iterator crend() const noexcept;

        // Member functions
        sparse_vector Transpose();

        sparse_vector TransposeSelf();

        double elements() const { return _numElements;}

        // Friend functions
        friend std::ostream &operator<<(std::ostream &stream, const sparse_vector &SparseVector);

    private:
        int _numElements;

    };
}


#endif //LINEARALGEBRA_SPARSEVECTOR_H
