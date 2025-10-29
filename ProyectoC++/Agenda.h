#ifndef AGENDA_H
#define AGENDA_H

#include <vector>
#include "Contacto.h"
using namespace std;

class Agenda {
private:
	vector<Contacto> contactos;

public:
	void agregarContacto(const Contacto& c);
	void listarContactos() const;
	void ordenarPorNombre();
	void ordenarPorTelefono();
	int buscarSecuencial(string nombre) const;
	int buscarBinaria(string nombre)const;
	void mostrarContactoEncontrado(int indice) const;
};
#endif

