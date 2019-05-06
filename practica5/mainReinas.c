/*
Compilacion
gcc mainReinas.c funcReinas.c -o reinas
*/

//******Librerias
#include <stdio.h>
#include <stdlib.h>
#include "funcReinas.h"
//*****Funcion principal

 int main(){

	int tablero,th=0,fila,retorno = 0;
	int *p;
	system ("cls");
	printf("\t \t N-Reinas\n");

	// Inicio del programa
	printf("Ingrese un numero entre 4 y 10 para consutruir tablero: ");
	scanf("%d",&tablero);
	//Valida si la posicion es valida
	while (th==0){
		if (tablero>=4 && tablero<=250){
			DibujarTablero (tablero);
			th=1;
		}
		else{
			printf("Error numero fuera de limites designados, construyendo tablero 4x4\n");
			DibujarTablero(4);
			th=1;
		}

	}

	int filasReinas [tablero];
	p=&filasReinas[0];// Apuntador a arreglo donde se encuentran las reinas

	//Inicializa el arreglo de las reinas en -1 para despues comenzar desde 0
	for (th=0;th<tablero;th++){
		filasReinas[th]=-1;
	}

	retorno=0;

	//Solucion iterativa al problema de la N reinas.
	for (fila=0;fila<tablero;fila++){

		//Detecta si se estan retrocediendo pasos y elimina la reina colocada antes
		if (retorno==1){
			BorrarReina(fila,filasReinas[fila],tablero);
		}
		//Evaluar si aun se puede recorrer la reina hacia abajo
		if (filasReinas[fila]<tablero-1){
		filasReinas[fila]++;
		retorno=0; // Como no es la ultima casilla no necesita seguir retornando
		}
		//Dibuja la reina para despues ser evaluada
		DibujarReina(fila,filasReinas[fila],tablero);
		EsperarMiliSeg (tiempo);
		//Manda a evaluar si es valida la posicion de la reina
		int valido=ValidarPosicion(fila,filasReinas[fila],p,tablero);
		//Si se esta regresando, la posicion se considera invalida para no realizar el mismo paso
		if (retorno==1){
			valido=0;
		}
		//Si la posicion no es valida y aun no se llega a la ultima casilla vertical se continua recorreidno la misma fila
		if (valido==0 && filasReinas[fila]<tablero-1){
			BorrarReina (fila,filasReinas[fila],tablero);
			fila--; // Para no avanzar la posicion de las filas

		}
		//si la poscicion no es valia y se llego a la ultima posicion vertical, se borra la reina actual y la anterior,
		// y comienza el proceso de retorno evaluando la posicion anterior
		else if (filasReinas[fila]==tablero-1 && valido==0){
				BorrarReina(fila,filasReinas[fila],tablero);
				BorrarReina(fila-1,filasReinas[fila]-1,tablero);
				filasReinas[fila]=-1;
				fila=fila-2;
				retorno=1;
			}
	}

	//Impresion de la solucion
  MoverCursor(60, 2);
	printf("Solucion: ");
	printf("(");
	for (th=0;th<tablero;th++){
		printf("%i,",filasReinas[th]+1);
	}
	printf(")\n");
	return 0;
}
