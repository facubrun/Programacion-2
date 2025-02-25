/* 5265175 */ // sustituiir con los 7 dígitos de la cédula

#include "../include/aplicaciones.h"
#include <string.h>
#include <math.h>

bool estaOrdenada(TCadena cad) {
	if(cantidadEnCadena(cad)==0 || cantidadEnCadena(cad)==1) return true;
	else{
		int cant = cantidadEnCadena(cad);
		int *arr = new int[cant];
		for(int i=0;i<cant;i++){
			arr[i]=natInfo(primeroEnCadena(cad));
			cad=cadenaSiguiente(cad);
		}
		int k=0;
		int l=1;	
		while(l<cant && arr[k]<arr[l]){
			k++;
			l++;
		}
		delete []arr;
		return l == cant;
    }
    			
}

TCadena mezclaCadenas(TCadena cad1, TCadena cad2) {
	if(cad1 == NULL) return copiaCadena(cad2);
	  else if(cad2 == NULL) return copiaCadena(cad1);
	    else if(cad1==NULL && cad2==NULL) return NULL;
	      else{
             nat cant1 = cantidadEnCadena(cad1);
			 nat cant2 = cantidadEnCadena(cad2);
			 TCadena mezcla = crearCadena();

		      while(cant1>0 && cant2>0){
				  if(natInfo(primeroEnCadena(cad1))<natInfo(primeroEnCadena(cad2))){
				 mezcla = (insertarAlFinal(natInfo(primeroEnCadena(cad1)),realInfo(primeroEnCadena(cad1)),mezcla)); 
				 cad1 = cadenaSiguiente(cad1);
				 cant1 = cant1-1;
			       }
			       else if(natInfo(primeroEnCadena(cad1))==natInfo(primeroEnCadena(cad2))){
					   mezcla = (insertarAlFinal(natInfo(primeroEnCadena(cad1)),realInfo(primeroEnCadena(cad1)),mezcla)); 
				       cad1 = cadenaSiguiente(cad1);
				       cant1 = cant1-1;
				       cad2 = cadenaSiguiente(cad2);
		               cant2 = cant2-1;
		            }   
					   
				   else if(natInfo(primeroEnCadena(cad2))<natInfo(primeroEnCadena(cad1))){ 
				     mezcla = (insertarAlFinal(natInfo(primeroEnCadena(cad2)),realInfo(primeroEnCadena(cad2)),mezcla));
		             cad2 = cadenaSiguiente(cad2);
		             cant2 = cant2-1;
			       }
			   } 
					while(cant1>0){
					  mezcla = (insertarAlFinal(natInfo(primeroEnCadena(cad1)),realInfo(primeroEnCadena(cad1)),mezcla)); 
				      cad1 = cadenaSiguiente(cad1);
				      cant1 = cant1-1;
				    }
			      
				   while(cant2>0){
					  mezcla = (insertarAlFinal(natInfo(primeroEnCadena(cad2)),realInfo(primeroEnCadena(cad2)),mezcla)); 
				      cad2 = cadenaSiguiente(cad2);
				      cant2 = cant2-1;
				    }  
			  	      
		return mezcla;
		}			 		 	
}

TAbb balanceadoAux(TInfo *arr,int ini,int fin){
	if(ini>fin) return NULL;
	else{//recursion
		int medio = floor((fin+ini)/2);
		TAbb izq = balanceadoAux(arr,ini,medio-1);
	    TAbb der = balanceadoAux(arr,medio+1,fin);
	    return consAbb(copiaInfo(arr[medio]),izq,der);
	  }
}         
TAbb crearBalanceado(TInfo *arreglo, nat n) {
    int ini = 0;
	TAbb abb_bal = crearAbb();
    abb_bal = balanceadoAux(arreglo,ini,n-1);
	return abb_bal;
}

TAbb unionAbbs(TAbb abb1, TAbb abb2) { 
		    TCadena cad1 = linealizacion(abb1);
		    TCadena cad2 = linealizacion(abb2);
		    TCadena cadena = mezclaCadenas(cad1,cad2);
		    nat cant = cantidadEnCadena(cadena);
		    TInfo *arr = new TInfo[cant];
		    TCadena aux = cadena;
		    for(nat i=0;i<cant;i++){
				arr[i]=primeroEnCadena(aux);
				aux = cadenaSiguiente(aux);
             }
           TAbb unionabb = crearBalanceado(arr,cant);
           delete []arr;
           liberarCadena(cad1);
           liberarCadena(cad2);
           liberarCadena(cadena);
	       return unionabb;
       }

TCola ordenadaPorModulo(nat p, TCadena cad) {
	TCola cMod = crearCola();
	nat cant = cantidadEnCadena(cad);
	TCadena *arr = new TCadena[p];
	for(nat i=0;i<p;i++){
		arr[i] = crearCadena();
	}	
	for(nat k=0;k<cant;k++){
		nat pos = natInfo(primeroEnCadena(cad))%p;
		arr[pos] = insertarAlFinal(natInfo(primeroEnCadena(cad)),realInfo(primeroEnCadena(cad)),arr[pos]);
		cad = cadenaSiguiente(cad);
	 }
	for(nat l=0;l<p;l++){
		nat cant_l = cantidadEnCadena(arr[l]);
		for(nat j=0;j<cant_l;j++){
		cMod=encolar(primeroEnCadena(arr[l]),cMod);
		arr[l]=cadenaSiguiente(arr[l]);
	     }
	 }
	for(nat m=0;m<p;m++)
		liberarCadena(arr[m]);
	delete []arr;
    return cMod;
} 

