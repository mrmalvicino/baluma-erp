#pragma once
#include <iostream>
#include "Terminal.h"
#include "Supplier.h"
#include "SupplierArchive.h"

class SupplierManager {
    public:
        void displayMenu();

    private:
        Terminal _terminal;
        Supplier _supplier;
        SupplierArchive _supplier_archive;
};