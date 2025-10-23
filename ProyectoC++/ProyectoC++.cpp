#include <iostream>
#include "Agenda.h"
using namespace std;

int main()
{
    Agenda agenda;
    int opcion;

    do {
        cout << "---Gestor de agenda de contactos---\n";
        cout << "1. Agregar Contacto\n";
        cout << "2. Listar Contactos\n";
        cout << "3. Ordenar por nombre\n";
        cout << "4. Ordenar por telefono\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        if (opcion == 1) {
            string nombre, telefono, correo;
            cout << "Ingrese el Nombre: ";
            getline(cin, nombre);
            cout << "Ingrese el Telefono: ";
            getline(cin, telefono);
            cout << "Ingrese el Correo: ";
            getline(cin, correo);

            Contacto nuevo(nombre, telefono, correo);
            agenda.agregarContacto(nuevo);
            cout << "Contacto agregado exitosamente.\n";

        }
        else if (opcion == 2) {
            agenda.listarContactos();
        }
        else if (opcion == 3) {
            agenda.ordenarPorNombre();
        }
        else if (opcion == 4) {
            agenda.ordenarPorTelefono();
        }
    } while (opcion != 0);
    cout << "Saliendo del programa...\n";
    return 0;
}
