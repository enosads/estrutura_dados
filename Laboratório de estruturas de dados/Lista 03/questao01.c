#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct{
    int info;
} REGISTRO;

typedef struct elemento{
    REGISTRO reg;
    struct elemento* prox;
} ELEMENTO;

typedef struct {
    ELEMENTO* inicio;
} LISTA;

void criarLista(LISTA *l){
    l->inicio = NULL;
}

void inserirElemListaInicio(LISTA *l, REGISTRO reg){
    ELEMENTO* e = malloc(sizeof(ELEMENTO));
    e->reg = reg;
    e->prox = l->inicio;
    l->inicio = e;
}

void imprimirLista(LISTA *l){
    ELEMENTO* end = l->inicio;
    printf("Lista: \" ");
    while(end != NULL){
        printf("%i ", end->reg.info);
        end = end->prox;
    }
    printf("\"\n");
}

bool estaVazia(LISTA *l){
    if(l == NULL || l->inicio == NULL) return true;
    return false;
}

ELEMENTO* buscaSequencial(LISTA *l, int info){
    ELEMENTO* pos = l->inicio;
    while(pos != NULL){
        if(pos->reg.info == info) return pos;
        pos = pos->prox;
    }
    return NULL;
}

bool excluirElemLista(LISTA *l, int info){
    ELEMENTO* ant = NULL;
    ELEMENTO* i = l->inicio;
    while(i != NULL && i->reg.info != info){
        ant = i;
        i = i->prox;
    }
    if(i == NULL) return false; // O elemento não existe;
    if(ant == NULL) l->inicio = i->prox;
    else ant->prox = i->prox;
    free(i);
    return true;
}

void excluirLista(LISTA *l){
    ELEMENTO* e = l->inicio;
    while(e != NULL){
        ELEMENTO* apagar = e; //Variável auxiliar
        e = e->prox;
        free(apagar);
    }
    l->inicio = NULL;
}

void verificarLista(LISTA *l){
    if(estaVazia(l)) printf("A lista esta vazia!\n");
    else printf("A lista nao esta vazia!\n");
    imprimirLista(l);
}

int main(){
    LISTA *l = (LISTA *) malloc(sizeof(LISTA));
    criarLista(l);
    printf("Lista criada!\n");
    verificarLista(l);

    printf("\nInserindo os elementos\n");
    REGISTRO regs[3];
    regs[0].info = 7;
    regs[1].info = 14;
    regs[2].info = 33;
    inserirElemListaInicio(l, regs[0]);
    inserirElemListaInicio(l, regs[1]);
    inserirElemListaInicio(l, regs[2]);
    verificarLista(l);

    printf("\nRemovendo o primeiro elemento\n");
    if(excluirElemLista(l, regs[2].info)) printf("Elemento %d excluido\n", regs[2].info);
    else printf("Elemento %d nao excluido\n", regs[2].info);
    verificarLista(l);

    printf("\nExcluindo lista\n");
    excluirLista(l);
    verificarLista(l);
}