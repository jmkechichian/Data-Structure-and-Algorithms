#include <stddef.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "colapersonas.h"

#define max_letras 20;

struct Personas {
    int CI;
    char nombre[max_letras];
    char apellido[max_letras];
};

struct RepresentacionColaPersona{
    Personas* arreglo;
    int cota;
    int tope;
};

ColaPersona crearColaPersonas (int cota){
    ColaPersona = new RepresentacionColaPersona();
    ColaPersona -> cota = cota;
    ColaPersona -> tope = -1;
    ColaPersona -> arreglo = new Personas[cota]
    return ColaPersona;
}

void encolarColaPersonas(ColaPersonas cola) {
    if (!esLlenaColaPersona(cola)) {
        cola->tope++;
        printf("Ingrese CI: ");
        scanf("%d", &(cola->arreglo[cola->tope].CI));
        printf("Ingrese nombre: ");
        scanf("%s", cola->arreglo[cola->tope].nombre);
        printf("Ingrese apellido: ");
        scanf("%s", cola->arreglo[cola->tope].apellido);
    }
}

void primeroColaPersonas(ColaPersonas cola) {
    if (!esVaciaColaPersona(cola)) {
        printf("CI: %d, ", cola->arreglo[0].CI);
        printf("Nombre: %s, ", cola->arreglo[0].nombre);
        printf("Apellido: %s\n", cola->arreglo[0].apellido);
    }
}

void desencolarColaPersonas(ColaPersonas cola) {
    if (!esVaciaColaPersona(cola)) {
        for (int i = 0; i < cola->tope; i++) {
            cola->arreglo[i] = cola->arreglo[i + 1];
        }
        cola->tope--;
    }
}

int esVaciaColaPersona(ColaPersonas cola) {
    return (cola->tope == -1);
}

int esLlenaColaPersona(ColaPersonas cola) {
    return (cola->tope == cola->cota - 1);
}

void destruirColaPersonas(ColaPersonas *cola) {
    free((*cola)->arreglo);
    free(*cola);
    *cola = NULL;
}
