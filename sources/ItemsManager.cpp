#include "../headers/ItemsManager.h"

ItemsManager::ItemsManager() {
    _items_backup.setPath("registers/products.bkp");
}

void ItemsManager::displayMainMenu() {
    int selection = 1;

    do {
        _terminal.clear();
        _terminal.displayMenuHeader("INVENTARIO");
        std::cout << "(1) DATOS DE LOS PRODUCTOS\n";
        std::cout << "(2) DATOS DE LOS DEPÓSITOS\n";
        std::cout << "(3) ADMINISTRAR MERCADERÍA EN DEPÓSITO\n";
        _terminal.printLine();
        std::cout << "(4) MOSTRAR INFORME\n";
        std::cout << "(5) EXPORTAR INFORME A CSV\n";
        _terminal.displayMenuFooter();

        selection = _terminal.validateInt(0, 4);

        switch (selection) {
            case 1:
                _products_manager.displayMenu();
                break;
            case 2:
                _warehouses_manager.displayMenu();
                break;
            case 3:
                loadItemsMenu();
                break;
            case 4:
                showInventory();
                break;
            case 5:
                exportInventoryCSV();
                break;
        }
    } while (selection != 0);
}

void ItemsManager::loadItemsMenu() {
    _warehouses_manager.searchWarehouse();

    if (_warehouses_manager.getWarehouse().getName() != "N/A") {
        setWarehousePaths();
        displayItemsMenu();
    } else {
        std::cout << "No se seleccionó ningún depósito para administrar su mercadería.\n";
        _terminal.pause();
        _terminal.clear();
    }
}

void ItemsManager::setWarehousePaths() {
        std::string dat_path = "registers/warehouse" + std::to_string(_warehouses_manager.getWarehouse().getId()) + ".dat";
        std::string bkp_path = "registers/warehouse" + std::to_string(_warehouses_manager.getWarehouse().getId()) + ".bkp";
        std::string csv_path = "registers/warehouse" + std::to_string(_warehouses_manager.getWarehouse().getId()) + ".csv";
        _items_archive.setPath(dat_path);
        _items_backup.setPath(bkp_path);
        _items_csv.setPath(csv_path);
}

