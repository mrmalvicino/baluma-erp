#pragma once
#include <iostream>
#include <cstdio>
#include "Transaction.h"

class TransactionsArchive {
    public:

    TransactionsArchive();

    TransactionsArchive(const std::string & path);

    void setPath(const std::string & path);

    std::string getPath() const;

    bool write(Transaction & reg);

    bool overWrite(Transaction & reg, int index);

    Transaction read(int index);

    int getIndex(int id);

    int getIndex(std::string & name);

    int getAmountOfRegisters();

    void createEmptyArchive();

    private:

    std::string _path;
};