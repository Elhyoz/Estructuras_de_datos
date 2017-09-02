#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <time.h>
#define TAM 10
using namespace std;

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
	int dequeued, option;
	int random_numbers = rand()%10;
	
	initialize(&q1);
	initialize(&par);
	initialize(&impar);
	random_fill(&q1);
	fflush(stdin);
	
	do{
		menu();
		cin>>option;
		switch(option){
			case 1:
				while(!empty(&q1)){
					dequeued = dequeue(&q1);
					cout<<"Elemento eliminado: "<<dequeued<<endl;
					system("pause");
					
					if(dequeued%2==0){
						cout<<"Ingreso: "<<dequeued<<endl;
						enqueue(&par, dequeued);
						system("pause");
					}
					
					else{
						cout<<"Ingreso: "<<dequeued<<endl;
						enqueue(&impar, dequeued);
						system("pause");
					}
				}
				/* Use this in Linux.
				cout<<"Presione una tecla para continuar..."<<endl;
				getchar();
				*/
				cout<<"Fila vacia"<<endl;
				system("pause");  //Only for windows
				break;
			case 2:
				cout<<"Fila de pares: ";
				print(&par);
				system("pause");
				break;
				
			case 3:
				cout<<"Fila de impares: ";
				print(&impar);
				system("pause");
				break;
			case 4:
				cout<<"Fin del programa. Adios."<<endl;
				break;
		}
	}while(option!=4);
}

void print(Random *pq){
	for(int i = 0; i < pq->rear;i++){
		cout<<pq->queue[i]<<", ";
	}
}

void random_fill(Random *pq){
	while(!full(pq)){
		pq->queue[pq->rear] = rand()%10;
		pq->rear++;
	}
	
}

void initialize(Random *pq){
	pq->front = 0;
	pq->rear = 0;
}

void menu(){
	system("cls");
	cout<<"Menu. Fila con arreglo estatico"<<endl<<endl;
	cout<<"Opcion 1. Dequeue\n\nOpcion 2. Imprimir pares\n\nOpcion 3. Imprimir impares\n\nOpcion 4. Salir"<<endl;
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
