#include "../headers/Warehouse.h"

Warehouse::Warehouse() {
    setId(1);
    setPath("registers/NULL");
    setIsActive(true);
}

void Warehouse::setId(int id) {
    _id = id;
}

int Warehouse::getId() const {
    return _id;
}

void Warehouse::setAdress(const Adress & adress) {
    _adress = adress;
}

Adress Warehouse::getAdress() const {
    return _adress;
}

void Warehouse::setName(std::string & name) {
    strcpy(_name, name.c_str());
}

std::string Warehouse::getName() const {
    return _name;
}

void Warehouse::setPath(const std::string & path) {
    strcpy(_path, path.c_str());
}

std::string Warehouse::getPath() const {
    return _path;
}

void Warehouse::setIsActive(bool is_active) {
    _is_active = is_active;
}

bool Warehouse::getIsActive() {
    return _is_active;
}