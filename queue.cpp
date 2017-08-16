#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#define TAM 4
using namespace std;

typedef int TipoDato;
typedef struct Queue{
	TipoDato fila[TAM];
	int front, rear;
}queue;

int full(queue *);
int empty(queue *);
void enqueue(queue *, int); /* (fila, elemento a insertar) */
int dequeue(queue *);
void initialize(queue *);
void menu();
void print(queue *);

int main(void){
	menu();
	int option;
	switch(option){
		case 1:
			if()
	}
	
	return 0;
}

int full(queue *pq){
	if(pq->rear == TAM){
		return 1;
	}
	else
		return 0;
}

int empty(queue *pq){
	return pq->front=pq->rear?1:0;
}

void enqueue(queue *pq, int element){
	pq->fila[pq->rear]=element;
	(pq->rear)++;
}

int dequeue(queue *pq){
	int temporal = pq->fila[pq->front];
	for(int i=0;i<pq->rear-1;i++){
		pq->fila[i] = pq->fila[i+1];
	}
	(pq->rear)--;
	return temporal;
}

void initialize(queue *pq){
	pq->front = 0;
	pq->rear = 0;
}

void menu(void){
	system("cls");
	cout<<"Menu. Fila con arreglo estatico"<<endl<<endl;
	cout<<"Opcion 1: Enqueue \n\nOpcion 2: Dequeue \n\nOpcion 3: Imprimir \n\nOpcion 4: Salir"<<endl;
	cout<<"Opcion: "<<endl;
}

void print(queue *pq){
	for(int i = 0; i < pq->rear;i++){
		cout<<"<--"<<pq->fila[i];
	}
}

