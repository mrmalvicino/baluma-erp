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
        std::cout << "(2) REGISTRAR COMPRA\n";
        std::cout << "(3) REGISTRAR VENTA\n";
        std::cout << "(4) MOSTRAR LIBRO DIARIO\n";
        std::cout << "(5) EXPORTAR LIBRO DIARIO A CSV\n";
        _terminal.displayMenuFooter();

        selection = _terminal.validateInt(0, 5);

        switch (selection) {
            case 1:
                _accounts_manager.displayMenu();
                break;
            case 2:
                addTransaction(-1);
                break;
            case 3:
                addTransaction(+1);
                break;
            case 4:
                showJournal();
                break;
            case 5:
                exportTransactionsCSV();
                break;
        }
    } while (selection != 0);
}

bool AccountingManager::addTransaction(int sign) {
    bool successful_write;
    bool user_wants_to_save;
    int absolute_value;

    _terminal.clear();
    _terminal.displayMenuHeader("NUEVA TRANSACCIÓN");

    _transaction.setDebit(0);
    _transaction.setCredit(0);
    _transaction.setId(generateTransactionId());

    cinAccountId(_transaction);
    cinTransactionDescription(_transaction, true);

    std::cout << "Ingresar importe:\n";
    absolute_value = _terminal.validateDouble(0);

    if (0 < sign) {
        _transaction.setCredit(_transaction.getCredit() + absolute_value);
    } else {
        _transaction.setDebit(_transaction.getDebit() + absolute_value);
    }

    std::cout << "¿Desea guardar un nuevo registro con los datos ingresados? [S/N]\n";
    user_wants_to_save = _terminal.validateBool();

    if (user_wants_to_save == true) {
        successful_write = _transactions_archive.write(_transaction);
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

void AccountingManager::loadTransaction(int index) {
    _transaction = _transactions_archive.read(index);
}

void AccountingManager::printTransaction() {
    std::cout << _transaction.getId() << "\t" << _transaction.getDateTime().toString() << "\t" << _transaction.getAccountId() << "\t" << _terminal.fill(_transaction.getDescription(), 30) << "\t" << _transaction.getDebit() << "\t" << _transaction.getCredit();
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

void AccountingManager::exportTransactionsBackup() {
    
}

void AccountingManager::importTransactionsBackup() {
    
}

void AccountingManager::exportTransactionsCSV() {
    
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