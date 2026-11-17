// Autores: Alejandro Serna Tovar 9030159, Jesus Esteban Monroy 9029007
//
// Datos de un articulo del inventario: codigo, nombre y cantidad.
// El nombre se guarda en un arreglo de tamano fijo (sin string de la STL).

#ifndef ARTICULO_H
#define ARTICULO_H

// Tamano del arreglo del nombre: 63 caracteres utiles mas el '\0'.
const int MAX_NOMBRE = 64;

struct Articulo {
    long long codigo;
    char nombre[MAX_NOMBRE];
    int cantidad;

    Articulo();
    Articulo(long long c, const char *n, int cant);
};

#endif