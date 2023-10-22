#pragma once
#include "Date.h"
#include "BusinessPartner.h"


class Employee : public BusinessPartner
{
    public:
        Employee();
        Employee(int id, const std::string & description, long long int legal_id, const Adress & adress, int phone, const std::string & email, const std::string & title, const Date & admission, bool is_active);

        void setTitle(const std::string & title);
        std::string getTitle() const;

        void setAdmission(const Date & admission);
        Date getAdmission() const;

    private:
        char _title[30];
        Date _admission;


};