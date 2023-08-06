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

void destruirPila(Pila p) {
    delete[] p->array;
    delete p;
}

bool esVaciaPila(Pila p) {
    return (p->tope == -1);
}

bool esLlenaPila(Pila p){
     return (p->tope == p->cota - 1);
}

void apilar(Pila &p, int i){
    if (!esLlenaPila(p)) {
        p->tope++;
        p->array[p->tope] = i;
    }
}

int cima(Pila p) {
    if (!esVaciaPila(p)) {
        return p->array[p->tope];
    }
    // Manejo del error o retorno especial en caso de pila vacía
    else {
      return -1; // Por ejemplo, en este caso, -1 podría indicar pila vacía
    }
}

int desapilar(Pila p) {
    if (!esVaciaPila(p)) {
        int dato = p->array[p->tope];
        p->tope--;
        return dato;
    }
    // Manejo del error o retorno especial en caso de pila vacía
    else {
      return -1; // Por ejemplo, en este caso, -1 podría indicar pila vacía
  }
}
