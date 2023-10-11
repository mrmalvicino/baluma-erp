#include "../headers/ProductsManager.h"

ProductsManager::ProductsManager() {
    _products_backup.setPath("registers/products.bkp");
}

void ProductsManager::displayMenu() {
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
                listProducts();
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

bool ProductsManager::addProduct() {
    bool successful_write;
    bool user_wants_to_save;

    _terminal.clear();
    _terminal.displayMenuHeader("AGREGAR PRODUCTO");

    _product.setId(generateProductId());

    cinProductName(_product);
    cinProductBrand(_product);
    cinProductModel(_product);
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

bool ProductsManager::editProduct() {
    _terminal.clear();

    searchProduct();

    if (_product.getId() == -1) {
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

        selection = _terminal.validateInt(0, 4);

        switch (selection) {
            case 1:
                cinProductName(_product);
                break;
            case 2:
                cinProductBrand(_product);
                break;
            case 3:
                cinProductModel(_product);
                break;
            case 4:
                cinProductDescription(_product);
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

    return successful_write;
}

void ProductsManager::searchProduct() {
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
            searchProductById();
            break;
        case 2:
            searchProductByNBM();
            break;
    }
}

void ProductsManager::listProducts() {
    _terminal.clear();

    int amount_of_products = _products_archive.getAmountOfRegisters();

    _terminal.displayMenuHeader("LISTADO DE PRODUCTOS");

    for (int i = 0; i < amount_of_products; i ++) {
        printProduct(i);
    }

    _terminal.pause();
    _terminal.clear();
}

void ProductsManager::printProduct(int index) {
    _product = _products_archive.read(index);
    _terminal.displayMenuHeader(_product.toString());
    std::cout << "# ID: " << _product.getId() << "\n";
    std::cout << "Nombre: " << _product.getName() << "\n";
    std::cout << "Marca: " << _product.getBrand() << "\n";
    std::cout << "Modelo: " << _product.getModel() << "\n";
    std::cout << "Descripción: " << _product.getDescription() << "\n";
    std::cout << "Precio unitario: $" << _product.getPrice() << "\n";
    _terminal.printBool(_product.getIsActive(), "Estado: Activo\n\n", "Estado: Dado de baja\n\n");
}

void ProductsManager::cinProductName(Product & product) {
    std::string name;

    std::cout << "Ingrese nombre del producto:\n";
    std::cin.ignore();
    getline(std::cin, name);

    product.setName(name);
}

void ProductsManager::cinProductBrand(Product & product) {
    std::string brand;

    std::cout << "Ingrese marca:\n";
    getline(std::cin, brand);

    product.setBrand(brand);
}

void ProductsManager::cinProductModel(Product & product) {
    std::string model;

    std::cout << "Ingrese modelo:\n";
    getline(std::cin, model);

    product.setModel(model);
}

void ProductsManager::cinProductDescription(Product & product) {
    std::string description;

    std::cout << "Ingrese descripcion:\n";
    getline(std::cin, description);

    product.setDescription(description);
}

void ProductsManager::cinProductPrice(Product & product) {
    double price;

    std::cout << "Ingrese valor unitario:\n";
    std::cin >> price;

    product.setPrice(price);
}

void ProductsManager::cinProductIsActive(Product & product) {
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

int ProductsManager::generateProductId() {
    int id = 1;

    if(_products_archive.getAmountOfRegisters() != 0) {
        id = _products_archive.getAmountOfRegisters() + 1;
    }

    return id;
}

void ProductsManager::searchProductById() {
    int index;
    int id;
    int max_id;

    max_id = _products_archive.getAmountOfRegisters();

    std::cout << "Ingresar ID o 0 para cancelar:\n";
    id = _terminal.validateInt(0, max_id);

    if (0 < id) {
        index = _products_archive.getIndex(id);
        printProduct(index);
    } else {
        _product.setId(-1);
        std::cout << "Búsqueda abortada por el usuario.\n";
    }

    _terminal.pause();
}

void ProductsManager::searchProductByNBM() {
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
        printProduct(index);
    } else {
        _product.setId(-1);
        std::cout << "Búsqueda abortada por el usuario.\n";
    }
    
    _terminal.pause();
}

void ProductsManager::exportProductsBackup() {
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

void ProductsManager::importProductsBackup() {
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