#pragma once
#include "Terminal.h"
#include "TransactionsArchive.h"
#include "ClientsManager.h"
#include "SuppliersManager.h"
#include "AccountsManager.h"

class AccountingManager {
    public:

    int getAmountOfTransactions();

    void displayMainMenu();

    bool addTransaction(int sign);

    void loadTransaction(int index);

    void printTransaction();

    void showJournal();

    int generateTransactionId();

    void exportTransactionsBackup();

    void importTransactionsBackup();

    void exportTransactionsCSV();

    void cinAccountId(Transaction & transaction);

    void cinTransactionDescription(Transaction & transaction, bool cin_ignore = false);

    private:

    int _amount_of_transactions;

    Terminal _terminal;

    Client _client;

    Supplier _supplier;

    Account _account;

    Transaction _transaction;

    TransactionsArchive _transactions_archive;

    TransactionsArchive _transactions_backup;

    ClientsManager _clients_manager;

    SuppliersManager _suppliers_manager;

    AccountsManager _accounts_manager;
};