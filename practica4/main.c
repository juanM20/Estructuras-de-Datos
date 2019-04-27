#include <stdio.h>
#include "funcionesRec.h"

int main()
{
  int opc=0;

  menu();
  scanf("%d", &opc);

  do
  {
    switch (opc) {
      case 1:
        printf("San fibonacci :v");
        system("cls");
        menu();
      break;

      case 2:
        printf("San tribonacci :v");
        system("cls");
        menu();
      break;

      case 3:
        printf("San Hanoi :v");
        system("cls");
        menu();
      break;

      case 4:
        printf("Santa mezcla ordenada alv :v");
        system("cls");
        menu();
      break;
    }//switch
  }while(opc<5);


  return 0;
}
