#include "../headers/ClientsManager.h"

ClientsManager::ClientsManager() {
    _clients_backup.setPath("registers/clients.bkp");
}

void ClientsManager::displayMenu() {
    int selection = 1;

    do {
        _terminal.clear();
        _terminal.displayMenuHeader("CLIENTES");
        std::cout << "(1) AGREGAR NUEVO\n";
        std::cout << "(2) EDITAR CLIENTE\n";
        std::cout << "(3) BUSCAR CLIENTE\n";
        std::cout << "(4) VER LISTADO\n";
        _terminal.printLine();
        std::cout << "(5) EXPORTAR BACKUP\n";
        std::cout << "(6) IMPORTAR BACKUP\n";
        std::cout << "(7) EXPORTAR CSV\n";
        std::cout << "(8) IMPORTAR CSV\n";
        _terminal.displayMenuFooter();

        selection = _terminal.validateInt(0, 8);

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

            case 5:
                exportClientsBackup();
                break;

            case 6:
                importClientsBackup();
                break;

            case 7:
                exportClientsCSV();
                break;

            case 8:
                importClientsCSV();
                break;
        }
    } while (selection != 0);
}

bool ClientsManager::addClient() {
    bool successful_write;
    bool user_wants_to_save;

    _terminal.clear();
    _terminal.displayMenuHeader("AGREGAR CLIENTE");

    _client.setId(generateClientId());

    cinClientDescription(_client);
    cinClientLegalId(_client);
    cinClientAdress(_client);
    cinClientPhone(_client);
    cinClientEmail(_client);
    cinClientCategory(_client);

    std::cout << "¿Desea guardar un nuevo registro con los datos ingresados? [S/N]\n";
    user_wants_to_save = _terminal.validateBool();

    if (user_wants_to_save == true) {
        successful_write = _clients_archive.write(_client);
        if (successful_write == true) {
            std::cout << "Registro guardado correctamente.\n";
        } else {
            std::cout << "Error de escritura.\n";
        }
    } else {
        successful_write = false;
        std::cout << "Registro descartado por usuario.\n";
    }

    _terminal.pause();
    _terminal.clear();

    return successful_write;
}

bool ClientsManager::editClient() {
    _terminal.clear();

    searchClient();

    if (_client.getId() == -1) {
        return false;
    }

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
        std::cout << "(6) EDITAR CATEGORÍA\n";
        std::cout << "(7) DAR DE BAJA O REINCORPORAR\n";
        _terminal.displayMenuFooter();

        selection = _terminal.validateInt(0, 7);

        switch (selection) {
            case 1:
                cinClientDescription(_client);
                break;
            case 2:
                cinClientLegalId(_client);
                break;
            case 3:
                cinClientAdress(_client);
                break;
            case 4:
                cinClientPhone(_client);
                break;
            case 5:
                cinClientEmail(_client);
                break;
            case 6:
                cinClientCategory(_client);
                break;
            case 7:
                cinClientIsActive(_client);
                break;
        }
    } while (selection != 0);

    int index = _clients_archive.getIndex(_client.getId());
    bool successful_write = _clients_archive.overWrite(_client, index);

    return successful_write;
}

void ClientsManager::searchClient() {
    _terminal.clear();

    int selection = 1;

    _terminal.displayMenuHeader("BUSCAR CLIENTE");
    std::cout << "(1) BUSCAR POR ID\n";
    std::cout << "(2) BUSCAR POR NOMBRE\n";
    _terminal.displayMenuFooter();

    selection = _terminal.validateInt(0, 2);

    switch (selection) {
        case 0:
            _terminal.clear();
            break;
        case 1:
            searchClientById();
            break;
        case 2:
            searchClientByDescription();
            break;
    }
}

void ClientsManager::listClients() {
    _terminal.clear();

    int amount_of_clients = _clients_archive.getAmountOfRegisters();

    _terminal.displayMenuHeader("LISTADO DE CLIENTES");

    for (int i = 0; i < amount_of_clients; i ++) {
        printClient(i);
    }

    _terminal.pause();
    _terminal.clear();
}

