#include "../headers/ItemCSV.h"

ItemCSV::ItemCSV() : _path("registers/Items.csv"), _delimiter(',')
{}

ItemCSV::ItemCSV(std::string path, char delimiter) : _path(path), _delimiter(delimiter)
{}

void ItemCSV::setPath(std::string path)
{
    _path = path;
}

std::string ItemCSV::getPath() const
{
    return _path;
}

void ItemCSV::setDelimiter(char delimiter)
{
    _delimiter = delimiter;
}

char ItemCSV::getDelimiter()
{
    return _delimiter;
}

void ItemCSV::writeItemsCSV(Item &item, ItemArchive &item_archive)
{
      std::ofstream file(getPath());

    if (file.is_open() == false) {
        std::cerr << "Error: No se pudo abrir el archivo al exportar CSV.\n";
    } else {
        int amount_ofsuppliers = item_archive.getAmountOfRegisters();

        for (int i = 0; i < amount_ofsuppliers; i ++) {
            item = item_archive.read(i);
            file << item.getId() << getDelimiter() << item.getName() << getDelimiter() << item.getDescription() << getDelimiter() << item.getBrand() << getDelimiter() << item.getModel() << getDelimiter() << item.getPrice() << getDelimiter() << item.getStock() << getDelimiter() << item.getIncome().toString() << getDelimiter() << item.getIsActive() << "\n";
        }

        file.close();

        std::cout << "CSV exportado correctamente.\n";
        _terminal.pause();
    }
}

void ItemCSV::readItemsCSV(Item &item, ItemArchive &item_archive)
{
     //preguntar a maxi.
}
