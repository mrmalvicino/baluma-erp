#pragma once
#include <iostream>
#include "Warehouse.h"
#include "WarehouseArchive.h"
#include "Terminal.h"

class WarehouseManager
{
    public:
        WarehouseManager();
        void displayMenu();
        bool addWarehouse();
        bool editWarehouse();
        void searchWarehouse();
        void listWarehouse();
        void printWarehouse(int index);
        int generateWarehouseId();
        void cinWarehouseName(Warehouse & warehouse);
        void cinWarehouseAdress(Warehouse & warehouse);
        void cinWarehousePath(Warehouse & warehouse);
        void cinWarehouseIsActive(Warehouse & warehouse);
        void searchWarehouseById();
        void searchWarehouseByName();
        void exportWarehouseBackup();
        void importWarehouseBackup();
        void setItemsPath(std::string);
        std::string getItemsPath();

    private:
        Warehouse _warehouse;
        WarehouseArchive _warehouse_archive;
        WarehouseArchive _warehouse_backup;
        Terminal _terminal;
};