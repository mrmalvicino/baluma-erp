#pragma once
#include<cstring>
#include <string>
using namespace std;

class Account {
public:
    Account();
    Account(int id,int accountNumber,const std::string & concept,const std::string & accountName, double balance, double passive, double active, bool isActive);
    //GETTERS Y SETTERS
    void setId(int _id);
    void setAccountNumber(int _accountNumber);
    void setActive(double _active);
    void setPassive(double _passive);
    void setBalance(double _balance);
    void setAccountName(const std::string &_accountName);
    void setConcept(const std::string &_concept);
    void setIsActive(bool _isActive);
    int getId();
    double getActive();
    double getPassive();
    double getBalance();
    int getAccountNumber();
    std::string getAccountName();
    std::string getConcept();
    bool getIsActive();
    //METODOS
    void deposit(double amount);
    void remove(double amount);
    void moveAccount();

private:
    int id;
    int accountNumber;
    double active;
    double passive;
    double balance;
    char accountName [30];
    char concept [60];
    bool isActive=true;
};


