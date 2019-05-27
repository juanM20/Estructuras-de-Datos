#include <stdio.h>
#include<stdlib.h>
#include<string.h>

int maximo(int a, int b);
int altura(struct nodo *ptr);
struct nodo* nuevoNodo(int dato1);
struct nodo* insertar(struct nodo *ptrRaiz, int midato1);
struct nodo *balancear (struct nodo *ptrRaiz);
//void insertar(struct nodo **ptrRaiz, int miDato1);
void imprimirArbol(struct nodo *ptrRaiz, int contador);
void preorden(struct nodo *ptrRaiz);
void inorden(struct nodo *ptrRaiz);
void postorden(struct nodo *ptrRaiz);
void eliminar(struct nodo **ptr, int clave);
void calculaAltura(struct nodo*p);
int maxProfundidad(struct nodo *ptrRaiz);
struct nodo *buscarDato(struct nodo *ptr, int clave);
struct nodo*rota_derecha(struct nodo*ptr);
struct nodo*rota_izquierda(struct nodo*ptr);
int Menu();
