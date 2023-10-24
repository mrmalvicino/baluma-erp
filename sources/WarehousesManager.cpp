#include "../headers/WarehousesManager.h"

WarehousesManager::WarehousesManager() {
    _warehouses_backup.setPath("registers/warehouses.bkp");
}

int WarehousesManager::getAmountOfWarehouses(){
    _amount_of_warehouses = _warehouses_archive.getAmountOfRegisters();
    return _amount_of_warehouses;
}

void WarehousesManager::setWarehouse(int index) {
    _warehouse = _warehouses_archive.read(index);
}

Warehouse WarehousesManager::getWarehouse() {
    return _warehouse;
}

void WarehousesManager::displayMenu() {
    int selection = 1;

    do {
        _terminal.clear();
        _terminal.displayMenuHeader("DEPÓSITOS");
        std::cout << "(1) AGREGAR DEPÓSITO\n";
        std::cout << "(2) EDITAR DEPÓSITO\n";
        std::cout << "(3) BUSCAR DEPÓSITO\n";
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
                listWarehousesMenu();
                break;
            case 5:
                exportWarehousesBackup();
                break;
            case 6:
                importWarehousesBackup();
                break;
            case 7:
                exportWarehousesCSV();
                break;
            case 8:
                importWarehousesCSV();
                break;
        }
    } while (selection != 0);
}

