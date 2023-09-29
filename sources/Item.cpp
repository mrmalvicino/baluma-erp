#include "../headers/Item.h"

Item::Item() {
    setDescription("N/A");
    setPrice(0);
    setStock(0);
    setIsActive(true);
}

Item::Item(int id, const std::string & name, const std::string & brand, const std::string & model, const std::string & description, double price, int stock, bool is_active) : Product(id, name, brand, model) {
    setDescription(description);
    setPrice(price);
    setStock(stock);
    setIsActive(is_active);
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

void Item::setIsActive(bool is_active) {
    _is_active = is_active;
}

bool Item::getIsActive() const {
    return _is_active;
}