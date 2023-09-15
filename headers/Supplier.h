/**
 * @file Supplier.h
 * @author Maximiliano Raúl Malvicino (mrmalvicino@gmail.com)
 * @brief Represents a supplier of an organization.
 * @copyright GNU General Public License. Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
 */

#pragma once
#include "BusinessPartner.h"

class Supplier : public BusinessPartner {
    public:

    /**
     * @brief Constructs a new Supplier object with default settings.
     */
    Supplier();

    /**
     * @brief Construct a new Supplier object.
     * @param id (int) Register number.
     * @param description (std::string) Name of the supplier.
     * @param legal_id (long long int) Number of ID card (DNI, CUIL, CUIT in Argentina).
     * @param adress (Adress) Adress of the supplier.
     * @param phone (int) Telephone or cellphone of the supplier.
     * @param email (std::string) E-mail of the supplier.
     * @param is_active (bool) Status of the supplier.
     * @param bank_account (int) Bank account of the supplier.
     */
    Supplier(int id, std::string description, int legal_id, Adress adress, int phone, std::string email, bool is_active, int bank_account);

    /**
     * @brief Sets the Bank Account object.
     * @param bank_account (int) Bank account of the supplier.
     */
    void setBankAccount(int bank_account);

    /**
     * @brief Gets the Bank Account object.
     * @return (int) Bank account of the supplier.
     */
    int getBankAccount();

    private:

    /**
     * @brief Bank account of the supplier.
     */
    int _bank_account;
};