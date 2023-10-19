/**
 * @file ItemsArchive.h
 * @author Franco Baez (Francobaez2309@gmail.com)
 * @brief Represents an archive of items.
 * @copyright GNU General Public License. Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
 */

#pragma once
#include <iostream>
#include <cstdio>
#include "Item.h"

class ItemsArchive {
    public:

    ItemsArchive();
    ItemsArchive(const std::string & path);
    void setPath(const std::string & path);
    std::string getPath();
    bool write(Item & reg);
    bool overWrite(Item & reg, int index);
    Item read(int index);
    int getIndex(int id);
    int getIndex(Product & product);
    int getAmountOfRegisters();
    void createEmptyArchive();

    private:

    std::string _path;
};