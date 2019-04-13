#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define TAM_PALABRA 51
#define TAM_DEFINICION 251
#include "TablaHash.h"


int main()
{
	char palabra[TAM_CADENAS];
	char definicion[TAM_DEFINICION];
	int indice=0,i=0,opcion=0;
	lista colisiones[VALORCADENA];
  static int PosicionCadena[VALORCADENA]={0};
	elemento palabraEl;
	//inicializamos todas las pila que se usaran seran igual al numero de caracteres de la palabra
	for(i=0;i<VALORCADENA;++i)
	Initialize(&colisiones[i]);
	menu();

	while(1){
	printf("Ingresa opcion\n");
	scanf("%d",&opcion);
	 switch(opcion){

		  case 2:
		  	    fflush(stdin);
		  			printf("Ingresa una Palabra: \n");
		        gets(palabra);
		        ++PosicionCadena[(sumaCaracteres(palabra))];
		        printf("vxvv %d %d\n",sumaCaracteres(palabra), PosicionCadena[(sumaCaracteres(palabra))]);
		        printf("Ingresa una Definicion: \n");
		        gets(definicion);
		        indice=sumaCaracteres(palabra)%VALORCADENA;
		        guardaDefinicion(indice,palabra,definicion,&colisiones[indice]);
		  break;

		  case 3:
		  	    fflush(stdin);
	          printf("Ingresa la palabra buscada: \n");
		        gets(palabra);
		        indice=sumaCaracteres(palabra)%VALORCADENA;
		        BusquedaPalabra(PosicionCadena[sumaCaracteres(palabra)],&colisiones[indice]);
	      break;


	      case 5:
	        		fflush(stdin);
		 					printf("Ingresa la palabra eliminada: \n");
		    			gets(palabra);


		    			indice=sumaCaracteres(palabra)%VALORCADENA;
		 					strcpy (palabraEl.p,palabra);
		 					Elimina( PosicionCadena[(sumaCaracteres(palabra))],&colisiones[indice], palabraEl);
	    	break;


		}

	}


return 0;
}
