#include <iostream>
#include "../headers/SupplierArchive.h"

SupplierArchive::SupplierArchive() {
    setPath("registers/suppliers.dat");
}

SupplierArchive::SupplierArchive(std::string path) {
    setPath(path);
}

void SupplierArchive::setPath(std::string path) {
    _path = path;
}

std::string SupplierArchive::getPath() {
    return _path;
}

bool SupplierArchive::write(Supplier & reg) {
    FILE * file_pointer = fopen(getPath().c_str(), "ab");
    bool successful_write = fwrite(& reg, sizeof(Supplier), 1, file_pointer);
    fclose(file_pointer);

    return successful_write;
}

bool SupplierArchive::write(Supplier & reg, int index) {
    FILE * file_pointer = fopen(getPath().c_str(), "rb+");
    fseek(file_pointer, sizeof(Supplier) * index, 0);
    bool successful_write = fwrite(& reg, sizeof(Supplier), 1, file_pointer);
    fclose(file_pointer);

    return successful_write;
}

Supplier SupplierArchive::read(int index) {
    Supplier reg;
    FILE * file_pointer = fopen(getPath().c_str(), "rb");
    fseek(file_pointer, sizeof(Supplier) * index, 0);
    fread(& reg, sizeof(Supplier), 1, file_pointer);
    fclose(file_pointer);

    return reg;
}

int SupplierArchive::getIndex(int id) {
    int i = 0;
    Supplier reg;
    reg = read(i);

    while (reg.getId() != id && i < getAmountOfRegisters()) {
        i ++;
        reg = read(i);
    }

    return i;
}

int SupplierArchive::getAmountOfRegisters() {
    FILE * file_pointer = fopen(getPath().c_str(), "rb");
    fseek(file_pointer, 0, SEEK_END);
    int bytes = ftell(file_pointer);
    fclose(file_pointer);
    int total_suppliers = bytes / sizeof(Supplier);

    return total_suppliers;
}