#include "../headers/Baluma.h"

void Baluma::run() {
    int selection = 1;

    do {
        _terminal.clear();
        _terminal.printLine();
        _terminal.centerAndPrint("BALUMA ERP");
        _terminal.printLine();
        std::cout << "(1) PRESUPUSTOS\n";
        std::cout << "(2) VENTAS\n";
        std::cout << "(3) CLIENTES\n";
        std::cout << "(4) INVENTARIO\n";
        std::cout << "(5) COMPRAS\n";
        std::cout << "(6) PROVEEDORES\n";
        std::cout << "(7) CONTABILIDAD\n";
        std::cout << "(8) RECURSOS HUMANOS\n";
        _terminal.printLine();
        std::cout << "(9) ACERCA DE BALUMA ERP\n";
        std::cout << "(0) SALIR\n";

        std::cin >> selection;

        switch (selection) {
            case 1:
                
                break;
            case 2:
                
                break;
            case 3:
                _client_manager.displayMenu();
                break;
            case 4:
                
                break;
            case 5:
                
                break;
            case 6:
                _supplier_manager.displayMenu();
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