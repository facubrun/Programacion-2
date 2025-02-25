/* 5265175 */ // sustituiir con los 7 dígitos de la cédula

#include "../include/aplicaciones.h"
#include "../include/cadena.h"
#include "../include/iterador.h"
#include <string.h>

void insertarACadena(TCadena &cad,TAbb a){
	if(a == NULL){}
	  else if(a != NULL){
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

void imprimir(int prof,TAbb a){
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

void caminoAscAux(nat clave,nat &k, TAbb a,TIterador &iter){
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
		   
void iPCortasAux(ArregloChars Arreglo,nat l,nat k, TPalabras palabras){
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
  if(pal!=NULL){
	  		
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

