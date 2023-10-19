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

    /**
     * @brief Construct a new Warehouse object with default settings.
     */
    Warehouse();

    /**
     * @brief Sets the register number.
     * @param id (int) Register number.
     */
    void setId(int id);

    /**
     * @brief Gets the register number.
     * @return (int) Register number.
     */
    int getId() const;

    /**
     * @brief Sets the name of the warehouse.
     * @param name (std::string) Name of the warehouse.
     */
    void setName(const std::string & name);

    /**
     * @brief Gets the name of the warehouse.
     * @return (std::string) Name of the warehouse.
     */
    std::string getName() const;

    /**
     * @brief Sets the adress of the warehouse.
     * @param adress (Adress) Adress of the warehouse.
     */
    void setAdress(const Adress & adress);

    /**
     * @brief Gets the adress of the warehouse.
     * @return (Adress) Adress of the warehouse.
     */
    Adress getAdress() const;

    /**
     * @brief Sets the status of the warehouse.
     * @param is_active (bool) Status of the warehouse.
     */
    void setIsActive(bool is_active);

    /**
     * @brief Gets the status of the warehouse.
     * @return (bool) Status of the warehouse.
     */
    bool getIsActive();

    private:

    /**
     * @brief Register number.
     */
    int _id;

    /**
     * @brief Name of the warehouse.
     */
    char _name[30];

    /**
     * @brief Adress of the warehouse.
     */
    Adress _adress;

    /**
     * @brief Status of the warehouse.
     */
    bool _is_active;
};