#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<math.h>
#include "Biblioteca.h"

//CAMBIOS EUGENIO JE
void Menu()
{
  printf("\n1.Corregir expresion");
  printf("\n2.Validar Parentesis.");
  printf("\n3.Pasar a Posfija.");
  printf("\n4.Evaluar expresion");
  printf("\n5.Salir\n");

  return;
}

/*
 Recibe una expresion y devuelve un boolean

Efecto: La cadena que ingresamos puede o no estar correcta, comprueba eso y
regresa TRUE si lo esta de lo contrario FALSE

*/

boolean Validar_Parentesis(char *cad)
{
  boolean validado;
  int i=0;              //controla el paso por la cadena
  int tamCadena=0;      // Guarda el tamañano de la cadena
  pila pila_parentesis; //Guarda los parentesis ya que solo nos importan, por el momento
  elemento elm;         //  Guarda el tipo de dato deseado


  Initialize(&pila_parentesis);
  tamCadena= strlen(cad);

  for(i=0; i<=tamCadena; i++)  //recorre la cadena
  {
    if(cad[i]=='(')//Ingresa en la Pila si es (
    {
      elm.c='(';
      Push(&pila_parentesis, elm);
    }
    else
	if(cad[i]==')') // Si detecta un parentesis cerrado no lo guarda, hace pop y saca al de la ultima posicion
    {
      if(Empty(&pila_parentesis)) //si esta vacia cumple y salta todo los pasos hasta
      {
        validado=FALSE;//¿Para que guardas si al momento de combrobrobar que esta vacia lo cambias a TRUE?
        goto regresar; //puesto para poder salir del if, y tome el valor TRUE al seguri a la condicion final
      }
      else
      {
        elm= Pop(&pila_parentesis);// ¿para que se guarda el elemento sacado?

      }
    }

  }

   regresar: // correccion @Eugenio
  if(Empty(&pila_parentesis))
    validado=TRUE;
  else
    validado=FALSE;

  //regresar: ¿porque la pusiste aqui?
  return validado;
}


/* Recibe una cadena

 Efecto: Ingresa los primeros datos al comenzar el programa y puede corregir
  la cadena con la condicion que mande Validar_Parentesis()

  Excepciones: Rango de ingreso: "A-Z" Y "()"

 */

void Corregir_Expresion(char *cad)
{
 int i;

  //Vaciar_Arreglos(&cad[0], &cad_posfija[0], &literalesDeExpresion[0], &valoresDeLiterales, &auxiliarAntiRepeticion[0]);
  printf("\n\nEscriba la nueva expresion:\n");
  scanf("%s", cad);

  for(i=0;i<strlen(cad);++i){

   if(cad[i]>=97 && cad[i]<=122)
   {
     printf("Has ingresado un caracter fuera del rango A-Z\n");
      Corregir_Expresion(cad);
   }

  }

  //printf("%s\n", cad);
  return;
}

/*
    Recibe la cadena ingresada, la condicion si es correcta o no,
	y la cadena postfija- Referencia

	Efecto: Si recibe un TRUE continua con la expresion y la pasa a postfija

	Excepciones: Al recibir un FALSE puede que no haya validado al
    principio
*/

