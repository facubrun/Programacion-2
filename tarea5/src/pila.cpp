/* 5265175 */ // sustituiir con los 7 dígitos de la cédula

#include "../include/pila.h"
#include "../include/cadena.h"

struct _rep_pila {
	TCadena cadena;
	nat cont;
};

TPila crearPila() {
	TPila p = new _rep_pila;
	p->cadena = crearCadena();
	p->cont = 0;
  return p; 
}

void liberarPila(TPila p) {
	liberarCadena(p->cadena);
	p->cont = 0;
	delete p;
	p = NULL;
}

nat cantidadEnPila(TPila p) {
	 return p->cont; 
}

TPila apilar(TInfo info, TPila p) {
	p->cadena=insertarAlInicio(natInfo(info),realInfo(info),p->cadena);
	p->cont++;
	return p; 
}

TInfo cima(TPila p) {
	 return primeroEnCadena(p->cadena); 
}

TPila desapilar(TPila p) { 
	p->cadena=removerPrimero(p->cadena);
	p->cont--;
	return p;
}
