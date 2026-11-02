// Autores: Jesus Esteban Monroy 9029007, Alejandro Serna Tovar 9030159
#include "Fabrica.h"
#include "ListaArticulos.h"
Inventario* crearInventario(const std::string& tipo) {
    Inventario* inventario = nullptr;
    if (tipo == "lista") {
        inventario = new ListaArticulos();
    }
    return inventario;
}
