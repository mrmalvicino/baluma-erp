#include "../headers/ItemsCSV.h"

ItemsCSV::ItemsCSV() : _path("registers/Items.csv"), _delimiter(',') {
    setPath("registers/products.csv");
    setDelimiter(',');
}

ItemsCSV::ItemsCSV(std::string path, char delimiter) : _path(path), _delimiter(delimiter) {
    setPath(path);
    setDelimiter(delimiter);
}

void ItemsCSV::setPath(std::string path) {
    _path = path;
}

std::string ItemsCSV::getPath() const {
    return _path;
}

void ItemsCSV::setDelimiter(char delimiter) {
    _delimiter = delimiter;
}

char ItemsCSV::getDelimiter() {
    return _delimiter;
}

void ItemsCSV::writeItemsCSV(Item & item, ItemsArchive & item_archive) {
      std::ofstream file(getPath());

    if (file.is_open() == false) {
        std::cerr << "Error: No se pudo abrir el archivo al exportar CSV.\n";
    } else {
        int amount_of_items = item_archive.getAmountOfRegisters();

        for (int i = 0; i < amount_of_items; i ++) {
            item = item_archive.read(i);
            file << item.getId() << getDelimiter() << item.getName() << getDelimiter() << item.getDescription() << getDelimiter() << item.getBrand() << getDelimiter() << item.getModel() << getDelimiter() << item.getPrice() << getDelimiter() << item.getStock() << getDelimiter() << item.getIncome().getDay() << getDelimiter() << item.getIncome().getMonth() << getDelimiter() << item.getIncome().getYear() << getDelimiter() << item.getIsActive() << "\n";
        }

        file.close();

        std::cout << "CSV exportado correctamente.\n";
        _terminal.pause();
    }
}

void ItemsCSV::readItemsCSV(Item & item, ItemsArchive & item_archive) {
    std::ifstream file(getPath());

    if (!file.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo al importar CSV.\n";
        return;
    }

    item_archive.createEmptyArchive();
    std::string row;
    const int amount_of_columns = 14;
    std::string column[amount_of_columns];

    while (std::getline(file, row)) {
        std::stringstream stream(row);

        for (int j = 0; j < amount_of_columns; j ++) {
            getline(stream, column[j], getDelimiter());
        }

        item.setId(std::stoi(column[0]));
        item.setName(column[1]);
        item.setDescription(column[2]);
        item.setBrand(column[3]);
        item.setModel(column[4]);
        item.setPrice(std::stod(column[5]));
        item.setStock(std::stoi(column[6]));
        Date income;
        income.setDay(std::stoi(column[7]));
        income.setMonth(std::stoi(column[8]));
        income.setYear(std::stoi(column[9]));
        item.setIncome(income);
        item.setIsActive(std::stoi(column[10]));

        item_archive.write(item);
    }

    file.close();
    std::cout << "CSV importado correctamente.\n";
    _terminal.pause();
}
