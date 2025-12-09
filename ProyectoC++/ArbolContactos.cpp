#include "ArbolContactos.h"

ArbolContactos::ArbolContactos() {
    raiz = NULL;
}

NodoArbol* ArbolContactos::insertar(NodoArbol* nodo, Contacto c) {
    if (nodo == NULL) {
        return new NodoArbol(c);
    }

    if (c.getNombre() < nodo->dato.getNombre()) {
        nodo->izquierda = insertar(nodo->izquierda, c);
    }
    else {
        nodo->derecha = insertar(nodo->derecha, c);
    }

    return nodo;
}

void ArbolContactos::insertarContacto(const Contacto& c) {
    raiz = insertar(raiz, c);
}

void ArbolContactos::imprimirArbol(NodoArbol* nodo, int espacio, int distancia) {
    if (nodo == NULL) return;

    espacio += distancia;

    imprimirArbol(nodo->derecha, espacio);

    cout << endl;
    for (int i = distancia; i < espacio; i++) cout << " ";
    cout << nodo->dato.getNombre() << endl;

    imprimirArbol(nodo->izquierda, espacio);
}

void ArbolContactos::mostrarArbol() {
    cout << "\n--- Visualizacion del arbol de contactos ---\n";
    imprimirArbol(raiz);
    cout << endl;
}

NodoArbol* ArbolContactos::buscar(NodoArbol* nodo, string nombre) {
    if (nodo == NULL || nodo->dato.getNombre() == nombre) {
        return nodo;
    }

    if (nombre < nodo->dato.getNombre()) {
        return buscar(nodo->izquierda, nombre);
    }
    else {
        return buscar(nodo->derecha, nombre);
    }
}

NodoArbol* ArbolContactos::buscarContacto(string nombre) {
    return buscar(raiz, nombre);
}

void ArbolContactos::inorden(NodoArbol* nodo) {
    if (nodo == NULL) return;

    inorden(nodo->izquierda);
    cout << nodo->dato.getNombre() << " - "
        << nodo->dato.getTelefono() << " - "
        << nodo->dato.getCorreo() << endl;
    inorden(nodo->derecha);
}

void ArbolContactos::recorrerInorden() {
    cout << "\n--- Recorrido INORDEN ---\n";
    inorden(raiz);
}

void ArbolContactos::preorden(NodoArbol* nodo) {
    if (nodo == NULL) return;

    cout << nodo->dato.getNombre() << " - "
        << nodo->dato.getTelefono() << " - "
        << nodo->dato.getCorreo() << endl;
    preorden(nodo->izquierda);
    preorden(nodo->derecha);
}

void ArbolContactos::recorrerPreorden() {
    cout << "\n--- Recorrido PREORDEN ---\n";
    preorden(raiz);
}