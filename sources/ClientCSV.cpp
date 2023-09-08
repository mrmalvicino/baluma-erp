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

void ClientCSV::writeClientsCSV(Client & client, ClientArchive & client_archive) {
    std::ofstream file(getPath());

    if (file.is_open() == false) {
        std::cerr << "Error: No se pudo abrir el archivo al exportar CSV.\n";
    } else {
        int amount_ofclients = client_archive.getAmountOfRegisters();

        for (int i = 0; i < amount_ofclients; i ++) {
            client = client_archive.read(i);
            file << client.getId() << getDelimiter() << client.getDescription() << getDelimiter() << client.getLegalId() << getDelimiter() << client.getAdress().getCountry() << getDelimiter() << client.getAdress().getState() << getDelimiter() << client.getAdress().getCity() << getDelimiter() << client.getAdress().getStreet() << getDelimiter() << client.getAdress().getNumber() << getDelimiter() << client.getAdress().getFloor() << getDelimiter() << client.getAdress().getLetter() << getDelimiter() << client.getPhone() << getDelimiter() << client.getEmail() << getDelimiter() << client.getIsActive() << getDelimiter() << client.getCategory() << "\n";
        }

        file.close();

        std::cout << "CSV exportado correctamente.\n";
        _terminal.pause();
    }
}

void ClientCSV::readClientsCSV(Client & client, ClientArchive & client_archive) {
    std::ifstream file(getPath());

    if (!file.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo al importar CSV.\n";
        return;
    }

    client_archive.createEmptyClientArchive();
    std::string row;
    const int amount_of_columns = 14;
    std::string column[amount_of_columns];

    while (std::getline(file, row)) {
        std::stringstream stream(row);

        for (int j = 0; j < amount_of_columns; j ++) {
            getline(stream, column[j], getDelimiter());
        }

        client.setId(std::stoi(column[0]));
        client.setDescription(column[1]);
        client.setLegalId(std::stoll(column[2]));
        Adress adress;
        adress.setCountry(column[3]);
        adress.setState(column[4]);
        adress.setCity(column[5]);
        adress.setStreet(column[6]);
        adress.setNumber(std::stoi(column[7]));
        adress.setFloor(std::stoi(column[8]));
        adress.setLetter(column[9][0]);
        client.setAdress(adress);
        client.setPhone(std::stoi(column[10]));
        client.setEmail(column[11]);
        client.setIsActive(std::stoi(column[12]));
        client.setCategory(column[13][0]);

        client_archive.write(client);
    }

    file.close();
    std::cout << "CSV importado correctamente.\n";
    _terminal.pause();
}