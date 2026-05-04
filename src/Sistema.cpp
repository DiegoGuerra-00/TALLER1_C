#include "Sistema.h"
#include "Nodo_canciones.h"
using namespace std;
#include <iostream>
#include <sstream>
Sistema::Sistema()
{
    canciones = nullptr;
    actual = nullptr;
    reproducir = false;
    modoRandom = false;

}
void Sistema::iniciar(){
    char opcion;
    cargarcancioes("music_source.txt");
    cargarestado("status.cfg");

    do {
        if (actual != nullptr) {
        espacio_linea();
        cout << "Actual: "
         << actual->dato.nombre << " - "
         << actual->dato.artista << endl;
        }
         opcion = mostrarMenu();

        switch(opcion){
            case 'W':
                opcion1();
                break;
            case 'Q':
                opcion2();
                break;
            case 'E':
                opcion3();
                break;
            case 'S':
                opcion4();
                break;

            case 'X':
                cout<< "Saliendo  del sistema..."<<endl;
                break;
            default:
                cout<< "opcion invalida"<<endl;
        }
    } while(opcion != 'X');


}
char Sistema::mostrarMenu(){
    char opcion;
    //cout << "Reproduciendo  (   ) : -----------"<<endl;
    //cout<< "Artista: -------"<< endl;
    //cout<< "Album: ----- (   ) [aaa]"<<endl;
    cout<<" "<<endl;
    cout<<"Opciones:"<<endl;
    cout<<"W - Reproducir/Pausar "<< endl;
    cout<< "Q - Pista Anterior "<< endl;
    cout<<"E - Pista Siguiente "<< endl;
    cout<<"S - Activar/Desactivar modo aleatorio"<< endl;
    cout<<"R - Repeticion (Desactivado/Repetir una/Repetir todas) "<<endl;
    cout<<"A - Ver lista de reproduccion actual "<<endl;
    cout<<"L - Listado de canciones"<< endl;
    cout<<"X - Salir "<< endl;
    cout<<"Ingrese Opcion: ";
    cin >> opcion;
    return toupper(opcion);
}

void Sistema::opcion1(){
   if(actual == nullptr){
    return;
   }
   reproducir  = !reproducir;
    espacio_linea();
    mostrarActual();
    espacio_linea();

}

void Sistema::opcion2(){
   if(actual !=nullptr && actual->anterior != nullptr){
      actual = actual->anterior;
      }

}
void Sistema::opcion3(){
    pistaSgte();
}
void Sistema::opcion4(){
    if(actual == nullptr){return;}
    modoRandom = !modoRandom;

    if(modoRandom){
        cout<<"(S) ";
        mezclarRandom();
    }else{
    cout<<"(Modo aleatorio desactivado) ";
    }

}
void Sistema::espacio_linea(){
    cout<<" " << endl;
}

void Sistema::cargarcancioes(const string& nombrearch){
    ifstream archivo;
    archivo.open(nombrearch,ios::in);
    string linea;
    if (archivo.fail()){
        espacio_linea();
        cout<<"Archivo vacio, verifique que " << nombrearch<<" este bien implementado"<<endl;
        espacio_linea();
        return;
    }
    while(getline(archivo,linea)){

        stringstream separador(linea);
        Nodo_canciones* nuevo = new Nodo_canciones();

        getline(separador,nuevo->dato.id, ',');
        getline(separador, nuevo->dato.nombre, ',');
        getline(separador, nuevo->dato.artista, ',');
        getline(separador, nuevo->dato.album, ',');
        getline(separador, nuevo->dato.fecha, ',');
        getline(separador, nuevo->dato.duracion, ',');
        getline(separador, nuevo->dato.duracion, ',');

        nuevo->siguiente = nullptr;
        nuevo->anterior = nullptr;
        agregarCancion(nuevo);



    }
    archivo.close();
}
void Sistema::cargarestado(const string& nombrearch){}

void Sistema::agregarCancion(Nodo_canciones* nueva) {
    nueva ->siguiente = nullptr;
    nueva ->anterior= nullptr;
    if (canciones == nullptr) {
        canciones = nueva;
        actual = nueva;
    } else {
        Nodo_canciones* aux = canciones;
        while (aux->siguiente != nullptr) {
            aux = aux->siguiente;
        }
        aux->siguiente = nueva;
        nueva->anterior = aux;
    }
}
void Sistema::mostrarActual(){
    if(actual== nullptr){
        cout<<"Actual: ----"<<endl;
        cout<<"Artista: ----"<< endl;
        cout<<"Album: -----[---]"<<endl;
        return;

    }
    if(reproducir){
        cout<<"Reproduciendo: ";
    }else{cout<<"En pausa: ";}
    cout <<"("<< actual->dato.id <<")" << ": "<< actual->dato.nombre<<endl;
    cout << "Artista: " << actual->dato.artista << endl;
    cout << "Album: " << actual->dato.album<< " [" << actual->dato.fecha << "]" << endl;
}
void Sistema::pistaSgte(){
    if(todo == nullptr){
        return;
    }
    if(actual != nullptr && actual->siguiente != nullptr){
        actual=actual->siguiente;
        return;
    }
    if(actual == nullptr){
        actual = canciones;
        reproducir = true;
        mostrarActual();
        return;
    }
     if (actual->siguiente != nullptr) {
        actual = actual->siguiente;
        reproducir = true;
        mostrarActual();
        return;
     }
        actual = canciones;
        reproducir = true;
        mostrarActual();



}
void Sistema::mezclarRandom(){
     if (actual == nullptr) {return;}
     Nodo_canciones* nuevo_inicio = actual->siguiente;
     Nodo_canciones* nuevo_final = nullptr;

     while(nuevo_inicio!= nullptr){
        Nodo_canciones* nuevo_siguiente = nuevo_inicio->siguiente;
        nuevo_inicio->siguiente = nuevo_final;
        nuevo_inicio->anterior = nuevo_siguiente;
        nuevo_final = nuevo_inicio;
        nuevo_inicio = nuevo_siguiente;
     }
     actual->siguiente = nuevo_final;
     nuevo_final->anterior = actual;



}

