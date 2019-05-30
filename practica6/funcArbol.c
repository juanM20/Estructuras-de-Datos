#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcArbol.h"

int Menu()
{
  int opcion;
  printf("1. Para meter un dato en el arbol\n");
  printf("2. Para imprimir el arbol\n");
  printf("3. Para mostrar los datos del arbol en preorden\n");
  printf("4. Para mostrar los datos del arbol en inorden\n");
  printf("5. Para mostrar los datos del arbol en postorden\n");
  printf("6. Para mostrar profundidad del arbol\n");
  printf("7. Para eliminar dato del arbol\n");
  printf("8. Para salir del programa\n");
  scanf("%d",&opcion);
  return opcion;
}

void Cargar_Archivo()
{
  printf("Ingrese la ruta del archivo:\n");
  scanf();/*
  archivo = fopen("Lunfardo.txt","r");
  if(archivo == NULL)
    printf("\nERROR: NO SE PUEDE ABRIR EL ARCHIVO");
  else
  {

    while(!feof(archivo))
    {

      fgets(cad_aux,TAM_CADENA,archivo);

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

      indice = sumaCaracteres(&palabra[0])%TAM_TABLA;
      if(Tam_Lista(&colisiones[indice]) > 1) num_colisiones++;
      Agregar_Definicion(&colisiones[indice],&palabra[0],&definicion[0]);
      printf("\nIndice: %d \t%s : %s",indice, palabra, definicion);

    }

  }*/
}

void imprimirArbol(struct nodo *ptrRaiz,int contador)
{
	int i,j;
	i=contador;
	if(ptrRaiz!=NULL)
	{
		imprimirArbol(ptrRaiz->ptrDer,i+1);
		printf("\n");
		for(j=1;j<i;j++)
			printf("-");
		printf("%d",ptrRaiz->dato);
		imprimirArbol(ptrRaiz->ptrIzq,i+1);
	}
}



struct nodo* balancear(struct nodo *ptr){
  calculaAltura(ptr);

     if ( altura(ptr -> ptrIzq) - altura(ptr -> ptrDer) == 2 )
     {
       printf("\nSe rota a la derecha" );
         if ( altura(ptr -> ptrIzq -> ptrDer) > altura(ptr -> ptrIzq -> ptrIzq) )
             ptr -> ptrIzq = rota_izquierda(ptr -> ptrIzq);
         return rota_derecha(ptr);
     }
     else if ( altura(ptr -> ptrDer) - altura(ptr -> ptrIzq) == 2 )
     {
       printf("\nSe rota a la izquierda" );
         if ( altura(ptr -> ptrDer -> ptrIzq) > altura(ptr -> ptrDer -> ptrDer) )
             ptr -> ptrDer = rota_derecha(ptr -> ptrDer);
         return rota_izquierda(ptr);
     }
     printf("\n %d",ptr->bal );
     return ptr;
}


void calculaAltura(struct nodo*p)
{
	p->bal=1+maximo(altura(p->ptrIzq),altura(p->ptrDer));
}

struct nodo* rota_izquierda(struct nodo* ptr){
    struct nodo * temp;
    temp = ptr -> ptrDer;
    ptr -> ptrDer = temp -> ptrIzq;
    temp -> ptrIzq = ptr;
    calculaAltura(ptr);
    calculaAltura(temp);
    return temp;
}

struct nodo* rota_derecha(struct nodo* ptr){
    struct nodo *temp;
    temp = ptr -> ptrIzq;
    ptr -> ptrIzq = temp -> ptrDer;
    temp -> ptrDer = ptr;
    calculaAltura(ptr);
    calculaAltura(temp);
    return temp;
}


int maxProfundidad(struct nodo*ptrRaiz)
{
	int profIzq, profDer;
	if(ptrRaiz==NULL)
	return 0;
	else
	{
		profIzq=maxProfundidad(ptrRaiz->ptrIzq);
   profDer=maxProfundidad(ptrRaiz->ptrDer);
   if(profIzq>profDer)
    return (profIzq+1);
   else
     return (profDer+1);
  }

}
