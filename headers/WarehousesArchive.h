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

        void createEmptyClientsArchive();

    private:
        std::string _path;

};