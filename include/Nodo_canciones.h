#ifndef NODO_CANCIONES_H
#define NODO_CANCIONES_H


#include "Cancion.h"

struct Nodo_canciones{
    Cancion dato;
    Nodo_canciones* siguiente;
    Nodo_canciones* anterior;
};

#endif

