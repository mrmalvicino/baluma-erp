#include "../headers/Transaction.h"

Transaction::Transaction() {
    setId(1);
    setAccountId(1);
    setDebit(0);
    setCredit(0);
    setDescription("N/A");
}

Transaction::Transaction(int id, int account_id, double debit, double credit,const std::string & description) {
    setId(id);
    setAccountId(account_id);
    setDebit(debit);
    setCredit(credit);
    setDescription(description);
}

void Transaction::setId(int id) {
    _id = id;
}

int Transaction::getId() const {
    return _id;
}

void Transaction::setAccountId(int account_id) {
    _account_id = account_id;
}

int Transaction::getAccountId() {
    return _account_id;
}

void Transaction::setDebit(double debit) {
    _debit = debit;
}

double Transaction::getDebit() {
    return _debit;
}

void Transaction::setCredit(double credit) {
    _credit = credit;
}

double Transaction::getCredit() {
    return _credit;
}

void Transaction::setDescription(const std::string & description) {
    strcpy(_description, description.c_str());
}

std::string Transaction::getDescription() {
    return _description;
}

void Transaction::setCreationDate(const Date & creation_date) {
    _creation_date = creation_date;
}

Date Transaction::getCreationDate() const {
    return _creation_date;
}