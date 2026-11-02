// Autores: Jesus Esteban Monroy 9029007, Alejandro Serna Tovar 9030159
// Lee la cantidad de ordenes y luego una orden por linea:AGREGAR c nombre cantidad, ELIMINAR c, CONSULTAR c, REPONER c cantidad, LISTAR.main solo conoce la interfaz Inventario; la estructura concreta la crea fabrica asi el mismo main sirve para la lista y para la tabla hash

#include "Fabrica.h"
#include <iostream>
#include <string>
// Escribe cdigo nombre cantidad y un salto de linea 
static void escribirArticulo(std::ostream& salida, const Articulo& articulo) {
    salida << articulo.codigo << ' ' << articulo.nombre << ' '
           << articulo.cantidad << '\n';
}
// Lee los datos de una orden, la aplica sobre el inventario y escribe la respuesta
static void ejecutarOrden(Inventario& inventario, const std::string& orden,
                          std::istream& entrada, std::ostream& salida) {
    long long codigo = 0;
    int cantidad = 0;
    std::string nombre;
    if (orden == "AGREGAR") {
        entrada >> codigo >> nombre >> cantidad;
        salida << (inventario.agregar(codigo, nombre.c_str(), cantidad) ? "ok" : "repetido") << '\n';
    } else if (orden == "ELIMINAR") {
        entrada >> codigo;
        salida << (inventario.eliminar(codigo) ? "ok" : "no existe") << '\n';
    } else if (orden == "CONSULTAR") {
        entrada >> codigo;
        Articulo articulo;
        if (inventario.consultar(codigo, articulo)) {
            escribirArticulo(salida, articulo);
        } else {
            salida << "no existe\n";
        }
    } else if (orden == "REPONER") {
        entrada >> codigo >> cantidad;
        salida << (inventario.reponer(codigo, cantidad) ? "ok" : "no existe") << '\n';
    } else if (orden == "LISTAR") {
        inventario.listar(salida);
    }
}

// Lee n y luego ejecuta hasta n ordenes (o hasta que se acabe la entrada).
static void procesarOrdenes(Inventario& inventario, std::istream& entrada,
                            std::ostream& salida) {
    int cantidadOrdenes = 0;
    entrada >> cantidadOrdenes;
    std::string orden;
    int leidas = 0;
    while (leidas < cantidadOrdenes && entrada >> orden) {
        ejecutarOrden(inventario, orden, entrada, salida);
        leidas = leidas + 1;
    }
}

int main(int argc, char* argv[]) {
    int codigoSalida = 0;
    std::string tipo = argc > 1 ? argv[1] : "lista";
    Inventario* inventario = crearInventario(tipo);
    if (inventario == nullptr) {
        std::cerr << "uso: " << argv[0] << " [lista] < entrada\n";
        codigoSalida = 1;
    } else {
        procesarOrdenes(*inventario, std::cin, std::cout);
        delete inventario;
    }
    return codigoSalida;
}