#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include "Terminal.h"
#include "Item.h"
#include "ItemArchive.h"

class ItemCSV
{
    public:

        ItemCSV();
        ItemCSV(std::string path, char delimiter);

        void setPath(std::string path);
        std::string getPath() const;

        void setDelimiter(char delimiter);
        char getDelimiter();

        void writeItemsCSV(Item &item, ItemArchive & item_archive);
        void readItemsCSV(Item &item, ItemArchive & item_archive);

    private:
        char _delimiter;
        std::string _path;
        Terminal _terminal;
};