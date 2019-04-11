#include <stdio.h>
#include <stdlib.h>

int main(){

  FILE *archivo;
  char caracter;

  archivo = fopen("Lunfardo.txt","r");

  if(archivo == NULL){
    printf("\nError: no se puede abrir el archivo.\n\n");
  }
  else{
    printf("\nContenido del archivo: \n\n");

    while( (caracter = fgetc(archivo)) != EOF ){
      printf("%c", caracter);
    }
  }
  fclose(archivo);

  return 0;
}
