/*Simulacion de la atencion de personas en un banco implementando el TAD Cola.
Realiza la simulacion de la atencion de personas con prioridades en una 
institucion bancaria.
Fecha: 01/04/2019
Version 1.1
Autores: Ayona Lopez Eugenio Milton,Emilio ,Juan*/
//LIBRERIAS
#include<stdio.h>
#include "TADColaEst.h"
//CONSTANTES
#define TIEMPO_BASE	100
#include "presentacion.h"
void GraficarCajas(int numero_cajeros);
//PROGRAMA PRINCIPAL
int main(void)
{
	int tiempo_cajeros,numero_cajeros;
	int tiempo_clientes;		//tiempo de llegada de los clientes 
	int tiempo_usuarios;		//tiempo de llegada de los usuarios 
	int tiempo_clipref;			//tiempo de llegada de los clientes preferentes
	int columna,aux;
	int tam_cola;
	int i,j;
	int cont_clientes, cont_usuarios, cont_clipref;
	int carga=0,estado=0; 
	int cliente=0,usuario=0,clienteP=0;
	
	int ClienteCola=0, UsuarioCola=0,Pcola=0;
	cola Clientes, Usuarios, ClientesP;
	elemento e;
	
	Initialize(&Clientes);
	Initialize(&Usuarios);
	Initialize(&ClientesP);
	unsigned int tiempo = 0;
	BorrarPantalla();
	printf("\nIngrese el numero de cajeros: ");
	scanf("%d",&numero_cajeros);
	
	
	
	//Verifica que los cajeros sean menor que 10
	while(numero_cajeros<=0||numero_cajeros>10)
	{
		BorrarPantalla();
		printf("\nNumero Incorrecto, ingrese otro:");
		scanf("%d",&numero_cajeros);
	}
	printf("\nTiempo de atencion en cajas:");
	scanf("%d",&tiempo_cajeros);	
	printf("\nTiempo de llegada de clientes:");
	scanf("%d",&tiempo_clientes);
	printf("\nTiempo de llegada de los usuarios:");
	scanf("%d",&tiempo_usuarios);
	printf("\nTiempo de llegada de los usuarios preferentes:");
	scanf("%d",&tiempo_clipref);
	BorrarPantalla();
	//Graficacion de los cajeros
	GraficarCajas(numero_cajeros);
	//Formacion de los clientes en la cola
	while(1)
	{
		EsperarMiliSeg(TIEMPO_BASE);
	
		tiempo++; //Aumenta el tiempo  del reloj del banco
		
		
		
		//Si corresponde al tiempo de llegada de un cliente
		if(tiempo%tiempo_clientes==0)
		{   
		    ++ClienteCola;
			cliente++;
			//Encolando a un cliente
			e.n=cliente;
			Queue(&Clientes, e);
		}
		//Si corresponde al tiempo de llegada de un Usuario
		if(tiempo%tiempo_usuarios==0)
		{ 
		    ++UsuarioCola;
			usuario++;
			//Encolando a un usuario
			e.n=usuario;		
			Queue(&Usuarios, e);
		}
		//Si corresponde al tiempo de llegada de un cliente preferente
		if(tiempo%tiempo_clipref==0)
		{   
		   ++Pcola;
			clienteP++;
			//Encolando a un clientepref
			e.n=clienteP;		
			Queue(&ClientesP, e);
		}			

		//ATENCION DE LAS PERSONAS FORMADAS
		
		/*
		 Cuando el tiempo es igual al asignado en tiempo_cajero 
		 Significa que la  disponibilidad de los cajeros esta disponible
		*/
		if(tiempo%tiempo_cajeros==0)
		{
		   GraficarCajas(numero_cajeros);
			//Clientes y C.preferentes que han pasado
			for(i=0;i<numero_cajeros;i++)
				carga=0;	//se usa para contar los clientesP y normales que han pasado por los cajeros
                            //Cuando llega a cinco tiene que permitirle  la entrada a un usuario del cliente
					
			for(j=0;j<numero_cajeros;j++)
			{
		
				estado=0;
				if(!Empty(&ClientesP))       //como la politica del banco dice que los clientes Preferenciales se atienden en cualquier momento
				{           
				   //printf("Cliente: %d  Usuario: %d  Cliente Prefe: %d",ClienteCola,UsuarioCola,Pcola);	
                                  
					e=Dequeue(&ClientesP);
					MoverCursor(36,13);
					printf("P%d",e.n);
					estado=1;
					++carga;
				//	getch();
                   // BorrarPantalla(); 
				}
				if(!Empty(&Clientes)&&estado==0)
				{   
				    printf("Cliente: %d  Usuario: %d  Cliente Prefe: %d",ClienteCola,UsuarioCola,Pcola);	
					e=Dequeue(&Clientes);
					MoverCursor(6,13);
					printf("C%d",e.n);
					estado=1;
					++carga;
				}
				if(!Empty(&Usuarios) && estado==0 &&carga>5 )
				{
					e=Dequeue(&Usuarios);
					MoverCursor(21,13);
					printf("U%d",e.n);
					estado=1;
					carga=0;
				}

			}
		}
		
		
		    
	}
}
/*
void GraficarCajas(int numero_cajeros)
Descripcion: Funcion para graficar las cajas para las filas del banco
Recibe: Un entero int numero_cajeros que corresponden al numero de cajas que se van a generar para la atencion
Observaciones: El numero deba estar contenido entre 0<numero_cajeros<11
*/
void GraficarCajas(int numero_cajeros)
{
	int j,i,k=0,columna,aux;
	//Dibujar caja a caja	
	for(j=0;j<numero_cajeros;j++) 	
	{
		//Auxiliar para recorrer las posicion en x en la consola
		columna=(j*9)+3+k;
		aux=columna;
		//Espacios entre cajas
		k=k+3;
		//Dibujando la parte superior de las cajas
		while(columna<=aux+8)		
		{
			MoverCursor(columna,3);
			printf("-");
			columna++;
		}
		columna--;
		//Especificamente se establece i=4 para la posicion en Y y variacion de la misma sin cambiar en X
		i=4;
		//Dibujando la parte derecha de las cajas
		while(i<=8)				
		{
			MoverCursor(columna,i);
			printf("-");
			i++;
		}
		i--;//Colocacion correcta del cursor dentro del borde de la caja
		//Dibujando la parte inferior de las cajas
		while(columna>=aux)		
		{
			MoverCursor(columna,i);
			printf("-");
			columna--;
		}
		columna++;//Colocacion correcta del cursor dentro del borde de la caja
		//Dibujando la parte izquierda de las cajas
		while(i!=3)		
		{
			MoverCursor(columna,i);
			printf("-");
			i--;
		}
		//Nombre y numero de cada caja
		MoverCursor(aux+1,4);			
		printf("CAJA %d",j+1);
	}
	MoverCursor(3,20);
	printf("CLIENTES");
	MoverCursor(18,20);
	printf("USUARIOS");
	MoverCursor(33,20);
	printf("CLIENTES");
	MoverCursor(32,21);
	printf("PREFERENTES");
	MoverCursor(12,23);
	printf("PERSONAS ATENDIDAS");
}