void ClientsManager::printClient(int index) {
    _client = _clients_archive.read(index);
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

void ClientsManager::cinClientDescription(Client & client) {
    std::string description;
    std::cout << "Ingresar nombre del cliente:\n";
    std::cin.ignore();
    getline(std::cin, description);
    client.setDescription(description);
}

void ClientsManager::cinClientLegalId(Client & client) {
    long long int legal_id;
    std::cout << "Ingresar CUIL o CUIT:\n";
    legal_id = _terminal.validateLongInt(1);
    client.setLegalId(legal_id);
}

void ClientsManager::cinClientAdress(Client & client) {
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

    std::cout << "Ingresar el departamento:\n";
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

void ClientsManager::cinClientPhone(Client & client) {
    int phone;
    std::cout << "Ingresar teléfono o celular:\n";
    phone = _terminal.validateInt(0);
    client.setPhone(phone);
}

void ClientsManager::cinClientEmail(Client & client) {
    std::string email;
    std::cout << "Ingresar e-mail:\n";
    std::cin.ignore();
    getline(std::cin, email);
    client.setEmail(email);
}

void ClientsManager::cinClientIsActive(Client & client) {
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

void ClientsManager::cinClientCategory(Client & client) {
    char category;
    std::cout << "Ingresar categoría:\n";
    category = _terminal.validateChar();
    client.setCategory(category);
}

int ClientsManager::generateClientId() {
    int id = 1;

    if(_clients_archive.getAmountOfRegisters() != 0) {
        id = _clients_archive.getAmountOfRegisters() + 1;
    }

    return id;
}

void ClientsManager::searchClientById() {
    int index;
    int id;
    int max_id;

    max_id = _clients_archive.getAmountOfRegisters();

    std::cout << "Ingresar ID o 0 para cancelar:\n";
    id = _terminal.validateInt(0, max_id);

    if (0 < id) {
        index = _clients_archive.getIndex(id);
        printClient(index);
    } else {
        _client.setId(-1);
        std::cout << "Búsqueda abortada por el usuario.\n";
    }

    _terminal.pause();
}

void ClientsManager::searchClientByDescription() {
    int index;
    std::string description;

    std::cout << "Ingresar nombre:\n";
    std::cin.ignore();
    getline(std::cin, description);

    index = _clients_archive.getIndex(description);

    while (index == -1) {
        std::cout << "No se encontró el registro " << description << ". Ingrese el nombre nuevamente o ingrese 0 para cancelar.\n";
        getline(std::cin, description);

        if (description == "0") {
            index = -2;
        } else {
            index = _clients_archive.getIndex(description); // Esta función retorna -1 si no encuentra un registro válido
        }
    }

    if (0 <= index) {
        printClient(index);
    } else {
        _client.setId(-1);
        std::cout << "Búsqueda abortada por el usuario.\n";
    }

    _terminal.pause();
}

void ClientsManager::exportClientsBackup() {
    int amount_of_clients = _clients_archive.getAmountOfRegisters();

    Client * clients_array = new Client[amount_of_clients];

    if (clients_array == NULL) {
        std::cout << "Error de memoria RAM: No se pudo asignar la memoria requerida al exportar backup.";
    } else {
        for (int i = 0; i < amount_of_clients; i ++) {
            clients_array[i] = _clients_archive.read(i);
        }

        _clients_backup.createEmptyArchive();

        for (int i = 0; i < amount_of_clients; i ++) {
            _clients_backup.write(clients_array[i]);
        }

        delete [] clients_array;

        std::cout << "Backup exportado correctamente.\n";
        _terminal.pause();
    }
}

void ClientsManager::importClientsBackup() {
    std::cout << "¿Desea reemplazar los clientes actuales por aquellos que haya en el archivo de respaldo? [S/N]\n";

    if (_terminal.validateBool() == false) {
        std::cout << "Importación abortada por el usuario.\n";
    } else {
        int amount_of_clients = _clients_backup.getAmountOfRegisters();

        Client * clients_array = new Client[amount_of_clients];

        if (clients_array == NULL) {
            std::cout << "Error de memoria RAM: No se pudo asignar la memoria requerida al importar backup.";
        } else {
            for (int i = 0; i < amount_of_clients; i ++) {
                clients_array[i] = _clients_backup.read(i);
            }

            _clients_archive.createEmptyArchive();

            for (int i = 0; i < amount_of_clients; i ++) {
                _clients_archive.write(clients_array[i]);
            }

            delete [] clients_array;
            std::cout << "Backup importado correctamente.\n";
            _terminal.pause();
        }
    }
}

void ClientsManager::exportClientsCSV() {
    _clients_csv.writeClientsCSV(_client, _clients_archive);
}
 
void ClientsManager::importClientsCSV() {
    std::cout << "¿Desea reemplazar los clientes actuales por aquellos que haya en el archivo CSV? [S/N]\n";

    if (_terminal.validateBool() == false) {
        std::cout << "Importación abortada por el usuario.\n";
    } else {
        _clients_csv.readClientsCSV(_client, _clients_archive);
    }
}