/**
 * @file InventoryManager.h
 * @author Franco Baez (Francobaez2309@gmail.com), Maximiliano Raúl Malvicino (mrmalvicino@gmail.com)
 * @brief Manages the inventory module.
 * @copyright GNU General Public License. Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
 */

#pragma once
#include <iostream>
#include "Terminal.h"
#include "Array.h"
#include "Product.h"
#include "ProductsArchive.h"
#include "Item.h"
#include "ItemsArchive.h"
#include "ItemsCSV.h"
#include "WarehousesManager.h"

class InventoryManager {
    public:

    /**
     * @brief Displays the inventory menu.
     */
    void displayMainMenu();

    /**
     * @brief Updates the _amount_of_products attribute and returns it's value.
     * @return (int) Returns the amount of registers recorded in the current ProductsArchive object.
     */
    int getAmountOfProducts();

    /**
     * @brief Gets the price of the current _item.
     * @return (double) Price attribute of the current _item.
     */
    double getItemPrice();

    /**
     * @brief Gets the stock of the current _item.
     * @return (int) Stock attribute of the current _item.
     */
    int getItemStock();

    /**
     * @brief Displays the products menu.
     */
    void displayProductsMenu();

    /**
     * @brief Adds a new product to the ProductsArchive object by prompting the user for inputs to collect various details of the product.
     * @return (bool) Returns true if the new product record is successfully added and otherwise, returns false.
     */
    bool addProduct();

    /**
     * @brief Allows editing an existing product's details interactively.
     * @return (bool) Returns true if the new product record is successfully edited and otherwise, returns false.
     */
    bool editProduct();

    /**
     * @brief Iterates through all the warehouses and checks if an item with the same ID as the current _product exists in the warehouse's ItemsArchive. If found, it updates the item's information of the ItemsArchive with the corresponding product information.
     * @return (bool) Returns true if the synchronization was successful for at least one item, otherwise returns false. It returns false if no matching items were found in any of the warehouses or if there was an issue while overwriting the item in the archive.
     */
    bool synchronizeItem();

    /**
     * @brief Allows searching for a product with an interactive menu based on different criteria, including product ID and product name.
     * @return (int) Returns 0 if the search was successful or -1 is the search was aborted.
     */
    int searchProduct();

    /**
     * @brief Searches for a product by their unique ID and displays their details.
     * @return (int) Returns 0 if the search was successful or -1 is the search was aborted.
     */
    int searchProductById();

    /**
     * @brief Searches for a product by their name, brand and model and displays their details.
     * @return (int) Returns 0 if the search was successful or -1 is the search was aborted.
     */
    int searchProductByNBM();

    /**
     * @brief Displays a menu with listing options.
     */
    void listProductsMenu();

    /**
     * @brief Displays a list of all products stored in the ProductsArchive object.
     * @param list_actives (bool) If true, active products will be printed.
     * @param list_inactives (bool) If true, inactive products will be printed.
     */
    void listProducts(bool list_actives = true, bool list_inactives = true);

    /**
     * @brief Reads a register from the _products_archive.
     * @param index (int) The index of the product record to read.
     */
    void loadProduct(int index);

    /**
     * @brief Prints detailed information about the current _product.
     */
    void printProduct();

    /**
     * @brief Generates a unique product ID based on the current number of product records.
     * @return (int) The generated unique product ID.
     */
    int generateProductId();

    /**
     * @brief Exports a binary file with a backup copy of the current _products_archive.
     */
    void exportProductsBackup();

    /**
     * @brief Imports a backup copy by overwriting the current _products_archive.
     */
    void importProductsBackup();

    /**
     * @brief Updates the _amount_of_items attribute and returns it's value.
     * @return (int) Returns the amount of registers recorded in the current ItemsArchive object.
     */
    int getAmountOfItems();

    /**
     * @brief Sets the path for the _items_archive, _items_backup and _items_csv objects for the current warehouse.
     * @param warehouse_id (int) Warehouse unique id that will define the paths.
     */
    void setWarehousePaths(int warehouse_id);

    /**
     * @brief Prompts the user for keyboard input to set the warehouse for which the item menu will be loaded. Then , calls the setWarehousePaths() and displayItemsMenu() methods if the user input is valid.
     * @param display_items_menu (bool) If true, the items menu will shown.
     */
    void loadItemsMenu(bool display_items_menu = true);

    /**
     * @brief Displays a menu to manage stock items in a specific warehouse.
     * @param warehouse_name Name of the warehouse to be displayed in the menu title.
     */
    void displayItemsMenu(std::string warehouse_name);

    /**
     * @brief Adds a new item to the ItemsArchive object by prompting the user for inputs to collect various details of the item.
     * @return (bool) Returns true if the new item record is successfully added and otherwise, returns false.
     */
    bool addItem();

    /**
     * @brief Allows editing an existing item's details interactively.
     * @return (bool) Returns true if the new item record is successfully edited and otherwise, returns false.
     */
    bool editItem();

    /**
     * @brief Allows searching for an item with an interactive menu based on different criteria, including item ID and item NBM (name-brand-model).
     * @return (int) Returns 0 if the search was successful or -1 is the search was aborted.
     */
    int searchItem();

