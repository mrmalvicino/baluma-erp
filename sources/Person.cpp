#include "../headers/Person.h"

Person::Person() {
    setFirstName("\0");
    setLastName("\0");
}

Person::Person(std::string first_name, std::string last_name) {
    setFirstName(first_name);
    setLastName(last_name);
}

void Person::setFirstName(std::string first_name) {
    strcpy(_first_name, first_name.c_str());
}

std::string Person::getFirstName() {
    return _first_name;
}

void Person::setLastName(std::string last_name) {
    strcpy(_last_name, last_name.c_str());
}

std::string Person::getLastName() {
    return _last_name;
}

void Person::setBirthdate(int day, int month, int year) {
    _birthdate.setDay(day);
    _birthdate.setMonth(month);
    _birthdate.setYear(year);
}

Date Person::getBirthdate() {
    return _birthdate;
}