#pragma once
#include <iostream>
#include "Terminal.h"
#include "Warehouse.h"
#include "WarehousesArchive.h"
#include "WarehousesCSV.h"

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
    int generateWarehouseId();
    void searchWarehouseById();
    void searchWarehouseByName();
    void exportWarehousesBackup();
    void importWarehousesBackup();
    void exportWarehousesCSV();
    void importWarehousesCSV();
    Warehouse getWarehouse();

    private:

    Terminal _terminal;
    Warehouse _warehouse;
    WarehousesArchive _warehouses_archive;
    WarehousesArchive _warehouses_backup;
    WarehousesCSV _warehouses_csv;
};