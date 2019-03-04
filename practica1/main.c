/*
Forma de ejecuciÃ³n: gcc main.c TADPila(Est)(Din).c Biblioteca.c -o archivo_ejecutable
*/

#include <stdio.h>
#include "Biblioteca.h"

int main()
{
  int opc;                     //opcion del menu
  char cad[TAM];               // guarda la expresion
  char cad_posfija[TAM];       // guarda la expresion postfija
  boolean v=FALSE;
  float valoresDeLiterales[90];
  char auxiliarAntiRepeticion[90]="";

  printf("BIENVENIDO...\nPrÃ¡ctica sobre el TAD Pila.\nEl programa recibe una expresiÃ³n en literales, y los valores de las mismas,\nfinalmente se obtiene el valor de la evaluaciÃ³n.\n");
   Corregir_Expresion(cad);
   Menu();
  do
  {
    printf("\nExpresion: %s",cad);
    printf("\nSelecciona opcion\n");
    scanf("%d", &opc);

if(opc>0 && opc<5) //LIMITA EL INGRESO
    switch(opc)
    {
      case 1:
             system("cls");
                Menu();
              Corregir_Expresion(cad);
              break;
      case 2:
              v = Validar_Parentesis(cad);
              if(v){
              	 system("cls");
              	     Menu();
              	  printf("\nParentesis validos, continua...\n");
			  }

              else
              {
			    system("cls");
			        Menu();
                printf("\nParentesis invalidos, corrigelo...\n");
                Corregir_Expresion(cad);
              }
              break;

      case 3:
      	       system("cls");
      	       Menu();
              Pasar_Posfijo(cad, v, cad_posfija);

              break;

      case 4:
      	       system("cls");
      	       Menu();
      	        Obtener_Valores(cad,valoresDeLiterales,auxiliarAntiRepeticion);
                Evaluar_Expresion(cad_posfija,valoresDeLiterales);
              break;
    }else
      printf("Ingrese del 1-5\n");
  } while (opc<5);

    return 0;
}
