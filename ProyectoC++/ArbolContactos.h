#ifndef ARBOL_CONTACTOS_H
#define ARBOL_CONTACTOS_H

#include <iostream>
#include <string>
#include "Contacto.h"
using namespace std;

struct NodoArbol {
    Contacto dato;
    NodoArbol* izquierda;
    NodoArbol* derecha;

    NodoArbol(Contacto c) : dato(c), izquierda(NULL), derecha(NULL) {}
};

class ArbolContactos {
private:
    NodoArbol* raiz;

    NodoArbol* insertar(NodoArbol* nodo, Contacto c);
    void imprimirArbol(NodoArbol* nodo, int espacio = 0, int distancia = 6);
    NodoArbol* buscar(NodoArbol* nodo, string nombre);
    void inorden(NodoArbol* nodo);
    void preorden(NodoArbol* nodo);

public:
    ArbolContactos();

    void insertarContacto(const Contacto& c);
    void mostrarArbol();
    void recorrerInorden();
    void recorrerPreorden();
    NodoArbol* buscarContacto(string nombre);
};

#endif
