#include "../headers/Supplier.h"

Supplier::Supplier() : BusinessPartner() {
    setBankAccount(0);
}

Supplier::Supplier(int id, std::string description, int legal_id, Adress adress, int phone, std::string email, int bank_account) : BusinessPartner(id, description, legal_id, adress, phone, email) {
    setBankAccount(bank_account);
}

void Supplier::setBankAccount(int bank_account) {
    _bank_account = bank_account;
}

int Supplier::getBankAccount() {
    return _bank_account;
}