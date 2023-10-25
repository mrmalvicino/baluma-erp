#include "../headers/TransactionsManager.h"

TransactionsManager::TransactionsManager() {
    _transactions_backup.setPath("registers/transactions.bkp");
}

void TransactionsManager::displayMenu() {
int selection = 1;

    do {
        _terminal.clear();
        _terminal.displayMenuHeader("VENTAS");
        std::cout << "(1) REALIZAR VENTA\n";
        std::cout << "(2) BUSCAR VENTA\n";
        std::cout << "(3) LISTAR VENTAS\n";
        _terminal.displayMenuFooter();
        std::cout << "(4) EXPORTAR BACKUP\n";
        std::cout << "(5) IMPORTAR BACKUP\n";
        selection = _terminal.validateInt(0, 5);

        switch (selection) {
            case 1:
                loadClients();
                break;
            case 2:
                std::cout << "EN PROCESO\n";
                break;
            case 3:
                std::cout << "EN PROCESO\n";
                break;
            case 4:
                std::cout << "EN PROCESO\n";
                break;
            case 5:
                std::cout << "EN PROCESO\n";
                break;
        }
    } while (selection != 0);
}

void TransactionsManager::loadClients() {
    
    _clients_manager.searchClient();
    
    int selection = 1;

    do {
        _terminal.clear();
        _terminal.displayMenuHeader("VENTA " + _client.getDescription());
        std::cout << "(1) CARGAR FECHA\n";
        std::cout << "(2) MOSTRAR FECHA\n";
        std::cout << "(3) SELECCIONAR ITEM/S\n";
        _terminal.displayMenuFooter();
        selection = _terminal.validateInt(0, 2);

        switch (selection) {
            case 1:
                cinCreationDate(_transaction);
                break;
            case 2:
                std::cout << "FECHA DE DOCUMENTO: " << _transaction.getDocDate().toString() << "\n";
                break;
            case 3:
                std::cout << "EN PROCESO\n";
                break;
        }
    } while (selection != 0);
   
}

int TransactionsManager::generateTransactionId() {
    int id = 1;

    if(_transactions_archive.getAmountOfRegisters() != 0) {
        id = _transactions_archive.getAmountOfRegisters() + 1;
    }

    return id;
}

void TransactionsManager::cinCreationDate(Transaction & transaction) {
    Date date;
    int day, month, year;

    _terminal.clear();
    _terminal.displayMenuHeader("INGRESE FECHA DE DOCUMENTO");

    std::cout << "INGRESAR DIA:\n";
    day = _terminal.validateInt(1, 31);

    std::cout << "INGRESAR MES:\n";
    month = _terminal.validateInt(1,12);

    std::cout << "INGRESAR AÑO:\n";
    year = _terminal.validateInt(1900,2023);

    date.setDay(day);
    date.setMonth(month);
    date.setYear(year);

    transaction.setDocDate(date);
}