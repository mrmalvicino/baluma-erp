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

    void displayMainMenu();

    /**
     * @brief Gets the amount of registers recorded in the products archive.
     * @return int 
     */
    int getAmountOfProducts();

    /**
     * @brief Displays the products menu.
     */
    void displayProductsMenu();

    /**
     * @brief Adds a new product to the product archive by prompting the user for inputs to collect various details of the product, such as description, legal ID, address, phone, email, and category.
     * @return (bool) Returns true if the new product record is successfully added and otherwise, returns false.
     */
    bool addProduct();

    /**
     * @brief Allows editing an existing product's details interactively.
     * @return (bool) Returns true if the new product record is successfully edited and otherwise, returns false.
     */
    bool editProduct();

    /**
     * @brief Allows searching for a product with an interactive menu based on different criteria, including product ID and product name.
     */
    void searchProduct();

    /**
     * @brief Displays a list of all products stored in the product archive.
     */
    void listProducts();

    /**
     * @brief Prints detailed information about a product for a given index in the archive.
     * @param index (int) The index of the product record to print.
     */
    void printProduct(int index);

    /**
     * @brief Prompts the user to enter the name of a product.
     * @param product (Product &) A reference to the Product object where the data will be stored.
     */
    void cinProductName(Product & product);

    /**
     * @brief Prompts the user to enter the brand of a product.
     * @param product (Product &) A reference to the Product object where the data will be stored.
     */
    void cinProductBrand(Product & product);

    /**
     * @brief Prompts the user to enter the model of a product.
     * @param product (Product &) A reference to the Product object where the data will be stored.
     */
    void cinProductModel(Product & product);

    /**
     * @brief Prompts the user to enter the description of a product.
     * @param product (Product &) A reference to the Product object where the data will be stored.
     */
    void cinProductDescription(Product & product);

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
     * @brief Generates a unique product ID based on the current number of product records.
     * @return (int) The generated unique product ID.
     */
    int generateProductId();

    /**
     * @brief Searches for a product by their unique ID and displays their details.
     */
    void searchProductById();

    /**
     * @brief Searches for a product by their name and displays their details.
     */
    void searchProductByNBM();

    /**
     * @brief Exports a binary file with a buckup copy of the current archive of products.
     */
    void exportProductsBackup();

    /**
     * @brief Imports a buckup copy by overwriting the current archive of products.
     */
    void importProductsBackup();

    int getAmountOfItems();

    void setWarehousePaths(int warehouse_id);

    void loadItemsMenu();

    void displayItemsMenu(std::string warehouse_name);

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

    /**
     * @brief Amount of registers recorded in the products archive.
     */
    int _amount_of_products;

    /**
     * @brief Amount of registers recorded in the current items archive.
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

    ItemsArchive _items_archive;

    ItemsArchive _items_backup;

    ItemsCSV _items_csv;

    WarehousesManager _warehouses_manager;
};