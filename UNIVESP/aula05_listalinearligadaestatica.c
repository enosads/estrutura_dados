#include <stdio.h>
#define MAX 50
#define INVALIDO -1

typedef int TIPOCHAVE;

typedef struct{
    TIPOCHAVE chave;
    //outros campos
} REGISTRO;

typedef struct{
    REGISTRO reg;
    int prox;
} ELEMENTO;

typedef struct{
    ELEMENTO A[MAX];
    int inicio;
    int dispo;
} LISTA;

void inicializarLista(LISTA *l){
    for(int i = 0; i < MAX -1; i++){
        l->A[i].prox = i + 1;
    }
    l->A[MAX-1].prox = INVALIDO;
    l->inicio = INVALIDO;
    l->dispo = 0;
}

int tamanho(LISTA *l){
    int i = l->inicio;
    int tam = 0;
    while(i != INVALIDO){
        tam++;
        i = l->A[i].prox;
    }
    return tam;
}
void exibirLista(LISTA *l){
    int i = l->inicio;
    while(i != INVALIDO){
        printf("%i ", l->A[i].reg.chave);
        i = l->A[i].prox;
    }
    printf("\"\n");
}
int buscaSequencial(LISTA *l, int ch){
    int i = l->inicio;
    while(i != INVALIDO && i < l->A[i].reg.chave) 
        i = l->A[i].prox;
    if (i != INVALIDO && i < l->A[i].reg.chave) 
        return i;
    return INVALIDO;
}
int obterNo(LISTA *l){
    int resultado = l->dispo;
    if (l->dispo != INVALIDO) 
        l->dispo = l->A[l->dispo].prox;
    return resultado;   
}
bool inserirElemListaOrd(LISTA *l, REGISTRO reg){
    if (l->dispo == INVALIDO) return false;
    int ant = INVALIDO;
    int i = l->inicio;
    TIPOCHAVE ch = reg.chave;
    while((i != INVALIDO) && (L->A[i].reg.chave < ch)){
        ant = i;
        i = l->A[i].prox;
    }
    if (i != INVALIDO && l->A[i].reg.chave == ch) return false;
    i = obterNo(l);
    l->A[i].reg = reg;
    if (ant == INVALIDO) {
        l->A[i].prox = l->inicio;
        l->inicio = i;
    }else{
        l->A[i].prox = l->A[ant].prox;
        l->A[ant].prox = i;
    }
    return true;    
}
bool excluirElemLista(LISTA *l, TIPOCHAVE ch){
    int ant = INVALIDO;
    int i = l->inicio;
    while((i != INVALIDO) && (l->A[i].reg.chave < ch)){
        ant = i; 
        i = l->A[i].prox;
    }
    if (i == INVALIDO || l->A[i].chave != ch) return false;
    if (ant == INVALIDO) l->inicio = l->A[i].prox;
    else l->A[ant].prox = l->A[i].prox;
    devolverNo(l, i);
    return true;
}
void devolverNo(LISTA *l, int j){
    l->A[j].prox = l->dispo;
    l->dispo = j;
}
void reinicializarLista(LISTA *l){
    inicializarLista(l);
}