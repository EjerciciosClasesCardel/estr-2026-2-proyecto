# Bitácora

Va en `docs/`, como los informes.

Una entrada por sesión de trabajo, con la fecha, quién trabajó, qué se
hizo y qué quedó pendiente. La entrada más reciente va arriba.

## 2026-__-__

- Quiénes:
- Qué hicimos:
- Qué quedó pendiente:
  
## 2026-11-15

- Quiénes: Jesús Esteban Monroy
- Qué hicimos: programa de experimentos `codigo/medir.cpp` (carga n artículos y mide consultas usando solo la interfaz `Inventario`); `Fabrica` y `principal.cpp` con los tipos `hash` y `map` y el número de cubetas; `Makefile` con los objetivos `medir` y `mediciones`; `.gitignore` con el ejecutable `medir`.
- Qué quedó pendiente: integrar `TablaHash` y `ReferenciaMap`, correr `make mediciones` y escribir el informe final.

## 2026-11-02

- Quiénes: Jesús Esteban Monroy
- Qué hicimos: casos de prueba en `datos/` (3 funcionales y 4 límite) e informe de avance completo; revisión e integración de los PR #8, #9 y #10.
- Qué quedó pendiente: verificar `make pruebas` en `main` y empezar la tabla hash para la entrega final

## 2026-11-02
- Quiénes: Alejandro Serna Tovar
- Qué hicimos: 
  - Se finalizó la implementación de `ListaArticulos.cpp` usando una lista enlazada simple con inserción al inicio ($O(1)$) sin utilizar el puntero `cola`.
  - Se cumplieron las restricciones del curso: único punto de retorno por función, iteración exclusiva mediante ciclos `while`, manejo de punteros con `NULL` y gestión manual de memoria y contadores.
  - Se realizó la integración (*merge*) con los cambios de la rama principal (`Fabrica`, `Makefile` y `principal.cpp`) y se verificó la compilación limpia del proyecto sin errores ni advertencias.
- Qué quedó pendiente: 
  - Revisión del Pull Request y *merge* final a la rama `main` por parte de Esteban Monroy.


## 2026-11-02
- Quiénes: Jesús Esteban Monroy
- Qué hicimos: programa principal (`codigo/principal.cpp`) que lee las órdenes y responde usando solo la interfaz `Inventario`; `Fabrica` que crea la estructura concreta (en el avance, la lista); `Makefile` del curso ajustado con nuestras fuentes; `.gitignore` corregido para que los `.out` de `datos/` sí se suban.
- Qué quedó pendiente: integrar `ListaArticulos.cpp` , casos de prueba , correr `make pruebas` y valgrind, informe de avanc.


## 2026-10-27
- Quiénes: Alejandro Serna Tovar
- Qué hicimos: Creación del archivo `codigo/ListaArticulos.h`. Se definió la estructura interna de la lista simplemente enlazada (el `Nodo`, el puntero `cabeza` y el contador `n`) y se declararon las firmas de los métodos de la interfaz `Inventario`. También se bloqueó la copia de listas (`= delete`) para proteger la memoria.
- Qué quedó pendiente: Implementar la lógica de estos métodos en el archivo `codigo/ListaArticulos.cpp`.


## 2026-10-27
- Quiénes: Jesús Esteban Monroy
- Qué hicimos: revise lo de Alejandro (Articulo), resolví el conflicto de la bitácora y lo integr e a main  creé la interfaz abstracta `Inventario` en `codigo/Inventario.h` con los métodos virtuales puros.
- Qué quedó pendiente: crear `codigo/ListaArticulos.h` e implementar sus métodos en `codigo/ListaArticulos.cpp`.
 

## 2026-10-27
- Quiénes: Alejandro Serna Tovar, Jesús Esteban Monroy
- Qué hicimos: Revisión y refactorización de `codigo/Articulo.h` y `codigo/Articulo.cpp`. Se aplicaron reglas de estilo de la Clase 15: control de precondiciones con `assert`, eliminación de contenedores STL, manejo seguro de cadenas de C (`strncpy` cerrando con `'\0'`) y corrección de namespaces (`using std::strncpy`).
- Qué quedó pendiente: Crear la interfaz base `Inventario.h` e iniciar la definición de `ListaArticulos.h`.


## 2026-10-26
- Quiénes: Alejandro Serna Tovar
- Qué hicimos: Creación e implementación básica del struct `Articulo` (`codigo/Articulo.h` y `codigo/Articulo.cpp`) con sus atributos (`codigo`, `nombre`, `cantidad`) y sus constructores.
- Qué quedó pendiente: Crear la interfaz base `Inventario.h` y definir la cabecera `ListaArticulos.h`.


## 2026-10-26
- Quiénes: Jesús Esteban Monroy
- Qué hicimos: completé en el README las estructuras del escenario A (lista enlazada simple, tabla hash con encadenamiento y std::map) con el PR #3.
- Qué quedó pendiente: subir Fabrica, main.cpp y Makefile; casos de prueba; informe de avance.


## 2026-10-16
- Quiénes: Jesús Esteban Monroy
- Qué hicimos: fork del repositorio base; invitación a Alejandro Serna y Juan Guzmán como colaboradores; README con la tabla de integrantes y el escenario A.
- Qué quedó pendiente: montar el entorno; definir la interfaz de `InventarioLista`; repartir tareas en el grupo.
