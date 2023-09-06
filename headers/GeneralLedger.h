#include<cstring>
using namespace std;
#include <string>
#include <vector>
#include <utility>
#include "JournalEntry.h"

class LibroDiario {
public:
    double saldoTotal;
    std::vector<AsientoContable> asientos;
    //constructor
    LibroDiario(double saldoTotal) : saldoTotal(0.0) {}
    //métodos
    void agregarAsiento(AsientoContable& asiento);
    void mostrarLibroDiario();
};