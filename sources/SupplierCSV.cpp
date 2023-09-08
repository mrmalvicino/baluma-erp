#include "../headers/SupplierCSV.h"

SupplierCSV::SupplierCSV() {
    setPath("registers/suppliers.csv");
    setDelimiter(',');
}

SupplierCSV::SupplierCSV(std::string path, char delimiter) {
    setPath(path);
    setDelimiter(delimiter);
}

void SupplierCSV::setPath(std::string path) {
    _path = path;
}

std::string SupplierCSV::getPath() {
    return _path;
}

void SupplierCSV::setDelimiter(char delimiter) {
    _delimiter = delimiter;
}

char SupplierCSV::getDelimiter() {
    return _delimiter;
}

void SupplierCSV::writeSuppliersCSV(Supplier & supplier, SupplierArchive & supplier_archive) {
    std::ofstream file(getPath());

    if (file.is_open() == false) {
        std::cerr << "Error: No se pudo abrir el archivo al exportar CSV.\n";
    } else {
        int amount_ofsuppliers = supplier_archive.getAmountOfRegisters();

        for (int i = 0; i < amount_ofsuppliers; i ++) {
            supplier = supplier_archive.read(i);
            file << supplier.getId() << getDelimiter() << supplier.getDescription() << getDelimiter() << supplier.getLegalId() << getDelimiter() << supplier.getAdress().getCountry() << getDelimiter() << supplier.getAdress().getState() << getDelimiter() << supplier.getAdress().getCity() << getDelimiter() << supplier.getAdress().getStreet() << getDelimiter() << supplier.getAdress().getNumber() << getDelimiter() << supplier.getAdress().getFloor() << getDelimiter() << supplier.getAdress().getLetter() << getDelimiter() << supplier.getPhone() << getDelimiter() << supplier.getEmail() << getDelimiter() << supplier.getIsActive() << getDelimiter() << supplier.getBankAccount() << "\n";
        }

        file.close();

        std::cout << "CSV exportado correctamente.\n";
        _terminal.pause();
    }
}

void SupplierCSV::readSuppliersCSV(Supplier & supplier, SupplierArchive & supplier_archive) {
    std::ifstream file(getPath());

    if (!file.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo al importar CSV.\n";
        return;
    }

    supplier_archive.createEmptySupplierArchive();
    std::string row;
    const int amount_of_columns = 14;
    std::string column[amount_of_columns];

    while (std::getline(file, row)) {
        std::stringstream stream(row);

        for (int j = 0; j < amount_of_columns; j ++) {
            getline(stream, column[j], getDelimiter());
        }

        supplier.setId(std::stoi(column[0]));
        supplier.setDescription(column[1]);
        supplier.setLegalId(std::stoll(column[2]));
        Adress adress;
        adress.setCountry(column[3]);
        adress.setState(column[4]);
        adress.setCity(column[5]);
        adress.setStreet(column[6]);
        adress.setNumber(std::stoi(column[7]));
        adress.setFloor(std::stoi(column[8]));
        adress.setLetter(column[9][0]);
        supplier.setAdress(adress);
        supplier.setPhone(std::stoi(column[10]));
        supplier.setEmail(column[11]);
        supplier.setIsActive(std::stoi(column[12]));
        supplier.setBankAccount(std::stoi(column[13]));

        supplier_archive.write(supplier);
    }

    file.close();
    std::cout << "CSV importado correctamente.\n";
    _terminal.pause();
}