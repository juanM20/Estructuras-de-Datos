/*
Autores:
Ayona Lopez Eugenio Milton
Benitez Morales Manuel Emilio
Tellez Perez Juan Manuel

Version 1.2 2019
*/

//*****Variables estaticas

//Variables para dibujar el tablero
#define ancho 75
#define alto 50


//Variables para control de tiempo
#define tiempo 50

//***** Prototipos de funcion
void DibujarTablero (int t);
void DibujarReina (int x,int y, int t);
void BorrarReina(int x,int y, int t);
int  Nreinas (int fila, int posicion, int *arregloReinas,int t);
int ValidarPosicion (int fila, int posicion, int *arregloReinas,int t);

//DECLARACI�N DE FUNCIONES
void MoverCursor( int x, int y ); 	//Funci�n para mover el cursor de escritura de pantalla, simulaci�n de la funci�n gotoxy() que se tenia en borland 3.0 en la libreria conio.h

void EsperarMiliSeg(int t);			//Funci�n para esperar un tiempo en milisegundos, simulaci�n de la funci�n delay() que se tenia en borland 3.0 en la libreria conio.h

void BorrarPantalla(void);			//Funci�n para borrar la pantalla de la consola, simulaci�n de la funci�n clrscr() que se tenia en borland 3.0 en la libreria conio.h
