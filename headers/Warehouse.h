#pragma once
#include <cstring>
#include <string>
#include "Adress.h"


class Warehouse {
    public:

    Warehouse();
    void setId(int id);
    int getId() const;
    void setAdress(const Adress & adress);
    Adress getAdress() const;
    void setPath(const std::string & path);
    std::string getPath() const;
    void setName(std::string & name);
    std::string getName() const;
    void setIsActive(bool is_active);
    bool getIsActive();

    private:

    int _id;
    Adress _adress;
    char _name[30];
    char _path[50];
    bool _is_active;
};