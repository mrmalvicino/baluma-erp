#include<cstring>
using namespace std;
#include <string>
#include "../headers/Transaction.h"
#include <iostream>

Transaction::Transaction(){
    setDebit(0);
    setCredit(0);
}

Transaction::Transaction(double debit, double credit){
    setDebit(debit);
    setCredit(credit);
}


void Transaction::setDebit(double _debit){
    debit=_debit;
}

void Transaction::setCredit(double _credit){
    credit=_credit;
}


double Transaction::getDebit(){
    return debit;
}

double Transaction::getCredit(){
    return 	credit;
}

void Transaction::cinTransaction(){
    cout<<"INGRESAR DEBITO: "<<endl;
    cin>>debit;
    cout<<"INGRESAR CREDITO: "<<endl;
    cin>>credit;
}

void Transaction::coutTransaction(){
    cout<<"DEBITO: "<<debit<<"\n";
    cout<<"CREDITO: "<<credit;
}