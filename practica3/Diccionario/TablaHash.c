#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "TablaHash.h"


/*

Recibe una cadena covierte cada caracter a su valor en ascii
suma el valor ascii de cada caracter y lo guarda en suma total
luego en valor sera el indice que se usara en cadalista y enlazar
en esa lista cuando alla colisiones
determinada 0-VALORCADEDA-1
*/
int sumaCaracteres(char * cadena){
int sumatotal=0,i;

	for(i=0;i<strlen(cadena);++i){
		sumatotal+=(int) cadena[i];
	}

return sumatotal;

}


void guardaDefinicion(int indice,char* palabra,char* definicion,lista* colisiones){

	switch(indice){
	case 1:
	 colision(colisiones,palabra,definicion);
	break;

	case 2:
	 colision(colisiones,palabra,definicion);
	break;

	case 3:
	 colision(colisiones,palabra,definicion);
	break;

	case 4:
	    colision(colisiones,palabra,definicion);
	break;
	case 5:
	  colision(colisiones,palabra,definicion);
	break;
	case 6:
	 colision(colisiones,palabra,definicion);
	break;
	case 7:
	 colision(colisiones,palabra,definicion);
	break;
	case 8:
		 colision(colisiones,palabra,definicion);
	break;
	case 9:
		 colision(colisiones,palabra,definicion);
	break;
	case 10:
		 colision(colisiones,palabra,definicion);
	break;
	case 11:
		 colision(colisiones,palabra,definicion);
	break;
	case 12:
		 colision(colisiones,palabra,definicion);
	break;
	case 13:
		 colision(colisiones,palabra,definicion);
	break;
	case 14:
		 colision(colisiones,palabra,definicion);
	break;
	case 15:
		 colision(colisiones,palabra,definicion);
	break;
	case 16:
		 colision(colisiones,palabra,definicion);
	break;
	case 17:
		 colision(colisiones,palabra,definicion);
	break;
	case 18:
		 colision(colisiones,palabra,definicion);
	break;
	case 19:
		 colision(colisiones,palabra,definicion);
	break;
	case 20:
		 colision(colisiones,palabra,definicion);
	break;
	case 21:
		 colision(colisiones,palabra,definicion);
	break;
	case 22:
		 colision(colisiones,palabra,definicion);
	break;
	case 23:
		 colision(colisiones,palabra,definicion);
	break;
	case 24:
		 colision(colisiones,palabra,definicion);
	break;
	case 25:
		 colision(colisiones,palabra,definicion);
	break;
	}
}

void colision(lista* colisiones,char* palabra,char * definicion){
	 elemento datos;
	 strcpy (datos.p,palabra);
	 strcpy (datos.d,definicion);
	 Add(colisiones,datos);
}

void menu(){

	printf("1.- Cargar un archivo de definiciones\n"
				 "2.- Agregar una palabra y su definici�n\n"
				 "3.- Buscar una palabra y ver su definici�n\n"
				 "4.- Modificar una definici�n\n"
				 "5.- Eliminar una palabra\n"
				 "6.- Salir\n");
}


void BusquedaPalabra(int posicion, lista* colisiones){
	printf("%s: %s\n",Element(colisiones,posicion).p, Element(colisiones,posicion).d);
}


void Elimina(int posicion12,lista* colision,elemento palabraEl){
	posicion eliminaDato= ElementPosition(colision,posicion12);
	Remove(colision,eliminaDato);
	printf("Palabra elimina con exito\n");
}
