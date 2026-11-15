// Autores: Alejandro Serna Tovar 9030159, Jesus Esteban Monroy 9029007

#include "TablaHash.h"
#include <cassert>

using std::ostream;

// Crea el arreglo de m cubetas vacias
TablaHash::TablaHash(int numCubetas) : cubetas(nullptr), m(numCubetas), n(0) {
    assert(numCubetas > 0);
    cubetas = new ListaArticulos[m];
}

// Libera el arreglo de cubetas; cada cubeta destruye sus propios nodos
TablaHash::~TablaHash() {
    delete[] cubetas;
}

// Funcion hash por division ajustada para codigos negativos
int TablaHash::cubeta(long long codigo) const {
    long long resto = codigo % m;
    if (resto < 0) {
        resto = resto + m;
    }
    return (int) resto;
}

// Agrega el articulo en su cubeta si el codigo no existe previamente
bool TablaHash::agregar(long long codigo, const char* nombre, int cantidad) {
    int idx = cubeta(codigo);
    bool agregado = cubetas[idx].agregar(codigo, nombre, cantidad);
    if (agregado) {
        n = n + 1;
    }
    return agregado;
}

// Elimina el articulo de su cubeta y descuenta n si existia
bool TablaHash::eliminar(long long codigo) {
    int idx = cubeta(codigo);
    bool eliminado = cubetas[idx].eliminar(codigo);
    if (eliminado) {
        n = n - 1;
    }
    return eliminado;
}

// Busca el articulo unicamente dentro de la cubeta correspondiente
bool TablaHash::consultar(long long codigo, Articulo& salida) const {
    int idx = cubeta(codigo);
    bool encontrado = cubetas[idx].consultar(codigo, salida);
    return encontrado;
}

// Incrementa las existencias del articulo en su cubeta
bool TablaHash::reponer(long long codigo, int cantidad) {
    int idx = cubeta(codigo);
    bool repuesto = cubetas[idx].reponer(codigo, cantidad);
    return repuesto;
}

// Imprime todos los articulos recorriendo de la cubeta 0 a la m - 1
void TablaHash::listar(ostream& salida) const {
    int i = 0;
    while (i < m) {
        cubetas[i].listar(salida);
        i = i + 1;
    }
}

// Devuelve la cantidad total de articulos en la tabla
int TablaHash::tamano() const {
    return n;
}

// Devuelve la cantidad de cubetas configuradas
int TablaHash::numCubetas() const {
    return m;
}