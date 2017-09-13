#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

typedef struct elemento
{
    int dato;
    struct elemento *sig;
}Elemento;

typedef struct ListaIdentificar
{
    Elemento *inicio;
    Elemento *fin;
    int tamano;
    
}Lista;

Elemento * creaNodo(void);
int inserta_primer_elem(Lista *, Elemento *);
int cont=0;

int main(void){
	Lista q1;
	Elemento *nvo;
	
	srand(time(NULL));
	/* TODO (Baruch#1#): Terminar lista de tamaño 100, llenarla de 
	                     manera aleatoria. */
	while(q1.tamano<=100){
		if(q1.tamano==0){
			inserta_primer_elem(&q1, nvo);
		}
		creaNodo();
		q1.tamano++;
	}
}

Elemento * creaNodo(void){
	
    Elemento *nvo;
    nvo=(Elemento *)malloc(sizeof(Elemento));
    if(nvo!=NULL)
    {
        nvo->sig=NULL;
        nvo->dato=++cont;
    }
    return nvo;
}

int inserta_primer_elem(Lista *l, Elemento *nvo)
{
        if(l->tamano==0){
            l->inicio=nvo;
            l->fin=nvo;
            l->tamano++;
            return 1;
        }
        else
            return 0;
}
