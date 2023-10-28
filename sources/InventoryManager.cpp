#include "../headers/InventoryManager.h"

void InventoryManager::displayMainMenu() {
    int selection = 1;

    do {
        _terminal.clear();
        _terminal.displayMenuHeader("INVENTARIO");
        std::cout << "(1) DATOS DE LOS PRODUCTOS\n";
        std::cout << "(2) DATOS DE LOS DEPÓSITOS\n";
        std::cout << "(3) ADMINISTRAR EXISTENCIAS\n";
        _terminal.printLine();
        std::cout << "(4) MOSTRAR INFORME\n";
        std::cout << "(5) EXPORTAR INFORME A CSV\n";
        _terminal.displayMenuFooter();

        selection = _terminal.validateInt(0, 5);

        switch (selection) {
            case 1:
                displayProductsMenu();
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

int InventoryManager::getAmountOfProducts(){
    _amount_of_products = _products_archive.getAmountOfRegisters();
    return _amount_of_products;
}

void InventoryManager::displayProductsMenu() {
    int selection = 1;

    do {
        _terminal.clear();
        _terminal.displayMenuHeader("PRODUCTOS");
        std::cout << "(1) AGREGAR PRODUCTO\n";
        std::cout << "(2) EDITAR PRODUCTO\n";
        std::cout << "(3) BUSCAR PRODUCTO\n";
        std::cout << "(4) VER LISTADO\n";
        _terminal.printLine();
        std::cout << "(5) EXPORTAR BACKUP\n";
        std::cout << "(6) IMPORTAR BACKUP\n";
        _terminal.displayMenuFooter();

        selection = _terminal.validateInt(0, 6);

        switch (selection) {
            case 1:
                addProduct();
                break;
            case 2:
                editProduct();
                break;
            case 3:
                searchProduct();
                break;
            case 4:
                listProductsMenu();
                break;
            case 5:
                exportProductsBackup();
                break;
            case 6:
                importProductsBackup();
                break;
        }
    } while (selection != 0);
}

bool InventoryManager::addProduct() {
    bool successful_write;
    bool user_wants_to_save;

    _terminal.clear();
    _terminal.displayMenuHeader("AGREGAR PRODUCTO");

    _product.setId(generateProductId());

    cinProductName(_product, true);
    cinProductBrand(_product);
    cinProductModel(_product);
    cinProductDescription(_product);
    cinProductPrice(_product);
    cinProductIsActive(_product);

    std::cout << "¿Desea guardar un nuevo registro con los datos ingresados? [S/N]\n";
    user_wants_to_save = _terminal.validateBool();

    if (user_wants_to_save == true) {
        successful_write = _products_archive.write(_product);
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

bool InventoryManager::editProduct() {
    _terminal.clear();

    int search_rtn = searchProduct();

    if (search_rtn == -1) {
        return false;
    }

    int selection = 1;

    do {
        _terminal.clear();
        _terminal.displayMenuHeader("EDITAR PRODUCTO");
        _terminal.centerAndPrint(_product.toString());
        std::cout << "\n";
        std::cout << "(1) EDITAR NOMBRE\n";
        std::cout << "(2) EDITAR MARCA\n";
        std::cout << "(3) EDITAR MODELO\n";
        std::cout << "(4) EDITAR DESCRIPCION\n";
        std::cout << "(5) EDITAR PRECIO\n";
        std::cout << "(6) DAR DE BAJA O REINCORPORAR\n";
        _terminal.displayMenuFooter();

        selection = _terminal.validateInt(0, 6);

        switch (selection) {
            case 1:
                cinProductName(_product, true);
                break;
            case 2:
                cinProductBrand(_product, true);
                break;
            case 3:
                cinProductModel(_product, true);
                break;
            case 4:
                cinProductDescription(_product, true);
                break;
            case 5:
                cinProductPrice(_product);
                break;
            case 6:
                cinProductIsActive(_product);
                break;
        }
    } while (selection != 0);

    int index = _products_archive.getIndex(_product.getId());
    bool successful_write = _products_archive.overWrite(_product, index);
    successful_write = synchronizeItem();

    return successful_write;
}

bool InventoryManager::synchronizeItem() {
    int amount_of_warehouses = _warehouses_manager.getAmountOfWarehouses();
    int amount_of_items;
    bool successful_write;

    for (int i = 0; i < amount_of_warehouses; i ++) { // TO DO
        setWarehousePaths(i + 1);
        amount_of_items = getAmountOfItems();

        for (int j = 0; j < amount_of_items; j ++) {
            _item = _items_archive.read(j);

            if (_product.getId() == _item.getId()) {
                _item.setName(_product.getName());
                _item.setBrand(_product.getBrand());
                _item.setModel(_product.getModel());
                _item.setDescription(_product.getDescription());
                _item.setPrice(_product.getPrice());
                _item.setIsActive(_product.getIsActive());
                int index = _items_archive.getIndex(_item.getId());
                successful_write = _items_archive.overWrite(_item, index);
            }
        }
    }

    return successful_write;
}

int InventoryManager::searchProduct() {
    _terminal.clear();

    int search_rtn = 0;
    int selection = 1;

    _terminal.displayMenuHeader("BUSCAR PRODUCTO");
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
            search_rtn = searchProductById();
            break;
        case 2:
            search_rtn = searchProductByNBM();
            break;
    }

    return search_rtn;
}

int InventoryManager::searchProductById() {
    int search_rtn = 0;
    int index;
    int id;

    std::cout << "Ingresar ID o 0 para cancelar:\n";
    id = _terminal.validateInt(0, getAmountOfProducts());

    if (0 < id) {
        index = _products_archive.getIndex(id);
        loadProduct(index);
        printProduct();
    } else {
        search_rtn = -1;
        std::cout << "Búsqueda abortada por el usuario.\n";
    }

    _terminal.pause();

    return search_rtn;
}

int InventoryManager::searchProductByNBM() {
    int search_rtn = 0;
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

    index = _products_archive.getIndex(_product);

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
                    index = _products_archive.getIndex(_product); // Esta función retorna -1 si no encuentra un registro válido
                }
            }
        }
    }

    if (0 <= index) {
        loadProduct(index);
        printProduct();
    } else {
        search_rtn = -1;
        std::cout << "Búsqueda abortada por el usuario.\n";
    }
    
    _terminal.pause();

    return search_rtn;
}

