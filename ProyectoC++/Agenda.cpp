#include "Agenda.h"
#include <iostream>
using namespace std;

// Agrega un nuevo contacto al vector de contactos
void Agenda::agregarContacto(const Contacto& c) {
	// Inserta el contacto al final del vector
	contactos.push_back(c);
}

//metodo burbuja
void Agenda::ordenarPorNombre() {
	// Obtiene la cantidad de contactos
	int n = contactos.size();
	// No se necesita ordenar si hay 0 o 1 elementos
	if (n <= 1) return;

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {

			// Compara nombres alfabeticamente
			if (contactos[j].getNombre() > contactos[j + 1].getNombre()) {
				// Intercambia contactos si estan en el orden incorrecto
				Contacto temp = contactos[j];
				contactos[j] = contactos[j + 1];
				contactos[j + 1] = temp;
			}
		}
	}
	cout << "Contactos ordenados por nombre correctamente.\n";
}

//Tambien burbuja
void Agenda::ordenarPorTelefono() {
	int n = contactos.size();
	if (n <= 1) return;

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {

			// Compara numeros telefonicos de manera lexicografica
			if (contactos[j].getTelefono() > contactos[j + 1].getTelefono()) {
				// Intercambia posiciones
				Contacto temp = contactos[j];
				contactos[j] = contactos[j + 1];
				contactos[j + 1] = temp;
			}
		}
	}
	cout << "Contactos ordenados por telefono correctamente.\n";
}

void Agenda::listarContactos() const {
	// Si no hay contactos, muestra mensaje y termina
	if (contactos.empty()) {
		cout << "No hay contactos registrados.\n";
		return;
	}
	// Recorre todos los contactos
	cout << "Lista de Contactos:\n";
	for (const auto& c : contactos) {
		// Llama al metodo mostrar() de cada contacto
		c.mostrar();
	}
}

int Agenda::buscarSecuencial(string nombre) const {
	// Recorre el vector desde el inicio
	for (size_t i = 0; i < contactos.size(); i++) {
		// Compara el nombre contacto por contacto
		if (contactos[i].getNombre() == nombre) {
			// Retorna el indice donde se encontro
			return i;
		}
	}
	// Si no lo encuentra
	return -1;
}

int Agenda::buscarBinaria(string nombre)const {
	// Límite inferior
	int inicio = 0;
	// Límite superior
	int fin = contactos.size() - 1;

	// Mientras el rango siga valido
	while (inicio<=fin){
		// Calcula la posicion del medio
		int medio = (inicio + fin) / 2;
		// Si el elemento del medio es el buscado
		if (contactos[medio].getNombre() == nombre) {
			return medio;
		}
		// Si el nombre buscado es mayor, buscar a la derecha
		else if (contactos[medio].getNombre() < nombre) {
			inicio = medio + 1;
		}
		// Si es menor, buscar a la izquierda
		else {
			fin = medio - 1;
		}
	}
	// No encontrado
	return -1;
}

void Agenda::mostrarContactoEncontrado(int indice)const {
	// Verifica si el indice es valido
	if (indice >= 0 && indice < contactos.size()) {
		cout << "\nContacto encontrado:\n";
		// Muestra el contacto localizado
		contactos[indice].mostrar();
	}
	else {
		cout << "Contacto no encontrado.\n";
	}
}
#include <vector> 
// Devuelve una copia del vector completo de contactos
vector<Contacto> Agenda::obtenerContactos() const {
	return contactos;
}