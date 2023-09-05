#include "../headers/Terminal.h"

Terminal::Terminal() {
    setLineLenght(30);
    setBackCaption("ATRÁS");
    
    #ifdef _WIN64
        setBackIcon(char(27));
    #endif

    #ifdef __linux__
        setBackIcon("←");
    #endif

    #ifdef __APPLE__
        setBackIcon("←");
    #endif
}

void Terminal::setLineLenght(int line_lenght) {
    _line_lenght = line_lenght;
}

int Terminal::getLineLenght() {
    return _line_lenght;
}

void Terminal::setBackIcon(std::string back_icon) {
    strcpy(_back_icon, back_icon.c_str());
}

std::string Terminal::getBackIcon() {
    return _back_icon;
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

        do{
            std::cout << "\nIngresar 0 para continuar.\n";
            std::cin >> aux;
        } while (aux != 0);
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
    std::cout << "(0) " << getBackIcon() << " " << getBackCaption() << "\n";
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