void InventoryManager::listProductsMenu() {
    _terminal.clear();

    int selection = 1;

    _terminal.displayMenuHeader("LISTAR PRODUCTOS");
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
            listProducts(true, true);
            break;
        case 2:
            listProducts(true, false);
            break;
        case 3:
            listProducts(false, true);
            break;
    }
}

void InventoryManager::listProducts(bool list_actives, bool list_inactives) {
    _terminal.clear();

    int amount_of_products = _products_archive.getAmountOfRegisters();

    _terminal.displayMenuHeader("LISTADO DE PRODUCTOS");

    for (int i = 0; i < amount_of_products; i ++) {
        loadProduct(i);

        if ( (_product.getIsActive() == true && list_actives == true) || (_product.getIsActive() == false && list_inactives == true) ) {
            printProduct();
        }
    }

    _terminal.pause();
    _terminal.clear();
}

void InventoryManager::loadProduct(int index) {
    _product = _products_archive.read(index);
}

void InventoryManager::printProduct() {
    _terminal.displayMenuHeader(_product.toString());
    std::cout << "# ID: " << _product.getId() << "\n";
    std::cout << "Nombre: " << _product.getName() << "\n";
    std::cout << "Marca: " << _product.getBrand() << "\n";
    std::cout << "Modelo: " << _product.getModel() << "\n";
    std::cout << "Descripción: " << _product.getDescription() << "\n";
    std::cout << "Precio unitario: $" << _product.getPrice() << "\n";
    _terminal.printBool(_product.getIsActive(), "Estado: Activo\n\n", "Estado: Dado de baja\n\n");
}

