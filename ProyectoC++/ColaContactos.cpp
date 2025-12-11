#include "ColaContactos.h"
#include <iostream>

using namespace std;

//constructor de la cola
ColaContactos::ColaContactos() {
    // Indica que la cola esta vacia
    frente = -1;
    // No hay elementos
    final = -1;
}
//verificar si la cola esta vacia
bool ColaContactos::colaVacia() {
    return (frente == -1 || frente > final);
}
//varificar si la cola esta llena
bool ColaContactos::colaLlena() {
    return (final == MAX_COLA - 1);
}
//Insertar un nuevo contacto (al final)
void ColaContactos::enqueue(const Contacto& c) {
    // Verifica que aún haya espacio en el arreglo
    if (colaLlena()) {
        cout << "La cola esta llena, no se puede insertar el contacto: "
            << c.getNombre() << endl;
        return;
    }
    // Si la cola estaba vacia, inicializa el frente
    if (frente == -1)
        frente = 0;
    // Avanza el final de la cola
    final++;
    // Inserta el nuevo contacto
    arreglo[final] = c;

    cout << "Contacto encolado: " << c.getNombre() << endl;
}
//Remover el primer contacto(al frente)
Contacto ColaContactos::dequeue() {
    if (colaVacia()) {
        cout << "La cola esta vacia.\n";
        // Devuelve contacto vacio
        return Contacto("", "", "");
    }
    // Guarda el contacto que se va a extraer
    Contacto temp = arreglo[frente];
    cout << "Desencolado: " << temp.getNombre() << endl;
    // Avanza el frente hacia el siguiente contacto
    frente++;
    //// Retorna el contacto removido
    return temp;
}
//Mouestra todos los contactos de la cola
void ColaContactos::mostrar() {
    if (colaVacia()) {
        cout << "La cola esta vacia.\n";
        return;
    }

    cout << "\n--- Contactos pendientes en cola ---\n";
    // Recorre desde el frente hasta el final
    for (int i = frente; i <= final; i++) {
        cout << arreglo[i].getNombre() << " | "
            << arreglo[i].getTelefono() << " | "
            << arreglo[i].getCorreo() << endl;
    }
}
//obtener el tamano de la cola
int ColaContactos::size() {
    if (colaVacia()) return 0;
    return final - frente + 1;
}