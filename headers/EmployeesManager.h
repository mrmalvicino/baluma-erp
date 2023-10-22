#pragma once
#include "Terminal.h"
#include "EmployeesArchive.h"

class EmployeesManager
{
    public:
        EmployeesManager();

        void displayMenu();

        bool addEmployee();

        bool editEmployee();

        int searchEmployee();

        int searchEmployeeById();

        int searchEmployeeByName();

        int searchEmployeeByDNI();

        void listEmployees(bool active);

        void printEmployee(int index);

        void cinEmployeeName(Employee & employee);
        
        void cinEmployeeLegalId(Employee & employee);

        void cinEmployeeAdress(Employee & employee);

        void cinEmployeePhone(Employee & employee);

        void cinEmployeeEmail(Employee & employee);

        void cinEmployeeIsActive(Employee & employee);

        void cinEmployeeTitle(Employee & employee);

        void cinEmployeeAdmission(Employee & employee);

        int generateEmployeeId();

        void exportEmployeeBackup();

        void importEmployeeBackup();

        bool calculateSeniority();



    private:
        Terminal _terminal;
        Employee _employee;
        EmployeesArchive _employees_archive;
};