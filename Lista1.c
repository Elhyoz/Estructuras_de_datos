#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
int main()
{
	Lista a=cons(4,cons(5,cons(6,vacia())));
	ImpElem(cabeza(resto(a)));
	return 0;
}
