#include <iostream>
#include "pila.h"

using namespace std;

int main() {
	// ----- Creazione oggetto Pila ----- //
  Pila pila1;

	// ----- Test pilaVuota ----- //
	cout << "Controllo elementi pila..." << endl;
  if ( pila1.pilaVuota() ) {
		cout << "> La pila è vuota" << endl;
	}
	
	// ----- Test inPila ----- //
  pila1.inPila(5);
  pila1.inPila(6);

	// ----- Test pilaVuota ----- //
	cout << "Controllo elementi pila..." << endl;
	if ( !pila1.pilaVuota() ) {
		cout << "> La pila è piena" << endl;
	}
	
	// ----- Test fuoriPila (pop) ----- //
  pila1.fuoriPila();
  cout << "Valore elemento in testa: " << pila1.leggiPila() << endl;
  
	// ----- Test inPila ----- //
  pila1.inPila(4);
  pila1.inPila(7);

	// ----- Test stampPila ----- //
  stampPila(pila1);


}