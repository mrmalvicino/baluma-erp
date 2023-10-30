#include "../headers/AccountingManager.h"

AccountingManager::AccountingManager() {
    checkAccounts();
}

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
    _transaction.setAccountId(_suppliers_acc_id);
    _transaction.setDebit(value * amount);
    cinTransactionDescription(_transaction, true);

    std::cout << "¿Desea agregar la compra con los datos ingresados? [S/N]\n";
    bool user_wants_to_save = _terminal.validateBool();

    if(user_wants_to_save == true) {
        successful_write_item = _inventory_manager.updateItem(); // Actualiza stock del item

        // Actualiza pasivo de proveedores
        _accounts_manager.loadAccount(_suppliers_acc_id - 1);
        _accounts_manager.updatePassive(amount * value);
        successful_write_account = _accounts_manager.updateAccount();

        // Actualiza pasivo de caja
        _accounts_manager.loadAccount(_cash_acc_id - 1);
        _accounts_manager.updatePassive(amount * value);
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
    _transaction.setAccountId(_clients_acc_id);
    _transaction.setCredit(value * amount);
    cinTransactionDescription(_transaction, true);

    std::cout << "Desea grabar la compra [S/N]?\n";
    bool user_wants_to_save = _terminal.validateBool();

    if(user_wants_to_save == true) {
        successful_write_item = _inventory_manager.updateItem(); // Actualiza stock del item

        // Actualiza pasivo de clientes
        _accounts_manager.loadAccount(_clients_acc_id - 1);
        _accounts_manager.updateActive( amount * value);
        successful_write_account = _accounts_manager.updateAccount();

        // Actualiza pasivo de caja
        _accounts_manager.loadAccount(_cash_acc_id - 1);
        _accounts_manager.updateActive(amount * value);
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

void AccountingManager::checkAccounts() {
    bool successful_write = true;
    int type;
    int id;

    _cash_acc_id = 0;
    _clients_acc_id = 0;
    _suppliers_acc_id = 0;

    for (int i = 0; i < _accounts_manager.getAmountOfAccounts(); i ++) {
        _accounts_manager.loadAccount(i);
        type = _accounts_manager.getAccountType();
        id = _accounts_manager.getAccountId();

        if (type == 1 || type == 2 || type == 3) {
            switch (type) {
            case 1:
                _cash_acc_id = id;
                break;
            case 2:
                _clients_acc_id = id;
                break;
            case 3:
                _suppliers_acc_id = id;
                break;
            }
        }
    }

    int new_id;

    if (_cash_acc_id == 0) {
        std::cout << "Ingresar saldo inicial de la caja:\n";
        double initial_balance = _terminal.validateDouble(0);

        new_id = _accounts_manager.generateAccountId();
        successful_write = _accounts_manager.addAccount(new_id, "Caja", 1, initial_balance);
        _cash_acc_id = new_id;
    }

    if (_clients_acc_id == 0) {
        new_id = _accounts_manager.generateAccountId();
        successful_write = _accounts_manager.addAccount(new_id, "Clientes", 2, 0);
        _clients_acc_id = new_id;
    }

    if (_suppliers_acc_id == 0) {
        new_id = _accounts_manager.generateAccountId();
        successful_write = _accounts_manager.addAccount(new_id, "Proveedores", 3, 0);
        _suppliers_acc_id = new_id;
    }

    if (successful_write == false) {
        std::cout << "No se pudieron crear las cuentas esenciales. Por favor crear cuentas de tipo 1, 2 y 3 para contabilizar la caja, los clientes y los proveedores respectivamente.\n";
    }
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