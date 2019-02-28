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
void Corregir_Expresion(char *cad);

/*
Convertir la Expresion de infija a posfija:
Recibe...
 -la direccion de cadena que se quiere convertir.
 -la variable que verifica si esta validada la expresion dada.
 -la direccion de la cadena donde se escribira la conversion de infija a posfija.
 Devuelve...
 -Nada.
*/
void Pasar_Posfijo(char *cad, boolean v, char *cad_posfija);

/*
Recibe la cadena postfija y devuelve el valor de
la evaluación.
Primero pide los valores de las literales por medio de Obtener_Valores.
*/
int Evaluar_Expresion(char *cad_posfija);

/*
Se ayuda de No_Repite, para pedir los valores de la literales una sola vez.
Recibe la cadena de Evaluar_Expresion, no devuelve valores.
*/
void Obtener_Valores(char *cad_posfija);

/*
primer argumeto es el arreglo de solo literales, el segundo el tamaño del
arreglo literales y el tercero es en donde se guardar el arreglo sin repeticion,
el arreglo sin repeticiones se modifica por referencia por lo tanto no nesecita enviar nada
*/
void No_Repite(char *cadena,int tam,char *resultado);

/*
Elimina el contenido de todos los arreglos usados a lo largo del programa,
para poder analizar una nueva expresiónd e manera correcta.
*/
void Vaciar_Arreglos(char *cad, char *cad_posfija, char *literalesDeExpresion, int *valoresDeLiterales, char *auxiliarAntiRepeticion);
