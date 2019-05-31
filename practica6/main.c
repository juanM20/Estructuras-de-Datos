#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include "funcArbol.h"

int main()
{
  int opc=0, i;
  char continuarMenu;
  char rutaDeArchivo[TAM_CADENA_DE_RUTA];
  FILE* archivo;

  printf("BIENVENIDO A LA PRACTICA 6, DICCIONAIO CON AVL\n");
  printf("Selecciona una opcion\n\n");

  do
  {
    Menu();
    scanf("%d", &opc);
    switch (opc)
    {
      case 1:
        system("cls");
        printf("Ingrese la ruta del archivo:\n");
        scanf("%s", rutaDeArchivo);
        //gets(rutaDeArchivo);
        Cargar_Archivo(rutaDeArchivo, archivo);
      break;

      case 2:
        system("cls");
        printf("Agregar palabra y definicion");
      break;

      case 3:
        system("cls");
        printf("Buscar palabra y definicion");
      break;

      case 4:
        system("cls");
        printf("Modificar una definicion");
      break;

      case 5:
        system("cls");
        printf("Eliminar una palabra");
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
