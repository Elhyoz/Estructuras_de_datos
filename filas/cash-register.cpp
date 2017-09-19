#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <time.h>
#include <windows.h>
#define TAM 100
using namespace std;

typedef struct Cash{
	int queue[TAM];
	int front, rear;
}cash;

int empty(cash *);
void random_fill(cash *);
int full(cash *);
int dequeue(cash *);
void print(cash *);
void initialize(cash *);


int main(void){
	int c1=0; 
	int timer=0;
	int c3=0;
	int c2=0;
	cash clients;	
	srand(time(NULL));
	initialize(&clients);
	random_fill(&clients);
	
	while(!empty(&clients)){
			
		if(c1==0 && c2==0 && c3==0){
			c1=dequeue(&clients);
			c2=dequeue(&clients);
			c3=dequeue(&clients);
		}
		
		if(c1==0){
			c1=dequeue(&clients);
		}
			
		if(c1!=0){
			c1--;
			cout<<"Caja 1. Articulos: "<<c1<<endl;
		}
			
		if(c2==0){
			c2=dequeue(&clients);
		}
			
		if(c2!=0){
			c2--;
			cout<<"Caja 2. Articulos: "<<c2<<endl;
		}
			
		if(c3==0){
			c3=dequeue(&clients);
		}
			
		if(c3!=0){
			c3--;
			cout<<"Caja 3. Articulos: "<<c3<<endl;
		}
		
		timer++;
		cout<<"Continua... "<<timer<<endl;
		Sleep(1000);
		system("cls");
	}
	cout<<"Fin del programa...";
	exit;
}

void initialize(cash *pq){
	pq->front = 0;
	pq->rear = 0;
}

int full(cash *pq){
	if(pq->rear == TAM){
		return 1;
	}
	else
		return 0;
}

int empty(cash *pq){
	if(pq->front==pq->rear){
		return 1;
	}
	else
		return 0;
//	return pq->front=pq->rear?1:0;
}

void random_fill(cash *pq){
	while(!full(pq)){
		pq->queue[pq->rear] = rand()%10+1;
		pq->rear++;
	}	
}

void print(cash *pq){
	for(int i = 0; i < pq->rear;i++){
		cout<<pq->queue[i]<<"<--"<<endl;
	}
}

int dequeue(cash *pq){
	int temporal = pq->queue[pq->front];
	
	for(int i = 0;i < pq->rear-1;i++){
		pq->queue[i] = pq->queue[i+1];
	}
	
	pq->rear--;
	return temporal;
}
