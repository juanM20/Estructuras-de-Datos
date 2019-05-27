#include <stdio.h>
#include<stdlib.h>
#include<string.h>

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

struct nodo{
	int dato;
	int bal;
	struct nodo *ptrIzq;
	struct nodo *ptrDer;
};





struct nodo* nuevoNodo(int dato1)
{
	struct nodo *ptrAux;
	ptrAux=(struct nodo *)malloc(sizeof(struct nodo));
	ptrAux->dato=dato1;
	ptrAux->bal=1;
	ptrAux->ptrIzq=ptrAux->ptrDer=NULL;
	system("cls");
	return ptrAux;
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


int maximo(int a, int b)
{
	if(a>b)
		return a;
	else
		return b;
}

int altura(struct nodo* ptr){
    if (ptr == NULL)
        return  0;
    else
        return (ptr -> bal) ;
}

struct nodo* insertar(struct nodo *ptrRaiz, int midato1){
  if(ptrRaiz==NULL)
    return nuevoNodo(midato1);
  else if(midato1 < ptrRaiz->dato)
    ptrRaiz->ptrIzq = insertar(ptrRaiz->ptrIzq, midato1);
  else if(midato1 > ptrRaiz->dato)
      ptrRaiz->ptrDer = insertar(ptrRaiz->ptrDer, midato1);
  else
      ptrRaiz->dato=midato1;
      return balancear(ptrRaiz);
}

/*void insertar (struct nodo **ptrRaiz, int miDato1)
{
	if(*ptrRaiz==NULL)
	*ptrRaiz=nuevoNodo(miDato1);
	else if(miDato1<(*ptrRaiz)->dato)
		insertar(&((*ptrRaiz)->ptrIzq),miDato1);
	else
		insertar(&((*ptrRaiz)->ptrDer),miDato1);
}*/


void preorden(struct nodo *ptrRaiz){
  if(ptrRaiz!=NULL){
    printf("\n %d \n", ptrRaiz->dato);
    preorden(ptrRaiz->ptrIzq);
    preorden(ptrRaiz->ptrDer);
  }
}

void inorden(struct nodo *ptrRaiz)
{
	if(ptrRaiz!=NULL)
	{
		inorden(ptrRaiz->ptrIzq);
		printf("\n %d\n",ptrRaiz->dato);
		inorden(ptrRaiz->ptrDer);
	}
}

void postorden(struct nodo *ptrRaiz)
{
	if(ptrRaiz!=NULL)
	{
		postorden(ptrRaiz->ptrIzq);
		postorden(ptrRaiz->ptrDer);
		printf("\n %d\n", ptrRaiz->dato);
	}
}

void recorrer(struct nodo **aPtrRaiz, struct nodo **bPtrRaiz, struct nodo **cPtrRaiz)
{
	if((*bPtrRaiz)->ptrDer!=NULL)
		recorrer(aPtrRaiz,&(*bPtrRaiz)->ptrDer,cPtrRaiz);
	else
		{
			(*aPtrRaiz)->dato=(*bPtrRaiz)->dato;
			*cPtrRaiz=*bPtrRaiz;
			*bPtrRaiz=(*bPtrRaiz)->ptrIzq;
		}
}

void eliminar(struct nodo **ptrRaiz, int clave)
{
	if(*ptrRaiz==NULL)
	{
		printf("El dato no existe\n");
		getchar();
	}
	else if(clave<(*ptrRaiz)->dato)
		eliminar(&(*ptrRaiz)->ptrIzq,clave);
	else if(clave>(*ptrRaiz)->dato)
		eliminar(&(*ptrRaiz)->ptrDer,clave);
	else
	{
		struct nodo *ptrAux;
		ptrAux=(*ptrRaiz);
		if(ptrAux->ptrIzq==NULL)
			(*ptrRaiz)=ptrAux->ptrIzq;
		else if(ptrAux->ptrDer==NULL)
			(*ptrRaiz)=ptrAux->ptrIzq;
		else
			recorrer(ptrRaiz,&(*ptrRaiz)->ptrIzq,&ptrAux);
			free(ptrAux);
	}
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
