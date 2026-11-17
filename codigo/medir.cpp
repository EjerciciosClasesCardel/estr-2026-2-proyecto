// Autores: Jesus Esteban Monroy 9029007
#include "Fabrica.h"
#include <chrono>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>

const int CONSULTAS = 2000;

// Codigo del articulo i. En el juego normal los codigos se reparten entre
// las cubetas; en el de colision todos son multiplos de cubetas, asi que
// c mod cubetas = 0 para todos y caen en la misma cubeta.
long long codigoDe(long long i, int cubetas, bool colision) {
    long long codigo = 0;
    if (colision) {
        codigo = (i + 1) * cubetas;
    } else {
        // 1000003 es primo: mezcla los codigos sin repetirlos.
        codigo = 1000000 + (i * 1000003) % 900000007;
    }
    return codigo;
}

// Carga n articulos en el inventario.
void cargar(Inventario& inventario, int n, int cubetas, bool colision) {
    int i = 0;
    while (i < n) {
        inventario.agregar(codigoDe(i, cubetas, colision), "articulo", 1);
        i = i + 1;
    }
}
//Se usa un código positivo que no está cargado para simular consultas fallidas en la prueba de colision, se elige otro múltiplo de cubetas para que caiga en una cubeta llena y fuerce el peor recorrido posible
long long codigoAusente(int k, int n, int cubetas, bool colision) {
    long long codigo = 0;
    if (colision) {
        codigo = ((long long) n + 1 + k) * cubetas;
    } else {
        codigo = (long long) k + 1;
    }
    return codigo;
}

// hace las consultas pares buscan un codigo que esta,las impares uno que no
long long medirConsultas(const Inventario& inventario, int n, int cubetas, bool colision) {
    Articulo salida;
    int encontrados = 0;
    int k = 0;
    std::chrono::steady_clock::time_point inicio = std::chrono::steady_clock::now();
    while (k < CONSULTAS) {
        long long codigo = 0;
        if (k % 2 == 0) {
            codigo = codigoDe((long long) k * 7919 % n, cubetas, colision);
        } else {
            codigo = codigoAusente(k, n, cubetas, colision);
        }
        if (inventario.consultar(codigo, salida)) {
            encontrados = encontrados + 1;
        }
        k = k + 1;
    }
    std::chrono::steady_clock::time_point fin = std::chrono::steady_clock::now();
    // Se escribe a cerr para que el compilador no elimine las consultas.
    std::cerr << "encontrados: " << encontrados << " de " << CONSULTAS << '\n';
    return std::chrono::duration_cast<std::chrono::nanoseconds>(fin - inicio).count();
}

int main(int argc, char* argv[]) {
    int codigoSalida = 0;
    if (argc != 5) {
        std::cerr << "uso: " << argv[0] << " lista|hash|map n cubetas normal|colision\n";
        codigoSalida = 1;
    } else {
        std::string tipo = argv[1];
        int n = std::atoi(argv[2]);
        int cubetas = std::atoi(argv[3]);
        bool colision = std::strcmp(argv[4], "colision") == 0;
        // se validan n y cubetas antes de crear la estructura si se crea primero y despues se rechaza quedaria memoria sin liberar
        Inventario* inventario = nullptr;
        if (n > 0 && cubetas > 0) {
            inventario = crearInventario(tipo, cubetas);
        }
        if (inventario == nullptr) {
            std::cerr << "tipo, n o cubetas no validos\n";
            codigoSalida = 1;
        } else {
            cargar(*inventario, n, cubetas, colision);
            long long total = medirConsultas(*inventario, n, cubetas, colision);
            std::cout << tipo << ',' << n << ',' << cubetas << ',' << argv[4] << ','
                      << CONSULTAS << ',' << total / CONSULTAS << '\n';
            delete inventario;
        }
    }
    return codigoSalida;
}
