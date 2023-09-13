#pragma once
#include <string>
#include <cstring>
#include "Date.h"

class Item {
    public:

    Item();
    Item(int id, const std::string & name, const std::string & description, const std::string & brand, const std::string & model, double price, int stock, bool is_active);
    void setId(int id);
    int getId() const;
    void setName(const std::string & name);
    std::string getName() const;
    void setDescription(const std::string & description);
    std::string getDescription() const;
    void setBrand(const std::string & brand);
    std::string getBrand() const;
    void setModel(const std::string & model);
    std::string getModel() const;
    void setPrice(double price);
    double getPrice() const;
    void setStock(int stock);
    int getStock() const;
    void setIncome(const Date & income);
    Date getIncome() const;
    void setIsActive(bool is_active);
    bool getIsActive() const;

    protected:

    int _id;
    char _name[30];
    char _description[30];
    char _brand[30];
    char _model[30];
    double _price;
    int _stock;
    Date _income;
    bool _is_active;
};