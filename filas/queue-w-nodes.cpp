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

typedef struct queue
{
    Elemento *inicio;
    Elemento *fin;
    int tamano;
}Queue;

void initialize(Queue *);
void menu();
int insert_end(Queue *, Elemento *);
int eliminate_start(Queue *);
Elemento * createNode(void);
int insert_first_elem(Queue *, Elemento *);
void print(Queue *);
int cont=0;

int main(void){
	Queue q1;
	Elemento *nvo;
	int option;
	
	initialize(&q1);
	
	do{
		menu();
		cin>>option;
		switch(option){
			case 1: nvo=createNode();
				if(nvo!=NULL){
					insert_first_elem(&q1, nvo);
					cout<<"Te la metieron excitantemente"<<endl;
				}
				
				else{
					cont--;
					free(nvo);
					cout<<"Ya te la metieron, no pidas mas"<<endl;
				}
				break;
				
			case 2: nvo=createNode();
				if(nvo!=NULL){
					if(insert_end(&q1, nvo))
						cout<<"Elemento insertado"<<endl;
					else{
						cont--;
						free(nvo);
						cout<<"Error. Lista vacia"<<endl;
					}
				}
				else
					cout<<"No pudo crearse el nodo"<<endl;
				break;
				
			case 3: 
				if(eliminate_start(&q1))
					cout<<"Nodo eliminado"<<endl;
				else
					cout<<"Error"<<endl;
				break;
			case 4:
				if(q1.tamano!=0)
					print(&q1);
				else
					cout<<"Fila vacia"<<endl;
				break;
				
			case 5:
				cout<<"Adios."<<endl;
				break;
			
			default:
				cout<<"Opcion no valida"<<endl;
		}
		system("pause");
	}while(option!=5);
	
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

void initialize(Queue *l)
{
    l->inicio=NULL;
    l->fin=NULL;
    l->tamano=0;
}

int insert_end(Queue *l, Elemento *nvo){
    if(l->tamano>0)
    {
        l->fin->sig=nvo;
        l->fin=nvo;
        l->tamano++;
        return 1;
    }
    else
        return 0;
}

int eliminate_start(Queue *l){
    Elemento *aux=l->inicio;
    if(l->tamano>1){
        l->inicio=l->inicio->sig;  //l->inicio=aux->sig;
        free(aux);
        l->tamano--;
        return 1;
    }
    else
        return 0;
}

void menu(){
	system("cls");
	cout<<"Opcion 1. Inicializar"<<endl<<"Opcion 2. Enqueue"<<endl<<"Opcion 3. Dequeue"
	<<endl<<"Opcion 4. Imprimir fila"<<endl<<"Opcion 5. Salir"<<endl;
	cout<<"Opcion: ";
}

int insert_first_elem(Queue *l, Elemento *nvo)
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

void print(Queue *l)
{
    Elemento *aux=l->inicio;
    while(aux!=NULL)
    {
        printf("%d --> ", aux->dato);
        aux=aux->sig;
    }
}

