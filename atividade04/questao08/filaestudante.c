#include <stdio.h>
#include <stdlib.h>
#include "filaestudante.h"

Fila criafila(){
	Fila fila;
	fila.total = 0;
	return fila;
}
 
void colocanafila(Fila *f, Estudante e){
	if(f->total == 0) f->inicio = e;
	if(f->total == 100){
		printf("Fila lotada\n");
		return;
	}
	f->fim = e;
	f->itens[f->total] = e;
	f->total++;
}
Estudante tiradafila(Fila *f){
	if(filavazia(f)){
		printf("Fila vazia\n");
		return;
	}
	Estudante e = f->inicio;
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
		printf("\n=========== Estudante %d ===========\nNome: %s\nMatricula: %d\nMedia: %.1f\n", (i+1), f->itens[i].nome, f->itens[i].matricula, f->itens[i].media);
	}	
}
