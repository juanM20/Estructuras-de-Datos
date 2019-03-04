/*
IMPLEMENTACIÃ“N DE LA LIBRERIA DEL TAD PILA ESTÃTICA (TADPilaEst.h)
AUTORES: //orden alfabÃ©tico
BenÃ­tez Morales Manuel Emilio

Febrero 2019
VERSIÃ“N: 1.0

DESCRIPCIÃ“N: TAD pila o stack.
Estructura de datos que cumple:
Los elementos se aÃ±aden y se remueven por un solo extremo.
Este extremo es llamado â€œtopeâ€ de la pila.

OBSERVACIONES: Estructura de datos estÃ¡tica, ya que se
asigna una cantidad fija de memoria para dicha estructura,
antes de la ejecuciÃ³n del programa.

COMPILACIÃ“N PARA GENERAR EL CÃ“DIGO OBJETO: gcc TADPilaEst.c -c
*/

//LIBRERAS
#include<stdio.h>
#include<stdlib.h>
#include "TADPilaEst.h"

//DEFINICIÃ“N DE FUNCIONES

/*
void Initialize(pila *s);
DescripciÃ³n: Inicializar pila (Iniciar una pila para su uso)
Recibe: pila *s (Referencia a la pila "s" a operar)
Devuelve:
Observaciones: El usuario a creado una pila y s tiene la referencia a ella,
si esto no ha pasado se ocasionara un error.
*/
void Initialize(pila *s)
{
	(*s).tope=-1; //s->tope=-1;
	return;
}

/*
void Push(pila *s, elemento e);
DescripciÃ³n: Empilar (Introducir un elemento a la pila)
Recibe: pila *s (Referencia a la pila "s" a operar), elemento e (Elemento a introducir en la pila)
Devuelve:
Observaciones: El usuario a creado una pila y s tiene la referencia a ella, s ya ha sido inicializada.
Ademas no se valida el indice del arreglo (tope) esta fuera del arreglo es decir hay desbordamiento
y se causarÃ¡ en error.
*/
void Push(pila *s, elemento e)
{
	s->tope++;

	//Si el tope alcanzo a MAX_ELEMENT, ya no hay mÃ¡s espacio para elementos en el arreglo
	if(s->tope==MAX_ELEMENT)
	{
		printf("\nERROR: PUSH(*S, E) DESBORDAMIENTO, NO MÃS ESPACIO EN LA PILA");
		exit(1);
	}

	//Insertar el elemento si no hubo error
	s->arreglo[s->tope]=e;
	return;
}

/*
elemento Pop(pila *s);
DescripciÃ³n: Desempilar (Extraer un elemento de la pila)
Recibe: pila *s (Referencia a la pila "s" a operar)
Devuelve: elemento (Elemento e extraido de la pila)
Observaciones: El usuario a creado una pila y s tiene la referencia a ella, s ya ha sido inicializada.
Ademas no se valida si la pila esta vacia (tope == -1) antes de desempilar (causa error desempilar si esta esta vacÃ­a)
*/
elemento Pop (pila *s)
{
	elemento r;

	//Si el tope es -1, se intenta Pop de pila vacia
	if(s->tope==-1)
	{
		printf("\nERROR POP(*S): SUBDESBORDAMIENTO, NO HAY ELEMENTOS EN LA PILA");
		exit(1);
	}

	//Si no hubo error retornar el elemento indexado por tope
	r=s->arreglo[s->tope];
	s->tope--;
	return r;
}

/*
boolean Empy(pila *s);
DescripciÃ³n: //Vacia (Preguntar si la pila esta vacia)
Recibe: pila *s (Referencia a la pila "s" a operar)
Devuelve: boolean (TRUE o FALSE segÃºn sea el caso)
Observaciones: El usuario a creado una pila y s tiene la referencia a ella, s ya ha sido inicializada.
*/
boolean Empty(pila *s)
{
	boolean r;
	if(s->tope==-1)
	{
		r= TRUE;
	}
	else
	{
		r= FALSE;
	}
	return r;
}

/*
elemento Top(pila *s);
DescripciÃ³n: Tope (Obtener el "elemento" del tope de la pila si extraerlo de la pila)
Recibe: pila *s (Referencia a la pila "s" a operar)
Devuelve: elemento (Elemento del tope de la pila)
Observaciones: El usuario a creado una pila y s tiene la referencia a ella, s ya ha sido inicializada.
Ademas no se valida si la pila esta vacia antes de consultar al elemento del tope (causa error si esta esta vacÃ­a).
*/
elemento Top(pila *s)
{
	//Si el tope es -1, se intenta Pop de pila vacia
	if(s->tope==-1)
	{
		printf("\nERROR TOP(*S): SUBDESBORDAMIENTO, NO HAY ELEMENTOS EN LA PILA");
		exit(1);
	}

	//Si no hubo error retornar el elemento indexado por tope
	return s->arreglo[s->tope];
}

/*
int Size(pila *s);
DescripciÃ³n: TamaÃ±o de la pila (Obtener el nÃºmero de elementos en la pila)
Recibe: pila *s (Referencia a la pila "s" a operar)
Devuelve: int (TamaÃ±o de la pila -1->Vacia, 1->1 elemento, 2->2 elementos, ...)
Observaciones: El usuario a creado una pila y s tiene la referencia a ella, s ya ha sido inicializada.
*/
int Size(pila *s)
{
	return s->tope+1;
}

/*
void Destroy(pila *s);
DescripciÃ³n: Elimina pila (Borra a todos los elementos en a la pila de memoria* Memoria estÃ¡tica (No se puede eleminar realmente)
Recibe: pila *s (Referencia a la pila "s" a operar)
Devuelve:
Observaciones: El usuario a creado una pila y s tiene la referencia a ella.
*/
void Destroy(pila *s)
{
	//s->tope=-1;
	Initialize(s);
	return;
}
