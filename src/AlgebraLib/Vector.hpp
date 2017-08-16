//
// Created by Lars Gebraad on 16-8-17.
//

#ifndef LINEARALGEBRA_VECTOR_HPP
#define LINEARALGEBRA_VECTOR_HPP

#include <iostream>
#include <vector>

namespace AlgebraLib {
    class Vector {
    public:
        typedef std::vector<double> Vector1D;

        // Constructors
        Vector();

        explicit Vector(bool isColumn);

        explicit Vector(unsigned long elements);

        Vector(unsigned long elements, bool isColumn);

        // Public fields
        unsigned long _elements;
        bool _isColumn;

        // Getters and setters using operators
        double &operator[](int i);

        const double &operator[](int i) const;

        double &operator()(int i);

        const double &operator()(int i) const;


        // Member functions

        // Friend functions
        friend std::ostream &operator<<(std::ostream &stream, const Vector &Vector);

//    private:
        // Private fields
        Vector1D _data;

    };
}

#endif //LINEARALGEBRA_VECTOR_HPP
