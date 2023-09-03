#pragma once
#include <cstdio>
#include "Supplier.h"

class SupplierArchive {
    public:
        SupplierArchive();
        SupplierArchive(std::string path);
        void setPath(std::string path);
        std::string getPath();
        bool write(Supplier & reg);
        bool write(Supplier & reg, int index);
        Supplier read(int index);
        int getIndex(int id);
        int getAmountOfRegisters();
    
    private:
        std::string _path;
};