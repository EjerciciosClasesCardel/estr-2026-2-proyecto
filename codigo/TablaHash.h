// Autores: Alejandro Serna Tovar 9030159, Jesus Esteban Monroy 9029007

#ifndef TABLA_HASH_H
#define TABLA_HASH_H

#include <ostream>
#include "Inventario.h"
#include "ListaArticulos.h"

class TablaHash : public Inventario {
public:
    // Precondicion: numCubetas > 0
    explicit TablaHash(int numCubetas);
    ~TablaHash() override;

    // Se prohibe copiar la tabla para evitar doble liberacion de cubetas
    TablaHash(const TablaHash&) = delete;
    TablaHash& operator=(const TablaHash&) = delete;

    bool agregar(long long codigo, const char* nombre, int cantidad) override;
    bool eliminar(long long codigo) override;
    bool consultar(long long codigo, Articulo& salida) const override;
    bool reponer(long long codigo, int cantidad) override;
    void listar(std::ostream& salida) const override;
    int tamano() const override;

    int numCubetas() const;

private:
    ListaArticulos* cubetas;  // arreglo dinamico de m listas enlazadas
    int m;                    // numero fijo de cubetas
    int n;                    // total de articulos almacenados

    // Calcula h(c) = c mod m garantizando resultado en [0, m - 1]
    int cubeta(long long codigo) const;
};

#endif
