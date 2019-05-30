#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TADArbolBin.h"

/*
struct nodo{
	int dato;
	int bal;
	struct nodo *ptrIzq;
	struct nodo *ptrDer;
};
*/
int altura(struct nodo *ptr);
elemento balancear (struct nodo *ptrRaiz);
//void insertar(struct nodo **ptrRaiz, int miDato1);
void imprimirArbol(struct nodo *ptrRaiz, int contador);
void calculaAltura(struct nodo*p);
int maxProfundidad(struct nodo *ptrRaiz);
elemento rota_derecha(struct nodo*ptr);
elemento rota_izquierda(struct nodo*ptr);
int Menu();
