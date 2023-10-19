/**
 * @file Product.h
 * @author Maximiliano Raúl Malvicino (mrmalvicino@gmail.com)
 * @brief Represents a product.
 * @copyright GNU General Public License. Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
 */

#pragma once
#include <string>
#include <cstring>

class Product {
    public:

    /**
     * @brief Construct a new Product object with default settings.
     */
    Product();

    /**
     * @brief Construct a new Product object with custom settings.
     */
    Product(int id, const std::string & name, const std::string & brand, const std::string & model, const std::string & description, double price, bool is_active);

    /**
     * @brief Sets the id of the product.
     * @param id (int) Register number.
     */
    void setId(int id);

    /**
     * @brief Gets the id of the product.
     * @return (int) Register number.
     */
    int getId() const;

    /**
     * @brief Sets the name of the product.
     * @param name (std::string) Name of the product.
     */
    void setName(const std::string & name);

    /**
     * @brief Gets the name of the product.
     * @return (std::string) Name of the product.
     */
    std::string getName() const;

    /**
     * @brief Sets the brand of the product.
     * @param brand (std::string) Brand of the product.
     */
    void setBrand(const std::string & brand);

    /**
     * @brief Gets the brand of the product.
     * @return (std::string) Brand of the product.
     */
    std::string getBrand() const;

    /**
     * @brief Sets the model of the product.
     * @param model (std::string) Model of the product.
     */
    void setModel(const std::string & model);

    /**
     * @brief Gets the model of the product.
     * @return (std::string) Model of the product.
     */
    std::string getModel() const;

    /**
     * @brief Sets the description of the product.
     * @param description (std::string) Description of the product.
     */
    void setDescription(const std::string & description);

    /**
     * @brief Gets the description of the product.
     * @return (std::string) Description of the product.
     */
    std::string getDescription() const;

    /**
     * @brief Sets the price of the product.
     * @param price (double) Price of the product.
     */
    void setPrice(double price);

    /**
     * @brief Gets the price of the product.
     * @return (double) Price of the product.
     */
    double getPrice() const;

    /**
     * @brief Sets the status of the product.
     * @param is_active (bool) Status of the product.
     */
    void setIsActive(bool is_active);

    /**
     * @brief Gets the status of the product.
     * @return (bool) Status of the product.
     */
    bool getIsActive() const;

    /**
     * @brief Concatenates the name, brand and model of the product.
     * @return (std::string) Name, brand and model of the product separated by a space.
     */
    std::string toString() const;

    private:

    /**
     * @brief Register number.
     */
    int _id;

    /**
     * @brief Name of the product.
     */
    char _name[30];

    /**
     * @brief Brand of the product.
     */
    char _brand[30];

    /**
     * @brief Model of the product.
     */
    char _model[30];

    /**
     * @brief Description of the product.
     */
    char _description[30];

    /**
     * @brief Price of the product.
     */
    double _price;

    /**
     * @brief Status of the product.
     */
    bool _is_active;
};