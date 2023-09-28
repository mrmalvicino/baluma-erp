#include "../headers/ItemsManager.h"

ItemsManager::ItemsManager() {
    _items_backup.setPath("registers/products.bkp");
}

void ItemsManager::displayMainMenu() {
    int selection = 1;

    do {
        _terminal.clear();
        _terminal.displayMenuHeader("INVENTARIO");
        std::cout << "(1) ADMINISTRAR DEPÓSITOS\n";
        std::cout << "(2) ADMINISTRAR MERCADERÍA\n";
        _terminal.printLine();
        std::cout << "(3) LISTADO DE PRODUCTOS\n";
        std::cout << "(4) EXPORTAR LISTADO A CSV\n";
        _terminal.displayMenuFooter();

        selection = _terminal.validateInt(0, 8);

        switch (selection) {
            case 1:
                _warehouses_manager.displayMenu();
                break;

            case 2:
                _warehouses_manager.searchWarehouse();
                _items_archive.setPath(_warehouses_manager.getItemsPath());
                displayProductsMenu();
                break;

            case 3:
                
                break;

            case 4:
                
                break;
        }
    } while (selection != 0);
}

void ItemsManager::displayProductsMenu() {
    int selection = 1;

    do {
        _terminal.clear();
        _terminal.displayMenuHeader("PRODUCTOS");
        std::cout << "(1) AGREGAR NUEVO\n";
        std::cout << "(2) EDITAR PRODUCTO\n";
        std::cout << "(3) BUSCAR PRODUCTO\n";
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
                addItem();
                break;

            case 2:
                editItem();
                break;

            case 3:
                searchItem();
                break;

            case 4:
                listItems();
                break;

            case 5:
                exportItemsBackup();
                break;

            case 6:
                importItemsBackup();
                break;

            case 7:
                exportItemsCSV();
                break;

            case 8:
                importItemsCSV();
                break;
        }
    } while (selection != 0);
}

