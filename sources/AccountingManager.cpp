#include "../headers/AccountingManager.h"

int AccountingManager::getAmountOfTransactions(){
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
    bool successful_write_acoount;
    bool successful_write_transaction;

    _inventory_manager.loadItemsMenu(false); // Carga el _warehouse
    int search_rtn = _inventory_manager.searchItem(); // Carga el _item
    int initial_stock = _inventory_manager.getItemStock();

    if (search_rtn == -1) {
        return false;
    }

    _terminal.clear();
    _inventory_manager.cinItemStock(false); // Modifica el stock del _item

    int final_stock = _inventory_manager.getItemStock();
    int amount = final_stock - initial_stock; // Determina la cantidad ingresada por el usuario
    std::cout << amount << std::endl;
    _terminal.pause();
    double value = _inventory_manager.getItemPrice();
    std::cout << "TOTAL: "<<value * amount<<".\n";

    Transaction transaction;
    transaction.setId(generateTransactionId()); // Agrega transaccion al libro diario
    transaction.setAccountId(2);
    transaction.setDebit(value * amount);
    cinTransactionDescription(transaction, true);
   
    std::cout << "Desea grabar la compra [S/N]?\n";
    bool user_choice = _terminal.validateBool();

    if(user_choice == true)
    {
        successful_write_item = _inventory_manager.updateItem(); // Actualiza stock del item

        _accounts_manager.loadAccount(1);
        _accounts_manager.updateCredit( amount * value); // Actualiza pasivo de proveedores
        successful_write_acoount = _accounts_manager.updateAccount();
    
        _accounts_manager.loadAccount(2);
        _accounts_manager.updateCredit(amount * value); // Actualiza pasivo de caja
        successful_write_acoount = _accounts_manager.updateAccount();

        successful_write_transaction = _transactions_archive.write(transaction); // Guarda la Transaccion creada.

        if(successful_write_item && successful_write_acoount && successful_write_transaction) // Verifica que hayan podido escribirse los cambios
        {
            std::cout << "Compra Registrada.\n";
            successful_changes = true;
        } else {

            std::cerr << "Error de grabado\n";
        }
    } else
    {
        std::cout << "Compra abortada por el usuario.\n";
    }

    _terminal.pause();

    return successful_changes;
}

bool AccountingManager::sell() {
    bool successful_changes = false;
    bool successful_write_item;
    bool successful_write_acoount;
    bool successful_write_transaction;

    _inventory_manager.loadItemsMenu(false); // Carga el _warehouse
    int search_rtn = _inventory_manager.searchItem(); // Carga el _item
    int initial_stock = _inventory_manager.getItemStock();

    if (search_rtn == -1) {
        return false;
    }

    _terminal.clear();
    _inventory_manager.cinItemStock(true); // Modifica el stock del _item

    int final_stock = _inventory_manager.getItemStock();
    int amount = initial_stock - final_stock; // Determina la cantidad ingresada por el usuario

    double value = _inventory_manager.getItemPrice();
    std::cout << "TOTAL: "<<value * amount<<".\n";

    Transaction transaction; 

    transaction.setId(generateTransactionId()); // Agrega transaccion al libro diario
    transaction.setAccountId(1);
    transaction.setCredit(value * amount);
    cinTransactionDescription(transaction, true);

    std::cout << "Desea grabar la compra [S/N]?\n";
    bool user_choice = _terminal.validateBool();

    if(user_choice == true)
    {
        successful_write_item = _inventory_manager.updateItem(); // Actualiza stock del item

        _accounts_manager.loadAccount(0);
        _accounts_manager.updateDebit( amount * value); // Actualiza pasivo de proveedores
        successful_write_acoount = _accounts_manager.updateAccount();
    
        _accounts_manager.loadAccount(2);
        _accounts_manager.updateDebit(amount * value); // Actualiza pasivo de caja
        successful_write_acoount = _accounts_manager.updateAccount();

        successful_write_transaction = _transactions_archive.write(transaction); // Guarda la Transaccion creada.

        if(successful_write_item && successful_write_acoount && successful_write_transaction) // Verifica que hayan podido escribirse los cambios
        {
            std::cout << "Compra Registrada.\n";
            successful_changes = true;
        } else {

            std::cerr << "Error de grabado\n";
        }
    } else
    {
        std::cout << "Compra abortada por el usuario.\n";
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

void AccountingManager::cinAccountId(Transaction & transaction) {
    int account_id;

    std::cout << "Ingresar el número de cuenta:\n";
    std::cin >> account_id;

    transaction.setAccountId(account_id);
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