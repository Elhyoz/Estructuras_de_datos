#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <time.h>
#include <string.h>
#define TAM 20

using namespace std;
int main(void){
	int size;
	char llave[size];
 	cout<<"Ingrese tamaño de alfabeto"<<endl;
 	cin>>size;
 	
 	for(int i=0; i<size;i++){
 		cout<<"Ingrese el alfabeto"<<endl;
 		cin>>llave[i];
	}
	cout<<"Su alfabeto es: ";
	for(int i=0;i<size;i++){
		cout<<llave[i]<<", ";
	}
 	
 }
