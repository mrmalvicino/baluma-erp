/**
 * @file BusinessPartner.h
 * @author Maximiliano Raúl Malvicino (mrmalvicino@gmail.com)
 * @brief Represents a business partner of an organization.
 * @copyright GNU General Public License. Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
 */

#pragma once
#include "Adress.h"

class BusinessPartner {
    public:

    /**
     * @brief Constructs a new Business Partner object with default settings.
     */
    BusinessPartner();

    /**
     * @brief Constructs a new Business Partner object.
     * @param id (int) Register number.
     * @param description (std::string) Name of the business partner.
     * @param legal_id (long long int) Number of ID card (DNI, CUIL, CUIT in Argentina).
     * @param adress (Adress) Adress of the business partner.
     * @param phone (int) Telephone or cellphone of the business partner.
     * @param email (std::string) E-mail of the business partner.
     * @param is_active (bool) Status of the business partner.
     */
    BusinessPartner(int id, std::string description, long long int legal_id, Adress adress, int phone, std::string email, bool is_active);

    /**
     * @brief Set the Id object.
     * @param id (int) Register number.
     */
    void setId(int id);

    /**
     * @brief Get the Id object.
     * @return (int) Register number.
     */
    int getId();

    /**
     * @brief Set the Description object.
     * @param description (std::string) Name of the business partner.
     */
    void setDescription(std::string description);

    /**
     * @brief Get the Description object.
     * @return (std::string) Name of the business partner.
     */
    std::string getDescription();

    /**
     * @brief Set the Legal Id object.
     * @param legal_id (long long int) Number of ID card (DNI, CUIL, CUIT in Argentina).
     */
    void setLegalId(long long int legal_id);

    /**
     * @brief Get the Legal Id object.
     * @return (long long int) Number of ID card (DNI, CUIL, CUIT in Argentina).
     */
    long long int getLegalId();

    /**
     * @brief Set the Adress object.
     * @param adress (Adress) Adress of the business partner.
     */
    void setAdress(Adress adress);

    /**
     * @brief Get the Adress object.
     * @return (Adress) Adress of the business partner.
     */
    Adress getAdress();

    /**
     * @brief Set the Phone object.
     * @param phone (int) Telephone or cellphone of the business partner.
     */
    void setPhone(int phone);

    /**
     * @brief Get the Phone object.
     * @return (int) Telephone or cellphone of the business partner.
     */
    int getPhone();

    /**
     * @brief Set the Email object.
     * @param email (std::string) E-mail of the business partner.
     */
    void setEmail(std::string email);

    /**
     * @brief Get the Email object.
     * @return (std::string) E-mail of the business partner.
     */
    std::string getEmail();

    /**
     * @brief Set the Is Active object.
     * @param is_active (bool) Status of the business partner.
     */
    void setIsActive(bool is_active);

    /**
     * @brief Get the Is Active object.
     * @return true if the business partner is active.
     * @return false if the business partner is not active.
     */
    bool getIsActive();

    private:
  
    int _id; // Register number
    char _description[30]; // Name of the business partner
    long long int _legal_id; // Number of ID card (DNI, CUIL, CUIT in Argentina)
    Adress _adress; // Adress of the business partner
    int _phone; // Telephone or cellphone of the business partner
    char _email[30]; // E-mail of the business partner
    bool _is_active; // Status of the business partner
};