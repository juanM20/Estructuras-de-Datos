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

/*
Correcion de la expresion ingresada:
Recibe la cadena que acaba de entrar el usuario,
no devuelve valor, pero modifica la cadena a una nueva que sea entrada.
*/
void Corregir_Expresion(char *cad);

void Pasar_Posfijo(char *cad, boolean v);

int Evaluar_Expresion(char *cad);

void Obtener_Valores();



void Menu(){
  printf("\n1.Corregir expresion");
  printf("\n2.Validar Parentesis.");
  printf("\n3.Pasar a Posfija.");
  printf("\n4.Evaluar expresion");
  printf("\n5.Salir\n");

  return;
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

void Corregir_Expresion(char *cad)
{
  printf("Expresión anterior:\n%s", cad);
  printf("\n\nEscriba la nueva expresión:\n");
  scanf("%s", cad);
  //printf("%s\n", cad);

  return;
}

void Pasar_Posfijo(char *cad, boolean v)
{
  pila p;
  elemento e;
  int i=0;

  while(cad[i] != '\0')
  {
    if(cad[i] == '(')
    {
      e = cad[i];
      Push(&p,e);
    }
  }


  return;
}

int Evaluar_Expresion(char *cad)
{
  int valor;

  return valor;
}

void Obtener_Valores()
{

  return;
}

int main(){

  int opc;
  char cad[TAM]=""; //por sí solo ya es apuntador
  char cad_posfija[TAM]="";
  boolean v;

  printf("BIENVENIDO...\nPráctica sobre el TAD Pila.\nEl programa recibe una expresión en literales, y los valores de las mismas,\nfinalmente se obtiene el valor de la evaluación.\n");
  printf("\nEscribe una expresión:\n");
  scanf("%s",cad);

  do
  {
    Menu();
    scanf("%d", &opc);
    switch(opc)
    {

      case 1:
              Corregir_Expresion(cad);
              break;
      case 2:
              v = Validar_Parentesis(cad);
              if(v)
                printf("\nParentesis válidos, continúa...\n");
              else
              {
                printf("\nParentesis inválidos, corrígelo...\n");
                Corregir_Expresion(cad);
              }
              break;

      case 3:
<<<<<<< HEAD
              Pasar_Posfijo(&cad[0], v, &cad_posfija[0]);
=======
              Pasar_Posfijo(cad, v);
>>>>>>> 34ae54a61e9fccefb025745632775bee6572feda
              break;

      case 4:
              Evaluar_Expresion(cad);
              break;
    }
  }
  while (opc<5);

  return 0;
}
//this is a comentario alv :v
