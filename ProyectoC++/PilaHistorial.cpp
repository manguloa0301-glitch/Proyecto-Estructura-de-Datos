#include "PilaHistorial.h"
#include <iostream>
using namespace std;

PilaHistorial::PilaHistorial() {
    tope = -1;
}

bool PilaHistorial::estaLlena() const {
    return tope == MAX - 1;
}

bool PilaHistorial::estaVacia() const {
    return tope == -1;
}

void PilaHistorial::push(const string& operacion) {
    if (estaLlena()) {
        cout << "El historial esta lleno.\n";
        return;
    }
    tope++;
    elementos[tope] = operacion;
}

void PilaHistorial::pop() {
    if (estaVacia()) {
        cout << "El historial esta vacio.\n";
        return;
    }
    tope--;
}

string PilaHistorial::top() const {
    if (estaVacia()) {
        return "Historial vacio";
    }
    return elementos[tope];
}

int PilaHistorial::size() const {
    return tope + 1;
}

void PilaHistorial::mostrar() const {
    if (estaVacia()) {
        cout << "No hay operaciones registradas.\n";
        return;
    }

    cout << "\n--- HISTORIAL (ultima operacion primero) ---\n";
    for (int i = tope; i >= 0; i--) {
        cout << elementos[i] << endl;
    }
}