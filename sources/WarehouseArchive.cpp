#include <iostream>
#include "../headers/WarehouseArchive.h"


WarehouseArchive::WarehouseArchive() : _path("registers/Warehouse.dat")
{}


WarehouseArchive::WarehouseArchive(const std::string &path) : _path(path)
{}

void WarehouseArchive::setPath(const std::string &path)
{
    _path = path;
}
std::string WarehouseArchive::getPath() const
{
    return _path;
}

bool WarehouseArchive::write(Warehouse &reg)
{
    FILE * file_pointer = fopen(getPath().c_str(), "ab");

    if(file_pointer == NULL)
    {
        std::cerr << "Erorr: No se pudo abrir el archivo.\n";
        return 0;
    }

    bool successful_write = fwrite(&reg, sizeof(Warehouse), 1, file_pointer);
    fclose(file_pointer);

    return successful_write;
}

bool WarehouseArchive::overWrite(Warehouse &reg, int index)
{
    FILE * file_pointer = fopen(getPath().c_str(), "rb+");

    if(file_pointer == NULL)
    {
        std::cerr << "Erorr: No se pudo abrir el archivo.\n";
        return 0;
    }

    fseek(file_pointer, sizeof(Warehouse) * index, 0);
    bool successful_write = fwrite(&reg, sizeof(Warehouse), 1, file_pointer);
    fclose(file_pointer);

    return successful_write;
}

Warehouse WarehouseArchive::read(int index)
{
    Warehouse reg;
    FILE * file_pointer = fopen(getPath().c_str(), "rb");

    if(file_pointer == NULL)
    {
        std::cerr << "Error:No se pudo abrir el archivo.\n";
        reg.setId(-1);
        return reg;
    }

    fseek(file_pointer, sizeof(Warehouse) * index, 0);
    fread(&reg, sizeof(Warehouse), 1, file_pointer);
    fclose(file_pointer);

    return reg;
}

int WarehouseArchive::getIndex(int id)
{
    int i = 0;
    Warehouse reg;
    reg = read(i);

    while(reg.getId() != id && i < getAmountOfRegisters())
    {
        i++;
        reg = read(i);
    }

    return i;
}

int WarehouseArchive::getIndex(std::string &name)
{
    int i = 0;
    Warehouse reg;
    reg = read(i);

    while(reg.getName() != name && i < getAmountOfRegisters())
    {
        i++;
        reg = read(i);
    }

    return i;
}

int WarehouseArchive::getAmountOfRegisters()
{
    FILE * file_pointer = fopen(getPath().c_str(), "rb");

    if(file_pointer == NULL)
    {
        std::cerr << "Error: No se pudo abrir el archivo.";
        return 0;
    }

    fseek(file_pointer, 0, SEEK_END);
    int bytes = ftell(file_pointer);
    fclose(file_pointer);
    int total_stores = bytes / sizeof(Warehouse);

    return total_stores;

}

void WarehouseArchive::createEmptyClientArchive()
{
    FILE * file_pointer = fopen(getPath().c_str(), "wb");

    if(file_pointer == NULL)
    {
        std::cerr << "Error: No se pudo abrir el archivo.\n";
    } else 
    {
        fclose(file_pointer);
    }
}
