//
// Created by Lars Gebraad on 14-8-17.
//

#include <ctime>
#include "src/AlgebraLib/AlgebraLib.hpp"


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

    std::cout << PSD.CholeskyDecompose();
    std::cout << PSD.CholeskyDecompose().InvertLowerTriangular();
    std::cout << PSD.CholeskyDecompose() * PSD.CholeskyDecompose().InvertLowerTriangular();

    // That works, nice.

    return EXIT_SUCCESS;
}