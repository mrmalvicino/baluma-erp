#pragma once
#include <iostream>
#include "Terminal.h"
#include "Transaction.h"
#include "TransactionArchive.h"

class TransactionManager {
    public:

    TransactionManager();
    void displayMenu(); 
    bool addTransaction();
    bool editTransaction();
    void searchTransaction();
    void listTransactions();
    void printTransaction(int index); 
    void cinTransactionAccountNumber(Transaction & Transaction);
    void cinTransactionNumber(Transaction & Transaction);
    void cinTransactionDebit(Transaction & Transaction);
    void cinTransactionCredit(Transaction & Transaction); 
    void cinTransactionDescription(Transaction & Transaction);
    int generateTransactionId();
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
    TransactionArchive _Transaction_archive;
    TransactionArchive _Transaction_backup;
   // TransactionCSV _Transaction_csv;
};