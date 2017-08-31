#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <time.h>
#define TAM 10
using namespace std;

/* TODO (#1#): Añadir la funcionalidad con el menu y la
		utilizacion de las demas funciones */


struct Random{
	int queue[TAM];
	int front, rear;
};

int full(Random *);
void fill(Random *);
int empty(Random *);
void enqueue(Random *, int); /* (fila, elemento a insertar) */
int dequeue(Random *);
void initialize(Random *);
void random_fill(Random *);
void print(Random *);
void menu();

int main(void){
	Random q1;
	Random par;
	Random impar;

	srand(time(NULL));
	int fila_random[TAM];
	int dequeued, option;
	int random_numbers = rand()%10;
	initialize(&q1);
	random_fill(&q1);
	cout<<"Fila rellenada de manera aleatoria: "<<setw(2);
	for(int i=0;i<TAM;i++){
		cout<<q1.queue[i]<<", ";
	}
	fflush(stdin);

	for(int i=0; i<TAM; i++){
		dequeued = dequeue(&q1);
		if(dequeued%2 == 0){
			enqueue(&par, dequeued);
		}
		else
			enqueue(&impar, dequeued);
	}

	cout<<"Fila de pares"<<endl;
	for(int i = 0;i < TAM; i++){
        cout<<par.queue[i]<<", ";
	}

	cout<<"Fila de impares"<<endl;
	for(int i = 0;i < TAM; i++){
        cout<<impar.queue[i]<<", ";
	}
}

void random_fill(Random *pq){
	for(int i=0; i<TAM; i++){
		pq->queue[i] = rand()%10;
	}
}

void initialize(Random *pq){
	pq->front = 0;
	pq->rear = 0;
}

void menu(){
	system("cls");
	cout<<"Menu. Fila con arreglo estatico"<<endl<<endl;
	cout<<"Opcion 1. Dequeue\n\n Opcion 2. Imprimir \n\n Opcion 3. Salir";
	cout<<"Opcion: ";
}

int dequeue(Random *pq){
	int temporal = pq->queue[pq->front];
	for(int i = 0;i < pq->rear-1;i++){
		pq->queue[i] = pq->queue[i+1];
	}
	pq->rear--;
	return temporal;
}

void enqueue(Random *pq, int dequeued){
	cout<<"Ingreso: "<<dequeued<<endl;
	cout<<"Presione una tecla para continuar..."<<endl;
	getchar();
	pq->queue[pq->rear]=dequeued;
	pq->rear++;
}

int empty(Random *pq){
	if(pq->front==pq->rear){
		return 1;
	}
	else
		return 0;
//	return pq->front=pq->rear?1:0;
}

int full(Random *pq){
	if(pq->rear == TAM){
		return 1;
	}
	else
		return 0;
}
