#include "../headers/BudgetManager.h"

void BudgetManager::displayMenu() {
    int selection = 1;

    do {
        _terminal.clear();
        _terminal.displayMenuHeader("PRESUPUESTOS");
        std::cout << "(1) NUEVA COTIZACIÓN\n";
        _terminal.displayMenuFooter();

        selection = _terminal.validateInt(0, 1);

        switch (selection) {
            case 1:
                std::cout << "...En desarrollo...\n";
                _terminal.pause();
                break;
        }
    } while (selection != 0);
}