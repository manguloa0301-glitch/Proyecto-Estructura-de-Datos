#include <iostream>
#include "Agenda.h"
#include "ListaEnlazada.h"
#include "PilaHistorial.h"
#include "ColaContactos.h"
#include "ArbolContactos.h"

void menuContactos(Agenda& agenda, PilaHistorial& historial) {
    int op;
    do {
        cout << "\n--- MENU DE CONTACTOS ---\n";
        cout << "1. Agregar Contacto\n";
        cout << "2. Listar Contactos\n";
        cout << "3. Ordenar por Nombre\n";
        cout << "4. Ordenar por Telefono\n";
        cout << "5. Buscar Secuencial\n";
        cout << "6. Buscar Binaria\n";
        cout << "0. Volver\n";
        cout << "Opcion: ";
        cin >> op;
        cin.ignore();

        if (op == 1) {
            string nombre, telefono, correo;
            cout << "Nombre: ";
            getline(cin, nombre);
            cout << "Telefono: ";
            getline(cin, telefono);
            cout << "Correo: ";
            getline(cin, correo);

            agenda.agregarContacto(Contacto(nombre, telefono, correo));
            historial.push("Se agrego contacto: " + nombre);

        }
        else if (op == 2) {
            agenda.listarContactos();

        }
        else if (op == 3) {
            agenda.ordenarPorNombre();

        }
        else if (op == 4) {
            agenda.ordenarPorTelefono();

        }
        else if (op == 5) {
            string nombre;
            cout << "Nombre a buscar: ";
            getline(cin, nombre);
            int pos = agenda.buscarSecuencial(nombre);
            agenda.mostrarContactoEncontrado(pos);

        }
        else if (op == 6) {
            agenda.ordenarPorNombre();
            string nombre;
            cout << "Nombre a buscar (binaria): ";
            getline(cin, nombre);
            int pos = agenda.buscarBinaria(nombre);
            agenda.mostrarContactoEncontrado(pos);
        }

    } while (op != 0);
}

void menuEliminar(Agenda& agenda, ListaEnlazada& lista, PilaHistorial& historial) {
    cout << "\n--- ELIMINAR CONTACTO ---\n";

    lista = ListaEnlazada();
    auto copia = agenda.obtenerContactos();

    for (auto& c : copia)
        lista.insertar(c);

    lista.mostrar();

    cout << "\nNombre a eliminar: ";
    string nombre;
    cin.ignore();
    getline(cin, nombre);

    lista.eliminar(nombre);
    historial.push("Se elimino contacto: " + nombre);

    cout << "\nLista actualizada:\n";
    lista.mostrar();
}

void menuPendientes(ColaContactos& cola, Agenda& agenda, PilaHistorial& historial) {
    int op;
    do {
        cout << "\n--- CONTACTOS PENDIENTES ---\n";
        cout << "1. Encolar contacto\n";
        cout << "2. Mostrar cola\n";
        cout << "3. Transferir pendientes a agenda\n";
        cout << "0. Volver\n";
        cout << "Opcion: ";
        cin >> op;
        cin.ignore();

        if (op == 1) {
            string n, t, c;
            cout << "Nombre: "; getline(cin, n);
            cout << "Telefono: "; getline(cin, t);
            cout << "Correo: "; getline(cin, c);

            cola.enqueue(Contacto(n, t, c));
            historial.push("Se encolo pendiente: " + n);

        }
        else if (op == 2) {
            cola.mostrar();

        }
        else if (op == 3) {
            cout << "Transfiriendo...\n";
            while (!cola.colaVacia()) {
                Contacto x = cola.dequeue();
                agenda.agregarContacto(x);
                historial.push("Transferido desde cola: " + x.getNombre());
            }
            cout << "Listo.\n";
        }

    } while (op != 0);
}

void menuArbol(ArbolContactos& arbol, Agenda& agenda) {
    int op;

    do {
        cout << "\n--- ARBOL DE CONTACTOS ---\n";
        cout << "1. Construir arbol\n";
        cout << "2. Mostrar arbol\n";
        cout << "3. Recorrer inorden\n";
        cout << "4. Recorrer preorden\n";
        cout << "5. Buscar en arbol\n";
        cout << "0. Volver\n";
        cout << "Opcion: ";
        cin >> op;
        cin.ignore();

        if (op == 1) {
            arbol = ArbolContactos();
            auto v = agenda.obtenerContactos();
            for (auto& c : v)
                arbol.insertarContacto(c);
            cout << "Arbol construido.\n";

        }
        else if (op == 2) {
            arbol.mostrarArbol();

        }
        else if (op == 3) {
            arbol.recorrerInorden();

        }
        else if (op == 4) {
            arbol.recorrerPreorden();

        }
        else if (op == 5) {
            string nombre;
            cout << "Nombre a buscar: ";
            getline(cin, nombre);

            NodoArbol* res = arbol.buscarContacto(nombre);
            if (res) cout << "Encontrado: " << res->dato.getNombre() << endl;
            else cout << "No encontrado.\n";
        }

    } while (op != 0);
}

void menuHistorial(PilaHistorial& historial) {
    cout << "\n--- HISTORIAL DE OPERACIONES ---\n";
    historial.mostrar();
}

int main()
{
    Agenda agenda;
    ListaEnlazada lista;
    PilaHistorial historial;
    ColaContactos colaPendientes;
    ArbolContactos arbol;

    int opcion;

    do {
        cout << "\n===== GESTOR DE AGENDA =====\n";
        cout << "1. Contactos\n";
        cout << "2. Eliminar contacto\n";
        cout << "3. Contactos pendientes\n";
        cout << "4. Arbol\n";
        cout << "5. Historial\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: menuContactos(agenda, historial); break;
        case 2: menuEliminar(agenda, lista, historial); break;
        case 3: menuPendientes(colaPendientes, agenda, historial); break;
        case 4: menuArbol(arbol, agenda); break;
        case 5: menuHistorial(historial); break;
        }

    } while (opcion != 0);

    return 0;
}
