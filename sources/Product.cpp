#include "../headers/Product.h"

Product::Product() {
    setId(1);
    setName("N/A");
    setBrand("N/A");
    setModel("N/A");
    setIsActive(true);
}

Product::Product(int id, const std::string & name, const std::string & brand, const std::string & model, bool is_active) {
    setId(id);
    setName(name);
    setBrand(brand);
    setModel(model);
    setIsActive(is_active);
}

void Product::setId(int id) {
    _id = id;
}

int Product::getId() const {
    return _id;
}

void Product::setName(const std::string & name) {
    strcpy(_name, name.c_str());
}

std::string Product::getName() const {
    return _name;
}

void Product::setBrand(const std::string & brand) {
    strcpy(_brand, brand.c_str());
}

std::string Product::getBrand() const {
    return _brand;
}

void Product::setModel(const std::string & model) {
    strcpy(_model, model.c_str());
}

std::string Product::getModel() const {
    return _model;
}

void Product::setIsActive(bool is_active) {
    _is_active = is_active;
}

bool Product::getIsActive() const {
    return _is_active;
}

std::string Product::toString() const {
    std::string name = getName();
    std::string brand = getBrand();
    std::string model = getModel();

    return name + " " + brand + " " + model;
}