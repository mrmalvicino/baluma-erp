#include "../headers/AccountsManager.h"

AccountsManager::AccountsManager() {
    _accounts_backup.setPath("registers/accounts.bkp");
}

int AccountsManager::getAmountOfAccounts() {
    _amount_of_accounts = _accounts_archive.getAmountOfRegisters();
    return _amount_of_accounts;
}

int AccountsManager::getAccountType() {
    return _account.getType();
}

int AccountsManager::getAccountId() {
    return _account.getId();
}

void AccountsManager::updatePassive(double passive) {
    _account.setPassive(_account.getPassive() + passive);
}

double AccountsManager::getPassive() {
    return _account.getPassive();
}

void AccountsManager::updateActive(double active) {
    _account.setActive(_account.getActive() + active);
}

double AccountsManager::getActive() {
    return _account.getActive();
}

void AccountsManager::displayMenu() {
    int selection = 1;

    do {
        _terminal.clear();
        _terminal.displayMenuHeader("CUENTAS");
        std::cout << "(1) AGREGAR CUENTA\n";
        std::cout << "(2) EDITAR CUENTA\n";
        std::cout << "(3) BUSCAR CUENTA\n";
        std::cout << "(4) VER LISTADO\n";
        _terminal.printLine();
        std::cout << "(5) EXPORTAR BACKUP\n";
        std::cout << "(6) IMPORTAR BACKUP\n";
        _terminal.displayMenuFooter();

        selection = _terminal.validateInt(0, 6);

        switch (selection) {
            case 1:
                addAccount();
                break;
            case 2:
                editAccount();
                break;
            case 3:
                searchAccount();
                break;
            case 4:
                listAccountsMenu();
                break;
            case 5:
                exportAccountsBackup();
                break;
            case 6:
                importAccountsBackup();
                break;
        }
    } while (selection != 0);
}

bool AccountsManager::addAccount() {
    bool successful_write;
    bool user_wants_to_save;

    _terminal.clear();
    _terminal.displayMenuHeader("AGREGAR CUENTA");

    _account.setId(generateAccountId());

    cinAccountName(true);
    cinAccountConcept();
    cinAccountBalance();

    std::cout << "¿Desea guardar un nuevo registro con los datos ingresados? [S/N]\n";
    user_wants_to_save = _terminal.validateBool();

    if (user_wants_to_save == true) {
        successful_write = _accounts_archive.write(_account);
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

bool AccountsManager::addAccount(int id, std::string name, int type, double initial_balance) {
    _account.setId(id);
    _account.setName(name);
    _account.setType(type);
    _account.setBalance(initial_balance);

    bool successful_write = _accounts_archive.write(_account);

    return successful_write;
}

bool AccountsManager::editAccount() {
    _terminal.clear();

    int search_rtn = searchAccount();

    if (search_rtn == -1) {
        return false;
    }

    int selection = 1;

    do {
        _terminal.clear();
        _terminal.displayMenuHeader("EDITAR CUENTA");
        _terminal.centerAndPrint(_account.getName());
        std::cout << "\n";
        std::cout << "(1) EDITAR NOMBRE\n";
        std::cout << "(2) EDITAR CONCEPTO\n";
        std::cout << "(3) EDITAR TIPO\n";
        std::cout << "(4) DAR DE BAJA O REINCORPORAR\n";
        _terminal.displayMenuFooter();

        selection = _terminal.validateInt(0, 4);

        switch (selection) {
            case 1:
                cinAccountName(true);
                break;
            case 2:
                cinAccountConcept(true);
                break;
            case 3:
                cinAccountType();
                break;
            case 4:
                cinAccountStatus();
                break;
        }
    } while (selection != 0);

    bool successful_write = updateAccount();

    return successful_write;
}

bool AccountsManager::updateAccount() {
    int index = _accounts_archive.getIndex(_account.getId());
    bool successful_write = _accounts_archive.overWrite(_account, index);

    return successful_write;
}

int AccountsManager::searchAccount() {
    _terminal.clear();

    int search_rtn = 0;
    int selection = 1;

    _terminal.displayMenuHeader("BUSCAR CUENTA");
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
            search_rtn = searchAccountById();
            break;
        case 2:
            search_rtn = searchAccountByName();
            break;
    }

    return search_rtn;
}

int AccountsManager::searchAccountById() {
    int search_rtn = 0;
    int index;
    int id;
    int max_id;

    max_id = _accounts_archive.getAmountOfRegisters();

    std::cout << "Ingresar ID o 0 para cancelar:\n";
    id = _terminal.validateInt(0, max_id);

    if (0 < id) {
        index = _accounts_archive.getIndex(id);
        loadAccount(index);
        printAccount();
    } else {
        search_rtn = -1;
        std::cout << "Búsqueda abortada por el usuario.\n";
    }

    _terminal.pause();

    return search_rtn;
}

int AccountsManager::searchAccountByName() {
    int search_rtn = 0;
    int index;
    std::string name;

    std::cout << "Ingresar nombre:\n";
    std::cin.ignore();
    getline(std::cin, name);

    index = _accounts_archive.getIndex(name);

    while (index == -1) {
        std::cout << "No se encontró el registro " << name << ". Ingrese el nombre nuevamente o ingrese 0 para cancelar.\n";
        getline(std::cin, name);

        if (name == "0") {
            index = -2;
        } else {
            index = _accounts_archive.getIndex(name); // Esta función retorna -1 si no encuentra un registro válido
        }
    }

    if (0 <= index) {
        loadAccount(index);
        printAccount();
    } else {
        search_rtn = -1;
        std::cout << "Búsqueda abortada por el usuario.\n";
    }

    _terminal.pause();

    return search_rtn;
}

void AccountsManager::listAccountsMenu() {
    _terminal.clear();

    int selection = 1;

    _terminal.displayMenuHeader("LISTAR CUENTAS");
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
            listAccounts(true, true);
            break;
        case 2:
            listAccounts(true, false);
            break;
        case 3:
            listAccounts(false, true);
            break;
    }
}

