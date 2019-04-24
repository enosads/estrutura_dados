#include "pilhadechars.h"

Pilha criapilha(){
	Pilha pilha;
	pilha->qtd = 0;
	pilha->topo = NULL;
}
void empilha(Pilha *p, char e);
int desempilha(Pilha *p);
bool pilhavazia(Pilha *p);
bool pilhacheia(Pilha *p);
void imprimirpilha(Pilha *p);
