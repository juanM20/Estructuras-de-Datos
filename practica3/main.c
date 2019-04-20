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
	long numInicial= 00000000000000000000000000000000;
	int i;

	int prov=0;
	//printf("%d", (array0s));
	printf("Ingresa una cadena: \n");
	gets(cadena);
	Caracter_a_ASCII(cadena, ascii);

	for(i=0; i<strlen(cadena); i++)
		numBins[i]= Dec_Bin(ascii[i]);


	for(i=0; i<strlen(cadena); i++)
		printf("\nSuma %d\n", Operacion_Hash(numBins[i], &numInicial));

	//tam_bin= CuentaDigitosDeBinario(numBin);



	//printf("\n%d", Bin_Dec(numInicial));

//Compuerta_XOR(10101);
return 0;
}
