#include "ListaEnlazada.h"

ListaEnlazada::ListaEnlazada() {
    cabeza = NULL;
}

ListaEnlazada::~ListaEnlazada() {
    Nodo* actual = cabeza;
    while (actual != NULL) {
        Nodo* temp = actual;
        actual = actual->siguiente;
        delete temp;
    }
}

void ListaEnlazada::insertar(Contacto c) {
    Nodo* nuevo = new Nodo(c);
    if (!cabeza) {
        cabeza = nuevo;
    }
    else {
        Nodo* actual = cabeza;
        while (actual->siguiente != NULL)
            actual = actual->siguiente;
        actual->siguiente = nuevo;
    }
}

void ListaEnlazada::eliminar(string nombre) {
    if (!cabeza) {
        cout << "La lista esta vacia.\n";
        return;
    }

    if (cabeza->dato.getNombre() == nombre) {
        Nodo* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
        cout << "Contacto eliminado.\n";
        return;
    }

    Nodo* actual = cabeza;
    while (actual->siguiente != NULL && actual->siguiente->dato.getNombre() != nombre)
        actual = actual->siguiente;

    if (actual->siguiente == NULL) {
        cout << "Contacto no encontrado.\n";
    }
    else {
        Nodo* temp = actual->siguiente;
        actual->siguiente = temp->siguiente;
        delete temp;
        cout << "Contacto eliminado.\n";
    }
}

void ListaEnlazada::mostrar() const {
    Nodo* actual = cabeza;
    while (actual != NULL) {
        actual->dato.mostrar();
        actual = actual->siguiente;
    }
}