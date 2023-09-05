#pragma once
#include "BusinessPartner.h"

class Supplier : public BusinessPartner {
    public:
        Supplier();
        Supplier(int id, std::string description, int legal_id, Adress adress, int phone, std::string email, bool is_active, int bank_account);
        void setBankAccount(int bank_account);
        int getBankAccount();

    private:
        int _bank_account;
};