#include "../headers/ClientManager.h"

void ClientManager::displayMenu() {
    int selection = 1;

    do {
        _terminal.clear();
        _terminal.displayMenuHeader("CLIENTES");
        std::cout << "(1) AGREGAR NUEVO\n";
        std::cout << "(2) EDITAR EXISTENTE\n";
        std::cout << "(3) BUSCAR CLIENTE\n";
        std::cout << "(4) VER LISTADO\n";
        _terminal.displayMenuFooter();

        selection = _terminal.validateInt(0, 4);

        switch (selection) {
            case 1:
                addClient();
                break;

            case 2:
                editClient();
                break;

            case 3:
                searchClient();
                break;

            case 4:
                listClients();
                break;
        }
    } while (selection != 0);
}

bool ClientManager::addClient() {
    _terminal.clear();
    _terminal.displayMenuHeader("AGREGAR CLIENTE");

    _client.setId(generateId());

    getUserInputForDescription(_client);
    getUserInputForLegalId(_client);
    getUserInputForAdress(_client);
    getUserInputForPhone(_client);
    getUserInputForEmail(_client);

    bool successful_write = _client_archive.write(_client);

    _terminal.pause();
    _terminal.clear();

    return successful_write;
}

bool ClientManager::editClient() {
    _terminal.clear();

    searchClient();

    int selection = 1;

    do {
        _terminal.clear();
        _terminal.displayMenuHeader("EDITAR CLIENTE");
        _terminal.centerAndPrint(_client.getDescription());
        std::cout << "\n";
        std::cout << "(1) EDITAR NOMBRE\n";
        std::cout << "(2) EDITAR CUIL/CUIT\n";
        std::cout << "(3) EDITAR DOMICILIO\n";
        std::cout << "(4) EDITAR TELÉFONO\n";
        std::cout << "(5) EDITAR E-MAIL\n";
        std::cout << "(6) DAR DE BAJA O REINCORPORAR\n";
        _terminal.displayMenuFooter();

        selection = _terminal.validateInt(0, 6);

        switch (selection) {
            case 1:
                getUserInputForDescription(_client);
                break;

            case 2:
                getUserInputForLegalId(_client);
                break;

            case 3:
                getUserInputForAdress(_client);
                break;

            case 4:
                getUserInputForPhone(_client);
                break;

            case 5:
                getUserInputForEmail(_client);
                break;

            case 6:
                getUserInputForIsActive(_client);
                break;
        }
    } while (selection != 0);

    int index = _client_archive.getIndex(_client.getId());
    bool successful_write = _client_archive.overWrite(_client, index);

    return successful_write;
}

void ClientManager::searchClient() {
    _terminal.clear();

    int selection = 1;

    _terminal.displayMenuHeader("BUSCAR CLIENTE");
    std::cout << "(1) BUSCAR POR ID\n";
    std::cout << "(2) BUSCAR POR NOMBRE\n";
    _terminal.displayMenuFooter();

    selection = _terminal.validateInt(0, 2);

    int index;

    switch (selection) {
        case 0:
            _terminal.clear();
            break;

        case 1:
            int id;
            int max_id;
            max_id = generateId() - 1;

            std::cout << "Ingresar ID:\n";
            id = _terminal.validateInt(1, max_id);

            index = _client_archive.getIndex(id);

            printClient(index);

            _terminal.pause();

            break;

        case 2:
            std::string description;

            std::cout << "Ingresar nombre:\n";
            std::cin.ignore();
            getline(std::cin, description);

            index = _client_archive.getIndex(description);

            printClient(index);

            _terminal.pause();

            break;
    }
}

void ClientManager::listClients() {
    _terminal.clear();

    int amount_of_clients = _client_archive.getAmountOfRegisters();

    _terminal.displayMenuHeader("LISTADO DE CLIENTES");

    for (int i = 0; i < amount_of_clients; i ++) {
        printClient(i);
    }

    _terminal.pause();
    _terminal.clear();
}

