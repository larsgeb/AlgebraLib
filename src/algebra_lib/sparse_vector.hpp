#ifndef LINEARALGEBRA_SPARSEVECTOR_H
#define LINEARALGEBRA_SPARSEVECTOR_H

#include "globals.hpp"

namespace algebra_lib {
    /*!
     * \brief Class for sparse vectors.
     */
    // Type definitions
    typedef std::map<unsigned int, double> sparseVectorContentDouble;

    class sparse_vector {
    public:
        // Fields


        // Constructors
        sparse_vector();

        explicit sparse_vector(unsigned int numElements);

        sparse_vector(unsigned int numElements, bool isColumn);

        // Getters and setters using operators
        double operator[](unsigned int i);

        const double operator[](unsigned int i) const;

        double &operator()(unsigned int i);

        const double operator()(unsigned int i) const;

        sparseVectorContentDouble::const_iterator begin() const;

        sparseVectorContentDouble::const_iterator end() const;

        sparseVectorContentDouble::reverse_iterator rbegin();

        sparseVectorContentDouble::reverse_iterator rend();

        sparseVectorContentDouble::const_iterator cbegin() const noexcept;

        sparseVectorContentDouble::const_iterator cend() const noexcept;

        sparseVectorContentDouble::const_reverse_iterator crbegin() const noexcept;

        sparseVectorContentDouble::const_reverse_iterator crend() const noexcept;

        // Member functions
        sparse_vector Normalize() const;

        sparse_vector Transpose() const;

        sparse_vector TransposeSelf();

        std::map<unsigned int, double>::const_iterator find(const unsigned int &key) const;

        unsigned int size() const { return _numElements; }

        bool isColumn() const { return _isColumn; }

        void eraseEntry(unsigned int element) { _vectorMap.erase(element); }

        // Friend functions
        friend std::ostream &operator<<(std::ostream &stream, const sparse_vector &SparseVector);

    private:
        unsigned _numElements;
        bool _isColumn;
        sparseVectorContentDouble _vectorMap;

    };
}


#endif //LINEARALGEBRA_SPARSEVECTOR_H
