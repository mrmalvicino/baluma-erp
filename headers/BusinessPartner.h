#include "Adress.h"

class BusinessPartner {
    public:
        BusinessPartner();
        BusinessPartner(int id, std::string description, int legal_id, Adress adress, int phone, std::string email);
        void setId(int id);
        void setDescription(std::string description);
        void setLegalId(int legal_id);
        void setAdress(Adress adress);
        void setPhone(int phone);
        void setEmail(std::string email);
        int getId();
        std::string getDescription();
        int getLegalId();
        Adress getAdress();
        int getPhone();
        std::string getEmail();

    private:
        int _id;
        char _description[30];
        int _legal_id;
        Adress _adress;
        int _phone;
        char _email[30];
};