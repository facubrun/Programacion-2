/* 5265175 */ // sustituiir con los 7 dígitos de la cédula

#include "../include/abb.h"

struct _rep_abb {
	TInfo info;
	TAbb izq;
	TAbb der;
};

void rotarDerecha(TAbb &a){
	if(a->izq !=NULL){
	TAbb l = a->izq;
	TAbb x = l->der;
	l->der = a;
	a->izq = x;
	a = l;
}
}
void rotarIzquierda(TAbb &a){
	if(a->der !=NULL){
	TAbb l = a->der;
	TAbb x = l->izq;
	l->izq = a;
	a->der = x;
	a = l;	
}	
}

TAbb rotar(nat clave, char tipo[2], TAbb abb) {
   if(abb!=NULL){
	if(clave == natInfo(abb->info)){
		if(tipo[0]=='L' && tipo[1]=='L'){
		    rotarDerecha(abb);
		}    
		else if(tipo[0]=='L' && tipo[1]=='R'){
			if(abb->izq != NULL && abb->izq->der != NULL){
			rotarIzquierda(abb->izq);
			rotarDerecha(abb);
		    }
		  } 
		else if(tipo[0]=='R' && tipo[1]== 'R'){
		   rotarIzquierda(abb);
		  } 
		else if(tipo[0]=='R' && tipo[1]=='L'){
			if(abb->der !=NULL && abb->der->izq != NULL){
			rotarDerecha(abb->der);
			rotarIzquierda(abb);
		    } 
	    }
	}	
	else if(clave < natInfo(abb->info)){
		if(abb->izq !=NULL)
		abb->izq = rotar(clave,tipo,abb->izq);
	}
	else if(clave > natInfo(abb->info)){
		if(abb->der !=NULL)
		abb->der = rotar(clave,tipo,abb->der);
	}
}
	return abb;
}

TAbb crearAbb() { 
	return NULL;
}	

void liberarAbb(TAbb abb) {
	if(abb != NULL ){
		liberarAbb(abb->izq);
		liberarAbb(abb->der);
		liberarInfo(abb->info);
		delete abb;
		abb=NULL;
	}
}

bool esVacioAbb(TAbb abb) {
	if(abb == NULL) return true;
	else return false;
}  

TAbb buscarSubarbol(nat elem, TAbb abb) {	 
	 if (abb == NULL)
		 return NULL;
	 
	 else if(natInfo(abb->info) == elem)
		 return abb;
	 
     else {
		if(elem < natInfo(abb->info))
		  return buscarSubarbol(elem,abb->izq);
	     
		else//(elem > natInfo(abb->info))
		  return buscarSubarbol(elem,abb->der);	
     }
}
      
TInfo raiz(TAbb abb) { 
	return abb->info;
}

TAbb izquierdo(TAbb abb) { 
	return abb->izq; 
}

TAbb derecho(TAbb abb) {
	 return abb->der; 
}

TInfo menorEnAbb(TAbb abb) {
	if(abb->izq == NULL)
	   return abb->info;
	else
	   return menorEnAbb(abb->izq);   
}

TInfo mayorEnAbb(TAbb abb) {
	if(abb->der == NULL)
	   return abb->info;
	else
	   return mayorEnAbb(abb->der);   
}

TAbb consAbb(TInfo dato, TAbb izq, TAbb der) {
	TAbb arb = new _rep_abb;
	arb->info = dato;
	arb->izq = izq;
	arb->der = der;
	return arb;
}
   
TAbb insertarEnAbb(TInfo dato, TAbb abb) {
    if(abb == NULL){
        TAbb nuevo = new _rep_abb;
	    nuevo->info = dato;
	    nuevo->izq = NULL;
	    nuevo->der = NULL;
	    abb = nuevo;
	  }
	   else if(natInfo(dato) < natInfo(abb->info))
	        abb->izq = insertarEnAbb(dato,abb->izq);
	   else if(natInfo(dato) > natInfo(abb->info))
	        abb->der = insertarEnAbb(dato,abb->der);
	        
    return abb;
} 
		
TAbb removerDeAbb(nat clave, TAbb abb) { 
	TAbb aux;
    if (abb != NULL){
	  if(natInfo(abb->info) == clave){
		  if(abb->izq == NULL){
			  aux = abb;
			  abb = abb->der;
			  liberarInfo(aux->info);
			  delete aux;		  
		 }else if (abb->der == NULL){
				aux = abb;
				abb = abb->izq;
				liberarInfo(aux->info);
				delete aux;
		  }else{
				 TInfo copia = mayorEnAbb(abb->izq);
				 liberarInfo(abb->info);
				 abb->info = copiaInfo(copia);
			     abb->izq = removerDeAbb(natInfo(copia),abb->izq);
			}
	  }else if(clave < natInfo(abb->info))   //si clave es menor a la raiz
		       abb->izq = removerDeAbb(clave,abb->izq);
		         
		  else                               //si clave es mayor a la raiz
		      abb->der = removerDeAbb(clave,abb->der);
   }
    return abb;
}

TAbb copiaAbb(TAbb abb) {	
	if(abb == NULL) return NULL;
	else{
	  TAbb copia = new _rep_abb;
	  copia->info = copiaInfo(abb->info);
	  copia->izq = copiaAbb(abb->izq);
	  copia->der = copiaAbb(abb->der);
	  return copia;
}
}
