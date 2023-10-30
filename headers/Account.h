/**
 * @file Account.h
 * @author Lucio Luque (lucholuque98@gmail.com)
 * @brief Represents an accounting account.
 * @copyright GNU General Public License. Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
 */

#pragma once
#include <cstring>
#include <string>
#include <cstdlib>
#include "Date.h"

class Account {
    public:

    /**
     * @brief Constructs a new Account object with default settings.
     */
    Account();

    /**
     * @brief Constructs a new Account object with custom settings.
     * @param accountName (std::string) Name of the account.
     * @param concept (std::string) Description of the account.
     * @param passive (double) Liabilities of the accounts.
     * @param active (double) Assets of the accounts.
     * @param balance (double) Result of subtracting liabilities from assets.
     * @param type (int) Type of account.
     * @param status (bool) Determines whether the account is active or not.
     */
    Account(const std::string & accountName, const std::string & concept, double passive, double active, double balance, int type, bool status);

    /**
     * @brief Sets the _id of the account.
     * @param id (int) Autogenerated account number for internal use.
     */
    void setId(int id);

    /**
     * @brief Gets the _id of the account.
     * @return (int) Autogenerated account number for internal use.
     */
    int getId()const;

    /**
     * @brief Sets the _name of the account.
     * @param name (std::string) Name of the account.
     */
    void setName(const std::string & name);

    /**
     * @brief Gets the _name of the account.
     * @return (std::string) Name of the account.
     */
    std::string getName();


    /**
     * @brief Sets the _concept of the account.
     * @param concept (std::string) Description of the account.
     */
    void setConcept(const std::string & concept);

    /**
     * @brief Gets the _concept of the account.
     * @return (std::string) Description of the account.
     */
    std::string getConcept();

    /**
     * @brief Sets the _passive of the account.
     * @param passive (double) Liabilities of the accounts.
     */
    void setPassive(double passive);

    /**
     * @brief Gets the _passive of the account.
     * @return (double) Liabilities of the accounts.
     */
    double getPassive();

    /**
     * @brief Sets the _active of the account.
     * @param active (double) Assets of the accounts.
     */
    void setActive(double active);

    /**
     * @brief Gets the _active of the account.
     * 
     * @return (double) Assets of the accounts.
     */
    double getActive();

    /**
     * @brief Sets the _balance of the account.
     * @param balance (double) Result of subtracting liabilities from assets.
     */
    void setBalance(double balance);

    /**
     * @brief Gets the _balance of the account.
     * @return (double) Result of subtracting liabilities from assets.
     */
    double getBalance();

    /**
     * @brief Sets the _type of the account.
     * @param type (int) Type of account.
     */
    void setType(int type);

    /**
     * @brief Gets the _type of the account.
     * @return (int) Type of account.
     */
    int getType();

    /**
     * @brief Sets the _creation_date of the account.
     * @param creation_date (Date) Date of creation of the account.
     */
    void setCreationDate(const Date & creation_date);

    /**
     * @brief Gets the _creation_date of the account.
     * @return (Date) Date of creation of the account.
     */
    Date getCreationDate() const;

    /**
     * @brief Set _status of the account.
     * @param status (bool) Status of the account.
     */
    void setStatus(bool status);

    /**
     * @brief Gets the status.
     * @return (bool) Status of the account.
     */
    bool getStatus();

    private:

    /**
     * @brief Autogenerated account number for internal use.
     */
    int _id;

    /**
     * @brief Name of the account.
     */
    char _name[30];

    /**
     * @brief Description of the account.
     */
    char _concept[60];

    /**
     * @brief Liabilities of the accounts.
     */
    double _passive;

    /**
     * @brief Assets of the accounts.
     */
    double _active;

    /**
     * @brief Result of subtracting liabilities from assets.
     */
    double _balance;

    /**
     * @brief Type of account. The following types of accounts are supported:
     * 
     * Type 1: Cash account. Used to register transactions in which money is involved.
     * Type 2: Clients account. Used to register sales.
     * Type 3: Suppliers account. Used to register purchases.
     */
    int _type;

    /**
     * @brief Date of creation of the account.
     */
    Date _creation_date;

    /**
     * @brief Determines whether the account is active or not.
     */
    bool _status;
};


