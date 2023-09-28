#pragma once
#include <cstdio>
#include "Transaction.h"

class TransactionsArchive {
    public:
        TransactionsArchive();
        TransactionsArchive(std::string path);
        void setPath(std::string path);
        std::string getPath();
        bool write(Transaction & reg);
        bool overWrite(Transaction & reg, int index);
        Transaction read(int index);
        int getAccountNumber(int number);
        int getIndex(int id);
        int getIndex(std::string & description);
        int getAmountOfRegisters();
        void createEmptyArchive();

    private:
        std::string _path;
};