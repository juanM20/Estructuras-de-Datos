/*
//NUEVO PUSH
LIBRERIA: Cabecera de la Biblioteca de funciones específicas para la Practica
AUTORES:
Ayona Lopez Eugenio Milton
BenÃ­tez Morales Manuel Emilio
Tellez Perez Juan Manuel

Febrero 2019
VERSIÃ“N: 1.0

DESCRIPCIÃ“N: Herramientas usadas en el programa.
Lista de funciones:
Cada una de las funciones que aquí se declaran, cumplen un objetivo
especifico en la implemetnacion, para poder llevar a cabo operaciones
separadas de manera correcta.

OBSERVACIONES: Esta libreria utiliza a TADPila Est o Din, y es la presente,
que se importa en el archivo principal.
*/

#include "TADPilaEst.h"

#define TAM 100
#define TAM_CADENA_LITERALES 55
#define LIM_INFERIOR 65
#define LIM_SUPERIOR 90

//Muestra el menu para que el usuario interactua con el programa
void Menu();

/*
Validacion de parentesis:
Recibe una cadena y devuelve TRUE si los parentesis
son correctos, y FALSE si no lo son.
*/
boolean Validar_Parentesis(char *cad);

/*
Correcion de la expresion ingresada:
Recibe la cadena que acaba de entrar el usuario,
no devuelve valor, pero modifica la cadena a una nueva que sea entrada.
*/
void Corregir_Expresion(char *cad);   //simon, tú eres el que hace el push, yo sólo edito XD
                                      //ve comentando el codigo y arreglandolo, ahorita que acabe el algoritmo, corregimos el error
/*
Convertir la Expresion de infija a posfija:
Recibe...
 -la direccion de cadena que se quiere convertir.
 -la variable que verifica si esta validada la expresion dada.
 -la direccion de la cadena donde se escribira la conversion de infija a posfija.
 Devuelve...
 -Nada.
*/
boolean  Pasar_Posfijo(char *cad, boolean v, char *cad_posfija);

/*
Recibe la cadena postfija y devuelve el valor de
la evaluaciÃ³n.
Primero pide los valores de las literales por medio de Obtener_Valores.
*/
//float Evaluar_Expresion(char *cad_posfija);

/*
Recibe los dos valores desempilados a operador,
y su respectivo operador, para devolver su valor
y regresarlo a la pila posteriorente en Evaluar_Expresion.
*/

void Obtener_Valores();

void No_Repite(char* cadena,int tam,char* resultado);

/*
Elimina el contenido de todos los arreglos usados a lo largo del programa,
para poder analizar una nueva expresiÃ³nd e manera correcta.
*/
//void Vaciar_Arreglos(char *cad, char *cad_posfija, char *literalesDeExpresion, int *valoresDeLiterales, char *auxiliarAntiRepeticion);

void Evaluar_Expresion(char *cad_posfija, float* valoresDeLiterales);
