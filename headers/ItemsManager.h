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
    int generateItemId();
    int productIndex();
    void listProducts();
    void printProduct(int index);
    void exportProductsCSV();

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