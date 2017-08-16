//
// Created by Lars Gebraad on 16-8-17.
//

#ifndef LINEARALGEBRA_MATRIX_HPP
#define LINEARALGEBRA_MATRIX_HPP

#include <iostream>
#include "Vector.hpp"

namespace AlgebraLib {
    class Matrix {
    public:
        typedef std::vector<AlgebraLib::Vector> Vector2D;

        // Constructors
        Matrix();

        Matrix(unsigned long rows, unsigned long columns);

        // Public fields
        unsigned long _columns;
        unsigned long _rows;

        // Getters and setters using operators
        Vector &operator[](int i);

        const Vector &operator[](int i) const;

        Vector &operator()(int i);

        const Vector &operator()(int i) const;


        // Member functions

        // Friend functions
        friend std::ostream &operator<<(std::ostream &stream, const Matrix &Matrix);

//    private:
        // Private fields
        Vector2D _data;

    };
}

#endif //LINEARALGEBRA_MATRIX_HPP
