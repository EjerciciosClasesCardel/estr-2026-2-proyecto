// Autores: Sebastian Pulgarin 9035866
#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <stdio.h>

#define Largo_nombre 64

enum { INV_OK = 0, INV_REPETIDO = 1, INV_NO_EXISTE = 2, INV_SIN_MEMORIA = 3 };

typedef struct Inventario Inventario;

Inventario *inv_crear(void);
void inv_destruir(Inventario *inv);
int inv_agregar(Inventario *inv, long long codigo, const char *nombre, int cantidad);
int inv_eliminar(Inventario *inv, long long codigo);
int inv_consultar(const Inventario *inv, long long codigo, char *nombre, int *cantidad);
int inv_reponer(Inventario *inv, long long codigo, int cantidad);
void inv_listar(const Inventario *inv, FILE *salida);

#endif