void AccountsManager::listAccounts(bool list_actives, bool list_inactives) {
    _terminal.clear();

    int amount_of_accounts = _accounts_archive.getAmountOfRegisters();

    _terminal.displayMenuHeader("LISTADO DE CUENTAS");

    for (int i = 0; i < amount_of_accounts; i ++) {
        loadAccount(i);

        if ( (_account.getStatus() == true && list_actives == true) || (_account.getStatus() == false && list_inactives == true) ) {
            printAccount();
        }
    }

    _terminal.pause();
    _terminal.clear();
}

void AccountsManager::loadAccount(int index) {
    _account = _accounts_archive.read(index);
}

void AccountsManager::printAccount() {
    _terminal.displayMenuHeader(_account.getName());
    std::cout << "# ID: " << _account.getId() << "\n";
    std::cout << "Concepto: " << _account.getConcept() << "\n";
    std::cout << "Pasivo: " << _account.getPassive() << "\n";
    std::cout << "Activo: " << _account.getActive() << "\n";
    std::cout << "Balance: " << _account.getBalance() << "\n";
    std::cout << "Tipo: " << _account.getType() << "\n";
    std::cout << "Fecha de creación: " << _account.getCreationDate().toString() << "\n";
    _terminal.printBool(_account.getStatus(), "Estado: Activo\n\n", "Estado: Dado de baja\n\n");
}

int AccountsManager::generateAccountId() {
    int id = 1;

    if (_accounts_archive.getAmountOfRegisters() != 0) {
        id = _accounts_archive.getAmountOfRegisters() + 1;
    }

    return id;
}

void AccountsManager::exportAccountsBackup() {
    int amount_of_accounts = _accounts_archive.getAmountOfRegisters();

    Account * accounts_array = new Account[amount_of_accounts];

    if (accounts_array == NULL) {
        std::cout << "Error de memoria RAM: No se pudo asignar la memoria requerida al exportar backup.";
    } else {
        for (int i = 0; i < amount_of_accounts; i ++) {
            accounts_array[i] = _accounts_archive.read(i);
        }

        _accounts_backup.createEmptyArchive();

        for (int i = 0; i < amount_of_accounts; i ++) {
            _accounts_backup.write(accounts_array[i]);
        }

        delete [] accounts_array;

        std::cout << "Backup exportado correctamente.\n";
        _terminal.pause();
    }
}

void AccountsManager::importAccountsBackup() {
    std::cout << "¿Desea reemplazar los cuentas actuales por aquellos que haya en el archivo de respaldo? [S/N]\n";

    if (_terminal.validateBool() == false) {
        std::cout << "Importación abortada por el usuario.\n";
    } else {
        int amount_of_accounts = _accounts_backup.getAmountOfRegisters();

        Account * accounts_array = new Account[amount_of_accounts];

        if (accounts_array == NULL) {
            std::cout << "Error de memoria RAM: No se pudo asignar la memoria requerida al importar backup.";
        } else {
            for (int i = 0; i < amount_of_accounts; i ++) {
                accounts_array[i] = _accounts_backup.read(i);
            }

            _accounts_archive.createEmptyArchive();

            for (int i = 0; i < amount_of_accounts; i ++) {
                _accounts_archive.write(accounts_array[i]);
            }

            delete [] accounts_array;
            std::cout << "Backup importado correctamente.\n";
            _terminal.pause();
        }
    }
}

void AccountsManager::cinAccountName(bool cin_ignore) {
    std::string name;

    if (cin_ignore == true) {
        std::cin.ignore();
    }

    std::cout << "Ingresar nombre de la cuenta:\n";
    getline(std::cin, name);

    _account.setName(name);
}

void AccountsManager::cinAccountConcept(bool cin_ignore) {
    std::string concept;

    if (cin_ignore == true) {
        std::cin.ignore();
    }

    std::cout << "Ingresar concepto:\n";
    getline(std::cin, concept);

    _account.setConcept(concept);
}

void AccountsManager::cinAccountBalance() {
    double balance;

    std::cout << "Ingresar saldo inicial:\n";
    std::cin >> balance;

    _account.setBalance(balance);
}

void AccountsManager::cinAccountType() {
    int type;

    std::cout << "Ingresar tipo de cuenta:\n";
    std::cin >> type;

    _account.setType(type);
}

void AccountsManager::cinAccountStatus() {
    if (_account.getStatus()) {
        _account.setStatus(false);
        std::cout << "El cuenta ha sido dado de baja.\n";
        _terminal.pause();
    } else {
        _account.setStatus(true);
        std::cout << "El cuenta ha sido reincorporado.\n";
        _terminal.pause();
    }
}