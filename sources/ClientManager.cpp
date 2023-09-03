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
                addClient();
                break;
            case 2:
                //editClient();
                break;
            case 3:
                //searchClient();
                break;
            case 4:
                listClients();
                break;
        }
    } while (selection != 0);
    
    _terminal.clear();
}

bool ClientManager::addClient() {
    _terminal.clear();

    int id;

    std::cout << "Ingresar id:\n";
    std::cin >> id;

    std::string description;

    std::cout << "Ingresar descripción:\n";
    std::cin.ignore();
    getline(std::cin, description);
    
    long long int legal_id;

    std::cout << "Ingresar CUIL o CUIT:\n";
    std::cin >> legal_id;

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

    int phone;

    std::cout << "Ingresar teléfono o celular:\n";
    std::cin >> phone;

    std::string email;

    std::cout << "Ingresar e-mail:\n";
    std::cin.ignore();
    getline(std::cin, email);

    _client.setId(id);
    _client.setDescription(description);
    _client.setLegalId(legal_id);
    _client.setAdress(adress);
    _client.setPhone(phone);
    _client.setEmail(email);

    bool successful_write = _client_archive.write(_client);

    _terminal.clear();

    return successful_write;
}

//bool ClientManager::editClient() {}

//Client ClientManager::searchClient() {}

void ClientManager::listClients() {
    _terminal.clear();

    int amount_of_clients = _client_archive.getAmountOfRegisters();

    std::cout << "------------------------------\n";
    std::cout << "     LISTADO DE CLIENTES      \n";
    std::cout << "------------------------------\n";

    for (int i = 0; i < amount_of_clients; i ++) {
        _client = _client_archive.read(i);
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
        std::cout << "------------------------------\n";
    }

    _terminal.pause();
    _terminal.clear();
}