#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <time.h>
#include <windows.h>
#define TAM 10
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

int main(void){
	int c1=0; 
	int timer=0;
	int c3=0;
	int c2=0;
	cash clients;	
	srand(time(NULL));
	
	random_fill(&clients);
	do{
		int dequeued;
		print(&clients);
		dequeue(&clients);
		timer++;
		cout<<"Continua... "<<timer<<endl;
		Sleep(1000);
		system("cls");
	}while(!empty(&clients));
	cout<<"Fin del programa...";
	exit;
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
