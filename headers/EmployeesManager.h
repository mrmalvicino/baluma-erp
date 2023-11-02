/**
 * @file EmployeesManager.h
 * @author Franco Baez (Francobaez2309@gmail.com), Lucio Luque (Lucholuque98@gmail.com).
 * @brief Manages the employee module.
 * @copyright GNU General Public License. Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
 */

#pragma once
#include "Terminal.h"
#include "EmployeesArchive.h"

class EmployeesManager
{
    public:

    /**
     * @brief Constructs a new EmployeesManager object with default settings.
     */
    EmployeesManager();
    
    /**
     * @brief Displays the employees menu.
     */
    void displayMenu();
    
    /**
     * @brief Adds a new employee to the employee archive by prompting the user for inputs to collect various details of the employee, such as description, legal ID, address, phone, email, and category.
     * @return (bool) Returns true if the new employee record is successfully added and otherwise, returns false.
     */
    bool addEmployee();

    /**
     * @brief Reads a register from the _employees_archive.
     * @param index (int) The index of the account record to read.
     */
    void loadEmployee(int index);
    
    /**
     * @brief Allows editing an existing employee's details interactively.
     * @return (bool) Returns true if the new employee record is successfully edited and otherwise, returns false.
     */
    bool editEmployee();
    
    /**
     * @brief Allows searching for a employee with an interactive menu based on different criteria, including employee ID and employee name.
     * @return (int) Returns 0 if the search was successful or -1 is the search was aborted.
     */
    int searchEmployee();
    
    /**
     * @brief Searches for a employee by their unique ID and displays their details.
     * @return (int) Returns 0 if the search was successful or -1 is the search was aborted.
     */
    int searchEmployeeById();
    
    /**
     * @brief Searches for a employee by their name and displays their details.
     * @return (int) Returns 0 if the search was successful or -1 is the search was aborted.
     */
    int searchEmployeeByName();
    
    /**
     * @brief Searches for a employee by their name and displays their details.
     * @return (int) Returns 0 if the search was successful or -1 is the search was aborted.
     */
    int searchEmployeeByDNI();

    /**
     * @brief Displays a menu with listing options.
     */
    void listEmployeesMenu();
    
    /**
     * @brief Displays a list of all accounts stored in the account archive.
     * @param list_actives (bool) If true, active accounts will be printed.
     * @param list_inactives (bool) If true, inactive accounts will be printed.
     */
    void listEmployees(bool list_actives, bool list_inactives);
    
    /**
     * @brief Prints detailed information about the current _employee.
     */
    void printEmployee();
    
    /**
     * @brief Prompts the user to enter the name of a employee.
     * @param employee (Employee &) A reference to the Employee object where the data will be stored.
     */
    void cinEmployeeName(Employee & employee);
    
    /**
     * @brief Prompts the user to enter the ID card number of a employee.
     * @param employee (Employee &) A reference to the Employee object where the data will be stored.
     */
    void cinEmployeeLegalId(Employee & employee);
    
    /**
     * @brief Prompts the user to enter the adress of a employee.
     * @param employee (Employee &) A reference to the Employee object where the data will be stored.
     */
    void cinEmployeeAdress(Employee & employee);
    
    /**
     * @brief Prompts the user to enter the phone of a employee.
     * @param employee (Employee &) A reference to the Employee object where the data will be stored.
     */
    void cinEmployeePhone(Employee & employee);
    
    /**
     * @brief Prompts the user to enter the email of a employee.
     * @param employee (Employee &) A reference to the Employee object where the data will be stored.
     */
    void cinEmployeeEmail(Employee & employee);
    
    /**
     * @brief Prompts the user to enter the status of a employee.
     * @param employee (Employee &) A reference to the Employee object where the data will be stored.
     */
    void cinEmployeeIsActive(Employee & employee);
    
    /**
     * @brief Prompts the user to enter the title of a employee.
     * @param employee (Employee &) A reference to the Employee object where the data will be stored.
     */
    void cinEmployeeTitle(Employee & employee, bool cin_ignore);
    
    /**
     * @brief Prompts the user to enter the admission of a employee.
     * @param employee (Employee &) A reference to the Employee object where the data will be stored.
     */
    void cinEmployeeAdmission(Employee & employee);
    
    /**
     * @brief Generates a unique employee ID based on the current number of employee records.
     * @return (int) The generated unique employee ID.
     */
    int generateEmployeeId();
    
    /**
     * @brief Exports a binary file with a backup copy of the current _employees_archive.
     */
    void exportEmployeeBackup();
    
    /**
     * @brief Imports a backup copy by overwriting the current _employees_archive.
     */
    void importEmployeeBackup();

    private:

    /**
     * @brief Terminal object with default settings.
     */
    Terminal _terminal;
    
    /**
     * @brief Employee object with default settings.
     */
    Employee _employee;
    
    /**
     * @brief EmployeesArchive object with default path.
     */
    EmployeesArchive _employees_archive;
    
    /**
     * @brief EmployeesArchive object with custom path.
     */
    EmployeesArchive _employees_backup;
};