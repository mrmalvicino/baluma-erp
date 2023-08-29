#include "../headers/functions.h"

void mainMenu(){
    int selection = 1;

    do{
        std::cout << "\n(1) PRESUPUSTOS\n";
        std::cout << "(2) VENTAS & CLIENTES\n";
        std::cout << "(3) STOCK & INVENTARIO\n";
        std::cout << "(4) COMPRAS & PROVEEDORES\n";
        std::cout << "(5) CONTABILIDAD\n";
        std::cout << "(6) RECURSOS HUMANOS\n";
        std::cout << "-------------------------\n";
        std::cout << "(7) INICIAR SESIÓN\n";
        std::cout << "-------------------------\n";
        std::cout << "(0) SALIR\n";

        std::cin >> selection;

        switch(selection){
            case 1:
                
                break;
            case 2:
                
                break;
            case 3:
                
                break;
            case 4:
                
                break;
            case 5:
                
                break;
            case 6:
                
                break;
            case 7:
                
                break;
        }
    } while(selection != 0);
}