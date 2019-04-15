// Practica 2.2 Admisnistrador de precesos de una computadora monoproceso

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "TADColaEst.h"
//#include "TADColaDin.h"
#include <windows.h>
#define T 1000
//#define T 1

void Ingresar_datos(cola *proc, int n);
void Imprimir_cola(cola *proc);
void Procesador(cola *proc, cola *fin);
void Imprimir_Proceso(elemento *i,cola *j);
int main(void)
{
	// Variable e inicializacion de colas
	cola procesos;
	cola finalizados;
	Initialize (&procesos);
	Initialize (&finalizados);
	elemento p,f;
	int np;
	cola *ColaP;
	cola *ColaF;
	ColaP = &procesos;
	ColaF = &finalizados;
	
	printf("Ingrese el numero de procesos a ejecutar:  "); //Solicitud inicial del numero de procesos a ejecutar
	scanf("%d",&np); 	// almacena el numero de procesos a ejecutar
	Ingresar_datos(ColaP,np);		//Llama a funcion para ingresar datos de los procesos
	Procesador(ColaP, ColaF);	//Llama a funcion para ejecutar procesos
	Imprimir_cola(ColaF);		//Llama a funcion para imprimir la lista de procesos finalizados
	return 0;
}


//Funcion para recibir los datos principales del proceso 
/*
void Ingresar_datos(cola *proc, int n);
Descripción: Ingresa los datos requerido para el funcionamiento de cada elemento
Recibe: cola *proc (Ya inicializada, cola de procesos) y int n (La cantidad de procesos que se van a ejecutar)
Devuelve:
Observaciones: El usuario a creado una cola y proc tiene la referencia a ella, 
si esto no ha pasado se ocasionara un error.
*/
void Ingresar_datos(cola *proc, int n){
	elemento p;
	int x;
	char nombre[45];
	char actividad[200];
	char id[45];
	int tiempo;

	for (x=0;x<n;x++){
		printf("Ingrese datos del proceso %d \n",x+1 );
		printf("\nIngrese nombre del proceso: ");
		scanf ("%s",p.nombre);
		printf("Ingrese actividad del proceso: ");
		fflush (stdin);
		gets(p.actividad); // Inseguro 
		//scanf("%s", p.actividad); //Funciona con Linux pero no guarda espacios
		//fgets(p.actividad,200,stdin); //
		//scanf("%[!\n]",p.actividad);	//No funciona ni linux ni windows
		fflush (stdin);
		printf("\nIngrese id del proceso: ");
		scanf ("%s",p.id);
		printf("\nIngrese tiempo requerido del proceso: ");
		scanf ("%d",&p.tiempo);
		p.tiempoEnProceso=0;
		Queue(proc,p);
		printf("\n \n ");

	}
return ;
}


//Funcion que realiza el trabajo de un nucleo del procesador  
/*
void Procesador(cola *proc,cola *fin);
Descripción: Realiza el trabajo de proceso de los elementos, a traves de 2 colas, de finalizado y procesos 
Recibe: cola *proc (Ya inicializada, cola de procesos) y cola *fin (Ya inicializada, cola de procesos finalizados)
Devuelve:
Observaciones: No administra prioridades, y una vez que inicia el procesamiento no se puede incluir otro proceso
*/
void Procesador(cola *proc,cola *fin){
	elemento i,o;
	elemento *aux;
	aux=&i;
	while (Empty(proc)!=TRUE){
		i=Dequeue(proc);
		Imprimir_Proceso (aux,proc);
		Sleep(T);
		i.tiempo--;
		i.tiempoEnProceso++;
		if (i.tiempo>0){
			i.tiempoEnProceso=i.tiempoEnProceso+Size(proc);
			Queue(proc,i);

		}
		else {
			Queue(fin,i);
		}
	}	
return ;	
}


//Funcion que realiza la impresion del trabajo del procesador   
/*
void Imprimir_Proceso(elemento *i,cola *j);
Descripción: imprime en pantalla el proceso anterior ejecutado, el siguiente y el actual
Recibe: cola *j (Ya inicializada, cola de procesos) y elemento *i (Elemento extraido del proceso actual)
Devuelve:
Observaciones: Recibe la cola de procesos para obtener los procesos siguientes y anterior
				para trabajar con linux se requiere modificar lineas de clear 
*/
void Imprimir_Proceso(elemento *i,cola *j){
	//system("clear");	//Para uso en Linux    CLEAR
	system("cls");  //Para uso de Windows
	elemento s,a;
	s=Front(j);
	a=Final(j);
	printf("\tUltimo procesado:\n");
	printf("Nombre:\t%s\tID:\t%s\tTiempo restante:\t%i\n",a.nombre,a.id,a.tiempo);
	printf("\n\n");
	printf("\tProcesado:\n");
	printf("Nombre:\t%s",i->nombre);
	printf("\nActivad:\t");
	puts (i->actividad);
	printf("ID:\t %s",i->id);
	printf("\nTiempo en proceso:\t %d",i->tiempoEnProceso);
	printf("\n");
	printf("\n\n");
	printf("\tSiguiente a procesar:\n");
	printf("Nombre:\t%s\tID:\t%s\tTiempo restante:\t%i\n",s.nombre,s.id,s.tiempo);
return ;	
}


//Funcion que imprime los procesos finalizados   
/*
void Imprimir_cola(cola *fin);
Descripción: imprime en pantalla los procesos finalizados y el orden con el que terminaron y el tiempo requerido
Recibe: cola *fin (Ya inicializada, cola de procesos finalizados) 
Devuelve:
Observaciones: para trabajar con linux se requiere modificar lineas de clear 
*/
void Imprimir_cola(cola *fin){
	elemento f;
	//system("clear");	//Para uso en Linux   Clear
	system("cls");  //Para uso de Windows
	while (Empty(fin)!=TRUE){
		f=Dequeue (fin);
		printf("Nombre de proceso\t %s \n",(f.nombre));
		printf("Actividad del proceso:\t");
		puts(f.actividad);
		printf("ID del proceso\t %s\n",f.id);
		//printf("Tiempo de proceso %i \n",(f.tiempo));
		printf("Proceso finalizado en:\t %i\n",f.tiempoEnProceso);
		printf("***********Finalizado\n\n");
	}
return ;
}
