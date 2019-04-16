#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "TADList.h"

#define TAM_TABLA 200 //Tamaño de la tabla hash.
#define TAM_CADENAS 50 //Tamanio de todas las cadenas usadas para el tratamiento de binario/decimal.
#define MAX_VALOR_ASCII 255 //Guarda el maximo valor del ASCII (255).


typedef struct TablaH{

  lista list[TAM_TABLA];

}TablaH;

/*
Convierte la cadena leída del archivo a sus valores ASCII,
recibe la cadena y un arreglo de destino para estos valores.
*/
void Caracter_a_ASCII(char* cadena, int ascii[]);

/*
Convierte un numero decimal a binario,
recibe un entero, y devuelve un long con su equivalencia en base 2.
*/
long Dec_Bin(int numAscii);

/*
Convierte un numero binario a decimal,
recibe un long, y devuelve un int con su equivalencia en base 10.
*/
int Bin_Dec(long numBin);

/*
Cuenta los digitos que contiene el número binario, es util para analizar
dicho numero y manipularlo,
recibe el binario en formato long, y devuelve un entero que representa
la cantidad de digitos (0 o 1) que lo componen.
*/
int CuantaDigitosDeBinario(long num);

/*

*/
int Operacion_Hash(long numBin, long* numInicial);

/*

*/
long Suma_Binaria(long numBin, long numInicial);

/*

*/
long Compuerta_XOR(long sumaBinaria);

/*

*/
int Comparacion_XOR(int bitArraySuma, int bitAuxXOR);
