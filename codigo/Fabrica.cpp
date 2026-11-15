// Autores: Jesus Esteban Monroy 9029007, Alejandro Serna Tovar 9030159
#include "Fabrica.h"
#include "ListaArticulos.h"
#include "ReferenciaMap.h"
#include "TablaHash.h"
Inventario* crearInventario(const std::string& tipo, int numCubetas) {
    Inventario* inventario = nullptr;
    if (tipo == "lista") {
        inventario = new ListaArticulos();
    } else if (tipo == "hash") {
        inventario = new TablaHash(numCubetas);
    } else if (tipo == "map") {
        inventario = new ReferenciaMap();
    }
    return inventario;
}
