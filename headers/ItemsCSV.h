/**
 * @file ItemsCSV.h
 * @author Maximiliano Raúl Malvicino (mrmalvicino@gmail.com)
 * @brief Represents a CSV archive of items.
 * @copyright GNU General Public License. Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
 */

#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include "Terminal.h"
#include "Item.h"
#include "ItemsArchive.h"

class ItemsCSV {
    public:

    /**
     * @brief Constructs a new ItemsCSV object with default settings.
     */
    ItemsCSV();

    /**
     * @brief Constructs a new ItemsCSV object with custom settings.
     * @param path (std::string) Path where the file will be saved.
     * @param delimiter (char) Character that is used to delimit columns.
     */
    ItemsCSV(std::string path, char delimiter);

    /**
     * @brief Sets the _path attribute.
     * @param path (std::string) Path where the file will be saved.
     */
    void setPath(std::string path);

    /**
     * @brief Gets the _path attribute.
     * @return (std::string) Path where the file will be saved.
     */
    std::string getPath() const;

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
     * @brief Exports item records to a CSV file.
     * @param item (Item) The item object used to write each register.
     * @param items_archive (ItemsArchive) The _items_archive containing the item records to export.
     */
    void writeItemsCSV(Item & item, ItemsArchive & items_archive);

    /**
     * @brief Imports item records from a CSV file.
     * @param item (Item) The item object used to read each register.
     * @param items_archive (ItemsArchive) The _items_archive where the item records are going to be imported to.
     */
    void readItemsCSV(Item & item, ItemsArchive & items_archive);

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