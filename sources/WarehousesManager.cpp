#include "../headers/WarehousesManager.h"

WarehousesManager::WarehousesManager()
{
    _warehouses_archive.setPath("registers/warehouse.dat");
}
void WarehousesManager::displayMenu()
{
    int selection = 1;

    do {
        _terminal.clear();
        _terminal.displayMenuHeader("DEPOSITOS");
        std::cout << "(1) AGREGAR NUEVO\n";
        std::cout << "(2) EDITAR DEPOSITO\n";
        std::cout << "(3) BUSCAR DEPOSITO\n";
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
                addWarehouse();
                break;

            case 2:
                editWarehouse();
                break;

            case 3:
                searchWarehouse();
                break;

            case 4:
                listWarehouse();
                break;

            case 5:
                break;

            case 6:
                break;

            case 7:
                break;

            case 8:
                break;
        }
    } while (selection != 0);
}

bool WarehousesManager::addWarehouse()
{
    bool successful_write;
    bool user_wants_to_save;

    _terminal.clear();
    _terminal.displayMenuHeader("AGREGAR DEPOSITO");

    _warehouse.setId(generateWarehouseId());

    cinWarehouseName(_warehouse);
    cinWarehouseAdress(_warehouse);
    cinWarehousePath(_warehouse);
    
    std::cout << "¿Desea guardar un nuevo registro con los datos ingresados? [S/N]\n";
    user_wants_to_save = _terminal.validateBool();

    if(user_wants_to_save == true)
    {
        successful_write = _warehouses_archive.write(_warehouse);
        if(successful_write == true)
        {
            std::cout << "Registro guardado correctamente.\n";
        }else 
        {
            std::cout << "Error de escritura.\n";
        }
    } else
    {
        successful_write = false;
        std::cout << "Registro descartado por usuario.\n";
    }

    _terminal.pause();
    _terminal.clear();

    return successful_write;
}

bool WarehousesManager::editWarehouse()
{
     _terminal.clear();

    searchWarehouse();

    if (_warehouse.getId() == -1) {
        return false;
    }

    int selection = 1;

    do {
        _terminal.clear();
        _terminal.displayMenuHeader("EDITAR CLIENTE");
        _terminal.centerAndPrint(_warehouse.getName());
        std::cout << "\n";
        std::cout << "(1) EDITAR NOMBRE\n";
        std::cout << "(2) EDITAR DOMICILIO\n";
        _terminal.displayMenuFooter();

        selection = _terminal.validateInt(0, 7);

        switch (selection) {
            case 1:
                cinWarehouseName(_warehouse);
                cinWarehousePath(_warehouse);
                break;
            case 2:
                cinWarehouseAdress(_warehouse);
                break;
        }
    } while (selection != 0);

    int index = _warehouses_archive.getIndex(_warehouse.getId());
    bool successful_write = _warehouses_archive.overWrite(_warehouse, index);

    return successful_write;
}

void WarehousesManager::searchWarehouse()
{
        _terminal.clear();

    int selection = 1;

    _terminal.displayMenuHeader("BUSCAR DEPOSITO");
    std::cout << "(1) BUSCAR POR ID\n";
    std::cout << "(2) BUSCAR POR NOMBRE\n";
    _terminal.displayMenuFooter();

    selection = _terminal.validateInt(0, 2);

    switch (selection) {
        case 0:
            _terminal.clear();
            break;
        case 1:
            searchWarehouseById();
            break;
        case 2:
            searchWarehouseByName();
            break;
    }

}

void WarehousesManager::listWarehouse()
{
     _terminal.clear();

    int amount_of_clients = _warehouses_archive.getAmountOfRegisters();

    _terminal.displayMenuHeader("LISTADO DE CLIENTES");

    for (int i = 0; i < amount_of_clients; i ++) {
        printWarehouse(i);
    }

    _terminal.pause();
    _terminal.clear();
}

void WarehousesManager::printWarehouse(int index)
{
    _warehouse = _warehouses_archive.read(index);
    _terminal.displayMenuHeader(_warehouse.getName());

    std::cout << "# ID: " << _warehouse.getId() << "\n";
    std::cout << "País: " << _warehouse.getAdress().getCountry() << "\n";
    std::cout << "Provincia: " << _warehouse.getAdress().getState() << "\n";
    std::cout << "Ciduad: " << _warehouse.getAdress().getCity() << "\n";
    std::cout << "Calle: " << _warehouse.getAdress().getStreet() << "\n";
    std::cout << "Número: " <<_warehouse.getAdress().getNumber() << "\n";
    std::cout << "Piso: " << _warehouse.getAdress().getFloor() << "\n";
    std::cout << "Departamento: " << _warehouse.getAdress().getLetter() << "\n";
    std::cout << "# PATH: " << _warehouse.getPath() << "\n";
    _terminal.printBool(_warehouse.getIsActive(), "Estado: Activo\n\n", "Estado: Dado de baja\n\n");
}

