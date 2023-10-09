/* 1111111 */ // sustituiir con los 7 dígitos de la cédula

#include "../include/archivo.h"
#include "../include/linea.h"
#include "../include/directorio.h"


#include <string.h>
#include <stdio.h>
#include <stdlib.h>
typedef char* Cadena;


//Enumeracion para el tipo de archivo
enum Tipo_archivo{
    Lectura_Escritura,
    Solo_Lectura
};

struct _rep_archivo{
    char* nombreArchivo;
    char* extension; // Campo para representar la extensión del archivo
    Tipo_archivo tipo_archivo;
    TFila fila;
};


//Crea un archivo vacío con nombre nombreArchivo, extensión extension y con permiso de lectura/escritura
//El archivo no contiene filas.
TArchivo createEmptyFile (Cadena nombreArchivo, Cadena extension){
    
    TArchivo archivo = new _rep_archivo;
    strcpy(archivo->nombreArchivo, nombreArchivo);
    strcpy(archivo->extension,extension);
    archivo->tipo_archivo= Lectura_Escritura;
    return archivo;
}

//Retorna un puntero a un array con el nombre del archivo "archivo"
char* getFileName (TArchivo archivo){
    return archivo->nombreArchivo;
}

//Retorna true si archivo tiene permiso de escritura
bool haveWritePermission (TArchivo archivo){
    if(archivo->tipo_archivo==Lectura_Escritura){
        return true;
    }
    return false;
}

//retorna true si archivo no tiene filas;
bool isEmptyFile(TArchivo archivo){
    return archivo->fila == NULL;
}

//pos-condición: Retorna un puntero a la linea de la primer fila del archivo "archivo"
TLinea getFirstRow (TArchivo archivo){
    return headRow(archivo->fila);
}

//Retorna un puntero a la siguiente Fila de archivo
TLinea getNextRow (TArchivo archivo){
    if (archivo != NULL) {
        TFila filaActual = archivo->fila;
        if (filaActual != NULL) {
            // Obtén la siguiente fila en la lista
            TFila siguienteFila = nextRow(filaActual);
            if (siguienteFila != NULL) {
                // Actualiza la fila en el archivo
                archivo->fila = siguienteFila;
                // Devuelve la primera línea de la siguiente fila
                return headRow(siguienteFila);
            }
        }
    }
    return NULL;
}

//Retorna la cantidad de Fila que tiene el archvio "archivo"
int getCountRow (TArchivo archivo){
        if (archivo != NULL) {
        int count = 0;
        TFila filaActual = archivo->fila;
        while (filaActual != NULL) {
            count++;
            nextRow(filaActual);

        }
        return count;
    }
    return 0; // Si el archivo es nulo, no tiene filas
}

//Retorna la cantidad de caracteres que tiene el archvio "archivo"
int getCountChars (TArchivo archivo){
       if (archivo != NULL) {
        int count = 0;
        TFila filaActual = archivo->fila;
        while (filaActual != NULL) {
            TLinea lineaActual = headRow(filaActual);
            while (lineaActual != NULL) {
                count += countNodesLine(lineaActual); // Contar caracteres en la línea
                lineaActual = nextLine(lineaActual); // Moverse a la siguiente línea
            }
            nextRow(filaActual); // Moverse a la siguiente fila
        }
        return count;
    }
    return 0; // Si el archivo es nulo, no tiene caracteres
}


//imprime la Linea del archivo indicada por "numero_linea"
//pre-condición el archivo tiene por lo menos numero_linea de lineas
void printLineFile(TArchivo archivo, int numero_linea){
    if (archivo != NULL && numero_linea >= 1) {
        TFila filaActual = archivo->fila;
        int numero_fila = 1;

        while (filaActual != NULL && numero_fila < numero_linea) {
            filaActual = nextRow(filaActual); // Avanzar a la siguiente fila
            numero_fila++;
        }

        if (filaActual != NULL) {
            TLinea lineaActual = headRow(filaActual);
            int numero_linea_actual = 1;

            while (lineaActual != NULL && numero_linea_actual < numero_linea) {
                lineaActual = nextLine(lineaActual); // Avanzar a la siguiente línea
                numero_linea_actual++;
            }

            if (lineaActual != NULL) {
                // Imprimir los caracteres de la línea con printf
                TLinea actual = lineaActual;
                while (actual != NULL) {
                    printf("%c", firstCharLine(actual));
                    actual = nextLine(actual);
                }
                printf("\n");
            } 
        } 
    } 
}


