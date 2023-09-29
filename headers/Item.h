#pragma once
#include "Product.h"
#include "Date.h"

class Item : public Product {
    public:

    Item();
    Item(int id, const std::string & name, const std::string & brand, const std::string & model, bool is_active, const std::string & description, double price, int stock);
    void setDescription(const std::string & description);
    std::string getDescription() const;
    void setPrice(double price);
    double getPrice() const;
    void setStock(int stock);
    int getStock() const;
    void setIncome(const Date & income);
    Date getIncome() const;
    std::string toString() const;

    private:

    char _description[30];
    double _price;
    int _stock;
    Date _income;
};