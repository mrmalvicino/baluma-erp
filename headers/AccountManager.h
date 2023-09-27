#pragma once
#include <iostream>
#include "Terminal.h"
#include "Account.h"
#include "AccountArchive.h"

class AccountManager {
    public:

    AccountManager();
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
    AccountArchive _Account_archive;
    AccountArchive _Account_backup;
   // AccountCSV _Account_csv;
};
