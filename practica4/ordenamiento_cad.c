#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
  int dato;
  struct nodo *izq;
  struct nodo *der;

}nodo;


nodo *CrearNodo(int n){

	nodo *Nuevo_Nodo = (nodo *)malloc(sizeof(nodo));

	Nuevo_Nodo -> dato = n;
	Nuevo_Nodo -> der = NULL;
	Nuevo_Nodo -> izq = NULL;

	return Nuevo_Nodo;
}

void InsertarNodo(nodo **arbol, int n){

	if((*arbol) == NULL){

		nodo *Nuevo_Nodo = CrearNodo(n);
		(*arbol) = Nuevo_Nodo;

	}else{

		int Val_raiz = (*arbol)->dato;
		if(n < Val_raiz){

			InsertarNodo(&(*arbol)->izq,n);
		}else{
			InsertarNodo(&(*arbol)->der,n);
		}


	}
}

void Inorden(nodo *arbol){

  if(arbol != NULL){
    Inorden(arbol->izq);
    printf("%d ",arbol->dato);
    Inorden(arbol->der);
  }
}


int main(){

  long tam;
  int *arreglo;

  nodo *arbol;

  printf("\nNumero de elemntos: ");
  scanf("%ld",&tam);

  arreglo = (int *)malloc(sizeof(int)*tam);

  for(int i=0; i<tam; i++){
    scanf("%d",&arreglo[i]);
  }

  printf("\nLista:\n");

  for(int i=0; i<tam; i++){
    printf("%d ",arreglo[i]);
    InsertarNodo(&arbol, arreglo[i]);
  }

  printf("\n\nLista ordenada: \n");

  Inorden(arbol);

  return 0;
}
