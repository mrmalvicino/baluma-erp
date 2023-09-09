/**
 * @file Client.h
 * @author Maximiliano Raúl Malvicino (mrmalvicino@gmail.com)
 * @brief Represents a client of an organization.
 * @copyright GNU General Public License. Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
 */

#pragma once
#include "BusinessPartner.h"

class Client : public BusinessPartner {
    public:

    /**
     * @brief Constructs a new Client object with default settings.
     */
    Client();

    /**
     * @brief Constructs a new Client object.
     * @param id (int) Register number.
     * @param description (std::string) Name of the client.
     * @param legal_id (long long int) Number of ID card (DNI, CUIL, CUIT in Argentina).
     * @param adress (Adress) Adress of the client.
     * @param phone (int) Telephone or cellphone of the client.
     * @param email (std::string) E-mail of the client.
     * @param is_active (bool) Status of the client.
     * @param category (char) Category of the client.
     */
    Client(int id, std::string description, long long int legal_id, Adress adress, int phone, std::string email, bool is_active, char category);

    /**
     * @brief Sets the Category object.
     * @param category (char) Category of the client.
     */
    void setCategory(char category);

    /**
     * @brief Gets the Category object.
     * @return (char) Category of the client.
     */
    char getCategory();

    private:

    char _category; // Category of the client
};