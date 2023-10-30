/**
 * @file AccountsArchive.h
 * @author Lucio Luque (lucholuque98@gmail.com)
 * @brief Represents the archive of accounts.
 * @copyright GNU General Public License. Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
 */

#pragma once
#include <iostream>
#include <cstdio>
#include "Account.h"

class AccountsArchive {
    public:

    /**
     * @brief Constructs a new AccountsArchive object with a default path.
     */
    AccountsArchive();

    /**
     * @brief Constructs a new AccountsArchive object with a custom path.
     */
    AccountsArchive(const std::string & path);

    /**
     * @brief Sets the _path attribute.
     * @param path (std::string) Path where the file will be saved.
     */
    void setPath(const std::string & path);

    /**
     * @brief Gets the _path attribute.
     * @return (std::string) Path where the file will be saved.
     */
    std::string getPath() const;

    /**
     * @brief Writes an account record to the archive file.
     * @param reg (Account) The account record to be written to the archive.
     * @return (bool) Returns true if the write operation was successful, false otherwise.
     * @note The file is opened in binary append mode ("ab") to ensure that new records are appended to the end of the file without overwriting existing data. If the file cannot be opened, an error message is printed to standard error.
     */
    bool write(Account & reg);

    /**
     * @brief Overwrites an account record at the specified index in the archive file.
     * @param reg (Account) The new account record that will overwrite the existing record.
     * @param index (int) The index of the record to be overwritten.
     * @return (bool) Returns true if the write operation was successful, false otherwise.
     * @note The file is opened in binary read-write mode ("rb+") to allow modification of existing records without affecting other parts of the file. If the file cannot be opened, an error message is printed to standard error.
     */
    bool overWrite(Account & reg, int index);

    /**
     * @brief Reads an account record from the archive file at a given index.
     * @param index (int) The index of the record to be read.
     * @return (Account) Returns an account record read from the archive file.
     * @note The file is opened in binary read mode ("rb"). An empty account wil be returned if there is a reading error or if the specified index is out of bounds.
     */
    Account read(int index);

    /**
     * @brief Finds the index of an account record with a given ID.
     * @param id (int) The ID of the account record to search for.
     * @return (int) The index of the matching account record.
     */
    int getIndex(int id);

    /**
     * @brief Finds the index of an account record with for a given name.
     * @param name (std::string) The name to search.
     * @return (int) The index of the matching account record or -1 in case the input does not match any record.
     */
    int getIndex(std::string & name);

    /**
     * @brief Retrieves the total number of account records stored in the archive file.
     * @return (int) Amount of account records stored in the archive file.
     * @note Calculates the number of records by dividing the file's size by the size of each account record.
     */
    int getAmountOfRegisters();

    /**
     * @brief Creates an empty account archive file.
     * @warning The method does not check if the file already exists; it will create a new empty file or overwrite an existing one.
     */
    void createEmptyArchive();

    private:

    /**
     * @brief Path where the file will be saved.
     */
    std::string _path;
};