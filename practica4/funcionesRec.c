#include <stdio.h>
#include <stdlib.h>
#include "funcionesRec.h"

/*

*/
void Menu()
{
  printf("BIENVENIDO A LA PRACTICA 4, SOLUCIONES RECURSIVAS\n");
  printf("Por favor elije el problema que deseas ver:\n");
  printf("1. Serie de Fibonacci.\n");
  printf("2. Serie de Tribonacci.\n");
  printf("3. Torres de Hanoi.\n");
  printf("4. Ordenamiento por mezcla.\n");
  return;
}

/*

*/
long fibonacci(int n)
{
  long fibo;
	if(n==0 || n==1)//Caso base
		fibo= n;
	else
		fibo= fibonacci(n-2) + fibonacci(n-1);

  return fibo;
}
