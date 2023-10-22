#include "../headers/EmployeesArchive.h"

EmployeesArchive::EmployeesArchive() : _path("registers/employees.dat")
{}

EmployeesArchive::EmployeesArchive(const std::string &path) : _path(path)
{}

void EmployeesArchive::setPath(const std::string &path)
{
    _path = path;
}

std::string EmployeesArchive::getPath() const
{
    return _path;
}
bool EmployeesArchive::write(Employee &reg)
{
    FILE * file_pointer = fopen(getPath().c_str(), "ab");

    if(file_pointer == NULL)
    {
        std::cerr << "Error: No se pudo abrir el archivo.\n";
        return 0;
    }

    bool successful_write = fwrite(& reg, sizeof(Employee), 1, file_pointer);
    fclose(file_pointer);

    return successful_write;
}

bool EmployeesArchive::overWrite(Employee &reg, int index)
{
    FILE * file_pointer = fopen(getPath().c_str(), "rb+");

    if(file_pointer == NULL)
    {
        std::cerr << "Error: No se pudo abrir el archivo.\n";
        return 0;
    }

    fseek(file_pointer, sizeof(Employee) * index, 0);
    bool successful_write = fwrite(& reg, sizeof(Employee), 1, file_pointer);
    fclose(file_pointer);

    return successful_write;
}

Employee EmployeesArchive::read(int index)
{
    Employee reg;
    FILE * file_pointer = fopen(getPath().c_str(), "rb");

    if(file_pointer == NULL)
    {
        std::cerr << "Error: No se pudo abrir el archivo.\n";
        return reg;
    }

    fseek(file_pointer, sizeof(Employee) * index, 0);
    fread(& reg, sizeof(Employee), 1, file_pointer);
    fclose(file_pointer);

    return reg;
}

int EmployeesArchive::getIndex(int id)
{
    int i = 0;
    Employee reg;
    reg = read(i);

    while (reg.getId() != id && i < getAmountOfRegisters())
    {
        i++;
        reg = read(i);
    }

    return i;
    
}

int EmployeesArchive::getIndex(std::string &description)
{
    int i = 0;
    Employee reg;
    reg = read(i);

    while (reg.getDescription() != description && i < getAmountOfRegisters())
    {
        i++;
        reg = read(i);
    }

    if(i == getAmountOfRegisters() + 1)
    {
        i = -1;
    }

    return i;
    
}

int EmployeesArchive::getIndex(long long int legal_id)
{
    int i = 0;
    Employee reg;
    reg = read(i);

    while(reg.getLegalId() != legal_id && i < getAmountOfRegisters())
    {
        i++;
        reg = read(i);
    }

    if(i == getAmountOfRegisters() + 1)
    {
        i = -1;
    }

    return i;
}

int EmployeesArchive::getAmountOfRegisters()
{
    FILE * file_pointer = fopen(getPath().c_str(), "rb");

    if(file_pointer == NULL)
    {
        return 0;
    }

    fseek(file_pointer, 0, SEEK_END);
    int bytes = ftell(file_pointer);
    fclose(file_pointer);
    int total_employees = bytes / sizeof(Employee);

    return total_employees;
}

void EmployeesArchive::createEmptyArchive()
{
    FILE * file_pointer = fopen(getPath().c_str(), "wb");

    if(file_pointer == NULL)
    {
        std::cerr << "Error: No se pudo abrir el archivo.\n";
    }else{
        fclose(file_pointer);
    }
}
