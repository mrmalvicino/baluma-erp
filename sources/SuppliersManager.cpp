#include "../headers/SuppliersManager.h"

SuppliersManager::SuppliersManager() {
    _suppliers_backup.setPath("registers/suppliers.bkp");
}

void SuppliersManager::displayMenu() {
    int selection = 1;

    do {
        _terminal.clear();
        _terminal.displayMenuHeader("PROVEEDORES");
        std::cout << "(1) AGREGAR PROVEEDOR\n";
        std::cout << "(2) EDITAR PROVEEDOR\n";
        std::cout << "(3) BUSCAR PROVEEDOR\n";
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
                addSupplier();
                break;
            case 2:
                editSupplier();
                break;
            case 3:
                searchSupplier();
                break;
            case 4:
                listSuppliersMenu();
                break;
            case 5:
                exportSuppliersBackup();
                break;
            case 6:
                importSuppliersBackup();
                break;
            case 7:
                exportSuppliersCSV();
                break;
            case 8:
                importSuppliersCSV();
                break;
        }
    } while (selection != 0);
}

bool SuppliersManager::addSupplier() {
    bool successful_write;
    bool user_wants_to_save;

    _terminal.clear();
    _terminal.displayMenuHeader("AGREGAR PROVEEDOR");

    _supplier.setId(generateSupplierId());

    cinSupplierDescription(_supplier);
    cinSupplierLegalId(_supplier);
    cinSupplierAdress(_supplier);
    cinSupplierPhone(_supplier);
    cinSupplierEmail(_supplier);
    cinSupplierBankAccount(_supplier);

    std::cout << "¿Desea guardar un nuevo registro con los datos ingresados? [S/N]\n";
    user_wants_to_save = _terminal.validateBool();

    if (user_wants_to_save == true) {
        successful_write = _suppliers_archive.write(_supplier);
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

bool SuppliersManager::editSupplier() {
    _terminal.clear();

    int search_rtn = searchSupplier();

    if (search_rtn == -1) {
        return false;
    }

    int selection = 1;

    do {
        _terminal.clear();
        _terminal.displayMenuHeader("EDITAR PROVEEDOR");
        _terminal.centerAndPrint(_supplier.getDescription());
        std::cout << "\n";
        std::cout << "(1) EDITAR NOMBRE\n";
        std::cout << "(2) EDITAR CUIL/CUIT\n";
        std::cout << "(3) EDITAR DOMICILIO\n";
        std::cout << "(4) EDITAR TELÉFONO\n";
        std::cout << "(5) EDITAR E-MAIL\n";
        std::cout << "(6) EDITAR CUENTA BANCARIA\n";
        std::cout << "(7) DAR DE BAJA O REINCORPORAR\n";
        _terminal.displayMenuFooter();

        selection = _terminal.validateInt(0, 7);

        switch (selection) {
            case 1:
                cinSupplierDescription(_supplier);
                break;
            case 2:
                cinSupplierLegalId(_supplier);
                break;
            case 3:
                cinSupplierAdress(_supplier);
                break;
            case 4:
                cinSupplierPhone(_supplier);
                break;
            case 5:
                cinSupplierEmail(_supplier);
                break;
            case 6:
                cinSupplierBankAccount(_supplier);
                break;
            case 7:
                cinSupplierIsActive(_supplier);
                break;
        }
    } while (selection != 0);

    int index = _suppliers_archive.getIndex(_supplier.getId());
    bool successful_write = _suppliers_archive.overWrite(_supplier, index);

    return successful_write;
}

int SuppliersManager::searchSupplier() {
    _terminal.clear();

    int search_rtn = 0;
    int selection = 1;

    _terminal.displayMenuHeader("BUSCAR PROVEEDOR");
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
            search_rtn = searchSupplierById();
            break;
        case 2:
            search_rtn = searchSupplierByDescription();
            break;
    }

    return search_rtn;
}

int SuppliersManager::searchSupplierById() {
    int search_rtn = 0;
    int index;
    int id;
    int max_id;

    max_id = _suppliers_archive.getAmountOfRegisters();

    std::cout << "Ingresar ID o 0 para cancelar:\n";
    id = _terminal.validateInt(0, max_id);

    if (0 < id) {
        index = _suppliers_archive.getIndex(id);
        loadSupplier(index);
        printSupplier();
    } else {
        search_rtn = -1;
        std::cout << "Búsqueda abortada por el usuario.\n";
    }

    _terminal.pause();

    return search_rtn;
}

int SuppliersManager::searchSupplierByDescription() {
    int search_rtn = 0;
    int index;
    std::string description;

    std::cout << "Ingresar nombre:\n";
    std::cin.ignore();
    getline(std::cin, description);

    index = _suppliers_archive.getIndex(description);

    while (index == -1) {
        std::cout << "No se encontró el registro " << description << ". Ingrese el nombre nuevamente o ingrese 0 para cancelar.\n";
        getline(std::cin, description);

        if (description == "0") {
            index = -2;
        } else {
            index = _suppliers_archive.getIndex(description); // Esta función retorna -1 si no encuentra un registro válido
        }
    }

    if (0 <= index) {
        loadSupplier(index);
        printSupplier();
    } else {
        search_rtn = -1;
        std::cout << "Búsqueda abortada por el usuario.\n";
    }

    _terminal.pause();

    return search_rtn;
}

void SuppliersManager::listSuppliersMenu() {
    _terminal.clear();

    int selection = 1;

    _terminal.displayMenuHeader("LISTAR PROVEEDORES");
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
            listSuppliers(true, true);
            break;
        case 2:
            listSuppliers(true, false);
            break;
        case 3:
            listSuppliers(false, true);
            break;
    }
}

