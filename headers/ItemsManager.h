#pragma once
#include <iostream>
#include "Terminal.h"
#include "Item.h"
#include "ItemsArchive.h"
#include "ItemsCSV.h"
#include "WarehousesManager.h"
#include "ProductsList.h"

class ItemsManager {
    public:

    ItemsManager();
    void displayMainMenu();
    void selectWarehouse();
    void displayProductsMenu();
    bool addItem();
    bool editItem();
    void searchItem();
    void listItems();
    void printItem(int index);
    void cinItemName(Item & item);
    void cinItemDescription(Item & item);
    void cinItemBrand(Item & item);
    void cinItemModel(Item & item);
    void cinItemPrice(Item & item);
    void cinItemStock(Item & item);
    void cinItemIncome(Item & item);
    void cinItemIsActive(Item & item);
    void searchItemById();
    void searchItemByDescription();
    void exportItemsBackup();
    void importItemsBackup();
    void exportItemsCSV();
    void importItemsCSV();
    void generateItemId();

    /**
     * @brief Searches for an item in the products list and returns its index.
     * Iterates through the list of products to find a match for the item's name, brand, and model. If a matching product is found, the method returns the index of that product in the list. If no matching product is found, it returns -1.
     * @return (int) The index of the found product or -1 if not found.
     */
    int productIndex();

    void listProducts(); //en desarrollo
    void printProduct(int index); //en desarrollo
    void exportProductsCSV(); //en desarrollo

    private:

    Terminal _terminal;
    Item _item;
    ItemsArchive _items_archive;
    ItemsArchive _items_backup;
    ItemsCSV _items_csv;
    WarehousesManager _warehouses_manager;
    Product _product;
    ProductsList _products_list;
};