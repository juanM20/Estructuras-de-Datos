#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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
long long Fibonacci(int n)
{
  long long fibo; //long long es para que pueda abarcar los numeros muy grandes
	if(n<2) //caso base
		fibo= n; //regresa 0 o 1 en esta condicion
	else
  {
    if(n>40)
      fibo= (1/sqrt(5))*(pow((1+sqrt(5))/2,n)-pow((1-sqrt(5))/2,n));
    else
      fibo= Fibonacci(n-1)+Fibonacci(n-2);
  }
  return fibo;
}

/*
Devuelve un numero muy largo que representa el termino n-simo de la sucesion Tribonacci.
Recibe un numero entero que representa el indice del termino n-simo de la sucesion Tribonacci que el usuario desea ver.
Funcion que se encarga de comparar los terminos n-simos para devolver cada uno de ellos de manera que el usuario pueda
consultar la sucesion.
*/
long long Tribonacci(int n)
{
  long long tribo; //long long es para que pueda abarcar los numeros muy grandes
	if(n<2) //caso base
		tribo= n; //regresa 0 o 1 en esta condicion
  else if(n==2)
    tribo= n-1;
	else
    tribo= Tribonacci(n-1)+Tribonacci(n-2)+Tribonacci(n-3);

  return tribo;
}

/*
Devuslve el numero de movimientos realizados.
Recibe el numero de discos que se usan, el palo de arranque (1), el paño auxiliar (2) y el palo de destino (3).
Se encarga de mostrar los movimientos de donde a donde se está moviendo cada disco.
*/
int Hanoi(int n,int com, int aux, int des)
{
  int nMovimientos;
  if(n==1)
  {
    printf("%c->%c",com,des);
    nMovimientos=1;
  }
  else{
    Hanoi(n-1,com,des,aux);
    nMovimientos++;
    printf("\n%c->%c\n",com,des);
    Hanoi(n-1,aux,com,des);
    nMovimientos++;
  }

  return nMovimientos;
}

/*
int* Ordenamiento_Por_Mezcla(int* listaParaOrdenar, int tamLista)
{
  int i, j, k;
  int mitadIzquierda[TAM_LISTA_NUMEROS];
  int mitadDerecha[TAM_LISTA_NUMEROS];

  for(i=0; i<tamLista; i++)
  {
    printf("%d, ",listaParaOrdenar[i]);
  }


  if (tamLista>1)
  {
      for(i=0; i<tamLista/2; i++)
        mitadIzquierda[i] = listaParaOrdenar[i];

      for(i=tamLista/2; i<tamLista; i++)
        mitadDerecha[i] = listaParaOrdenar[i];

      Ordenamiento_Por_Mezcla(mitadIzquierda, tamLista/2);
      Ordenamiento_Por_Mezcla(mitadDerecha, tamLista-(tamLista/2));

      i=0;
      j=0;
      k=0;
      while (i<tamLista/2 && j<tamLista-(tamLista/2))
      {
        if (mitadIzquierda[i]<mitadDerecha[j])
        {
          listaParaOrdenar[k]=mitadIzquierda[i];
          i=i+1;
        }
        else
        {
          listaParaOrdenar[k]=mitadDerecha[j];
          j=j+1;
          k=k+1;
        }
      }

      while (i < tamLista/2)
      {
        listaParaOrdenar[k]=mitadIzquierda[i];
        i=i+1;
        k=k+1;
      }

      while (j < tamLista-(tamLista/2))
      {
        listaParaOrdenar[k]=mitadDerecha[j];
        j=j+1;
        k=k+1;
      }
  }
  //printf("Mezclar ",listaParaOrdenar);

  Ordenamiento_Por_Mezcla(listaParaOrdenar, tamLista-1);


  for(i=0; i<tamLista; i++)
  {
    printf("%d, ",listaParaOrdenar[i]);
  }

  return listaParaOrdenar;
}
*/
