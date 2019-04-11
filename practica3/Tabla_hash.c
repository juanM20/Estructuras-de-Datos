#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Tabla_hash.h"

/*
Convierte la cadena leída del archivo a sus valores ASCII,
recibe la cadena y un arreglo de destino para estos valores.
*/
void Caracter_a_ASCII(char* cadena, int ascii[])
{
	int i;

	for(i=0; i<strlen(cadena); i++)
	{
		if(cadena[i]<0)
			ascii[i]=(int)(MAX_VALOR_ASCII+cadena[i])+1; //Porque es un número negativo en cadena[]
		else
			ascii[i]= (int)cadena[i];
	}

	return;
}

/*
Convierte un numero decimal a binario,
recibe un entero, y devuelve un long con su equivalencia en base 2.
*/
long Dec_Bin(int numAscii)
{
  long r_bin;
	int i;

	if(numAscii<2)
		r_bin= numAscii;
	else
		r_bin= numAscii%2 + (10*Dec_Bin(numAscii/2));

	return r_bin;
}

/*
Convierte un numero binario a decimal,
recibe un long, y devuelve un int con su equivalencia en base 10.
*/
int Bin_Dec(long numBin)
{
	int r_dec=0, tam_bin, i;
	int arrayNumBin[MAX_VALOR_ASCII];

	//meter binario a la cadena de enteros para poder opoerarlo
	tam_bin= CuentaDigitosDeBinario(numBin);
	for(i=0; i<tam_bin; i++)
	{
		arrayNumBin[i]= numBin%10;
		numBin= numBin/10;
	}

	//conversión a decimal
	for(i=0; i<tam_bin; i++)
	{
		r_dec+= pow(2, i)*arrayNumBin[i];
	}

	return r_dec;
}

/*
Cuenta los digitos que contiene el número binario, es util para analizar
dicho numero y manipularlo,
recibe el binario en formato long, y devuelve un entero que representa
la cantidad de digitos (0 o 1) que lo componen.
*/
int CuentaDigitosDeBinario(long num)
{
	int contador=1;

	while(num/10>0)
	{
		num=num/10;
		contador++;
	}

	return contador;
}

/*

*/
int Operacion_Hash(long numBin)
{
	int ret;
	printf("%d\n", numBin);

	return ret;
}
