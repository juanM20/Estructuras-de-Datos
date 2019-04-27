#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TADList.h"

void Init(lista *l){
    l->tam = 0;
    l->frente = NULL;
    l->fin = NULL;

}

void Insertar(lista *l, element e){

    nodo *nuevo_nodo = malloc(sizeof(nodo));
    nuevo_nodo->e = e;
    nuevo_nodo->sig = NULL;
    nuevo_nodo->ant = NULL;

   if(l->frente==NULL){

       l->frente = nuevo_nodo;
       l->fin = nuevo_nodo;
       l->tam++;
       return;
   }

    nuevo_nodo->sig = l->frente;
    l->frente->ant = nuevo_nodo;
    l->frente = nuevo_nodo;
    l->tam++;

}

boolean Lista_Vacia(lista *l){

    boolean r=FALSE;

    if(l->frente==NULL && l->fin==NULL){
         r = TRUE;
    }

    return r;
}

void Eliminar(lista *l, char *p){

    nodo *aux,*aux2;
    boolean r= FALSE;

    if(!Lista_Vacia(l)){

        aux = l->frente;

        while(aux != NULL){

            if(strcmp(aux->e.palabra,p) == 0){

                aux2 = aux;
                aux->ant->sig = aux->sig;
                aux->sig->ant = aux->ant;
                r=TRUE;
                l->tam--;
                break;
            }

            aux = aux->sig;
        }

        if(r == FALSE){
            printf("\nNo existe esa palabra...");
        }

    }
    else{
        printf("\nLa lista está vacía...");
    }

    if(r == TRUE) free(aux2);
}

void Imprimir_Lista(lista *l){

    nodo *aux;

    aux = l->frente;

    while(aux != NULL){

        printf("%s: %s -> ",aux->e.palabra, aux->e.significado);
        aux = aux->sig;
    }
}

void Imprimir_Colisiones(lista *l){

    nodo *aux;

    aux = l->frente;

    while(aux != NULL){

        printf("[%s]-> ", aux->e.palabra);
        aux = aux->sig;
    }
}

int Tam_Lista(lista *l){
  return l->tam;
}

void Buscar_Elemento(lista *l, char *p){

  nodo *aux = l->frente;

  while(aux != NULL){
    if(strcmp(aux->e.palabra,p) == 0){
      printf("\n%s: %s",aux->e.palabra,aux->e.significado);
      return;
    }
    aux = aux->sig;
  }

  printf("\nLa palabra no existe.");
  return;

}

void Modificar_Elemento(lista *l, char *p){

  nodo *aux = l->frente;
  char nueva_def[150];
  int i=0;

  while(aux != NULL){
    if(strcmp(aux->e.palabra,p) == 0){
      while(getchar() != '\n');
      printf("\nEcribe la nueva definicion: ");
      gets(nueva_def);
      while(nueva_def[i] != '\0'){
        aux->e.significado[i] = nueva_def[i];
        i++;
      }
      aux->e.significado[i] = '\0';

      printf("\n%s: %s",aux->e.palabra,aux->e.significado);
      return;
    }
    aux = aux->sig;
  }

  printf("\nLa palabra no existe.");
  return;

}
