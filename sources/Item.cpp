#include "../headers/Item.h"

Item::Item() {
    setId(1);
    setName("N/A");
    setDescription("N/A");
    setBrand("N/A");
    setModel("N/A");
    setPrice(0);
    setStock(0);
    setIsActive(true);
}

Item::Item(int id, const std::string & name, const std::string & description, const std::string & brand, const std::string & model, double price, int stock, bool is_active) {
    setId(id);
    setName(name);
    setDescription(description);
    setBrand(brand);
    setModel(model);
    setPrice(price);
    setStock(stock);
    setIsActive(is_active);
}

void Item::setId(int id) {
    _id = id;
}

int Item::getId() const {
    return _id;
}

void Item::setName(const std::string & name) {
    strcpy(_name, name.c_str());
}

std::string Item::getName() const {
    return _name;
}

void Item::setDescription(const std::string & description) {
    strcpy(_description, description.c_str());
}

std::string Item::getDescription() const {
    return _description;
}

void Item::setBrand(const std::string & brand) {
    strcpy(_brand, brand.c_str());
}

std::string Item::getBrand() const {
    return _brand;
}

void Item::setModel(const std::string & model) {
    strcpy(_model, model.c_str());
}

std::string Item::getModel() const {
    return _model;
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