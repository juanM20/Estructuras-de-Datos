#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Tabla_hash.h"

int main()
{
	char cadena[TAM_CADENAS];
	int numBins[TAM_CADENAS];
	//int numDecs[TAM_CADENAS];
	int ascii[TAM_CADENAS];
	int array0s[]= {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};//32 es el tamaño que naneja el simulador
	int i;

	int prov=0;
	//printf("%d", (array0s));
	printf("Ingresa una cadena: \n");
	gets(cadena);
	caracter_a_ASCII(cadena, ascii);

	for(i=0; i<strlen(cadena); i++)
	{
		numBins[i]= dec_bin(ascii[i]);
	}

	for(i=0; i<strlen(cadena); i++)
	{
		Operacion_Hash(numBins[i]);
	}



return 0;
}
