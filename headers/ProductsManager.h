/**
 * @file ProductsManager.h
 * @author Maximiliano Raúl Malvicino (mrmalvicino@gmail.com)
 * @brief Manages the product module.
 * @copyright GNU General Public License. Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
 */

#pragma once
#include <iostream>
#include "Terminal.h"
#include "Product.h"
#include "ProductsArchive.h"

class ProductsManager {
    public:

    /**
     * @brief Constructs a new ProductsManager object with default settings.
     */
    ProductsManager();

    /**
     * @brief Displays the products menu.
     */
    void displayMenu();

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

    private:

    /**
     * @brief Terminal object with default settings.
     */
    Terminal _terminal;

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
};