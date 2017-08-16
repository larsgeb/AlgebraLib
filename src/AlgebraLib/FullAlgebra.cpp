//
// Created by Lars Gebraad on 16-8-17.
//
#include <iostream>
#include "FullAlgebra.hpp"

namespace AlgebraLib {
    std::ostream &operator<<(std::ostream &stream, const Vector &Vector) {
        stream << "Full " << (Vector._isColumn ? "column" : "row");
        stream << " vector of dimension " << Vector._elements << ":" << std::endl;
        for (auto &&item : Vector._data) {
            stream << "\t" << item;
            if (Vector._isColumn)
                stream << std::endl;
        }
        stream << std::endl;
        return stream;
    }

    std::ostream &operator<<(std::ostream &stream, const AlgebraLib::Matrix &Matrix) {
        int row = 1;
        stream << "Full matrix of dimension " << Matrix._rows << "x";
        stream << Matrix._columns << ":" << std::endl;
        for (auto &&item : Matrix._data) {
            stream << "row " << row << "\t|\t";
            for (auto &&item2 : item._data) {
                stream << item2 << "\t";
            }
            stream << std::endl;
            row++;
        }
        return stream;
    }

}