#include <iostream>
#include "../headers/WarehousesArchive.h"

WarehousesArchive::WarehousesArchive() {
    setPath("registers/warehouses.dat");
}

WarehousesArchive::WarehousesArchive(const std::string & path) {
    setPath(path);
}

void WarehousesArchive::setPath(const std::string & path) {
    setPath(path);
}

std::string WarehousesArchive::getPath() const {
    return _path;
}

bool WarehousesArchive::write(Warehouse & reg) {
    FILE * file_pointer = fopen(getPath().c_str(), "ab");

    if (file_pointer == NULL) {
        std::cerr << "Erorr: No se pudo abrir el archivo.\n";
        return 0;
    }

    bool successful_write = fwrite(& reg, sizeof(Warehouse), 1, file_pointer);
    fclose(file_pointer);

    return successful_write;
}

bool WarehousesArchive::overWrite(Warehouse & reg, int index) {
    FILE * file_pointer = fopen(getPath().c_str(), "rb+");

    if (file_pointer == NULL) {
        std::cerr << "Erorr: No se pudo abrir el archivo.\n";
        return 0;
    }

    fseek(file_pointer, sizeof(Warehouse) * index, 0);
    bool successful_write = fwrite(& reg, sizeof(Warehouse), 1, file_pointer);
    fclose(file_pointer);

    return successful_write;
}

Warehouse WarehousesArchive::read(int index) {
    Warehouse reg;
    FILE * file_pointer = fopen(getPath().c_str(), "rb");

    if (file_pointer == NULL) {
        std::cerr << "Error:No se pudo abrir el archivo.\n";
        reg.setId(-1);
        return reg;
    }

    fseek(file_pointer, sizeof(Warehouse) * index, 0);
    fread(& reg, sizeof(Warehouse), 1, file_pointer);
    fclose(file_pointer);

    return reg;
}

int WarehousesArchive::getIndex(int id) {
    int i = 0;
    Warehouse reg;
    reg = read(i);

    while (reg.getId() != id && i < getAmountOfRegisters()) {
        i++;
        reg = read(i);
    }

    return i;
}

int WarehousesArchive::getIndex(std::string & name) {
    int i = 0;
    Warehouse reg;
    reg = read(i);

    while (reg.getName() != name && i < getAmountOfRegisters()) {
        i++;
        reg = read(i);
    }

    return i;
}

int WarehousesArchive::getAmountOfRegisters() {
    FILE * file_pointer = fopen(getPath().c_str(), "rb");

    if (file_pointer == NULL) {
        std::cerr << "Error: No se pudo abrir el archivo.";
        return 0;
    }

    fseek(file_pointer, 0, SEEK_END);
    int bytes = ftell(file_pointer);
    fclose(file_pointer);
    int total_stores = bytes / sizeof(Warehouse);

    return total_stores;
}

void WarehousesArchive::createEmptyArchive() {
    FILE * file_pointer = fopen(getPath().c_str(), "wb");

    if (file_pointer == NULL) {
        std::cerr << "Error: No se pudo abrir el archivo.\n";
    } else {
        fclose(file_pointer);
    }
}