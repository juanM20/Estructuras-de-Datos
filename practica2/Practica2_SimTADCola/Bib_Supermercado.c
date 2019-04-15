/*
IMPLEMENTACION
Simulacion de la atencion a clientes en un supermercado, implementando el TAD Cola.
Realiza la simulacion de la llegada y atencion de las cajas a las personas, atendiendo a 
por lo menso 100 clientes.
Fecha: 01/04/2019
Version 1.0
Autores: Ayona Lopez Eugenio Milton, Benitez Morales Manuel Emilio
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Bib_Supermercado.h"

int Entrada_Cajeras(int ncajas)
{
	printf("Cajas en esta tienda: ");
	scanf("%d", &ncajas);
	
	if(ncajas<=0 || ncajas>=11)
	{
		printf("Debes poner una cantidad de cajas mayor que 0 y menor que 11.\n");
		ncajas=-1;//ayuda a la condicion en el main
	}
	
	return ncajas;
}

int Entrada_Atencion(int tatencion)
{
	printf("Tiempo de atencion (ms): ");
	scanf("%d", &tatencion);
	
	if(tatencion%10!=0)
	{
		printf("El tiempo de atencion de la caja debe ser multiplo de 10.\n");
		tatencion=-1;//ayuda a la condicion en el main
	}
	
	return tatencion;
}

int Entrada_LlegadaCliente(int tllegada)
{
	printf("Tiempo de llegada de los clientes (ms): ");
	scanf("%d", &tllegada);
	
	if(tllegada%10!=0)
	{
		printf("El tiempo de llegada de los clientes debe ser multiplo de 10.\n");
		tllegada=-1;//ayuda a la condicion en el main
	}
	
	return tllegada;
}

int N_Clientes(int nclientes)
{
	printf("Numero de clientes a atender: ");
	scanf("%d", &nclientes);
	
	if(nclientes<100)
	{
		printf("Debe haber al menos 100 clientes.\n");
		nclientes=-1;//ayuda a la condicion en el main
	}
	
	return nclientes;
}

void Simulacion(int cajas, int tAtencion, int tLlegada, int nClientes)
{
	int i, o, clientes_restantes=nClientes, numCaja, tamFila, formar, contador_clientes=0;
	int tiempo=0, cliente=0; //Tiempo de base para la espera y la llegada, cliente atendido
	cola filaParaCobrar;
	cola filaDeCaja[cajas]; //arreglo de colas, porque en un super hay varias filas	
	elemento e;
	
	Borrar_Pantalla();
	
	printf("SuperESCOM\n\n");
	printf("Tiempo de atencion en cada caja: %d ms\n", tAtencion);
	printf("Tiempo de llegada de clientes: %d ms\n\n\n", tLlegada);
	printf("Clientes restantes: %d", clientes_restantes);
	
	//Se inician todas las colas
	for(i=0;i<cajas;i++)
	{
		Initialize(&filaDeCaja[i]);  
	}
	
	for(i=0; i<cajas; i++)
	{
		Imprimir_Caja((i*10)+1, 8, cajas);
	}
	
	Tiempo_Espera(TIEMPO_BASE);
	
	do
	{
		tiempo++; 
		Tiempo_Espera(TIEMPO_BASE);
		if(tiempo%tLlegada==0)
		{
			clientes_restantes--; //un cliente menos que atender
			cliente++;
			numCaja= rand()%cajas; //Se selecciona una caja al azar
			e.n= cliente;
			Queue(&filaDeCaja[numCaja], e); //encolar al nuevo cliente
			
			for(i=0; i<cajas; i++) //se recorren las cajas
			{
				tamFila= Size(&filaDeCaja[i]); //hay que saber cuantos hay formados
				formar= (5*(i+1) + 6*i - i)-1;//Moviendo el cursorsobre x para formar al cliente
				
				for(o=1; o<=tamFila; o++) //se recorren los clientes formados
				{
					if(o==1)
					{
						e= Element(&filaDeCaja[i], o);
						Mover_Cursor(formar,12);
						printf("*", e.n);
						//Imprime el numero de clientes en espera a ser atendidos
						Mover_Cursor(formar-4,7);
						printf("Fila:%d", tamFila);
						Mover_Cursor(formar,11);
					}
					else
					{
						e=Element(&filaDeCaja[i], o);
						Mover_Cursor(formar, o+12);
						printf("*", e.n);
						//Imprime el numero de clientes en espera a ser atendidos
						Mover_Cursor(formar-4,7);
						printf("Fila:%d", tamFila);
						Mover_Cursor(formar, o+11);
					}
				}
			}
		}
		//Rectifica el tiempo de cada una de las colas
		for(i=0; i<cajas; i++)
		{
			if(tiempo%tAtencion==0)
			{
				//Si hay alguien por atender
				if (!Empty(&filaDeCaja[i]))
				{ 
					e=Dequeue(&filaDeCaja[i]);
					//Aumenta el Numero de clientes atendidos
					contador_clientes++; 
				}
				//Si la cola esta vacia(no hay clientes formados)
				else
				{
					formar=(5*(i+1) + 6*i - i)-1;
					Mover_Cursor(formar, 12);
					//Si la caja esta vacia, imprime "-"
					printf("-"); 
				}
			}
		}
		
	}while(clientes_restantes>0 || (tamFila!=0 && contador_clientes>=100));
	
	printf("\n\nTIENDA CERRADA\n");
	printf("Atendidos: %d clientes", contador_clientes);
	
	return;
}


//////////FUNCIONES PARA LA INTERFAZ

void Tiempo_Espera(int tiempo)
{
	Sleep(tiempo);//tiempo en milisegundos
	return;
}

void Borrar_Pantalla()
{
	system("cls");
	return;
}

void Mover_Cursor(int x, int y) //simula el gotoxy de conio.h
{
	HANDLE salida = GetStdHandle(STD_OUTPUT_HANDLE); //"objeto" de la "clase" handle
	COORD posicion = {x, y}; 
	SetConsoleCursorPosition(salida, posicion);
	return;
}

void Imprimir_Caja(int x,int y, int ncajas)
{	
	int fila,columna,i;
	int aux=x; 	//Guarda la posicion del cursor
	for(fila=1; fila<=ALTO_CAJA; fila++)
	{	
		x=aux; 	
		
		for(columna=1; columna<=ANCHO_CAJA; columna++)
		{
			Mover_Cursor(x,y);	//Se posiciona en una coordenada especificada
			if(y==9 && columna>1 && columna<10)
			{
				for(i=0; i<ncajas; i++)
				{
					if(x==(i*10)+2 && i<15)
					{
						printf("Caja #%d", i+1);
						x=x+5;
						columna=columna+8;
					}
					if(x==(i*10)+2 && i>=15)
					{
						printf("Caja #%d", i+1);
						x=x+5;
						columna=columna+9;
					}
				}
			}
			else
			printf("|");	//Margen de la caja
			Tiempo_Espera(TIEMPO_BASE);
			x++;	//Aumentando la posicion en la consola en el eje x
		}
		y++;	//Aumentando la posicion en la consola en el eje y
	}
}
