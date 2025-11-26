#include <iostream>
#include "Agenda.h"
#include "ListaEnlazada.h"
#include "PilaHistorial.h"
#include "ColaContactos.h"

int main()
{
    Agenda agenda;
    ListaEnlazada lista;
    PilaHistorial historial;
    ColaContactos colaPendientes;

    int opcion;

    do {
        cout << "---Gestor de agenda de contactos---\n";
        cout << "1. Agregar Contacto\n";
        cout << "2. Listar Contactos\n";
        cout << "3. Ordenar por nombre\n";
        cout << "4. Ordenar por telefono\n";
        cout << "5. Buscar contacto (secuencial)\n";
        cout << "6. Buscar contacto (binaria)\n";
        cout << "7. Eliminar Contacto\n";
        cout << "8. Historial\n";
        cout << "9. Agregar Contactos pendientes\n";
        cout << "10. Lista de contactos pendientes\n";
        cout << "11. Transferir contactos pendientes\n";
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

            agenda.agregarContacto(Contacto(nombre, telefono, correo));

            historial.push("Se agrego el contacto: " + nombre);

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
        else if (opcion == 5) {
            string nombre;
            cout << "Ingrese el nombre a buscar: ";
            getline(cin, nombre);
            int pos = agenda.buscarSecuencial(nombre);
            agenda.mostrarContactoEncontrado(pos);
        }
        else if (opcion == 6) {
            agenda.ordenarPorNombre();
            string nombre;
            cout << "Ingrese el nombre a buscar: ";
            getline(cin, nombre);
            int pos = agenda.buscarBinaria(nombre);
            agenda.mostrarContactoEncontrado(pos);
        }
        else if (opcion == 7) {
            cout << "Copiando contactos de la agenda a la lista...\n";
            lista = ListaEnlazada(); 
            vector<Contacto> copia = agenda.obtenerContactos();
            for (auto& c : copia) {
                lista.insertar(c);
            }

            cout << "\nContactos actuales:\n";
            lista.mostrar();

            string nombreEliminar;
            cout << "\nIngrese el nombre del contacto a eliminar: ";
            getline(cin, nombreEliminar);

            lista.eliminar(nombreEliminar);

            historial.push("Se elimino el contacto: " + nombreEliminar);

            cout << "\nLista actualizada:\n";
            lista.mostrar();
        }
        else if (opcion == 8) {
            historial.mostrar();
        }
        else if (opcion == 9) {
            string nombre, telefono, correo;

            cout << "Ingrese el Nombre: ";
            getline(cin, nombre);
            cout << "Ingrese el Telefono: ";
            getline(cin, telefono);
            cout << "Ingrese el Correo: ";
            getline(cin, correo);

            colaPendientes.enqueue(Contacto(nombre, telefono, correo));
            historial.push("Se encolo contacto pendiente: " + nombre);
        }
        else if (opcion == 10) {
            colaPendientes.mostrar();
        }
        else if (opcion == 11) {
            cout << "\nTransfiriendo contactos desde la cola...\n";

            while (!colaPendientes.colaVacia()) {
                Contacto c = colaPendientes.dequeue();
                agenda.agregarContacto(c);
                historial.push("Se agrego desde la cola: " + c.getNombre());
            }
            cout << "Transferencia completa.\n";
        }

    } while (opcion != 0);
    
    return 0;
}
