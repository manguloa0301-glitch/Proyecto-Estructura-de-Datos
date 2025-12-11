#include "ArbolContactos.h"
#include <iostream>

using namespace std;

//constructor del arbol
ArbolContactos::ArbolContactos() {
    raiz = NULL;
}
//funcion recursiva
NodoArbol* ArbolContactos::insertar(NodoArbol* nodo, Contacto c) {
    // Si no existe nodo, se crea uno nuevo
    if (nodo == NULL) {
        return new NodoArbol(c);
    }
    // Si el nombre es menor al del nodo actual, va a la izquierda
    if (c.getNombre() < nodo->dato.getNombre()) {
        nodo->izquierda = insertar(nodo->izquierda, c);
    }
    // Si es mayor o igual, va a la derecha
    else {
        nodo->derecha = insertar(nodo->derecha, c);
    }
    // Devuelve el nodo actual para mantener el enlace
    return nodo;
}
//metodo para insertar contactos
void ArbolContactos::insertarContacto(const Contacto& c) {
    raiz = insertar(raiz, c);
}
//funcion para imprimir el arbol de manera visual
void ArbolContactos::imprimirArbol(NodoArbol* nodo, int espacio, int distancia) {
    //caso base
    if (nodo == NULL) return;
    //incrementa la identacion 
    espacio += distancia;
    //imprime el subarbol derecho
    imprimirArbol(nodo->derecha, espacio);
    //imprime la separacion
    cout << endl;
    for (int i = distancia; i < espacio; i++) cout << " ";
    //muestra el nombre
    cout << nodo->dato.getNombre() << endl;
    //imprime el subarbol izquierdo
    imprimirArbol(nodo->izquierda, espacio);
}
//metodo para presentar el arbol completo
void ArbolContactos::mostrarArbol() {
    cout << "\n--- Visualizacion del arbol de contactos ---\n";
    //llama la funcion recursiva
    imprimirArbol(raiz);
    cout << endl;
}
//funcion recursiva para buscar un contacto
NodoArbol* ArbolContactos::buscar(NodoArbol* nodo, string nombre) {
    // Si el nodo es NULL o encuentra coincidencia, devuelve nodo
    if (nodo == NULL || nodo->dato.getNombre() == nombre) {
        return nodo;
    }
    // Si el nombre buscado es menor, buscar en la izquierda
    if (nombre < nodo->dato.getNombre()) {
        return buscar(nodo->izquierda, nombre);
    }
    // Si es mayor, buscar en la derecha
    else {
        return buscar(nodo->derecha, nombre);
    }
}
//metodo para buscar contactos
NodoArbol* ArbolContactos::buscarContacto(string nombre) {
    return buscar(raiz, nombre);
}
//recorrido inorden
void ArbolContactos::inorden(NodoArbol* nodo) {
    if (nodo == NULL) return;
    //1.visita izquierda
    inorden(nodo->izquierda);
    cout << nodo->dato.getNombre() << " - "
        << nodo->dato.getTelefono() << " - "
        << nodo->dato.getCorreo() << endl;
    //3.visita derecha
    inorden(nodo->derecha);
}
//metodo para mostrar inorden
void ArbolContactos::recorrerInorden() {
    cout << "\n--- Recorrido INORDEN ---\n";
    inorden(raiz);
}
//recorrido preorden
void ArbolContactos::preorden(NodoArbol* nodo) {
    if (nodo == NULL) return;
    //1.visita raiz
    cout << nodo->dato.getNombre() << " - "
        << nodo->dato.getTelefono() << " - "
        << nodo->dato.getCorreo() << endl;
    //2.visita izquierda
    preorden(nodo->izquierda);
    //3.visita derecha
    preorden(nodo->derecha);
}
//metodo para mostrar preorden
void ArbolContactos::recorrerPreorden() {
    cout << "\n--- Recorrido PREORDEN ---\n";
    preorden(raiz);
}