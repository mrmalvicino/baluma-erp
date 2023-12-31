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
    BusinessPartner(int id, const std::string & description, long long int legal_id, const Adress & adress, int phone, const std::string & email, bool is_active);

    /**
     * @brief Sets the Id object.
     * @param id (int) Register number.
     */
    void setId(int id);

    /**
     * @brief Gets the Id object.
     * @return (int) Register number.
     */
    int getId();

    /**
     * @brief Sets the Description object.
     * @param description (std::string) Name of the business partner.
     */
    void setDescription(const std::string & description);

    /**
     * @brief Gets the Description object.
     * @return (std::string) Name of the business partner.
     */
    std::string getDescription();

    /**
     * @brief Sets the Legal Id object.
     * @param legal_id (long long int) Number of ID card (DNI, CUIL, CUIT in Argentina).
     */
    void setLegalId(long long int legal_id);

    /**
     * @brief Gets the Legal Id object.
     * @return (long long int) Number of ID card (DNI, CUIL, CUIT in Argentina).
     */
    long long int getLegalId();

    /**
     * @brief Sets the Adress object.
     * @param adress (Adress) Adress of the business partner.
     */
    void setAdress(const Adress & adress);

    /**
     * @brief Gets the Adress object.
     * @return (Adress) Adress of the business partner.
     */
    Adress getAdress();

    /**
     * @brief Sets the Phone object.
     * @param phone (int) Telephone or cellphone of the business partner.
     */
    void setPhone(int phone);

    /**
     * @brief Gets the Phone object.
     * @return (int) Telephone or cellphone of the business partner.
     */
    int getPhone();

    /**
     * @brief Sets the Email object.
     * @param email (std::string) E-mail of the business partner.
     */
    void setEmail(const std::string & email);

    /**
     * @brief Gets the Email object.
     * @return (std::string) E-mail of the business partner.
     */
    std::string getEmail();

    /**
     * @brief Sets the Is Active object.
     * @param is_active (bool) Status of the business partner.
     */
    void setIsActive(bool is_active);

    /**
     * @brief Gets the Is Active object.
     * @return true if the business partner is active.
     * @return false if the business partner is not active.
     */
    bool getIsActive();

    private:

    /**
     * @brief Register number.
     */
    int _id;

    /**
     * @brief Name of the business partner.
     */
    char _description[30];

    /**
     * @brief Number of ID card (DNI, CUIL, CUIT in Argentina).
     */
    long long int _legal_id;

    /**
     * @brief Adress of the business partner.
     */
    Adress _adress;

    /**
     * @brief Telephone or cellphone of the business partner.
     */
    int _phone;

    /**
     * @brief E-mail of the business partner.
     */
    char _email[30];

    /**
     * @brief Status of the business partner.
     */
    bool _is_active;
};