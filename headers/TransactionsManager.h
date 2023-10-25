#pragma once
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

    int generateTransactionId();

    void cinCreationDate(Transaction & _transaction);

    void loadClients();

    private:

    Terminal _terminal;

    Transaction _transaction;

    Account _account;

    Client _client;

    Supplier _supplier;

    TransactionsArchive _transactions_archive;

    TransactionsArchive _transactions_backup;

    AccountsManager _accounts_manager;

    ClientsManager _clients_manager;

    SuppliersManager _suppliers_manager;
};