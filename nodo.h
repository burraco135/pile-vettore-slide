#ifndef _NODO_H
#define _NODO_H
#include <iostream>

using namespace std;

typedef int tipoelem;

class Nodo {
  public:
    // ----- Implementazione costruttore ----- //
    Nodo() { }

		// ----- Implementazione costruttore default ----- //
    Nodo(tipoelem a) { elemento = a; }
		
		// ----- Implementazione distruttore ----- //
    ~Nodo() { }
    
		// ----- Implementazione operatori ----- //
    void setElemento(tipoelem a) {
			elemento = a;
		}

    tipoelem getElemento() const {
			return elemento;
		}

    bool operator ==(Nodo &n) {
			return ( getElemento() == n.getElemento() );
		} //sovraccarico operatore = 		

  private:
		// il nodo ha elementi di tipo tipoelem
    tipoelem elemento;
};

std::ostream& operator<<(std::ostream&, const Nodo &n) {
	return cout << n.getElemento();
} //sovraccarico per stampa


# endif // _NODO_H