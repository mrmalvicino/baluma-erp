/**
 * @file SuppliersManager.h
 * @author Maximiliano Raúl Malvicino (mrmalvicino@gmail.com)
 * @brief Manages the supplier module.
 * @copyright GNU General Public License. Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
 */

#pragma once
#include <iostream>
#include "Terminal.h"
#include "Supplier.h"
#include "SuppliersArchive.h"
#include "SuppliersCSV.h"

class SuppliersManager {
    public:

    /**
     * @brief Constructs a new SuppliersManager object with default settings.
     */
    SuppliersManager();

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
     * @return (int) Returns 0 if the search was successful or -1 is the search was aborted.
     */
    int searchSupplier();

    /**
     * @brief Searches for a supplier by their unique ID and displays their details.
     * @return (int) Returns 0 if the search was successful or -1 is the search was aborted.
     */
    int searchSupplierById();

    /**
     * @brief Searches for a supplier by their name and displays their details.
     * @return (int) Returns 0 if the search was successful or -1 is the search was aborted.
     */
    int searchSupplierByDescription();

    /**
     * @brief Displays a menu with listing options.
     */
    void listSuppliersMenu();

    /**
     * @brief Displays a list of all suppliers stored in the supplier archive.
     * @param list_actives (bool) If true, active suppliers will be printed.
     * @param list_inactives (bool) If true, inactive suppliers will be printed.
     */
    void listSuppliers(bool list_actives = true, bool list_inactives = true);

    /**
     * @brief Reads a register from the _suppliers_archive.
     * @param index (int) The index of the supplier record to read.
     */
    void loadSupplier(int index);

    /**
     * @brief Prints detailed information about the current _supplier.
     */
    void printSupplier();

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

    /**
     * @brief Terminal object with default settings.
     */
    Terminal _terminal;

    /**
     * @brief Supplier object with default settings.
     */
    Supplier _supplier;

    /**
     * @brief SuppliersArchive object with default path.
     */
    SuppliersArchive _suppliers_archive;

    /**
     * @brief SuppliersArchive object with custom path.
     */
    SuppliersArchive _suppliers_backup;

    /**
     * @brief SuppliersCSV object with default settings.
     */
    SuppliersCSV _suppliers_csv;
};