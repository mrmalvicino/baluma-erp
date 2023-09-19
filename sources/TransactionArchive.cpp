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


int write(Transaction & reg, FILE *file){
    file=fopen("transaction.dat","ab");
    if(file==NULL){
        printf("\nError al abrir el archivo.");
        return -1;
    }
    reg.cinTransaction();
    fwrite(& reg,sizeof reg,1,file);
    fclose(file);
}

int read(Transaction & reg,FILE *file){
    file=fopen("transaction.dat","rb");
    if(file==NULL){
        printf("\nError al abrir el archivo.");
        return -1;
    }
    while(fread(& reg,sizeof reg,1,file)==1){
    reg.coutTransaction();
    std::cout<<"\n";
    }
    fclose(file);
}

Transaction readS(Transaction & reg,FILE *file,int index) {
    file = fopen("Transaction.dat", "rb");

    if (file == NULL) {
        printf("\nError al abrir el archivo.");
        return reg;
    }

    fseek(file, sizeof(Transaction) * index, 0);
    fread(& reg, sizeof(Transaction), 1, file);
    reg.coutTransaction();
    fclose(file);

    return reg;
}