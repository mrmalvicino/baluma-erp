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

    int getAmountOfTransactions();

    void displayMainMenu();

    bool buy();

    bool sell();

    void loadTransaction(int index);

    void printTransaction();

    void showJournal();

    int generateTransactionId();

    void checkAccounts();

    void cinTransactionDescription(Transaction & transaction, bool cin_ignore = false);

    private:

    int _amount_of_transactions;

    int _cash_acc_id;

    int _clients_acc_id;

    int _suppliers_acc_id;

    Terminal _terminal;

    Client _client;

    Supplier _supplier;

    Account _account;

    Transaction _transaction;

    TransactionsArchive _transactions_archive;

    TransactionsArchive _transactions_backup;

    ClientsManager _clients_manager;

    SuppliersManager _suppliers_manager;

    InventoryManager _inventory_manager;

    AccountsManager _accounts_manager;
};