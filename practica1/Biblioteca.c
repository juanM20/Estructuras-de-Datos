/*
//NUEVO PUSH
IMPLEMENTACION: Implemetación de la Biblioteca de funciones especificas
AUTORES:
Ayona Lopez Eugenio Milton
BenÃ­tez Morales Manuel Emilio
Juan Manuel Tellez "EL PANCHO"


Febrero 2019
VERSIÃ“N: 1.0

DESCRIPCIÃ“N: Herramientas usadas en el programa.
Lista de funciones:
Cada una de las funciones que aquí se declaran, cumplen un objetivo
especifico en la implemetnacion, para poder llevar a cabo operaciones
separadas de manera correcta.

OBSERVACIONES: Esta libreria utiliza a TADPila Est o Din, y es la presente,
que se importa en el archivo principal.

COMPILACIÃ“N PARA GENERAR EL CÃ“DIGO OBJETO: gcc Biblioteca.c -c
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<math.h>
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
        Pop(&pila_parentesis);

      }
    }

  }

   regresar: // correccion @Eugenio
  if(Empty(&pila_parentesis))
    validado=TRUE;
  else
    validado=FALSE;

  //regresar: ¿porque la pusiste aqui?//jajajaa bambi XD  MIRA AQUI ERA EL ERROR, donde??

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

boolean Pasar_Posfijo(char *cad, boolean v, char *cad_posfija)
{
  pila pila_posfija;      // Guarda cadena
  elemento e;            //Caracter actual
  elemento aux_e;        //
  int i=0;
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

            	++aux;
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
             	 ++aux;
              	cad_posfija[aux] = aux_e.c;
            	} else
                break;
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
              ++aux;
              cad_posfija[aux] = aux_e.c;
            }else
              break;
          }
          Push(&pila_posfija,e);

        }
        else if(Top(&pila_posfija).c == '(')
		{
          Push(&pila_posfija,e);
        }
	break;

	case '^':

  if(Top(&pila_posfija).c == '+' || Top(&pila_posfija).c == '-'||Top(&pila_posfija).c == '/' ||Top(&pila_posfija).c == '*')  //caso precedencia mayor al caracter actual
 {
   Push(&pila_posfija,e);
 }else if(Top(&pila_posfija).c == '^'){ //MISMA PRECEDENCIA
   ++aux;
    cad_posfija[aux] = Pop(&pila_posfija).c;
    Push(&pila_posfija,e);
 }  else if(Top(&pila_posfija).c == '(')
   {
     Push(&pila_posfija,e);
   }

	break;

	case ')'://caso cuando detecta que termino un parentesis
	  while(Empty(&pila_posfija)==FALSE) //Mientras la pila no este vacia saca elemetos  de la pila  NO ES TRUE !NO FUNCIONA
        {
          aux_e = Pop(&pila_posfija);// saca de la pila y guarda el tope

		  if(aux_e.c != '('){ //si el ultimo elemento no es igual "("  guarda en la cadena_posfija
            ++aux;
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
        ++aux;
        cad_posfija[aux] = aux_e.c;
      }
    }

    printf("Expresion postfija: %s",cad_posfija);
  }


  Destroy(&pila_posfija);
  return TRUE;
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
  //COMO EL ARREGLO GUAR DIRECTAMENTE EN LA POSICION QUE OCUPA EL
  //CARACTER DEL CODIGO ASCII DEBEMOS LIMITAR A NUESTRO ARREGLO HASTA EL RANGO QUE QUEREMOS
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
//ESPERO LE  ENTIENDAN AMIGOS
void No_Repite(char* cadena,int tam,char* resultado){
<<<<<<< HEAD
<<<<<<< HEAD
	int j=0,k=0,inicio,i;

//recorre la cadena con repeticiones hasta que llega la final
	for(i=0;i<tam;++i){

  //la primera letra la mmete al arreglo sin repeticiones directamente
=======
=======
>>>>>>> ffb1065ba236890b0fa0df0c9bc6603adc27c73b
	int j=0;
  int k=0;
  int inicio;
  int i;
//AAABAA
	for(i=0;i<tam;++i){//Recorre el arreglo con repeticiones
<<<<<<< HEAD
>>>>>>> 05ff76b93a6b831a9a5491e46c206b0b79875084
=======
>>>>>>> ffb1065ba236890b0fa0df0c9bc6603adc27c73b
		if(i==0){

			resultado[j]=cadena[i]; // Si es el primer caracter que toca se incluye en el arreglo sin repeticion
		}else{

<<<<<<< HEAD
<<<<<<< HEAD
      //recorre las letras del arreglo sin repeticion
			for(inicio=0;inicio<=j;++inicio){
        //si detecta caracter diferente a los de la cadena sin repeticion
				if((cadena[i]!=resultado[inicio])){
					++k;
=======

 //j es variable su maximo sera los elementos sin repeticion por ejemplo AABBCCC el max de j sera [0,2]
			for(inicio=0;inicio<=j;++inicio){//Recorre el arreglo sin repeticiones

				if((cadena[i]!=resultado[inicio])){ //Con base a la cadena con repeticiones y la cadena sin repeticiones
                                            //verifica si dentro de la cadena que la cadena sin repeticiones
                                            //no este el caracter actual de la cadena con repeticiones
                                            // en sintesis si un elemento de cadena no es igual a un elemento de resultado
                                            // no habre

					++k;  // Cada vez que haya un elemento diferente que no este dentro de resultado aumenta k
                //prueba todas las combinaciones que puede haber entre el arreglo cadena y resultado por ejemplo
                // CAD: AABBC  RES: A

                   /*CAD        RES
                      A          A    NO PASA NADA  K=0 Y DETIENE INTERNO  1)
                      A          A    1)
                      B          A    ELEMENTO DIFERENTE AUMENTA LA POSICION GUARDA B EN RES: AB  J DE RESULTADO Y SITUA A K=0 2)
                      B          A    COMO J AUMENTO ESPERA QUE SE PRUEBEN TODAS LAS COMBINACIONES DE RESULTADO
                      B          B   1)
                      C          A   2)
                      C          B   2)
                      C                 //SI PASA POR TODO EL ARREGLO resultado  SIGNIFICA QUE NO ENCONTRO ELEMENTO PARECIDO K= TAM(RESULTADO)

                  */
