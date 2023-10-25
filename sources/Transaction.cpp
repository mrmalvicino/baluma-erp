#include "../headers/Transaction.h"

Transaction::Transaction() {
    setId(1);
    setAccountNumber(0);
    setTransactionId(1);
    setDebit(0);
    setCredit(0);
    setDescription("N/A");
}

Transaction::Transaction(int id, int account_number, int transaction_id, double debit, double credit,const std::string & description) {
    setId(id);
    setAccountNumber(account_number);
    setTransactionId(transaction_id);
    setDebit(debit);
    setCredit(credit);
    setDescription(description);
}

void Transaction::setAccountNumber(int account_number) {
    _account_number = account_number;
}

void Transaction::setTransactionId(int transaction_id) {
    _transaction_id = transaction_id;
}

void Transaction::setDebit(double debit) {
    _debit = debit;
}

void Transaction::setCredit(double credit) {
    _credit = credit;
}

void Transaction::setDescription(const std::string & description) {
    strcpy(_description, description.c_str());
}

void Transaction::setId(int id) {
    _id = id;
}

void Transaction::setDocDate(const Date & creation_date) {
    _creation_date = creation_date;
}

Date Transaction::getDocDate() const{
    return _creation_date;
}

int Transaction::getId() const {
    return _id;
}

int Transaction::getAccountNumber() {
    return _account_number;
}

int Transaction::getTransactionId() {
    return _transaction_id;
}

double Transaction::getDebit() {
    return _debit;
}

double Transaction::getCredit() {
    return _credit;
}

std::string Transaction::getDescription() {
    return _description;
}

void Transaction::cinTransaction() {
    std::cout << "INGRESAR DEBITO:\n";
    std::cin >> _debit;
    std::cout << "INGRESAR CREDITO:\n";
    std::cin >> _credit;
    std::cout << "INGRESAR DESCRIPCION:\n";
    std::cin >> _description;
}

void Transaction::coutTransaction() {
    std::cout << "DEBITO: " << _debit << "\n";
    std::cout << "CREDITO: " << _credit << "\n";
    std::cout << "DESCRIPCION: " << _description << "\n";
}