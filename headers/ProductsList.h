#pragma once
#include <iostream>
#include <cstdio>
#include "Product.h"

class ProductsList {
    public:

    ProductsList();
    ProductsList(const std::string & path);
    void setPath(const std::string & path);
    std::string getPath();
    bool write(Product & reg);
    bool overWrite(Product & reg, int index);
    Product read(int index);
    int getIndex(int id);
    int getIndex(std::string & name);
    int getAmountOfRegisters();
    void createEmptyArchive();

    private:

    std::string _path;
};