TPila menoresQueElResto(TCadena cad, nat cantidad) { 
	TPila p = crearPila();
	while(cantidad>0){
		while(cantidadEnPila(p)>0 && natInfo(primeroEnCadena(cad))<=natInfo(cima(p))){
			   p = desapilar(p);
		}	   
			p=apilar(primeroEnCadena(cad),p);
			cad = cadenaSiguiente(cad);
	        cantidad--;
     } 		
	return p; 
}

static void insertarACadena(TCadena &cad,TAbb a){
     if(a != NULL){
	   insertarACadena(cad,derecho(a));
	   cad = insertarAlInicio(natInfo(raiz(a)),realInfo(raiz(a)),cad);
	   insertarACadena(cad,izquierdo(a));
      }
}
	
TCadena linealizacion(TAbb abb) {
	TCadena cadena = crearCadena();
	insertarACadena(cadena,abb);
  return cadena;
}

static void imprimir(int prof,TAbb a){
	if(a!=NULL){
	  imprimir(prof+1,derecho(a));	
	  for(int i=1;i<=prof;i++)
	     printf("-");
	  imprimirInfo(raiz(a));
	  printf("\n");
   	  imprimir(prof+1,izquierdo(a));
    }
}     

void imprimirAbb(TAbb abb) {
	 int prof = 0;
	 imprimir(prof,abb);
}        

bool esPerfAux(int alt,TAbb a){
	bool esPerf = true;
	if (a == NULL && alt == 0) 
	  esPerf = true;	  
	  else if(a!=NULL && alt!=0 && esPerfAux(alt-1,izquierdo(a)) && esPerfAux(alt-1,derecho(a))) 
	      esPerf = true;   
	        else esPerf = false;
	 
  return esPerf;
}	

int altura(TAbb a){
	if(a!=NULL){
	 int alt_izq = altura(izquierdo(a));
	 int alt_der = altura(derecho(a));
	 
	  if(alt_der < alt_izq) return alt_izq + 1;
	    else return alt_der + 1;
    }
    else return 0;
}    
		
bool esPerfecto(TAbb abb) {
  return esPerfAux(altura(abb),abb);
}

TAbb menores(double limite, TAbb abb) {
	TAbb mIzq,mDer,nuevo;
	TInfo MayorIzq,Raiz;
	if(abb == NULL)
	   nuevo = NULL;
	 else{
		mIzq = menores(limite,izquierdo(abb));
		mDer = menores(limite,derecho(abb));
		Raiz = raiz(abb);
		 if (limite > realInfo(Raiz)){
			 Raiz = copiaInfo(raiz(abb));
			 nuevo = consAbb(Raiz,mIzq,mDer);
		 }
		  else if(mIzq == NULL)
		       nuevo = mDer;
		    else if(mDer == NULL)
		         nuevo = mIzq;
		       else{
			       MayorIzq = copiaInfo(mayorEnAbb(mIzq));
			       mIzq = removerDeAbb(natInfo(MayorIzq),mIzq);
			       nuevo = consAbb(MayorIzq,mIzq,mDer);
		        }
	         }
   return nuevo;			
}

static void caminoAscAux(nat clave,nat &k, TAbb a,TIterador &iter){
	  if(a!=NULL){
	   if(clave > natInfo(raiz(a))){
	     caminoAscAux(clave,k,derecho(a),iter);
	    } 
	     else if(clave < natInfo(raiz(a))){
	        caminoAscAux(clave,k,izquierdo(a),iter); 
          }
      }  
    if(k>0){
	   agregarAIterador(natInfo(raiz(a)),iter);
	   k = k-1;
	}	 
}


TIterador caminoAscendente(nat clave, nat k, TAbb abb) {
	TIterador iter=crearIterador();
	caminoAscAux(clave,k,abb,iter);
  return iter;
}		 
		   
static void iPCortasAux(ArregloChars Arreglo,nat l,nat k, TPalabras palabras){
	if(l<=k){
	  if (letra(palabras) == '\0') {
	    Arreglo[l]=	'\0';
        printf("%s\n", Arreglo);
      }else {
         Arreglo[l] = letra(palabras);
         iPCortasAux(Arreglo, l+1,k, subarboles(palabras));
	   }
          if (siguientes(palabras) != NULL)
            iPCortasAux(Arreglo,l,k, siguientes(palabras));
    }
}
        
void imprimirPalabrasCortas(nat k, TPalabras palabras) {
	nat largo = 0;
	ArregloChars Arreglo = new char[k+1];
	iPCortasAux(Arreglo,largo,k,subarboles(palabras));
	delete [] Arreglo;
}

TPalabras FinPrefijoAux(ArregloChars pref,nat l,TPalabras pal,TPalabras resul){	
  if(pal!=NULL && l+1<=strlen(pref)){
	  		
	    if(pref[l]==letra(pal)){
		  resul = FinPrefijoAux(pref,l+1,subarboles(pal),resul);
		  if(pref[l+1]=='\0'){
 	      resul = pal;
          }
        } 
	     else if(siguientes(pal)!=NULL){
	          resul = FinPrefijoAux(pref,l,siguientes(pal),resul);
	         }
         }
  
   else resul = NULL;
   
 return resul;
}

TPalabras buscarFinPrefijo(ArregloChars prefijo, TPalabras palabras) {
	TPalabras resul=NULL;
	nat l = 0;
	return FinPrefijoAux(prefijo,l,subarboles(palabras),resul);
}

void aux(TIterador iterEnt,TIterador iterSal){
	    if(estaDefinidaActual(iterEnt)){
			nat actual = actualEnIterador(iterEnt);
		    avanzarIterador(iterEnt);
		    aux(iterEnt,iterSal);
            agregarAIterador(actual,iterSal);
         }   
}

TIterador reversoDeIterador(TIterador iter) {
	TIterador iterRev = crearIterador();
	reiniciarIterador(iter);
        aux(iter,iterRev);
		return iterRev;
    }

