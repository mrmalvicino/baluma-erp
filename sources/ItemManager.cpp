#include "../headers/ItemManager.h"

ItemManager::ItemManager()
{
    _item_backup.setPath("registers/inventory.bkp");
}

void ItemManager::displayMenu()
{
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
                editSupplier();
                break;

            case 3:
                searchItem();
                break;

            case 4:
                listItems();
                break;

            case 5:
                importItemBackuo();
                break;

            case 6:
                exportItemBackup();
                break;

            case 7:
                _item_archive.createEmptyItemArchive();
                break;

            case 8:
                
                break;
        }
    } while (selection != 0);

}

bool ItemManager::addItem()
{
    bool successful_write;
    bool user_wants_to_save;

    _terminal.clear();
    _terminal.displayMenuHeader("AGREGAR PROVEEDOR");

    _item.setId(generateItemId());

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
        successful_write = _item_archive.write(_item);
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

bool ItemManager::editSupplier()
{
    _terminal.clear();

    searchItem();

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

    int index = _item_archive.getIndex(_item.getId());
    bool successful_write = _item_archive.overWrite(_item, index);

    return successful_write;
}

void ItemManager::searchItem()
{
    _terminal.clear();

    int selection = 1;

    _terminal.displayMenuHeader("BUSCAR PROVEEDOR");
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

void ItemManager::listItems()
{
    _terminal.clear();

    int amount_of_items = _item_archive.getAmountOfRegisters();

    _terminal.displayMenuHeader("LISTADO DE PROVEEDORES");

    for (int i = 0; i < amount_of_items; i ++) {
        printItem(i);
    }

    _terminal.pause();
    _terminal.clear();
}

void ItemManager::printItem(int index)
{
    _item = _item_archive.read(index);
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

void ItemManager::cinItemName(Item &item)
{
    std::string name;

    std::cout << "Ingrese nombre del producto:\n";
    std::cin.ignore();
    getline(std::cin, name);

    item.setName(name);
}

void ItemManager::cinItemDescription(Item &item)
{
    std::string description;

    std::cout << "Ingrese descripcion:\n";
    std::cin.ignore();
    getline(std::cin, description);

    item.setDescription(description);
}

void ItemManager::cinItemBrand(Item &item)
{
    std::string brand;

    std::cout << "Ingrese marca:\n";
    std::cin.ignore();
    getline(std::cin, brand);

    item.setBrand(brand);
}

void ItemManager::cinItemModel(Item &item)
{
    std::string model;

    std::cout << "Ingrese modelo:\n";
    std::cin.ignore();
    getline(std::cin, model);

    item.setModel(model);
}

void ItemManager::cinItemPrice(Item &item)
{
    double price;

    std::cout << "Ingrese valor unitario:\n";
    std::cin >> price;

    item.setPrice(price);
}

void ItemManager::cinItemStock(Item &item)
{
    int stock;

    std::cout << "Ingrese el stock:\n";
    stock = _terminal.validateInt(0);

    item.setStock(stock);
}

void ItemManager::cinItemIncome(Item &item)
{
    Date date;
    int d, m, a;

    std::cout << "Ingrese fecha de ingreso:\n\n";
    std::cout << "Ingrese dia:\n";
    d = _terminal.validateInt(1, 31);

    std::cout << "Ingrese mes:\n";
    m = _terminal.validateInt(1,12);

    std::cout << "Ingrese anio:\n";
    a = _terminal.validateInt(1900,2023);

    date.setDay(d);
    date.setMonth(m);
    date.setYear(a);

    item.setIncome(date);

}

void ItemManager::cinItemIsActive(Item &item)
{
    if (item.getIsActive()) {
        item.setIsActive(false);
        std::cout << "El proveedor ha sido dado de baja.\n";
        _terminal.pause();
    } else {
        item.setIsActive(true);
        std::cout << "El proveedor ha sido reincorporado.\n";
        _terminal.pause();
    }
}

int ItemManager::generateItemId()
{
    int id = 1;

    if (_item.getId() != 1) {
        id = _item_archive.getAmountOfRegisters();
    }

    return id + 1;
}

void ItemManager::searchItemById()
{
    int index;
    int id;
    int max_id;

    max_id = _item_archive.getAmountOfRegisters();

    std::cout << "Ingresar ID:\n";
    id = _terminal.validateInt(1, max_id);

    index = _item_archive.getIndex(id);

    printItem(index);

    _terminal.pause();
}

void ItemManager::searchItemByDescription()
{
    int index;
    std::string description;

    std::cout << "Ingresar nombre:\n";
    std::cin.ignore();
    getline(std::cin, description);

    index = _item_archive.getIndex(description);

    printItem(index);
    
    _terminal.pause();
}

void ItemManager::exportItemBackup()
{
     int amount_of_items = _item_archive.getAmountOfRegisters();

    Item * items_array = new Item[amount_of_items];

    if (items_array == NULL) {
        std::cout << "Error de memoria RAM: No se pudo asignar la memoria requerida al exportar backup.";
    } else {
        for (int i = 0; i < amount_of_items; i ++) {
            items_array[i] = _item_archive.read(i);
        }

        _item_backup.createEmptyItemArchive();

        for (int i = 0; i < amount_of_items; i ++) {
            _item_backup.write(items_array[i]);
        }

        delete [] items_array;

        std::cout << "Backup exportado correctamente.\n";
        _terminal.pause();
    }
}

void ItemManager::importItemBackuo()
{
     std::cout << "¿Desea reemplazar los Items actuales por aquellos que haya en el archivo de respaldo? [S/N]\n";

    if (_terminal.validateBool() == false) {
        std::cout << "Importación abortada por el usuario.\n";
    } else {
        int amount_of_items = _item_backup.getAmountOfRegisters();

        Item * items_array = new Item[amount_of_items];

        if (items_array == NULL) {
            std::cout << "Error de memoria RAM: No se pudo asignar la memoria requerida al importar backup.";
        } else {
            for (int i = 0; i < amount_of_items; i ++) {
                items_array[i] = _item_backup.read(i);
            }

            _item_archive.createEmptyItemArchive();

            for (int i = 0; i < amount_of_items; i ++) {
                _item_archive.write(items_array[i]);
            }

            delete [] items_array;
            std::cout << "Backup importado correctamente.\n";
            _terminal.pause();
        }
    }
}
