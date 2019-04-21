#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TADList.h"

#define TAM_TABLA 20 //definimos el tamaño de la tabla HASH.
#define TAM_PALABRA 50 //definimos el tamaño de la palabra.
#define TAM_DEF 150 //definimos el tamaño de la definicion.
#define TAM_CADENA TAM_DEF+TAM_PALABRA



int sumaCaracteres(char * cadena){

	int sumatotal=0,i=0;

	while(cadena[i] != '\0'){
		sumatotal+=(int) cadena[i];
		i++;
	}

return sumatotal;

}

void Agregar_Definicion(lista *colision, char *palabra, char *definicion){

  element e;

  e.id_palabra = sumaCaracteres(palabra);
  strcpy(e.palabra, palabra);
  strcpy(e.significado, definicion);
  Insertar(colision,e);
}

void menu(){

	printf("1.- Cargar un archivo de definiciones\n"
				 "2.- Agregar una palabra y su definici�n\n"
				 "3.- Buscar una palabra y ver su definici�n\n"
				 "4.- Modificar una definici�n\n"
				 "5.- Eliminar una palabra\n"
				 "6.- Salir\n");
}

int main(){

  int opcion=0, respuesta=0; // variables para continuar en el menu y seleccionar una opcion.

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
    printf("tam[%d]: %d  ",i, colisiones[i].tam);
  }
  printf("\n");

  do{

    menu();
    printf("\nElige opcion: ");
    scanf("%d",&opcion);

    switch (opcion) {

      case 1:
              archivo = fopen("Lunfardo.txt","r");
              if(archivo == NULL) printf("\nErro: no se puede abrir el archivo");
              else{

                while(!feof(archivo)){

                  fgets(cad_aux,200,archivo);

                  i=0;
                  while(cad_aux[i] != ':'){
                    palabra[i] = cad_aux[i];
                    i++;
                  }
                  palabra[i] = '\0';
                  i++;
                  j=i;

                  i=0;
                  while(cad_aux[j] != '\0'){
                    definicion[i] = cad_aux[j];
                    i++;
                    j++;
                  }
                  definicion[i] = '\0';

                  indice = sumaCaracteres(&palabra[0])%TAM_TABLA;
                  //if(Tam_Lista(&colisiones[indice]) > 1) num_colisiones++;
                  //Agregar_Definicion(&colisiones[indice],&palabra[0],&definicion[0]);
                  printf("\nIndice: %d \t%s : %s",indice, palabra, definicion);

                }

                /*printf("\nEstadísticas:\n\n");
                for(int i=0; i<TAM_TABLA; i++){
                  Imprimir_Lista(&colisiones[i]);
                }*/
                printf("\nNumero de colisiones: %d",num_colisiones);

              }

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
