//
// Created by Lars Gebraad on 14-8-17.
//

#include <ctime>
#include <iomanip>
#include "SparseLinearAlgebra/src/AlgebraLib/algebra_lib.hpp"


int main() {
    AlgebraLib::Matrix PSD(3, 3);

    PSD[0][0] = 4;
    PSD[0][1] = 12;
    PSD[0][2] = -16;
    PSD[1][0] = 12;
    PSD[1][1] = 37;
    PSD[1][2] = -43;
    PSD[2][0] = -16;
    PSD[2][1] = -43;
    PSD[2][2] = 98;


    AlgebraLib::WriteMatrix(PSD.CholeskyDecompose().InvertLowerTriangular(),"Matrix.txt");


    AlgebraLib::Matrix A = AlgebraLib::ReadMatrix("Matrix.txt");

    std::cout << A.InvertLowerTriangular() * A;

    return EXIT_SUCCESS;
}