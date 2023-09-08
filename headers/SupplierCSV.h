#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include "Terminal.h"
#include "Supplier.h"
#include "SupplierArchive.h"

class SupplierCSV {
    public:
        SupplierCSV();
        SupplierCSV(std::string path, char delimiter);
        void setPath(std::string path);
        std::string getPath();
        void setDelimiter(char delimiter);
        char getDelimiter();
        void writeSuppliersCSV(Supplier & supplier, SupplierArchive & supplier_archive);
        void readSuppliersCSV(Supplier & supplier, SupplierArchive & supplier_archive);

    private:
        char _delimiter;
        std::string _path;
        Terminal _terminal;
};