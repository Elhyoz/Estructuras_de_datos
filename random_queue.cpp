#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <time.h>
#define TAM 10
using namespace std;


/* TODO (#1#): Añadir la funcionalidad con el menú y la 
		utilización de las demás funciones */
		

typedef struct Random{
	int queue[TAM];
	int front, rear;
}random;

int full(random *);
void fill(random *);
int empty(random *);
void enqueue(random *, int); /* (fila, elemento a insertar) */
int dequeue(random *);
void initialize(random *);
void random_fill(random *);
void print(random *);
void menu();

int main(void){
	random q1, par, impar;
	srand(time(NULL));
	int fila_random[TAM];
	int dequeued, option;
	int random_numbers = rand()%10;
	initialize(&q1);
	random_fill(&q1);
	for(int i=0;i<TAM;i++){
		cout<<q1.queue[i]<<endl;
	}
	fflush(stdin);
	dequeued = dequeue(&q1);
	if(dequeued%2 == 0){
		enqueue(&par, dequeued);
	}
	else
		enqueue(&impar, dequeued);
	
}

void random_fill(random *pq){
	for(int i=0; i<TAM; i++){
		pq->queue[i] = rand()%10;
	}
}

void initialize(random *pq){
	pq->front = 0;
	pq->rear = 0;
}

void menu(){
	system("cls");
	cout<<"Menu. Fila con arreglo estatico"<<endl<<endl;
	cout<<"Opcion 1. Dequeue\n\n Opcion 2. Imprimir \n\n Opcion 3. Salir";
	cout<<"Opcion: ";
}

int dequeue(random *pq){
	int temporal = pq->queue[pq->front];
	for(int i = 0;i < pq->rear-1;i++){
		pq->queue[i] = pq->queue[i+1];
	}
	pq->rear--;
	return temporal;
}

void enqueue(random *pq, int dequeued){
	cout<<"Ingreso: "<<dequeued<<endl;
	system("pause");
	pq->queue[pq->rear]=dequeued;
	pq->rear++;
}

int empty(random *pq){
	if(pq->front==pq->rear){
		return 1;
	}
	else
		return 0;
//	return pq->front=pq->rear?1:0;
}

int full(random *pq){
	if(pq->rear == TAM){
		return 1;
	}
	else
		return 0;
}
