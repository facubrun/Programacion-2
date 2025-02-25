/* 5265175 */ // sustituiir con los 7 dígitos de la cédula

#include "../include/cadena.h"
#include "../include/info.h"

struct _rep_cadena {
	TInfo dato;
	TCadena sig;
	TCadena ant;
	
};

TCadena crearCadena() {
	TCadena cad= NULL;
  return cad;
}

void liberarCadena(TCadena cad) {
	if (cantidadEnCadena(cad)==0) {
		cad = NULL;
    }
    else if (cantidadEnCadena(cad)==1){
		liberarInfo(cad->dato);
        delete cad;
        cad = NULL;
     }
    else {
		nat cant = cantidadEnCadena(cad);
		TCadena aux = cad;
	    for(nat i=1;i <= cant; i++){
		   cad= cad->sig;
	       liberarInfo(aux->dato);
           delete aux;
           aux=cad;
     }
       cad = NULL;
     }
}
nat cantidadEnCadena(TCadena cad) {
	nat cont=0;
	if (cad == NULL)
		return cont;
	else if (cad->sig == cad)
		return cont+1;
	
	else{
	  TCadena p = cad;
	  cont=0;
	  while(p->sig != cad){
		cont++;
		p = p->sig;
	   }
	   return cont+1;
     }
}

bool estaEnCadena(nat natural, TCadena cad) {
	TCadena p=cad;
	if (cad == NULL)
	   return false;
	
	else if (cad->sig == cad && natInfo(cad->dato) == natural)
	    return true;    
    
    else {  
	  while(p->sig != cad && natInfo(p->dato) != natural)
	  p = p->sig;

  return (natInfo(p->dato) == natural);
     }
}

TCadena insertarAlInicio(nat natural, double real, TCadena cad) {
	TCadena p = new _rep_cadena;
	p->dato = crearInfo(natural,real);
	if (cantidadEnCadena(cad)==0){
	p->sig= p;
	p->ant=p;
	cad = p;
	return cad;
    }
    else if(cantidadEnCadena(cad)==1){
	    p->ant =cad;
	    p->sig = cad;
	    cad->ant = p;
	    cad->sig = p;
	    cad = p;
	    return cad;
	   } 
    else {
	p->sig = cad;
	p->ant = cad->ant;
	cad->ant->sig = p;
	cad->ant = p;
	cad= p;
  return cad;
     }
}

TInfo infoCadena(nat natural, TCadena cad) {
	TCadena p = cad;
	if (cantidadEnCadena(cad)==1 && natInfo(cad->dato) == natural){
	    return cad->dato;
	 } 
	else {
		p=cad;
	  while(p->sig != cad && natInfo(p->dato) != natural){
	       p = p->sig;
	    }       
      return p->dato;
     }
}

TInfo primeroEnCadena(TCadena cad) {
  return cad->dato;
}

TCadena cadenaSiguiente(TCadena cad) {
	TCadena p=cad;
	if (cantidadEnCadena(cad)==0 || cantidadEnCadena(cad)==1)
		p=cad;
		
	else {
	 p = cad->sig;
     }
  return p;
}     

TCadena removerDeCadena(nat natural, TCadena cad) {
	    if(cantidadEnCadena(cad)==0){}
	    
	    else if(cantidadEnCadena(cad)==1 && natInfo(cad->dato)==natural){ //un solo elemento y contiene natural
			liberarInfo(cad->dato);
			delete cad;
			cad=NULL;
		}
		else {	
		    TCadena p = cad;
	        while(p->sig != cad && natInfo(p->dato)!=natural) {
			  p = p->sig;
	        }
	          if(p==cad){// natural esta en el primer nodo de la cadena
				  p->sig->ant = p->ant;
				  p->ant->sig = p->sig;
				  cad = cad->sig;
			      liberarInfo(p->dato);
			      delete p;
			      p = NULL;
			  }    
              else if(p != cad){//natural esta en nodo intermedio o ultimo
				p->ant->sig = p->sig;
				p->sig->ant = p->ant;
				liberarInfo(p->dato);
				delete p;
				p = NULL;
	         }
	    }
	    return cad;           				
} 			


void imprimirCadena(TCadena cad) {
	TCadena p=cad;
	if (cantidadEnCadena(cad)==0){printf("\n");}
	
	else if (cantidadEnCadena(cad)==1){
	imprimirInfo(cad->dato);
	printf("\n");
     }
     
	else {
		nat cant=cantidadEnCadena(cad);
	 for(nat i=1; i <= cant; i++) {
		imprimirInfo(p->dato);
		p = p->sig;
      }
      printf("\n");
     }
}
