

//******Librerias
#include <stdio.h>
#include <stdlib.h>
#include "presentacion.h"

//*****Variables estaticas

//Variables para dibujar el tablero
#define ancho 75
#define alto 50
int desH =25;
int desV =5;

//Variables para control de tiempo
#define tiempo 50

//***** Prototipos de funcion 
void DibujarTablero (int t);
void DibujarReina (int x,int y, int t);
void BorrarReina(int x,int y, int t);
int  Nreinas (int fila, int posicion, int *arregloReinas,int t);
int ValidarPosicion (int fila, int posicion, int *arregloReinas,int t);


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
	printf("Solucion: ");
	printf("(");
	for (th=0;th<tablero;th++){ 
		printf("%i,",filasReinas[th]+1);
	}
	printf(")\n");
	return 0;
}


/*
void DibujarTablero (int t)
Descripción: Dibuja un tablero de ajedrez cuadrado de n*n
Recibe: Recibe un numero entero del numero de divisiones por lado
Devuelve: void
Observaciones: El numero entero a recibir tiene que ser mayor o
igual a 1 de lo contrario ocasionara un error.
2.- Cada que se llama a la funcion hace una limpieza de la pantalla 
3.- El numero entero que recibe debe ser menor a las dimensiones 
asignadas para los limites del tablero que se asignan en
el programa en el apartado "Variables para dibujar tablero"(ancho,alto)
*/

void DibujarTablero (int t){
	int x=0,y=0,j,k,dimAlt,dimAn,modAlt,modAn;
	system ("cls");
	if (t<1 || t>alto || t>ancho){
		printf("Dimensiones fuera de los margenes de construccion\n");
		exit (1);
	}
	//Operacion designacion de espacios 
	dimAlt=alto/t;
	modAlt=alto%t;
	dimAn=ancho/t;
	modAn=ancho%t;

	//Titulo de la matriz
	MoverCursor (desH, desV/2);
	printf("Nreinas se encontraran %d reinas\n",t );

	//Dibujo de lineas horizontales
	for (y=desV;y<=(alto-modAlt)+desV;y=y+dimAlt)
		for (x=desH;x<(ancho-modAn)+desH;x++){		
			MoverCursor (x,y);
			printf("-");
		}
	//Dibujo de lineas verticales

	for (y=desV;y<(alto-modAlt)+desV;y++)
		for (x=desH;x<=(ancho-modAn)+desH;x=x+dimAn){
			MoverCursor(x,y);
			printf("|");
		}	
	printf("\n\n");

	return;
}


/*
void DibujarReina (int x,int y,int t)
Descripción: Dibuja dentro del tablero una reina con el caracter designado
Recibe: Recibe las cordenadas x,y ademas de la dimension de una lado del tablero
Devuelve: void
Observaciones: La funcion no evalua si ya se ha dibujado el tablero anteriormente
			los dezplazamientos tienen que ser iguales a los del Dibujar tablero
			La funcion no evalua si se esta dentro de los limites del tablero
*/

void DibujarReina (int x,int y,int t){
	MoverCursor (0,0);
	int dimAlt,dimAn;
	int cordX, cordY;
	//Operaciones necesarias para diviir los cuadros
	dimAlt=alto/t;
	dimAn=ancho/t;

	cordX = ((x+1)*dimAn)+desH-(dimAn/2);
	cordY = ((y+1)*dimAlt)+desV-(dimAlt/2);

	MoverCursor (cordX,cordY);
	printf("R"); //Caracter de representacion de una reina

	MoverCursor (0,desV+alto);

	return;
}


/*
void BorrarReina (int x,int y,int t)
Descripción: Imprime un espacio dentro del tablero 
Recibe: Recibe las cordenadas x,y ademas de la dimension de una lado del tablero
Devuelve: void
Observaciones: La funcion no evalua si ya se ha dibujado el tablero anteriormente
			los dezplazamientos tienen que ser iguales a los del Dibujar tablero
			La funcion no evalua si se esta dentro de los limites del tablero
*/

void BorrarReina (int x,int y,int t){
	MoverCursor (0,0);
	int dimAlt,dimAn;
	int cordX, cordY;
	dimAlt=alto/t;
	dimAn=ancho/t;

	cordX = ((x+1)*dimAn)+desH-(dimAn/2);
	cordY = ((y+1)*dimAlt)+desV-(dimAlt/2);

	MoverCursor (cordX,cordY);
	char c = ' ';
	printf("%c",c);

	MoverCursor (0,desV+alto);

	return;
}

/*
int ValidarPosicion (int fila, int posicion, int *arregloReinas,int t)
Descripción: Valida la posicion donde se asigno la reina, valida con diagonales y horizontal 
Recibe: Recibe el arreglo donde se localizan las reinas, el tamaño del arreglo para conocer 
		ademas saber que elemento del arreglo se va evaluar conociendo la fila, y el valor de dicho elemento 
Devuelve: un int, devuelve 1 si la posicion que se quiere evaluar es valida, y 0 si no es valida
Observaciones: Unicamente hace la evaluacion del las posiciones a la izquierda de la posicion a evaluar, por 
			   lo tanto omite las posiciones a la derecha
*/

int ValidarPosicion (int fila, int posicion, int *arregloReinas,int t){
	int resultado=1,aux;
	for (aux=fila-1;aux>=0;aux--){
		if (*(arregloReinas+aux)==posicion || abs(*(arregloReinas+aux)-posicion)==abs(fila-aux)){
			resultado=0; //El  resultado no es valido
			aux=0;
		}
	}

	return resultado;
}