#include <iostream>
#include "../headers/ClientArchive.h"

ClientArchive::ClientArchive() {
    setPath("registers/clients.dat");
}

ClientArchive::ClientArchive(std::string path) {
    setPath(path);
}

void ClientArchive::setPath(std::string path) {
    _path = path;
}

std::string ClientArchive::getPath() {
    return _path;
}

bool ClientArchive::write(Client & reg) {
    FILE * file_pointer = fopen(getPath().c_str(), "ab");
    bool successful_write = fwrite(& reg, sizeof(Client), 1, file_pointer);
    fclose(file_pointer);

    return successful_write;
}

bool ClientArchive::overWrite(Client & reg, int index) {
    FILE * file_pointer = fopen(getPath().c_str(), "rb+");
    fseek(file_pointer, sizeof(Client) * index, 0);
    bool successful_write = fwrite(& reg, sizeof(Client), 1, file_pointer);
    fclose(file_pointer);

    return successful_write;
}

Client ClientArchive::read(int index) {
    Client reg;
    FILE * file_pointer = fopen(getPath().c_str(), "rb");
    fseek(file_pointer, sizeof(Client) * index, 0);
    fread(& reg, sizeof(Client), 1, file_pointer);
    fclose(file_pointer);

    return reg;
}

int ClientArchive::getIndex(int id) {
    int i = 0;
    Client reg;
    reg = read(i);

    while (reg.getId() != id && i < getAmountOfRegisters()) {
        i ++;
        reg = read(i);
    }

    return i;
}

int ClientArchive::getIndex(std::string description) {
    int i = 0;
    Client reg;
    reg = read(i);

    while (reg.getDescription() != description && i < getAmountOfRegisters()) {
        i ++;
        reg = read(i);
    }

    return i;
}

int ClientArchive::getAmountOfRegisters() {
    FILE * file_pointer = fopen(getPath().c_str(), "rb");
    fseek(file_pointer, 0, SEEK_END);
    int bytes = ftell(file_pointer);
    fclose(file_pointer);
    int total_clients = bytes / sizeof(Client);

    return total_clients;
}