void SuppliersManager::listSuppliers(bool list_actives, bool list_inactives) {
    _terminal.clear();

    int amount_of_suppliers = _suppliers_archive.getAmountOfRegisters();

    _terminal.displayMenuHeader("LISTADO DE PROVEEDORES");

    for (int i = 0; i < amount_of_suppliers; i ++) {
        loadSupplier(i);

        if ( (_supplier.getIsActive() == true && list_actives == true) || (_supplier.getIsActive() == false && list_inactives == true) ) {
            printSupplier();
        }
    }

    _terminal.pause();
    _terminal.clear();
}

void SuppliersManager::loadSupplier(int index) {
    _supplier = _suppliers_archive.read(index);
}

void SuppliersManager::printSupplier() {
    _terminal.displayMenuHeader(_supplier.getDescription());
    std::cout << "# ID: " << _supplier.getId() << "\n";
    std::cout << "CUIL/CUIT: " << _supplier.getLegalId() << "\n";
    std::cout << "País: " << _supplier.getAdress().getCountry() << "\n";
    std::cout << "Provincia: " << _supplier.getAdress().getState() << "\n";
    std::cout << "Ciduad: " << _supplier.getAdress().getCity() << "\n";
    std::cout << "Calle: " << _supplier.getAdress().getStreet() << "\n";
    std::cout << "Número: " << _supplier.getAdress().getNumber() << "\n";
    std::cout << "Piso: " << _supplier.getAdress().getFloor() << "\n";
    std::cout << "Departamento: " << _supplier.getAdress().getLetter() << "\n";
    std::cout << "Teléfono: " << _supplier.getPhone() << "\n";
    std::cout << "E-mail: " << _supplier.getEmail() << "\n";
    std::cout << "Cuenta Bancaria: " << _supplier.getBankAccount() << "\n";
    _terminal.printBool(_supplier.getIsActive(), "Estado: Activo\n\n", "Estado: Dado de baja\n\n");
}

void SuppliersManager::cinSupplierDescription(Supplier & supplier) {
    std::string description;
    std::cout << "Ingresar nombre del proveedor:\n";
    std::cin.ignore();
    getline(std::cin, description);
    supplier.setDescription(description);
}

void SuppliersManager::cinSupplierLegalId(Supplier & supplier) {
    long long int legal_id;
    std::cout << "Ingresar CUIL o CUIT:\n";
    legal_id = _terminal.validateLongInt(1);
    supplier.setLegalId(legal_id);
}

