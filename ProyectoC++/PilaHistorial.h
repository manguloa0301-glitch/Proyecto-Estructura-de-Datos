#include <iostream>
#include <string>

#define MAX 200


class PilaHistorial {
private:
    std::string elementos[MAX];
    int tope;

public:
    PilaHistorial();
    bool estaLlena() const;
    bool estaVacia() const;
    void push(const std::string& operacion);
    void pop();
    std::string top() const;
    int size() const;
    void mostrar() const;
};
