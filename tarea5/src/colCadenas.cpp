/* 5265175 */ // sustituiir con los 7 dígitos de la cédula

#include "../include/colCadenas.h"

struct _rep_colCadenas {
	TCadena *arrcads;
	nat tam;
	};

TColCadenas crearColCadenas(nat tamanio) {
	TColCadenas col = new _rep_colCadenas;
	col->tam=tamanio;
	col->arrcads = new TCadena[tamanio];
	for(nat i=0 ; i<tamanio ; i++) {
		col->arrcads[i]=crearCadena();
	}	
  return col;
}

void liberarColCadenas(TColCadenas col) {
	TColCadenas aux = col;
	for(nat i=0 ; i<tamanioColCadenas(col) ; i++) {
	liberarCadena(aux->arrcads[i]);
     }
     delete []col->arrcads;
     delete col;
     col = NULL;

}

nat tamanioColCadenas(TColCadenas col){
	return col->tam;		 
}

TCadena cadenaDeColCadenas(nat pos, TColCadenas col) {
  return col->arrcads[pos];
}

nat cantidadColCadenas(nat pos, TColCadenas col) {
	return cantidadEnCadena(col->arrcads[pos]);
}

bool estaEnColCadenas(nat natural, nat pos, TColCadenas col) {
	return estaEnCadena(natural,(col->arrcads[pos]));
}

TColCadenas insertarEnColCadenas(nat natural, double real, nat pos,
                                 TColCadenas col) {
          col->arrcads[pos] = insertarAlInicio(natural,real,col->arrcads[pos]);
          return col;
}

TInfo infoEnColCadenas(nat natural, nat pos, TColCadenas col) {
  return infoCadena(natural,(col->arrcads[pos]));
}

TColCadenas removerDeColCadenas(nat natural, nat pos, TColCadenas col) {
  col->arrcads[pos]= removerDeCadena(natural,col->arrcads[pos]);
  return col;
}
