#ifndef LINEARALGEBRA_VECTOR_HPP
#define LINEARALGEBRA_VECTOR_HPP

#include "Globals.hpp"

namespace AlgebraLib {
    /*!
     * \brief Class for full vectors.
     */
    class Vector {
    public:
        // Constructors
        /*!
         * \brief Default constructor, creates \f$ 2 \times 1 \f$ zero column vector.
         */
        Vector();

        /*!
         * \brief Constructor for row or column vector, creates 2 dimensional vector.
         * @param isColumn True if vector is a column matrix.
         */
        explicit Vector(bool isColumn);

        /*!
         * \brief Constructor for column vector.
         * @param elements Number of dimensions of vector.
         */
        explicit Vector(unsigned long elements);

        /*!
         * \brief Constructor for vector.
         * @param elements Number of dimensions of vector.
         * @param isColumn True if vector is a column matrix.
         */
        Vector(unsigned long elements, bool isColumn);

        // Public member functions
        /*!
         * \brief Retrieving private member field of dimensions of vector.
         * @return Whether or not the vector is a column vector.
         */
        const bool &isColumn() { return _isColumn; };

        const bool &isColumn() const { return _isColumn; };

        /*!
         * \brief Retrieving private member field of dimensions of vector.
         * @return Dimensions of vector.
         */
        const unsigned long &elements() { return _elements; };

        const unsigned long &elements() const { return _elements; };

        Vector Transpose();

        Vector Transpose() const;

        Vector &TransposeSelf();

        Vector Normalize();

        Vector Normalize() const;

        Vector &NormalizeSelf();

        // Getters and setters using operators
        /*!
         * \brief Access elements using zero-based index.
         * @param i \f$ i - 1\f$ mathematical index.
         * @return Element at \f$ i - 1 \f$.
         */
        double &operator[](int i);

        /*!
         * \brief Access elements of constant instance using zero-based index.
         * @param i \f$ i - 1\f$ mathematical index.
         * @return Element at \f$ i - 1 \f$.
         */
        const double &operator[](int i) const;

        /*!
         * \brief Access elements using one-based index.
         * @param i \f$ i \f$ mathematical index.
         * @return Element at \f$ i  \f$.
         */
        double &operator()(int i);

        /*!
         * \brief Access elements of constant instance using one-based index.
         * @param i \f$ i \f$ mathematical index.
         * @return Element at \f$ i  \f$.
         */
        const double &operator()(int i) const;

        // Friend functions
        friend std::ostream &operator<<(std::ostream &stream, const Vector &Vector);

        // Iterator forwards
        /*!
         * \brief Iterator begin, forwards to private _vectorContents member.
         * @return Iterator std::vector<double>::begin().
         */
        contentVectorDouble::iterator begin();

        /*!
         * \brief Iterator end, forwards to private _vectorContents member.
         * @return Iterator std::vector<double>::end().
         */
        contentVectorDouble::iterator end();

        /*!
         * \brief Iterator begin, forwards to private _vectorContents member.
         * @return Iterator std::vector<double>::begin().
         */
        contentVectorDouble::const_iterator begin() const;

        /*!
         * \brief Iterator end, forwards to private _vectorContents member.
         * @return Iterator std::vector<double>::end().
         */
        contentVectorDouble::const_iterator end() const;

        /*!
         * \brief Iterator reverse begin, forwards to private _vectorContents member.
         * @return Iterator std::vector<double>::rbegin().
         */
        contentVectorDouble::reverse_iterator rbegin();

        /*!
         * \brief Iterator reverse end, forwards to private _vectorContents member.
         * @return Iterator std::vector<double>::rend().
         */
        contentVectorDouble::reverse_iterator rend();

        /*!
         * \brief Iterator cbegin, forwards to private _vectorContents member.
         * @return Iterator std::vector<double>::cbegin().
         */
        contentVectorDouble::const_iterator cbegin() const noexcept;

        /*!
         * \brief Iterator cend, forwards to private _vectorContents member.
         * @return Iterator std::vector<double>::cend().
         */
        contentVectorDouble::const_iterator cend() const noexcept;

        /*!
         * \brief Iterator crbegin, forwards to private _vectorContents member.
         * @return Iterator std::vector<double>::crbegin().
         */
        contentVectorDouble::const_reverse_iterator crbegin() const noexcept;

        /*!
         * \brief Iterator crend, forwards to private _vectorContents member.
         * @return Iterator std::vector<double>::crend().
         */
        contentVectorDouble::const_reverse_iterator crend() const noexcept;

    private:
        // Private fields
        /*!
         * \brief Contents of vector.
         */
        contentVectorDouble _vectorContents;
        /*!
         * \brief Number of elements in vetor.
         */
        unsigned long _elements;
        /*!
         * \brief Shape of vector.
         */
        bool _isColumn;
    };

    /* --------------------------------------------------- *
     * Typedefs relying on class
     * --------------------------------------------------- */
    typedef std::vector<AlgebraLib::Vector> contentVectorVector;
}

#endif //LINEARALGEBRA_VECTOR_HPP
