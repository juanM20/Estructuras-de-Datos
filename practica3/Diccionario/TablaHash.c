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

	int sumatotal=0,i=0;

	while(cadena[i] != '\0'){
		sumatotal+=(int) cadena[i];
		i++;
	}


return sumatotal;

}

void colision(lista* colisiones,char* palabra,char * definicion, int indice){
	 elemento datos;
	 strcpy (datos.p,palabra);
	 strcpy (datos.d,definicion);
	 Add(&colisiones[indice],datos);
}

void guardaDefinicion(int indice,char* palabra,char* definicion,lista* colisiones){

	if(indice > 0 && indice < VALORCADENA){
		colision(&colisiones[indice],palabra,definicion, indice);
	}
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
