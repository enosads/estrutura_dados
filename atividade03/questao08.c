#include <stdio.h>
#include <stdlib.h>

struct Nos{
	int num;
	struct Nos *proximo;
};

typedef struct Nos No;

No *lista = NULL;

void inserirPrimeiro(int valor) {
    No *no = (No*) malloc (sizeof(No));
    no->num = valor;
    no->proximo = lista;
    lista = no;
}
void inserirUltimo(int valor) {
    if (lista == NULL) {
        inserirPrimeiro(valor);
        return;
    }
    No *no = lista, *novo;
    while (no->proximo != NULL){
        no = no->proximo;
    }
    novo = (No*) malloc(sizeof(No));
    novo->num = valor;
    novo->proximo = NULL;
    no->proximo = novo;
}
int tamanho(){
    int cont = 0;
    No *no = lista;
    while (no != NULL){
        no = no->proximo;
        cont++;
    }
    return cont;
}
void main(){
    
    for(int i = 0; i < 10; i++){
        inserirUltimo(i+1);
    }
    printf("Numero de Nos: %d\n", tamanho());
}