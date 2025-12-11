#include "Contacto.h"
#include <iostream>
using namespace std;

//constructor de la clase Contacto
Contacto::Contacto(string n, string t, string c) {
	// Recibe nombre, teléfono y correo y los asigna a sus atributos internos
	nombre = n;
	telefono = t;
	correo = c;
}

// Metodos GET: devuelven los valores de los atributos
// 'const' indica que estos metodos NO modifican el objeto
string Contacto::getNombre() const { return nombre; }
string Contacto::getTelefono() const { return telefono; }
string Contacto::getCorreo() const { return correo; }

// Metodos SET: permiten modificar los atributos del contacto
void Contacto::setNombre(string n) { nombre = n; }
void Contacto::setTelefono(string t) { telefono = t; }
void Contacto::setCorreo(string c) { correo = c; }

// Metodo para mostrar los datos del contacto en pantalla
void Contacto::mostrar() const {
	// Imprime el nombre, teléfono y correo
	cout << "Nombre: " << nombre << "\n";
	cout << "Telefono: " << telefono << "\n";
	cout << "Correo: " << correo << "\n";
}
