#include <stdio.h>
#include "funcionesRec.h"

int main()
{
  int opc=0;

  Menu();
  scanf("%d", &opc);
  if(opc>0 && opc<5)
  {
    switch (opc)
    {
      case 1:
        system("cls");
        printf("San fibonacci :v");
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

  return 0;
}
