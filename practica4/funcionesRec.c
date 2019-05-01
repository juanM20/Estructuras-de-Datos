#include <stdio.h>
#include <stdlib.h>
#include "funcionesRec.h"

/*
No devuelve valores.
No recibe valores.
Funcion que se encarga de mostrar el menu al usuario.
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
Devuelve un numero muy largo que representa el termino n-simo de la sucesion Fibonacci.
Recibe un numero entero que representa el indice del termino n-simo de la sucesion Fibonacci que el usuario desea ver.
Funcion que se encarga de comparar los terminos n-simos para devolver cada uno de ellos de manera que el usuario pueda
consultar la sucesion.
*/
long long fibonacci(int n)
{
  long long fibo; //long long es para que pueda abarcar los numeros muy grandes
	if(n<2) //caso base
		fibo= n; //regresa 0 o 1 en esta condicion
	else
    fibo= fibonacci(n-1)+fibonacci(n-2);

  return fibo;
}

/*
Devuelve un numero muy largo que representa el termino n-simo de la sucesion Tribonacci.
Recibe un numero entero que representa el indice del termino n-simo de la sucesion Tribonacci que el usuario desea ver.
Funcion que se encarga de comparar los terminos n-simos para devolver cada uno de ellos de manera que el usuario pueda
consultar la sucesion.
*/
long long tribonacci(int n)
{
  long long tribo; //long long es para que pueda abarcar los numeros muy grandes
	if(n<2) //caso base
		tribo= n; //regresa 0 o 1 en esta condicion
  else if(n==2)
    tribo= n-1;
	else
    tribo= tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3);

  return tribo;
}
