//gcc TADList.c main-2.c -o Funcion_Hash-2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "TADList.h"

#define TAM_TABLA 700 //definimos el tamaño de la tabla HASH.
#define TAM_PALABRA 50 //definimos el tamaño de la palabra.
#define TAM_DEF 650 //definimos el tamaño de la definicion.
#define TAM_CADENA TAM_DEF+TAM_PALABRA

/*
Esta es la funcion hashing
que nos dara el indice donde
colocaremos la palabra y su definicion
en la tabla hash.
*/
long long sumaCaracteres(char * cadena)
{

	int i=0, car=0;
	long long sumatotal=0;


	while(cadena[i] != '\0'){

		car = (int)cadena[i];
		if(car < 0) car*=-1;

		sumatotal += car*(pow(i,2));
		i++;
	}

	if(sumatotal < 0)
		sumatotal*=-1;

return sumatotal;

}

/*Funcion Agregar_Definicion:
	Se copian las cadenas de palabra y definicion
	en una variable de tipo "elment" para insertarlas
	después en la tabla hash dependiendo de
*/
void Agregar_Definicion(lista *colision, char *palabra, char *definicion)
{

  element e;
	int i=0;

	while(palabra[i] != '\0'){
		e.palabra[i] = palabra[i];
		i++;
	}
	e.palabra[i] = '\0';

	i=0;
	while(definicion[i] != '\0'){
		e.significado[i] = definicion[i];
		i++;
	}
	e.significado[i] = '\0';

  Insertar(colision,e);
}

void menu()
{

	printf("\n1.- Cargar un archivo de definiciones\n"
				 "2.- Agregar una palabra y su definici�n\n"
				 "3.- Buscar una palabra y ver su definici�n\n"
				 "4.- Modificar una definici�n\n"
				 "5.- Eliminar una palabra\n"
				 "6.- Mostrar Estadisticas\n"
				 "7.- Salir\n");
}


int main()
{

  int opcion=0, respuesta=0; // variables para continuar en el menu y seleccionar una opcion.
	int opcion2=0;//opcion para elegir funcion hash.

  /*Estas variables se ocuparan para manipular el archivo que se leerá
    y también se extraerán las "palabras" con su respectiva "definición".
  */
  FILE * archivo;
  char cad_aux[TAM_CADENA];//cadena auxiliar que nos permitira extraer las palabras junto con su definicion.
  char palabra[TAM_PALABRA], definicion[TAM_DEF];// p es la palabra que se guardará y def es la definicion.
  int i=0,j=0; //variables que nos ayudarán a indicar los indices de las cadenas donde se extraerán las palabras y definiciones.

  int indice=0, num_colisiones=0;
  lista colisiones[TAM_TABLA];

  for(int i=0; i<TAM_TABLA; i++){
    Init(&colisiones[i]);
  }

  do{

    menu();
    printf("\nElige opcion: ");
    scanf("%d",&opcion);

    switch (opcion) {

      case 1:

              archivo = fopen("Lunfardo.txt","r");
              if(archivo == NULL) printf("\nErro: no se puede abrir el archivo");
              else
							{

                while(!feof(archivo))
								{

                  fgets(cad_aux,TAM_CADENA,archivo);

                  i=0;
                  while(cad_aux[i] != ':')
									{
                    palabra[i] = cad_aux[i];
                    i++;
                  }
                  palabra[i] = '\0';
                  i++;
                  j=i;

                  i=0;
                  while(cad_aux[j] != '\0')
									{
                    definicion[i] = cad_aux[j];
                    i++;
                    j++;
                  }

                  definicion[i] = '\0';

                  indice = sumaCaracteres(&palabra[0])%TAM_TABLA;
                  if(Tam_Lista(&colisiones[indice]) > 1) num_colisiones++;
                  Agregar_Definicion(&colisiones[indice],&palabra[0],&definicion[0]);
                  printf("\nIndice: %d \t%s : %s",indice, palabra, definicion);

                }

							}

              break;
			case 2:

							while(getchar() != '\n');
							printf("\nIngresa la palabra: ");
							gets(palabra);

							printf("presiona enter.");
							while(getchar() != '\n');
							printf("\nIngresa una Definicion: ");
							gets(definicion);

							indice = sumaCaracteres(&palabra[0])%TAM_TABLA;
							Agregar_Definicion(&colisiones[indice],&palabra[0],&definicion[0]);
							printf("\nIndice: %d \t%s : %s",indice, palabra, definicion);

							break;
		 case 3:
		 					while(getchar() != '\n');
							printf("\nIngresa la palabra: ");
							gets(palabra);
							indice = sumaCaracteres(&palabra[0])%TAM_TABLA;
							if(Tam_Lista(&colisiones[indice]) > 0)
								Buscar_Elemento(&colisiones[indice],palabra);
							else printf("\nNo existe la palabra.");

							break;
		 case 4:
		 					while(getchar() != '\n');
							printf("Ingresa la palabra: ");
							gets(palabra);
							indice = sumaCaracteres(&palabra[0])%TAM_TABLA;
							if(Tam_Lista(&colisiones[indice]) > 0)
								Modificar_Elemento(&colisiones[indice],palabra);
							else printf("\nNo existe la palabra.");

							break;

		 case 5:
		 					while(getchar() != '\n');
							printf("Ingresa la palabra: ");
							gets(palabra);
							indice = sumaCaracteres(&palabra[0])%TAM_TABLA;
							if(Tam_Lista(&colisiones[indice]) > 0)
								Eliminar(&colisiones[indice], palabra);
							else printf("\nNo existe la palabra.");

		  				break;

		 case 6:
							printf("\nEstadísticas:\n\n");
							num_colisiones=0;
							for(int i=0; i<TAM_TABLA; i++)
							{
								if(Tam_Lista(&colisiones[i]) >= 2)
									num_colisiones += Tam_Lista(&colisiones[i])-1;

								printf("Lista: %d ",i+1);
								Imprimir_Colisiones(&colisiones[i]);
								printf("\n\n");
							}
							printf("\nNumero de colisiones: %d",num_colisiones);

		 					break;
		 case 7:
				 			exit(0);
				 		  break;

      default:
              printf("\nError: No existe esa opcion por favor prueba otra vez.");
              break;
    }

    printf("\nSeguir en el Menu: ");
    scanf("%d",&respuesta);

  }while(respuesta == 1);


  return 0;
}