int WarehousesManager::generateWarehouseId()
{
    int id = 1;

    if(_warehouses_archive.getAmountOfRegisters() != 0)
    {
        id = _warehouses_archive.getAmountOfRegisters() + 1;
    }

    return id;
}

void WarehousesManager::cinWarehouseName(Warehouse & warehouse)
{
    std::string name;
    
    std::cout << "Ingrese nombre del deposito:\n";
    std::cin.ignore();
    getline(std::cin, name);

    warehouse.setName(name);
}

void WarehousesManager::cinWarehouseAdress(Warehouse & warehouse)
{
     Adress adress;

    std::string country;
    std::string state;
    std::string city;
    std::string street;
    int number;
    int floor;
    char letter;

    std::cout << "Ingresar el país del domicilio:\n";
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

    warehouse.setAdress(adress);
}

void WarehousesManager::cinWarehousePath(Warehouse & warehouse)
{
    std::string path;

    path = "registers/deposito-" + warehouse.getName() + ".dat";

    warehouse.setPath(path);
}

void WarehousesManager::cinWarehouseIsActive(Warehouse &warehouse)
{
    if (warehouse.getIsActive()) {
        warehouse.setIsActive(false);
        std::cout << "El cliente ha sido dado de baja.\n";
        _terminal.pause();
    } else {
        warehouse.setIsActive(true);
        std::cout << "El cliente ha sido reincorporado.\n";
        _terminal.pause();
    }
}

void WarehousesManager::searchWarehouseById()
{
    int index;
    int id;
    int max_id;

    max_id = _warehouses_archive.getAmountOfRegisters();

    std::cout << "Ingresar ID o 0 para cancelar:\n";
    id = _terminal.validateInt(0, max_id);

    if(0 < id)
    {
        index = _warehouses_archive.getIndex(id);
        printWarehouse(index);
    }else 
    {
        _warehouse.setId(-1);
        std::cout << "Búsqueda abordata por el usuario.\n";
    }

    _terminal.pause();
}

void WarehousesManager::searchWarehouseByName()
{
    int index;
    std::string name;

    std::cout << "Ingresar nombre:\n";
    std::cin.ignore();
    getline(std::cin, name);

    index = _warehouses_archive.getIndex(name);

    while (index == -1) {
        std::cout << "No se encontró el registro " << name << ". Ingrese el nombre nuevamente o ingrese 0 para cancelar.\n";
        getline(std::cin, name);

        if (name == "0") {
            index = -2;
        } else {
            index = _warehouses_archive.getIndex(name); // Esta función retorna -1 si no encuentra un registro válido
        }
    }

    if (0 <= index) {
        printWarehouse(index);
    } else {
        _warehouse.setId(-1);
        std::cout << "Búsqueda abortada por el usuario.\n";
    }

    _terminal.pause();
}

void WarehousesManager::exportWarehouseBackup()
{
    int amount_of_warehouse = _warehouses_archive.getAmountOfRegisters();

    Warehouse * warehouse_array = new Warehouse[amount_of_warehouse];

    if (warehouse_array == NULL) {
        std::cout << "Error de memoria RAM: No se pudo asignar la memoria requerida al exportar backup.";
    } else {
        for (int i = 0; i < amount_of_warehouse; i ++) {
            warehouse_array[i] = _warehouses_archive.read(i);
        }

        _warehouses_backup.createEmptyClientsArchive();

        for (int i = 0; i < amount_of_warehouse; i ++) {
            _warehouses_backup.write(warehouse_array[i]);
        }

        delete [] warehouse_array;

        std::cout << "Backup exportado correctamente.\n";
        _terminal.pause();
    }
}

void WarehousesManager::importWarehouseBackup()
{
    std::cout << "¿Desea reemplazar los clientes actuales por aquellos que haya en el archivo de respaldo? [S/N]\n";

    if (_terminal.validateBool() == false) {
        std::cout << "Importación abortada por el usuario.\n";
    } else {
        int amount_of_clients = _warehouses_backup.getAmountOfRegisters();

        Warehouse * warehouse_array = new Warehouse[amount_of_clients];

        if (warehouse_array == NULL) {
            std::cout << "Error de memoria RAM: No se pudo asignar la memoria requerida al importar backup.";
        } else {
            for (int i = 0; i < amount_of_clients; i ++) {
                warehouse_array[i] = _warehouses_backup.read(i);
            }

            _warehouses_archive.createEmptyClientsArchive();

            for (int i = 0; i < amount_of_clients; i ++) {
                _warehouses_archive.write(warehouse_array[i]);
            }

            delete [] warehouse_array;
            std::cout << "Backup importado correctamente.\n";
            _terminal.pause();
        }
    }
}

std::string WarehousesManager::getItemsPath() {
    return _warehouse.getPath();
}

void WarehousesManager::setItemsPath(std::string path) {
    _warehouse.setPath(path);
}