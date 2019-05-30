/*
Compilacion
gcc main.c funcionesRec.c -o main
*/

#include <stdio.h>
#include "funcionesRec.h"

int main()
{
  int nTermino=0, opc=0, i;
  char continuarMenu;
  int listaDeNumeros[TAM_LISTA_NUMEROS], auxlistaDeNumeros, nParaOrdenar;

  int n;
  char com;
  char aux;
  char des;

  printf("BIENVENIDO A LA PRACTICA 4, SOLUCIONES RECURSIVAS\n\n");

  do
  {
    Menu();
    scanf("%d", &opc);
    switch (opc)
    {
      case 1:
        system("cls");
        printf("Selecciona el termino n-simo de la sucesion: n=");
        scanf("%d", &nTermino);
        printf("\nSerie Fibonacci:\n");
        for(i=0; i<=nTermino; i++)
          printf("n%d= %d,\n", i,Fibonacci(i)); //se manda el término i a la funcion, para que se imprima la sucesion completa
      break;

      case 2:
        system("cls");
        printf("Selecciona el termino n-simo de la sucesion: n=");
        scanf("%d", &nTermino);
        printf("\nSerie Tribonacci:\n");
        for(i=0; i<=nTermino; i++)
          printf("%d,", Tribonacci(i)); //se manda el término i a la funcion, para que se imprima la sucesion completa
      break;

      case 3:
        system("cls");
        com='1';
        aux='2';
        des='3';
        printf("Ingrese el numero de discos: n=");
        scanf("%d",&n);
        Hanoi(n,com,aux,des);
      break;

      case 4:
        system("cls");

        printf("Cuantos numeros va a ordenar?\n");
        scanf("%d", &nParaOrdenar);
        printf("Ingrese los numeros a ordenar:\n");
        for(i=0; i<nParaOrdenar; i++)
        {
          printf("n%d= ", i+1);
          scanf("%d", &listaDeNumeros[i]);
        }

      break;

      default:
        exit(1);
    }//switch

    fflush(stdin);
    printf("\n\nSeguir en el menu? (S/N): ");
    scanf("%c", &continuarMenu);

  }while(continuarMenu=='s' || continuarMenu=='S');

  return 0;
}
