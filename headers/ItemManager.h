#pragma once
#include <iostream>
#include "Terminal.h"
#include "Item.h"
#include "ItemArchive.h"
#include "ItemCSV.h"

class ItemManager {
    public:

    ItemManager();
    void displayMenu();
    bool addItem();
    bool editSupplier();
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
    int generateItemId();
    void searchItemById();
    void searchItemByDescription();
    void exportItemsBackup();
    void importItemsBackup();
    void exportItemsCSV();
    void importItemsCSV();

    private:

    Terminal _terminal;
    Item _item;
    ItemArchive _item_archive;
    ItemArchive _item_backup;
    ItemCSV _item_csv;
};