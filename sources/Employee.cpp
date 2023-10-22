#include "../headers/Employee.h"

Employee::Employee() : BusinessPartner()
{
    setTitle("N/A");
}

Employee::Employee(int id, const std::string &description, long long int legal_id, const Adress &adress, int phone, const std::string &email, const std::string &title, const Date &admission, bool is_active)
    : BusinessPartner(id, description, legal_id, adress, phone, email, is_active)
{
    setTitle(title);
    setAdmission(admission);
}

void Employee::setTitle(const std::string &title)
{
    strcpy(_title, title.c_str());
}

std::string Employee::getTitle() const
{
    return _title;
}

void Employee::setAdmission(const Date &admission)
{
    _admission = admission;
}

Date Employee::getAdmission() const
{
    return _admission;
}
