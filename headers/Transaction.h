#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include "Date.h"

class Transaction{
    public:

    Transaction();

    Transaction(int id, int accountNumber, int transactionId, double debit, double credit,const std::string & description);

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

    int _id;

    int _account_number;

    int _transaction_id;

    double _debit;

    double _credit;

    char _description[30];

    Date _creation_date;
};