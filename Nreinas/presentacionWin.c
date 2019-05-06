/*
Autores:
Ayona Lopez Eugenio Milton
Benitez Morales Manuel Emilio
Tellez Perez Juan Manuel

Version 1.2 2019
*/
//LIBRERIAS
#include <windows.h>
#include"presentacion.h"
int desH =25;
int desV =5;
//DEFINICI�N DE FUNCIONES

//Funci�n para mover el cursor de escritura de pantalla, simulaci�n de la funci�n gotoxy() que se tenia en borland 3.0 en la libreria conio.h
void MoverCursor( int x, int y )
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = { x, y };
	SetConsoleCursorPosition( hStdout, position );
	return;
};

//Funci�n para esperar un tiempo en milisegundos, simulaci�n de la funci�n delay() que se tenia en borland 3.0 en la libreria conio.h
void EsperarMiliSeg(int t)
{
	Sleep(t);
	return;
}

//Funci�n para borrar la pantalla de la consola, simulaci�n de la funci�n clrscr() que se tenia en borland 3.0 en la libreria conio.h
void BorrarPantalla(void)
{
	system("cls");
	return;
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
