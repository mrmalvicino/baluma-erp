#pragma once
#include <iostream>
#include <cstdio>
#include "Account.h"

class AccountsArchive {
    public:

    AccountsArchive();

    AccountsArchive(std::string path);

    void setPath(std::string path);

    std::string getPath();

    bool write(Account & reg);

    bool overWrite(Account & reg, int index);

    Account read(int index);

    int getAccountNumber(int number);

    int getAccountType(int number);

    int getIndex(int id);

    int getIndex(std::string & name);

    int getAmountOfRegisters();

    void createEmptyArchive();

    private:

    std::string _path;
};