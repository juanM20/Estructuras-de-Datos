#define TRUE 1
#define FALSE 0

typedef char boolean;

typedef struct element{

    long id_palabra;
    char palabra[51];
    char significado[200];

}element;

typedef struct nodo{

    element e;
    struct nodo *sig;
    struct nodo *ant;

}nodo;

typedef struct lista{

    nodo *frente;
    nodo *fin;

}lista;


void Init(lista *l);
void Insertar(lista *l, element e);
boolean Lista_Vacia(lista *l);
void Eliminar(lista *l, long id);
void Imprimir_Lista(lista *l);

