#include "pilhadechars.h"

int main() {
	Pilha p = criapilha();
	empilha(&p, 'A');
	empilha(&p, 'H');
	empilha(&p, 'L');
	empilha(&p, 'I');
	empilha(&p, 'P');
	imprimirpilha(&p);
	char c1 = desempilha(&p);
	char c2 = desempilha(&p);
	printf("Primeira remocao: %c\n", c1);
	printf("Segunda remocao: %c\n", c2);
	if(pilhavazia(&p)) printf("A pilha esta vazia\n");
	else printf("A pilha nao esta vazia\n");
	if(pilhacheia(&p)) printf("A pilha esta cheia\n");
	else printf("A pilha nao esta cheia\n");
	imprimirpilha(&p);
	return 0;
}
