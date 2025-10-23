#include "Agenda.h"
#include <iostream>
using namespace std;

void Agenda::agregarContacto(const Contacto& c) {
	contactos.push_back(c);
}

void Agenda::ordenarPorNombre() {
	int n = contactos.size();
	if (n <= 1) return;

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (contactos[j].getNombre() > contactos[j + 1].getNombre()) {
				Contacto temp = contactos[j];
				contactos[j] = contactos[j + 1];
				contactos[j + 1] = temp;
			}
		}
	}
	cout << "Contactos ordenados por nombre correctamente.\n";
}

void Agenda::ordenarPorTelefono() {
	int n = contactos.size();
	if (n <= 1) return;

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (contactos[j].getTelefono() > contactos[j + 1].getTelefono()) {
				Contacto temp = contactos[j];
				contactos[j] = contactos[j + 1];
				contactos[j + 1] = temp;
			}
		}
	}
	cout << "Contactos ordenados por telefono correctamente.\n";
}

void Agenda::listarContactos() const {
	if (contactos.empty()) {
		cout << "No hay contactos registrados.\n";
		return;
	}
	cout << "Lista de Contactos:\n";
	for (const auto& c : contactos) {
		c.mostrar();
	}
}
