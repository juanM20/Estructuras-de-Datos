/*
LIBRERIA
Simulacion de la atencion a clientes en un supermercado, implementando el TAD Cola.
Realiza la simulacion de la llegada y atencion de las cajas a las personas, atendiendo a 
por lo menso 100 clientes.
Fecha: 01/04/2019
Version 1.0
Autores: Ayona Lopez Eugenio Milton, Benitez Morales Manuel Emilio
*/
#include "TADColaDin.h"

#define ALTO_CAJA 3 
#define ANCHO_CAJA 8
#define TIEMPO_BASE 10

/*
Pide la cantidad de cajas que hay en la tienda y
retorna el valor ingresado cuando este es correcto.
*/
int Entrada_Cajeras(int ncajas);

/*
Pide el tiempo en milisegundos de atencion a los clientes y
retorna el valor ingresado cuando este es correcto.
*/
int Entrada_Atencion(int tatencion);

/*
Pide el tiempo en milisegundos de llegada de los clientes y
retorna el valor ingresado cuando este es correcto.
*/
int Entrada_LlegadaCliente(int tllegada);

/*
Pide el numero de clientes que atenderan las cajas y
retorna esa cantidad.
*/
int N_Clientes(int nclientes);

/*
Realiza todo el proceso de la representacion del servicio de las cajas,
no devuelve valor, y recibe los enteros ingresados como tiempo de atencion, de llegada
y el numero de clientes y cajas para poder realizar el proceso.
*/
void Simulacion(int cajas, int tAtencion, int tLlegada, int nClientes);



//////////FUNCIONES PARA LA INTERFAZ

/*
Recibe el timepo en milisegundos ingresados por el usuario, y se detiene 
precisamente para realizar las operaciones pausadas.
*/
void Tiempo_Espera(int tiempo);

/*
No recibe ni devuelve valores; se encarga de limpiar la pantalla de la consola
para realizar de manera atractiva la simulacion.
*/
void Borrar_Pantalla();

/*
Se encarga de mover el cursor a las posiciones especificadas de la consola, para relizar
una atractiva simulacion.
*/
void Mover_Cursor(int x, int y); //simula el gotoxy de conio.h

/*
Realiza la escritura en pantalla de las representaciones de cajas; recibe las
posiciones en x,y y el numero de cajas en la tienda, no devulve valores.
*/
void Imprimir_Caja(int x,int y, int ncajas);

