#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct{
    int inicio, fim, total;
    int itens[MAX];
}Fila;

Fila criafila();
void colocanafila(Fila *f, int e);
int tiradafila(Fila *f);
bool filavazia(Fila *f);
void liberafila(Fila *f);
void imprimirfila(Fila *f);