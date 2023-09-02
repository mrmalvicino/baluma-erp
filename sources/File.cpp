#include <iostream>
#include "../headers/File.h"

// Construct

File::File() {
    setPath("registers/registers.dat");
}

File::File(std::string path) {
    setPath(path);
}

// Public Methods

void File::setPath(std::string path) {
    _path = path;
}

std::string File::getPath() {
    return _path;
}

bool File::write(Register & reg_write) {
    FILE * file_pointer = fopen(getPath().c_str(), "ab");
    bool successful_write = fwrite(& reg_write, sizeof(Register), 1, file_pointer);
    fclose(file_pointer);

    return successful_write;
}

bool File::write(Register & reg_write, int index) {
    FILE * file_pointer = fopen(getPath().c_str(), "rb+");
    fseek(file_pointer, sizeof(Register) * index, 0);
    bool successful_write = fwrite(& reg_write, sizeof(Register), 1, file_pointer);
    fclose(file_pointer);

    return successful_write;
}

Register File::read(int index) {
    Register reg_read;
    FILE * file_pointer = fopen(getPath().c_str(), "rb");
    fseek(file_pointer, sizeof(Register) * index, 0);
    fread(& reg_read, sizeof(Register), 1, file_pointer);
    fclose(file_pointer);

    return reg_read;
}

int File::getIndex(int id) {
    int i = 0;
    Register reg_read;
    reg_read = read(i);

    while (reg_read.getId() != id && i < getAmountOfRegisters()) {
        i ++;
        reg_read = read(i);
    }

    return i;
}

int File::getAmountOfRegisters() {
    FILE * file_pointer = fopen(getPath().c_str(), "rb");
    fseek(file_pointer, 0, SEEK_END);
    int bytes = ftell(file_pointer);
    fclose(file_pointer);
    int total_registers = bytes / sizeof(Register);

    return total_registers;
}