void ClientManager::printClient(int index) {
    _client = _client_archive.read(index);
    _terminal.displayMenuHeader(_client.getDescription());
    std::cout << "# ID: " << _client.getId() << "\n";
    std::cout << "CUIL/CUIT: " << _client.getLegalId() << "\n";
    std::cout << "País: " << _client.getAdress().getCountry() << "\n";
    std::cout << "Provincia: " << _client.getAdress().getState() << "\n";
    std::cout << "Ciduad: " << _client.getAdress().getCity() << "\n";
    std::cout << "Calle: " << _client.getAdress().getStreet() << "\n";
    std::cout << "Número: " << _client.getAdress().getNumber() << "\n";
    std::cout << "Piso: " << _client.getAdress().getFloor() << "\n";
    std::cout << "Departamento: " << _client.getAdress().getLetter() << "\n";
    std::cout << "Teléfono: " << _client.getPhone() << "\n";
    std::cout << "E-mail: " << _client.getEmail() << "\n";
    std::cout << "Categoría: " << _client.getCategory() << "\n";
    _terminal.printBool(_client.getIsActive(), "Estado: Activo\n\n", "Estado: Dado de baja\n\n");
}

void ClientManager::getUserInputForDescription(Client & client) {
    std::string description;
    std::cout << "Ingresar nombre del cliente:\n";
    std::cin.ignore();
    getline(std::cin, description);
    client.setDescription(description);
}

void ClientManager::getUserInputForLegalId(Client & client) {
    long long int legal_id;
    std::cout << "Ingresar CUIL o CUIT:\n";
    legal_id = _terminal.validateLongInt(1);
    client.setLegalId(legal_id);
}

void ClientManager::getUserInputForAdress(Client & client) {
    Adress adress;

    std::string country;
    std::string state;
    std::string city;
    std::string street;
    int number;
    int floor;
    char letter;

    std::cout << "Ingresar el país del domicilio:\n";
    std::cin.ignore();
    getline(std::cin, country);

    std::cout << "Ingresar la provincia del domicilio:\n";
    getline(std::cin, state);

    std::cout << "Ingresar la ciudad del domicilio:\n";
    getline(std::cin, city);

    std::cout << "Ingresar la calle del domicilio:\n";
    getline(std::cin, street);

    std::cout << "Ingresar el número de domicilio:\n";
    number = _terminal.validateInt(0);

    std::cout << "Ingresar el piso:\n";
    floor = _terminal.validateInt(0);

    std::cout << "Ingresar el departamento o lote:\n";
    letter = _terminal.validateChar();

    adress.setCountry(country);
    adress.setState(state);
    adress.setCity(city);
    adress.setStreet(street);
    adress.setNumber(number);
    adress.setFloor(floor);
    adress.setLetter(letter);

    client.setAdress(adress);
}

void ClientManager::getUserInputForPhone(Client & client) {
    int phone;
    std::cout << "Ingresar teléfono o celular:\n";
    phone = _terminal.validateInt(0);
    client.setPhone(phone);
}

void ClientManager::getUserInputForEmail(Client & client) {
    std::string email;
    std::cout << "Ingresar e-mail:\n";
    std::cin.ignore();
    getline(std::cin, email);
    client.setEmail(email);
}

void ClientManager::getUserInputForIsActive(Client & client) {
    if (client.getIsActive()) {
        client.setIsActive(false);
        std::cout << "El cliente ha sido dado de baja.\n";
        _terminal.pause();
    } else {
        client.setIsActive(true);
        std::cout << "El cliente ha sido reincorporado.\n";
        _terminal.pause();
    }
}

int ClientManager::generateId() {
    int id;

    if (_client.getId() != 0) {
        id = _client_archive.getAmountOfRegisters() + 1;
    } else {
        id = 1;
    }

    return id;
}