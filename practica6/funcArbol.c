#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcArbol.h"

int Menu()
{
  int opcion;
  printf("1. Para meter un dato en el arbol\n");
  printf("2. Para imprimir el arbol\n");
  printf("3. Para mostrar los datos del arbol en preorden\n");
  printf("4. Para mostrar los datos del arbol en inorden\n");
  printf("5. Para mostrar los datos del arbol en postorden\n");
  printf("6. Para mostrar profundidad del arbol\n");
  printf("7. Para eliminar dato del arbol\n");
  printf("8. Para salir del programa\n");
  scanf("%d",&opcion);
  return opcion;
}

void Cargar_Archivo()
{
  printf("Ingrese la ruta del archivo:\n");
  scanf();/*
  archivo = fopen("Lunfardo.txt","r");
  if(archivo == NULL)
    printf("\nERROR: NO SE PUEDE ABRIR EL ARCHIVO");
  else
  {

    while(!feof(archivo))
    {

      fgets(cad_aux,TAM_CADENA,archivo);

      i=0;
      while(cad_aux[i] != ':')
      {
        palabra[i] = cad_aux[i];
        i++;
      }
      palabra[i] = '\0';
      i++;
      j=i;

      i=0;
      while(cad_aux[j] != '\0')
      {
        definicion[i] = cad_aux[j];
        i++;
        j++;
      }

      definicion[i] = '\0';

      indice = sumaCaracteres(&palabra[0])%TAM_TABLA;
      if(Tam_Lista(&colisiones[indice]) > 1) num_colisiones++;
      Agregar_Definicion(&colisiones[indice],&palabra[0],&definicion[0]);
      printf("\nIndice: %d \t%s : %s",indice, palabra, definicion);

    }

  }*/
}
