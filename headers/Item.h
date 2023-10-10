#pragma once
#include "Product.h"
#include "Date.h"

class Item : public Product {
    public:

    Item();
    Item(int id, const std::string & name, const std::string & brand, const std::string & model, const std::string & description, double price, bool is_active, int stock);
    void setStock(int stock);
    int getStock() const;
    void setIncome(const Date & income);
    Date getIncome() const;
    std::string toString() const;

    private:

    int _stock;
    Date _income;
};