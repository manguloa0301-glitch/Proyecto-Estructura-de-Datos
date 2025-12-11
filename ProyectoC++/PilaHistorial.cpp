#include "PilaHistorial.h"
#include <iostream>

using namespace std;

//constructor
PilaHistorial::PilaHistorial() {
    tope = -1;
}
//metodo para verificar si la pila está llena
bool PilaHistorial::estaLlena() const {
    return tope == MAX - 1;
}
//metodo para verificar si la pila esta vacia
bool PilaHistorial::estaVacia() const {
    return tope == -1;
}
//push para insertar una operacion en la pila
void PilaHistorial::push(const string& operacion) {
    if (estaLlena()) {
        cout << "El historial esta lleno.\n";
        return;
    }
    // Avanza una posición en la pila
    tope++;
    // Guarda la operacion en la nueva posicion
    elementos[tope] = operacion;
}

// pop para eliminar la ultima operacion guardada
void PilaHistorial::pop() {
    if (estaVacia()) {
        cout << "El historial esta vacio.\n";
        return;
    }
    // Retrocede un espacio, lo anterior queda fuera del historial
    tope--;
}
//top para obtener la ultima operacion
string PilaHistorial::top() const {
    if (estaVacia()) {
        return "Historial vacio";
    }
    // Devuelve la operacion en la cima
    return elementos[tope];
}
//cantidad de elementos en la pila:
int PilaHistorial::size() const {
    // Si tope = 2, hay 3 elementos
    return tope + 1;
}
//imprimir todo el historial
void PilaHistorial::mostrar() const {
    if (estaVacia()) {
        cout << "No hay operaciones registradas.\n";
        return;
    }

    cout << "\n--- HISTORIAL (ultima operacion primero) ---\n";
    // Recorre la pila desde el tope hasta la base
    for (int i = tope; i >= 0; i--) {
        cout << elementos[i] << endl;
    }
}