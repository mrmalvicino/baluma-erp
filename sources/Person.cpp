#include "../headers/Person.h"

Person::Person() {
    _first_name = "\0";
    _last_name = "\0";
}

Person::Person(std::string first_name, std::string last_name) {
    _first_name = first_name;
    _last_name = last_name;
}

void Person::setFirstName(std::string first_name) {
    _first_name = first_name;
}

void Person::setLastName(std::string last_name) {
    _last_name = last_name;
}

std::string Person::getFirstName() {
    return _first_name;
}

std::string Person::getLastName() {
    return _last_name;
}