/**
 * @file WarehousesArchive.h
 * @author Franco Baez (Francobaez2309@gmail.com)
 * @brief Represents an archive of warehouses.
 * @copyright GNU General Public License. Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
 */

#pragma once
#include "Warehouse.h"

class WarehousesArchive
{
    public:

    /**
     * @brief Constructs a new WarehousesArchive object with default path.
     */
    WarehousesArchive();

    /**
     * @brief Constructs a new WarehousesArchive object.
     * @param path (std::string) Path where the file will be saved.
     */
    WarehousesArchive(const std::string &path);

    /**
     * @brief Sets the _path attribute.
     * @param path (std::string) Path where the file will be saved.
     */
    void setPath(const std::string &path);

    /**
     * @brief Gets the _path attribute.
     * @return (std::string) Path where the file will be saved.
     */
    std::string getPath() const;

    /**
     * @brief Writes a warehouse record to the archive file.
     * @param reg (Warehouse) The warehouse record to be written to the archive.
     * @return (bool) Returns true if the write operation was successful, false otherwise.
     * @note The file is opened in binary append mode ("ab") to ensure that new records are appended to the end of the file without overwriting existing data. If the file cannot be opened, an error message is printed to standard error.
     */
    bool write(Warehouse &reg);

    /**
     * @brief Overwrites a warehouse record at the specified index in the archive file.
     * @param reg (Warehouse) The new warehouse record that will overwrite the existing record.
     * @param index (int) The index of the record to be overwritten.
     * @return (bool) Returns true if the write operation was successful, false otherwise.
     * @note The file is opened in binary read-write mode ("rb+") to allow modification of existing records without affecting other parts of the file. If the file cannot be opened, an error message is printed to standard error.
     */
    bool overWrite(Warehouse &reg, int index);

    /**
     * @brief Reads a warehouse record from the archive file at a given index.
     * @param index (int) The index of the record to be read.
     * @return (Warehouse) Returns a warehouse record read from the archive file.
     * @note The file is opened in binary read mode ("rb"). An empty warehouse wil be returned if there is a reading error or if the specified index is out of bounds.
     */
    Warehouse read(int index);

    /**
     * @brief Finds the index of a warehouse record with a given ID.
     * @param id (int) The ID of the warehouse record to search for.
     * @return (int) The index of the matching warehouse record.
     */
    int getIndex(int id);

    /**
     * @brief Finds the index of a warehouse record with a given description.
     * @param description (std::string) The description of the warehouse record to search for.
     * @return (int) The index of the matching warehouse record or -1 in case the input does not match any record.
     */
    int getIndex(std::string &name);

    /**
     * @brief Retrieves the total number of warehouse records stored in the archive file.
     * @return (int) Amount of warehouse records stored in the archive file.
     * @note Calculates the number of records by dividing the file's size by the size of each warehouse record.
     */
    int getAmountOfRegisters();

    /**
     * @brief Creates an empty warehouse archive file.
     * @warning The method does not check if the file already exists; it will create a new empty file or overwrite an existing one.
     */
    void createEmptyArchive();

    private:

    /**
     * @brief Path where the file will be saved.
     */
    std::string _path;
};