//gcc TADList.c Tabla_hash.c Prueba_2.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tabla_hash.h"


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
  }

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
                  if(Tam_Lista(&colisiones[indice]) > 1) num_colisiones++;
                  Agregar_Definicion(&colisiones[indice],&palabra[0],&definicion[0]);
                  printf("\nIndice: %d \t%s : %s",indice, palabra, definicion);

                }

                printf("\nEstadísticas:\n\n");
                for(int i=0; i<TAM_TABLA; i++){
                  Imprimir_Colisiones(&colisiones[i]);
									printf("\n\n");
                }
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
