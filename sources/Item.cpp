#include "../headers/Item.h"

Item::Item() {
    setDescription("N/A");
    setPrice(0);
    setStock(0);
}

Item::Item(int id, const std::string & name, const std::string & brand, const std::string & model, bool is_active, const std::string & description, double price, int stock) : Product(id, name, brand, model, is_active) {
    setDescription(description);
    setPrice(price);
    setStock(stock);
}

void Item::setDescription(const std::string & description) {
    strcpy(_description, description.c_str());
}

std::string Item::getDescription() const {
    return _description;
}

void Item::setPrice(double price) {
    _price = price;
}

double Item::getPrice() const {
    return _price;
}

void Item::setStock(int stock) {
    _stock = stock;
}

int Item::getStock() const {
    return _stock;
}

void Item::setIncome(const Date & income) {
    _income = income;
}

Date Item::getIncome() const {
    return _income;
}

std::string Item::toString() const {
    std::string name = getName();
    std::string brand = getBrand();
    std::string model = getModel();

    return name + " " + brand + " " + model;
}