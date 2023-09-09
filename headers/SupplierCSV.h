/**
 * @file SupplierCSV.h
 * @author Maximiliano Raúl Malvicino (mrmalvicino@gmail.com)
 * @brief Manages a supplier archive file, allowing storage and retrieval of supplier records in a CSV file.
 * @copyright GNU General Public License. Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
 */

#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include "Terminal.h"
#include "Supplier.h"
#include "SupplierArchive.h"

class SupplierCSV {
    public:

    /**
     * @brief Constructs a new Supplier CSV object with default settings.
     */
    SupplierCSV();

    /**
     * @brief Constructs a new Supplier CSV object.
     * @param path (std::string) Path where the file will be saved.
     * @param delimiter (char) Character that is used to delimit columns.
     */
    SupplierCSV(std::string path, char delimiter);

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
     * @brief Exports supplier records to a CSV file.
     * @param supplier (Supplier) The supplier object used to write each register.
     * @param supplier_archive (SupplierArchive) The supplier archive containing the supplier records to export.
     */
    void writeSuppliersCSV(Supplier & supplier, SupplierArchive & supplier_archive);

    /**
     * @brief 
     * @param supplier (Supplier) The supplier object used to read each register.
     * @param supplier_archive (SupplierArchive) The supplier archive where the supplier records are going to be imported to.
     */
    void readSuppliersCSV(Supplier & supplier, SupplierArchive & supplier_archive);

    private:

    char _delimiter; // Path where the file will be saved
    std::string _path; // Character that is used to delimit columns
    Terminal _terminal; // Terminal object with default settings.
};