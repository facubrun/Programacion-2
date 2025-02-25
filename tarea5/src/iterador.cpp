/* 5265175 */ // sustituiir con los 7 dígitos de la cédula

#include "../include/iterador.h"

typedef struct st_iter * TIter;
struct st_iter {
	nat elemento;
	TIter sig;
	};

struct _rep_iterador {
	TIter primero;
	TIter ultimo;
	TIter actual;
	};

TIterador crearIterador() {
	TIterador iter = new _rep_iterador;
	iter->primero  = NULL;
	iter->actual   = NULL;
	iter->ultimo   = NULL;
  return iter;
}

void liberarIterador(TIterador iter) {
	if (iter->primero == NULL){//no tiene elementos
		delete iter;
		iter = NULL;
		}
	else if (iter->primero->sig == NULL){//tiene un solo elemento
		delete iter->primero;
		delete iter;
		iter = NULL;
	}
	else {
		TIter aux = iter->primero;
		while(iter->primero->sig != NULL){//tiene mas de un elemento
			iter->primero = iter->primero->sig;
			delete aux;
			aux = iter->primero;
		}
		delete aux;
		aux = NULL;
		delete iter;
		iter = NULL;
	}	
}

bool estaDefinidaActual(TIterador iter) {
	return (iter->actual != NULL);
}

void agregarAIterador(nat elem, TIterador const iter) {
	TIter insfin = new st_iter;
	if (iter->primero==NULL){
		insfin->elemento = elem;
		insfin->sig = NULL;
		iter->primero = insfin;
		iter->ultimo = insfin;
	}
	else {
    insfin->elemento = elem;
	insfin->sig = NULL;
	iter->ultimo->sig = insfin;
	iter->ultimo = insfin;
     }
}

void reiniciarIterador(TIterador const iter) {
	iter->actual = iter->primero;		
}

void avanzarIterador(TIterador const iter) {
	if (estaDefinidaActual(iter) && iter->actual->sig !=NULL)
	iter->actual = iter->actual->sig;
	else iter->actual = NULL;
}

nat actualEnIterador(TIterador iter) {
  return iter->actual->elemento;
}
