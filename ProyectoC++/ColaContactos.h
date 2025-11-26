#define COLA_CONTACTOS_H

#include <iostream>
#include "Contacto.h"

#define MAX_COLA 50
using namespace std;

class ColaContactos {
private:
    Contacto arreglo[MAX_COLA];
    int frente;
    int final;

public:
    ColaContactos();

    bool colaVacia();
    bool colaLlena();

    void enqueue(const Contacto& c);
    Contacto dequeue();
    void mostrar();
    int size();
};