#include "Sistema.h"
#include "Nodo_canciones.h"
using namespace std;
#include <iostream>
#include <sstream>
Sistema::Sistema()
{
    repetir = nada;
    canciones = nullptr;
    actual = nullptr;
    regristrado = nullptr;
    reproducir = false;
    modoRandom = false;


}
void Sistema::iniciar(){
    char opcion;
    cargarcancioes("music_source.txt");
    cargarestado("status.cfg");

    mostrarActual();
    do {

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
            case 'R':
                 opcion5();
                 break;
            case 'A':
                opcion6();
                break;
            case 'L':
                opcion7();
                break;

            case 'X':
                modificarEstadoarch();
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

void Sistema::opcion1(){ //-------------------------
   if(actual == nullptr){
    return;
   }
   reproducir  = !reproducir;
    espacio_linea();
    mostrarActual();

    espacio_linea();
    modificarEstadoarch();

}

void Sistema::opcion2(){//-------------------------
   if(actual !=nullptr && actual->anterior != nullptr){
      actual = actual->anterior;
      mostrarListaActual();
      }
    modificarEstadoarch();
    mostrarListaActual();

}
void Sistema::opcion3(){//-------------------------
    pistaSgte();
    mostrarListaActual();

    modificarEstadoarch();
}
void Sistema::opcion4(){//-------------------------
    if(actual == nullptr){return;}
    modoRandom = !modoRandom;

    if(modoRandom){
        cout<<"(S) ";
        mezclarRandom();
        mostrarListaActual();

    }else{
    cout<<"(Modo aleatorio desactivado) ";
    mostrarListaActual();
    }
    modificarEstadoarch();

}
 void Sistema::opcion5(){//-------------------------
    if(actual == nullptr){return;}
    if(repetir == nada){
        repetir = repetirUnavez;
    }else if(repetir == repetirUnavez){
        repetir = repetirTODO;
    }else{repetir =nada;}
    if(repetir == repetirUnavez){
        cout<<"(R) ";
    }else if(repetir == repetirTODO){
        cout<<"(RA) ";
    }
    if(modoRandom){
        cout<<"(S) ";
    }
    mostrarListaActual();
    modificarEstadoarch();


 }
 void Sistema::opcion6(){//-----------------------
    if(actual == nullptr){return;}
    espacio_linea();
    mostrarListaActual();
    espacio_linea();
    cout<<"Lista de reproduccion actual:"<< endl;
    Nodo_canciones* sigCancionEnLista = actual->siguiente;
    int num = 1;

    if(sigCancionEnLista == nullptr){
        char valor;
        cout<<"Vacia"<<endl;
        cout<<"Opciones:"<<endl;
        cout<<"V - volver al menu principal: ";
        cin>> valor;
        valor = toupper(valor);
        return;
     }
     while(sigCancionEnLista != nullptr){
        cout<< num<<". "<<sigCancionEnLista->dato.nombre<<" - "<<sigCancionEnLista->dato.artista<<endl;
        sigCancionEnLista = sigCancionEnLista->siguiente;
        num++;
      }
    espacio_linea();
    char valor;

    cout<<"Opciones:"<<endl;
    cout<<"S<num> - Saltar a la cancion seleccionada"<<endl;
    cout<<"V - Volver al menu principal"<<endl;
    cout<<"Eliga una opcion: ";
    cin >> (valor);
    valor = toupper(valor);
    while(valor != 'V' && valor != 'S'){
        cout<<"Opcion invalida, reingrese (S o V): ";
        cin>> valor;
        valor = toupper(valor);
    }
    valor = toupper(valor);

    if(valor == 'V'){  mostrarListaActual(); return;}
    if(valor == 'S'){
    int numero;
    cout<<"Eliga el numero de la cancion a saltar (solo numeros permitidos): ";
    cin>> numero; // se da por hecho que el usuario solo ingresara  un numero de la lista

    saltoCancion(numero);
    }
    espacio_linea();
    mostrarListaActual();
    modificarEstadoarch();
 }

 void Sistema::opcion7(){//--------------
    if(actual == nullptr){
        cout<<"Sin canciones registradas"<<endl;
        return;
    }else{
        char opcion;
        string nombrecancion,nombrearts,fecha,tiempo,ruta;
        do{
            mostrarListaActual();
            mostrarSubMenuOpcionL();
            cout<<"Eliga una opcion:";
            cin >>opcion;
            opcion = toupper(opcion);
            switch(opcion){
                case 'R':
                    int num;
                    cout<<"Seleccione el numero de la cancion (solo valores enteros permitidos): ";
                    cin>>num;
                    saltoCancion(num); // salta cancion
                    mostrarListaActual(); // reproduce
                    mezclarRandom();
                    break;
                case 'A':
                    int numero;
                    cout<<"Seleccione el numero de la cancion (solo valores enteros permitidos): ";
                    cin>>numero;
                    moverCancionAlFinal(numero);
                    break;
                case 'N':
                    espacio_linea();
                    cout <<"Agregar cancion al registro"<<endl;
                    espacio_linea();
                    cout<<"Nombre de la cancion; ";
                    cin>>nombrecancion;
                    cout<<"Nombre del artista; ";
                    cin>>nombrearts;
                    cout<<"Año de lanzamiento; ";
                    cin>>fecha;
                    cout<<"Tiempo en segundos; ";
                    cin>>tiempo;
                    cout<<"Ruta ubicacion del archivo; ";
                    cin>>ruta;
                    agregarCancionAltxt( nombrecancion, nombrearts, fecha, tiempo, ruta);
                    break;
                case 'D':
                    int numeroBorrar;
                    cout<<"Seleccione el numero de la cancion a borrar (solo valores enteros permitidos): ";
                    cin>>numeroBorrar;
                    borrarCancion(numeroBorrar);
                    break;
            }
        }while(opcion != 'V');
        mostrarListaActual();
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
void Sistema::cargarestado(const string& nombrearch){} // {ñ{ññ{{ñt{ñtr

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
    cout <<"("<< actual->dato.id <<") " <<actual->dato.nombre<<endl;
    cout << "Artista: " << actual->dato.artista << endl;
    cout << "Album: " << actual->dato.album<< " [" << actual->dato.fecha << "]" << endl;
}
void Sistema::pistaSgte(){
    if(todo == nullptr){
        return;
    }
    if(repetir == repetirUnavez){return;}
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
     if(actual->siguiente == nullptr){
        actual = canciones;
        if(modoRandom){
            mezclarRandom();
        }
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

void Sistema::mostrarListaActual(){ //----------------------------
    cout <<"Actual ("<< actual->dato.id<<"): "<< actual->dato.nombre<< " - "<<actual->dato.artista<<endl;
}
void Sistema::saltoCancion(int numero){ //-------------------
    Nodo_canciones* saltoNuevo = actual->siguiente;
     if (saltoNuevo == nullptr) {return;}
    int lugar = 1;

    while(saltoNuevo != nullptr&& lugar<numero){
            saltoNuevo = saltoNuevo->siguiente;
            lugar++;
    }
    actual = saltoNuevo;
    reproducir = true;
}
void Sistema::modificarEstadoarch(){//--------------------
    ofstream arch("status.cfg");
    Nodo_canciones* temporal;
    if(actual == nullptr){return;}
    if (arch.fail()){return;}

    if(actual != nullptr){
        arch<<"ACTUAL(id): "<<actual->dato.id<<endl;
        temporal = actual->siguiente;
    }else{
        temporal = nullptr;
    }
    arch<<"REPRODUCIENDO: "<<actual->dato.nombre<<endl;
    arch<<"ESTADO MODO ALEATORIO: ";
    if(modoRandom){ // 1 SI ESTA ACTIVADO
       arch<<"1"<<endl;
    }else{
        arch<<"0"<<endl;
    }
    arch<<"REPETICION: "<< repetir<<endl;
    arch<<"LISTA PENDIENTE: ";
    while(temporal != nullptr){
        arch<< temporal->dato.id;
        if(temporal->siguiente != nullptr){
            arch<<",";
        }
        temporal = temporal->siguiente;
    }arch<<endl;
    arch.close();
}
void Sistema::listarRegistro(){


}
void Sistema::mostrarSubMenuOpcionL(){
    espacio_linea();
    cout<<"Canciones registradas:"<<endl;
    Nodo_canciones* regristrado = actual->siguiente;
    int num = 1;
      while(regristrado != nullptr){
        cout<< num<<". "<<regristrado->dato.nombre<<" - "<<regristrado->dato.artista<<endl;
        regristrado = regristrado->siguiente;
        num++;
      }
    espacio_linea();
    cout<<"Opciones:"<<endl;
    cout<<"R <num> - Reproducir cancion seleccionada"<<endl;
    cout<<"A <num> -  Agregar cancion seleccionada al final de la lista de reproduccion actual "<<endl;
    cout<<"N - Agregar cancion al registro de canciones "<<endl;
    cout<<"D<num> - Eliminar cancion seleccionada "<<endl;
    cout<<"V - Volver al menu principal "<<endl;
}

void Sistema::moverCancionAlFinal(int numero){
    if(actual == nullptr || numero < 0){return;}
    Nodo_canciones* copiaActual = actual;
    Nodo_canciones* anterior = nullptr;
    Nodo_canciones* ultimo = actual;
    int pos = 1;
    while(copiaActual != nullptr && pos < numero){
        anterior = copiaActual;
        copiaActual = copiaActual ->siguiente;
        pos++;
    }
    if(copiaActual->siguiente == nullptr){return;}
    if(anterior != nullptr){
        anterior->siguiente = copiaActual->siguiente;
        copiaActual->siguiente->anterior = anterior;
    }else{
        actual = copiaActual->siguiente;
        actual->anterior = nullptr;
    }
    while(ultimo ->siguiente != nullptr){
        ultimo = ultimo->siguiente;
    }
    ultimo->siguiente = copiaActual;
    copiaActual->anterior = ultimo;
    copiaActual->siguiente = nullptr;

}
void Sistema::agregarCancionAltxt(string nombrecancion,string nombrearts,string fecha,string tiempo,string ruta){
    ofstream archivo("music_source.txt");
    archivo<<nombrecancion<<";"<<nombrearts<<";"<<fecha<<";"<<tiempo<<";"<<ruta<<endl;
    archivo.close();
}
void Sistema::borrarCancion(int numero){
    if(actual == nullptr || numero < 0){return;}
    Nodo_canciones* actualizar = actual;

    if(numero ==1){
        delete actualizar;
        borrarDelArch(numero);
        return;
    }
    int posicion  =1;
    Nodo_canciones* antes = nullptr;
    while(actualizar != nullptr && posicion <= numero){
        antes = actualizar;
        actualizar = actualizar->siguiente;
        posicion++;
    }
    antes->siguiente = actualizar->siguiente;
    delete actualizar;
    borrarDelArch(numero);

}
void Sistema::borrarDelArch(int numero){
    ifstream entrada("music_source.txt");
    ofstream salir("copia.txt");

    string linea;
    int suma = 1;
    while(getline(entrada,linea)){
       if(suma != numero){
        salir<<linea<<endl;
       }suma++;
    }
    entrada.close();
    salir.close();
    remove("music_source.txt");

}




