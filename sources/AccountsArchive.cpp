#include <iostream>
#include "../headers/AccountsArchive.h"

AccountsArchive::AccountsArchive() {
    setPath("registers/accounts.dat");
}

AccountsArchive::AccountsArchive(const std::string & path) {
    setPath(path);
}

void AccountsArchive::setPath(const std::string & path) {
    _path = path;
}

std::string AccountsArchive::getPath() const {
    return _path;
}

bool AccountsArchive::write(Account & reg) {
    FILE * file_pointer = fopen(getPath().c_str(), "ab");

    if (file_pointer == NULL) {
        std::cerr << "Erorr: No se pudo abrir el archivo.\n";
        return 0;
    }

    bool successful_write = fwrite(& reg, sizeof(Account), 1, file_pointer);
    fclose(file_pointer);

    return successful_write;
}

bool AccountsArchive::overWrite(Account & reg, int index) {
    FILE * file_pointer = fopen(getPath().c_str(), "rb+");

    if (file_pointer == NULL) {
        std::cerr << "Erorr: No se pudo abrir el archivo.\n";
        return 0;
    }

    fseek(file_pointer, sizeof(Account) * index, 0);
    bool successful_write = fwrite(& reg, sizeof(Account), 1, file_pointer);
    fclose(file_pointer);

    return successful_write;
}

Account AccountsArchive::read(int index) {
    Account reg;
    FILE * file_pointer = fopen(getPath().c_str(), "rb");

    if (file_pointer == NULL) {
        std::cerr << "Error:No se pudo abrir el archivo.\n";
        reg.setId(-1);
        return reg;
    }

    fseek(file_pointer, sizeof(Account) * index, 0);
    fread(& reg, sizeof(Account), 1, file_pointer);
    fclose(file_pointer);

    return reg;
}

int AccountsArchive::getIndex(int id) {
    int i = 0;
    Account reg;
    reg = read(i);

    while (reg.getId() != id && i < getAmountOfRegisters()) {
        i++;
        reg = read(i);
    }

    return i;
}

int AccountsArchive::getIndex(std::string & account_name) {
    int i = 0;
    Account reg;
    reg = read(i);

    while (reg.getAccountName() != account_name && i < getAmountOfRegisters()) {
        i ++;
        reg = read(i);
    }

    if (i == getAmountOfRegisters()) {
        i = -1;
    }

    return i;
}

int AccountsArchive::getAmountOfRegisters() {
    FILE * file_pointer = fopen(getPath().c_str(), "rb");

    if (file_pointer == NULL) {
        return 0;
    }

    fseek(file_pointer, 0, SEEK_END);
    int bytes = ftell(file_pointer);
    fclose(file_pointer);
    int total_stores = bytes / sizeof(Account);

    return total_stores;
}

void AccountsArchive::createEmptyArchive() {
    FILE * file_pointer = fopen(getPath().c_str(), "wb");

    if (file_pointer == NULL) {
        std::cerr << "Error: No se pudo abrir el archivo.\n";
    } else {
        fclose(file_pointer);
    }
}