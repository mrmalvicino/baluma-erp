/**
 * @file Account.h
 * @author Lucio Luque (lucholuque98@gmail.com), Maximiliano Raúl Malvicino (mrmalvicino@gmail.com)
 * @brief Represents an accounting account.
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

    int getAmountOfAccounts();

    int getAccountType();

    int getAccountId();

    void updatePassive(double passive);

    double getPassive();

    void updateActive(double active);

    double getActive();

    void displayMenu();

    bool addAccount();

    bool addAccount(int id, std::string name, int type, double initial_balance);

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

    void cinAccountStatus();

    private:

    int _amount_of_accounts;

    Terminal _terminal;

    Account _account;

    AccountsArchive _accounts_archive;

    AccountsArchive _accounts_backup;
};