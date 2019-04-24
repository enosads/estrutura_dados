#include "pilhadechars.h"

Pilha criapilha(){
	Pilha pilha;
	pilha.qtd = 0;
	pilha.topo = NULL;
	return pilha;
}
void empilha(Pilha *p, char e){
	if(p->qtd == 100){
		printf("Pilha cheia!\n");
		return;
	}
	int i;
	for(i = p->qtd; i > 0; i--){
		p->itens[i] = p->itens[i-1];
	}
	p->topo = e;
	p->itens[0] = e;
	p->qtd += 1;
}
char desempilha(Pilha *p){
	if(p->qtd == 0){
		printf("Pilha vazia!\n");
		return;
	}
	char e = p->topo;
	int i;
	for(i = 0; i < p->qtd -1; i++){
		p->itens[i] = p->itens[i+1];
	}
	p->topo = p->itens[0];
	p->qtd--;
	return e;
}
bool pilhavazia(Pilha *p){
	if(p->qtd == 0) return true;
	return false;
};
bool pilhacheia(Pilha *p){
	if(p->qtd == 100) return true;
	return false;
};

void imprimirpilha(Pilha *p){
	int i;
	for(i = 0; i < p->qtd; i++){
		printf("%c", p->itens[i]);
	}
	printf("\n");
};
