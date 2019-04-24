#include "filadeints.h"

int main() {
	Fila f = criafila();
	colocanafila(&f, 4);
	colocanafila(&f, 6);
	colocanafila(&f, 8);
	colocanafila(&f, 3);
	colocanafila(&f, 1);
	int n1 = tiradafila(&f);
	int n2 = tiradafila(&f);
	int n3 = tiradafila(&f);
	colocanafila(&f, 3);
	colocanafila(&f, 1);
	colocanafila(&f, 5);
	colocanafila(&f, 6);
	int n4 = tiradafila(&f);
	int n5 = tiradafila(&f);
	imprimirfila(&f);
	if(filavazia(&f)) printf("Fila vazia\n");
	else printf("Fila nao vazia\n");
	liberafila(&f); 
	printf("Liberando fila...\n");
	if(filavazia(&f)) printf("Fila vazia\n");
	else printf("Fila nao vazia\n");
	liberafila(&f); 
	return 0;
}