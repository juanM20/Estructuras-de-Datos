#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcArbol.h"

void Menu()
{
  printf("1. Cargar un archivo de deficiniones\n");
  printf("2. Agregar una palabra y su definicion\n");
  printf("3. Buscar una palabra y ver su definicion\n");
  printf("4. Modificar una definicion\n");
  printf("5. Eliminar una palabra\n");
  printf("6. Salir\n");
}

void Cargar_Archivo(char* ruta, FILE* archivo)
{
  //printf("%s", ruta);
  int i=0, j=0; //variables que nos ayudarán a indicar los indices de las cadenas donde se extraerán las palabras y definiciones.
  char cad_aux[TAM_CADENA];//cadena auxiliar que nos permitira extraer las palabras junto con su definicion.
  char palabra[TAM_PALABRA], definicion[TAM_DEF];// p es la palabra que se guardará y def es la definicion.
  archivo = fopen(ruta,"r");
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

    }
    printf("\nARCHIVO CARGADO CON EXITO!!!");

    //for(i=0; i<strlen(palabra); i++){
      printf("%s", palabra[0]);
    //}
  }
}


/*
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
*/
/*
struct nodo* balancear(struct nodo *ptr)
{
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
*/
/*
void calculaAltura(posicion p)
{
	p->e=1+maximo(altura(p->izq),altura(p->der));
}
*/
/*
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
*/
