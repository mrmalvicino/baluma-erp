#pragma once
#include "Product.h"
#include "Date.h"

class Item : public Product {
    public:

    Item();
    Item(int id, const std::string & name, const std::string & brand, const std::string & model, const std::string & description, double price, int stock, bool is_active);
    void setDescription(const std::string & description);
    std::string getDescription() const;
    void setPrice(double price);
    double getPrice() const;
    void setStock(int stock);
    int getStock() const;
    void setIncome(const Date & income);
    Date getIncome() const;
    void setIsActive(bool is_active);
    bool getIsActive() const;

    private:

    char _description[30];
    double _price;
    int _stock;
    Date _income;
    bool _is_active;
};