#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Biblioteca.h"

void Menu()
{
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
  printf("\n\nEscriba la nueva expresión:\n");
  scanf("%s", cad);
  //printf("%s\n", cad);

  return;
}

void Pasar_Posfijo(char *cad, boolean v, char *cad_posfija)
{
  pila pila_posfija;
  elemento e,aux_e;
  int i=0,aux=-1;

  Initialize(&pila_posfija);

  if(!v) printf("\nParece que no has validado tu expresion...");
  else
  {
    while(cad[i] != '\0')
    {
      e.c = cad[i];

      if(e.c == '+' || e.c == '-')
      {
        if(Empty(&pila_posfija))
        {
          Push(&pila_posfija,e);
        }
        else if(Top(&pila_posfija).c == '+' || Top(&pila_posfija).c == '-')
        {
            aux++;
            cad_posfija[aux] = Pop(&pila_posfija).c;
            Push(&pila_posfija,e);
        }
        else if(Top(&pila_posfija).c == '*' || Top(&pila_posfija).c == '/' || Top(&pila_posfija).c == '^')
        {
          while(!Empty(&pila_posfija))
          {
            aux_e = Pop(&pila_posfija);
            if(aux_e.c != '('){
              aux++;
              cad_posfija[aux] = aux_e.c;
            }
          }
          Push(&pila_posfija,e);
        }
        else if(Top(&pila_posfija).c == '('){
          Push(&pila_posfija,e);
        }
      }
      else if(e.c == '*' || e.c == '/')
      {
        if(Empty(&pila_posfija))
        {
          Push(&pila_posfija,e);
        }
        else if(Top(&pila_posfija).c == '+' || Top(&pila_posfija).c == '-')
        {
          Push(&pila_posfija,e);
        }
        else if(Top(&pila_posfija).c == '^')
        {
          while(!Empty(&pila_posfija))
          {
            aux_e = Pop(&pila_posfija);
            if(aux_e.c != '('){
              aux++;
              cad_posfija[aux] = aux_e.c;
            }
          }
          Push(&pila_posfija,e);
        }
        else if(Top(&pila_posfija).c == '('){
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
          aux_e = Pop(&pila_posfija);
          if(aux_e.c != '('){
            aux++;
            cad_posfija[aux] = aux_e.c;
          }
        }
      }
      else if(e.c == '(')
      {
        Push(&pila_posfija,e);
      }
      else
      {
        aux++;
        cad_posfija[aux] = e.c;
      }
      i++;
    }

    while(!Empty(&pila_posfija))
    {
      aux_e = Pop(&pila_posfija);
      if(aux_e.c != '('){
        aux++;
        cad_posfija[aux] = aux_e.c;
      }
    }
  }
  Destroy(&pila_posfija);
  return;
}

int Evaluar_Expresion(char *cad_posfija)
{
  int valor;
  elemento diccionario[TAM];

  Obtener_Valores(cad_posfija, &diccionario[0]);

  return valor;
}

void Obtener_Valores(char *cad, elemento *diccionario)
{
  int i, i_aux=0;

  /*
  Los siguientes 3 arreglos guardan las letras, sus valores, y sus no repeticiones respectivamente,
  la congruencia es que el valor en la posicion n de valoresDeLiterales
  corresponde a la letra en la misma posición en literalesDeExpresion,
  mientras que auxiliarAntiRepeticion guarda sólo una copia de cada literal.
  */
  char literalesDeExpresion[TAM_CADENA_LITERALES]="";
  //int valoresDeLiterales[TAM_CADENA_LITERALES];
  //char auxiliarAntiRepeticion[TAM_CADENA_LITERALES]="";

  //Obtener las literales de la expresion
  for(i=0; i<strlen(cad); i++)
  {
    if(cad[i]>=LIM_INFERIOR && cad[i]<=LIM_SUPERIOR)
    {
      literalesDeExpresion[i_aux]=cad[i];
      i_aux++;
    }
  }
  No_Repite(literalesDeExpresion, strlen(literalesDeExpresion), diccionario);

  //pedir al ususario el valor de dichas literales
  for(i=0; i<strlen(auxiliarAntiRepeticion); i++)
  {
    printf("Valor de %c: ", auxiliarAntiRepeticion[i]);
    scanf("%d", &valoresDeLiterales[i]);
  }

/*
  //estos for solo prueban que los valores sean congruentes
  for(i=0; i<strlen(literalesDeExpresion); i++)
  {
    printf("%c,", literalesDeExpresion[i]);
  }
printf("\n");
  for(i=0; i<sizeof(*valoresDeLiterales); i++)
  {
    printf("%d,", valoresDeLiterales[i]);
  }
*/

  return;
}

//funcion que evita la repeticion
void No_Repite(char *cadena,int tam,elemento *diccionario)
{
	int j=0,k=0,inicio,i;

	for(i=0;i<tam;++i)
  {
		if(i==0)
    {
			diccionario[j].c = cadena[i];
		}
    else
    {
			for(inicio=0;inicio<=j;++inicio)
      {
				if((cadena[i] != diccionario[inicio].c ))
        {
					++k;
				}
        else
        {
					k=0;
				    break;
				}
			}
			if(k==j+1)
      {
			  ++j;
	      diccionario[j].c = cadena[i];
	      k=0;
			}
		}
	}

  return;
}
