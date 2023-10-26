#include "../headers/Terminal.h"

Terminal::Terminal() {
    setLineLenght(50);
    setBackCaption("ATRÁS");
}

void Terminal::setLineLenght(int line_lenght) {
    _line_lenght = line_lenght;
}

int Terminal::getLineLenght() {
    return _line_lenght;
}

void Terminal::setBackCaption(std::string back_caption) {
    strcpy(_back_caption, back_caption.c_str());
}

std::string Terminal::getBackCaption() {
    return _back_caption;
}

void Terminal::clear() {
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

void Terminal::pause() {
    #ifdef _WIN64
        system("pause");
    #endif

    #ifdef __linux__
        int aux = 1;

        do{
            std::cout << "Ingresar 0 para continuar.\n";
            std::cin >> aux;
        } while (aux != 0);
    #endif

    #ifdef __APPLE__
        int aux = 1;
        std::cout << "\nIngresar 0 para continuar.\n";

        while (true) {
            if (std::cin >> aux && aux == 0) {
                break;
            } else {
                std::cin.clear();
                cleanBuffer();
                std::cout << "Ingresar 0 para continuar.\n";
            }
        }
    #endif
}

void Terminal::printLine() {
    for (int i = 0; i < getLineLenght(); i ++) {
        std::cout << "-";
    }

    std::cout << "\n";
}

void Terminal::centerAndPrint(std::string text) {
    int blanks = (getLineLenght() - text.length()) / 2;
    
    for (int i = 0; i < blanks; i ++) {
        std::cout << " ";
    }

    std::cout << text;

    for (int i = 0; i < blanks; i ++) {
        std::cout << " ";
    }

    std::cout << "\n";
}

void Terminal::printBackOption() {
    std::cout << "(0) " << getBackCaption() << "\n";
}

void Terminal::displayMenuHeader(std::string title) {
    printLine();
    centerAndPrint(title);
    printLine();
}

void Terminal::displayMenuFooter() {
    printLine();
    printBackOption();
}

void Terminal::printBool(bool parameter, std::string text_if_true, std::string text_if_false) {
    if (parameter == true) {
        std::cout << text_if_true;
    } else {
        std::cout << text_if_false;
    }
}

bool Terminal::validateBool() {
    char input;
    bool rtn;

    while (true) {
        if (std::cin >> input && (input == 'y' || input == 'Y' || input == 's' || input == 'S' || input == 'n' || input == 'N')) {
            break;
        } else {
            std::cin.clear();
            cleanBuffer();
            std::cout << "Error de validación: Ingresar 'S' para confirmar o 'N' para denegar.\n";
        }
    }

    if (input == 'y' || input == 'Y' || input == 's' || input == 'S') {
        rtn = true;
    } else {
        rtn = false;
    }

    return rtn;
}

int Terminal::validateInt() {
    int rtn;
    
    while (true) {
        if (std::cin >> rtn) {
            break;
        } else {
            std::cin.clear();
            cleanBuffer();
            std::cout << "Error de validación: Ingrese un número entero.\n";
        }
    }

    return rtn;
}

int Terminal::validateInt(int min) {
    int rtn;
    
    while (true) {
        if (std::cin >> rtn && min <= rtn) {
            break;
        } else {
            std::cin.clear();
            cleanBuffer();
            std::cout << "Error de validación: Ingrese un número entero mayor o igual a " << min << ".\n";
        }
    }

    return rtn;
}

int Terminal::validateInt(int min, int max) {
    int rtn;
    
    while (true) {
        if (std::cin >> rtn && min <= rtn && rtn <= max) {
            break;
        } else {
            std::cin.clear();
            cleanBuffer();
            if (min < max) {
                std::cout << "Error de validación: Ingrese un número entero mayor (o igual) a " << min << " y menor (o igual) a " << max << ".\n";
            } else if (min == max) {
                std::cout << "Error de validación: El único ingreso válido es " << min << ".\n";
            } else {
                std::cout << "Error de validación: Los extremos están definidos de manera que no haya ingresos válidos.\n";
            }
        }
    }

    return rtn;
}

long long int Terminal::validateLongInt() {
    long long int rtn;
    
    while (true) {
        if (std::cin >> rtn) {
            break;
        } else {
            std::cin.clear();
            cleanBuffer();
            std::cout << "Error de validación: Ingrese un número entero.\n";
        }
    }

    return rtn;
}

long long int Terminal::validateLongInt(int min) {
    long long int rtn;
    
    while (true) {
        if (std::cin >> rtn && min <= rtn) {
            break;
        } else {
            std::cin.clear();
            cleanBuffer();
            std::cout << "Error de validación: Ingrese un número entero mayor o igual a " << min << ".\n";
        }
    }

    return rtn;
}

long long int Terminal::validateLongInt(int min, int max) {
    long long int rtn;
    
    while (true) {
        if (std::cin >> rtn && min <= rtn && rtn <= max) {
            break;
        } else {
            std::cin.clear();
            cleanBuffer();
            if (min < max) {
                std::cout << "Error de validación: Ingrese un número entero mayor (o igual) a " << min << " y menor (o igual) a " << max << ".\n";
            } else if (min == max) {
                std::cout << "Error de validación: El único ingreso válido es " << min << ".\n";
            } else {
                std::cout << "Error de validación: Los extremos están definidos de manera que no haya ingresos válidos.\n";
            }
        }
    }

    return rtn;
}

double Terminal::validateDouble() {
    double rtn;
    
    while (true) {
        if (std::cin >> rtn) {
            break;
        } else {
            std::cin.clear();
            cleanBuffer();
            std::cout << "Error de validación: Ingrese un número.\n";
        }
    }

    return rtn;
}

double Terminal::validateDouble(int min) {
    double rtn;
    
    while (true) {
        if (std::cin >> rtn && min <= rtn) {
            break;
        } else {
            std::cin.clear();
            cleanBuffer();
            std::cout << "Error de validación: Ingrese un número mayor o igual a " << min << ".\n";
        }
    }

    return rtn;
}

double Terminal::validateDouble(int min, int max) {
    double rtn;
    
    while (true) {
        if (std::cin >> rtn && min <= rtn && rtn <= max) {
            break;
        } else {
            std::cin.clear();
            cleanBuffer();
            if (min < max) {
                std::cout << "Error de validación: Ingrese un número mayor (o igual) a " << min << " y menor (o igual) a " << max << ".\n";
            } else if (min == max) {
                std::cout << "Error de validación: El único ingreso válido es " << min << ".\n";
            } else {
                std::cout << "Error de validación: Los extremos están definidos de manera que no haya ingresos válidos.\n";
            }
        }
    }

    return rtn;
}

char Terminal::validateChar() {
    char rtn;
    
    while (true) {
        if (std::cin >> rtn) {
            break;
        } else {
            std::cin.clear();
            cleanBuffer();
        }
    }

    return rtn;
}

void Terminal::configureUTF8() {
    #ifdef _WIN64
        system("chcp 65001");
        system("Set-Culture es-ES");
    #endif
}

void Terminal::cleanBuffer() {
    int aux;
    while ((aux = std::cin.get()) != '\n' && aux != EOF) {}
}

std::string Terminal::fill(std::string text, unsigned int length) {
    while (text.length() < length) {
        text += " ";
    }

    return text;
}