/* 5265175 */ // sustituiir con los 7 dígitos de la cédula

#include "../include/cola.h"
#include "../include/cadena.h"

struct _rep_cola {
	TCadena cad;
	nat cont;
};

TCola crearCola() {
	TCola c = new _rep_cola;
	c->cad = crearCadena();
	c->cont=0;
	return c;
}

void liberarCola(TCola c) {
	liberarCadena(c->cad);
	c->cont=0;
	delete c;
	c=NULL;
}

nat cantidadEnCola(TCola c) { 
	return c->cont;
}

TCola encolar(TInfo info, TCola c) { 
	c->cad = insertarAlFinal(natInfo(info),realInfo(info),c->cad);
	c->cont++;
	return c;
}

TInfo frente(TCola c) { 
	return primeroEnCadena(c->cad);
}

TCola desencolar(TCola c) { 
	c->cad = removerPrimero(c->cad);
	c->cont--;
	return c;
}
