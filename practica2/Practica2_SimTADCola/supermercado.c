/*
PROGRAMA PRINCIPAL
Modo de compilación: gcc supermercado.c TADCola(Din)(Est).c Bib_Supermercado.c -o archivo_ejecutable
Fecha: 01/04/2019
Version 1.0
Autores: Ayona Lopez Eugenio Milton, Benitez Morales Manuel Emilio
*/

#include <stdio.h>
#include "Bib_Supermercado.h"

int main()
{
	int n_cajeras, t_atencion, t_llegada, n_clientes;
	
	Borrar_Pantalla();
	
	printf("SuperESCOM\n\n");
	
	do
	{
		//Pide los datos hasta que todo sea correcto
		n_cajeras= Entrada_Cajeras(n_cajeras);
		t_atencion= Entrada_Atencion(t_atencion);
		t_llegada= Entrada_LlegadaCliente(t_llegada);
		n_clientes= N_Clientes(n_clientes);
		
		//Y sia lgo no es correcto, entonces pide precisamente que se ingresen de nuevo
		if(n_cajeras==-1 || t_atencion==-1 || t_llegada==-1 || n_clientes==-1)
		{
			printf("\n\n\nVuelva a ingresar los datos, alguno de ellos sale de la especificacion!!!\n\n\n");
		}
	}while(n_cajeras==-1 || t_atencion==-1 || t_llegada==-1 || n_clientes==-1);
	
	printf("\n\nTIENDA ABIERTA\n\n");
	
	Simulacion(n_cajeras, t_atencion, t_llegada, n_clientes);
	
	return 0;
}
	
	
