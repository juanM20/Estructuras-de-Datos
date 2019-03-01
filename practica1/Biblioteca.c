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
  //Vaciar_Arreglos(&cad[0], &cad_posfija[0], &literalesDeExpresion[0], &valoresDeLiterales, &auxiliarAntiRepeticion[0]);
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

float Potencia(float base, float exponente)
{
  float pot;

  if(base==0)
    pot=0;

  if(exponente==0)
    pot= 1;
  else
    pot= Potencia(base, exponente-1)*base;

  return pot;
}

float Evaluar_SubExpresiones(float valor1, char operador, float valor2)
{
  float r;

  if(operador=='+')
    r= valor1+valor2;

  if(operador=='-')
    r= valor1-valor2;

  if(operador=='*')
    r= valor1*valor2;

  if(operador=='/')
    r= valor1/valor2;

  if(operador=='^')
    r= Potencia(valor1, valor2);

  return r;
}

float Evaluar_Expresion(char *cad_posfija)
{
  float valor;

  elemento diccionario[TAM];
  int i=0, indice_dic=0, indice_cond=0;
  elemento elm, aux_elmL1, aux_elmL2; //char
  elemento elm_valorDeLetra; //float
  pila eval_pila_postfija;

  char valoresAOperar[2];
  char operador;

  float valorPrimeraLetra;
  float valorSegundaLetra;

  Initialize(&eval_pila_postfija);

  if(strlen(cad_posfija)==0)
    printf("\n\nParece que no has convertido a posfijo...");
  else
  {
    Obtener_Valores(cad_posfija, &diccionario[0],&indice_dic);
  /*  while(i < indice_dic+1)
    {
        printf("\n%c = %f", diccionario[i].c,diccionario[i].valor);
        i++;
    }*/

    while(cad_posfija[i] != '\0')
    {
      elm.c= cad_posfija[i];
      if(elm.c!='+' && elm.c!='-' && elm.c!='*' && elm.c!='/' && elm.c!='^')
      {
        printf("No es operador");
        //Busqueda en el diccionario
        /*i=0;
        while(i < indice_dic+1)
        {
          if(diccionario[i].c==elm.c)
            elm_valorDeLetra.valor= diccionario[i].valor;
            Push(&eval_pila_postfija, elm_valorDeLetra);
            printf("%f\n", diccionario[i].valor);
            printf("%ld\n", sizeof(diccionario));
        }*/
      }/*
      else
      {
        operador= elm.c;
        aux_elmL1= Pop(&eval_pila_postfija);
        valoresAOperar[1]= aux_elmL1.c;
        aux_elmL2= Pop(&eval_pila_postfija);
        valoresAOperar[0]= aux_elmL2.c;

        //Busqueda en el diccionario
        while(i < indice_dic+1)
        {
          if(diccionario[i].c==valoresAOperar[0])
            valorPrimeraLetra= diccionario[i].valor;

          if(diccionario[i].c==valoresAOperar[1])
            valorSegundaLetra= diccionario[i].valor;
        }

        elm_valorDeLetra.valor= Evaluar_SubExpresiones(valorPrimeraLetra, operador, valorSegundaLetra);
        if(Empty(&eval_pila_postfija))
          valor= elm_valorDeLetra.valor;
        else
          Push( &eval_pila_postfija,  elm_valorDeLetra);*/
      }
      i++;
    }////////////////

  return 0;//valor;
}



