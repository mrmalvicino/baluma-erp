#include<iostream>
#include<cstdlib>

using namespace std;

#include"../headers/GeneralLedger.h"

void LibroDiario::agregarAsiento(AsientoContable& asiento) {
    asientos.push_back(asiento);

    saldoTotal += asiento.calcularTotal();
}

void LibroDiario::mostrarLibroDiario() {
    std::cout << ".:Libro Diario:."<<endl;
    cout<<endl;
    for (auto& asiento : asientos) {
        asiento.mostrarInformacion();

        std::cout << "----------------------------------"<<endl;

    }
    cout<<"El saldo total correspondiente a los asientos: $"<<saldoTotal<<endl;
}