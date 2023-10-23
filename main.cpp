/** \mainpage Software documentation
 * 
 * \section intro_sec Introduction
 * This document contains the information necessary to either use the compiled software or contribute developing the software.
 * 
 * \section run_sec Run from terminal
 * Navigate using the @c cd command to reach the software's directory and then run one of the following commands depending on your OS.
 * 
 * Windows users:
 * @code{.shell}
 * .\bin\main.exe
 * @endcode
 * 
 * Linux or MacOS users:
 * @code{.shell}
 * ./bin/main
 * @endcode
 * 
 * This is going to execute the @c main() function that creates an object from the Baluma class which calls the @c run() method.
 */

#include "headers/Baluma.h"

using namespace std;

int main() {
    Baluma baluma;
    baluma.run();

    return 0;
}

/*
BUGS 1, 2, 3 y 4(Maxi: listo)

IMPLEMENTACIÓN 1 (Maxi: listo)

IMPLEMENTACION 2
Habría que hacer un submenú para listar, que en vez de listar todos los registros ofrezca la posibilidad de ver o bien todos o solo los activos, o los inactivos.

IMPLEMENTACION 3
me falta terminar el CSV  para informe de inventario, es rápido pero quiero antes revisar lo otro

IMPLEMENTACIÓN 4 (Maxi: listo)
*/