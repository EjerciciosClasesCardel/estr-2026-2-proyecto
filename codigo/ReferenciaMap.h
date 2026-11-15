// Autores: Jesus Esteban Monroy 9029007
// ReferenciaMap inventario de referencia hecho con std::map de la STL tiene la misma interfaz que ListaArticulos y TablaHash para poder compararlas en los experimentos std::map  asi que buscar insertar y borrar cuestan O(log n) y LISTAR sale en orden creciente de codigo
#ifndef REFERENCIA_MAP_H
#define REFERENCIA_MAP_H
#include "Inventario.h"
#include <map>
class ReferenciaMap : public Inventario {
private:
    // Clave: codigo del articulo. Valor: el articulo completo.
    std::map<long long, Articulo> datos;
public:
    bool agregar(long long codigo, const char* nombre, int cantidad) override;
    bool eliminar(long long codigo) override;
    bool consultar(long long codigo, Articulo& salida) const override;
    bool reponer(long long codigo, int cantidad) override;
    void listar(std::ostream& salida) const override;
    int tamano() const override;
};
#endif
