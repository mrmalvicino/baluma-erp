#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include "Terminal.h"
#include "Item.h"
#include "ItemsArchive.h"

class ItemsCSV {
    public:

    ItemsCSV();
    ItemsCSV(std::string path, char delimiter);
    void setPath(std::string path);
    std::string getPath() const;
    void setDelimiter(char delimiter);
    char getDelimiter();
    void writeItemsCSV(Item & item, ItemsArchive & item_archive);
    void readItemsCSV(Item & item, ItemsArchive & item_archive);

    private:

    std::string _path;
    char _delimiter;
    Terminal _terminal;
};