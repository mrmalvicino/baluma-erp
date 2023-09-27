#include <iostream>
#include "../headers/TransactionArchive.h"

TransactionArchive::TransactionArchive() {
    setPath("registers/transaction.dat");
}

TransactionArchive::TransactionArchive(std::string path) {
    setPath(path);
}

void TransactionArchive::setPath(std::string path) {
    _path = path;
}

std::string TransactionArchive::getPath() {
    return _path;
}

bool TransactionArchive::write(Transaction & reg){
    FILE * file_pointer = fopen(getPath().c_str(), "ab");
     if (file_pointer == NULL) {
        std::cerr << "Error: No se pudo abrir el archivo.\n";
        return 0;
        }
    bool successful_write = fwrite(& reg, sizeof(Transaction), 1, file_pointer);
        fclose(file_pointer);
        return successful_write;
}

bool TransactionArchive::overWrite(Transaction & reg, int index){
    FILE * file_pointer = fopen(getPath().c_str(), "rb+");
     if (file_pointer == NULL) {
        std::cerr << "Error: No se pudo abrir el archivo.\n";
        return 0;
        }
        fseek(file_pointer, sizeof(Transaction) * index, 0);
    bool successful_write = fwrite(& reg, sizeof(Transaction), 1, file_pointer);
        fclose(file_pointer);
        return successful_write;
}

Transaction TransactionArchive::read(int index){
    Transaction reg;
    FILE * file_pointer = fopen(getPath().c_str(), "rb");
     if (file_pointer == NULL) {
        std::cerr << "Error: No se pudo abrir el archivo.\n";
        return reg;
        }
        fseek(file_pointer, sizeof(Transaction) * index, 0);
        fread(& reg, sizeof(Transaction), 1, file_pointer);
        fclose(file_pointer);
        return reg;
}

int TransactionArchive::getAccountNumber(int id){
    int i = 0;
    Transaction reg;
    reg = read(i);
        while (reg.getAccountNumber() != id && i < getAmountOfRegisters()) {
            i ++;
            reg = read(i);
            }
            return i;
}

int TransactionArchive::getAmountOfRegisters(){
    FILE * file_pointer = fopen(getPath().c_str(), "rb");
        if (file_pointer == NULL) {
            std::cerr << "Error: No se pudo abrir el archivo.\n";
            return 1;
            }
        fseek(file_pointer, 0, SEEK_END);
        int bytes = ftell(file_pointer);
        fclose(file_pointer);
        int total_transactions = bytes / sizeof(Transaction);
            return total_transactions;
}

int TransactionArchive::getIndex(int id) {
    int i = 0;
    Transaction reg;
        reg = read(i);
            while (reg.getTransactionId() != id && i < getAmountOfRegisters()) {
                i ++;
                reg = read(i);
            }
            return i;
}

int TransactionArchive::getIndex(std::string & description) {
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

void TransactionArchive::createEmptyTransactionArchive() {
    FILE * file_pointer = fopen(getPath().c_str(), "wb");
        if (file_pointer == NULL) {
                std::cerr << "Error: No se pudo abrir el archivo.\n";
            } else {
                fclose(file_pointer);
            }
}   