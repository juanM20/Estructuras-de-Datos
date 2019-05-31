#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TADArbolBin.h"

#define TAM_CADENA_DE_RUTA 200
#define TAM_PALABRA 50 //definimos el tamaño de la palabra.
#define TAM_DEF 650 //definimos el tamaño de la definicion.
#define TAM_CADENA TAM_DEF+TAM_PALABRA

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
void Menu();
void Cargar_Archivo(char* ruta, FILE* archivo);