bool ItemsManager::addItem() {
    bool successful_write;
    bool user_wants_to_save;

    _terminal.clear();
    _terminal.displayMenuHeader("AGREGAR PRODUCTO");

    cinItemName(_item);
    cinItemDescription(_item);
    cinItemBrand(_item);
    cinItemModel(_item);
    cinItemPrice(_item);
    cinItemStock(_item);
    cinItemIncome(_item);

    std::cout << "¿Desea guardar un nuevo registro con los datos ingresados? [S/N]\n";
    user_wants_to_save = _terminal.validateBool();

    if (user_wants_to_save == true) {
        // successful_write = _items_list_archive.write(_item);
        _item.setId(generateItemId()); // Se va a usar otra función
        successful_write = _items_archive.write(_item); // Antes lo guarda en _listado_de_productos
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

bool ItemsManager::editItem() {
    _terminal.clear();

    searchItem();

    if (_item.getId() == -1) {
        return false;
    }

    int selection = 1;

    do {
        _terminal.clear();
        _terminal.displayMenuHeader("EDITAR PRODUCTO");
        _terminal.centerAndPrint(_item.getName());
        std::cout << "\n";
        std::cout << "(1) EDITAR NOMBRE\n";
        std::cout << "(2) EDITAR DESCRIPCION\n";
        std::cout << "(3) EDITAR MARCA\n";
        std::cout << "(4) EDITAR MODELO\n";
        std::cout << "(5) EDITAR STOCK\n";
        std::cout << "(6) EDITAR PRECIO\n";
        std::cout << "(7) EDITAR FECHA DE INGRESO\n";
        std::cout << "(8) DAR DE BAJA O REINCORPORAR\n";
        _terminal.displayMenuFooter();

        selection = _terminal.validateInt(0, 8);

        switch (selection) {
            case 1:
                cinItemName(_item);
                break;
            case 2:
                cinItemDescription(_item);
                break;
            case 3:
                cinItemBrand(_item);
                break;
            case 4:
                cinItemModel(_item);
                break;
            case 5:
                cinItemStock(_item);
                break;
            case 6:
                cinItemPrice(_item);
                break;
            case 7:
                cinItemIncome(_item);
                break;
            case 8:
                cinItemIsActive(_item);
                break;
        }
    } while (selection != 0);

    int index = _items_archive.getIndex(_item.getId());
    bool successful_write = _items_archive.overWrite(_item, index);

    return successful_write;
}

void ItemsManager::searchItem() {
    _terminal.clear();

    int selection = 1;

    _terminal.displayMenuHeader("BUSCAR PRODUCTO");
    std::cout << "(1) BUSCAR POR ID\n";
    std::cout << "(2) BUSCAR POR NOMBRE\n";
    _terminal.displayMenuFooter();

    selection = _terminal.validateInt(0, 2);

    switch (selection) {
        case 0:
            _terminal.clear();
            break;
        case 1:
            searchItemById();
            break;
        case 2:
            searchItemByDescription();
            break;
    }
    
}

void ItemsManager::listItems() {
    _terminal.clear();

    int amount_of_items = _items_archive.getAmountOfRegisters();

    _terminal.displayMenuHeader("LISTADO DE PRODUCTOS");

    for (int i = 0; i < amount_of_items; i ++) {
        printItem(i);
    }

    _terminal.pause();
    _terminal.clear();
}

void ItemsManager::printItem(int index) {
    _item = _items_archive.read(index);
    _terminal.displayMenuHeader(_item.getName());
    std::cout << "# ID: " << _item.getId() << "\n";
    std::cout << "Descripcion: " << _item.getDescription() << "\n";
    std::cout << "Marca: " << _item.getBrand() << "\n";
    std::cout << "Modelo: " << _item.getModel() << "\n";
    std::cout << "Stock: " << _item.getStock() << "\n";
    std::cout << "Precio unitario: " << _item.getPrice() << "\n";
    std::cout << "Fecha de ingreso: " << _item.getIncome().toString() << "\n";
    _terminal.printBool(_item.getIsActive(), "Estado: Activo\n\n", "Estado: Dado de baja\n\n");
}

void ItemsManager::cinItemName(Item & item) {
    std::string name;

    std::cout << "Ingrese nombre del producto:\n";
    std::cin.ignore();
    getline(std::cin, name);

    item.setName(name);
}

void ItemsManager::cinItemDescription(Item & item) {
    std::string description;

    std::cout << "Ingrese descripcion:\n";
    getline(std::cin, description);

    item.setDescription(description);
}

void ItemsManager::cinItemBrand(Item & item) {
    std::string brand;

    std::cout << "Ingrese marca:\n";
    getline(std::cin, brand);

    item.setBrand(brand);
}

void ItemsManager::cinItemModel(Item & item) {
    std::string model;

    std::cout << "Ingrese modelo:\n";
    getline(std::cin, model);

    item.setModel(model);
}

void ItemsManager::cinItemPrice(Item & item) {
    double price;

    std::cout << "Ingrese valor unitario:\n";
    std::cin >> price;

    item.setPrice(price);
}

void ItemsManager::cinItemStock(Item & item) {
    int stock;

    std::cout << "Ingrese el stock:\n";
    stock = _terminal.validateInt(0);

    item.setStock(stock);
}

void ItemsManager::cinItemIncome(Item & item) {
    Date date;
    int day, month, year;

    std::cout << "Ingrese dia de ingreso:\n";
    day = _terminal.validateInt(1, 31);

    std::cout << "Ingrese mes de ingreso:\n";
    month = _terminal.validateInt(1,12);

    std::cout << "Ingrese año de ingreso:\n";
    year = _terminal.validateInt(1900,2023);

    date.setDay(day);
    date.setMonth(month);
    date.setYear(year);

    item.setIncome(date);
}

void ItemsManager::cinItemIsActive(Item & item) {
    if (item.getIsActive()) {
        item.setIsActive(false);
        std::cout << "El producto ha sido dado de baja.\n";
        _terminal.pause();
    } else {
        item.setIsActive(true);
        std::cout << "El producto ha sido reincorporado.\n";
        _terminal.pause();
    }
}

int ItemsManager::generateItemId() {
    int id = 1;

    if(_items_archive.getAmountOfRegisters() != 0) {
        id = _items_archive.getAmountOfRegisters() + 1;
    }

    return id;
}

void ItemsManager::searchItemById() {
    int index;
    int id;
    int max_id;

    max_id = _items_archive.getAmountOfRegisters();

    std::cout << "Ingresar ID o 0 para cancelar:\n";
    id = _terminal.validateInt(0, max_id);

    if (0 < id) {
        index = _items_archive.getIndex(id);
        printItem(index);
    } else {
        _item.setId(-1);
        std::cout << "Búsqueda abortada por el usuario.\n";
    }

    _terminal.pause();
}

void ItemsManager::searchItemByDescription() {
    int index;
    std::string description;

    std::cout << "Ingresar nombre:\n";
    std::cin.ignore();
    getline(std::cin, description);

    index = _items_archive.getIndex(description);

    while (index == -1) {
        std::cout << "No se encontró el registro " << description << ". Ingrese el nombre nuevamente o ingrese 0 para cancelar.\n";
        getline(std::cin, description);

        if (description == "0") {
            index = -2;
        } else {
            index = _items_archive.getIndex(description); // Esta función retorna -1 si no encuentra un registro válido
        }
    }

    if (0 <= index) {
        printItem(index);
    } else {
        _item.setId(-1);
        std::cout << "Búsqueda abortada por el usuario.\n";
    }
    
    _terminal.pause();
}

void ItemsManager::exportItemsBackup() {
     int amount_of_items = _items_archive.getAmountOfRegisters();

    Item * items_array = new Item[amount_of_items];

    if (items_array == NULL) {
        std::cout << "Error de memoria RAM: No se pudo asignar la memoria requerida al exportar backup.";
    } else {
        for (int i = 0; i < amount_of_items; i ++) {
            items_array[i] = _items_archive.read(i);
        }

        _items_backup.createEmptyArchive();

        for (int i = 0; i < amount_of_items; i ++) {
            _items_backup.write(items_array[i]);
        }

        delete [] items_array;

        std::cout << "Backup exportado correctamente.\n";
        _terminal.pause();
    }
}

void ItemsManager::importItemsBackup() {
     std::cout << "¿Desea reemplazar los Items actuales por aquellos que haya en el archivo de respaldo? [S/N]\n";

    if (_terminal.validateBool() == false) {
        std::cout << "Importación abortada por el usuario.\n";
    } else {
        int amount_of_items = _items_backup.getAmountOfRegisters();

        Item * items_array = new Item[amount_of_items];

        if (items_array == NULL) {
            std::cout << "Error de memoria RAM: No se pudo asignar la memoria requerida al importar backup.";
        } else {
            for (int i = 0; i < amount_of_items; i ++) {
                items_array[i] = _items_backup.read(i);
            }

            _items_archive.createEmptyArchive();

            for (int i = 0; i < amount_of_items; i ++) {
                _items_archive.write(items_array[i]);
            }

            delete [] items_array;
            std::cout << "Backup importado correctamente.\n";
            _terminal.pause();
        }
    }
}

void ItemsManager::exportItemsCSV() {
    _items_csv.writeItemsCSV(_item, _items_archive);
}

void ItemsManager::importItemsCSV() {
    std::cout << "¿Desea reemplazar los itemes actuales por aquellos que haya en el archivo CSV? [S/N]\n";

    if (_terminal.validateBool() == false) {
        std::cout << "Importación abortada por el usuario.\n";
    } else {
        _items_csv.readItemsCSV(_item, _items_archive);
    }
}