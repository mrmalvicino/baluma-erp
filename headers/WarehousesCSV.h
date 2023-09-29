/**
 * @file WarehousesCSV.h
 * @author Maximiliano Raúl Malvicino (mrmalvicino@gmail.com)
 * @brief Manages a warehouse archive file, allowing storage and retrieval of warehouse records in a CSV file.
 * @copyright GNU General Public License. Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
 */

#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include "Terminal.h"
#include "Warehouse.h"
#include "WarehousesArchive.h"

class WarehousesCSV {
    public:

    /**
     * @brief Constructs a new WarehousesCSV object with default settings.
     */
    WarehousesCSV();

    /**
     * @brief Constructs a new WarehousesCSV object.
     * @param path (std::string) Path where the file will be saved.
     * @param delimiter (char) Character that is used to delimit columns.
     */
    WarehousesCSV(std::string path, char delimiter);

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
     * @brief Sets the Delimiter object.
     * @param delimiter (char) Character that is used to delimit columns.
     */
    void setDelimiter(char delimiter);

    /**
     * @brief Gets the Delimiter object.
     * @return (char) Character that is used to delimit columns.
     */
    char getDelimiter();

    /**
     * @brief Exports warehouse records to a CSV file.
     * @param warehouse (Warehouse) The warehouse object used to write each register.
     * @param warehouse_archive (WarehousesArchive) The warehouse archive containing the warehouse records to export.
     */
    void writeWarehousesCSV(Warehouse & warehouse, WarehousesArchive & warehouse_archive);

    /**
     * @brief 
     * @param warehouse (Warehouse) The warehouse object used to read each register.
     * @param warehouse_archive (WarehousesArchive) The warehouse archive where the warehouse records are going to be imported to.
     */
    void readWarehousesCSV(Warehouse & warehouse, WarehousesArchive & warehouse_archive);

    private:

    /**
     * @brief Path where the file will be saved.
     */
    std::string _path;

    /**
     * @brief Character that is used to delimit columns.
     */
    char _delimiter;

    /**
     * @brief Terminal object with default settings.
     */
    Terminal _terminal;
};