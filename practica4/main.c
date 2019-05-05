#include <stdio.h>
#include "funcionesRec.h"

int main()
{
  int nTermino=0, opc=0, i;
  char continuarMenu;

  int n;
  char com='1';
  char aux='2';
  char des='3';

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
          printf("n%d= %d,\n", i,fibonacci(i)); //se manda el término i a la funcion, para que se imprima la sucesion completa
      break;

      case 2:
        system("cls");
        printf("Selecciona el termino n-simo de la sucesion: n=");
        scanf("%d", &nTermino);
        printf("\nSerie Tribonacci:\n");
        for(i=0; i<=nTermino; i++)
          printf("%d,", tribonacci(i)); //se manda el término i a la funcion, para que se imprima la sucesion completa
      break;

      case 3:
        system("cls");

        printf("Ingrese el numero de discos\n");
        scanf("%d",&n);

        hanoi(n,com,aux,des);
      break;

      case 4:
        system("cls");
        printf("Santa mezcla ordenada alv :v");
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
