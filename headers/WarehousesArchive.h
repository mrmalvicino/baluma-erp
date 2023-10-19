/**
 * @file WarehousesArchive.h
 * @author Franco Baez (Francobaez2309@gmail.com)
 * @brief Represents an archive of warehouses.
 * @copyright GNU General Public License. Copyright (C) 2007 Free Software Foundation, Inc. <https://fsf.org/>
 */

#pragma once
#include "Warehouse.h"

class WarehousesArchive
{
    public:

    WarehousesArchive();

    WarehousesArchive(const std::string &path);

    void setPath(const std::string &path);

    std::string getPath() const;

    bool write(Warehouse &reg);

    bool overWrite(Warehouse &reg, int index);

    Warehouse read(int index);

    int getIndex(int id);

    int getIndex(std::string &name);

    int getAmountOfRegisters();

    void createEmptyArchive();

    private:

    std::string _path;
};