#include "../headers/Register.h"

Register::Register() {
    setId(0);
    setDescription("N/A");
}

Register::Register(int id, std::string description) {
    setId(id);
    setDescription(description);
}

void Register::setId(int id) {
    _id = id;
}

void Register::setDescription(std::string description) {
    strcpy(_description, description.c_str());
}

int Register::getId() {
    return _id;
}

std::string Register::getDescription() {
    return _description;
}