#include "../headers/ClientsArchive.h"

ClientsArchive::ClientsArchive() {
    setPath("registers/clients.dat");
}

ClientsArchive::ClientsArchive(std::string path) {
    setPath(path);
}

void ClientsArchive::setPath(std::string path) {
    _path = path;
}

std::string ClientsArchive::getPath() {
    return _path;
}

bool ClientsArchive::write(Client & reg) {
    FILE * file_pointer = fopen(getPath().c_str(), "ab");

    if (file_pointer == NULL) {
        std::cerr << "Error: No se pudo abrir el archivo.\n";
        return 0;
    }

    bool successful_write = fwrite(& reg, sizeof(Client), 1, file_pointer);
    fclose(file_pointer);

    return successful_write;
}

bool ClientsArchive::overWrite(Client & reg, int index) {
    FILE * file_pointer = fopen(getPath().c_str(), "rb+");

    if (file_pointer == NULL) {
        std::cerr << "Error: No se pudo abrir el archivo.\n";
        return 0;
    }

    fseek(file_pointer, sizeof(Client) * index, 0);
    bool successful_write = fwrite(& reg, sizeof(Client), 1, file_pointer);
    fclose(file_pointer);

    return successful_write;
}

Client ClientsArchive::read(int index) {
    Client reg;
    FILE * file_pointer = fopen(getPath().c_str(), "rb");

    if (file_pointer == NULL) {
        std::cerr << "Error: No se pudo abrir el archivo.\n";
        return reg;
    }

    fseek(file_pointer, sizeof(Client) * index, 0);
    fread(& reg, sizeof(Client), 1, file_pointer);
    fclose(file_pointer);

    return reg;
}

int ClientsArchive::getIndex(int id) {
    int i = 0;
    Client reg;
    reg = read(i);

    while (reg.getId() != id && i < getAmountOfRegisters()) {
        i ++;
        reg = read(i);
    }

    return i;
}

int ClientsArchive::getIndex(std::string & description) {
    int i = 0;
    Client reg;
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

int ClientsArchive::getAmountOfRegisters() {
    FILE * file_pointer = fopen(getPath().c_str(), "rb");

    if (file_pointer == NULL) {
        return 0;
    }

    fseek(file_pointer, 0, SEEK_END);
    int bytes = ftell(file_pointer);
    fclose(file_pointer);
    int total_clients = bytes / sizeof(Client);

    return total_clients;
}

void ClientsArchive::createEmptyArchive() {
    FILE * file_pointer = fopen(getPath().c_str(), "wb");

    if (file_pointer == NULL) {
        std::cerr << "Error: No se pudo abrir el archivo.\n";
    } else {
        fclose(file_pointer);
    }
}