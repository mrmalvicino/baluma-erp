#pragma once
#include "BusinessPartner.h"

class Client : public BusinessPartner {
    public:
        Client();
        Client(int id, std::string description, long long int legal_id, Adress adress, int phone, std::string email, bool is_active, char category);
        void setCategory(char category);
        char getCategory();

    private:
        char _category;
};