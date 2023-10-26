#pragma once
#include "Terminal.h"
#include "TransactionsArchive.h"
#include "ClientsManager.h"
#include "SuppliersManager.h"
#include "AccountsManager.h"

class TransactionsManager {
    public:

    TransactionsManager();

    private:

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