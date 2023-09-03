#include "../headers/Client.h"

Client::Client() : BusinessPartner() {
    setState(true);
}

Client::Client(int id, std::string description, int legal_id, Adress adress, int phone, std::string email, bool state) : BusinessPartner(id, description, legal_id, adress, phone, email) {
    setState(state);
}

void Client::setState(bool state) {
    _state = state;
}

bool Client::getState() {
    return _state;
}