bool WarehousesManager::addWarehouse() {
    bool successful_write;
    bool user_wants_to_save;

    _terminal.clear();
    _terminal.displayMenuHeader("AGREGAR DEPÓSITO");

    _warehouse.setId(generateWarehouseId());

    cinWarehouseName(_warehouse);
    cinWarehouseAdress(_warehouse);

    std::cout << "¿Desea guardar un nuevo registro con los datos ingresados? [S/N]\n";
    user_wants_to_save = _terminal.validateBool();

    if (user_wants_to_save == true) {
        successful_write = _warehouses_archive.write(_warehouse);

        if(successful_write == true) {
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

bool WarehousesManager::editWarehouse() {
     _terminal.clear();

    bool successful_write = false;
    int search_rtn = searchWarehouse();

    if (search_rtn == -1) {
        return successful_write;
    }

    int selection = 1;

    do {
        _terminal.clear();
        _terminal.displayMenuHeader("EDITAR DEPÓSITO");
        _terminal.centerAndPrint(_warehouse.getName());
        std::cout << "\n";
        std::cout << "(1) EDITAR NOMBRE\n";
        std::cout << "(2) EDITAR DOMICILIO\n";
        std::cout << "(3) DAR DE BAJA O REINCORPORAR\n";
        _terminal.displayMenuFooter();

        selection = _terminal.validateInt(0, 3);

        switch (selection) {
            case 1:
                cinWarehouseName(_warehouse);
                break;
            case 2:
                std::cin.ignore();
                cinWarehouseAdress(_warehouse);
                break;
            case 3:
                cinWarehouseIsActive(_warehouse);
                break;
        }
    } while (selection != 0);

    int index = _warehouses_archive.getIndex(_warehouse.getId());
    successful_write = _warehouses_archive.overWrite(_warehouse, index);

    return successful_write;
}

int WarehousesManager::searchWarehouse() {
    _terminal.clear();

    int search_rtn = 0;
    int selection = 1;

    _terminal.displayMenuHeader("BUSCAR DEPÓSITO");
    std::cout << "(1) BUSCAR POR ID\n";
    std::cout << "(2) BUSCAR POR NOMBRE\n";
    _terminal.displayMenuFooter();

    selection = _terminal.validateInt(0, 2);

    switch (selection) {
        case 0:
            search_rtn = -1;
            _terminal.clear();
            break;
        case 1:
            search_rtn = searchWarehouseById();
            break;
        case 2:
            search_rtn = searchWarehouseByName();
            break;
    }

    return search_rtn;
}

int WarehousesManager::searchWarehouseById() {
    int search_rtn = 0;
    int index;
    int id;
    int max_id;

    max_id = getAmountOfWarehouses();

    std::cout << "Ingresar ID o 0 para cancelar:\n";
    id = _terminal.validateInt(0, max_id);

    if (0 < id) {
        index = _warehouses_archive.getIndex(id);
        loadWarehouse(index);
        printWarehouse();
    } else {
        search_rtn = -1;
        std::cout << "Búsqueda abordata por el usuario.\n";
    }

    _terminal.pause();

    return search_rtn;
}

int WarehousesManager::searchWarehouseByName() {
    int search_rtn = 0;
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
        loadWarehouse(index);
        printWarehouse();
    } else {
        search_rtn = -1;
        std::cout << "Búsqueda abortada por el usuario.\n";
    }

    _terminal.pause();

    return search_rtn;
}

void WarehousesManager::listWarehousesMenu() {
    _terminal.clear();

    int selection = 1;

    _terminal.displayMenuHeader("LISTAR DEPÓSITOS");
    std::cout << "(1) LISTAR TODOS LOS REGISTROS\n";
    std::cout << "(2) LISTAR SOLO ACTIVOS\n";
    std::cout << "(3) LISTAR SOLO DADOS DE BAJA\n";
    _terminal.displayMenuFooter();

    selection = _terminal.validateInt(0, 3);

    switch (selection) {
        case 0:
            _terminal.clear();
            break;
        case 1:
            listWarehouses(true, true);
            break;
        case 2:
            listWarehouses(true, false);
            break;
        case 3:
            listWarehouses(false, true);
            break;
    }
}

void WarehousesManager::listWarehouses(bool list_actives, bool list_inactives) {
     _terminal.clear();

    _terminal.displayMenuHeader("LISTADO DE DEPÓSITOS");

    for (int i = 0; i < getAmountOfWarehouses(); i ++) {
        loadWarehouse(i);

        if ( (_warehouse.getIsActive() == true && list_actives == true) || (_warehouse.getIsActive() == false && list_inactives == true) ) {
            printWarehouse();
        }
    }

    _terminal.pause();
    _terminal.clear();
}

void WarehousesManager::loadWarehouse(int index) {
    _warehouse = _warehouses_archive.read(index);
}

void WarehousesManager::printWarehouse() {
    _terminal.displayMenuHeader(_warehouse.getName());

    std::cout << "# ID: " << _warehouse.getId() << "\n";
    std::cout << "País: " << _warehouse.getAdress().getCountry() << "\n";
    std::cout << "Provincia: " << _warehouse.getAdress().getState() << "\n";
    std::cout << "Ciduad: " << _warehouse.getAdress().getCity() << "\n";
    std::cout << "Calle: " << _warehouse.getAdress().getStreet() << "\n";
    std::cout << "Número: " <<_warehouse.getAdress().getNumber() << "\n";
    std::cout << "Piso: " << _warehouse.getAdress().getFloor() << "\n";
    std::cout << "Departamento: " << _warehouse.getAdress().getLetter() << "\n";
    _terminal.printBool(_warehouse.getIsActive(), "Estado: Activo\n\n", "Estado: Dado de baja\n\n");
}

void WarehousesManager::cinWarehouseName(Warehouse & warehouse) {
    std::string name;
    
    std::cout << "Ingrese nombre del depósito:\n";
    std::cin.ignore();
    getline(std::cin, name);

    warehouse.setName(name);
}

void WarehousesManager::cinWarehouseAdress(Warehouse & warehouse) {
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

void WarehousesManager::cinWarehouseIsActive(Warehouse & warehouse) {
    if (warehouse.getIsActive()) {
        warehouse.setIsActive(false);
        std::cout << "El depósito ha sido dado de baja.\n";
        _terminal.pause();
    } else {
        warehouse.setIsActive(true);
        std::cout << "El depósito ha sido reincorporado.\n";
        _terminal.pause();
    }
}

int WarehousesManager::generateWarehouseId() {
    int id = 1;

    if (getAmountOfWarehouses() != 0) {
        id = getAmountOfWarehouses() + 1;
    }

    return id;
}

void WarehousesManager::exportWarehousesBackup() {
    Warehouse * warehouse_array = new Warehouse[getAmountOfWarehouses()];

    if (warehouse_array == NULL) {
        std::cout << "Error de memoria RAM: No se pudo asignar la memoria requerida al exportar backup.";
    } else {
        for (int i = 0; i < _amount_of_warehouses; i ++) {
            warehouse_array[i] = _warehouses_archive.read(i);
        }

        _warehouses_backup.createEmptyArchive();

        for (int i = 0; i < _amount_of_warehouses; i ++) {
            _warehouses_backup.write(warehouse_array[i]);
        }

        delete [] warehouse_array;

        std::cout << "Backup exportado correctamente.\n";
        _terminal.pause();
    }
}

void WarehousesManager::importWarehousesBackup() {
    std::cout << "¿Desea reemplazar los depósitos actuales por aquellos que haya en el archivo de respaldo? [S/N]\n";

    if (_terminal.validateBool() == false) {
        std::cout << "Importación abortada por el usuario.\n";
    } else {
        Warehouse * warehouse_array = new Warehouse[getAmountOfWarehouses()];

        if (warehouse_array == NULL) {
            std::cout << "Error de memoria RAM: No se pudo asignar la memoria requerida al importar backup.";
        } else {
            for (int i = 0; i < _amount_of_warehouses; i ++) {
                warehouse_array[i] = _warehouses_backup.read(i);
            }

            _warehouses_archive.createEmptyArchive();

            for (int i = 0; i < _amount_of_warehouses; i ++) {
                _warehouses_archive.write(warehouse_array[i]);
            }

            delete [] warehouse_array;
            std::cout << "Backup importado correctamente.\n";
            _terminal.pause();
        }
    }
}

void WarehousesManager::exportWarehousesCSV() {
    _warehouses_csv.writeWarehousesCSV(_warehouse, _warehouses_archive);
}

void WarehousesManager::importWarehousesCSV() {
    std::cout << "¿Desea reemplazar los warehousees actuales por aquellos que haya en el archivo CSV? [S/N]\n";

    if (_terminal.validateBool() == false) {
        std::cout << "Importación abortada por el usuario.\n";
    } else {
        _warehouses_csv.readWarehousesCSV(_warehouse, _warehouses_archive);
    }
}