    /**
     * @brief Searches for an item by their unique ID and displays their details.
     * @return (int) Returns 0 if the search was successful or -1 is the search was aborted.
     */
    int searchItemById();

    /**
     * @brief Searches for an item by their name, brand and model and displays their details.
     * @return (int) Returns 0 if the search was successful or -1 is the search was aborted.
     */
    int searchItemByNBM();

    /**
     * @brief Displays a menu with listing options.
     */
    void listItemsMenu();

    /**
     * @brief Displays a list of all items stored in the ItemsArchive object.
     * @param list_actives (bool) If true, active items will be printed.
     * @param list_inactives (bool) If true, inactive items will be printed.
     */
    void listItems(bool list_actives = true, bool list_inactives = true);

    /**
     * @brief Reads a register from the _items_archive.
     * @param index (int) The index of the item record to read.
     */
    void loadItem(int index);

    /**
     * @brief Prints detailed information about the current _item.
     */
    void printItem();

    /**
     * @brief Exports a binary file with a backup copy of the current _items_archive.
     */
    void exportItemsBackup();

    /**
     * @brief Imports a backup copy by overwriting the current _items_archive.
     */
    void importItemsBackup();

    /**
     * @brief Exports a CSV file with the current _items_archive.
     */
    void exportItemsCSV();

    /**
     * @brief Imports a CSV file by overwriting the current _items_archive.
     */
    void importItemsCSV();

    /**
     * @brief Generates a new id for an item or retrieves the product id if the NBM (name-brand-model) of the current _item was already registered as a product in the _products_archive.
     */
    void generateItemId();

    /**
     * @brief Checks whether the current _item already exists as a Product register of the _products_archive. If not, it writes the Item attributes shared with the Product class to the _products_archive. If the item exists as a product, it updates the current _item description and price with the values from the _products_archive.
     */
    void synchronizeProduct();

    /**
     * @brief Searches for an item in the products list and returns its index.
     * Iterates through the list of products to find a match for the item's name, brand, and model. If a matching product is found, the method returns the index of that product in the list. If no matching product is found, it returns -1.
     * @return (int) The index of the found product or -1 if not found.
     */
    int productIndex();

    /**
     * @brief Displays a complete inventory report, allowing the user to search for stock and product details.
     */
    void showInventory();

    /**
     * @brief Exports a complete inventory report in CSV format.
     */
    void exportInventoryCSV();

    /**
     * @brief Prompts the user to enter the name of a product.
     * @param product (Product &) A reference to the Product object where the data will be stored.
     */
    void cinProductName(Product & product, bool cin_ignore = false);

    /**
     * @brief Prompts the user to enter the brand of a product.
     * @param product (Product &) A reference to the Product object where the data will be stored.
     */
    void cinProductBrand(Product & product, bool cin_ignore = false);

    /**
     * @brief Prompts the user to enter the model of a product.
     * @param product (Product &) A reference to the Product object where the data will be stored.
     */
    void cinProductModel(Product & product, bool cin_ignore = false);

    /**
     * @brief Prompts the user to enter the description of a product.
     * @param product (Product &) A reference to the Product object where the data will be stored.
     */
    void cinProductDescription(Product & product, bool cin_ignore = false);

    /**
     * @brief Prompts the user to enter the price of a product.
     * @param product (Product &) A reference to the Product object where the data will be stored.
     */
    void cinProductPrice(Product & product);

    /**
     * @brief Prompts the user to enter the status of a product.
     * @param product (Product &) A reference to the Product object where the data will be stored.
     */
    void cinProductIsActive(Product & product);

    /**
     * @brief Prompts the user to enter the stock of an item.
     * @param is_sale (is_sale) If true, the stock attribute of an _item will decrease instead of increasing. Determines whether if a transaction is a sale or a purchase. Used only from the AccountingManager class.
     */
    void cinItemStock(bool is_sale = false);

    /**
     * @brief Prompts the user to enter the income date of an item.
     */
    void cinItemIncome();

    private:

    /**
     * @brief Amount of registers recorded in the products archive.
     */
    int _amount_of_products;

    /**
     * @brief Amount of registers recorded in the current ItemsArchive object.
     */
    int _amount_of_items;

    /**
     * @brief Terminal object with default settings.
     */
    Terminal _terminal;

    /**
     * @brief Array object with default settings.
     */
    Array _array;

    /**
     * @brief Product object with default settings.
     */
    Product _product;

    /**
     * @brief ProductsArchive object with default path.
     */
    ProductsArchive _products_archive;

    /**
     * @brief ProductsArchive object with custom path.
     */
    ProductsArchive _products_backup;

    /**
     * @brief Item object with default settings.
     */
    Item _item;

    /**
     * @brief ItemsArchive object used as main archive.
     */
    ItemsArchive _items_archive;

    /**
     * @brief ItemsArchive object used as backup archive.
     */
    ItemsArchive _items_backup;

    /**
     * @brief ItemsCSV object with default settings.
     */
    ItemsCSV _items_csv;

    /**
     * @brief WarehousesManager object with default settings.
     */
    WarehousesManager _warehouses_manager;
};