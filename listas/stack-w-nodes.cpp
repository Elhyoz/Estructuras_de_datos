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

Elemento * createNode(void);
int initialize_stack(Pila *, Elemento *);
int push(Pila *, Elemento *);
int pop(Pila *);
void print(Pila *l);
void menu();
void initialize(Pila *);
int cont=0;

int main(void){
	Pila s1;
	Elemento *nvo;
	int option;
	
	initialize(&s1);
	
	do{
		menu();
		cin>>option;
		switch(option){
			case 1:
				nvo=createNode();
				if(nvo!=NULL){
					if(initialize_stack(&s1, nvo))
						cout<<"Primer elemento insertado exitosamente"<<endl;
					else{
						cont--;
						free(nvo);
						cout<<"Error. La pila ya contiene elementos."<<endl;
					}
				}
				else
					cout<<"No se pudo crear el nodo"<<endl;
				break;
				
			case 2:
				nvo=createNode();
				if(nvo!=NULL){
					if(push(&s1, nvo))
						cout<<"Elemento insertado exitosamente"<<endl;
					else{
						cont--;
						free(nvo);
						cout<<"Overflow"<<endl;
					}
				}
				else
					cout<<"No se pudo generar el nodo"<<endl;
				break;
			
			case 3:
				if(pop(&s1))
					cout<<"Elemento eliminado"<<endl;
				else
					cout<<"Underflow"<<endl;
				break;
			
			case 4:
				if(s1.tamano!=0)
					print(&s1);
				else
					cout<<"No hay elementos"<<endl;
				break;
				
			case 5:
				cout<<"Fin del programa"<<endl;
				break;
			default:
				cout<<"Opcion invalida"<<endl;
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
	system("cls");
	cout<<"Opcion 1. Inicializar pila"<<endl<<"Opcion 2. Push"
	<<endl<<"Opcion 3. Pop"<<endl<<"Opcion 4. Imprimir pila"<<endl<<"Opcion 5. Salir"<<endl;
	cout<<"Opcion: ";
}

void print(Pila *l){
    Elemento *aux=l->inicio;
    while(aux!=NULL)
    {
        printf("%d --> ", aux->dato);
        aux=aux->sig;
    }
}


