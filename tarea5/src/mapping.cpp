/* 5265175 */ // sustituiir con los 7 dígitos de la cédula

#include "../include/mapping.h"
#include "../include/cadena.h"
#include "../include/colCadenas.h"

nat hash(nat n,nat M){ return n%M;}

struct _rep_mapping { 
	TColCadenas tabla;
	nat cant;
};

TMapping crearMap(nat M) { 
	TMapping map = new _rep_mapping;
	map->tabla = crearColCadenas(M);
	map->cant = 0;
	return map;
}

void liberarMap(TMapping map) {
   liberarColCadenas(map->tabla);
   map->cant = 0;
   delete map;
   map = NULL;
}

TMapping asociarEnMap(nat clave, double valor, TMapping map) {
	  nat M = tamanioColCadenas(map->tabla);
	  nat pos = hash(clave,M);
	  map->tabla=insertarEnColCadenas(clave,valor,pos,map->tabla);
	  map->cant++;
	 return map; 
}

TMapping desasociarEnMap(nat clave, TMapping map) {
	nat M = tamanioColCadenas(map->tabla);
	nat pos = hash(clave,M);
	map->tabla = removerDeColCadenas(clave,pos,map->tabla);
	map->cant--;
	 return map; 
}

bool esClaveEnMap(nat clave, TMapping map) {
	nat M = tamanioColCadenas(map->tabla);
	nat pos = hash(clave,M);
	return estaEnColCadenas(clave,pos,map->tabla);
}

double valorEnMap(nat clave, TMapping map) {
	nat M = tamanioColCadenas(map->tabla);
	nat pos = hash(clave,M); 
	return realInfo(infoEnColCadenas(clave,pos,map->tabla));
}

bool estaLlenoMap(TMapping map) { 
	return map->cant == tamanioColCadenas(map->tabla);
}


