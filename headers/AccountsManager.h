/**
 * @file AccountsManager.h
 * @author Maximiliano Raúl Malvicino (mrmalvicino@gmail.com)
 * @brief Manages the account module.
 * @copyright GNU General Public License. Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
 */

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

    int searchAccount();

    int searchAccountById();

    int searchAccountByName();

    void listAccountsMenu();

    void listAccounts(bool list_actives = true, bool list_inactives = true);

    void loadAccount(int index);

    void printAccount();

    void cinAccountName(Account & account);

    void cinAccountConcept(Account & account);

    void cinAccountStatus(Account & account);

    int generateAccountId();

    void exportAccountsBackup();

    void importAccountsBackup();

    private:

    Terminal _terminal;

    Account _account;

    AccountsArchive _accounts_archive;

    AccountsArchive _accounts_backup;
};