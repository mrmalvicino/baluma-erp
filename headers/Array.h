/**
 * @file Array.h
 * @author Maximiliano Raúl Malvicino (mrmalvicino@gmail.com)
 * @brief Utility class to work with arrays.
 * @copyright GNU General Public License. Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
 */

#pragma once
#include <iostream>

class Array {
    public:

    /**
     * @brief Allocates and initializes a dynamic array of integers of the specified size.
     * @param size (int) Number of elements in the array to allocate.
     * @return array (int *) Pointer to the newly allocated array of integers. It is the caller's responsibility to free the memory when it's no longer needed.
     */
    int * allocateVector(int size);

    /**
     * @brief Deallocates a dynamic array of integers.
     * @param array (int *) Pointer to the dynamic array of integers to be deallocated.
     */
    void deleteVector(int * array);

    /**
     * @brief Allocates and initializes a dynamic 2D matrix of integers with the specified number of rows and columns.
     * @param rows (int) Number of rows in the matrix.
     * @param cols (int) Number of columns in the matrix.
     * @return matrix (int **) Pointer to the newly allocated 2D matrix of integers. It is the caller's responsibility to free the memory when it's no longer needed.
     */
    int ** allocateMatrix(int rows, int cols);

    /**
     * @brief Deallocates a dynamic 2D matrix of integers.
     * @param array (int **) Pointer to the dynamic 2D matrix to be deallocated.
     * @param rows (int) Number of rows in the matrix.
     */
    void deleteMatrix(int ** array, int rows);

    /**
     * @brief Prints the content of a 2D matrix of integers to the standard output.
     * @param matrix (int **) Pointer to the 2D matrix of integers to be printed.
     * @param rows (int) Number of rows in the matrix.
     * @param cols (int) number of columns in the matrix.
     */
    void printMatrix(int ** matrix, int rows, int cols);
};