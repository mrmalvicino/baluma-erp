#include "../headers/ItemsArchive.h"

ItemsArchive::ItemsArchive() {
    setPath("registers/products.dat");
}

ItemsArchive::ItemsArchive(const std::string & path) {
    setPath(path);
}

void ItemsArchive::setPath(const std::string & path) {
    _path = path;
}

std::string ItemsArchive::getPath() {
    return _path;
}

bool ItemsArchive::write(Item & reg) {
    FILE * file_pointer = fopen(getPath().c_str(), "ab");

    if (file_pointer == NULL) {
        std::cerr << "Error: No se pudo abrir el archivo.\n";
        return 0;
    }

    bool successful_write = fwrite(& reg, sizeof(Item), 1, file_pointer);
    fclose(file_pointer);

    return successful_write;
}

bool ItemsArchive::overWrite(Item & reg, int index) {
    FILE * file_pointer = fopen(getPath().c_str(), "rb+");

    if (file_pointer == NULL) {
        std::cerr << "Error: No se pudo abrir el archivo.\n";
        return 0;
    }

    fseek(file_pointer, sizeof(Item) * index, 0);
    bool successful_write = fwrite(& reg, sizeof(Item), 1, file_pointer);
    fclose(file_pointer);

    return successful_write;
}

Item ItemsArchive::read(int index) {
    Item reg;
    FILE * file_pointer = fopen(getPath().c_str(), "rb");

    if (file_pointer == NULL) {
        std::cerr << "Error: No se pudo abrir el archivo.\n";
        return reg;
    }

    fseek(file_pointer, sizeof(Item) * index, 0);
    fread(& reg, sizeof(Item), 1, file_pointer);
    fclose(file_pointer);

    return reg;
}

int ItemsArchive::getIndex(int id) {
     int i = 0;
    Item reg;
    reg = read(i);

    while (reg.getId() != id && i < getAmountOfRegisters()) {
        i ++;
        reg = read(i);
    }

    return i;
}

int ItemsArchive::getIndex(std::string & description) {
    int i = 0;
    Item reg;
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

int ItemsArchive::getAmountOfRegisters() {
    FILE * file_pointer = fopen(getPath().c_str(), "rb");

    if (file_pointer == NULL) {
        return 0;
    }

    fseek(file_pointer, 0, SEEK_END);
    int bytes = ftell(file_pointer);
    fclose(file_pointer);
    int total_items = bytes / sizeof(Item);

    return total_items;
}

void ItemsArchive::createEmptyArchive() {
    FILE * file_pointer = fopen(getPath().c_str(), "wb");

    if (file_pointer == NULL) {
        std::cerr << "Error: No se pudo abrir el archivo.\n";
    } else {
        fclose(file_pointer);
    }
}