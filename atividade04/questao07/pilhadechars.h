#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct{
	int qtd;
	char topo; 
	char itens[MAX];
} Pilha;

Pilha criapilha();
void empilha(Pilha *p, char e);
char desempilha(Pilha *p);
bool pilhavazia(Pilha *p);
bool pilhacheia(Pilha *p);
void imprimirpilha(Pilha *p);
