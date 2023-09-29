#include "../headers/ProductsList.h"

ProductsList::ProductsList() {
    setPath("registers/products.dat");
}

ProductsList::ProductsList(const std::string & path) {
    setPath(path);
}

void ProductsList::setPath(const std::string & path) {
    _path = path;
}

std::string ProductsList::getPath() {
    return _path;
}

bool ProductsList::write(Product & reg) {
    FILE * file_pointer = fopen(getPath().c_str(), "ab");

    if (file_pointer == NULL) {
        std::cerr << "Error: No se pudo abrir el archivo.\n";
        return 0;
    }

    bool successful_write = fwrite(& reg, sizeof(Product), 1, file_pointer);
    fclose(file_pointer);

    return successful_write;
}

bool ProductsList::overWrite(Product & reg, int index) {
    FILE * file_pointer = fopen(getPath().c_str(), "rb+");

    if (file_pointer == NULL) {
        std::cerr << "Error: No se pudo abrir el archivo.\n";
        return 0;
    }

    fseek(file_pointer, sizeof(Product) * index, 0);
    bool successful_write = fwrite(& reg, sizeof(Product), 1, file_pointer);
    fclose(file_pointer);

    return successful_write;
}

Product ProductsList::read(int index) {
    Product reg;
    FILE * file_pointer = fopen(getPath().c_str(), "rb");

    if (file_pointer == NULL) {
        std::cerr << "Error: No se pudo abrir el archivo.\n";
        return reg;
    }

    fseek(file_pointer, sizeof(Product) * index, 0);
    fread(& reg, sizeof(Product), 1, file_pointer);
    fclose(file_pointer);

    return reg;
}

int ProductsList::getIndex(int id) {
     int i = 0;
    Product reg;
    reg = read(i);

    while (reg.getId() != id && i < getAmountOfRegisters()) {
        i ++;
        reg = read(i);
    }

    return i;
}

int ProductsList::getIndex(std::string & name) {
    int i = 0;
    Product reg;
    reg = read(i);

    while (reg.getName() != name && i < getAmountOfRegisters()) {
        i ++;
        reg = read(i);
    }

    if (i == getAmountOfRegisters()) {
        i = -1;
    }

    return i;
}

int ProductsList::getAmountOfRegisters() {
    FILE * file_pointer = fopen(getPath().c_str(), "rb");

    if (file_pointer == NULL) {
        std::cerr << "Error: No se pudo abrir el archivo.\n";
        return 0;
    }

    fseek(file_pointer, 0, SEEK_END);
    int bytes = ftell(file_pointer);
    fclose(file_pointer);
    int total_items = bytes / sizeof(Product);

    return total_items;
}

void ProductsList::createEmptyArchive() {
    FILE * file_pointer = fopen(getPath().c_str(), "wb");

    if (file_pointer == NULL) {
        std::cerr << "Error: No se pudo abrir el archivo.\n";
    } else {
        fclose(file_pointer);
    }
}