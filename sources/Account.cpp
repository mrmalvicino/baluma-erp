#include "../headers/Account.h"
#include<iostream>
#include<cstdlib>
using namespace std;

Account::Account() {
    setId(1);
    setAccountNumber(0);
    setConcept("N/A");
    setAccountName("N/A");
    setBalance(0);
    setPassive(0);
    setActive(0);
    setIsActive(true);
}

Account::Account(int id,int accountNumber,const std::string & concept,const std::string & accountName, double balance, double passive, double active, bool isActive){
    setId(id);
    setAccountNumber(accountNumber);
    setConcept(concept);
    setAccountName(accountName);
    setBalance(balance);
    setPassive(passive);
    setActive(active);
    setIsActive(isActive);
}

void Account::setId(int _id) {
    id = _id;
}

void Account::setActive(double _active){
    active=_active;
}
void Account::setPassive(double _passive){
    passive=_passive;
}
void Account::setBalance(double _balance){
    balance=_balance;
}

void Account::setAccountNumber(int _accountNumber){
    accountNumber =_accountNumber ;
}

void Account::setAccountName(const std::string &_accountName){
    strcpy(accountName, _accountName.c_str());
}

void Account::setConcept(const std::string &_concept){
    strcpy(concept, _concept.c_str());
}

void Account::setIsActive(bool _isActive){
    isActive=_isActive;
}

int Account::getId() {
    return id;
}

double Account::getActive(){
    return active; 
}
double Account::getPassive(){
    return passive;  
}

double Account::getBalance(){
    balance=active-passive;
    return balance;
}

std::string Account::getAccountName(){
    return accountName;
}

std::string Account::getConcept(){
    return concept;
}

int Account::getAccountNumber(){
    return accountNumber;
}

bool Account::getIsActive(){
    return isActive;
}

void Account::deposit(double amount){
    balance+=amount;
}
void Account::remove(double amount){
    balance-=amount;
}

