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
void imprime(Lista *);
void random_fill(Lista *);
void initialize(Lista *);
int random_generate();
int inserta_random(Lista *, int);
int inserta_al_inicio(Lista *, Elemento *);
int cont=0;

int main(void){
	Lista q1;
	Elemento *nvo;
	srand(time(NULL));
	initialize(&q1);
	/* TODO (Baruch#1#): Terminar lista de tamaño 100, llenarla de 
	                     manera aleatoria. */
	
	for(int i=0;i<100;i++){
		nvo=creaNodo();
		inserta_primer_elem(&q1, nvo);
		inserta_al_inicio(&q1, nvo);
		imprime(&q1);
	}
}

Elemento * creaNodo(void){
    Elemento *nvo;
    nvo=(Elemento *)malloc(sizeof(Elemento));
    if(nvo!=NULL){
        nvo->sig=NULL;
        nvo->dato= 1 + (rand()%50);
    }
    return nvo;
}

int inserta_primer_elem(Lista *l, Elemento *nvo){
        if(l->tamano==0){
            l->inicio=nvo;
            l->fin=nvo;
            l->tamano++;
            return 1;
        }
        else
            return 0;
}

void imprime(Lista *l){
    Elemento *aux = l->inicio;
    while(aux!=NULL){
        cout<<" -->"<<aux->dato<<endl;
        aux=aux->sig;
    }
}

void initialize(Lista *l){
	l->inicio=NULL;
    l->fin=NULL;
    l->tamano=0;
}

int random_generate(){
	int random;
	random = 1+ (rand()%50);
	return random;
}

int inserta_al_inicio(Lista *l, Elemento *nvo)
{
    if(l->tamano>0)
    {
        nvo->sig=l->inicio;
        l->inicio=nvo;
        l->tamano++;
        return 1;
    }
    else
        return 0;
}
