/**
 * @file ProductsArchive.h
 * @author Maximiliano Raúl Malvicino (mrmalvicino@gmail.com)
 * @brief Represents an archive of products.
 * @copyright GNU General Public License. Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
 */

#pragma once
#include <iostream>
#include <cstdio>
#include "Product.h"

class ProductsArchive {
    public:

    /**
     * @brief Constructs a new ProductsArchive object with a default path.
     */
    ProductsArchive();

    /**
     * @brief Constructs a new ProductsArchive object with a custom path.
     */
    ProductsArchive(const std::string & path);

    /**
     * @brief Sets the _path attribute.
     * @param path (std::string) Path where the file will be saved.
     */
    void setPath(const std::string & path);

    /**
     * @brief Gets the _path attribute.
     * @return (std::string) Path where the file will be saved.
     */
    std::string getPath();

    /**
     * @brief Writes a product record to the archive file.
     * @param reg (Product) The product record to be written to the archive.
     * @return (bool) Returns true if the write operation was successful, false otherwise.
     * @note The file is opened in binary append mode ("ab") to ensure that new records are appended to the end of the file without overwriting existing data. If the file cannot be opened, an error message is printed to standard error.
     */
    bool write(Product & reg);

    /**
     * @brief Overwrites a product record at the specified index in the archive file.
     * @param reg (Product) The new product record that will overwrite the existing record.
     * @param index (int) The index of the record to be overwritten.
     * @return (bool) Returns true if the write operation was successful, false otherwise.
     * @note The file is opened in binary read-write mode ("rb+") to allow modification of existing records without affecting other parts of the file. If the file cannot be opened, an error message is printed to standard error.
     */
    bool overWrite(Product & reg, int index);

    /**
     * @brief Reads a product record from the archive file at a given index.
     * @param index (int) The index of the record to be read.
     * @return (Product) Returns a product record read from the archive file.
     * @note The file is opened in binary read mode ("rb"). An empty product wil be returned if there is a reading error or if the specified index is out of bounds.
     */
    Product read(int index);

    /**
     * @brief Finds the index of a product record with a given ID.
     * @param id (int) The ID of the product record to search for.
     * @return (int) The index of the matching product record.
     */
    int getIndex(int id);

    /**
     * @brief Finds the index of a product record with for a given name, brand and model.
     * @param description (Product) The product to search.
     * @return (int) The index of the matching product record or -1 in case the input does not match any record.
     */
    int getIndex(Product & product);

    /**
     * @brief Retrieves the total number of product records stored in the archive file.
     * @return (int) Amount of product records stored in the archive file.
     * @note Calculates the number of records by dividing the file's size by the size of each product record.
     */
    int getAmountOfRegisters();

    /**
     * @brief Creates an empty product archive file.
     * @warning The method does not check if the file already exists; it will create a new empty file or overwrite an existing one.
     */
    void createEmptyArchive();

    private:

    /**
     * @brief Path where the file will be saved.
     */
    std::string _path;
};