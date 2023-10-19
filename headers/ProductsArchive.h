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

    ProductsArchive();
    ProductsArchive(const std::string & path);
    void setPath(const std::string & path);
    std::string getPath();
    bool write(Product & reg);
    bool overWrite(Product & reg, int index);
    Product read(int index);
    int getIndex(int id);
    int getIndex(Product & product);
    int getAmountOfRegisters();
    void createEmptyArchive();

    private:

    std::string _path;
};