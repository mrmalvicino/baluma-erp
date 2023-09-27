#pragma once
#include <cstdio>
#include "Transaction.h"

class TransactionArchive {
    public:
        TransactionArchive();
        TransactionArchive(std::string path);
        void setPath(std::string path);
        std::string getPath();
        bool write(Transaction & reg);
        bool overWrite(Transaction & reg, int index);
        Transaction read(int index);
        int getAccountNumber(int number);
        int getIndex(int id);
        int getIndex(std::string & description);
        int getAmountOfRegisters();
        void createEmptyTransactionArchive();

    private:
        std::string _path;
};