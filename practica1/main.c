#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "TADPilaEst.c"
//#include "TADPilaDin.c"

#define TAM 100

void Menu(){

  printf("\n1.Escribir una expresion.");
  printf("\n2.Validar Parentesis.");
  printf("\n3.Pasar a Posfija.");
  printf("\n4.Agregar Valores.");
  printf("\n5.Salir.");
}

void Escribir_Expresion(char *cad)
{
    scanf("%s",&cad);
}

boolean Validar_Parentesis(char *cad)
{
<<<<<<< HEAD

=======
  boolean validado=0;

  return validado;
>>>>>>> e945dc849ff61f76a6a4336bd4694213c8a7e864
}


int main(){

  int opc,resp;
  char cad[TAM];
  boolean v;

  Menu();
  printf("\nElige una opcion: ");
  scanf("%d",&opc);

  switch(opc)
  {

    case 1:
            Escribir_Expresion(&cad[0]);
            break;
    case 2:
            v = Validar_Parentesis(&cad[0]);
  }

}
//this is a comentario alv :v
