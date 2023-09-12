#include "../headers/BusinessPartner.h"

BusinessPartner::BusinessPartner() {
    setId(1);
    setDescription("N/A");
    setLegalId(0);
    setPhone(0);
    setEmail("N/A");
    setIsActive(true);
}

BusinessPartner::BusinessPartner(int id, const std::string & description, long long int legal_id, const Adress & adress, int phone, const std::string & email, bool is_active) {
    setId(id);
    setDescription(description);
    setLegalId(legal_id);
    setAdress(adress);
    setPhone(phone);
    setEmail(email);
    setIsActive(is_active);
}

void BusinessPartner::setId(int id) {
    _id = id;
}

int BusinessPartner::getId() {
    return _id;
}

void BusinessPartner::setDescription(const std::string & description) {
    strcpy(_description, description.c_str());
}

std::string BusinessPartner::getDescription() {
    return _description;
}

void BusinessPartner::setLegalId(long long int legal_id) {
    _legal_id = legal_id;
}

long long int BusinessPartner::getLegalId() {
    return _legal_id;
}

void BusinessPartner::setAdress(const Adress & adress) {
    _adress = adress;
}

Adress BusinessPartner::getAdress() {
    return _adress;
}

void BusinessPartner::setPhone(int phone) {
    _phone = phone;
}

int BusinessPartner::getPhone() {
    return _phone;
}

void BusinessPartner::setEmail(const std::string & email) {
    strcpy(_email, email.c_str());
}

std::string BusinessPartner::getEmail() {
    return _email;
}

void BusinessPartner::setIsActive(bool is_active) {
    _is_active = is_active;
}

bool BusinessPartner::getIsActive() {
    return _is_active;
}