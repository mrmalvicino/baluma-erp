/**
 * @file SupplierManager.h
 * @author Maximiliano Raúl Malvicino (mrmalvicino@gmail.com)
 * @brief Manages the supplier module.
 * @copyright GNU General Public License. Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
 */

#pragma once
#include <iostream>
#include "Terminal.h"
#include "Supplier.h"
#include "SupplierArchive.h"
#include "SupplierCSV.h"

class SupplierManager {
    public:

    /**
     * @brief Constructs a new Supplier Manager object with default settings.
     */
    SupplierManager();

    /**
     * @brief Displays the suppliers menu.
     */
    void displayMenu();

    /**
     * @brief Adds a new supplier to the supplier archive by prompting the user for inputs to collect various details of the supplier, such as description, legal ID, address, phone, email, and category.
     * @return (bool) Returns true if the new supplier record is successfully added and otherwise, returns false.
     */
    bool addSupplier();

    /**
     * @brief Allows editing an existing supplier's details interactively.
     * @return (bool) Returns true if the new supplier record is successfully edited and otherwise, returns false.
     */
    bool editSupplier();

    /**
     * @brief Allows searching for a supplier with an interactive menu based on different criteria, including supplier ID and supplier name.
     */
    void searchSupplier();

    /**
     * @brief Displays a list of all suppliers stored in the supplier archive.
     */
    void listSuppliers();

    /**
     * @brief Prints detailed information about a supplier for a given index in the archive.
     * @param index (int) The index of the supplier record to print.
     */
    void printSupplier(int index);

    /**
     * @brief Prompts the user to enter the name of a supplier.
     * @param supplier (Supplier &) A reference to the Supplier object where the data will be stored.
     */
    void cinSupplierDescription(Supplier & supplier);

    /**
     * @brief Prompts the user to enter the ID card number of a supplier.
     * @param supplier (Supplier &) A reference to the Supplier object where the data will be stored.
     */
    void cinSupplierLegalId(Supplier & supplier);

    /**
     * @brief Prompts the user to enter the adress of a supplier.
     * @param supplier (Supplier &) A reference to the Supplier object where the data will be stored.
     */
    void cinSupplierAdress(Supplier & supplier);

    /**
     * @brief Prompts the user to enter the phone of a supplier.
     * @param supplier (Supplier &) A reference to the Supplier object where the data will be stored.
     */
    void cinSupplierPhone(Supplier & supplier);

    /**
     * @brief Prompts the user to enter the email of a supplier.
     * @param supplier (Supplier &) A reference to the Supplier object where the data will be stored.
     */
    void cinSupplierEmail(Supplier & supplier);

    /**
     * @brief Prompts the user to enter the status of a supplier.
     * @param supplier (Supplier &) A reference to the Supplier object where the data will be stored.
     */
    void cinSupplierIsActive(Supplier & supplier);

    /**
     * @brief Prompts the user to enter the bank account of a supplier.
     * @param supplier (Supplier &) A reference to the Supplier object where the data will be stored.
     */
    void cinSupplierBankAccount(Supplier & supplier);

    /**
     * @brief Generates a unique supplier ID based on the current number of supplier records.
     * @return (int) The generated unique supplier ID.
     */
    int generateSupplierId();

    /**
     * @brief Searches for a supplier by their unique ID and displays their details.
     */
    void searchSupplierById();

    /**
     * @brief Searches for a supplier by their name and displays their details.
     */
    void searchSupplierByDescription();

    /**
     * @brief Exports a binary file with a buckup copy of the current archive of suppliers.
     */
    void exportSuppliersBackup();

    /**
     * @brief Imports a buckup copy by overwriting the current archive of suppliers.
     */
    void importSuppliersBackup();

    /**
     * @brief Exports a CSV file with the current archive of suppliers.
     */
    void exportSuppliersCSV();

    /**
     * @brief Imports a CSV file by overwriting the current archive of suppliers.
     */
    void importSuppliersCSV();

    private:

    Terminal _terminal; // Terminal object with default settings.
    Supplier _supplier; // Supplier object with default settings.
    SupplierArchive _supplier_archive; // Supplier Archive object with default path.
    SupplierArchive _supplier_backup; // Supplier Archive object with custom path.
    SupplierCSV _supplier_csv; // Supplier CSV object with default settings.
};