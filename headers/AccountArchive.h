#pragma once
#include <cstdio>
#include "Account.h"

class AccountArchive {
    public:
        AccountArchive();
        AccountArchive(std::string path);
        void setPath(std::string path);
        std::string getPath();
        bool write(Account & reg);
        bool overWrite(Account & reg, int index);
        Account read(int index);
        int getAccountNumber(int number);
        int getDenomination(std::string denomination);
        int getAmountOfRegisters();

    private:
        std::string _path;

};