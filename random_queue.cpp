#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <time.h>
#define TAM 4
typedef struct Random{
	int queue[TAM];
	int front, rear;
}random;



char love = TRUE;

int full(queue *);
void fill(random *)
int empty(queue *);
void enqueue(queue *, int); /* (fila, elemento a insertar) */
int dequeue(queue *);
void initialize(queue *);
void random_fill(random *);
void print(queue *);

int main(void){
	random q, par, impar;
	initialize(&q);
	int dequeued;
}

void initialize(queue *pq){
	pq->front = 0;
	pq->rear = 0;
}