/*
float Evaluar_Expresion(char *cad_posfija)
{
  float valor=0;
  int indice_d=-1, indice_aux=-1;
  elemento diccionario[TAM];
  char arreglo_auxiliar[TAM];
  boolean repeticion = FALSE;
  pila p;
  elemento e;
  float operador1,operador2;

  int i=0;
  while(cad_posfija[i] != '\0')
  {
    if(cad_posfija[i]>=LIM_INFERIOR && cad_posfija[i] <= LIM_SUPERIOR)
    {
      if(indice_aux == -1)
      {
        indice_aux++;
        arreglo_auxiliar[indice_aux] = cad_posfija[i];

        indice_d++;
        diccionario[indice_d].c = cad_posfija[i];
      }
      else
      {

        int j=0;
        while(arreglo_auxiliar[j] != '\0')
        {
          if(cad_posfija[i] == arreglo_auxiliar[j])
          {
            repeticion = TRUE;
            break;
          }
        }

        if(repeticion == FALSE)
        {
          indice_d++;
          diccionario[indice_d].c = cad_posfija[i];

          indice_aux++;
          arreglo_auxiliar[indice_aux] = cad_posfija[i];
        }

      }
    }
    else
    {
      indice_d++;
      diccionario[indice_d].c = cad_posfija[i];
    }
  }

  for(int i=0; i<indice_d+1; i++)
  {
    if(cad_posfija[i]>=LIM_INFERIOR && cad_posfija[i]<=LIM_SUPERIOR)
    {
      printf("\nValor de %c:", diccionario[i].c);
      scanf("%f", &diccionario[i].valor);
    }
  }

  i=0;
  while(i < indice_d)
  {
    if(diccionario[i].c>=LIM_INFERIOR && diccionario[i].c<=LIM_SUPERIOR)
    {
      Push(&p,e);
    }
    else if(diccionario[i].c == '+')
    {
      operador2 = Pop(&p).valor;
      operador1 = Pop(&p).valor;
      e.valor = operador1 + operador2;
      Push(&p,e);
    }
    else if(diccionario[i].c == '-')
    {
      operador2 = Pop(&p).valor;
      operador1 = Pop(&p).valor;
      e.valor = operador1 - operador2;
      Push(&p,e);
    }
    else if(diccionario[i].c == '*')
    {
      operador2 = Pop(&p).valor;
      operador1 = Pop(&p).valor;
      e.valor = operador1 * operador2;
      Push(&p,e);
    }
    else if(diccionario[i].c == '/')
    {
      operador2 = Pop(&p).valor;
      operador1 = Pop(&p).valor;
      e.valor = operador1 / operador2;
      Push(&p,e);
    }
    else if(diccionario[i].c == '^')
    {
      operador2 = Pop(&p).valor;
      operador1 = Pop(&p).valor;
      e.valor = operador1 / operador2;
      Push(&p,e);
    }

    i++;
  }

  valor = Pop(&p).valor;

  return valor;
}
*/

void Obtener_Valores(char *cad_posfija, elemento *diccionario, int *indice_dic)
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
  for(i=0; i<strlen(cad_posfija); i++)
  {
    if(cad_posfija[i]>=LIM_INFERIOR && cad_posfija[i]<=LIM_SUPERIOR)
    {
      literalesDeExpresion[i_aux]=cad_posfija[i];
      i_aux++;
    }
  }
  No_Repite(&literalesDeExpresion[0], strlen(literalesDeExpresion), &diccionario[0], indice_dic);

  //pedir al ususario el valor de dichas literales
  int j=0;
  while(j < *indice_dic+1)
  {
    printf("\nValor de %c:", diccionario[j].c);
    scanf("%f",&diccionario[j].valor);
    j++;
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
void No_Repite(char *cadena,int tam,elemento *diccionario, int *indice_dic)
{
	int k=0,inicio,i;
  *indice_dic = 0;

	for(i=0;i<tam;++i)
  {
		if(i==0)
    {
			diccionario[*indice_dic].c = cadena[i];
		}
    else
    {
			for(inicio=0; inicio<=*indice_dic; ++inicio)
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
			if(k==*indice_dic+1)
      {
			  ++*indice_dic;
	      diccionario[*indice_dic].c = cadena[i];
	      k=0;
			}
		}
	}

  return;
}
/*
void Vaciar_Arreglos(char *cad, char *cad_posfija, char *literalesDeExpresion, int *valoresDeLiterales, char *auxiliarAntiRepeticion)
{
  int i;
  for(i=0; strlen(cad); i++)
    cad[i]="";

  for(i=0; strlen(cad_posfija); i++)
    cad_posfija[i]="";

  for(i=0; strlen(literalesDeExpresion); i++)
    literalesDeExpresion[i]="";

  for(i=0; sizeof(*valoresDeLiterales); i++)
    valoresDeLiterales[i]=NULL;

  for(i=0; strlen(auxiliarAntiRepeticion); i++)
    auxiliarAntiRepeticion[i]="";
}
*/
