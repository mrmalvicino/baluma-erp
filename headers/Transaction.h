#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include "Date.h"

class Transaction{
    public:

    Transaction();

    Transaction(int id, int account_id, double debit, double credit,const std::string & description);

    void setId(int id);

    int getId() const;

    void setAccountId(int account_id);

    int getAccountId();

    void setDebit(double debit);

    double getDebit();

    void setCredit(double credit);

    double getCredit();

    void setDescription(const std::string & description);

    std::string getDescription();

    void setCreationDate(const Date & creation_date);

    Date getCreationDate() const;

    private:

    int _id;

    int _account_id;

    double _debit;

    double _credit;

    char _description[30];

    Date _creation_date;
};