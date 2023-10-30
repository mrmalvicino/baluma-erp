/**
 * @file Transaction.h
 * @author Lucio Luque (lucholuque98@gmail.com)
 * @brief Represents a transaction.
 * @copyright GNU General Public License. Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
 */

#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include "DateTime.h"

class Transaction{
    public:

    /**
     * @brief Constructs a new Transaction object.
     */
    Transaction();

    /**
     * @brief Sets default values for a Transaction, such as the current date and time.
     */
    void reset();

    /**
     * @brief Sets the _id of a Transaction.
     * @param id (int) Autogenerated number of transaction.
     */
    void setId(int id);

    /**
     * @brief Gets the _id of a Transaction.
     * @return (int) Autogenerated number of transaction.
     */
    int getId() const;

    /**
     * @brief Sets the _account_id of a Transaction.
     * @param account_id (int) Main account that the transaction involves.
     */
    void setAccountId(int account_id);

    /**
     * @brief Gets the _account_id of a Transaction.
     * @return (int) Main account that the transaction involves.
     */
    int getAccountId();

    /**
     * @brief Sets the _debit of a Transaction.
     * @param debit (double) Outcome of money that the transaction involves.
     */
    void setDebit(double debit);

    /**
     * @brief Gets the _debit of a Transaction.
     * @return (double) Outcome of money that the transaction involves.
     */
    double getDebit();

    /**
     * @brief Sets the _credit of a Transaction.
     * @param credit (double) Income of money that the transaction involves.
     */
    void setCredit(double credit);

    /**
     * @brief Gets the _credit of a Transaction.
     * @return (double) Income of money that the transaction involves.
     */
    double getCredit();

    /**
     * @brief Sets the _description of a Transaction.
     * @param description (std::string) Description of the transaction.
     */
    void setDescription(const std::string & description);

    /**
     * @brief Gets the _description of a Transaction.
     * @return (std::string) Description of the transaction.
     */
    std::string getDescription();

    /**
     * @brief Sets the _date_time of a Transaction.
     * @param creation_date (DateTime) Date and time when a transaction was made.
     */
    void setDateTime(const DateTime & creation_date);

    /**
     * @brief Gets the _date_time of a Transaction.
     * @return (DateTime) Date and time when a transaction was made.
     */
    DateTime getDateTime() const;

    private:

    /**
     * @brief Autogenerated number of transaction.
     */
    int _id;

    /**
     * @brief Main account that the transaction involves.
     */
    int _account_id;

    /**
     * @brief Outcome of money that the transaction involves.
     */
    double _debit;

    /**
     * @brief Income of money that the transaction involves.
     */
    double _credit;

    /**
     * @brief Description of the transaction.
     */
    char _description[30];

    /**
     * @brief Date and time when a transaction was made.
     */
    DateTime _date_time;
};