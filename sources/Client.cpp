#include "../headers/Client.h"

Client::Client() : BusinessPartner() {
    setCategory('C');
}

Client::Client(int id, std::string description, long long int legal_id, Adress adress, int phone, std::string email, bool is_active, char category) : BusinessPartner(id, description, legal_id, adress, phone, email, is_active) {
    setCategory(category);
}

void Client::setCategory(char category) {
    _category = category;
}

char Client::getCategory() {
    return _category;
}