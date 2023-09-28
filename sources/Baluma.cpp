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
        std::cout << "(5) VENTAS\n";
        std::cout << "(6) COMPRAS\n";
        std::cout << "(7) PRESUPUESTOS\n";
        std::cout << "(8) RECURSOS HUMANOS\n";
        _terminal.printLine();
        std::cout << "(9) ACERCA DE BALUMA ERP\n";
        std::cout << "(0) SALIR\n";

        std::cin >> selection;

        switch (selection) {
            case 1:
                _clients_manager.displayMenu();
                break;
            case 2:
                _suppliers_manager.displayMenu();
                break;
            case 3:
                _items_manager.displayMainMenu();
                break;
            case 4:
                
                break;
            case 5:
                
                break;
            case 6:
                
                break;
            case 7:
                
                break;
            case 8:
                
                break;
            case 9:
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