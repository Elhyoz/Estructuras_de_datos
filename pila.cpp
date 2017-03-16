#include <stdio.h>
#include <stdlib.h>
#include "Pila.h"


int main(int argc, char *argv){
	Pila a = empty();
	char *pal = *(argv+1);
	int i = 0;
	puts(*(argv+i++));

	while(*(pal+i)) a = push(*(pal+i++), a); //ejemplo 1

	while(pal[i]) a = push(pal[i++], a);

	while(!isempty(a)){
		ImpElem(top(a));
		a = pop(a);
	}
	return 0;
}