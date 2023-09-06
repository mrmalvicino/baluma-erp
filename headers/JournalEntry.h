#include<cstring>
using namespace std;
#include <string>
#include <vector>
#include <utility>
#include "AccountingAccount.h"

class AsientoContable {
public:
    std::string fecha;
    std::string descripcion;
    std::vector<pair<cuentaContable, double>> cuentasYMonto;
    //constructor
    AsientoContable(std::string fecha, std::string descripcion)
        : fecha(fecha), descripcion(descripcion) {}
    //métodos
    void agregarCuenta(cuentaContable &cuenta, double monto, bool esActivo);
    double calcularTotal();
    void mostrarInformacion();

};