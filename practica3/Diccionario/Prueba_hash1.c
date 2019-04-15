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
  char *c_aux;//cadena auxiliar que nos permitira extraer las palabras junto con su definicion.
  char *p = (char *)malloc(sizeof(char)*50), *def = (char *)malloc(sizeof(char)*150);// p es la palabra que se guardará y def es la definicion.
  c_aux = (char *)malloc(sizeof(char)*200);

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

                while(!feof(archivo)){

                  fgets(c_aux,200,archivo);

                  int i=0,j=0;
                  while(c_aux[i] != ':'){
                    p[i] = c_aux[i];
                    i++;
                  }
                  p[i] = '\0';
                  i++;
                  j=i;

                  i=0;
                  while(c_aux[j] != '\0'){
                    def[i] = c_aux[j];
                    i++;
                    j++;
                  }
                  def[i] = '\0';

                  printf("\n%s :: %s",p,def);
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
