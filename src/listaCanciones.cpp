#include <iostream>
#include "listaCanciones.h"
using namespace std;
void inicializarLista(Nodo_canciones*& cabeza, Nodo_canciones*& cola){
    cabeza = NULL;
    cola = NULL;
}
void agregarCancion(Nodo_canciones*& cabeza, Nodo_canciones*& cola, Cancion cancion){
    Nodo_canciones* nuevo= new Nodo_canciones;
    nuevo->dato = cancion;
    nuevo->siguiente = NULL;
    nuevo->anterior  = cola;

    if(cabeza == NULL){
        cabeza = nuevo;
    }else{
        cola->siguiente = nuevo;
    }
    cola = nuevo;


}
void mostrarLista(Nodo_canciones* cabeza){
    Nodo_canciones* copia = cabeza;
    int i=1;
    while(copia != NULL){
        cout<< i<<". ";
        cout<< copia->dato.nombre<<" - "<<copia->dato.artista<<endl;
        copia->siguiente;

    }

}
