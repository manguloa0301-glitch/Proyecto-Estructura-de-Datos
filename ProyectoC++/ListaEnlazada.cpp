#include "ListaEnlazada.h"
#include <iostream>

using namespace std;

// Constructor: inicializa la lista enlazada vacia
ListaEnlazada::ListaEnlazada() {
    // La lista empieza sin nodos
    cabeza = NULL;
}
// Destructor: libera toda la memoria de los nodos al destruir la lista
ListaEnlazada::~ListaEnlazada() {
    // Comienza desde la cabeza
    Nodo* actual = cabeza;
    // Recorre todos los nodos eliminandolos
    while (actual != NULL) {
        // Guarda referencia temporal
        Nodo* temp = actual;
        // Avanza al siguiente nodo
        actual = actual->siguiente;
        // Libera nodo actual
        delete temp;
    }
}

void ListaEnlazada::insertar(Contacto c) {
    // Crea nodo en memoria dinamica
    Nodo* nuevo = new Nodo(c);
    // Si la lista esta vacia, el nuevo nodo se convierte en la cabeza
    if (!cabeza) {
        cabeza = nuevo;
    }
    else {
        // Si no esta vacia, recorre hasta el ultimo nodo
        Nodo* actual = cabeza;
        while (actual->siguiente != NULL)
            actual = actual->siguiente;
        // Inserta al final
        actual->siguiente = nuevo;
    }
}

void ListaEnlazada::eliminar(string nombre) {
    // Si la lista esta vacia, no hay nada que borrar
    if (!cabeza) {
        cout << "La lista esta vacia.\n";
        return;
    }
    // Caso especial: el contacto a eliminar esta en la cabeza
    if (cabeza->dato.getNombre() == nombre) {
        // Guarda el nodo que se eliminara
        Nodo* temp = cabeza;
        // Mueve la cabeza al siguiente nodo
        cabeza = cabeza->siguiente;
        // Libera memoria
        delete temp;
        cout << "Contacto eliminado.\n";
        return;
    }
    // Recorre buscando el nodo anterior al que se quiere eliminar
    Nodo* actual = cabeza;
    while (actual->siguiente != NULL && actual->siguiente->dato.getNombre() != nombre)
        actual = actual->siguiente;
    // Si llego al final sin encontrar el contacto
    if (actual->siguiente == NULL) {
        cout << "Contacto no encontrado.\n";
    }
    // El contacto existe: se elimina
    else {
        // Nodo que se eliminara
        Nodo* temp = actual->siguiente;
        // Enlaza alrededor del nodo
        actual->siguiente = temp->siguiente;
        // Libera nodo
        delete temp;
        cout << "Contacto eliminado.\n";
    }
}

void ListaEnlazada::mostrar() const {
    // Comienza en el primer nodo
    Nodo* actual = cabeza;
    // Recorre toda la lista imprimiendo cada contacto
    while (actual != NULL) {
        actual->dato.mostrar();
        // Llama al metodo mostrar() del contacto
        actual = actual->siguiente;
    }
}