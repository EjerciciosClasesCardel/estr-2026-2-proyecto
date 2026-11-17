// Autores: Alejandro Serna Tovar 9030159, Jesus Esteban Monroy 9029007
//
// ListaArticulos.cpp: implementacion de los metodos de la lista enlazada simple.
// Los articulos nuevos se insertan al principio, asi que LISTAR los muestra
// del ultimo que llego al primero.

#include "ListaArticulos.h"

// Constructor: inicia la lista vacia.
ListaArticulos::ListaArticulos() {
    cabeza = NULL;
    n = 0;
}

// Destructor: borra todos los nodos para no dejar memoria sin liberar.
ListaArticulos::~ListaArticulos() {
    while (cabeza != NULL) {
        Nodo* a_borrar = cabeza;
        cabeza = cabeza->sig;
        delete a_borrar;
    }
    n = 0;
}

// Busqueda lineal: devuelve el nodo con ese codigo, o NULL si no esta.
// La condicion del while para al encontrarlo, sin break ni return adentro.
ListaArticulos::Nodo* ListaArticulos::buscarNodo(long long codigo) const {
    Nodo* actual = cabeza;
    while (actual != NULL && actual->dato.codigo != codigo) {
        actual = actual->sig;
    }
    return actual;
}

// Agregar: si el codigo no estaba, crea el articulo y lo pone al principio.
// Devuelve false si el codigo ya existia (repetido).
bool ListaArticulos::agregar(long long codigo, const char* nombre, int cantidad) {
    bool esNuevo = buscarNodo(codigo) == NULL;
    if (esNuevo) {
        Nodo* nuevo = new Nodo;
        // El constructor de Articulo copia el nombre sin salirse del arreglo.
        nuevo->dato = Articulo(codigo, nombre, cantidad);
        // Se engancha al principio: primero apunta a la cabeza vieja.
        nuevo->sig = cabeza;
        cabeza = nuevo;
        n = n + 1;
    }
    return esNuevo;
}

// Eliminar: busca el codigo guardando el nodo anterior, desenlaza el nodo
// y libera su memoria. Devuelve false si el codigo no estaba.
bool ListaArticulos::eliminar(long long codigo) {
    Nodo* anterior = NULL;
    Nodo* actual = cabeza;
    while (actual != NULL && actual->dato.codigo != codigo) {
        anterior = actual;
        actual = actual->sig;
    }
    bool existe = actual != NULL;
    if (existe) {
        if (anterior == NULL) {
            // Era el primero de la lista: la cabeza pasa al siguiente.
            cabeza = actual->sig;
        } else {
            // Esta en el medio o al final: el anterior lo salta.
            anterior->sig = actual->sig;
        }
        delete actual;
        n = n - 1;
    }
    return existe;
}

// Consultar: si lo encuentra, copia el articulo en salida.
bool ListaArticulos::consultar(long long codigo, Articulo& salida) const {
    Nodo* encontrado = buscarNodo(codigo);
    bool existe = encontrado != NULL;
    if (existe) {
        salida = encontrado->dato;
    }
    return existe;
}

// Reponer: suma cantidad a las existencias de un articulo que ya esta.
bool ListaArticulos::reponer(long long codigo, int cantidad) {
    Nodo* encontrado = buscarNodo(codigo);
    bool existe = encontrado != NULL;
    if (existe) {
        encontrado->dato.cantidad = encontrado->dato.cantidad + cantidad;
    }
    return existe;
}

// Listar: escribe "codigo nombre cantidad", un articulo por linea.
void ListaArticulos::listar(std::ostream& salida) const {
    Nodo* actual = cabeza;
    while (actual != NULL) {
        salida << actual->dato.codigo << " "
               << actual->dato.nombre << " "
               << actual->dato.cantidad << "\n";
        actual = actual->sig;
    }
}

// Tamano: numero de articulos guardados.
int ListaArticulos::tamano() const {
    return n;
}