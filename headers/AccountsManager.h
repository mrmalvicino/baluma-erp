#pragma once
#include <iostream>
#include "Terminal.h"
#include "DateTime.h"
#include "Account.h"
#include "AccountsArchive.h"

class AccountsManager {
    public:

    AccountsManager();

    void displayMenu();

    bool addAccount();

    bool editAccount();

    bool updateAccount();

    int searchAccount();

    int searchAccountById();

    int searchAccountByName();

    void listAccountsMenu();

    void listAccounts(bool list_actives = true, bool list_inactives = true);

    void loadAccount(int index);

    void printAccount();

    int generateAccountId();

    void exportAccountsBackup();

    void importAccountsBackup();

    void cinAccountName(Account & account, bool cin_ignore = false);

    void cinAccountConcept(Account & account, bool cin_ignore = false);

    void cinAccountBalance(Account & account);

    void cinAccountType(Account & account);

    void cinAccountTypeId(Account & account);

    void cinAccountStatus(Account & account);

    private:

    Terminal _terminal;

    Account _account;

    AccountsArchive _accounts_archive;

    AccountsArchive _accounts_backup;
};