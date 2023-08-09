#ifndef _LISTAENTEROS_H
#define _LISTAENTEROS_H

struct Lista;
typedef Lista * ListaEnteros;

// Pre-condicion: No
//Pos - Condicion: Retorna un puntero a una lista vacia
crearListaEnteros();

//PosCon: Agrega el entero al final de la lista
void agregarEnteroLista(ListsEnteros &lista, int entero);

//Pre-condicion: la lista no esta vacía
//Pos: retorna el primer entero de la lista
int primeroListaEntero (ListaEntero lista);

//Pre: la lista no esta vacía
//Pos: elimina el primer entero de la lista
void eliminarPrimeroLista( ListaEnteros &lista);

//retorna true si en la lista no hay ningun entero
bool esVaciaListaEnteros(ListaEnteros lista);

//Pos: retorna la cantidad de enteros en la lista
int cantindadEnterosLista(ListEnteros lista);

//Pos: destruye toda la memoria ocupada por lista
void destruirListaEnteros (ListaEnteros &lista);

void imprimirLista (ListaEnteros &lista);

#endif /*_LISTAENTEROS_H*/
