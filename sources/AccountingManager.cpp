#include "../headers/AccountingManager.h"

int AccountingManager::getAmountOfTransactions() {
    _amount_of_transactions = _transactions_archive.getAmountOfRegisters();
    return _amount_of_transactions;
}

void AccountingManager::displayMainMenu() {
    int selection = 1;

    do {
        _terminal.clear();
        _terminal.displayMenuHeader("CONTABILIDAD");
        std::cout << "(1) ADMINISTRAR CUENTAS\n";
        std::cout << "(2) MOSTRAR LIBRO DIARIO\n";
        _terminal.printLine();
        std::cout << "(3) REGISTRAR COMPRA\n";
        std::cout << "(4) REGISTRAR VENTA\n";
        _terminal.displayMenuFooter();

        selection = _terminal.validateInt(0, 4);

        switch (selection) {
            case 1:
                _accounts_manager.displayMenu();
                break;
            case 2:
                showJournal();
                break;
            case 3:
                buy();
                break;
            case 4:
                sell();
                break;
        }
    } while (selection != 0);
}

bool AccountingManager::buy() {
    bool successful_changes = false;
    bool successful_write_item;
    bool successful_write_account;
    bool successful_write_transaction;
    int search_rtn = 0;

    search_rtn = _inventory_manager.loadItemsMenu(false); // Usuario selecciona en qué _warehouse se va a stockiar el item a comprar

    if (search_rtn == -1) {
        return false;
    }

    search_rtn = _inventory_manager.searchItem(); // Usuario selecciona qué _item se va a comprar

    if (search_rtn == -1) {
        return false;
    }

    int initial_stock = _inventory_manager.getItemStock();

    _terminal.clear();
    _inventory_manager.cinItemStock(false); // Usuario ingresa cantidad y se modifica el stock del _item

    int final_stock = _inventory_manager.getItemStock();
    int amount = final_stock - initial_stock; // Determina la cantidad ingresada por el usuario

    double value = _inventory_manager.getItemPrice();

    // Carga los datos en el objeto _transaction
    _transaction.reset();
    _transaction.setId(generateTransactionId());
    _transaction.setAccountId(2);
    _transaction.setDebit(value * amount);
    cinTransactionDescription(_transaction, true);

    std::cout << "¿Desea agregar la compra con los datos ingresados? [S/N]\n";
    bool user_wants_to_save = _terminal.validateBool();

    if(user_wants_to_save == true) {
        successful_write_item = _inventory_manager.updateItem(); // Actualiza stock del item

        // Actualiza pasivo de proveedores
        _accounts_manager.loadAccount(1);
        _accounts_manager.updateCredit(amount * value);
        successful_write_account = _accounts_manager.updateAccount();

        // Actualiza pasivo de caja
        _accounts_manager.loadAccount(2);
        _accounts_manager.updateCredit(amount * value);
        successful_write_account = _accounts_manager.updateAccount();

        successful_write_transaction = _transactions_archive.write(_transaction); // Agrega transaccion al libro diario

        if(successful_write_item && successful_write_account && successful_write_transaction) { // Verifica que se hayan podido escribir los cambios
            std::cout << "Compra registrada satisfactoriamente.\n";
            successful_changes = true;
        } else {
            std::cerr << "Error de grabado.\n";
        }
    } else {
        std::cout << "Compra abortada por el usuario.\n";
    }

    _terminal.pause();

    return successful_changes;
}

bool AccountingManager::sell() {
    bool successful_changes = false;
    bool successful_write_item;
    bool successful_write_account;
    bool successful_write_transaction;
    int search_rtn = 0;

    search_rtn = _inventory_manager.loadItemsMenu(false); // Usuario selecciona en qué _warehouse se va a stockiar el item a vender

    if (search_rtn == -1) {
        return false;
    }

    search_rtn = _inventory_manager.searchItem(); // Usuario selecciona qué _item se va a vender

    if (search_rtn == -1) {
        return false;
    }

    int initial_stock = _inventory_manager.getItemStock();

    _terminal.clear();
    _inventory_manager.cinItemStock(true); // Usuario ingresa cantidad y se modifica el stock del _item

    int final_stock = _inventory_manager.getItemStock();
    int amount = initial_stock - final_stock; // Determina la cantidad ingresada por el usuario

    double value = _inventory_manager.getItemPrice();

    // Carga los datos en el objeto _transaction
    _transaction.reset();
    _transaction.setId(generateTransactionId());
    _transaction.setAccountId(1);
    _transaction.setCredit(value * amount);
    cinTransactionDescription(_transaction, true);

    std::cout << "Desea grabar la compra [S/N]?\n";
    bool user_wants_to_save = _terminal.validateBool();

    if(user_wants_to_save == true) {
        successful_write_item = _inventory_manager.updateItem(); // Actualiza stock del item

        // Actualiza pasivo de clientes
        _accounts_manager.loadAccount(0);
        _accounts_manager.updateDebit( amount * value);
        successful_write_account = _accounts_manager.updateAccount();

        // Actualiza pasivo de caja
        _accounts_manager.loadAccount(2);
        _accounts_manager.updateDebit(amount * value);
        successful_write_account = _accounts_manager.updateAccount();

        successful_write_transaction = _transactions_archive.write(_transaction); // Agrega transaccion al libro diario

        if(successful_write_item && successful_write_account && successful_write_transaction) { // Verifica que se hayan podido escribir los cambios
            std::cout << "Venta registrada satisfactoriamente.\n";
            successful_changes = true;
        } else {
            std::cerr << "Error de grabado.\n";
        }
    } else {
        std::cout << "Venta abortada por el usuario.\n";
    }

    _terminal.pause();

    return successful_changes;
}

void AccountingManager::loadTransaction(int index) {
    _transaction = _transactions_archive.read(index);
}

void AccountingManager::printTransaction() {
    std::cout << _transaction.getId() << "\t";
    std::cout << _transaction.getDateTime().toString() << "\t";
    std::cout << _transaction.getAccountId() << "\t";
    std::cout << _terminal.fill(_transaction.getDescription(), 30) << "\t";
    std::cout << _transaction.getDebit() << "\t";
    std::cout << _transaction.getCredit();
}

void AccountingManager::showJournal() {
    _terminal.clear();
    std::cout << "# ID\t" << _terminal.fill("Fecha y hora", 18) << "\t# Cta.\t" << _terminal.fill("Descripción", 30) << "\tDebe\tHaber\n";

    for (int i = 0; i < getAmountOfTransactions(); i ++) {
        loadTransaction(i);
        printTransaction();
        std::cout << "\n";
    }

    _terminal.pause();
    _terminal.clear();
}

int AccountingManager::generateTransactionId() {
    int id = 1;

    if(_transactions_archive.getAmountOfRegisters() != 0) {
        id = _transactions_archive.getAmountOfRegisters() + 1;
    }

    return id;
}

void AccountingManager::cinTransactionDescription(Transaction & transaction, bool cin_ignore) {
    std::string description;

    if (cin_ignore == true) {
        std::cin.ignore();
    }

    std::cout << "Ingresar descripción de la transacción:\n";
    getline(std::cin, description);

    transaction.setDescription(description);
}