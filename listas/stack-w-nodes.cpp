#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

typedef struct elemento{
    int dato;
    struct elemento *sig;
}Elemento;

typedef struct ListaIdentificar{
    Elemento *inicio;
    Elemento *fin;
    int tamano;
}Pila;

int main(void){
	Pila s1;
	Elemento *nvo;
	
	initialize(&s1);
	
	do{
		menu();
		cin>>option;
		switch(option){
			case 1:
				nvo=createNode();
				if(nvo!=NULL)
					cout<<"Primer elemento insertado exitosamente"<<endl;
		}
	}while(option!=4);
	
}

Elemento * createNode(void){
    Elemento *nvo;
    nvo=(Elemento *)malloc(sizeof(Elemento));
    if(nvo!=NULL)
    {
        nvo->sig=NULL;
        nvo->dato=++cont;
    }
    return nvo;
}

int initialize_stack(Pila *l, Elemento *nvo)
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

int push(Pila *l, Elemento *nvo){
    if(l->tamano>0){
        l->fin->sig=nvo;
        l->fin=nvo;
        l->tamano++;
        return 1;
    }
    else
        return 0;
}

int pop(Pila *l){
    Elemento *aux=l->inicio;   int i;
    if(l->tamano>1){
        for(i=1;i<=(l->tamano-2);i++)
            aux=aux->sig;
        l->fin=aux;
        free(aux->sig);
        l->fin->sig=NULL;
        l->tamano--;
        return 1;
    }
    else
        return 0;
}

void initialize(Pila *l)
{
    l->inicio=NULL;
    l->fin=NULL;
    l->tamano=0;
}

void menu(){
	cout<<"Opcion 1. Inicializar pila"<<endl<<"Opcion 2. Push"
	<<endl<<"Opcion 3. Pop"<<endl<<"Opcion 4. Imprimir pila"<<endl<<"Opcion 5. Salir"<<endl;
	cout<<"Opcion: ";
}


