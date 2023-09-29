#include "../headers/WarehousesCSV.h"

WarehousesCSV::WarehousesCSV() {
    setPath("registers/warehouses.csv");
    setDelimiter(',');
}

WarehousesCSV::WarehousesCSV(std::string path, char delimiter) {
    setPath(path);
    setDelimiter(delimiter);
}

void WarehousesCSV::setPath(std::string path) {
    _path = path;
}

std::string WarehousesCSV::getPath() {
    return _path;
}

void WarehousesCSV::setDelimiter(char delimiter) {
    _delimiter = delimiter;
}

char WarehousesCSV::getDelimiter() {
    return _delimiter;
}

void WarehousesCSV::writeWarehousesCSV(Warehouse & warehouse, WarehousesArchive & warehouse_archive) {
    std::ofstream file(getPath());

    if (file.is_open() == false) {
        std::cerr << "Error: No se pudo abrir el archivo al exportar CSV.\n";
    } else {
        int amount_of_warehouses = warehouse_archive.getAmountOfRegisters();

        for (int i = 0; i < amount_of_warehouses; i ++) {
            warehouse = warehouse_archive.read(i);
            file << warehouse.getId() << getDelimiter() << warehouse.getName() << getDelimiter() << warehouse.getAdress().getCountry() << getDelimiter() << warehouse.getAdress().getState() << getDelimiter() << warehouse.getAdress().getCity() << getDelimiter() << warehouse.getAdress().getStreet() << getDelimiter() << warehouse.getAdress().getNumber() << getDelimiter() << warehouse.getAdress().getFloor() << getDelimiter() << warehouse.getAdress().getLetter() << getDelimiter() << warehouse.getIsActive() << "\n";
        }

        file.close();

        std::cout << "CSV exportado correctamente.\n";
        _terminal.pause();
    }
}

void WarehousesCSV::readWarehousesCSV(Warehouse & warehouse, WarehousesArchive & warehouse_archive) {
    std::ifstream file(getPath());

    if (!file.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo al importar CSV.\n";
        return;
    }

    warehouse_archive.createEmptyArchive();
    std::string row;
    const int amount_of_columns = 14;
    std::string column[amount_of_columns];

    while (std::getline(file, row)) {
        std::stringstream stream(row);

        for (int j = 0; j < amount_of_columns; j ++) {
            getline(stream, column[j], getDelimiter());
        }

        warehouse.setId(std::stoi(column[0]));
        warehouse.setName(column[1]);
        Adress adress;
        adress.setCountry(column[2]);
        adress.setState(column[3]);
        adress.setCity(column[4]);
        adress.setStreet(column[5]);
        adress.setNumber(std::stoi(column[6]));
        adress.setFloor(std::stoi(column[7]));
        adress.setLetter(column[8][0]);
        warehouse.setAdress(adress);
        warehouse.setIsActive(std::stoi(column[9]));

        warehouse_archive.write(warehouse);
    }

    file.close();
    std::cout << "CSV importado correctamente.\n";
    _terminal.pause();
}