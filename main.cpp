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

int main() {
    Baluma baluma;
    baluma.run();

    return 0;
}