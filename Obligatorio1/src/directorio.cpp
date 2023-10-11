/* 1111111 */ // sustituiir con los 7 dígitos de la cédula

#define MAX_NOMBRE 15

#include "../include/linea.h"
#include "../include/fila.h"
#include "../include/directorio.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>


typedef char* Cadena;
/*
struct _rep_directorio {
    Cadena nombre;
    TDirectorio sig; //puntero a TDirectorio siguiente
    TDirectorio ant; // puntero al TDirectorio anterior
    TDirectorio root; //puntero al primer TDirectorio RAIZ
    TArchivo* arch_sig;
    TArchivo arch_ant;
    TArchivo arch; //Puntero al archivo en el que estoy
    int numArchivos;
};*/

struct listaArchivo{
     TArchivo archivo;
     listaArchivo* sig;
};

struct _rep_directorio {
    char* nombre;
    listaArchivo* cabeza; 
    int numArchivos;
};
typedef struct _rep_directorio *TDirectorio;


//Crea el directorio de nombre Raíz del filesystem 
TDirectorio createRootDirectory(){
    TDirectorio raiz;
    raiz=new(_rep_directorio);
    char nombre[]= "raiz";
    raiz->nombre=(char*)malloc(strlen(nombre)+1);// +1 PARA EL CARACTER NULO
    strcpy(raiz->nombre, nombre);
    raiz->numArchivos=0;
    return raiz;
}


//retorna true si el directorio "directorio" no tiene archivos
bool isEmptyDirectory(TDirectorio directorio){//MIRARLA MEJOR
    if(directorio->numArchivos==0){
        return true;
    }
    else{
        return false;
    }
}

//retorna true si el archivo de nombre "nombreArchivo existe en el directorio "directorio"
bool existFileDirectory(TDirectorio directorio, Cadena nombreArchivo){

        listaArchivo* actual = directorio -> cabeza;
        while(actual != NULL){
            if (strcmp(getFileName(actual->archivo), nombreArchivo)==0) {
            // Se encontró el archivo, devuelve true
            return true;
        }
            actual = actual->sig;
        }
        //caso contrario
        return false;
    }



//pre-condicion existe el archivo de nombre nombreArchivo en el directorio "directorio"
//pos-condicion: retorna un puntero al archivo de nombre "nombreArchivo"
TArchivo getFileDirectory(TDirectorio directorio, Cadena nombreArchivo){

    if(existFileDirectory( directorio, nombreArchivo)){
        listaArchivo* actual = directorio->cabeza;
        while (actual != NULL) {
            if (strcmp(getFileName(actual->archivo), nombreArchivo)==0) {
                // Se encontró el archivo, devuelve un puntero a la estructura TArchivo
                return actual->archivo;
            }   
            actual = actual->sig;
        }
        
    }        
    return NULL;
}

//pre-condicion: No existe en directorio un archivo de nombre "nombreArchivo"
//crea un archivo vacio con nombre nombreArchivo y permiso de lectura/escritura
void createFileInDirectory(TDirectorio &directorio, Cadena nombreArchivo){
    
    if(!existFileDirectory( directorio, nombreArchivo)){
        // Inicializar el nuevoArchivo
        listaArchivo* aux = new listaArchivo;
        TArchivo nuevoArchivo = createEmptyFile(nombreArchivo, nombreArchivo);
        aux -> sig = NULL;

            if (directorio->cabeza == NULL) {   
                // Si la lista está vacía, el nuevo archivo se convierte en el primer elemento
                directorio->cabeza = aux;     
            } else {
                // Si la lista no está vacía, recorremos la lista hasta el último elemento
                
                listaArchivo* actual = directorio->cabeza;
                while (actual->sig != NULL) {
                    actual = actual->sig;
                }
                // Agregamos el nuevo archivo al final
                actual->archivo = nuevoArchivo;
            }
        directorio->numArchivos++;    
    } 
}
/*
//pre condicion: el archivo nombreArchivo existe en directorio
//pos-condicion: inserta una nueva fila al comienzo del archivo nombreArchivo conteniendo los chars texto
void insertTextFile(TDirectorio& directorio, Cadena nombreArchivo, Cadena texto){

    // Abrir el archivo en modo de lectura y escritura
    TArchivo archivo = getFileDirectory(directorio, nombreArchivo);

    // Leer el contenido actual del archivo
   TLinea contenidoActual = getFirstRow(archivo);

    // Concatenar el nuevo texto al contenido actual
    Cadena nuevoContenido = (Cadena)malloc(strlen(texto) + getCountChars(archivo) + 2); // +2 para el '\n' y '\0'
    strcpy(nuevoContenido, texto);
    strcat(nuevoContenido, "\n");
    strcat(nuevoContenido, contenidoActual);

    // Insertar el nuevo contenido en el archivo
    insertCharsFileFirstLine(directorio, nombreArchivo, nuevoContenido);
}

*/


//pre condicion: el archivo nombreArchivo existe en directorio
//pos-condicion: agrega al comienzo de la primera fila del archivo de nombre nombreArchivo los caracteres de texto
//desplazando los caracteres existentes hacia la derecha
void insertCharsFileFirstLine(TDirectorio& directorio, Cadena nombreArchivo, Cadena texto){}

//pre-condicion: existe el archivo de nombre "nombreArchivo" en el directorio "directorio"
//pos-condicion: elimina el archivo del directorio "directorio" y toda la memoria utilizada por este.
void deleteFileDirectory(TDirectorio& directorio, Cadena nombreArchivo){}

//pre-condicion: existe el archivo de nombre "nombreArchivo" en el directorio "directorio"
//pos-condicion: elimina los "cantidad" caracteres iniciales del archivo nombreArchivo
void deleteCharsFile(TDirectorio& directorio, Cadena nombreArchivo, int cantidad){}

//pre-condicion: existe el archivo de nombre "nombreArchivo" en el directorio "directorio"
//pos-condicion: le setea el permiso de escritura al archivo de nombre nombreArchivo
void setFilePermission(TDirectorio& directorio, Cadena nombreArchivo, bool permisoEscritura){}

//pre-condicion: existe el archivo de nombre "nombreArchivo" en el directorio "directorio"
//pos-condicion: imprime el contenido del archivo "nombreArchivo"
void printFile(TDirectorio& directorio, Cadena nombreArchivo){}

//pos-condicion destruye toda la memoria de directorio
void destroyDirectory (TDirectorio &directorio){}
