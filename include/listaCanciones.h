#ifndef LISTACANCIONES_H_INCLUDED
#define LISTACANCIONES_H_INCLUDED

#include "Nodo_canciones.h"

void inicializarLista(Nodo_canciones*& cabeza, Nodo_canciones*& cola);
void agregarCancion(Nodo_canciones*& cabeza, Nodo_canciones*& cola, Cancion c);
void mostrarLista(Nodo_canciones* cabeza);



#endif // LISTACANCIONES_H_INCLUDED
