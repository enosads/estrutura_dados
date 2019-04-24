#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct{
    int matricula;
    char *nome;
    float u1;
    float u2;
    float media;
} Estudante;

typedef struct{
    int  total;
    Estudante inicio, fim;
	Estudante itens[MAX];
}Fila;

Fila criafila();
void colocanafila(Fila *f, Estudante e);
Estudante tiradafila(Fila *f);
bool filavazia(Fila *f);
void liberafila(Fila *f);
void imprimirfila(Fila *f);