int InventoryManager::generateProductId() {
    int id = 1;

    if(_products_archive.getAmountOfRegisters() != 0) {
        id = _products_archive.getAmountOfRegisters() + 1;
    }

    return id;
}

void InventoryManager::exportProductsBackup() {
    int amount_of_products = _products_archive.getAmountOfRegisters();

    Product * products_array = new Product[amount_of_products];

    if (products_array == NULL) {
        std::cout << "Error de memoria RAM: No se pudo asignar la memoria requerida al exportar backup.";
    } else {
        for (int i = 0; i < amount_of_products; i ++) {
            products_array[i] = _products_archive.read(i);
        }

        _products_backup.createEmptyArchive();

        for (int i = 0; i < amount_of_products; i ++) {
            _products_backup.write(products_array[i]);
        }

        delete [] products_array;

        std::cout << "Backup exportado correctamente.\n";
        _terminal.pause();
    }
}

void InventoryManager::importProductsBackup() {
    std::cout << "¿Desea reemplazar los productos actuales por aquellos que haya en el archivo de respaldo? [S/N]\n";

    if (_terminal.validateBool() == false) {
        std::cout << "Importación abortada por el usuario.\n";
    } else {
        int amount_of_products = _products_backup.getAmountOfRegisters();

        Product * products_array = new Product[amount_of_products];

        if (products_array == NULL) {
            std::cout << "Error de memoria RAM: No se pudo asignar la memoria requerida al importar backup.";
        } else {
            for (int i = 0; i < amount_of_products; i ++) {
                products_array[i] = _products_backup.read(i);
            }

            _products_archive.createEmptyArchive();

            for (int i = 0; i < amount_of_products; i ++) {
                _products_archive.write(products_array[i]);
            }

            delete [] products_array;
            std::cout << "Backup importado correctamente.\n";
            _terminal.pause();
        }
    }
}

int InventoryManager::getAmountOfItems(){
    _amount_of_items = _items_archive.getAmountOfRegisters();
    return _amount_of_items;
}

void InventoryManager::setWarehousePaths(int warehouse_id) {
        std::string dat_path = "registers/warehouse" + std::to_string(warehouse_id) + ".dat";
        std::string bkp_path = "registers/warehouse" + std::to_string(warehouse_id) + ".bkp";
        std::string csv_path = "registers/warehouse" + std::to_string(warehouse_id) + ".csv";
        _items_archive.setPath(dat_path);
        _items_backup.setPath(bkp_path);
        _items_csv.setPath(csv_path);
}

void InventoryManager::loadItemsMenu() {
    int search_rtn = _warehouses_manager.searchWarehouse();

    if (search_rtn != -1) {
        setWarehousePaths(_warehouses_manager.getWarehouse().getId());
        displayItemsMenu(_warehouses_manager.getWarehouse().getName());
    }
}

