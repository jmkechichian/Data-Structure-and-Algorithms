/* 1111111 */ // sustituiir con los 7 dígitos de la cédula

#include "../include/archivo.h"
#include "../include/linea.h"
#include "../include/directorio.h"


struct archivo {
    char archivoNombre[15];
    char extension[3];
    bool escritura;
    archivo *siguiente;
    TFila *primerFila;

};

typedef struct archivo *archivoLista;


struct _rep_archivo {
    archivoLista *primerArchivo;
};



