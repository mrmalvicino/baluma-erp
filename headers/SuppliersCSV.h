/**
 * @file SuppliersCSV.h
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
#include "SuppliersArchive.h"

class SuppliersCSV {
    public:

    /**
     * @brief Constructs a new SuppliersCSV object with default settings.
     */
    SuppliersCSV();

    /**
     * @brief Constructs a new SuppliersCSV object.
     * @param path (std::string) Path where the file will be saved.
     * @param delimiter (char) Character that is used to delimit columns.
     */
    SuppliersCSV(std::string path, char delimiter);

    /**
     * @brief Sets the _path attribute.
     * @param path (std::string) Path where the file will be saved.
     */
    void setPath(std::string path);

    /**
     * @brief Gets the _path attribute.
     * @return (std::string) Path where the file will be saved.
     */
    std::string getPath();

    /**
     * @brief Sets the _delimiter attribute.
     * @param delimiter (char) Character that is used to delimit columns.
     */
    void setDelimiter(char delimiter);

    /**
     * @brief Gets the _delimiter attribute.
     * @return (char) Character that is used to delimit columns.
     */
    char getDelimiter();

    /**
     * @brief Exports supplier records to a CSV file.
     * @param supplier (Supplier) The supplier object used to write each register.
     * @param suppliers_archive (SuppliersArchive) The _suppliers_archive containing the supplier records to export.
     */
    void writeSuppliersCSV(Supplier & supplier, SuppliersArchive & suppliers_archive);

    /**
     * @brief Imports supplier records from a CSV file.
     * @param supplier (Supplier) The supplier object used to read each register.
     * @param suppliers_archive (SuppliersArchive) The _suppliers_archive where the supplier records are going to be imported to.
     */
    void readSuppliersCSV(Supplier & supplier, SuppliersArchive & suppliers_archive);

    private:

    /**
     * @brief Path where the file will be saved.
     */
    char _delimiter;

    /**
     * @brief Character that is used to delimit columns.
     */
    std::string _path;

    /**
     * @brief Terminal object with default settings.
     */
    Terminal _terminal;
};