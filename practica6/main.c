#include <stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
  struct nodo *miPtrRaiz;
	miPtrRaiz=NULL;
	int clave;
	int maxi;
	int numnodos=0;

	for(;;)
	{

		int seleccion=menu();
		switch(seleccion)
		{
			case 1:
				printf("Ingrese un valor entero:\n");
				scanf("%d",&clave);
				getchar();
				miPtrRaiz=insertar(miPtrRaiz, clave);
				printf("\n");
			break;
			case 2:
				system("cls");
				imprimirArbol(miPtrRaiz,1);
				printf("\n");
			break;
			case 3:
				system("cls");
				printf("\nPreorden\n");
				preorden(miPtrRaiz);
			break;
			case 4:
				system("cls");
				printf("\nInorden\n");
				inorden(miPtrRaiz);
			break;
			case 5:
				system("cls");
				printf("\nPostorden\n");
				postorden(miPtrRaiz);
			break;
			case 6:
				system("cls");
				printf("\nProfundidad:%d",maxProfundidad(miPtrRaiz));
				getchar();
			break;
			case 7:
				system("cls");
				printf("Elimine un valor entero \n");
				scanf("%d",&clave);
				getchar();
				eliminar(&miPtrRaiz, clave);
				printf("\n");
				imprimirArbol(miPtrRaiz,1);
				printf("\n");
				printf("\nPreorden\n");
				preorden(miPtrRaiz);
				printf("\nInorden\n");
				inorden(miPtrRaiz);
				printf("\nPostorden\n");
				postorden(miPtrRaiz);
				maxi=maxProfundidad(miPtrRaiz);
				printf("\nProfundidad:     %d\n",maxi);
				system("pause");
				system("cls");

			break;
			case 8:
				exit(0);
			default:
				printf("Intente otra vez. Ingrese del 1 al 8\n");
				getchar();

		}
	}

  return 0;
}
