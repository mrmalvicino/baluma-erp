#include "../headers/Account.h"

Account::Account() {
    setId(1);
    setName("N/A");
    setConcept("N/A");
    setPassive(0);
    setActive(0);
    setBalance(0);
    setType(0);
    setTypeId(0);
    setStatus(true);
}

Account::Account(int id, const std::string & name, const std::string & concept, double passive, double active, double balance, int type, int type_id, bool status) {
    setId(id);
    setName(name);
    setConcept(concept);
    setPassive(passive);
    setActive(active);
    setBalance(balance);
    setType(type);
    setTypeId(type_id);
    setStatus(status);
}

void Account::setId(int id) {
    _id = id;
}

int Account::getId() const {
    return _id;
}

void Account::setName(const std::string & name) {
    strcpy(_name, name.c_str());
}

std::string Account::getName() {
    return _name;
}

void Account::setConcept(const std::string & concept) {
    strcpy(_concept, concept.c_str());
}

std::string Account::getConcept() {
    return _concept;
}

void Account::setPassive(double passive) {
    _balance -= passive;
    _passive = passive;
}

double Account::getPassive() {
    return _passive;
}

void Account::setActive(double active) {
    _balance += active;
    _active = active;
}

double Account::getActive() {
    return _active; 
}

void Account::setBalance(double balance) {
    _balance = balance;
}

double Account::getBalance() {
    return _balance;
}

void Account::setType(int type) {
    _type = type;
}

int Account::getType() {
    return _type;
}

void Account::setTypeId(int type_id) {
    _type_id = type_id;
}

int Account::getTypeId() {
    return _type_id;
}

void Account::setCreationDate(const Date & creation_date) {
    _creation_date = creation_date;
}

Date Account::getCreationDate() const {
    return _creation_date;
}

void Account::setStatus(bool status) {
    _status = status;
}

bool Account::getStatus() {
    return _status;
}

void Account::deposit(double amount) {
    _balance += amount;
}

void Account::remove(double amount) {
    _balance -= amount;
}