/**
 * @file Item.h
 * @author Franco Baez (Francobaez2309@gmail.com), Maximiliano Raúl Malvicino (mrmalvicino@gmail.com)
 * @brief Represents an existing item at a warehouse.
 * @copyright GNU General Public License. Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
 */

#pragma once
#include "Product.h"
#include "Date.h"

class Item : public Product {
    public:

    /**
     * @brief Constructs a new Item object with default settings.
     */
    Item();

    /**
     * @brief Constructs a new Item object with custom settings.
     */
    Item(int id, const std::string & name, const std::string & brand, const std::string & model, const std::string & description, double price, bool is_active, int stock);

    /**
     * @brief Sets the stock of an item.
     * @param stock (int) Stock of an item.
     */
    void setStock(int stock);

    /**
     * @brief Gets the stock of an item.
     * @return (int) Stock of an item.
     */
    int getStock() const;

    /**
     * @brief Sets the income of an item.
     * @param income (Date) Income of an item.
     */
    void setIncome(const Date & income);

    /**
     * @brief Gets the income of an item.
     * @return (Date) Income of an item.
     */
    Date getIncome() const;

    /**
     * @brief Concatenates the name, brand and model of the item.
     * @return (std::string) Name, brand and model of the item separated by a space.
     */
    std::string toString() const;

    private:

    /**
     * @brief Amount of items found at a given warehouse.
     */
    int _stock;

    /**
     * @brief Last stock increase.
     */
    Date _income;
};