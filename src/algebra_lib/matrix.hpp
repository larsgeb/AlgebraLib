#ifndef LINEARALGEBRA_MATRIX_HPP
#define LINEARALGEBRA_MATRIX_HPP

#include "globals.hpp"
#include "vector.hpp"

namespace algebra_lib {
    /*!
     * \brief Class for full matrices.
     */
    class matrix {
    public:
        // Constructors
        /*!
         * \brief Default constructor.
         *
         * Creates zero matrix of size \f$ 2 \times 2\f$.
         */
        matrix();

        /*!
         * \brief Constructor for specified matrix size.
         *
         * @param rows rows in matrix
         * @param columns columns in matrix
         *
         * Creates zero matrix of size \f$ rows \times columns\f$.
         */
        matrix(unsigned long rows, unsigned long columns);

        // Member functions
        matrix InvertLowerTriangular();
        matrix InvertLowerTriangular() const;
        matrix InvertMatrixElements(bool preserveZero = false);
        matrix InvertMatrixElements(bool preserveZero = false) const;
        matrix & InvertMatrixElementsSelf(bool preserveZero = false);
        matrix Transpose();
        matrix & TransposeSelf();
        matrix Transpose() const;
        vector Trace(int offset = 0);
        vector Trace(int offset = 0) const;
        matrix CholeskyDecompose();
        matrix CholeskyDecompose() const;
        vector SolveLowerTriangular(vector &Y);
        vector SolveLowerTriangular(vector &Y) const;
        matrix & Unit();

        // Read only field accessing
        /*!
         * Access read only field columns by reference.
         * @return Columns of matrix
         */
        const unsigned long &columns() const { return _columns; }

        /*!
         * Access read only field rows by reference.
         * @return rows of matrix
         */
        const unsigned long &rows() const { return _rows; }

        // Getters and setters using operators
        /*!
         * \brief Access by reference through operator, zero based.
         * @param i \f$ i - 1 \f$ one based (mathematical) index.
         * @return Vector component at one based (mathematical) index.
         */
        vector &operator[](int i);

        /*!
         * \brief Access by reference of constant instance through operator, one based.
         * @param i \f$ i - 1 \f$ one based (mathematical) index.
         * @return Vector component at one based (mathematical) index.
         */
        const vector &operator[](int i) const;

        /*!
         * \brief Access by reference through operator, zero based.
         * @param i \f$ i \f$ one based (mathematical) index.
         * @return Vector component at one based (mathematical) index.
         */
        vector &operator()(int i);

        /*!
         * \brief Access by reference of constant instance through operator, one based.
         * @param i \f$ i \f$ one based (mathematical) index.
         * @return Vector component at one based (mathematical) index.
         */
        const vector &operator()(int i) const;

        vector getColumn(int i);

        const vector getColumn(int i) const;

        matrix setColumn(int i, vector Vector);

        // Friend functions
        friend std::ostream &operator<<(std::ostream &stream, const matrix &Matrix);

        // Iterator forwards
        /*!
         * \brief Iterator begin, forwards to private _matrixContents member.
         * @return Iterator std::vector<Vector>::begin().
         */
        contentVectorVector::iterator begin();

        /*!
         * \brief Iterator end, forwards to private _matrixContents member.
         * @return Iterator std::vector<Vector>::end().
         */
        contentVectorVector::iterator end();

        /*!
         * \brief Iterator begin, forwards to private _matrixContents member.
         * @return Iterator std::vector<Vector>::begin().
         */
        contentVectorVector::const_iterator begin() const;

        /*!
         * \brief Iterator end, forwards to private _matrixContents member.
         * @return Iterator std::vector<Vector>::end().
         */
        contentVectorVector::const_iterator end() const;

        /*!
         * \brief Iterator reverse begin, forwards to private _matrixContents member.
         * @return Iterator std::vector<Vector>::rbegin().
         */
        contentVectorVector::reverse_iterator rbegin();

        /*!
         * \brief Iterator reverse end, forwards to private _matrixContents member.
         * @return Iterator std::vector<Vector>::rend().
         */
        contentVectorVector::reverse_iterator rend();

        /*!
         * \brief Iterator cbegin, forwards to private _matrixContents member.
         * @return Iterator std::vector<Vector>::cbegin().
         */
        contentVectorVector::const_iterator cbegin() const noexcept;

        /*!
         * \brief Iterator cend, forwards to private _matrixContents member.
         * @return Iterator std::vector<Vector>::cend().
         */
        contentVectorVector::const_iterator cend() const noexcept;

        /*!
         * \brief Iterator crbegin, forwards to private _matrixContents member.
         * @return Iterator std::vector<Vector>::crbegin().
         */
        contentVectorVector::const_reverse_iterator crbegin() const noexcept;

        /*!
         * \brief Iterator crend, forwards to private _matrixContents member.
         * @return Iterator std::vector<Vector>::crend().
         */
        contentVectorVector::const_reverse_iterator crend() const noexcept;

    private:
        // Private fields
        /*!
         * \brief Columns in matrix. Can not be changed after initialization.
         */
        unsigned long _columns;

        /*!
         * \brief Rows in matrix. Can not be changed after initialization.
         */
        unsigned long _rows;

        /**
         * \brief Instance of std::vector<Vector> which contains matrix rows.
         */
        contentVectorVector _matrixContents;

    };
}

#endif //LINEARALGEBRA_MATRIX_HPP
