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

/*
Convertir la Expresion de infija a posfija:
Recibe...
 -la direccion de cadena que se quiere convertir.
 -la variable que verifica si esta validada la expresion dada.
 -la direccion de la cadena donde se escribira la conversion de infija a posfija.
 Devuelve...
 -Nada.
*/
void Pasar_Posfijo(char *cad, boolean v, char *cad_posfija);

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
    validado=FALSE;

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

void Pasar_Posfijo(char *cad, boolean v, char *cad_posfija)
{
  pila pila_posfija;
  elemento e;
  int i=0,aux=0;

  if(!v) printf("\nLa expresion no es válida...");
  else
  {
    while(cad[i] != '\0')
    {
      e.c = cad[i];

      if(e.c == '+' || e.c == '-')
      {
        if(Top(&pila_posfija).c == '+' || Top(&pila_posfija).c)
        {
            aux++;
            cad_posfija[aux] = Pop(&pila_posfija).c;
            Push(&pila_posfija,e);
        }
        else if(Top(&pila_posfija).c == '*' || Top(&pila_posfija).c == '/' || Top(&pila_posfija).c == '^')
        {
          while(!Empty(&pila_posfija))
          {
            aux++;
            cad_posfija[aux] = Pop(&pila_posfija).c;
          }
          Push(&pila_posfija,e);
        }
      }
      else if(e.c == '*' || e.c == '/')
      {
        if(Top(&pila_posfija).c == '+' || Top(&pila_posfija).c == '-')
        {
          Push(&pila_posfija,e);
        }
        else if(Top(&p).c == '^')
        {
          while(!Empty(&pila_posfija))
          {
            aux++;
            cad_posfija[aux] = Pop(&pila_posfija).c;
          }
          Push(&pila_posfija,e);
        }
      }
      else if(e.c == '^')
      {
        Push(&pila_posfija,e);
      }
      else if(e.c == ')')
      {

        while(!Empty(&pila_posfija))
        {
          aux++;
          cad_posfija[aux] = Pop(&pila_posfija).c;
        }
      }
      else
      {
        aux++;
        cad_posfija[aux] = e.c;
      }
    }
    aux++;
    cad_posfija[aux] = '\0';

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
  boolean v=FALSE;

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
              Pasar_Posfijo(&cad[0], v, &cad_posfija[0]);
<<<<<<< HEAD
=======
              printf("\nExpresion en posfijo: %s",cad_posfija);
>>>>>>> 2564171a10150ae308608e449a86802d7920bd0b
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
