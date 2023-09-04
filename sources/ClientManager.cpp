#include "../headers/ClientManager.h"

void ClientManager::displayMenu() {
    int selection = 1;

    do {
        _terminal.clear();
        _terminal.displayMenuHeader("CLIENTES");
        std::cout << "(1) AGREGAR NUEVO\n";
        std::cout << "(2) EDITAR EXISTENTE\n";
        std::cout << "(3) BORRAR CLIENTE\n";
        std::cout << "(4) BUSCAR CLIENTE\n";
        std::cout << "(5) VER LISTADO\n";
        _terminal.displayMenuFooter();

        std::cin >> selection;

        switch (selection) {
            case 1:
                addClient();
                break;

            case 2:
                editClient();
                break;

            case 3:
                deleteClient();
                break;

            case 4:
                searchClient();
                break;

            case 5:
                listClients();
                break;
        }
    } while (selection != 0);
}

bool ClientManager::addClient() {
    _terminal.clear();
    _terminal.displayMenuHeader("AGREGAR CLIENTE");

    int id;
    std::cout << "Ingresar id:\n";
    std::cin >> id;
    _client.setId(id); // asignar id automatico todo

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
        std::cout << "(1) EDITAR NOMBRE\n";
        std::cout << "(2) EDITAR CUIL/CUIT\n";
        std::cout << "(3) EDITAR DOMICILIO\n";
        std::cout << "(4) EDITAR TELÉFONO\n";
        std::cout << "(5) EDITAR E-MAIL\n";
        _terminal.displayMenuFooter();

        std::cin >> selection;

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
        }
    } while (selection != 0);

    int index = _client_archive.getIndex(_client.getId());
    bool successful_write = _client_archive.overWrite(_client, index);

    return successful_write;
}

void ClientManager::deleteClient() {
    //todo
}

void ClientManager::searchClient() {
    _terminal.clear();

    int selection = 1;

    _terminal.displayMenuHeader("BUSCAR CLIENTE");
    std::cout << "(1) BUSCAR POR ID\n";
    std::cout << "(2) BUSCAR POR NOMBRE\n";
    _terminal.displayMenuFooter();

    std::cin >> selection;
    int index;

    switch (selection) {
        case 0:
            _terminal.clear();
            break;

        case 1:
            int id;

            std::cout << "Ingresar ID:\n";
            std::cin >> id;

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
        _terminal.printLine();
    }

    _terminal.pause();
    _terminal.clear();
}

void ClientManager::printClient(int index) {
    _client = _client_archive.read(index);
    std::cout << "ID: " << _client.getId() << "\n";
    std::cout << "Cliente: " << _client.getDescription() << "\n";
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
    std::cout << "Activo: " << _client.getStatus() << "\n";
}

void ClientManager::getUserInputForDescription(Client & client) {
    std::string description;
    std::cout << "Ingresar nombre de la organización o del cliente:\n";
    std::cin.ignore();
    getline(std::cin, description);
    client.setDescription(description);
}

void ClientManager::getUserInputForLegalId(Client & client) {
    long long int legal_id;
    std::cout << "Ingresar CUIL o CUIT:\n";
    std::cin >> legal_id;
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
    std::cin >> number;

    std::cout << "Ingresar el piso:\n";
    std::cin >> floor;

    std::cout << "Ingresar el departamento o lote:\n";
    std::cin >> letter;

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
    std::cin >> phone;
    client.setPhone(phone);
}

void ClientManager::getUserInputForEmail(Client & client) {
    std::string email;
    std::cout << "Ingresar e-mail:\n";
    std::cin.ignore();
    getline(std::cin, email);
    client.setEmail(email);
}