#include <stdio.h>
#include <stdlib.h>
#include "funcionesRec.h"

/*

*/
void Menu()
{
  printf("Por favor elije el problema que deseas ver:\n");
  printf("1. Serie de Fibonacci.\n");
  printf("2. Serie de Tribonacci.\n");
  printf("3. Torres de Hanoi.\n");
  printf("4. Ordenamiento por mezcla.\n");
  printf("5. Salir.\n");
  return;
}

/*

*/
long long fibonacci(int n)
{
  long long fibo;
	if(n<2)//caso base
		fibo= n;
	else
    fibo= fibonacci(n-1) + fibonacci(n-2);

  return fibo;
}
