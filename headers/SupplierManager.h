#pragma once
#include <iostream>
#include "Terminal.h"
#include "Supplier.h"
#include "SupplierArchive.h"
#include "SupplierCSV.h"

class SupplierManager {
    public:
        SupplierManager();
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
        void searchSupplierById();
        void searchSupplierByDescription();
        void exportSuppliersBackup();
        void importSuppliersBackup();
        void exportSuppliersCSV();
        void importSuppliersCSV();

    private:
        Terminal _terminal;
        Supplier _supplier;
        SupplierArchive _supplier_archive;
        SupplierArchive _supplier_backup;
        SupplierCSV _supplier_csv;
};