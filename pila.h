#ifndef _PILA_H
#define _PILA_H
#include "nodo.h"

using namespace std;

const int MAXLUNGH = 100;

class Pila {
	friend void stampPila(Pila &p); //ha il privilegio di accedere a tutti i membri di classe (privati, protetti e pubblici) come se lo fosse

	public:
		// ----- Implementazione costruttore ----- //
		Pila() { creaPila(); }

		// ----- Implementazione distruttore ----- //
		~Pila() {}

		// ----- Implementazione operatori ----- //
		void creaPila() {
			testa = 0;
		}

		bool pilaVuota() const {
			return ( testa == 0 );
		} // 1 se la pila è vuota, 0 altrimenti

		tipoelem leggiPila() const {
			return elementi[testa];
		}

		void fuoriPila() {
			if (!pilaVuota()) {
        elementi[testa] = 0; // "cancella" l'elemento in testa
				testa--; // vado all'elemento precedente
			} else {
				cout << "La pila è vuota" << endl;
			}
		} //POP

		void inPila(tipoelem a) {
			if (testa == MAXLUNGH) {
				cout << "Capacità massima raggiunta" << endl;
			} else {
				elementi[testa] = a;
        testa++;		
			}
		} //PUSH

	private:
		// vettore di elementi di tipo tipoelem
		tipoelem elementi[MAXLUNGH];
		//indice del primo elemento della pila
		int testa;
};

void stampPila(Pila &p) {
	for (int i = 0; i < p.testa; i++) {
		cout << "|" << p.elementi[i] << "|" << endl ;
	}
	
	cout << endl;
}

#endif //_PILA_H