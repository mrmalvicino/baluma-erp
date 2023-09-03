#include "../headers/ClientManager.h"

void ClientManager::openClientMenu() {
    int selection = 1;

    do {
        std::cout << "--------------------------\n";
        std::cout << "         CLIENTES         \n";
        std::cout << "--------------------------\n";
        std::cout << "(1) AGREGAR NUEVO\n";
        std::cout << "(2) EDITAR EXISTENTE\n";
        std::cout << "(3) BUSCAR POR ID\n";
        std::cout << "(4) VER LISTADO\n";
        std::cout << "--------------------------\n";
        std::cout << "(0) SALIR\n";

        std::cin >> selection;

        switch (selection) {
            case 1:
                _terminal.clear();
                addClient();
                break;
            case 2:
                //editClient();
                break;
            case 3:
                //searchClient();
                break;
            case 4:
                _terminal.clear();
                listClients();
                break;
        }
    } while (selection != 0);
    
    _terminal.clear();
}

bool ClientManager::addClient() {
    int id;

    std::cout << "Ingresar id:\n";
    std::cin >> id;

    std::string description;

    std::cout << "Ingresar descripción:\n";
    std::cin.ignore();
    getline(std::cin, description);
    
    int legalId;

    std::cout << "Ingresar CUIL o CUIT:\n";
    std::cin >> legalId;

    Adress adress;

    // pedir los datos para los setters

    int phone;

    std::cout << "Ingresar teléfono o celular:\n";
    std::cin >> phone;

    std::string email;

    std::cout << "Ingresar e-mail:\n";
    std::cin.ignore();
    getline(std::cin, email);

    _client.setId(id);
    _client.setDescription(description);
    _client.setLegalId(legalId);
    _client.setAdress(adress);
    _client.setPhone(phone);
    _client.setEmail(email);

    _client_archive.write(_client);
}

//bool ClientManager::editClient() {}

//Client ClientManager::searchClient() {}

void ClientManager::listClients() {
    int amount_of_clients = _client_archive.getAmountOfRegisters();

    for (int i = 0; i < amount_of_clients; i ++) {
        _client = _client_archive.read(i);
        std::cout << _client.getId() << "\t" << _client.getDescription() << "\n"; // agregar el resto de los datos
    }
}