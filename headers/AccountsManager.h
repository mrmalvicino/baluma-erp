#pragma once
#include <iostream>
#include "Terminal.h"
#include "Account.h"
#include "AccountsArchive.h"
#include "ClientsManager.h"
#include "SuppliersManager.h"


class AccountsManager {
    public:

    AccountsManager();
    void displayMenu(); 
    bool addAccount();
    bool editAccount();
    void searchAccount();
    void listMenuAccounts();
    void listAccounts();
    void listSuppliersAccounts();
    void listClientsAccounts();
    void listVariusAccounts();
    void printAccount(int index); 
    void cinAccountNumber(Account & Account);
    void cinAccountActive(Account & Account);
    void cinAccountPassive(Account & Account); 
    void cinAccountName(Account & Account);
    void cinAccountType(Account & Account);
    void cinAccountTypeId(Account & Account);
    void cinAccountConcept(Account & Account);  
    void cinAccountIsActive(Account & Account);
    void cinCreateDate(Account & account);  
    int generateAccountId();
    int generateTypeId();
    void searchAccountById();
    void searchAccountByName();
    void exportAccountsBackup();
    void importAccountsBackup();
    //void exportAccountsCSV();
    //void importAccountsCSV();

    private:

    Terminal _terminal;
    Account _Account;
    ClientsManager _clientManager;
    SuppliersManager _supplierManager;
    AccountsArchive _Account_archive;
    AccountsArchive _Account_backup;
    //AccountCSV _Account_csv;
};
