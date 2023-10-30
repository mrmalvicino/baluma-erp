#include "../headers/Transaction.h"

Transaction::Transaction() {
    reset();
}

void Transaction::reset() {
    setId(0);
    setAccountId(0);
    setDebit(0);
    setCredit(0);
    setDescription("N/A");
    _date_time.setCurrentDateTime();
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

void Transaction::setDateTime(const DateTime & date_time) {
    _date_time = date_time;
}

DateTime Transaction::getDateTime() const {
    return _date_time;
}