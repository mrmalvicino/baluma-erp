#pragma once
#include <iostream>
#include "Array.h"
#include "Terminal.h"
#include "Item.h"
#include "ItemsArchive.h"
#include "ItemsCSV.h"
#include "WarehousesManager.h"
#include "ProductsManager.h"

class ItemsManager {
    public:

    ItemsManager();
    void displayMainMenu();
    void loadItemsMenu();
    void setWarehousePaths();
    void displayItemsMenu();
    bool addItem();
    bool editItem();
    void searchItem();
    void listItems();
    void printItem(int index);
    void cinItemName(Item & item);
    void cinItemBrand(Item & item);
    void cinItemModel(Item & item);
    void cinItemDescription(Item & item);
    void cinItemPrice(Item & item);
    void cinItemStock(Item & item);
    void cinItemIncome(Item & item);
    void searchItemById();
    void searchItemByNBM();
    void exportItemsBackup();
    void importItemsBackup();
    void exportItemsCSV();
    void importItemsCSV();
    void generateItemId();
    void synchronizeProduct();

    /**
     * @brief Searches for an item in the products list and returns its index.
     * Iterates through the list of products to find a match for the item's name, brand, and model. If a matching product is found, the method returns the index of that product in the list. If no matching product is found, it returns -1.
     * @return (int) The index of the found product or -1 if not found.
     */
    int productIndex();

    void showInventory(); //en desarrollo
    void exportInventoryCSV(); //en desarrollo

    private:

    Array _array;
    Terminal _terminal;
    Item _item;
    ItemsArchive _items_archive;
    ItemsArchive _items_backup;
    ItemsCSV _items_csv;
    Product _product;
    ProductsArchive _products_archive;
    ProductsManager _products_manager;
    WarehousesManager _warehouses_manager;
};