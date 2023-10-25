#include <iostream>
#include "../headers/TransactionsArchive.h"

TransactionsArchive::TransactionsArchive() {
    setPath("registers/transactions.dat");
}

TransactionsArchive::TransactionsArchive(const std::string & path) {
    setPath(path);
}

void TransactionsArchive::setPath(const std::string & path) {
    _path = path;
}

std::string TransactionsArchive::getPath() const {
    return _path;
}

bool TransactionsArchive::write(Transaction & reg) {
    FILE * file_pointer = fopen(getPath().c_str(), "ab");

    if (file_pointer == NULL) {
        std::cerr << "Erorr: No se pudo abrir el archivo.\n";
        return 0;
    }

    bool successful_write = fwrite(& reg, sizeof(Transaction), 1, file_pointer);
    fclose(file_pointer);

    return successful_write;
}

bool TransactionsArchive::overWrite(Transaction & reg, int index) {
    FILE * file_pointer = fopen(getPath().c_str(), "rb+");

    if (file_pointer == NULL) {
        std::cerr << "Erorr: No se pudo abrir el archivo.\n";
        return 0;
    }

    fseek(file_pointer, sizeof(Transaction) * index, 0);
    bool successful_write = fwrite(& reg, sizeof(Transaction), 1, file_pointer);
    fclose(file_pointer);

    return successful_write;
}

Transaction TransactionsArchive::read(int index) {
    Transaction reg;
    FILE * file_pointer = fopen(getPath().c_str(), "rb");

    if (file_pointer == NULL) {
        std::cerr << "Error:No se pudo abrir el archivo.\n";
        reg.setId(-1);
        return reg;
    }

    fseek(file_pointer, sizeof(Transaction) * index, 0);
    fread(& reg, sizeof(Transaction), 1, file_pointer);
    fclose(file_pointer);

    return reg;
}

int TransactionsArchive::getIndex(int id) {
    int i = 0;
    Transaction reg;
    reg = read(i);

    while (reg.getId() != id && i < getAmountOfRegisters()) {
        i++;
        reg = read(i);
    }

    return i;
}

int TransactionsArchive::getIndex(std::string & description) {
    int i = 0;
    Transaction reg;
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

int TransactionsArchive::getAmountOfRegisters() {
    FILE * file_pointer = fopen(getPath().c_str(), "rb");

    if (file_pointer == NULL) {
        return 0;
    }

    fseek(file_pointer, 0, SEEK_END);
    int bytes = ftell(file_pointer);
    fclose(file_pointer);
    int total_stores = bytes / sizeof(Transaction);

    return total_stores;
}

void TransactionsArchive::createEmptyArchive() {
    FILE * file_pointer = fopen(getPath().c_str(), "wb");

    if (file_pointer == NULL) {
        std::cerr << "Error: No se pudo abrir el archivo.\n";
    } else {
        fclose(file_pointer);
    }
}