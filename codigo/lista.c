//Autores: Sebastian Pulgarin 9035866

#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include "inventario.h"



typedef struct Nodo
{
    long long c;
    char nombre[Largo_nombre];
    int cantidad;
    struct Nodo *siguiente;

}Nodo;

struct Inventario{
    Nodo *cabeza;
};


Inventario *inv_crear(void){
    Inventario *inv = (Inventario *)malloc(sizeof(Inventario));
    if (inv != NULL){
        inv->cabeza = NULL;
    }
    return inv;
}


static Nodo *buscar(const Inventario *inv, long long c){
    Nodo *p = inv->cabeza;
    while (p != NULL && p->c != c){
        p = p->siguiente;
    }
    return p;
}

int inv_consultar(const Inventario *inv,long long c, char *nombre, int *cantidad){
    int resultado;
    Nodo *n =buscar(inv ,c);
    if (n==NULL)resultado=INV_NO_EXISTE;
    else{
        strncpy(nombre,n->nombre,Largo_nombre-1);
        nombre[Largo_nombre-1] = '\0';
        *cantidad = n->cantidad;
        resultado = INV_OK;
    }
    return resultado;
}

int inv_reponer(Inventario *inv, long long c,int cantidad){
    int resultado;
    Nodo *n = buscar(inv,c);
    if (n == NULL)resultado = INV_NO_EXISTE;
    else{
        n->cantidad += cantidad;
        resultado = INV_OK;
    }
    return resultado;
}

int inv_agregar(Inventario *inv, long long c, const char *nombre, int cantidad){
    int resultado;
    if (buscar(inv, c) != NULL)resultado = INV_REPETIDO;
    else{
        Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
        if (nuevo == NULL){
            resultado = INV_SIN_MEMORIA;
        }
        else{
            nuevo->c = c;
            strncpy(nuevo-> nombre,nombre,Largo_nombre - 1);
            nuevo->nombre[Largo_nombre -1]='\0';
            nuevo->cantidad = cantidad;
            nuevo->siguiente = NULL;

            if (inv->cabeza == NULL)inv->cabeza=nuevo;
            else{
                Nodo *p = inv->cabeza;
                while (p->siguiente !=NULL)p = p->siguiente;
                p->siguiente = nuevo;
            }
            resultado = INV_OK;
        }
    }
    return resultado;
}

int inv_eliminar(Inventario *inv,long long c){
    int resultado;
    Nodo *ant = NULL;
    Nodo *act = inv->cabeza;

    while (act != NULL && act->c != c){
        ant = act;
        act = act->siguiente;
    }
    if (act == NULL)resultado=INV_NO_EXISTE;
    else{
        if (ant == NULL)inv->cabeza = act ->siguiente;
        else{ant->siguiente = act->siguiente;}
        free(act);
        resultado=INV_OK;
    }
    return resultado;
}

void inv_listar(const Inventario *inv,FILE *salida){
    Nodo *p = inv->cabeza;
    while (p != NULL){
        fprintf(salida,"%lld %s %d\n",p->c,p->nombre,p->cantidad);
        p=p->siguiente;
    }
}

void inv_destruir(Inventario *inv){
    if (inv != NULL){
        Nodo *p = inv->cabeza;
    
    while(p != NULL){
        Nodo *siguiente = p->siguiente;
        free(p);
        p = siguiente;
        }
    }   
    free(inv);
}
