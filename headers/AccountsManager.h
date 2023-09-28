#pragma once
#include <iostream>
#include "Terminal.h"
#include "Account.h"
#include "AccountsArchive.h"

class AccountsManager {
    public:

    AccountsManager();
    void displayMenu(); 
    bool addAccount();
    bool editAccount();
    void searchAccount();
    void listAccounts();
    void printAccount(int index); 
    void cinAccountNumber(Account & Account);
    void cinAccountActive(Account & Account);
    void cinAccountPassive(Account & Account); 
    void cinAccountName(Account & Account);
    void cinAccountConcept(Account & Account);  
    void cinAccountIsActive(Account & Account);  
    int generateAccountId();
    void searchAccountById();
    void searchAccountByName();
    void exportAccountsBackup();
    void importAccountsBackup();
    //void exportAccountsCSV();
    //void importAccountsCSV();

    private:

    Terminal _terminal;
    Account _Account;
    AccountsArchive _Account_archive;
    AccountsArchive _Account_backup;
   // AccountCSV _Account_csv;
};
