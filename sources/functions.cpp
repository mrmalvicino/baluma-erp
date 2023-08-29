#include "../headers/functions.h"

void terminalClear(){
    #ifdef _WIN64
        system("cls");
    #endif

    #ifdef __linux__
        system("clear");
    #endif

    #ifdef __APPLE__
        system("clear");
    #endif
}

void terminalPause(){
    #ifdef _WIN64
        system("pause");
    #endif

    #ifdef __linux__
        int aux = 1;

        do{
            std::cout << "Ingresar 0 para continuar.\n";
            std::cin >> aux;
        } while(aux != 0);
    #endif

    #ifdef __APPLE__
        int aux = 1;

        do{
            std::cout << "\nIngresar 0 para continuar.\n";
            std::cin >> aux;
        } while(aux != 0);
    #endif
}

void mainMenu(){
    int selection = 1;

    do{
        std::cout << "(1) PRESUPUSTOS\n";
        std::cout << "(2) VENTAS & CLIENTES\n";
        std::cout << "(3) STOCK & INVENTARIO\n";
        std::cout << "(4) COMPRAS & PROVEEDORES\n";
        std::cout << "(5) CONTABILIDAD\n";
        std::cout << "(6) RECURSOS HUMANOS\n";
        std::cout << "-------------------------\n";
        std::cout << "(7) INICIAR SESIÓN\n";
        std::cout << "-------------------------\n";
        std::cout << "(8) ACERCA DE BALUMA ERP\n";
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
            case 8:
                about();
                break;
        }
    } while(selection != 0);
    
    terminalClear();
}

void about(){
    terminalClear();
    
    std::cout << "Baluma ERP es un software de gestión empresarial libre y gratuito, distribuido bajo la licencia GNU General Public License. Para más información, visitar https://github.com/mrmalvicino/baluma-erp\n";

    terminalPause();
    terminalClear();
}