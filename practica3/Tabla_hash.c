#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Tabla_hash.h"

void caracter_a_ASCII(char* cadena, int ascii[])
{
	int i;

	for(i=0; i<strlen(cadena); i++)
	{
		if(cadena[i]<0)
			ascii[i]=(int)(MAX_VALOR_ASCII+cadena[i])+1;
		else
			ascii[i]= (int)cadena[i];
	}

	return;
}

long dec_bin(int numAscii)
{
  long r_bin;
	int i;

	if(numAscii<2)
		r_bin= numAscii;
	else
		r_bin= numAscii%2 + (10*dec_bin(numAscii/2));

	return r_bin;
}

int bin_dec(long numBin)
{
	int r_dec=0, tam_bin, i;
	int arrayNumBin[MAX_VALOR_ASCII];

	//meter binario a la cadena de enteros para poder opoerarlo
	tam_bin= cuentaDigitosDeBinario(numBin);
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


int cuentaDigitosDeBinario(long num)
{
	int contador=1;

	while(num/10>0)
	{
		num=num/10;
		contador++;
	}

	return contador;
}
