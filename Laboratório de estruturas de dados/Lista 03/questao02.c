#include <stdio.h>
#include <malloc.h>

typedef struct ponto{ 
    float x; 
    float y; 
} Ponto; 

typedef struct elemento{ 
    Ponto* info; 
    struct elemento *prox; 
} Elemento;

typedef struct{
    Elemento* inicio;
} Lista;

void criarLista(Lista *l){
    l->inicio = NULL;
}

void exibirLista(Lista *l){
    Elemento* end = l->inicio;
    printf("Lista: \"");
    while(end != NULL){
        printf("(%.1f, %.1f) ", end->info->x, end->info->y);
        end = end->prox;
    }
    printf("\"\n");
}

void inserirElemListaInicio(Lista *l, Ponto* p){
    Elemento* e = (Elemento*) malloc(sizeof(Elemento));
    e->info = p;
    e->prox = l->inicio;
    l->inicio = e;
}

int main(){
    
    Lista *l = (Lista*) malloc(sizeof(Lista));
    criarLista(l);
    Ponto* p = (Ponto *) malloc(sizeof(Ponto));
    p->x = 5.0;
    p->y = 10.0;
    Ponto* q = (Ponto *) malloc(sizeof(Ponto));
    q->x = 20.0;
    q->y = 30.0;
    inserirElemListaInicio(l, p);
    inserirElemListaInicio(l, q);
    exibirLista(l);

    return 0;
}