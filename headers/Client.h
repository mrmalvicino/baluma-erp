#pragma once
#include "BusinessPartner.h"

class Client : public BusinessPartner {
    public:
        Client();
        Client(int id, std::string description, int legal_id, Adress adress, int phone, std::string email, bool state);
        void setStatus(bool state);
        bool getStatus();

    private:
        bool _status;
};