void Pasar_Posfijo(char *cad, boolean v, char *cad_posfija)
{
  pila pila_posfija;      // Guarda cadena
  elemento e;            //Caracter actual
  elemento aux_e;        //
  int i=0;               //CEl
  int aux=-1;

  Initialize(&pila_posfija);
  printf("\n");
  if(!v) {
  	printf("\nParece que no has validado tu expresion...");
  	printf("Expresion postfija: " );
  }
  else
  {
    while(cad[i] != '\0')//Mientras no encuentre caracter nulo
    {
      e.c = cad[i];

          switch(e.c){ //Caracter actual
           /*
             Si el primer  operador detectado es + ó -
            */
			case '-':
			case '+':
		  	if(Empty(&pila_posfija)) //si la pila esta vacia ingresa el caracter actual de la cadena
        	{
          	  Push(&pila_posfija,e);
        	}
        	else if(Top(&pila_posfija).c == '+' || Top(&pila_posfija).c == '-')
        	/* Si tienen el caracter actual tiene la misma precedencia que el tope de la pila
        	   Saca el tope de la pila e ingresa el caracter actual
        	*/
        	{

            	aux++;
            	cad_posfija[aux] = Pop(&pila_posfija).c;
            	Push(&pila_posfija,e);
        	}
        	else if(Top(&pila_posfija).c == '*' || Top(&pila_posfija).c == '/' || Top(&pila_posfija).c == '^')
        	/*Si el tope de la pila tiene mayor precedencia que el caracter actual
			*/
			{
         	 while(!Empty(&pila_posfija))//Mientras la pila no este vacia saca elemetos  de la pila
          	{
            	aux_e = Pop(&pila_posfija); // saca de la pila y guarda el tope

            	if(aux_e.c != '(') //si el ultimo elemento no es igual "("  guarda en la cadena_posfija
				{
             	 aux++;
              	cad_posfija[aux] = aux_e.c;
            	}
          	}

          	Push(&pila_posfija,e);    /*ya que se han sacado los elementos debajo del signo de mayor precedncia (pila vacia)
          	   						   se  coloca el caracter actual de la cadena en la pila*/
        }
        else if(Top(&pila_posfija).c == '('){  // si  la cadena actual comienza con "(" guarda directamente
          Push(&pila_posfija,e);
        }

	break;

	/*
    Si el primer  operador detectado es * ó /
    */
	case '*':
	case '/':

	  if(Empty(&pila_posfija))
        {
          Push(&pila_posfija,e);
        }
		else if(Top(&pila_posfija).c == '*' || Top(&pila_posfija).c == '/')	// caso misma precedencia
			{
            	++aux;
            	cad_posfija[aux] = Pop(&pila_posfija).c;
            	Push(&pila_posfija,e);
           }
        else if(Top(&pila_posfija).c == '+' || Top(&pila_posfija).c == '-')  //caso precedencia mayor al caracter actual
        {
          Push(&pila_posfija,e);
        }
        else if(Top(&pila_posfija).c == '^')  //caso de precedencia menor al caracter actual
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
        else if(Top(&pila_posfija).c == '(')
		{
          Push(&pila_posfija,e);
        }
	break;

	case '^':
	 Push(&pila_posfija,e);
	break;

	case ')'://caso cuando detecta que termino un parentesis
	  while(Empty(&pila_posfija)==FALSE) //Mientras la pila no este vacia saca elemetos  de la pila  NO ES TRUE !NO FUNCIONA
        {
          aux_e = Pop(&pila_posfija);// saca de la pila y guarda el tope

		  if(aux_e.c != '('){ //si el ultimo elemento no es igual "("  guarda en la cadena_posfija
            aux++;
            cad_posfija[aux] = aux_e.c;
          }else
            break;
        }
	break;

		case '(':   // Si detecta un parentesis "(" añade directamente a la pila
		Push(&pila_posfija,e);
		break;

  		default:  //  A todos los demas caracteres los encapsula y activan el default
    	++aux;
    	cad_posfija[aux] = e.c;
   		break;
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

    printf("Expresion postfija: %s",cad_posfija);

  }


  Destroy(&pila_posfija);
  return;
}



void Obtener_Valores(char* cad,float* valoresDeLiterales, char* auxiliarAntiRepeticion)
{
        //controla el paso por la cadena
  int i_aux=0;   // controla la posicion de la variable
  int o_aux=0;   //
  int j,k,l,m;
  /*
  Los siguientes 3 arreglos guardan las letras, sus valores, y sus no repeticiones respectivamente,
  la congruencia es que el valor en la posicion n de valoresDeLiterales
  corresponde a la letra en la misma posición en literalesDeExpresion,
  mientras que auxiliarAntiRepeticion guarda sólo una copia de cada literal.
  */

  //SE DEBE PONER 90 DEBIDO A QUE NUESTRO RANGO SON LAS MAYUSCULAS
  char literalesDeExpresion[90]="";

  printf("Expresion: %s\n", cad);
  //Obtener las literales de la expresion
  for(j=0; j<strlen(cad); j++)
  {
    if(cad[j]>=65 && cad[j]<=90)
    {
      literalesDeExpresion[i_aux]=cad[j];
      ++i_aux;
    }
  }

   No_Repite(literalesDeExpresion,i_aux,auxiliarAntiRepeticion);
  //pedir al ususario el valor de dichas literales
  //COMO EL ARREGLO GUAR DIRECTAMENTE EN LA POSICION QUE OCUPA EL CARACTER DEL CODIGO ASCII DEBEMOS LIMITAR A NUESTRO ARREGLO HASTA EL RANGO QUE QUEREMOS
  for(k=0; k<strlen(auxiliarAntiRepeticion); k++)
  {
    printf("Valor de %2c: ", auxiliarAntiRepeticion[k]);
    scanf("%f", &valoresDeLiterales[auxiliarAntiRepeticion[k]]);
  }

  printf("\n");
  //estos for solo prueban que los valores sean congruentes
  for(l=0; l<strlen(literalesDeExpresion); l++)
  {
    printf("%2c,  ", literalesDeExpresion[l]);
  }

printf("\n");

  for(m=0; m<strlen(literalesDeExpresion); m++)
  {
    printf("%.1f, ", valoresDeLiterales[literalesDeExpresion[m]]);
  }

 printf("\n\n");

  return;
}


//funcion que evita la repeticion

void No_Repite(char* cadena,int tam,char* resultado){
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



void Evaluar_Expresion(char* cad_posfija, float* valoresDeLiterales)
{
   pila resultado;
   elemento numero_conv;
   elemento valorNP;
   char float_cad[2]="";
   char cadena_num[strlen(cad_posfija)+10];
   int control_cn=0;
   int i;
   float n1;
   float n2;
  Initialize(&resultado);

printf("Pasos:\n");
   for(i=0;i<strlen(cad_posfija);i++)
   {
		switch(cad_posfija[i]){

		case '+':
		    n1= Pop(&resultado).valor;
			n2= Pop(&resultado).valor;
			printf("%.2f + %.2f\n",n2,n1);
			valorNP.valor= n1+n2;
			Push(&resultado,valorNP);
		break;


		case '-':
			n1= Pop(&resultado).valor;
			n2= Pop(&resultado).valor;
			printf("%.2f - %.2f\n",n2,n1);
			valorNP.valor= n1+n2;
			Push(&resultado,valorNP);
		break;


		case '/':
			n1= Pop(&resultado).valor;
			n2= Pop(&resultado).valor;
			printf("%.2f / %.2f\n",n2,n1);
			valorNP.valor= n2/n1;
			Push(&resultado,valorNP);
		break;


		case '*':
		    n1= Pop(&resultado).valor;
			n2= Pop(&resultado).valor;
			printf("%.2f * %.2f\n",n2,n1);
			valorNP.valor= n1*n2;
			Push(&resultado,valorNP);
		break;

		case '^':
		n1= Pop(&resultado).valor;
		n2= Pop(&resultado).valor;
			printf("%.2f ^ %.2f\n",n2,n1);
		valorNP.valor= pow(n2,n1);
		Push(&resultado,valorNP);
		break;


	    default:
	        sprintf(float_cad,"%.1f",valoresDeLiterales[cad_posfija[i]]);
			printf("nrl %s\n",cadena_num);
	    	numero_conv.valor=valoresDeLiterales[cad_posfija[i]];
	    	Push(&resultado,numero_conv);
	    break;

	}

   }

  printf("%s\n",cadena_num);
  printf("\nResultado de la expresion %.2f\n",Top(&resultado).valor);


}