#pragma once
#include<cstring>
using namespace std;
#include <string>
#include "Date.h"

class Transaction{
    public:
        //CONSTRUCTOR
        Transaction();
        Transaction(int id, int accountNumber, int transactionId, double debit, double credit,const std::string & description);
        //SETTERS Y GETTERS
        void setAccountNumber(int _accountNumber);
        void setTransactionId(int _transactionId);
        void setDebit(double _debit);
        void setCredit(double _credit);
        void setDescription(const std::string &_description);
        void setId(int _id);
        void setDocDate(const Date & _docDate);
        Date getDocDate() const;
        int getId() const;
        int getAccountNumber();
        int getTransactionId();
        double getDebit();
        double getCredit();
        std::string getDescription();
        void cinTransaction();
        void coutTransaction();
    private:   
        int id;
        int accountNumber;
        int transactionId;
        double debit;
        double credit;
        char description [30];
        Date docDate;
};