#pragma once
#include <iostream>

class Array {
    public:

    int * allocateVector(int size);
    void deleteVector(int * array);
    int ** allocateMatrix(int rows, int cols);
    void deleteMatrix(int ** array, int rows);
    void printMatrix(int ** matrix, int rows, int cols);
};