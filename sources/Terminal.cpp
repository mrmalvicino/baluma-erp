#include "../headers/Terminal.h"

void Terminal::clear(){
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

void Terminal::pause(){
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