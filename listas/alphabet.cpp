#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <time.h>
#include <string.h>
#define TAM 20

using namespace std;
void readString(char llave[], int x);
void multiplyAlphabet(char llave[], int k);
int main(void){
	int size, k;
	char llave[TAM];
 	cout<<"Ingrese tamaño de alfabeto"<<endl;
 	cin>>size;
 	llave[size];
 	cout<<"Ingrese alfabeto"<<endl;
	readString(llave, size);
	cout<<"Ingrese la potencia deseada"<<endl;
	cin>>k;
	multiplyAlphabet(llave, k);
	return 0;
 }
 
void readString(char llave[], int x){
 	for(int i=0; i<x;i++){
 		cin>>llave[i];
	}
}

void multiplyAlphabet(char llave, int k){
	int count=1;
	cout<<strcat(llave[0], llave[count]);
}



