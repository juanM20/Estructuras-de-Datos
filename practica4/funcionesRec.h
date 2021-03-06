#include <stdio.h>
#include <stdlib.h>

#define TAM_LISTA_NUMEROS 50

/*
No devuelve valores.
No recibe valores.
Funcion que se encarga de mostrar el menu al usuario.
*/
void Menu();

/*
Devuelve un numero muy largo que representa el termino n-simo de la sucesion Fibonacci.
Recibe un numero entero que representa el indice del termino n-simo de la sucesion Fibonacci que el usuario desea ver.
Funcion que se encarga de comparar los terminos n-simos para devolver cada uno de ellos de manera que el usuario pueda
consultar la sucesion.
*/
long long Fibonacci(int n);

/*
Devuelve un numero muy largo que representa el termino n-simo de la sucesion Tribonacci.
Recibe un numero entero que representa el indice del termino n-simo de la sucesion Tribonacci que el usuario desea ver.
Funcion que se encarga de comparar los terminos n-simos para devolver cada uno de ellos de manera que el usuario pueda
consultar la sucesion.
*/
long long Tribonacci(int n);

/*
Devuslve el numero de movimientos realizados.
Recibe el numero de discos que se usan, el palo de arranque (1), el paño auxiliar (2) y el palo de destino (3).
Se encarga de mostrar los movimientos de donde a donde se está moviendo cada disco.
*/
int Hanoi(int n,int com, int aux, int des);

/*

*/
int* Ordenamiento_Por_Mezcla(int* listaParaOrdenar, int tamLista);
