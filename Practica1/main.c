#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TADPilaEst.c"
//#include "TADPilaDin.c"

#define TAM_CADENA 100

void menu()
{
    printf("\nMenu Practica 1");
    printf("\n1.Escribir una expresion.");
    printf("\n2.Validar Parentesis.");
    printf("\n3.Cambiar a posfija.");
    printf("\n4.Asignar valores y evaluar la expresion.");
    printf("\n5.Corregir expresion.");
    printf("\n6.Salir");
}

void Escribe_Expresion(char *cad)
{
    printf("\nEscribe la expresion: ");
    scanf("%s",cad);
}

boolean validar_parentesis(char *cad)
{

    boolean r= FALSE;
    pila p;
    elemento e;
    int i=0;

    if(cad[0] == '\0')
    {
        printf("\nLa cadena esta vacia, escribe una...");
    }
    else
    {

        while(cad[i] != '\0')
        {

            if(cad[i] == '(')
            {
                e.c = '(';
                Push(&p, e);
            }
            else if(cad[i] == ')')
            {

                if(Empty(&p))
                {
                    printf("\nError: Falto abrir parentesis");
                    exit(1);
                }
                else Pop(&p);
            }
            i++;
        }

        if(Empty(&p))
        {
            r = TRUE;
            printf("\nLa expresion es correcta");

        }else printf("\nError: Falto cerrar parentesis");
    }

    return r;
}

void expresion_posfija(char *cad, boolean validacion, char *cad_posfija)
{
    pila p;
    elemento e;
    int i=0,j=0;

    if(!validacion) printf("\nLa expresion no es valida para pasarla a posfijo.");
    else
    {
        while(cad[i] != '\0')
        {
            if(cad[i] == '(')
            {
                e.c = cad[i];
                Push(&p,e);
            }
            else if(cad[i] == '+' || cad[i] == '-')
            {
                if(Top(&p).c == '+' || Top(&p).c == '-')
                {
                    e.c = cad[i];
                    cad_posfija[j] = Pop(&p).c;
                    j++;
                    Push(&p, e);
                }
                else if(Top(&p).c == '*' || Top(&p).c == '/' || Top(&p).c == '^')
                {
                    e.c = cad[i];
                    Push(&p, e);
                }
            }
            else if(cad[i] == '*' || cad[i] == '/')
            {
                if(Top(&p).c == '*' || Top(&p).c == '/')
                {
                    e.c = cad[i];
                    cad_posfija[j] = Pop(&p).c;
                    j++;
                    Push(&p, e);
                }
                else if(Top(&p).c == '+' || Top(&p).c == '-')
                {
                    e.c = cad[i];

                    do
                    {
                        cad_posfija[j] = Pop(&p).c;
                        j++;
                    }while(!Empty(&p));

                    Push(&p, e);
                }
                else if(Top(&p).c == '^')
                {
                    e.c = cad[i];
                    Push(&p, e);
                }
            }
            else if(cad[i] == '^')
            {
                if(Top(&p).c == '+' || Top(&p).c == '-' || Top(&p).c == '*' || Top(&p).c == '/')
                {
                    e.c = cad[i];

                    do
                    {
                        cad_posfija[j] = Pop(&p).c;
                        j++;
                    }while(!Empty(&p));

                    Push(&p, e);
                }
            }
            else
            {
                cad_posfija[j] = Pop(&p).c;
                j++;
            }

            i++;
        }

        cad_posfija[j] = '\0';
        printf("\n%s",cad_posfija);
    }
}



int main(){

    char cad[TAM_CADENA];
    char cad_posija[TAM_CADENA];
    pila mi_pila;
    int resp,opc;
    boolean validacion;

    cad[0] = '\0';

    do
    {
        menu();
        printf("\nElige una opcion: ");
        scanf("%d",&opc);

        switch(opc)
        {

            case 1:
                    Escribe_Expresion(&cad[0]);
                    break;
            case 2:
                    validacion = validar_parentesis(&cad[0]);
                    break;
            case 3:
                    expresion_posfija(&cad[0],validacion,&cad_posija[0]);
                    break;
                    
            case 4:
                    break;
        }

        printf("\nQuieres realizar otra operacion? Si=1 No=0");
        scanf("%d",&resp);
    }while(resp != 0);

    return 0;
}
