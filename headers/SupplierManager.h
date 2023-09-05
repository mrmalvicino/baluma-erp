#pragma once
#include <iostream>
#include "Terminal.h"
#include "Supplier.h"
#include "SupplierArchive.h"

class SupplierManager {
    public:
        void displayMenu();
        bool addSupplier();
        bool editSupplier();
        void searchSupplier();
        void listSuppliers();
        void printSupplier(int index);
        void cinSupplierDescription(Supplier & supplier);
        void cinSupplierLegalId(Supplier & supplier);
        void cinSupplierAdress(Supplier & supplier);
        void cinSupplierPhone(Supplier & supplier);
        void cinSupplierEmail(Supplier & supplier);
        void cinSupplierIsActive(Supplier & supplier);
        void cinSupplierBankAccount(Supplier & supplier);
        int generateSupplierId();

    private:
        Terminal _terminal;
        Supplier _supplier;
        SupplierArchive _supplier_archive;
};