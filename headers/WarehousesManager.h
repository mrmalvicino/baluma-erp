#pragma once
#include <iostream>
#include "Warehouse.h"
#include "WarehousesArchive.h"
#include "Terminal.h"

class WarehousesManager {
    public:

    WarehousesManager();
    void displayMenu();
    bool addWarehouse();
    bool editWarehouse();
    void searchWarehouse();
    void listWarehouse();
    void printWarehouse();
    void printWarehouse(int index);
    void cinWarehouseName(Warehouse & warehouse);
    void cinWarehouseAdress(Warehouse & warehouse);
    void cinWarehouseIsActive(Warehouse & warehouse);
    void generateWarehousePath(Warehouse & warehouse);
    int generateWarehouseId();
    void searchWarehouseById();
    void searchWarehouseByName();
    void exportWarehouseBackup();
    void importWarehouseBackup();
    void setItemsPath(std::string);
    std::string getItemsPath();

    private:

    Terminal _terminal;
    Warehouse _warehouse;
    WarehousesArchive _warehouses_archive;
    WarehousesArchive _warehouses_backup;
};