#pragma once
#include <iostream>
#include "Terminal.h"
#include "Transaction.h"
#include "TransactionsArchive.h"
#include "ClientsManager.h"
#include "SuppliersManager.h"
#include "AccountsManager.h"


class TransactionsManager {
    public:

    TransactionsManager();
    void displayMenu(); 
    bool addTransaction();
    void searchTransaction();
    void listTransactions();
    void printTransaction(int index); 
    void cinTransactionAccountNumber(Transaction & _transaction);
    void cinTransactionNumber(Transaction & _transaction);
    void cinTransactionDebit(Transaction & _transaction);
    void cinTransactionCredit(Transaction & _transaction); 
    void cinTransactionDescription(Transaction & _transaction);
    int generateTransactionId();
    void cinCreateDate(Transaction & _transaction);
    void loadClients();
    void searchTransactionById();
    void searchTransactionByDescription();
    //void searchTransactionByAccountNumber();
    void exportTransactionsBackup();
    void importTransactionsBackup();
    //void exportTransactionsCSV();
    //void importTransactionsCSV();

    private:

    Terminal _terminal;
    Transaction _Transaction;
    TransactionsArchive _Transaction_archive;
    TransactionsArchive _Transaction_backup;
    ClientsManager _client_manager;
    SuppliersManager _supplier_manager;
    AccountsManager _account_manager;
    Account _account;
    Client _client;
    Supplier _supplier;
    // TransactionCSV _Transaction_csv;
};