#include "../headers/Item.h"

Item::Item() 
{
    setId(1);
    setName(" ");
    setDescription(" ");
    setBrand(" ");
    setModel(" ");
    setPrice(0);
    setStock(0);
    setIsActive(true);

}

Item::Item(int id, const std::string &name, const std::string &description, const std::string &brand, const std::string &model, double price, int stock, bool is_active)
{
    setId(id);
    setName(name);
    setDescription(description);
    setBrand(brand);
    setModel(model);
    setPrice(price);
    setStock(stock);
    setIsActive(is_active);
}

void Item::setId(int id)
{
    _id = id;
}

void Item::setName(const std::string &name)
{
    strcpy(_name, name.c_str());
}

void Item::setDescription(const std::string &description)
{
    strcpy(_description, description.c_str());
}

void Item::setBrand(const std::string &brand)
{
    strcpy(_brand, brand.c_str());
}

void Item::setModel(const std::string &model)
{
    strcpy(_model, model.c_str());
}

void Item::setPrice(double price)
{
    _price = price;
}

void Item::setStock(int stock)
{
    _stock = stock;
}

int Item::getId() const
{
    return _id;
}

std::string Item::getName() const
{
    return _name;
}

std::string Item::getDescription() const
{
    return _description;
}

std::string Item::getBrand() const
{
    return _brand;
}

std::string Item::getModel() const
{
    return _model;
}

double Item::getPrice() const
{
    return _price;
}

int Item::getStock() const
{
    return _stock;
}
Date Item::getIncome() const
{
    return _income;
}

bool Item::getIsActive() const
{
    return _is_active;
}

void Item::setIncome(const Date &income)
{
    _income = income;
}

void Item::setIsActive(bool is_active)
{
    _is_active = is_active;
}
