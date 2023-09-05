#pragma once
#include "Adress.h"

class BusinessPartner {
    public:
        BusinessPartner();
        BusinessPartner(int id, std::string description, long long int legal_id, Adress adress, int phone, std::string email, bool is_active);
        void setId(int id);
        void setDescription(std::string description);
        void setLegalId(long long int legal_id);
        void setAdress(Adress adress);
        void setPhone(int phone);
        void setEmail(std::string email);
        void setIsActive(bool is_active);
        int getId();
        std::string getDescription();
        long long int getLegalId();
        Adress getAdress();
        int getPhone();
        std::string getEmail();
        bool getIsActive();

    private:
        int _id;
        char _description[30];
        long long int _legal_id;
        Adress _adress;
        int _phone;
        char _email[30];
        bool _is_active;
};