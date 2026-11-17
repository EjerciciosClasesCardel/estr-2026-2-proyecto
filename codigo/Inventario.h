// Autores: Jesus Esteban Monroy 9029007, Alejandro Serna Tovar 9030159

// Interfaz inventario. Cada estructura  la implementa con
// las mismas firmas de modo que main.cpp trabaja con un Inventario* sin
// saber cual estructura hay detras
#ifndef INVENTARIO_H
#define INVENTARIO_H
#include "Articulo.h"
#include <ostream>
class Inventario {
public:
    virtual ~Inventario() {}
    // Agrega el articulo devuelve false si el codigo ya estaba repetido.
    virtual bool agregar(long long codigo, const char* nombre, int cantidad) = 0;
    // Quita el articulo. Devuelve false si el codigo no estaba.
    virtual bool eliminar(long long codigo) = 0;
    // Si el codigo esta copia el articulo en salida y devuelve true;
    // si no devuelve false y no toca salida.
    virtual bool consultar(long long codigo, Articulo& salida) const = 0;
    // Suma cantidad a la existencia devuelve false si el codigo no estaba.
    virtual bool reponer(long long codigo, int cantidad) = 0;
    // Escribe todos los articulos uno por linea con el formato
    // codigo nombre cantidad el orden depende de la estructura.
    virtual void listar(std::ostream& salida) const = 0;
    // Numero de articulos guardados.
    virtual int tamano() const = 0;
};
#endif