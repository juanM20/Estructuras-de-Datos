
//Definir un elemento (Se modela con una estructura "elemento")
typedef struct elemento
{
	//Variables de la estructura "elemento" (El usuario puede modificar)
	char c;
   float valor;
	//***
	//***
	//***
}elemento;

//Definir una pila (Se modela con una estructura que unicamente incluye un puntero a "elemento")
typedef struct pila
{
	elemento arreglo[MAX_ELEMENT];		//La pila es un arreglo estÃ¡tico de MAX_ELEMET
	int tope; 							//El tope es un entero (Indice del arreglo de elementos)
}pila;


//DECLARACIÃ“N DE FUNCIONES DE PILA

//Inicializar pila (Iniciar una pila para su uso)
void Initialize(pila *s);

//Empilar (Introducir un elemento a la pila)
void Push(pila *s, elemento e);

//Desempilar (Extraer un elemento de la pila)
elemento Pop (pila *s);

//Vacia (Preguntar si la pila esta vacia)
boolean Empty(pila *s);

//Tope (Obtener el "elemento" del tope de la pila si extraerlo de la pila)
elemento Top(pila *s);

//TamaÃ±o de la pila (Obtener el nÃºmero de elementos en la pila)
int Size(pila *s);

//Elimina pila (Borra a todos los elementos y a la pila de memoria)
void Destroy(pila *s);
