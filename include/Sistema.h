#ifndef SISTEMA_H
#define SISTEMA_H
#include "Nodo_canciones.h"
#include "listaCanciones.h"
#include <fstream>
using namespace std;
#include <iostream>


class Sistema
{
    public://-----publico
    Sistema();
    void iniciar();
    char mostrarMenu();
    void opcion1(); //w
    void opcion2(); //Q
    void opcion3(); //E
    void opcion4(); // S
    void opcion5(); // R
    void opcion6(); // A
    void opcion7(); // L



    void cargarcancioes(const string& nombrearch);
    void cargarestado(const string& nombrearch);
    void agregarCancion(Nodo_canciones* nueva);
    void espacio_linea();
    void mostrarActual();
    void pistaSgte();
    void mezclarRandom();

    private://----privado
    Nodo_canciones* canciones;
    Nodo_canciones* actual;
    Nodo_canciones* todo;
    bool reproducir;
    bool modoRandom;
    enum tipoRepeticion{
        nada,repetirUnavez,repetirTODO
    };
    tipoRepeticion repetir;
    void mostrarListaActual();
    void saltoCancion(int numero);

};

#endif
