#ifndef CONTACTO_H
#define CONTACTO_H

#include <string>
using namespace std;

class Contacto {
private:
	string nombre;
	string telefono;
	string correo;

public:
	Contacto() = default;
	Contacto(string n, string t, string c);

	string getNombre() const;
	string getTelefono() const;
	string getCorreo() const;

	void setNombre(string n);
	void setTelefono(string t);
	void setCorreo(string c);

	void mostrar() const;
};
#endif

