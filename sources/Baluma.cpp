#include "../headers/Baluma.h"

void Baluma::run() {
    _terminal.configureUTF8();

    int selection = 1;

    do {
        _terminal.clear();
        _terminal.printLine();
        _terminal.centerAndPrint("BALUMA ERP");
        _terminal.printLine();
        std::cout << "(1) CLIENTES\n";
        std::cout << "(2) PROVEEDORES\n";
        std::cout << "(3) INVENTARIO\n";
        std::cout << "(4) CONTABILIDAD\n";
        std::cout << "(5) RECURSOS HUMANOS\n";
        std::cout << "(6) PRESUPUESTOS\n";
        _terminal.printLine();
        std::cout << "(7) ACERCA DE BALUMA ERP\n";
        std::cout << "(0) SALIR\n";

        selection = _terminal.validateInt(0, 7);

        switch (selection) {
            case 1:
                _clients_manager.displayMenu();
                break;
            case 2:
                _suppliers_manager.displayMenu();
                break;
            case 3:
                _inventory_manager.displayMainMenu();
                break;
            case 4:
                _accounting_manager.displayMainMenu();
                break;
            case 5:
                _employees_manager.displayMenu();
                break;
            case 6:
                
                break;
            case 7:
                about();
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