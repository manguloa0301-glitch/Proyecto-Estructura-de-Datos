#ifndef LISTA_ENLAZADA_H
#define LISTA_ENLAZADA_H

#include "Contacto.h"
#include <iostream>
using namespace std;

struct Nodo {
    Contacto dato;
    Nodo* siguiente;

    Nodo(Contacto c) {
        dato = c;
        siguiente = NULL;
    }
};

class ListaEnlazada {
private:
    Nodo* cabeza;

public:
    ListaEnlazada();
    ~ListaEnlazada();
    void insertar(Contacto c);
    void eliminar(string nombre);
    void mostrar() const;
};

#endif
