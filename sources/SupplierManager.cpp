#include "../headers/SupplierManager.h"

void SupplierManager::displayMenu() {
    int selection = 1;

    do {
        _terminal.clear();
        _terminal.displayMenuHeader("PROVEEDORES");
        std::cout << "(1) AGREGAR NUEVO\n";
        std::cout << "(2) EDITAR EXISTENTE\n";
        std::cout << "(3) BUSCAR PROVEEDOR\n";
        std::cout << "(4) VER LISTADO\n";
        _terminal.displayMenuFooter();

        selection = _terminal.validateInt(0, 4);

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
                listSuppliers();
                break;
        }
    } while (selection != 0);
}

bool SupplierManager::addSupplier() {
    _terminal.clear();
    _terminal.displayMenuHeader("AGREGAR PROVEEDOR");

    _supplier.setId(generateSupplierId());

    cinSupplierDescription(_supplier);
    cinSupplierLegalId(_supplier);
    cinSupplierAdress(_supplier);
    cinSupplierPhone(_supplier);
    cinSupplierEmail(_supplier);

    bool successful_write = _supplier_archive.write(_supplier);

    _terminal.pause();
    _terminal.clear();

    return successful_write;
}

bool SupplierManager::editSupplier() {
    _terminal.clear();

    searchSupplier();

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

        selection = _terminal.validateInt(0, 6);

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

    int index = _supplier_archive.getIndex(_supplier.getId());
    bool successful_write = _supplier_archive.overWrite(_supplier, index);

    return successful_write;
}

void SupplierManager::searchSupplier() {
    _terminal.clear();

    int selection = 1;

    _terminal.displayMenuHeader("BUSCAR PROVEEDOR");
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
            max_id = generateSupplierId() - 1;

            std::cout << "Ingresar ID:\n";
            id = _terminal.validateInt(1, max_id);

            index = _supplier_archive.getIndex(id);

            printSupplier(index);

            _terminal.pause();

            break;

        case 2:
            std::string description;

            std::cout << "Ingresar nombre:\n";
            std::cin.ignore();
            getline(std::cin, description);

            index = _supplier_archive.getIndex(description);

            printSupplier(index);

            _terminal.pause();

            break;
    }
}

void SupplierManager::listSuppliers() {
    _terminal.clear();

    int amount_of_suppliers = _supplier_archive.getAmountOfRegisters();

    _terminal.displayMenuHeader("LISTADO DE PROVEEDORES");

    for (int i = 0; i < amount_of_suppliers; i ++) {
        printSupplier(i);
    }

    _terminal.pause();
    _terminal.clear();
}

void SupplierManager::printSupplier(int index) {
    _supplier = _supplier_archive.read(index);
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

void SupplierManager::cinSupplierDescription(Supplier & supplier) {
    std::string description;
    std::cout << "Ingresar nombre del proveedor:\n";
    std::cin.ignore();
    getline(std::cin, description);
    supplier.setDescription(description);
}

void SupplierManager::cinSupplierLegalId(Supplier & supplier) {
    long long int legal_id;
    std::cout << "Ingresar CUIL o CUIT:\n";
    legal_id = _terminal.validateLongInt(1);
    supplier.setLegalId(legal_id);
}

void SupplierManager::cinSupplierAdress(Supplier & supplier) {
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

void SupplierManager::cinSupplierPhone(Supplier & supplier) {
    int phone;
    std::cout << "Ingresar teléfono o celular:\n";
    phone = _terminal.validateInt(0);
    supplier.setPhone(phone);
}

void SupplierManager::cinSupplierEmail(Supplier & supplier) {
    std::string email;
    std::cout << "Ingresar e-mail:\n";
    std::cin.ignore();
    getline(std::cin, email);
    supplier.setEmail(email);
}

void SupplierManager::cinSupplierIsActive(Supplier & supplier) {
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

void SupplierManager::cinSupplierBankAccount(Supplier & supplier) {
    int bank_account;
    std::cout << "Ingresar cuenta bancaria:\n";
    bank_account = _terminal.validateInt(0);
    supplier.setBankAccount(bank_account);
}

int SupplierManager::generateSupplierId() {
    int id;

    if (_supplier.getId() != 0) {
        id = _supplier_archive.getAmountOfRegisters() + 1;
    } else {
        id = 1;
    }

    return id;
}