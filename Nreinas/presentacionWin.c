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
Dibuja el tablero nxn, donde n es el numero entero que recibe de parametro
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
Dibuja simbolicamente uan reian en elt tablero
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
Borrra un reina cuando el algoritmo se da cuenta que un determinado camino
para llegar a la solucion no es valido
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
Valida la posicion donde se asigno la reina, valida con diagonales y horizontal
Recibe: Recibe el arreglo de las reinas, el tamaño del arreglo para conocer
ademas saber que elemento del arreglo se va evaluar conociendo la fila, y el valor de dicho elemento
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
