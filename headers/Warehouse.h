/**
 * @file Warehouse.h
 * @author Franco Baez (Francobaez2309@gmail.com)
 * @brief Represents a warehouse.
 * @copyright GNU General Public License. Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
 */

#pragma once
#include <cstring>
#include <string>
#include "Adress.h"

class Warehouse {
    public:

    Warehouse();
    void setId(int id);
    int getId() const;
    void setName(const std::string & name);
    std::string getName() const;
    void setAdress(const Adress & adress);
    Adress getAdress() const;
    void setIsActive(bool is_active);
    bool getIsActive();

    private:

    int _id;
    char _name[30];
    Adress _adress;
    bool _is_active;
};