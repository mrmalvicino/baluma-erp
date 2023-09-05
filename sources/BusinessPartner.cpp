#include "../headers/BusinessPartner.h"

BusinessPartner::BusinessPartner() {
    setId(0);
    setDescription("N/A");
    setLegalId(0);
    setPhone(0);
    setEmail("N/A");
    setIsActive(true);
}

BusinessPartner::BusinessPartner(int id, std::string description, long long int legal_id, Adress adress, int phone, std::string email, bool is_active) {
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

void BusinessPartner::setDescription(std::string description) {
    strcpy(_description, description.c_str());
}

void BusinessPartner::setLegalId(long long int legal_id) {
    _legal_id = legal_id;
}

void BusinessPartner::setAdress(Adress adress) {
    _adress = adress;
}

void BusinessPartner::setPhone(int phone) {
    _phone = phone;
}

void BusinessPartner::setEmail(std::string email) {
    strcpy(_email, email.c_str());
}

void BusinessPartner::setIsActive(bool is_active) {
    _is_active = is_active;
}

int BusinessPartner::getId() {
    return _id;
}

std::string BusinessPartner::getDescription() {
    return _description;
}

long long int BusinessPartner::getLegalId() {
    return _legal_id;
}

Adress BusinessPartner::getAdress() {
    return _adress;
}

int BusinessPartner::getPhone() {
    return _phone;
}

std::string BusinessPartner::getEmail() {
    return _email;
}

bool BusinessPartner::getIsActive() {
    return _is_active;
}