#include "../headers/Baluma.h"

void Baluma::run() {
    _terminal.configureUTF8();

    int selection = 1;

    do {
        _terminal.clear();
        _terminal.displayMenuHeader("BALUMA ERP");
        std::cout << "(1) SOCIOS DE NEGOCIO\n";
        std::cout << "(2) INVENTARIO\n";
        std::cout << "(3) CONTABILIDAD\n";
        std::cout << "(4) RECURSOS HUMANOS\n";
        _terminal.printLine();
        std::cout << "(5) ACERCA DE BALUMA ERP\n";
        std::cout << "(0) SALIR\n";

        selection = _terminal.validateInt(0, 5);

        switch (selection) {
            case 1:
                businessPartnersMenu();
                break;
            case 2:
                _inventory_manager.displayMainMenu();
                break;
            case 3:
                _accounting_manager.displayMainMenu();
                break;
            case 4:
                _employees_manager.displayMenu();
                break;
            case 5:
                about();
                break;
        }
    } while (selection != 0);
}

void Baluma::businessPartnersMenu() {
    _terminal.configureUTF8();

    int selection = 1;

    do {
        _terminal.clear();
        _terminal.displayMenuHeader("SOCIOS DE NEGOCIO");
        std::cout << "(1) CLIENTES\n";
        std::cout << "(2) PROVEEDORES\n";
        _terminal.displayMenuFooter();

        selection = _terminal.validateInt(0, 2);

        switch (selection) {
            case 1:
                _clients_manager.displayMenu();
                break;
            case 2:
                _suppliers_manager.displayMenu();
                break;
        }
    } while (selection != 0);
}

void Baluma::about() {
    _terminal.clear();
    std::cout << "Baluma ERP es un software de gestión empresarial libre y gratuito, distribuido bajo la licencia GNU General Public License. Para más información, visitar https://github.com/mrmalvicino/baluma-erp\n";
    _terminal.pause();
    _terminal.clear();
}