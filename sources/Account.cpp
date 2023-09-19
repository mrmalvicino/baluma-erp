#include<iostream>
#include<cstdlib>
using namespace std;
#include "../headers/Account.h"

Account::Account() {
    setAccountNumber(0);
    setDenomination("N/A");
    setConcept("N/A");
    setAccountName("N/A");
    setBalance(0);
    setPassive(0);
    setActive(0);
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

void Account::setAccountName(std::string _accountName){
    accountName=_accountName;
}
void Account::setDenomination(std::string _denomination){
    denomination=_denomination;
}
void Account::setConcept(std::string _concept){
    concept=_concept;
}
double Account::getActive(){
    return active; 
}
double Account::getPassive(){
    return passive;  
}

double Account::getBalance(){
    return balance;
}

std::string Account::getAccountName(){
    return accountName;
}

std::string Account::getDenomination(){
    return denomination;
}

std::string Account::getConcept(){
    return concept;
}

int Account::getAccountNumber(){
    return accountNumber;
}

void Account::deposit(double amount){
    balance+=amount;
}
void Account::remove(double amount){
    balance-=amount;
}

