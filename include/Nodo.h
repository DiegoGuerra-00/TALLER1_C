#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED
#include "Cancion.h"

struct Nodo {
    Cancion* dato;
    Nodo* siguiente;
    Nodo(Cancion* c)
};


#endif // NODO_H_INCLUDED