void SuppliersManager::cinSupplierAdress(Supplier & supplier) {
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

    supplier.setAdress(adress);
}

void SuppliersManager::cinSupplierPhone(Supplier & supplier) {
    int phone;
    std::cout << "Ingresar teléfono o celular:\n";
    phone = _terminal.validateInt(0);
    supplier.setPhone(phone);
}

void SuppliersManager::cinSupplierEmail(Supplier & supplier) {
    std::string email;
    std::cout << "Ingresar e-mail:\n";
    std::cin.ignore();
    getline(std::cin, email);
    supplier.setEmail(email);
}

void SuppliersManager::cinSupplierIsActive(Supplier & supplier) {
    if (supplier.getIsActive()) {
        supplier.setIsActive(false);
        std::cout << "El proveedor ha sido dado de baja.\n";
        _terminal.pause();
    } else {
        supplier.setIsActive(true);
        std::cout << "El proveedor ha sido reincorporado.\n";
        _terminal.pause();
    }
}

void SuppliersManager::cinSupplierBankAccount(Supplier & supplier) {
    int bank_account;
    std::cout << "Ingresar cuenta bancaria:\n";
    bank_account = _terminal.validateInt(0);
    supplier.setBankAccount(bank_account);
}

int SuppliersManager::generateSupplierId() {
    int id = 1;

    if(_suppliers_archive.getAmountOfRegisters() != 0) {
        id = _suppliers_archive.getAmountOfRegisters() + 1;
    }

    return id;
}

void SuppliersManager::exportSuppliersBackup() {
    int amount_of_suppliers = _suppliers_archive.getAmountOfRegisters();

    Supplier * suppliers_array = new Supplier[amount_of_suppliers];

    if (suppliers_array == NULL) {
        std::cout << "Error de memoria RAM: No se pudo asignar la memoria requerida al exportar backup.";
    } else {
        for (int i = 0; i < amount_of_suppliers; i ++) {
            suppliers_array[i] = _suppliers_archive.read(i);
        }

        _suppliers_backup.createEmptyArchive();

        for (int i = 0; i < amount_of_suppliers; i ++) {
            _suppliers_backup.write(suppliers_array[i]);
        }

        delete [] suppliers_array;

        std::cout << "Backup exportado correctamente.\n";
        _terminal.pause();
    }
}

void SuppliersManager::importSuppliersBackup() {
    std::cout << "¿Desea reemplazar los supplieres actuales por aquellos que haya en el archivo de respaldo? [S/N]\n";

    if (_terminal.validateBool() == false) {
        std::cout << "Importación abortada por el usuario.\n";
    } else {
        int amount_of_suppliers = _suppliers_backup.getAmountOfRegisters();

        Supplier * suppliers_array = new Supplier[amount_of_suppliers];

        if (suppliers_array == NULL) {
            std::cout << "Error de memoria RAM: No se pudo asignar la memoria requerida al importar backup.";
        } else {
            for (int i = 0; i < amount_of_suppliers; i ++) {
                suppliers_array[i] = _suppliers_backup.read(i);
            }

            _suppliers_archive.createEmptyArchive();

            for (int i = 0; i < amount_of_suppliers; i ++) {
                _suppliers_archive.write(suppliers_array[i]);
            }

            delete [] suppliers_array;
            std::cout << "Backup importado correctamente.\n";
            _terminal.pause();
        }
    }
}

void SuppliersManager::exportSuppliersCSV() {
    _suppliers_csv.writeSuppliersCSV(_supplier, _suppliers_archive);
}
 
void SuppliersManager::importSuppliersCSV() {
    std::cout << "¿Desea reemplazar los supplieres actuales por aquellos que haya en el archivo CSV? [S/N]\n";

    if (_terminal.validateBool() == false) {
        std::cout << "Importación abortada por el usuario.\n";
    } else {
        _suppliers_csv.readSuppliersCSV(_supplier, _suppliers_archive);
    }
}