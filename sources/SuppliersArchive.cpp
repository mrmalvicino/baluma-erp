#include <iostream>
#include "../headers/SuppliersArchive.h"

SuppliersArchive::SuppliersArchive() {
    setPath("registers/suppliers.dat");
}

SuppliersArchive::SuppliersArchive(std::string path) {
    setPath(path);
}

void SuppliersArchive::setPath(std::string path) {
    _path = path;
}

std::string SuppliersArchive::getPath() {
    return _path;
}

bool SuppliersArchive::write(Supplier & reg) {
    FILE * file_pointer = fopen(getPath().c_str(), "ab");

    if (file_pointer == NULL) {
        std::cerr << "Error: No se pudo abrir el archivo.\n";
        return 0;
    }

    bool successful_write = fwrite(& reg, sizeof(Supplier), 1, file_pointer);
    fclose(file_pointer);

    return successful_write;
}

bool SuppliersArchive::overWrite(Supplier & reg, int index) {
    FILE * file_pointer = fopen(getPath().c_str(), "rb+");

    if (file_pointer == NULL) {
        std::cerr << "Error: No se pudo abrir el archivo.\n";
        return 0;
    }

    fseek(file_pointer, sizeof(Supplier) * index, 0);
    bool successful_write = fwrite(& reg, sizeof(Supplier), 1, file_pointer);
    fclose(file_pointer);

    return successful_write;
}

Supplier SuppliersArchive::read(int index) {
    Supplier reg;
    FILE * file_pointer = fopen(getPath().c_str(), "rb");

    if (file_pointer == NULL) {
        std::cerr << "Error: No se pudo abrir el archivo.\n";
        return reg;
    }

    fseek(file_pointer, sizeof(Supplier) * index, 0);
    fread(& reg, sizeof(Supplier), 1, file_pointer);
    fclose(file_pointer);

    return reg;
}

int SuppliersArchive::getIndex(int id) {
    int i = 0;
    Supplier reg;
    reg = read(i);

    while (reg.getId() != id && i < getAmountOfRegisters()) {
        i ++;
        reg = read(i);
    }

    return i;
}

int SuppliersArchive::getIndex(std::string & description) {
    int i = 0;
    Supplier reg;
    reg = read(i);

    while (reg.getDescription() != description && i < getAmountOfRegisters()) {
        i ++;
        reg = read(i);
    }

    if (i == getAmountOfRegisters()) {
        i = -1;
    }

    return i;
}

int SuppliersArchive::getAmountOfRegisters() {
    FILE * file_pointer = fopen(getPath().c_str(), "rb");

    if (file_pointer == NULL) {
        std::cerr << "Error: No se pudo abrir el archivo.\n";
        return 0;
    }

    fseek(file_pointer, 0, SEEK_END);
    int bytes = ftell(file_pointer);
    fclose(file_pointer);
    int total_suppliers = bytes / sizeof(Supplier);

    return total_suppliers;
}

void SuppliersArchive::createEmptyArchive() {
    FILE * file_pointer = fopen(getPath().c_str(), "wb");

    if (file_pointer == NULL) {
        std::cerr << "Error: No se pudo abrir el archivo.\n";
    } else {
        fclose(file_pointer);
    }
}