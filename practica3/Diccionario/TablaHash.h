#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "TADListaSL.h"
#define VALORCADENA 13   //Es el valor-1 maximo que una cadena puede tener
#define TAM_CADENAS 50 //Tamanio de todas las cadenas usadas para el tratamiento de binario/decimal.
#define COMBALTA 13*122
#define MAX_VALOR_ASCII 255 //Guarda el maximo valor del ASCII (255).


/*
Recibe: indice(codigo), palabra, definicion, lista

Efecto: Guarda con respecto al indice asignado llamando a la funcion colisiones con respecto al codigo unico
dado por la formula cod=sumatcara%(tampalacadMax+1) que genera un dominio de [1-palacadMax]

Restricciones: Como todo se controla con un switch cada vez que nosotros queramos una cadena mas grande se debe agregar un caso mas
por ejemplo tampalacadMax=12 aqui hay 12 cases de 1-12 si nosotros quisieramos  tampalacadMax=13 deberemos agregar un caso demas.

*/

void guardaDefinicion(int indice,char* palabra,char* definicion,lista* colisiones);


/*
 Recibe: Una lista, apuntador a char una palabra y la definicion de ella
  
 Efecto: Guarda las palabras y deficiones en una lista añadiendo cada palabra
 una seguida de otra, hay que destacar que para cada palabra se genera un codigo unico
 que esta dado por la formula cod=sumatcara%(tampalacadMax+1) entre mas grande sea (palacadMax+1)
 menos colisiones habra pero las colisiones se manejan de la siguiente manera
 
 supongamos:
 
 palabra     codigo
 y              4
 457            4    (esta es una colision de palabras)
        .
        .
        .
    n           4
 No hay problema para ello ya que la lista puede solucionar este problema
 de la siguiente manera.
 
 y---->457....--->n
 
 

*/

void colision(lista* colisiones,char* palabra,char * definicion);

void menu();

/*
Recibe: una cadena y envia la suma total de caracteres

Efecto: Suma los caacteres por individual de acuerdo al valor en ascii
por ejemplo:

eugenio:
101+117+103+101+110+105+111= 748

Restricciones: como el codigo ascii cada caracter es unico cadenas como
eugenio, Eugenio, eugeNio.... son cadenas diferentes por lo que se debe tener
un orden unico ya sea Empezando solo par mayusculas o minusculas para evitar
este tipo de error.

Posible: solucion debido a que las palabras anteriormente mencionadas son subcadenas de eugenio
podemos utilizar la funcion strcmp(str1, str2)

Esta nos genera tres diferentes resultados
diferecia entre str1 y str2: -1
igualdad entre str1 y str2:   0
subcadena entre str1 y str2:  1  (creo)


*/

int sumaCaracteres(char * cadena);

/*
Recibe el numero especifico para cada palabra(posicion)
 recibe la lista.
 Efecto: Al recibir la posicion especifica de la palabra en la lista 
 utilizamos element para ir a el elemento especifico de la posicion asiganada.
 
 Restricciones: Cuando recibe un mismo caracter o palabra aumenta la posicion especifica de esa palabra.
 Aunque por el momento ese efecto no importa ya que la el aumento lo controla la misma palabra para cada 
 diferente es un aumento diferente.
palabra  pos 
 y        1
 y        2
eugenio   1
ricardo   1
Eugenio   1
*/
void BusquedaPalabra(int posicion,lista* colisiones);


void Elimina(int posicion12,lista* colision,elemento palabraEl);

