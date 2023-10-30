/**
 * @file AccountingManager.h
 * @author Maximiliano Raúl Malvicino (mrmalvicino@gmail.com), Lucio Luque (lucholuque98@gmail.com), Franco Baez (Francobaez2309@gmail.com)
 * @brief Manages the accounting module.
 * @copyright GNU General Public License. Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
 */

#pragma once
#include "Terminal.h"
#include "TransactionsArchive.h"
#include "ClientsManager.h"
#include "SuppliersManager.h"
#include "InventoryManager.h"
#include "AccountsManager.h"

class AccountingManager {
    public:

    AccountingManager();

    /**
     * @brief Gets the amount of transactions recorded in the _transactions_archive.
     * @return (int) Amount of journal's transactions.
     */
    int getAmountOfTransactions();

    /**
     * @brief Displays the accounting menu.
     */
    void displayMainMenu();

    /**
     * @brief Adds a purchase transaction.
     * @return (bool) Returns true if the transaction is successfully added and otherwise, returns false.
     */
    bool buy();

    /**
     * @brief Adds a sale transaction.
     * @return (bool) Returns true if the transaction is successfully added and otherwise, returns false.
     */
    bool sell();

    /**
     * @brief Loads a _transaction.
     * @param index (int) The index of the transaction record to read.
     */
    void loadTransaction(int index);

    /**
     * @brief Prints detailed information about the current _transaction.
     */
    void printTransaction();

    /**
     * @brief Prints detailed information about all the transactions of the _transactions_archive.
     */
    void showJournal();

    /**
     * @brief Generates a unique transaction ID based on the current number of transaction records.
     * @return (int) The generated unique transaction ID.
     */
    int generateTransactionId();

    /**
     * @brief Checks if the essential accounts ("Cash", "Clients" and "Suppliers") exist in the system and configures them if they are not found.
     */
    void checkAccounts();

    /**
     * @brief Prompts the user to enter the description of the current _transaction.
     * @param cin_ignore (bool) If true, the cin buffer will be ignored. Should be true if the user was prompted with any std::cin input before this method was called.
     */
    void cinTransactionDescription(bool cin_ignore = false);

    private:

    /**
     * @brief Amount of transactions recorded in the _transactions_archive that represents the journal.
     */
    int _amount_of_transactions;

    /**
     * @brief Id number of the Cash account.
     */
    int _cash_acc_id;

    /**
     * @brief Id number of the Clients account.
     */
    int _clients_acc_id;

    /**
     * @brief Id number of the Suppliers account.
     */
    int _suppliers_acc_id;

    /**
     * @brief Terminal object with default settings.
     */
    Terminal _terminal;

    /**
     * @brief Client object with default settings.
     */
    Client _client;

    /**
     * @brief Supplier object with default settings.
     */
    Supplier _supplier;

    /**
     * @brief Account object with default settings.
     */
    Account _account;

    /**
     * @brief Transaction object with default settings.
     */
    Transaction _transaction;

    /**
     * @brief TransactionsArchive object with default path.
     */
    TransactionsArchive _transactions_archive;

    /**
     * @brief TransactionsArchive object with custom path.
     */
    TransactionsArchive _transactions_backup;

    /**
     * @brief ClientsManager object with default settings.
     */
    ClientsManager _clients_manager;

    /**
     * @brief SuppliersManager object with default settings.
     */
    SuppliersManager _suppliers_manager;

    /**
     * @brief InventoryManager object with default settings.
     */
    InventoryManager _inventory_manager;

    /**
     * @brief AccountsManager object with default settings.
     */
    AccountsManager _accounts_manager;
};