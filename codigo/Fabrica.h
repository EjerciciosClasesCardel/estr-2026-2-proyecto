// Autores: Jesus Esteban Monroy 9029007, Alejandro Serna Tovar 9030159
// Unico punto del programa que conoce las clases concretas del inventario principal.cpp y medir.cpp piden la estructura por su nombre y despuessolo usan la interfaz Inventario
#ifndef FABRICA_H
#define FABRICA_H
#include "Inventario.h"
#include <string>
// tamano de tabla por defecto un primo lejos de potencias de 2 y de 10
const int CUBETAS_POR_DEFECTO = 1009;
// devuelve nullptr si el tipo no existe Quien recibe el inventario lo libera con delete
Inventario* crearInventario(const std::string& tipo, int numCubetas);
#endif
