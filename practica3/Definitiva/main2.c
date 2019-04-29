//gcc TADList.c Tabla_hash.c Prueba_2.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tabla_hash.h"

/*
#define TAM_TABLA 600 //definimos el tamaño de la tabla HASH.
#define TAM_PALABRA 50 //definimos el tamaño de la palabra.
#define TAM_DEF 150 //definimos el tamaño de la definicion.
#define TAM_CADENA TAM_DEF+TAM_PALABRA
*/

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

  //Variables para la funcion hashing 2
  int numBins[TAM_CADENAS];
	int ascii[TAM_CADENAS];
	long numInicial= 00000000000000000000000000000000;

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

              archivo = fopen("BIOQUANTUM.txt","r");
              if(archivo == NULL) printf("\nErro: no se puede abrir el archivo");
              else
							{

                while(!feof(archivo))
								{

                  fgets(cad_aux,200,archivo);

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

                  //inicio de la funcion hashing
                  Caracter_a_ASCII(palabra, ascii);
                  for(int i=0; i<strlen(palabra); i++)
                    numBins[i] = Dec_Bin(ascii[i]);

                  for(i=0; i<strlen(palabra); i++)
                  	printf("\nSuma %d\n", Operacion_Hash(numBins[i], &numInicial));

                  //tam_bin= CuentaDigitosDeBinario(numBin);
                  printf("\n%d", Bin_Dec(numInicial));
                  indice = Bin_Dec(numInicial);
                  //fin de la funcion hashing

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

              //inicio de la funcion hashing
              Caracter_a_ASCII(palabra, ascii);
              for(int i=0; i<strlen(palabra); i++)
                numBins[i] = Dec_Bin(ascii[i]);

              for(i=0; i<strlen(palabra); i++)
                printf("\nSuma %d\n", Operacion_Hash(numBins[i], &numInicial));

              //tam_bin= CuentaDigitosDeBinario(numBin);
              printf("\n%d", Bin_Dec(numInicial));
              indice = Bin_Dec(numInicial);
              //fin de la funcion hashing

							Agregar_Definicion(&colisiones[indice],&palabra[0],&definicion[0]);
							printf("\nIndice: %d \t%s : %s",indice, palabra, definicion);

							break;
		 case 3:
		 					while(getchar() != '\n');
							printf("\nIngresa la palabra: ");
							gets(palabra);

              //inicio de la funcion hashing
              Caracter_a_ASCII(palabra, ascii);
              for(int i=0; i<strlen(palabra); i++)
                numBins[i] = Dec_Bin(ascii[i]);

              for(i=0; i<strlen(palabra); i++)
                printf("\nSuma %d\n", Operacion_Hash(numBins[i], &numInicial));

              //tam_bin= CuentaDigitosDeBinario(numBin);
              printf("\n%d", Bin_Dec(numInicial));
              indice = Bin_Dec(numInicial);
              //fin de la funcion hashing

							if(Tam_Lista(&colisiones[indice]) > 0)
								Buscar_Elemento(&colisiones[indice],palabra);
							else printf("\nNo existe la palabra.");

							break;
		 case 4:
		 					while(getchar() != '\n');
							printf("Ingresa la palabra: ");
							gets(palabra);

              //inicio de la funcion hashing
              Caracter_a_ASCII(palabra, ascii);
              for(int i=0; i<strlen(palabra); i++)
                numBins[i] = Dec_Bin(ascii[i]);

              for(i=0; i<strlen(palabra); i++)
                printf("\nSuma %d\n", Operacion_Hash(numBins[i], &numInicial));

              //tam_bin= CuentaDigitosDeBinario(numBin);
              printf("\n%d", Bin_Dec(numInicial));
              indice = Bin_Dec(numInicial);
              //fin de la funcion hashing

							if(Tam_Lista(&colisiones[indice]) > 0)
								Modificar_Elemento(&colisiones[indice],palabra);
							else printf("\nNo existe la palabra.");

							break;

		 case 5:
		 					while(getchar() != '\n');
							printf("Ingresa la palabra: ");
							gets(palabra);

              //inicio de la funcion hashing
              Caracter_a_ASCII(palabra, ascii);
              for(int i=0; i<strlen(palabra); i++)
                numBins[i] = Dec_Bin(ascii[i]);

              for(i=0; i<strlen(palabra); i++)
                printf("\nSuma %d\n", Operacion_Hash(numBins[i], &numInicial));

              //tam_bin= CuentaDigitosDeBinario(numBin);
              printf("\n%d", Bin_Dec(numInicial));
              indice = Bin_Dec(numInicial);
              //fin de la funcion hashing

							if(Tam_Lista(&colisiones[indice]) > 0)
								Eliminar(&colisiones[indice], palabra);
							else printf("\nNo existe la palabra.");

		  				break;

		 case 6:
							printf("\nEstadísticas:\n\n");
							num_colisiones=0;
							for(int i=0; i<TAM_TABLA; i++)
							{
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
