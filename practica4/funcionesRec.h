#include <stdio.h>
#include <stdlib.h>

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
long long fibonacci(int n);

/*
Devuelve un numero muy largo que representa el termino n-simo de la sucesion Tribonacci.
Recibe un numero entero que representa el indice del termino n-simo de la sucesion Tribonacci que el usuario desea ver.
Funcion que se encarga de comparar los terminos n-simos para devolver cada uno de ellos de manera que el usuario pueda
consultar la sucesion.
*/
long long tribonacci(int n);

/*

*/
void hanoi(int n,int com, int aux, int fin);
