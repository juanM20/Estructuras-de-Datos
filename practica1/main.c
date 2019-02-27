#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "TADPilaEst.h"
//#include "TADPilaDin.c"

#define TAM 100

void Menu(){

  printf("\n1.Escribir una expresion.");
  printf("\n2.Validar Parentesis.");
  printf("\n3.Pasar a Posfija.");
  printf("\n4.Agregar Valores.");
  printf("\n5.Salir.");
}

void Escribir_Expresion(char *cad)
{
    scanf("%s",&cad);
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




int main(){

  int opc,resp;
  char cad[TAM];
  boolean v;

  Menu();
  printf("\nElige una opcion: ");
  scanf("%d",&opc);

  switch(opc)
  {

    case 1:
            Escribir_Expresion(&cad[0]);
            break;
    case 2:
            v = Validar_Parentesis(&cad[0]);
  }

  return 0;
}
//this is a comentario alv :v
