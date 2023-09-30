#include "../headers/Array.h"

int * Array::allocateVector(int size) {
    int * array = new int[size]; // Crea un puntero de enteros

    for (int i = 0; i < size; i ++) { // Asigna cero en cada componente
        array[i] = 0;
    }

    return array;
}

void Array::deleteVector(int * array) {
    delete [] array; // Libera el puntero
}

int ** Array::allocateMatrix(int rows, int cols) {
    int ** matrix = new int * [rows]; // Crea un puntero de punteros de enteros

    for (int i = 0; i < rows; i ++) {
        matrix[i] = allocateVector(cols);
    }

    for (int i = 0; i < rows; i ++) { // Asigna cero en cada componente
        for (int j = 0; j < cols; j ++) {
            matrix[i][j] = 0;
        }
    }

    return matrix;
}

void Array::deleteMatrix(int ** matrix, int rows) {
    for (int i = 0; i < rows; i ++) {
        deleteVector(matrix[i]); // Libera cada puntero del puntero
    }

    delete [] matrix; // Libera el puntero externo
}

void Array::printMatrix(int ** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i ++) {
        for (int j = 0; j < cols; j ++) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << "\n";
    }
}