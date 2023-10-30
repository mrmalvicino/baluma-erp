/**
 * @file Employee.h
 * @author Franco Baez (Francobaez2309@gmail.com), Lucio Luque (Lucholuque98@gmail.com).
 * @brief Represents a Employee of an organization.
 * @copyright GNU General Public License. Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
 */

#pragma once
#include "Date.h"
#include "BusinessPartner.h"


class Employee : public BusinessPartner
{
    public:
    /**
     * @brief Constructs a new Employee object with default settings.
     */
    Employee();

    /**
     * @brief Constructs a new Employee object.
     * @param id (int) Register number.
     * @param description (const std::string) Name of the Employee.
     * @param legal_id (long long int) Number of ID card (DNI, CUIL, CUIT in Argentina).
     * @param adress (const Adress) Adress of the Employee.
     * @param phone (int) Telephone or cellphone of the Employee.
     * @param email (const std::string) E-mail of the Employee.
     * @param title (const std::string) Title of the Employee.
     * @param admission (const Date) Admission of the Employee.
     * @param is_active (bool) Status of the Employee.
     */
    Employee(int id, const std::string & description, long long int legal_id, const Adress & adress, int phone, const std::string & email, const std::string & title, const Date & admission, bool is_active);
    
    /**
     * @brief Sets the Title object.
     * @param title (const std::string) Title of the Employee.
     */
    void setTitle(const std::string & title);
    
    /**
     * @brief Gets the Title object.
     * @return (std::string) Title of the Employee.
     */
    std::string getTitle() const;
    
    /**
     * @brief Sets the Admission object.
     * @param admission (const Date) Admission of the Employee.
     */
    void setAdmission(const Date & admission);
    
    /**
     * @brief Gets the Admission object.
     * @return (Date) Admission of the Employee.
     */
    Date getAdmission() const;

    private:

    /**
     * @brief Title of the Employee.
     */
    char _title[30];

    /**
     * @brief Admission of the Employee.
     */
    Date _admission;


};