#pragma once
#include <cstring>
#include <string>
#include <cstdlib>
#include "Date.h"

class Account {
    public:

    Account();

    Account(int id, const std::string & accountName, const std::string & concept, double passive, double active, double balance, int type, bool status);

    void setId(int id);

    int getId()const;

    void setName(const std::string & name);

    std::string getName();

    void setConcept(const std::string & concept);

    std::string getConcept();

    void setPassive(double passive);

    double getPassive();

    void setActive(double active);

    double getActive();

    void setBalance(double balance);

    double getBalance();

    void setType(int type);

    int getType();

    void setCreationDate(const Date & creation_date);

    Date getCreationDate() const;

    void setStatus(bool status);

    bool getStatus();

    void deposit(double amount);

    void remove(double amount);

    private:

    int _id;

    char _name[30];

    char _concept[60];

    double _passive;

    double _active;

    double _balance;

    int _type;

    int _type_id; // SACAR Y REDEFINIR CUENTAS

    Date _creation_date;

    bool _status;
};


