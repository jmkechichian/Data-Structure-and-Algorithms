#ifndef _PILA_H
#define _PILA_H

// Definición de la representación de la Pila acotada
struct RepresentacionPila;

// Definición del tipo de dato Pila
typedef struct RepresentacionPila *Pila;

// Operaciones

Pila crearPila(int cota);
// Devuelve la pila vacía que podrá contener hasta cota elementos

void destruirPila(Pila pila);
// Libera la memoria de la pila

bool esVaciaPila(Pila p);
// Devuelve true si y solo si p es vacia

bool esLlenaPila(Pila p);
// Devuelve true si y solo si p tiene cota elementos, donde cota es el valor del parametro pasado en crearPila.

void apilar(Pila &p, int i);
// Si !esLlenaPila(p) inserta i en la cima de p, en otro caso no hace nada.

int cima(Pila p);
// Devuelve la cima de p. Precondicion !esVaciaPila(p).

int desapilar(Pila pila);
// Remueve la cima de p. Precondicion !esVaciaPila(p)

int topePila(Pila pila);
// Devuelve el elemento del tope de la pila sin eliminarlo

#endif
