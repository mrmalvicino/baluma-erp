#include "../headers/AccountsArchive.h"

AccountsArchive::AccountsArchive() {
    setPath("registers/accounts.dat");
}

AccountsArchive::AccountsArchive(std::string path) {
    setPath(path);
}

void AccountsArchive::setPath(std::string path) {
    _path=path;
}

std::string AccountsArchive::getPath() {
    return _path;
}

bool AccountsArchive::write(Account & reg) {
    FILE * file_pointer = fopen(getPath().c_str(), "ab");

    if (file_pointer == NULL) {
        std::cerr << "Error: No se pudo abrir el archivo.\n";
        return 0;
    }

    bool successful_write = fwrite(& reg, sizeof(Account), 1, file_pointer);
    fclose(file_pointer);

    return successful_write;
}

bool AccountsArchive::overWrite(Account & reg, int index) {
        FILE * file_pointer = fopen(getPath().c_str(), "rb+");

    if (file_pointer == NULL) {
        std::cerr << "Error: No se pudo abrir el archivo.\n";
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
    std::cerr << "Error: No se pudo abrir el archivo.\n";
    return reg;
    }

    fseek(file_pointer, sizeof(Account) * index, 0);
    fread(& reg, sizeof(Account), 1, file_pointer);
    fclose(file_pointer);

    return reg;
}

int AccountsArchive::getAccountNumber(int id) {
    int i = 0;
    Account reg;
    reg = read(i);

    while (reg.getAccountNumber() != id && i < getAmountOfRegisters()) {
    i ++;
    reg = read(i);
    }

    return i;
}

int AccountsArchive::getAccountType(int id) {
    int type;
    Account reg;
    reg = read(id);
    type = reg.getType();
    return type;
}

int AccountsArchive::getAmountOfRegisters() {
        FILE * file_pointer = fopen(getPath().c_str(), "rb");

    if (file_pointer == NULL) {
    //std::cerr << "Error: No se pudo abrir el archivo.\n";
    return 0;
    }
    fseek(file_pointer, 0, SEEK_END);
    int bytes = ftell(file_pointer);
    fclose(file_pointer);
    int total_accounts = bytes / sizeof(Account);

    return total_accounts;
}

int AccountsArchive::getIndex(int id) {
    int i = 0;
    Account reg;
    reg = read(i);

    while (reg.getId() != id && i < getAmountOfRegisters()) {
        i ++;
        reg = read(i);
    }

    if (i == getAmountOfRegisters()) {
        i = -1;
    }

    return i;
    }

int AccountsArchive::getIndex(std::string & name) {
    int i = 0;
    Account reg;
    reg = read(i);

    while (reg.getAccountName() != name && i < getAmountOfRegisters()) {
        i ++;
        reg = read(i);
    }

    if (i == getAmountOfRegisters()) {
        i = -1;
    }

    return i;
}

void AccountsArchive::createEmptyArchive() {
    FILE * file_pointer = fopen(getPath().c_str(), "wb");

    if (file_pointer == NULL) {
        std::cerr << "Error: No se pudo abrir el archivo.\n";
    } else {
        fclose(file_pointer);
    }
}