//Elimina los cant cantidad de caracteres finales del "archivo"
//En caso que el archivo tenga menos caracteres los elimina a todos
void deleteCharterFile (TArchivo &archivo, int cant){
  if (archivo != NULL) {
        TFila filaActual = archivo->fila;

        // Recorrer las filas hasta encontrar la última fila con caracteres
        while (filaActual != NULL && !isEmptyRow(filaActual)) {
            nextRow(filaActual);
        }

        // Verificar si se encontró una fila con caracteres
        if (filaActual != NULL) {
            TLinea lineaActual = headRow(filaActual);
          

            // Recorrer las líneas de la última fila y eliminar caracteres
            while (lineaActual != NULL && cant > 0) {
                int caracteresEnLinea = countNodesLine(lineaActual);

                // Si la cantidad de caracteres en la línea es mayor o igual a cant, eliminarlos
                if (caracteresEnLinea >= cant) {
                    for (int i = 0; i < cant; i++) {
                        deleteLastChar(lineaActual); // Eliminar el último carácter de la línea
                    }
                    cant = 0; // Se han eliminado todos los caracteres necesarios
                } else {
                    // Si la cantidad de caracteres en la línea es menor a cant,
                    // eliminar la línea completa y continuar con la siguiente línea
                    cant -= caracteresEnLinea;
                    destroyLine(lineaActual);
                    lineaActual = nextLine(lineaActual); // Moverse a la siguiente línea
                }
            }

            // Si quedan caracteres por eliminar, continuar con las filas anteriores
            if (cant > 0) {
                filaActual = archivo->fila;
                while (filaActual != NULL) {
                    lineaActual = headRow(filaActual);

                    while (lineaActual != NULL && cant > 0) {
                        int caracteresEnLinea = countNodesLine(lineaActual);

                        // Si la cantidad de caracteres en la línea es mayor o igual a cant, eliminarlos
                        if (caracteresEnLinea >= cant) {
                            for (int i = 0; i < cant; i++) {
                                deleteLastChar(lineaActual); // Eliminar el último carácter de la línea
                            }
                            cant = 0; // Se han eliminado todos los caracteres necesarios
                        } else {
                            // Si la cantidad de caracteres en la línea es menor a cant,
                            // eliminar la línea completa y continuar con la siguiente línea
                            cant -= caracteresEnLinea;
                            destroyLine(lineaActual);
                            lineaActual = nextLine(lineaActual); // Moverse a la siguiente línea
                        }
                    }

                    if (cant == 0) {
                        break; // Se han eliminado todos los caracteres necesarios
                    }

                     nextRow(filaActual); // Moverse a la siguiente fila
                }
            }
        }
    }
}
    
//Cambia el nombre del archivo "archivo" por nuevoNombre
void setName(TArchivo &archivo, Cadena nuevoNombre){

}

//Cambia la extension del "archivo" por nuevoNombre
void setExtension(TArchivo &archivo, Cadena nuevaExtension){

}

//Inserta el texto "texto" como una nueva fila al comienzo del archivo
void insertChartsNewRow(TArchivo &archivo, Cadena texto){
 if (archivo != NULL && texto != NULL) {
        // Crear una nueva fila vacía
        TFila nuevaFila = createRow();

        // Crear una nueva línea vacía
        TLinea nuevaLinea = createLine();

        // Llenar la línea con los caracteres del texto
        for (int i = 0; texto[i] != '\0'; i++) {
            insertCharLine(texto[i], nuevaLinea);
        }

        // Insertar la línea en la fila
        insertRow(nuevaFila /*nuevaLinea*/);

        // Insertar la fila al comienzo del archivo
       nextRow(nuevaFila);
       insertRow (nuevaFila);
    }
}
//pre-condicion El archivo tiene por lo menos una fila
//Ins0erta el texto "texto" al inicio de la primer fila del archivo
void insertChartsFirstRow(TArchivo &archivo, Cadena texto){
  if (archivo != NULL && texto != NULL && archivo->fila != NULL) {
        // Crear una nueva línea vacía
        TLinea nuevaLinea = createLine();

        // Llenar la línea con los caracteres del texto
        for (int i = 0; texto[i] != '\0'; i++) {
            insertCharLine(texto[i], nuevaLinea);
        }

        // Obtener la primera fila del archivo
        TFila primeraFila = archivo->fila;

        // Insertar la línea al inicio de la primera fila
        insertRow(primeraFila);
    }
}

//si valor == true se le asigna el permiso de escritura de "archivo"
//si valor == false se le quita el permiso de escritura de "archivo"
//pre-condicion archivo !=NULL
void setWritePermission(TArchivo &archivo, bool valor){

}

//elimina toda la memoria utilizada por "archivo"
void destroyFile (TArchivo &archivo){

}
