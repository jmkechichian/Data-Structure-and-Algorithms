/* 1111111 */ // sustituiir con los 7 dígitos de la cédula

#include "../include/linea.h"
#include "../include/fila.h"
#include "../include/directorio.h"

/*
struct TDirectorio {
    char nombre[MAX_NOMBRE];
    TArchivo *primerArchivo; //puntero a la lista de archivos dentro del _rep_directorio

};

//Crea el TDirectorio de nombre Raíz del filesystem 
TDirectorio createRootDirectory(){
    TDirectorio directorio = new TDirectorio;
    directorio -> nombre = "RAIZ";
    directorio -> TArchivo = NULL;
    return directorio;
}

//retorna true si el directorio "directorio" no tiene archivos
bool isEmptyDirectory(TDirectorio directorio){
    return directorio -> TArchivo == NULL;
}

//retorna true si el archivo de nombre "nombreArchivo existe en el directorio "directorio"
bool existFileDirectory(TDirectorio directorio, Cadena nombreArchivo){
 //buscar en la lista archivos del directorio
    bool encontre = false;
    while (!encontre && !isEmptyDirectory(directorio)){
     if(directorio -> TArchivo -> archivoLista -> archivoNombre == nombreArchivo){
        encontre = true;
     } else {
         directorio = directorio -> TArchivo -> archivoLista ->
          siguiente;
         }
    } return encontre;
};
   
//pre-condicion existe el archivo de nombre nombreArchivo en el directorio "directorio"
//pos-condicion: retorna un puntero a UN TIPO archivo de nombre "nombreArchivo"
TArchivo getFileDirectory(TDirectorio directorio, Cadena nombreArchivo){
    // existFileDirectory (archivo) = true
    
}

//pre-condicion: No existe en directorio un archivo de nombre "nombreArchivo"
//crea un archivo vacio con nombre nombreArchivo y permiso de lectura/escritura
void createFileInDirectory(TDirectorio& directorio, Cadena nombreArchivo){
    //bool existFileDirectory ("nombreArchivo") = false
    //create new archivo
    //VERIFICAR SI LA LISTA DE ARCHIVOS ESTA VACIA O NO DENTRO DEL DIRECTORIO
    //acomodar punteros dependiendo condiciones
}

//pre condicion: el archivo nombreArchivo existe en directorio
//pos-condicion: inserta una nueva fila al COMIENZO DEL ARCHIVO nombreArchivo conteniendo los chars texto
void insertTextFile(TDirectorio& directorio, Cadena nombreArchivo, Cadena texto){
    //bool existFileDirectory ("nombreArchivo") = true
    //new fila
}

//pre condicion: el archivo nombreArchivo existe en directorio
//pos-condicion: agrega al comienzo de la primera fila del archivo de nombre nombreArchivo los caracteres de texto
//desplazando los caracteres existentes hacia la derecha
void insertCharsFileFirstLine(TDirectorio& directorio, Cadena nombreArchivo, Cadena texto){
    //bool existFileDirectory ("nombreArchivo") = true
    //insertar caracter en fila
}

//pre-condicion: existe el archivo de nombre "nombreArchivo" en el directorio "directorio"
//pos-condicion: elimina el archivo del directorio "directorio" y toda la memoria utilizada por este.
void deleteFileDirectory(TDirectorio& directorio, Cadena nombreArchivo);
    //bool existFileDirectory ("nombreArchivo") = true



//pre-condicion: existe el archivo de nombre "nombreArchivo" en el directorio "directorio"
//pos-condicion: elimina la "cantidad" caracteres iniciales del archivo nombreArchivo
void deleteCharsFile(TDirectorio& directorio, Cadena nombreArchivo, int cantidad);
    //bool existFileDirectory ("nombreArchivo") = true



//pre-condicion: existe el archivo de nombre "nombreArchivo" en el directorio "directorio"
//pos-condicion: le setea el permiso de escritura al archivo de nombre nombreArchivo
void setFilePermission(TDirectorio& directorio, Cadena nombreArchivo, bool permisoEscritura);
    //bool existFileDirectory ("nombreArchivo") = true


//pre-condicion: existe el archivo de nombre "nombreArchivo" en el directorio "directorio"
//pos-condicion: imprime el contenido del archivo "nombreArchivo"
void printFile(TDirectorio& directorio, Cadena nombreArchivo);

//pos-condicion destruye toda la memoria de directorio
void destroyDirectory (TDirectorio& directorio);




*/