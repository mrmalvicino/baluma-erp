#pragma once
#include <iostream>
#include <cstdio>
#include "Employee.h"

class EmployeesArchive
{
    public:
        EmployeesArchive();
        EmployeesArchive(const std::string & path);

        void setPath(const std::string & path);
        std::string getPath() const;

        bool write(Employee & reg);

        bool overWrite(Employee & reg, int index);

        Employee read(int index);

        int getIndex(int id);

        int getIndex(std::string & description);

        int getIndex(long long int legal_id);

        int getAmountOfRegisters();

        void createEmptyArchive();

    private:
        std::string _path;

};