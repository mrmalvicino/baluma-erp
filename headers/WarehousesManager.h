/**
 * @file WarehousesManager.h
 * @author Franco Baez (Francobaez2309@gmail.com)
 * @brief Manages the warehouses data.
 * @copyright GNU General Public License. Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
 */

#pragma once
#include <iostream>
#include "Terminal.h"
#include "Warehouse.h"
#include "WarehousesArchive.h"
#include "WarehousesCSV.h"

class WarehousesManager {
    public:

    /**
     * @brief Constructs a new WarehousesManager object with default settings.
     */
    WarehousesManager();

    /**
     * @brief Updates the _amount_of_warehouses attribute and returns the amount of warehouses.
     * @return (int) Amount of warehouses.
     */
    int getAmountOfWarehouses();

    /**
     * @brief Sets the _warehouse attribute.
     * @param index (int) Index of the _warehouse record from the _warehouse_archive.
     */
    void setWarehouse(int index);

    /**
     * @brief Gets the _warehouse attribute.
     * @return (Warehouse) Current warehouse.
     */
    Warehouse getWarehouse();

    /**
     * @brief Displays the warehouses menu.
     */
    void displayMenu();

    /**
     * @brief Adds a new warehouse to the _warehouses_archive by prompting the user for inputs to collect various details of the warehouse, such as description, legal ID, address, phone, email, and category.
     * @return (bool) Returns true if the new warehouse record is successfully added and otherwise, returns false.
     */
    bool addWarehouse();

    /**
     * @brief Allows editing an existing warehouse's details interactively.
     * @return (bool) Returns true if the new warehouse record is successfully edited and otherwise, returns false.
     */
    bool editWarehouse();

    /**
     * @brief Allows searching for a warehouse with an interactive menu based on different criteria, including warehouse ID and warehouse name.
     * @return (int) Returns 0 if the search was successful or -1 is the search was aborted.
     */
    int searchWarehouse();

    /**
     * @brief Searches for a warehouse by their unique ID and displays their details.
     * @return (int) Returns 0 if the search was successful or -1 is the search was aborted.
     */
    int searchWarehouseById();

    /**
     * @brief Searches for a warehouse by their name and displays their details.
     * @return (int) Returns 0 if the search was successful or -1 is the search was aborted.
     */
    int searchWarehouseByName();

    /**
     * @brief Displays a list of all warehouses stored in the _warehouses_archive.
     */
    void listWarehouses();

    /**
     * @brief Prints detailed information about the current _warehouse.
     */
    void printWarehouse();

    /**
     * @brief Read a certain _warehouse from the _warehouses_archive and calls the printWarehouse() method.
     * @param index (int) Index of the _warehouse that is going to be printed.
     */
    void printWarehouse(int index);

    /**
     * @brief Prompts the user to enter the name of a warehouse.
     * @param warehouse (Warehouse &) A reference to the Warehouse object where the data will be stored.
     */
    void cinWarehouseName(Warehouse & warehouse);

    /**
     * @brief Prompts the user to enter the adress of a warehouse.
     * @param warehouse (Warehouse &) A reference to the Warehouse object where the data will be stored.
     */
    void cinWarehouseAdress(Warehouse & warehouse);

    /**
     * @brief Prompts the user to enter the status of a warehouse.
     * @param warehouse (Warehouse &) A reference to the Warehouse object where the data will be stored.
     */
    void cinWarehouseIsActive(Warehouse & warehouse);

    /**
     * @brief Generates a unique warehouse ID based on the current number of warehouse records.
     * @return (int) The generated unique warehouse ID.
     */
    int generateWarehouseId();

    /**
     * @brief Exports a binary file with a buckup copy of the current _warehouses_archive.
     */
    void exportWarehousesBackup();

    /**
     * @brief Imports a buckup copy by overwriting the current _warehouses_archive.
     */
    void importWarehousesBackup();

    /**
     * @brief Exports a CSV file with the current _warehouses_archive.
     */
    void exportWarehousesCSV();

    /**
     * @brief Imports a CSV file by overwriting the current _warehouses_archive.
     */
    void importWarehousesCSV();

    private:

    /**
     * @brief Amount of warehouses.
     */
    int _amount_of_warehouses;

    /**
     * @brief Terminal object with default settings.
     */
    Terminal _terminal;

    /**
     * @brief Warehouse object with default settings.
     */
    Warehouse _warehouse;

    /**
     * @brief WarehousesArchive object with default path.
     */
    WarehousesArchive _warehouses_archive;

    /**
     * @brief WarehousesArchive object with custom path.
     */
    WarehousesArchive _warehouses_backup;

    /**
     * @brief WarehousesCSV object with default settings.
     */
    WarehousesCSV _warehouses_csv;
};