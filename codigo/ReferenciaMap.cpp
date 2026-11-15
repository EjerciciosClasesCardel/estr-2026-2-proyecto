// Autores: Jesus Esteban Monroy 9029007
// Implementacion de ReferenciaMap sobre std::map<long long, Articulo>
#include "ReferenciaMap.h"
#include <utility>
using std::map;
using std::make_pair;
// insert no reemplaza si la clave ya existe .second dice si se inserto
bool ReferenciaMap::agregar(long long codigo, const char* nombre, int cantidad) {
    bool insertado = datos.insert(make_pair(codigo, Articulo(codigo, nombre, cantidad))).second;
    return insertado;
}
// erase(clave) devuelve cuantos elementos borro 1 si estab 0 si no
bool ReferenciaMap::eliminar(long long codigo) {
    bool borrado = datos.erase(codigo) == 1;
    return borrado;
}
// find devuelve end() cuando el codigo no esta
bool ReferenciaMap::consultar(long long codigo, Articulo& salida) const {
    map<long long, Articulo>::const_iterator it = datos.find(codigo);
    bool encontrado = it != datos.end();
    if (encontrado) {
        salida = it->second;
    }
    return encontrado;
}
bool ReferenciaMap::reponer(long long codigo, int cantidad) {
    map<long long, Articulo>::iterator it = datos.find(codigo);
    bool encontrado = it != datos.end();
    if (encontrado) {
        it->second.cantidad = it->second.cantidad + cantidad;
    }
    return encontrado;
}
// el map recorre sus claves en orden creciente asi que la salida queda ordenada por codigo (distinto al orden de la lista)
void ReferenciaMap::listar(std::ostream& salida) const {
    map<long long, Articulo>::const_iterator it = datos.begin();
    while (it != datos.end()) {
        salida << it->second.codigo << " "
               << it->second.nombre << " "
               << it->second.cantidad << "\n";
        ++it;
    }
}
int ReferenciaMap::tamano() const {
    int cantidad = (int) datos.size();
    return cantidad;
}
