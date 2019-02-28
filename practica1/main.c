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

/*
Recibe la cadena postfija y devuelve el valor de
la evaluación.
Primero pide los valores de las literales por medio de Obtener_Valores.
*/
int Evaluar_Expresion(char *cad_posfija);

/*
Se ayuda de No_Repite, para pedir los valores de la literales una sola vez.
Recibe la cadena de Evaluar_Expresion, no devuelve valores.
*/
void Obtener_Valores(char *cad);

/*
primer argumeto es el arreglo de solo literales, el segundo el tamaño del
arreglo literales y el tercero es en donde se guardar el arreglo sin repeticion,
el arreglo sin repeticiones se modifica por referencia por lo tanto no nesecita enviar nada
*/
void No_Repite(char cadena[],int tam,char resultado[]);

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
  Obtener_Valores(cad_posfija);

  return valor;
}

void Obtener_Valores(char *cad)
{
  int i, i_aux=0, o, o_aux=1;
  /*
  Los siguientes 3 arreglos guardan las letras, sus valores, y sus no repeticiones respectivamente,
  la congruencia es que el valor en la posicion n de valoresDeLiterales
  corresponde a la letra en la misma posición en literalesDeExpresion,
  mientras que auxiliarAntiRepeticion guarda sólo una copia de cada literal.
  */
  char literalesDeExpresion[55]="";
  int valoresDeLiterales[55];
  char auxiliarAntiRepeticion[55]="";

  //Obtener las literales de la expresion
  for(i=0; i<strlen(cad); i++)
  {
    if(cad[i]>=65 && cad[i]<=90)
    {
      literalesDeExpresion[i_aux]=cad[i];
      i_aux++;
    }
  }

  //pedir al ususario el valor de dichas literales
  for(i=0; i<strlen(literalesDeExpresion); i++)
  {
    printf("Valor de %c: ", literalesDeExpresion[i]);
    scanf("%d", &valoresDeLiterales[i]);
  }

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


  return;
}

//funcion que evita la repeticion
void No_Repite(char cadena[],int tam,char resultado[]){
	int j=0,k=0,inicio,i;

	for(i=0;i<tam;++i){
		if(i==0){

			resultado[j]=cadena[i];
		}else{

			for(inicio=0;inicio<=j;++inicio){

				if((cadena[i]!=resultado[inicio])){
					++k;
				}else {
					k=0;
				    break;
				}
			}

			if(k==j+1){
			  ++j;
	          resultado[j]=cadena[i];
	           k=0;
			}
		}
	}
}

int main(){

  int opc,resp;
  char cad[TAM]; //por sí solo ya es apuntador
  char cad_posfija[100];
  boolean v=FALSE;

  printf("BIENVENIDO...\nPráctica sobre el TAD Pila.\nEl programa recibe una expresión en literales, y los valores de las mismas,\nfinalmente se obtiene el valor de la evaluación.\n");
  printf("\nEscribe una expresión:\n");
  scanf("%s",cad);

  do
  {
    printf("\nExpresion: %s",cad);
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
              printf("\nExpresion en posfijo: %s",cad_posfija);
              break;

      case 4:
              Evaluar_Expresion(&cad_posfija[0]);
              break;
    }

    /*printf("\nQuieres continuar: Si=1 No=0");
    scanf("%d",&resp);*/

  } while (opc<5);

  return 0;
}