>>>>>>> ffb1065ba236890b0fa0df0c9bc6603adc27c73b
				}else {
					  k=0;    //cuando haya un elemento igual en los dos arreglos detiene el ciclo interno
				    break;
				}
			}

<<<<<<< HEAD
    //como k solo aumenta cuando el caracter es diferente al que esta en la cadena sin repeticion
    //

			if(k==j+1){
			  ++j;
	      resultado[j]=cadena[i];
	       k=0;
=======

 //j es variable su maximo sera los elementos sin repeticion por ejemplo AABBCCC el max de j sera [0,2]
			for(inicio=0;inicio<=j;++inicio){//Recorre el arreglo sin repeticiones

				if((cadena[i]!=resultado[inicio])){ //Con base a la cadena con repeticiones y la cadena sin repeticiones
                                            //verifica si dentro de la cadena que la cadena sin repeticiones
                                            //no este el caracter actual de la cadena con repeticiones
                                            // en sintesis si un elemento de cadena no es igual a un elemento de resultado
                                            // no habre

					++k;  // Cada vez que haya un elemento diferente que no este dentro de resultado aumenta k
                //prueba todas las combinaciones que puede haber entre el arreglo cadena y resultado por ejemplo
                // CAD: AABBC  RES: A

                   /*CAD        RES
                      A          A    NO PASA NADA  K=0 Y DETIENE INTERNO  1)
                      A          A    1)
                      B          A    ELEMENTO DIFERENTE AUMENTA LA POSICION GUARDA B EN RES: AB  J DE RESULTADO Y SITUA A K=0 2)
                      B          A    COMO J AUMENTO ESPERA QUE SE PRUEBEN TODAS LAS COMBINACIONES DE RESULTADO
                      B          B   1)
                      C          A   2)
                      C          B   2)
                      C                 //SI PASA POR TODO EL ARREGLO resultado  SIGNIFICA QUE NO ENCONTRO ELEMENTO PARECIDO K= TAM(RESULTADO)

                  */
				}else {
					  k=0;    //cuando haya un elemento igual en los dos arreglos detiene el ciclo interno
				    break;
				}
			}

=======
>>>>>>> ffb1065ba236890b0fa0df0c9bc6603adc27c73b
			if(k==j+1){ // SOLO ABRE CUANDO PRUEBA TODO EL ARREGLO RESULTADO FUE PROBADO CUANDO NO ENCUENTRA NIGUNA CONCIDENIA
			      ++j;
	          resultado[j]=cadena[i];
	           k=0;
<<<<<<< HEAD
>>>>>>> 05ff76b93a6b831a9a5491e46c206b0b79875084
=======
>>>>>>> ffb1065ba236890b0fa0df0c9bc6603adc27c73b
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
			valorNP.valor= n2-n1;
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
	    	numero_conv.valor=valoresDeLiterales[cad_posfija[i]];
	    	Push(&resultado,numero_conv);
	    break;

	}

   }
  printf("\nResultado de la expresion %.2f\n",Top(&resultado).valor);

}
