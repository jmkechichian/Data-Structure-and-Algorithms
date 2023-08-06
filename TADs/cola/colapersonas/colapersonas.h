#ifndef _COLAPERSONA_H
#define _COLAPERSONA_H

struct RepresentacionColaPersona;
typedef RepresentacionColaPersona * ColaPersonas;

//No tiene Precondicion
//Pos Condicion Retorna un puntero a una cola de personas vacias. Topeada a cota elementos
ColaPersonas crearColaPersonas (int cota);

//Precondicion: La cola no esta llena
//Poscondicion: solicita por teclado CI, nombre y apellido de la persona y lo agrega al final de la cola
void encolarColaPersonas (ColaPersonas &cola);

//Precondicion:la cola no es vacia (Tiene por lo menos 1 persona)
//Poscondicion: Imprime en pantalla los datos de la persona que esta al inicio de la pantalla
void primeroColaPersonas (ColaPersona cola);

//PreCondicion: la cola no esta vacia 
//Saca a la persona que esta al inicio de la cola
void deseconlarColaPersonas (ColaPersonas &cola);

//retorna true si en la cola hay por lo menos 1 person, false si es lo contrario
bool esVaciaColaPersona (ColaPersonas cola);

//retorna true si la cola esta llena, false si es lo contrario
bool esLlenaColaPersona (ColaPersonas cola);

//destruye tolda la memoria solicitada para la cola
void destruirColaPersonas (ColaPersonas &cola);

#endif