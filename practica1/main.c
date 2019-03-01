/*
Forma de ejecución: gcc main.c TADPila(Est)(Din).c Biblioteca.c -o archivo_ejecutable
*/

#include <stdio.h>
#include "Biblioteca.h"

int main()
{
  int opc,resp;
  char cad[TAM];
  char cad_posfija[100];
  boolean v=FALSE;

  printf("BIENVENIDO...\nPráctica sobre el TAD Pila.\nEl programa recibe una expresión en literales, y los valores de las mismas,\nfinalmente se obtiene el valor de la evaluación.\n");
  printf("\nEscribe una expresión:\n");
  scanf("%s",&cad[0]);

  do
  {
    printf("\nExpresion: %s",cad);
    Menu();
    scanf("%d", &opc);
    switch(opc)
    {
      case 1:
              Corregir_Expresion(&cad[0]);
              break;
      case 2:
              v = Validar_Parentesis(&cad[0]);
              if(v)
                printf("\nParentesis válidos, continúa...\n");
              else
              {
                printf("\nParentesis inválidos, corrígelo...\n");
                Corregir_Expresion(&cad[0]);
              }
              break;

      case 3:
              Pasar_Posfijo(&cad[0], v, &cad_posfija[0]);
              printf("\nExpresion en posfijo: %s",cad_posfija);
              break;

      case 4:
              Evaluar_Expresion(&cad_posfija[0]);
              break;
    }
  } while (opc<5);

    return 0;
}
