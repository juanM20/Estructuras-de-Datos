#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "TADPilaEst.h"
//#include "TADPilaDin.c"

#define TAM 100

//Muestra el menú para que el usuario inrteractúe con el programa
void Menu();

/*
Validación de paréntesis:
Recibe una cadena y devuelve TRUE si los paréntesis
son correctos, y FALSE si no lo son.
*/
boolean Validar_Parentesis(char *cad);



void Menu(){
  printf("\n1.");
  printf("\n2.Validar Parentesis.");
  printf("\n3.Pasar a Posfija.");
  printf("\n4.Evaluar expresión");
  printf("\n5.Salir.");
}


boolean Validar_Parentesis(char *cad)
{
  boolean validado;
  int i=0, tamCadena=0;
  pila pila_parentesis;
  elemento elm;
  Initialize(&pila_parentesis);
  tamCadena= strlen(cad);

  for(i=0; i<=tamCadena; i++)
  {
    if(cad[i]=='(')
    {
      elm.c='(';
      Push(&pila_parentesis, elm);
    }
    else if(cad[i]==')')
    {
      if(Empty(&pila_parentesis))
      {
        validado=FALSE;
        goto regresar; //puesto para poder salir del if, y tome el valor TRUE al seguri a la condición final
      }
      else
      {
        elm= Pop(&pila_parentesis);

      }
    }
  }

  if(Empty(&pila_parentesis))
    validado=TRUE;
  else
  {
    validado=FALSE;
  }
  regresar:

  return validado;
}

void Pasar_Posfijo(char *cad, boolean v)
{

}




int main(){

  int opc;
  char cad[TAM]="";

  printf("BIENVENIDO...\nPractica sobre el TAD Pila.\nEl programa recibe una expresion en literales, y los valores de las mismas,\nfinalmente se obtiene el valor de la evaluacion.\n");
  printf("\nEscribe una expresion:\n");
  scanf("%s",cad);
  
/*
  switch(opc)
  {

    case 1:
            Escribir_Expresion();
            break;
    case 2:
            v = Validar_Parentesis(&cad[0]);
            break;

    case 3:
            Pasar_Posfijo(&cad[0], v);
            break;
  }
*/
  return 0;
}
//this is a comentario alv :v
