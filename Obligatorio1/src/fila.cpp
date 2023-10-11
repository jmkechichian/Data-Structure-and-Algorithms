/* 1111111 */ // sustituiir con los 7 dígitos de la cédula
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.

 */

#include <stdio.h>

#include "../include/fila.h"
#include "../include/linea.h"



struct _rep_fila {
    TLinea elemento;
    _rep_fila* siguiente;
    int cantFila;
};
typedef struct _rep_fila* TFila;


//Pos-condición crea una fila vacía.
TFila createRow(){
    return NULL;
}

//Pos-Condición retorna true si la fila es vacía.
bool isEmptyRow(TFila fila){
    return fila ==  NULL;
}

//Pos-Condición Inserta una nueva fila al principio de "fila"
 void insertRow (TFila &fila, TLinea &linea){
    TFila nuevaFila = createRow(); // Crear una nueva fila vacía
    TLinea nuevaLinea = createLine();
    nuevaFila->siguiente = NULL; // Establecer la fila actual como siguiente de la nueva fila
    nuevaFila-> elemento = nuevaLinea;// Insertar la linea en la fila
    if(fila == NULL){
        fila = nuevaFila;
        fila -> cantFila++;
    }
    else{
        TFila actual = fila;
        while(actual->siguiente != NULL){
            actual = actual -> siguiente;
        }
    }   fila -> cantFila++;
    
 }

//pre-condicion: fila !=NULL
//pos-condicion: retorna un puntero al primer nodo de la fila "fila"
TLinea headRow(TFila fila){
    if (fila != NULL) {
        return fila->elemento;
    } else {
        return NULL;
    }
}

//pre-condicion: fila !=NULL
//pos-condicion: Retorna un puntero al siguente elemento de la fila "fila"
TFila nextRow (TFila fila){
    if (fila != NULL && fila->siguiente != NULL) {
        return fila->siguiente;
    } else {
        return NULL;
    }
}

//pre-condicion: fila != NULL
//elimina el primer nodo de la fila "fila"
void deleteFirstRow (TFila &fila){
   if (fila != NULL && fila->cantFila > 0) {
        TFila aux = fila;
        fila = fila->siguiente;
        destroyLine(aux->elemento); 
        delete aux;
        
    }
}

//Elimina toda la memoria de la fila "fila"
void deleteRows (TFila& fila){
    while (fila != NULL) {
        TFila aux = fila;
        fila = fila->siguiente;
        delete aux;
    }
    fila = NULL; // Importante para evitar usar la fila después de liberarla
}

