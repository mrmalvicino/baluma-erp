#include <iostream>
#include "headers/functions.h"
#include "headers/File.h"

int main(){
    //mainMenu();

    File inventario;
    
    // Guardar:
    Register producto_1(101, "alta yanta");
    Register producto_2(102, "te verde de java");
    Register producto_3(103, "pajarito");
    Register producto_4(104, "latita");
    inventario.write(producto_1);
    inventario.write(producto_2);
    inventario.write(producto_3);
    inventario.write(producto_4);
    
    // Cargar:
    Register producto_i;
    
    int cantidad_de_productos = inventario.getAmountOfRegisters();

    for (int i = 0; i < cantidad_de_productos; i ++) {
        producto_i = inventario.read(i);
        std::cout << producto_i.getId() << "\t" << producto_i.getDescription() << "\n";
    }
}