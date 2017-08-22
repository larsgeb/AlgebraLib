//
// Created by Lars Gebraad on 14-8-17.
//

#include <ctime>
#include <iomanip>
#include "src/algebra_lib/algebra_lib.hpp"

using namespace algebra_lib;

int main() {

    /*matrix PSD(3, 3);

    PSD[0][0] = 4;
    PSD[0][1] = 12;
    PSD[0][2] = -16;
    PSD[1][0] = 12;
    PSD[1][1] = 37;
    PSD[1][2] = -43;
    PSD[2][0] = -16;
    PSD[2][1] = -43;
    PSD[2][2] = 98;


    WriteMatrix(PSD.CholeskyDecompose().InvertLowerTriangular(),"Matrix.txt");


    matrix A = ReadMatrix("Matrix.txt");

    std::cout << A.InvertLowerTriangular() * A;*/

    sparse_matrix B(501, 501);

    sparse_matrix A = ParallelMatrixProduct(B, B);
    std::cout << A;

    return EXIT_SUCCESS;
}