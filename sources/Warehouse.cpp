#include "../headers/Warehouse.h"

Warehouse::Warehouse() {
    setId(1);
    setName("N/A");
    setIsActive(true);
}

void Warehouse::setId(int id) {
    _id = id;
}

int Warehouse::getId() const {
    return _id;
}

void Warehouse::setName(const std::string & name) {
    strcpy(_name, name.c_str());
}

std::string Warehouse::getName() const {
    return _name;
}

void Warehouse::setAdress(const Adress & adress) {
    _adress = adress;
}

Adress Warehouse::getAdress() const {
    return _adress;
}

void Warehouse::setIsActive(bool is_active) {
    _is_active = is_active;
}

bool Warehouse::getIsActive() {
    return _is_active;
}