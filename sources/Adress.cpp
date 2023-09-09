#include "../headers/Adress.h"

Adress::Adress() {
    setCountry("Argentina");
    setState("Buenos Aires");
    setCity("N/A");
    setStreet("N/A");
    setNumber(0);
    setFloor(0);
    setLetter('\0');
}

Adress::Adress(std::string country, std::string state, std::string city, std::string street, int number, int floor, char letter) {
    setCountry(country);
    setState(state);
    setCity(city);
    setStreet(street);
    setNumber(number);
    setFloor(floor);
    setLetter(letter);
}

void Adress::setCountry(std::string country) {
    strcpy(_country, country.c_str());
}

std::string Adress::getCountry() {
    return _country;
}

void Adress::setState(std::string state) {
    strcpy(_state, state.c_str());
}

std::string Adress::getState() {
    return _state;
}

void Adress::setCity(std::string city) {
    strcpy(_city, city.c_str());
}

std::string Adress::getCity() {
    return _city;
}

void Adress::setStreet(std::string street) {
    strcpy(_street, street.c_str());
}

std::string Adress::getStreet() {
    return _street;
}

void Adress::setNumber(int number) {
    _number = number;
}

int Adress::getNumber() {
    return _number;
}

void Adress::setFloor(int floor) {
    _floor = floor;
}

int Adress::getFloor() {
    return _floor;
}

void Adress::setLetter(char letter) {
    _letter = letter;
}

char Adress::getLetter() {
    return _letter;
}