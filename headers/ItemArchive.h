#pragma once
#include <iostream>
#include <cstdio>
#include "Item.h"

class ItemArchive {
    public:

    ItemArchive();
    ItemArchive(const std::string & path);
    void setPath(const std::string & path);
    std::string getPath();
    bool write(Item & reg);
    bool overWrite(Item & reg, int index);
    Item read(int index);
    int getIndex(int id);
    int getIndex(std::string & description);
    int getAmountOfRegisters();
    void createEmptyItemArchive();

    private:

    std::string _path;
};