void ItemsManager::displayItemsMenu() {
    int selection = 1;

    do {
        _terminal.clear();
        _terminal.displayMenuHeader("EXISTENCIAS");
        _terminal.centerAndPrint(_warehouses_manager.getWarehouse().getName());
        std::cout << "\n";
        std::cout << "(1) AGREGAR EXISTENCIA\n";
        std::cout << "(2) EDITAR EXISTENCIA\n";
        std::cout << "(3) BUSCAR EXISTENCIA\n";
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
    bool successful_write = false;
    bool user_wants_to_save;

    _terminal.clear();
    _terminal.displayMenuHeader("AGREGAR EXISTENCIA");

    cinItemName(_item);
    cinItemBrand(_item);
    cinItemModel(_item);
    cinItemDescription(_item);
    cinItemPrice(_item);
    cinItemStock(_item);
    cinItemIncome(_item);

    std::cout << "¿Desea guardar un nuevo registro con los datos ingresados? [S/N]\n";
    user_wants_to_save = _terminal.validateBool();

    if (user_wants_to_save == true) {
        generateItemId();
        successful_write = _items_archive.write(_item);

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
        _terminal.displayMenuHeader("EDITAR EXISTENCIA");
        _terminal.centerAndPrint(_item.getName());
        std::cout << "\n";
        std::cout << "(1) EDITAR DESCRIPCION\n";
        std::cout << "(2) EDITAR PRECIO\n";
        std::cout << "(3) EDITAR STOCK\n";
        std::cout << "(4) EDITAR FECHA DE INGRESO\n";
        std::cout << "(5) DAR DE BAJA O REINCORPORAR\n";
        _terminal.displayMenuFooter();

        selection = _terminal.validateInt(0, 5);

        switch (selection) {
            case 1:
                cinItemDescription(_item);
                break;
            case 2:
                cinItemPrice(_item);
                break;
            case 3:
                cinItemStock(_item);
                break;
            case 4:
                cinItemIncome(_item);
                break;
            case 5:
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

    _terminal.displayMenuHeader("BUSCAR EXISTENCIA");
    std::cout << "(1) BUSCAR POR ID\n";
    std::cout << "(2) BUSCAR POR NOMBRE, MARCA Y MODELO\n";
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
            searchItemByProduct();
            break;
    }
}

void ItemsManager::listItems() {
    _terminal.clear();

    int amount_of_items = _items_archive.getAmountOfRegisters();

    _terminal.displayMenuHeader("EXISTENCIAS EN DEPÓSITO");

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

void ItemsManager::cinItemDescription(Item & item) {
    std::string description;

    std::cout << "Ingrese descripcion:\n";
    getline(std::cin, description);

    item.setDescription(description);
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

void ItemsManager::searchItemById() {
    int index;
    int id;
    int max_id;

    max_id = _products_archive.getAmountOfRegisters();

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

void ItemsManager::searchItemByProduct() {
    int index;
    std::string name;
    std::string brand;
    std::string model;

    std::cout << "Ingresar nombre:\n";
    std::cin.ignore();
    getline(std::cin, name);

    std::cout << "Ingresar marca:\n";
    getline(std::cin, brand);

    std::cout << "Ingresar modelo:\n";
    getline(std::cin, model);

    _product.setName(name);
    _product.setBrand(brand);
    _product.setModel(model);

    index = _items_archive.getIndex(_product);

    while (index == -1) {
        std::cout << "No se encontró el registro " << _product.toString() << ".";
        std::cout << "Ingrese el nombre nuevamente o ingrese 0 para cancelar.\n";
        getline(std::cin, name);

        if (name == "0") {
            index = -2;
        } else {
            std::cout << "Ingrese la marca nuevamente o ingrese 0 para cancelar.\n";
            getline(std::cin, brand);

            if (brand == "0") {
                index = -2;
            } else {
                std::cout << "Ingrese el modelo nuevamente o ingrese 0 para cancelar.\n";
                getline(std::cin, model);

                if (model == "0") {
                    index = -2;
                } else {
                    _product.setName(name);
                    _product.setBrand(brand);
                    _product.setModel(model);
                    index = _items_archive.getIndex(_product); // Esta función retorna -1 si no encuentra un registro válido
                }
            }
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

void ItemsManager::generateItemId() {
    int id = 1;
    int amount_of_products = _products_archive.getAmountOfRegisters();
    int item_index_in_products_archive = productIndex();
    bool add_item_to_products = true;

    if(amount_of_products != 0) { // Si la lista no es vacía, determinar si el nuevo item ya existe
        if (item_index_in_products_archive != -1) {
            id = item_index_in_products_archive + 1; // Si existe, el id es la ubicación del item en la lista de productos + 1
            add_item_to_products = false; // Además, si existe no debe ser agregado nuevamente
        } else {
            id = amount_of_products + 1; // Si no existe, agregar item a la lista con nuevo id
        }
    } // Si la lista es vacía, el nuevo item va a ser el primero en la lista de productos

    _item.setId(id);

    if (add_item_to_products == true) {
        bool successful_write = _products_archive.write(_item);

        if (successful_write == true) {
            std::cout << "Creando registro...\n";
        } else {
            std::cout << "Error de escritura.\n";
        }
    }
}

int ItemsManager::productIndex() {
    int index = -1;

    int amount_of_products = _products_archive.getAmountOfRegisters();

    for (int i = 0; i < amount_of_products; i ++) {
        _product = _products_archive.read(i);

        if (_item.getName() == _product.getName() && _item.getBrand() == _product.getBrand() && _item.getModel() == _product.getModel()) {
            index = i;
        }
    }

    return index;
}

void ItemsManager::showInventory() {
    _terminal.clear();

    int amount_of_warehouses = _warehouses_manager.getAmountOfWarehouses();
    int amount_of_products = _products_archive.getAmountOfRegisters();
    int amount_of_items;

    int ** quantities_matrix = _array.allocateMatrix(amount_of_products, amount_of_warehouses);

    for (int i = 0; i < amount_of_warehouses; i ++) {
        _warehouses_manager.setWarehouse(i);
        setWarehousePaths();
        amount_of_items = _items_archive.getAmountOfRegisters();

        for (int j = 0; j < amount_of_items; j ++) {
            for (int k = 0; k < amount_of_products; k ++) {
                _item = _items_archive.read(j);
                _product = _products_archive.read(k);

                if (_product.getId() == _item.getId()) {
                    quantities_matrix[k][i] = _item.getStock();
                }
            }
        }
    }

    int total_stock = 0;

    for (int i = 0; i < amount_of_products; i ++) {
        _product = _products_archive.read(i);
        std::cout << _terminal.fill(_product.toString());

        for (int j = 0; j < amount_of_warehouses; j ++) {
            _warehouses_manager.setWarehouse(j);
            std::cout << "\tStock " << _warehouses_manager.getWarehouse().getName() << ": " << quantities_matrix[i][j] << "\t";
            total_stock += quantities_matrix[i][j];
        }

        std::cout << "Stock total: " << total_stock << "\n";
        total_stock = 0;
    }

    _terminal.pause();
    _array.deleteMatrix(quantities_matrix, amount_of_products);
}

void ItemsManager::exportInventoryCSV() {
    return; //EN DESARROLLO
}