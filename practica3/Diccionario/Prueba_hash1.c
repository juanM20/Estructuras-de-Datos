#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define TAM_PALABRA 51
#define TAM_DEFINICION 251
#include "TablaHash.h"


int main()
{
  FILE * archivo;
  char caracter, c_aux;

	char palabra[TAM_CADENAS];
	char definicion[TAM_DEFINICION];
	int indice=0,opcion=0;
	lista colisiones[VALORCADENA];
  static int PosicionCadena[VALORCADENA]={0};
	elemento palabraEl;
	//inicializamos todas las pila que se usaran seran igual al numero de caracteres de la palabra
	for(int i=0;i<VALORCADENA;++i)
	Initialize(&colisiones[i]);
	menu();

	while(1){
	printf("Ingresa opcion\n");
	scanf("%d",&opcion);
	 switch(opcion){

     case 1:
            archivo = fopen("Lunfardo.txt","r");
            if(archivo == NULL) printf("\nError: no se puede abrir el archivo.\n");
            else{

              while( (caracter = fgetc(archivo)) != EOF){

                int i=0,j=0;

                if(c_aux != ':'){
                  int i=0;
                  palabra[i++] = caracter;
                }

                else if(c_aux != '.'){
                  int i=0;
                  c_aux = fgetc(archivo);
                  definicion[i++] = c_aux;
                }

                indice = sumaCaracteres(palabra)%VALORCADENA;
                guardaDefinicion(indice,palabra,definicion,&colisiones[indice]);

                caracter = c_aux;
              }
            }
     break;

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
