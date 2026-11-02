// Autores: Jesus Esteban Monroy 9029007, Alejandro Serna Tovar 9030159

#ifndef FABRICA_H
#define FABRICA_H
#include "Inventario.h"
#include <string>
// tipo "lista" devuelve nullptr si el tipo no existe quien recibe el inventario lo libera con delete.
Inventario* crearInventario(const std::string& tipo);
#endif
