#include "filadeints.h"

Fila criafila(){
	Fila fila;
	fila.fim = NULL;
	fila.inicio = NULL;
	fila.total = 0;
	return fila;
}
 
void colocanafila(Fila *f, int e){
	if(f->total == 0) f->inicio = e;
	if(f->total == 100){
		printf("Fila lotada\n");
		return;
	}
	f->fim = e;
	f->itens[f->total] = e;
	f->total++;
}
int tiradafila(Fila *f){
	if(filavazia(f)){
		printf("Fila vazia\n");
		return;
	}
	int e = f->inicio;
	int i;
	for(i = 0; i < f->total -1; i++){
		f->itens[i] = f->itens[i+1];
	}
	f->total--;
	f->inicio = f->itens[0];
	f->fim = f->itens[f->total];
	return e;
}
bool filavazia(Fila *f){
	if(f->total == 0) return true;
	return false;
}
void liberafila(Fila *f){
	f->inicio = f->itens[0];
	f->fim = f->itens[0];
	f->total = 0;
}
void imprimirfila(Fila *f){
	int i;
	for(i = 0; i < f->total; i++){
		printf("%d ", f->itens[i]);
	}
	printf("\n");
}