#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <algorythm>
using namespace std;

typedef char GenericType;

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

int main(void){
	Elemento *nvo;
	/* TODO (Baruch#1#): Terminar lista de tamaño 100, llenarla de 
	                     manera aleatoria. */
	while(Lista.tamano<=100){	
		
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