void InventoryManager::displayItemsMenu(std::string warehouse_name) {
    int selection = 1;

    do {
        _terminal.clear();
        _terminal.displayMenuHeader("EXISTENCIAS");
        _terminal.centerAndPrint(warehouse_name);
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
                listItemsMenu();
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

bool InventoryManager::addItem() {
    bool successful_write = false;
    bool user_wants_to_save;

    _terminal.clear();
    _terminal.displayMenuHeader("AGREGAR EXISTENCIA");

    cinProductName(_item, true);
    cinProductBrand(_item);
    cinProductModel(_item);
    cinProductDescription(_item);
    cinProductPrice(_item);
    cinItemStock(_item);
    cinItemIncome(_item);

    std::cout << "¿Desea guardar un nuevo registro con los datos ingresados? [S/N]\n";
    user_wants_to_save = _terminal.validateBool();

    if (user_wants_to_save == true) {
        generateItemId();
        synchronizeProduct();

        int item_index = _items_archive.getIndex(_item);

        if (item_index == -1) {
            successful_write = _items_archive.write(_item);
        } else {
            successful_write = _items_archive.overWrite(_item, item_index);
        }

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

bool InventoryManager::editItem() {
    _terminal.clear();

    int search_rtn = searchItem();

    if (search_rtn == -1) {
        return false;
    }

    int selection = 1;

    do {
        _terminal.clear();
        _terminal.displayMenuHeader("EDITAR EXISTENCIA");
        _terminal.centerAndPrint(_item.getName());
        std::cout << "\n";
        std::cout << "(1) EDITAR STOCK\n";
        std::cout << "(2) EDITAR FECHA DE INGRESO\n";
        _terminal.displayMenuFooter();

        selection = _terminal.validateInt(0, 2);

        switch (selection) {
            case 1:
                cinItemStock(_item);
                break;
            case 2:
                cinItemIncome(_item);
                break;
        }
    } while (selection != 0);

    int index = _items_archive.getIndex(_item.getId());
    bool successful_write = _items_archive.overWrite(_item, index);

    return successful_write;
}

int InventoryManager::searchItem() {
    _terminal.clear();

    int search_rtn = 0;
    int selection = 1;

    _terminal.displayMenuHeader("BUSCAR EXISTENCIA");
    std::cout << "(1) BUSCAR POR ID\n";
    std::cout << "(2) BUSCAR POR NOMBRE, MARCA Y MODELO\n";
    _terminal.displayMenuFooter();

    selection = _terminal.validateInt(0, 2);

    switch (selection) {
        case 0:
            search_rtn = -1;
            _terminal.clear();
            break;
        case 1:
            search_rtn = searchItemById();
            break;
        case 2:
            search_rtn = searchItemByNBM();
            break;
    }

    return search_rtn;
}

int InventoryManager::searchItemById() {
    int search_rtn = 0;
    int index;
    int id;

    std::cout << "Ingresar ID o 0 para cancelar:\n";
    id = _terminal.validateInt(0, getAmountOfProducts());

    if (0 < id) {
        index = _items_archive.getIndex(id);
        loadItem(index);

        if (_item.getName() != "N/A") {
            printItem();
        } else {
            search_rtn = -1;
            std::cout << "No hay existencias del producto en este depósito.\n";
        }
    } else {
        search_rtn = -1;
        std::cout << "Búsqueda abortada por el usuario.\n";
    }

    _terminal.pause();

    return search_rtn;
}

int InventoryManager::searchItemByNBM() {
    int search_rtn = 0;
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
        loadItem(index);
        printItem();
    } else {
        search_rtn = -1;
        std::cout << "Búsqueda abortada por el usuario.\n";
    }

    _terminal.pause();

    return search_rtn;
}

void InventoryManager::listItemsMenu() {
    _terminal.clear();

    int selection = 1;

    _terminal.displayMenuHeader("LISTAR EXISTENCIAS");
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
            listItems(true, true);
            break;
        case 2:
            listItems(true, false);
            break;
        case 3:
            listItems(false, true);
            break;
    }
}

void InventoryManager::listItems(bool list_actives, bool list_inactives) {
    _terminal.clear();

    int amount_of_items = _items_archive.getAmountOfRegisters();

    _terminal.displayMenuHeader("EXISTENCIAS EN DEPÓSITO");

    for (int i = 0; i < amount_of_items; i ++) {
        loadItem(i);

        if ( (_item.getIsActive() == true && list_actives == true) || (_item.getIsActive() == false && list_inactives == true) ) {
            printItem();
        }
    }

    _terminal.pause();
    _terminal.clear();
}

void InventoryManager::loadItem(int index) {
    _item = _items_archive.read(index);
}

void InventoryManager::printItem() {
    _terminal.displayMenuHeader(_item.toString());
    std::cout << "# ID: " << _item.getId() << "\n";
    std::cout << "Rubro: " << _item.getName() << "\n";
    std::cout << "Marca: " << _item.getBrand() << "\n";
    std::cout << "Modelo: " << _item.getModel() << "\n";
    std::cout << "Descripción: " << _item.getDescription() << "\n";
    std::cout << "Precio unitario: " << _item.getPrice() << "\n";
    std::cout << "Stock: " << _item.getStock() << "\n";
    std::cout << "Fecha de ingreso: " << _item.getIncome().toString() << "\n";
    _terminal.printBool(_item.getIsActive(), "Estado: Activo\n\n", "Estado: Dado de baja\n\n");
}

void InventoryManager::exportItemsBackup() {
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

void InventoryManager::importItemsBackup() {
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

void InventoryManager::exportItemsCSV() {
    _items_csv.writeItemsCSV(_item, _items_archive);
}

void InventoryManager::importItemsCSV() {
    std::cout << "¿Desea reemplazar los itemes actuales por aquellos que haya en el archivo CSV? [S/N]\n";

    if (_terminal.validateBool() == false) {
        std::cout << "Importación abortada por el usuario.\n";
    } else {
        _items_csv.readItemsCSV(_item, _items_archive);
    }
}

void InventoryManager::generateItemId() {
    int id = 1;
    int amount_of_products = _products_archive.getAmountOfRegisters();
    int product_index = productIndex();

    if(amount_of_products != 0) { // Si hay al menos 1 producto, determinar si el nuevo item ya existe como producto
        if (product_index != -1) {
            id = product_index + 1; // Si existe, el id es la ubicación del item en la lista de productos + 1
        } else {
            id = amount_of_products + 1; // Si no existe, agregar producto a la lista con nuevo id
        }
    } // Si la lista es vacía, el nuevo item va a ser el primero en la lista de productos

    _item.setId(id);
}

void InventoryManager::synchronizeProduct() {
    int product_index = productIndex();

    if (product_index == -1) { // Si la existencia aun no fue registrada como producto
        bool successful_write = _products_archive.write(_item); // Escribir en el archivo de productos lo compartido por la herencia de item

        if (successful_write == true) {
            std::cout << "La existencia fue registrada como un nuevo producto.\n";
        } else {
            std::cout << "Error de escritura.\n";
        }
    } else { // Si la existencia ya fue agregada como producto, tomar la descripción y el precio del producto
        _product = _products_archive.read(product_index);
        _item.setDescription(_product.getDescription());
        _item.setPrice(_product.getPrice());
    }
}

int InventoryManager::productIndex() {
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

void InventoryManager::showInventory() {
    _terminal.clear();

    int amount_of_warehouses = _warehouses_manager.getAmountOfWarehouses();
    int amount_of_products = getAmountOfProducts();
    int amount_of_items;

    int ** quantities_matrix = _array.allocateMatrix(amount_of_products, amount_of_warehouses);

    for (int i = 0; i < amount_of_warehouses; i ++) {
        _warehouses_manager.setWarehouse(i);
        setWarehousePaths(_warehouses_manager.getWarehouse().getId());
        amount_of_items = getAmountOfItems();

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
        std::cout << _terminal.fill(_product.toString(), 35) << "$" << _product.getPrice() << "\n";
        std::cout << _product.getDescription() << "\n";

        for (int j = 0; j < amount_of_warehouses; j ++) {
            _warehouses_manager.setWarehouse(j);
            std::cout << "\tStock " << _warehouses_manager.getWarehouse().getName() << ": " << quantities_matrix[i][j] << "\n";
            total_stock += quantities_matrix[i][j];
        }

        std::cout << "\tStock total: " << total_stock << "\n\n";
        total_stock = 0;
    }

    _terminal.pause();
    _array.deleteMatrix(quantities_matrix, amount_of_products);
}

void InventoryManager::exportInventoryCSV() {
    _terminal.clear();

    int amount_of_warehouses = _warehouses_manager.getAmountOfWarehouses();
    int amount_of_products = getAmountOfProducts();
    int amount_of_items;

    int ** quantities_matrix = _array.allocateMatrix(amount_of_products, amount_of_warehouses);

    for (int i = 0; i < amount_of_warehouses; i ++) {
        _warehouses_manager.setWarehouse(i);
        setWarehousePaths(_warehouses_manager.getWarehouse().getId());
        amount_of_items = getAmountOfItems();

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

    std::ofstream file("registers/inventory.csv");

    if (file.is_open() == false) {
        std::cerr << "Error: No se pudo abrir el archivo al exportar CSV.\n";
        return;
    }

    for (int i = 0; i < amount_of_products; i ++) {
        _product = _products_archive.read(i);
        file << _product.getId() << "," << _product.getName() << "," << _product.getBrand() << "," << _product.getModel() << "," << _product.getDescription() << "," << _product.getPrice() << "," << _product.getIsActive() << ",";

        for (int j = 0; j < amount_of_warehouses; j ++) {
            _warehouses_manager.setWarehouse(j);
            file << quantities_matrix[i][j] << ",";
            total_stock += quantities_matrix[i][j];
        }

        file << total_stock << "\n";
        total_stock = 0;
    }

    _array.deleteMatrix(quantities_matrix, amount_of_products);
    file.close();
    std::cout << "CSV exportado correctamente.\n";
    _terminal.pause();
}

void InventoryManager::cinProductName(Product & product, bool cin_ignore) {
    std::string name;

    if (cin_ignore == true) {
        std::cin.ignore();
    }

    std::cout << "Ingrese nombre del producto:\n";
    getline(std::cin, name);

    product.setName(name);
}

void InventoryManager::cinProductBrand(Product & product, bool cin_ignore) {
    std::string brand;

    if (cin_ignore == true) {
        std::cin.ignore();
    }

    std::cout << "Ingrese marca:\n";
    getline(std::cin, brand);

    product.setBrand(brand);
}

void InventoryManager::cinProductModel(Product & product, bool cin_ignore) {
    std::string model;

    if (cin_ignore == true) {
        std::cin.ignore();
    }

    std::cout << "Ingrese modelo:\n";
    getline(std::cin, model);

    product.setModel(model);
}

void InventoryManager::cinProductDescription(Product & product, bool cin_ignore) {
    std::string description;

    if (cin_ignore == true) {
        std::cin.ignore();
    }

    std::cout << "Ingrese descripción:\n";
    getline(std::cin, description);

    product.setDescription(description);
}

void InventoryManager::cinProductPrice(Product & product) {
    double price;

    std::cout << "Ingrese valor unitario:\n";
    std::cin >> price;

    product.setPrice(price);
}

void InventoryManager::cinProductIsActive(Product & product) {
    if (product.getIsActive()) {
        product.setIsActive(false);
        std::cout << "El producto ha sido dado de baja.\n";
        _terminal.pause();
    } else {
        product.setIsActive(true);
        std::cout << "El producto ha sido reincorporado.\n";
        _terminal.pause();
    }
}

void InventoryManager::cinItemStock(Item & item) {
    int stock = item.getStock();

    std::cout << "Cantidad de unidades:\n";
    stock += _terminal.validateInt(0);

    item.setStock(stock);
}

void InventoryManager::cinItemIncome(Item & item) {
    Date date;
    int day, month, year;

    std::cout << "Ingrese dia de ingreso:\n";
    day = _terminal.validateInt(1, 31);

    std::cout << "Ingrese mes de ingreso:\n";
    month = _terminal.validateInt(1,12);

    std::cout << "Ingrese año de ingreso:\n";
    year = _terminal.validateInt(0);

    date.setDay(day);
    date.setMonth(month);
    date.setYear(year);

    item.setIncome(date);
}