#include<cstring>
using namespace std;
#include <string>
#include "../headers/Transaction.h"
#include <iostream>

Transaction::Transaction(){
    setAccountNumber(0);
    setTransactionId(1);
    setDebit(0);
    setCredit(0);
    setDescription("N/A");
}

Transaction::Transaction(int accountNumber, int transactionId, double debit, double credit,const std::string & description){
    setAccountNumber(accountNumber);
    setTransactionId(transactionId);
    setDebit(debit);
    setCredit(credit);
    setDescription(description);
}

void Transaction::setAccountNumber(int _accountNumber) {
    accountNumber = _accountNumber;
}

void Transaction::setTransactionId(int _transactionId){
    transactionId = _transactionId;
}

void Transaction::setDebit(double _debit){
    debit=_debit;
}

void Transaction::setCredit(double _credit){
    credit=_credit;
}

void Transaction::setDescription(const std::string &_description){
    strcpy(description, _description.c_str());
}

int Transaction::getAccountNumber(){
    return accountNumber;
}

int Transaction::getTransactionId(){
    return transactionId;
}

double Transaction::getDebit(){
    return debit;
}

double Transaction::getCredit(){
    return 	credit;
}

std::string Transaction::getDescription(){
    return description;
}

void Transaction::cinTransaction(){
    cout<<"INGRESAR DEBITO: "<<endl;
    cin>>debit;
    cout<<"INGRESAR CREDITO: "<<endl;
    cin>>credit;
    cout<<"INGRESAR DESCRIPCION: "<<endl;
    cin>>description;
}

void Transaction::coutTransaction(){
    cout<<"DEBITO: "<<debit<<"\n";
    cout<<"CREDITO: "<<credit<<"\n";
    cout<<"DESCRIPCION: "<<description<<"\n";
}