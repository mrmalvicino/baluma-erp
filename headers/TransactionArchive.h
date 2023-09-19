#pragma once
#include <cstdio>
#include "Transaction.h"

class TransactionArchive {
    public:
        TransactionArchive();
        TransactionArchive(std::string path);
        void setPath(std::string path);
        std::string getPath();
        int write(Transaction & reg, FILE *file);
        int read(Transaction & reg,FILE *file);
        Transaction readS(Transaction & reg,FILE *file,int index);
    
    private:
        std::string _path;
};