/**
 * @file EmployeesArchive.h
 * @author Franco Baez (Francobaez2309@gmail.com), Lucio Luque (Lucholuque98@gmail.com).
 * @brief Manages a employee archive, allowing storage and retrieval of employee records in a binary file.
 * @copyright GNU General Public License. Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
 */

#pragma once
#include <iostream>
#include <cstdio>
#include "Employee.h"

class EmployeesArchive
{
    public:

    /**
     * @brief Constructs a new EmployeesArchive object with default path.
     */
    EmployeesArchive();
    
    /**
     * @brief Constructs a new EmployeesArchive object.
     * @param path (const std::string) Path where the file will be saved.
     */
    EmployeesArchive(const std::string & path);
    
    /**
     * @brief Sets the _path attribute.
     * @param path (const std::string) Path where the file will be saved.
     */
    void setPath(const std::string & path);
    
    /**
     * @brief Gets the _path attribute.
     * @return (std::string) Path where the file will be saved.
     */
    std::string getPath() const;
    
    /**
     * @brief Writes a employee record to the archive file.
     * @param reg (Employee) The employee record to be written to the archive.
     * @return (bool) Returns true if the write operation was successful, false otherwise.
     * @note The file is opened in binary append mode ("ab") to ensure that new records are appended to the end of the file without overwriting existing data. If the file cannot be opened, an error message is printed to standard error.
     */
    bool write(Employee & reg);
    
    /**
     * @brief Overwrites a employee record at the specified index in the archive file.
     * @param reg (Employee) The new employee record that will overwrite the existing record.
     * @param index (int) The index of the record to be overwritten.
     * @return (bool) Returns true if the write operation was successful, false otherwise.
     * @note The file is opened in binary read-write mode ("rb+") to allow modification of existing records without affecting other parts of the file. If the file cannot be opened, an error message is printed to standard error.
     */
    bool overWrite(Employee & reg, int index);
    
    /**
     * @brief Reads a employee record from the archive file at a given index.
     * @param index (int) The index of the record to be read.
     * @return (Employee) Returns a employee record read from the archive file.
     * @note The file is opened in binary read mode ("rb"). An empty employee wil be returned if there is a reading error or if the specified index is out of bounds.
     */
    Employee read(int index);
    
    /**
     * @brief Finds the index of a employee record with a given ID.
     * @param id (int) The ID of the employee record to search for.
     * @return (int) The index of the matching employee record.
     */
    int getIndex(int id);
    
    /**
     * @brief Finds the index of a employee record with a given description.
     * @param description (std::string) The description of the employee record to search for.
     * @return (int) The index of the matching employee record or -1 in case the input does not match any record.
     */
    int getIndex(std::string & description);
    
    /**
     * @brief Finds the index of a employee record with a given legal id.
     * @param legal_id (long long int) The legal id of the employee record to search for.
     * @return (int) The index of the matching employee record or -1 in case the input does not match any record.
     */
    int getIndex(long long int legal_id);
    
    /**
     * @brief Retrieves the total number of employee records stored in the archive file.
     * @return (int) Amount of employee records stored in the archive file.
     * @note Calculates the number of records by dividing the file's size by the size of each employee record.
     */
    int getAmountOfRegisters();
    
    /**
     * @brief Creates an empty employee archive file.
     * @warning The method does not check if the file already exists; it will create a new empty file or overwrite an existing one.
     */
    void createEmptyArchive();

    private:
    
    /**
     * @brief Path where the file will be saved.
     */ 
    std::string _path;

};