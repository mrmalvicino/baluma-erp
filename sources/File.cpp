#include <iostream>
#include "../headers/File.h"

// Construct

// Public Methods

bool File::write(Register & reg_write) const {
    FILE * file_pointer = fopen("registers/registers.dat", "ab");
    bool successful_write = fwrite(& reg_write, sizeof(Register), 1, file_pointer);
    fclose(file_pointer);

    return successful_write;
}

Register File::read(int reg_index) {
    Register reg_read;
    FILE * file_pointer = fopen("registers/registers.dat", "rb");
    fseek(file_pointer, sizeof(Register) * reg_index, 0);
    fread(& reg_read, sizeof(Register), 1, file_pointer);
    fclose(file_pointer);

    return reg_read;
}

int File::getAmountOfRegisters() {
    FILE * file_pointer = fopen("registers/registers.dat", "rb");
    fseek(file_pointer, 0, SEEK_END);
    int bytes = ftell(file_pointer);
    fclose(file_pointer);
    int total_registers = bytes / sizeof(Register);

    return total_registers;
}