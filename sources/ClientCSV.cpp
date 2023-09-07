#include "../headers/ClientCSV.h"

ClientCSV::ClientCSV() {
    setPath("registers/clients.csv");
    setDelimiter(',');
}

ClientCSV::ClientCSV(std::string path, char delimiter) {
    setPath(path);
    setDelimiter(delimiter);
}

void ClientCSV::setPath(std::string path) {
    _path = path;
}

std::string ClientCSV::getPath() {
    return _path;
}

void ClientCSV::setDelimiter(char delimiter) {
    _delimiter = delimiter;
}

char ClientCSV::getDelimiter() {
    return _delimiter;
}

void ClientCSV::writeClientsCSV() {
    std::ofstream file(getPath());

    if (file.is_open() == false) {
        std::cerr << "Error: No se pudo abrir el archivo al exportar CSV.\n";
    } else {
        int amount_of_clients = _client_archive.getAmountOfRegisters();

        for (int i = 0; i < amount_of_clients; i ++) {
            _client = _client_archive.read(i);
            file << _client.getId() << getDelimiter() << _client.getDescription() << getDelimiter() << _client.getLegalId() << getDelimiter() << _client.getAdress().getCountry() << getDelimiter() << _client.getAdress().getState() << getDelimiter() << _client.getAdress().getCity() << getDelimiter() << _client.getAdress().getStreet() << getDelimiter() << _client.getAdress().getNumber() << getDelimiter() << _client.getAdress().getFloor() << getDelimiter() << _client.getAdress().getLetter() << getDelimiter() << _client.getPhone() << getDelimiter() << _client.getEmail() << getDelimiter() << _client.getIsActive() << getDelimiter() << _client.getCategory() << "\n";
        }

        file.close();

        std::cout << "CSV exportado correctamente.\n";
        _terminal.pause();
    }
}

void ClientCSV::readClientsCSV() {
    std::ifstream file(getPath());

    if (!file.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo al importar CSV.\n";
        return;
    }

    _client_archive.createNewEmptyFile();
    std::string row;
    const int amount_of_columns = 14;
    std::string column[amount_of_columns];

    while (std::getline(file, row)) {
        std::stringstream stream(row);

        for (int j = 0; j < amount_of_columns; j ++) {
            getline(stream, column[j], getDelimiter());
        }

        _client.setId(std::stoi(column[0]));
        _client.setDescription(column[1]);
        _client.setLegalId(std::stoll(column[2]));
        Adress adress;
        adress.setCountry(column[3]);
        adress.setState(column[4]);
        adress.setCity(column[5]);
        adress.setStreet(column[6]);
        adress.setNumber(std::stoi(column[7]));
        adress.setFloor(std::stoi(column[8]));
        adress.setLetter(column[9][0]);
        _client.setAdress(adress);
        _client.setPhone(std::stoi(column[10]));
        _client.setEmail(column[11]);
        _client.setIsActive(std::stoi(column[12]));
        _client.setCategory(column[13][0]);

        _client_archive.write(_client);
    }

    file.close();
    std::cout << "CSV importado correctamente.\n";
    _terminal.pause();
}