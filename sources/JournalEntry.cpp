/*
#include<iostream>
#include<cstdlib>

using namespace std;

#include"../headers/JournalEntry.h"

void AsientoContable::agregarCuenta(cuentaContable &cuenta, double monto, bool esActivo) {
        if (!esActivo) {
            monto *= -1.0;
            cuenta.depositar(monto);
        }else {cuenta.depositar(monto);}
        cuentasYMonto.push_back(std::make_pair(cuenta, monto));
    }

double AsientoContable::calcularTotal() {
        double total = 0.0;
        for (const auto& cuentaMonto : cuentasYMonto) {
            total += cuentaMonto.second;
        }
        return total;
    }

void AsientoContable::mostrarInformacion(){
        std::cout << "Fecha: " << fecha << std::endl;
        std::cout << "Descripcion: " << descripcion << std::endl;
        std::cout << "Cuentas involucradas y montos:" << std::endl;
        for (const auto& cuentaMonto : cuentasYMonto) {
            std::cout << "Cuenta: " << cuentaMonto.first.nombreDeCuenta<< ", Monto: $" << cuentaMonto.second << std::endl;
        }
        std::cout << "Total del asiento: $" << calcularTotal() << std::endl;
    }
*/