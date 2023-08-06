#include <stddef.h>
#include <assert.h>

#include "pila.h"

struct RepresentacionPila{
  int* array;
  int tope;
  int cota;
};


Pila crearPila(int cota) {
    Pila p = new RepresentacionPila();
    p ->tope = -1; // Pila vacía
    p ->array = new int cota;
    p ->cota = cota;
    return p;
}
