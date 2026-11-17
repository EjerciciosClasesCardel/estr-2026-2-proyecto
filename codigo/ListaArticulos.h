// Autores: Alejandro Serna Tovar 9030159, Jesus Esteban Monroy 9029007
//
// ListaArticulos: implementa el inventario usando una lista enlazada simple.

#ifndef LISTA_ARTICULOS_H
#define LISTA_ARTICULOS_H

#include "Inventario.h"

class ListaArticulos : public Inventario {
private:
    // Estructura basica del nodo para la lista
    struct Nodo {
        Articulo dato;
        Nodo* sig;
    };

    Nodo* cabeza;
    int n; // Contador de articulos en la lista

    // Metodo auxiliar para buscar un articulo por codigo sin repetir codigo
    Nodo* buscarNodo(long long codigo) const;

public:
    ListaArticulos();
    ~ListaArticulos() override;

    // Evitamos que se copie la lista por accidente para no tener problemas de memoria
    ListaArticulos(const ListaArticulos&) = delete;
    ListaArticulos& operator=(const ListaArticulos&) = delete;

    // Metodos heredados de la interfaz Inventario
    bool agregar(long long codigo, const char* nombre, int cantidad) override;
    bool eliminar(long long codigo) override;
    bool consultar(long long codigo, Articulo& salida) const override;
    bool reponer(long long codigo, int cantidad) override;
    void listar(std::ostream& salida) const override;
    int tamano() const override;
};

#endif