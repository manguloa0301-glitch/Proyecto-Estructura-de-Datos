#include "Contacto.h"
#include <iostream>
using namespace std;

Contacto::Contacto(string n, string t, string c) {
	nombre = n;
	telefono = t;
	correo = c;
}

string Contacto::getNombre() const { return nombre; }
string Contacto::getTelefono() const { return telefono; }
string Contacto::getCorreo() const { return correo; }

void Contacto::setNombre(string n) { nombre = n; }
void Contacto::setTelefono(string t) { nombre = t; }
void Contacto::setCorreo(string c) { nombre = c; }

void Contacto::mostrar() const {
	cout << "Nombre: " << nombre << "\n";
	cout << "Telefono: " << telefono << "\n";
	cout << "Correo: " << correo << "\n";
}
