#include "../headers/AccountsManager.h"

AccountsManager::AccountsManager() {
    _Account_backup.setPath("registers/Accounts.bkp");
}

void AccountsManager::displayMenu() {
    int selection = 1;

    do {
        _terminal.clear();
        _terminal.displayMenuHeader("CUENTAS");
        std::cout << "(1) AGREGAR CUENTA\n";
        std::cout << "(2) EDITAR CUENTA\n";
        std::cout << "(3) BUSCAR CUENTA\n";
        std::cout << "(4) LISTAR CUENTAS\n";
        _terminal.displayMenuFooter();
        selection = _terminal.validateInt(0, 4);

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
                listAccounts();
                break;
        }
    } while (selection != 0);
}

bool AccountsManager::addAccount() {
    bool successful_write;
    bool user_wants_to_save;

    _terminal.clear();
    _terminal.displayMenuHeader("AGREGAR CUENTA");

    _Account.setId(generateAccountId());

    cinAccountNumber(_Account);
    cinAccountActive(_Account);
    cinAccountPassive(_Account); 
    cinAccountName(_Account);
    cinAccountConcept(_Account);  

    std::cout << "¿Desea guardar un nuevo registro con los datos ingresados? [S/N]\n";
    user_wants_to_save = _terminal.validateBool();

    if (user_wants_to_save == true) {
        successful_write = _Account_archive.write(_Account);
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

bool AccountsManager::editAccount() {
    _terminal.clear();

    searchAccount();

    if (_Account.getId() == -1) {
        return false;
    }

    int selection = 1;

    do {
        _terminal.clear();
        _terminal.displayMenuHeader("EDITAR CUENTA");
        _terminal.centerAndPrint(_Account.getAccountName());
        std::cout << "\n";
        std::cout << "(1) EDITAR NUMERO\n";
        std::cout << "(2) EDITAR ACTIVO\n";
        std::cout << "(3) EDITAR PASIVO\n";
        std::cout << "(4) EDITAR NOMBRE\n";
        std::cout << "(5) EDITAR CONCEPTO\n";
        std::cout << "(6) DAR DE BAJA\n";
        _terminal.displayMenuFooter();

        selection = _terminal.validateInt(0, 6);

        switch (selection) {
            case 1:
                cinAccountNumber(_Account);
                break;
            case 2:
                cinAccountActive(_Account);
                break;
            case 3:
                cinAccountPassive(_Account);
                break;
            case 4:
                cinAccountName(_Account);
                break;
            case 5:
                cinAccountConcept(_Account);
                break;
            case 6:
                cinAccountIsActive(_Account);
                break;
        }
    } while (selection != 0);

    int index = _Account_archive.getIndex(_Account.getId());
    bool successful_write = _Account_archive.overWrite(_Account, index);

    return successful_write;
}

void AccountsManager::searchAccount() {
    _terminal.clear();

    int selection;

    _terminal.displayMenuHeader("BUSCAR CUENTA");
    std::cout << "(1) BUSCAR POR ID\n";
    std::cout << "(2) BUSCAR POR NOMBRE\n";
    _terminal.displayMenuFooter();

    selection = _terminal.validateInt(0, 2);

    switch (selection) {
        case 1:
            searchAccountById();
            break;
        case 2:
            searchAccountByName();
            break;
    }
}

void AccountsManager::listAccounts() {
    _terminal.clear();

    int amount_of_Accounts = _Account_archive.getAmountOfRegisters();

    _terminal.displayMenuHeader("LISTADO DE CUENTAS");

    for (int i = 0; i < amount_of_Accounts; i ++) {
        printAccount(i);
    }

    _terminal.pause();
    _terminal.clear();
}

void AccountsManager::printAccount(int index) {
    _Account = _Account_archive.read(index);
    _terminal.displayMenuHeader(_Account.getAccountName());
    std::cout << "NUMERO: " << _Account.getAccountNumber()<<"\n";
    std::cout << "ACTIVO: " << _Account.getActive()<<"\n";
    std::cout << "PASIVO: " << _Account.getPassive()<<"\n";
    std::cout << "BALANCE: " << _Account.getBalance()<<"\n";
    std::cout << "CONCEPTO: " << _Account.getConcept()<<"\n";
    _terminal.printBool(_Account.getIsActive(), "ESTADO: Activa\n\n", "ESTADO: Dada de baja\n\n");
}

void AccountsManager::cinAccountNumber(Account & Account) {
    int number;
    std::cout << "Ingresar número de cuenta:\n";
    number = _terminal.validateInt(0);
    Account.setAccountNumber(number);
}

void AccountsManager::cinAccountActive(Account & Account) {
    double active;
    std::cout << "Ingresar activo:\n";
    active = _terminal.validateInt(0);
    Account.setActive(active);
}

void AccountsManager::cinAccountPassive(Account & Account) {
    double passive;
    std::cout << "Ingresar pasivo:\n";
    passive = _terminal.validateInt(0);
    Account.setPassive(passive);
}


void AccountsManager::cinAccountName(Account & Account) {
    std::string name;
    std::cin.ignore();
    std::cout << "Ingresar nombre:\n";
    getline(std::cin, name);
    Account.setAccountName(name);
}

void AccountsManager::cinAccountIsActive(Account & Account) {
    if (Account.getIsActive()) {
        Account.setIsActive(false);
        std::cout << "La cuenta ha sido dado de baja.\n";
        _terminal.pause();
    } else {
        Account.setIsActive(true);
        std::cout << "La cuenta ha sido dada de alta.\n";
        _terminal.pause();
    }
}

void AccountsManager::cinAccountConcept(Account & Account) {
    std::string concept;
    std::cin.ignore();
    std::cout << "Ingresar concepto:\n";
    getline(std::cin, concept);
    Account.setConcept(concept);
}

int AccountsManager::generateAccountId() {
    int id = 1;

    if(_Account_archive.getAmountOfRegisters() != 0) {
        id = _Account_archive.getAmountOfRegisters() + 1;
    }

    return id;
}

void AccountsManager::searchAccountById() {
    int index;
    int id;
    int max_id;

    max_id = _Account_archive.getAmountOfRegisters();

    std::cout << "Ingresar ID o 0 para cancelar:\n";
    id = _terminal.validateInt(0, max_id);

    if (0 < id) {
        index = _Account_archive.getIndex(id);
        printAccount(index);
    } else {
        _Account.setId(-1);
        std::cout << "Búsqueda abortada por el usuario.\n";
    }

    _terminal.pause();
}

void AccountsManager::searchAccountByName() {
    int index;
    std::string name;

    std::cout << "Ingresar nombre:\n";
    std::cin.ignore();
    getline(std::cin, name);

    index = _Account_archive.getIndex(name);

    while (index == -1) {
        std::cout << "No se encontró el registro " << name << ". Ingrese el nombre nuevamente o ingrese 0 para cancelar.\n";
        getline(std::cin, name);

        if (name == "0") {
            index = -2;
        } else {
            index = _Account_archive.getIndex(name);
        }
    }

    if (0 <= index) {
        printAccount(index);
    } else {
        _Account.setId(-1);
        std::cout << "Búsqueda abortada por el usuario.\n";
    }

    _terminal.pause();
}

void AccountsManager::exportAccountsBackup() {
    int amount_of_Accounts = _Account_archive.getAmountOfRegisters();

    Account * Accounts_array = new Account[amount_of_Accounts];

    if (Accounts_array == NULL) {
        std::cout << "Error de memoria RAM: No se pudo asignar la memoria requerida al exportar backup.";
    } else {
        for (int i = 0; i < amount_of_Accounts; i ++) {
            Accounts_array[i] = _Account_archive.read(i);
        }

        _Account_backup.createEmptyArchive();

        for (int i = 0; i < amount_of_Accounts; i ++) {
            _Account_backup.write(Accounts_array[i]);
        }

        delete [] Accounts_array;

        std::cout << "Backup exportado correctamente.\n";
        _terminal.pause();
    }
}

void AccountsManager::importAccountsBackup() {
    std::cout << "¿Desea reemplazar las cuentas actuales por aquellas que haya en el archivo de respaldo? [S/N]\n";

    if (_terminal.validateBool() == false) {
        std::cout << "Importación abortada por el usuario.\n";
    } else {
        int amount_of_Accounts = _Account_backup.getAmountOfRegisters();

        Account * Accounts_array = new Account[amount_of_Accounts];

        if (Accounts_array == NULL) {
            std::cout << "Error de memoria RAM: No se pudo asignar la memoria requerida al importar backup.";
        } else {
            for (int i = 0; i < amount_of_Accounts; i ++) {
                Accounts_array[i] = _Account_backup.read(i);
            }

            _Account_archive.createEmptyArchive();

            for (int i = 0; i < amount_of_Accounts; i ++) {
                _Account_archive.write(Accounts_array[i]);
            }

            delete [] Accounts_array;
            std::cout << "Backup importado correctamente.\n";
            _terminal.pause();
        }
    }
}
/*
void AccountsManager::exportAccountsCSV() {
    _Account_csv.writeAccountsCSV(_Account, _Account_archive);
}
 
void AccountsManager::importAccountsCSV() {
    std::cout << "¿Desea reemplazar los Accountes actuales por aquellos que haya en el archivo CSV? [S/N]\n";

    if (_terminal.validateBool() == false) {
        std::cout << "Importación abortada por el usuario.\n";
    } else {
        _Account_csv.readAccountsCSV(_Account, _Account_archive);
    }
}
*/