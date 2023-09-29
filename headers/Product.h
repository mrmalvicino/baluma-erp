#pragma once
#include <string>
#include <cstring>

class Product {
    public:

    Product();
    Product(int id, const std::string & name, const std::string & brand, const std::string & model, bool is_active);
    void setId(int id);
    int getId() const;
    void setName(const std::string & name);
    std::string getName() const;
    void setBrand(const std::string & brand);
    std::string getBrand() const;
    void setModel(const std::string & model);
    std::string getModel() const;
    void setIsActive(bool is_active);
    bool getIsActive() const;
    std::string toString() const;

    private:

    int _id;
    char _name[30];
    char _brand[30];
    char _model[30];
    bool _is_active;
};