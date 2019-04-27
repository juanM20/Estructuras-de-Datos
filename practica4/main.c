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
        printf("San fibonacci :v");
        system("cls");
        Menu();
      break;

      case 2:
        printf("San tribonacci :v");
        system("cls");
        Menu();
      break;

      case 3:
        printf("San Hanoi :v");
        system("cls");
        Menu();
      break;

      case 4:
        printf("Santa mezcla ordenada alv :v");
        system("cls");
        Menu();
      break;
    }//switch
  }

  return 0;
}
