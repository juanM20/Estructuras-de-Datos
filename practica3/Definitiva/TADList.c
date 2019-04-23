#include <stdio.h>
#include <stdlib.h>
#include "TADList.h"

void Init(lista *l){

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
       return;
   }

    nuevo_nodo->sig = l->frente;
    l->frente->ant = nuevo_nodo;
    l->frente = nuevo_nodo;

}

boolean Lista_Vacia(lista *l){

    boolean r=FALSE;

    if(l->frente==NULL && l->fin==NULL){
         r = TRUE;
    }

    return r;
}

void Eliminar(lista *l, long id){

    nodo *aux,*aux2;
    boolean r= FALSE;

    if(!Lista_Vacia(l)){

        aux = l->frente;

        while(aux != NULL){

            if(aux->e.id_palabra == id){

                aux2 = aux;
                aux->ant->sig = aux->sig;
                aux->sig->ant = aux->ant;
                r=TRUE;
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

        printf("\n%s: %s",aux->e.palabra, aux->e.significado);
        aux = aux->sig;
    }

}
