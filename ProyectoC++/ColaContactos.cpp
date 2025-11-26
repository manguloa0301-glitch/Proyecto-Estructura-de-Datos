#include "ColaContactos.h"
#include <iostream>

using namespace std;

ColaContactos::ColaContactos() {
    frente = -1;
    final = -1;
}

bool ColaContactos::colaVacia() {
    return (frente == -1 || frente > final);
}

bool ColaContactos::colaLlena() {
    return (final == MAX_COLA - 1);
}

void ColaContactos::enqueue(const Contacto& c) {
    if (colaLlena()) {
        cout << "La cola esta llena, no se puede insertar el contacto: "
            << c.getNombre() << endl;
        return;
    }

    if (frente == -1)
        frente = 0;

    final++;
    arreglo[final] = c;

    cout << "Contacto encolado: " << c.getNombre() << endl;
}

Contacto ColaContactos::dequeue() {
    if (colaVacia()) {
        cout << "La cola esta vacia.\n";
        return Contacto("", "", "");
    }

    Contacto temp = arreglo[frente];
    cout << "Desencolado: " << temp.getNombre() << endl;

    frente++;
    return temp;
}

void ColaContactos::mostrar() {
    if (colaVacia()) {
        cout << "La cola esta vacia.\n";
        return;
    }

    cout << "\n--- Contactos pendientes en cola ---\n";

    for (int i = frente; i <= final; i++) {
        cout << arreglo[i].getNombre() << " | "
            << arreglo[i].getTelefono() << " | "
            << arreglo[i].getCorreo() << endl;
    }
}

int ColaContactos::size() {
    if (colaVacia()) return 0;
    return final - frente + 1;
}