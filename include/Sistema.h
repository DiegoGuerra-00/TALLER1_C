#ifndef SISTEMA_H
#define SISTEMA_H
#include "Nodo_canciones.h"
#include "listaCanciones.h"
#include <fstream>
using namespace std;
#include <iostream>


class Sistema
{
    public:
        Sistema();

    void iniciar();
    char mostrarMenu();
    void opcion1();
    void opcion2();
    void opcion3();
    void opcion4();


    void cargarcancioes(const string& nombrearch);
    void cargarestado(const string& nombrearch);
    void agregarCancion(Nodo_canciones* nueva);
    void espacio_linea();
    void mostrarActual();
    void pistaSgte();
    void generarlistRandom();

    private:
    Nodo_canciones* canciones;
    Nodo_canciones* actual;
    Nodo_canciones* todo;
    bool reproducir;


};

#endif
