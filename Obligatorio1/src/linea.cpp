/* 1111111 */ // sustituiir con los 7 dígitos de la cédula
/*
 Modulo que implemente el archivo linea.h

 */
#include <stdio.h>
#include "../include/linea.h"



struct _rep_linea{
    char letra;
    TLinea siguiente;
    int cantidad;
};


typedef struct _rep_linea* TLinea;


// Pos-condición: Crea una línea vacía
TLinea createLine() {
    return NULL;
}

// Pos-condición: Retorna true si la línea "linea" es vacía
bool isEmptyLine(TLinea linea) {
    return linea == NULL;
}

// Pre-condición: linea != NULL
// Inserta el caracter letra al final de la línea.
void insertCharLine(char letra, TLinea& linea) {
    TLinea nuevoNodo = new _rep_linea;
    nuevoNodo->letra = letra;
    nuevoNodo->siguiente = NULL;

    if (isEmptyLine(linea)) {
        linea = nuevoNodo;
    } else {
        TLinea actual = linea;
        while (actual->siguiente != NULL) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevoNodo;
    }
     linea->cantidad++;
}


//pre-condición linea != NULL
//Retorna el primer caracter de la linea "linea"
char firstCharLine(TLinea linea){
     return linea -> letra;
}

//pre-condicion linea !=NULL
//Retorna un puntero a al siguiente nodo de "linea"
TLinea nextLine(TLinea linea){

        return linea->  siguiente;
}


//Retorna la cantidad de elementos que tiene la linea "linea"
int countNodesLine(TLinea linea){
    return linea -> cantidad;
}

//pre-condicion: linea != NULL
//pos-condicion: Elimina el primer nodo de la linea "linea"
void deleteFirstChar(TLinea& linea){

       if (linea != NULL && linea->cantidad > 0) {
        TLinea aux = linea;
        linea = linea->siguiente;
        delete aux;
        aux = NULL;
        linea->cantidad--;
    }
}

//pre-condicion: linea != NULL
//pos-condicion: Elimina el ultimo nodo de la linea "linea"
void deleteLastChar(TLinea& linea) {
 if (linea != NULL && linea->cantidad > 0) {
        // Si la línea tiene un solo nodo, simplemente lo eliminamos
        if (linea->siguiente == NULL) {
            delete linea;
            linea = NULL; // La línea está vacía después de eliminar el último nodo
        } else {
            TLinea actual = linea;
            TLinea anterior = NULL;

            // Avanzamos al último nodo manteniendo un puntero al nodo anterior
            while (actual->siguiente != NULL) {
                anterior = actual;
                actual = actual->siguiente;
            }

            // Eliminamos el último nodo y actualizamos el puntero del nodo anterior
            delete actual;
            actual = NULL;
            anterior->siguiente = NULL;

            linea->cantidad--; // Decrementar la cantidad de elementos en la línea
        }
    }
}

//Pos-condicion: Destruye toda la memoria utilizada por linea
void destroyLine(TLinea& linea){
   while (linea != NULL) {
        TLinea aux = linea;
        linea = linea->siguiente;
        delete aux;
    }
}
