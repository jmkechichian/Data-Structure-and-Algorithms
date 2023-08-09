
struct Nodo {
	int valor;
	Nodo *siguiente;
};

typedef Nodo * nodoLista;

//Declarar Lista de ListsEnteros

struct Lista {
	nodolista primero;
	nodolista ultimo;
	int cantidad;
};


ListaEnteros crearListaEnteros(){

	ListaEnteros lista = new ListaEnteros;
	lista -> primero = NULL;
	lista -> ultimo = NULL;
	lista -> cantidad = 0;
	return lista;
}

bool esVaciaListaEnteros(ListaEnteros lista){
    return lista -> cantidad == 0;
}
    
    
void agregarEnteroLista(ListsEnteros &lista, int entero){

    nodoLista aux = new Nodo;
        aux -> valor = valor;
        aux -> siguiente = NULL;
        if ( esVaciaListaEnteros(lista)) { // tambien se puede usar lista = NULL
            lista -> primero = aux;
            lista -> ultimo = aux;
        }
        else { 
            lista -> ultimo -> siguiente = aux;
            lista -> ultimo = aux;
            aux = NULL;
            }
        lista -> cantidad++;
    }

int primeroListaEntero (ListaEntero lista){
    
    return lista -> primero -> valor;
}

void eliminarPrimeroLista(ListaEntero &lista){
    nodoLista aux = lista -> primero; 
    if(lista -> primero -> siguiente == NULL){
        delete lista -> primero;
        lista -> primero = NULL;
        lista -> ultimo = NULL;
        aux = NULL;
    }
    else {
        lista -> primero = lista -> primero -> siguiente;
        delete aux;
        aux = NULL;
    }
    lista -> cantidad--;
}

void destruirListaEnteros(ListaEnteros &lista){
    nodoLista aux = lista -> primero;
    while (!esVaciaListaEnteros(lista)){
        lista -> primero = lista -> primero -> siguiente;
        delete aux;
        aux = lista -> primero;
    }
    lista -> primero = NULL;
    lista -> ultimo = NULL;
    delete lista;
}

void imprimirLista (ListaEnteros &lista){
    printf("[");
    int cant = cantindadEnterosLista(lista);
    for(int i = 1; i <= cant; i++){
        if(i == cant){
            printf("%d]\n", primeroListaEntero(lista));
            eliminarPrimeroLista(lista);
        }
        else{
            printf("%d-", primeroListaEntero(lista));
            eliminarPrimeroLista(lista);
        }
    }
}

