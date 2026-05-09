#include "Cancion.h"
Cancion::Cancion() {
    int id = 0;
    int fecha = 0;
    int duracion = 0;
}

Cancion::Cancion(int id, const string& artista, const string& album, int fecha, int duracion,const string& ruta){
    this->id = id;
    this->artista = artista;
    this->album = album;
    this->fecha = fecha;
    this->duracion = duracion;
    this->ruta = ruta;
}
