#include <stddef.h>
#include <assert.h>

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