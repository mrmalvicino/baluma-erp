/**
 * @file AccountsManager.h
 * @author Lucio Luque (lucholuque98@gmail.com), Maximiliano Raúl Malvicino (mrmalvicino@gmail.com)
 * @brief Manages the accounts of the accounting module.
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

    /**
     * @brief Construct a new Accounts Manager object
     * 
     */
    AccountsManager();

    /**
     * @brief Get the Amount Of Accounts object
     * 
     * @return int 
     */
    int getAmountOfAccounts();

    /**
     * @brief Get the Account Type object
     * 
     * @return int 
     */
    int getAccountType();

    /**
     * @brief Get the Account Id object
     * 
     * @return int 
     */
    int getAccountId();

    /**
     * @brief 
     * 
     * @param passive 
     */
    void updatePassive(double passive);

    /**
     * @brief Get the Passive object
     * 
     * @return double 
     */
    double getPassive();

    /**
     * @brief 
     * 
     * @param active 
     */
    void updateActive(double active);

    /**
     * @brief Get the Active object
     * 
     * @return double 
     */
    double getActive();

    /**
     * @brief 
     * 
     */
    void displayMenu();

    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    bool addAccount();

    /**
     * @brief 
     * 
     * @param id 
     * @param name 
     * @param type 
     * @param initial_balance 
     * @return true 
     * @return false 
     */
    bool addAccount(int id, std::string name, int type, double initial_balance);

    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    bool editAccount();

    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    bool updateAccount();

    /**
     * @brief 
     * 
     * @return int 
     */
    int searchAccount();

    /**
     * @brief 
     * 
     * @return int 
     */
    int searchAccountById();

    /**
     * @brief 
     * 
     * @return int 
     */
    int searchAccountByName();

    /**
     * @brief 
     * 
     */
    void listAccountsMenu();

    /**
     * @brief 
     * 
     * @param list_actives 
     * @param list_inactives 
     */
    void listAccounts(bool list_actives = true, bool list_inactives = true);

    /**
     * @brief 
     * 
     * @param index 
     */
    void loadAccount(int index);

    /**
     * @brief 
     * 
     */
    void printAccount();

    /**
     * @brief 
     * 
     * @return int 
     */
    int generateAccountId();

    /**
     * @brief 
     * 
     */
    void exportAccountsBackup();

    /**
     * @brief 
     * 
     */
    void importAccountsBackup();

    /**
     * @brief 
     * 
     * @param cin_ignore 
     */
    void cinAccountName(bool cin_ignore = false);

    /**
     * @brief 
     * 
     * @param cin_ignore 
     */
    void cinAccountConcept(bool cin_ignore = false);

    /**
     * @brief 
     * 
     */
    void cinAccountBalance();

    /**
     * @brief 
     * 
     */
    void cinAccountType();

    /**
     * @brief 
     * 
     */
    void cinAccountStatus();

    private:

    /**
     * @brief 
     * 
     */
    int _amount_of_accounts;

    /**
     * @brief 
     * 
     */
    Terminal _terminal;

    /**
     * @brief 
     * 
     */
    Account _account;

    /**
     * @brief 
     * 
     */
    AccountsArchive _accounts_archive;

    /**
     * @brief 
     * 
     */
    AccountsArchive _accounts_backup;
};