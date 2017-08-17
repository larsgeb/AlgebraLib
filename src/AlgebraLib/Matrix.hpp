#ifndef LINEARALGEBRA_MATRIX_HPP
#define LINEARALGEBRA_MATRIX_HPP

#include "Globals.hpp"
#include "Vector.hpp"

namespace AlgebraLib {
    /*!
     * \brief Class for full matrices.
     */
    class Matrix {
    public:
        // Constructors
        /*!
         * \brief Default constructor.
         *
         * Creates zero matrix of size \f$ 2 \times 2\f$.
         */
        Matrix();

        /*!
         * \brief Constructor for specified matrix size.
         *
         * @param rows rows in matrix
         * @param columns columns in matrix
         *
         * Creates zero matrix of size \f$ rows \times columns\f$.
         */
        Matrix(unsigned long rows, unsigned long columns);

        // Member functions
        Matrix InvertLowerTriangular();
        Matrix InvertLowerTriangular() const;
        Matrix InvertMatrixElements(bool preserveZero = false);
        Matrix InvertMatrixElements(bool preserveZero = false) const;
        Matrix & InvertMatrixElementsSelf(bool preserveZero = false);
        Matrix Transpose();
        Matrix & TransposeSelf();
        Matrix Transpose() const;
        Vector Trace(int offset = 0);
        Vector Trace(int offset = 0) const;
        Matrix CholeskyDecompose();
        Matrix CholeskyDecompose() const;
        Vector SolveLowerTriangular(Vector &Y);
        Vector SolveLowerTriangular(Vector &Y) const;

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
        Vector &operator[](int i);

        /*!
         * \brief Access by reference of constant instance through operator, one based.
         * @param i \f$ i - 1 \f$ one based (mathematical) index.
         * @return Vector component at one based (mathematical) index.
         */
        const Vector &operator[](int i) const;

        /*!
         * \brief Access by reference through operator, zero based.
         * @param i \f$ i \f$ one based (mathematical) index.
         * @return Vector component at one based (mathematical) index.
         */
        Vector &operator()(int i);

        /*!
         * \brief Access by reference of constant instance through operator, one based.
         * @param i \f$ i \f$ one based (mathematical) index.
         * @return Vector component at one based (mathematical) index.
         */
        const Vector &operator()(int i) const;

        Vector getColumn(int i);

        const Vector getColumn(int i) const;

        Matrix setColumn(int i, Vector &Vector);

        Matrix setColumn(int i, Vector Vector);

        // Friend functions
        friend std::ostream &operator<<(std::ostream &stream, const Matrix &Matrix);

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
