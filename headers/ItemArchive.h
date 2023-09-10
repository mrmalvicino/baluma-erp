#pragma once
#include "Item.h"

class ItemArchive
{
    public:

        ItemArchive();
        ItemArchive(const std::string &path);

        void setPath(const std::string &path);
        std::string getPath();

        bool write(Item & reg);

        bool overWrite(Item & reg, int index);

        int getIndex(int id);

        int getIndex(std::string & description);

        Item read(int index);

        int getAmountOfRegisters();

        void createEmptyItemArchive();

    private:
        std::string _path; 

};