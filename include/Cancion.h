#ifndef CANCION_H
#define CANCION_H
#include <string>




struct Cancion {
    std::string id;
    std::string nombre;
    std::string artista;
    std::string album;
    std::string fecha;
    std::string duracion;
    std::string ruta;
};

#endif // CANCION_H
