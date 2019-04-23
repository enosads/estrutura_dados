#include <stdio.h>
#include <stdlib.h>

//Nó da lista
typedef struct {
    int num;
} No;

//Lista estática
typedef struct {
    int qtd;
    No nos[30];
} Lista;

int qtdPares(Lista *l){
    int qtd = 0;
    
    for(int i = 0; i < l->qtd; i++){
        if (l->nos[i].num % 2 == 0) qtd++;
    }
    return qtd;
}

int main(){
    Lista *l = (Lista*) malloc(sizeof(Lista));
    l->qtd = 100;
    for(int i = 1; i <= 100; i++){
        l->nos[i].num = i;
    }
    
    int qtd = qtdPares(l);
    printf("\nQuantidade de numeros pares na lista: %d",qtd);
}