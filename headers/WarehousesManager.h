#pragma once
#include <iostream>
#include "Terminal.h"
#include "Warehouse.h"
#include "WarehousesArchive.h"
#include "WarehousesCSV.h"

class WarehousesManager {
    public:

    WarehousesManager();
    int getAmountOfWarehouses();
    void setWarehouse(int index);
    Warehouse getWarehouse();
    void displayMenu();
    bool addWarehouse();
    bool editWarehouse();
    void searchWarehouse();
    void listWarehouses();
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

    private:

    int _amount_of_warehouses;
    Terminal _terminal;
    Warehouse _warehouse;
    WarehousesArchive _warehouses_archive;
    WarehousesArchive _warehouses_backup;
    WarehousesCSV _warehouses_csv;
};