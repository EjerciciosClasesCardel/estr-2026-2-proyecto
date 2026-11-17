// Autores: Alejandro Serna Tovar 9030159, Jesus Esteban Monroy 9029007

#include "Articulo.h"

#include <cassert>
#include <cstring>

using std::strncpy;

// Articulo vacio: codigo 0, nombre vacio, cantidad 0.
Articulo::Articulo() {
    codigo = 0;
    nombre[0] = '\0';
    cantidad = 0;
}

// Copia a lo sumo MAX_NOMBRE - 1 caracteres y cierra la cadena con '\0'.
// Exige n != NULL.
Articulo::Articulo(long long c, const char *n, int cant) {
    assert(n != NULL);
    codigo = c;
    strncpy(nombre, n, MAX_NOMBRE - 1);
    nombre[MAX_NOMBRE - 1] = '\0';
    cantidad = cant;
}