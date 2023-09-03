#include "../headers/Client.h"

Client::Client() : BusinessPartner() {
    setStatus(true);
}

Client::Client(int id, std::string description, int legal_id, Adress adress, int phone, std::string email, bool status) : BusinessPartner(id, description, legal_id, adress, phone, email) {
    setStatus(status);
}

void Client::setStatus(bool status) {
    _status = status;
}

bool Client::getStatus() {
    return _status;
}