#pragma once
#include <iostream>
#include <cstdio>
#include "Account.h"

class AccountsArchive {
    public:

    AccountsArchive();

    AccountsArchive(const std::string & path);

    void setPath(const std::string & path);

    std::string getPath() const;

    bool write(Account & reg);

    bool overWrite(Account & reg, int index);

    Account read(int index);

    int getIndex(int id);

    int getIndex(std::string & name);

    int getAmountOfRegisters();

    void createEmptyArchive();

    private:

    std::string _path;
};