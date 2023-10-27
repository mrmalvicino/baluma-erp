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
                addTransaction();
                break;
        }
    } while (selection != 0);
}

bool AccountingManager::addTransaction() {
    bool successful_write;
    bool user_wants_to_save;
    int value;

    _terminal.clear();
    _terminal.displayMenuHeader("NUEVO MOVIMIENTO");

    //agregar balance del libro diario a partir del ultimo saldo
    _transaction.setDebit(0);
    _transaction.setCredit(0);
    _transaction.setId(generateTransactionId());

    cinAccountId(_transaction); // Validar que el ingreso sea solo de numeros de ID existentes
    cinTransactionDescription(_transaction, true);

    // si el tipo de la cuenta es
    //                              1 - cliente ---> va al haber
    //                              2 - proveedor ---> va al debe
    //                              3 - caja ---> puede ir al debe o al haber
    //                              4 - banco ---> puede ir al debe o al haber segun sea deposito o retiro
    //                              5 - gs gr ---> debe

    std::cout << "Ingresar importe:\n";
    value = _terminal.validateDouble();

    if (0 < value) { // con qué lo hago, con un switch? (segun el tipo de cuenta)
        _transaction.setCredit(_transaction.getCredit() + value);
    } else {
        value = - value;
        _transaction.setDebit(_transaction.getDebit() + value);
    }

    std::cout << "¿Desea guardar un nuevo registro con los datos ingresados? [S/N]\n";
    user_wants_to_save = _terminal.validateBool();

    if (user_wants_to_save == true) {
        successful_write = _transactions_archive.write(_transaction);
        if (successful_write == true) {
            std::cout << "Registro guardado correctamente.\n";
            // actualizar activo y pasivo de la cuenta en cuestion
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