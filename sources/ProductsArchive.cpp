#include "../headers/ProductsArchive.h"

ProductsArchive::ProductsArchive() {
    setPath("registers/products.dat");
}

ProductsArchive::ProductsArchive(const std::string & path) {
    setPath(path);
}

void ProductsArchive::setPath(const std::string & path) {
    _path = path;
}

std::string ProductsArchive::getPath() {
    return _path;
}

bool ProductsArchive::write(Product & reg) {
    FILE * file_pointer = fopen(getPath().c_str(), "ab");

    if (file_pointer == NULL) {
        std::cerr << "Error: No se pudo abrir el archivo.\n";
        return 0;
    }

    bool successful_write = fwrite(& reg, sizeof(Product), 1, file_pointer);
    fclose(file_pointer);

    return successful_write;
}

bool ProductsArchive::overWrite(Product & reg, int index) {
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

Product ProductsArchive::read(int index) {
    Product reg;
    FILE * file_pointer = fopen(getPath().c_str(), "rb");

    if (file_pointer == NULL) {
        return reg;
    }

    fseek(file_pointer, sizeof(Product) * index, 0);
    fread(& reg, sizeof(Product), 1, file_pointer);
    fclose(file_pointer);

    return reg;
}

int ProductsArchive::getIndex(int id) {
     int i = 0;
    Product reg;
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

int ProductsArchive::getIndex(Product & product) {
    int i = 0;
    Product reg;
    reg = read(i);

    while (reg.toString() != product.toString() && i < getAmountOfRegisters()) {
        i ++;
        reg = read(i);
    }

    if (i == getAmountOfRegisters()) {
        i = -1;
    }

    return i;
}

int ProductsArchive::getAmountOfRegisters() {
    FILE * file_pointer = fopen(getPath().c_str(), "rb");

    if (file_pointer == NULL) {
        return 0;
    }

    fseek(file_pointer, 0, SEEK_END);
    int bytes = ftell(file_pointer);
    fclose(file_pointer);
    int total_products = bytes / sizeof(Product);

    return total_products;
}

void ProductsArchive::createEmptyArchive() {
    FILE * file_pointer = fopen(getPath().c_str(), "wb");

    if (file_pointer == NULL) {
        std::cerr << "Error: No se pudo abrir el archivo.\n";
    } else {
        fclose(file_pointer);
    }
}