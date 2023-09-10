#pragma once
#include "Date.h"
#include <string>
#include <cstring>

class Item
{
    public:
        Item();
        Item(int id, const std::string &name, const std::string &description, const std::string &brand, const std::string &model, double price, int stock, bool is_active);

        void setId(int id);
        void setName(const std::string &name);
        void setDescription(const std::string &description);
        void setBrand(const std::string &brand);
        void setModel(const std::string &model);
        void setPrice(double price);
        void setStock(int stock);
        void setIncome(const Date &income);
        void setIsActive(bool is_active);

        int getId() const;
        std::string getName() const;
        std::string getDescription() const;
        std::string getBrand() const;
        std::string getModel() const;
        double getPrice() const;
        int getStock() const;
        Date getIncome() const;
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