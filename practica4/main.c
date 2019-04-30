#include <stdio.h>
#include "funcionesRec.h"

int main()
{
  int opc=0;
  int numFibo=0, resFibo=0, i;

  Menu();
  scanf("%d", &opc);
  if(opc>0 && opc<5)
  {
    switch (opc)
    {
      case 1:
        printf("Selecciona el termino n-simo de la serie: ");
        scanf("%d", &numFibo);
        for(i=0; i==numFibo; i++)
        {
          resFibo= fibonacci(numFibo);
          printf("%d", resFibo);
        }
      break;

      case 2:
        system("cls");
        printf("San tribonacci :v");
      break;

      case 3:
        system("cls");
        printf("San Hanoi :v");
      break;

      case 4:
        system("cls");
        printf("Santa mezcla ordenada alv :v");
      break;
    }//switch
  }
  else
    exit(1);

  return 0;
}
