#pragma once
#include <iostream>
#include "Terminal.h"
#include "DateTime.h"
#include "Account.h"
#include "AccountsArchive.h"

class AccountsManager {
    public:

    AccountsManager();

    void updatePassive(double passive);

    double getPassive();

    void updateActive(double active);

    double getActive();

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

    void cinAccountName(bool cin_ignore = false);

    void cinAccountConcept(bool cin_ignore = false);

    void cinAccountBalance();

    void cinAccountType();

    void cinAccountTypeId();

    void cinAccountStatus();

    private:

    Terminal _terminal;

    Account _account;

    AccountsArchive _accounts_archive;

    AccountsArchive _accounts_backup;
};