/**
 * @file SupplierArchive.h
 * @author Maximiliano Raúl Malvicino (mrmalvicino@gmail.com)
 * @brief Manages a supplier archive, allowing storage and retrieval of supplier records in a binary file.
 * @copyright GNU General Public License. Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
 */

#pragma once
#include <cstdio>
#include "Supplier.h"

class SupplierArchive {
    public:

    /**
     * @brief Constructs a new Supplier Archive object with default path.
     */
    SupplierArchive();

    /**
     * @brief Constructs a new Supplier Archive object.
     * @param path (std::string) Path where the file will be saved.
     */
    SupplierArchive(std::string path);

    /**
     * @brief Sets the Path object.
     * @param path (std::string) Path where the file will be saved.
     */
    void setPath(std::string path);

    /**
     * @brief Gets the Path object.
     * @return (std::string) Path where the file will be saved.
     */
    std::string getPath();

    /**
     * @brief Writes a supplier record to the archive file.
     * @param reg (Supplier) The supplier record to be written to the archive.
     * @return (bool) Returns true if the write operation was successful, false otherwise.
     * @note The file is opened in binary append mode ("ab") to ensure that new records are appended to the end of the file without overwriting existing data. If the file cannot be opened, an error message is printed to standard error.
     */
    bool write(Supplier & reg);

    /**
     * @brief Overwrites a supplier record at the specified index in the archive file.
     * @param reg (Supplier) The new supplier record that will overwrite the existing record.
     * @param index (int) The index of the record to be overwritten.
     * @return (bool) Returns true if the write operation was successful, false otherwise.
     * @note The file is opened in binary read-write mode ("rb+") to allow modification of existing records without affecting other parts of the file. If the file cannot be opened, an error message is printed to standard error.
     */
    bool overWrite(Supplier & reg, int index);

    /**
     * @brief Reads a supplier record from the archive file at a given index.
     * @param index (int) The index of the record to be read.
     * @return (Supplier) Returns a supplier record read from the archive file.
     * @note The file is opened in binary read mode ("rb"). An empty supplier wil be returned if there is a reading error or if the specified index is out of bounds.
     */
    Supplier read(int index);

    /**
     * @brief Finds the index of a supplier record with a given ID.
     * @param id (int) The ID of the supplier record to search for.
     * @return (int) The index of the matching supplier record.
     */
    int getIndex(int id);

    /**
     * @brief Finds the index of a supplier record with a given description.
     * @param description (std::string) The description of the supplier record to search for.
     * @return (int) The index of the matching supplier record or -1 in case the input does not match any record.
     */
    int getIndex(std::string & description);

    /**
     * @brief Retrieves the total number of supplier records stored in the archive file.
     * @return (int) Amount of supplier records stored in the archive file.
     * @note Calculates the number of records by dividing the file's size by the size of each supplier record.
     */
    int getAmountOfRegisters();

    /**
     * @brief Creates an empty supplier archive file.
     * @warning The method does not check if the file already exists; it will create a new empty file or overwrite an existing one.
     */
    void createEmptySupplierArchive();

    private:

    std::string _path; // Path where the file will be saved
};