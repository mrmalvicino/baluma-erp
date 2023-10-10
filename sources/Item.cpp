#include "../headers/Item.h"

Item::Item() {
    setDescription("N/A");
    setPrice(0);
    setStock(0);
}

Item::Item(int id, const std::string & name, const std::string & brand, const std::string & model, const std::string & description, double price, bool is_active, int stock) : Product(id, name, brand, model, description, price, is_active) {
    setStock(stock);
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