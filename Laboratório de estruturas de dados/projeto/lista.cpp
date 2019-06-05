#include "lista.h"
#include <iostream>

Lista* criar_lista(){
    Lista* lista = new Lista;
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->qtd = 0;
    return lista;
}

void inserir_inicio(Lista *&l, int num, string movedor, char tipo_pessoa, string data){
    Processo* p = new Processo;
    p->num = num;
    p->movedor = movedor;
    p->tipo_pessoa = tipo_pessoa;
    p->data = data;

    if(l->qtd == 0){
        l->inicio = p;
        l->fim = p;
        p->prox = NULL;
        p->ant = NULL;
    }else{
        p->prox = l->inicio;
        l->inicio = p;
        p->ant = NULL;
    }
    l->qtd++;
}

void inserir_fim(Lista *&l, int num, string movedor, char tipo_pessoa, string data){
    Processo* p = new Processo;
    p->num = num;
    p->movedor = movedor;
    p->tipo_pessoa = tipo_pessoa;
    p->data = data;

    if(l->qtd == 0){
        l->inicio = p;
        l->fim = p;
        p->prox = NULL;
        p->ant = NULL;
    }else{
        l->fim->prox = p;
        p->ant = l->fim;
        l->fim = p;
        p->prox = NULL;
    }
    l->qtd++;
}

bool inserir_posicao(Lista *&l, int posicao, int num, string movedor, char tipo_pessoa, string data){
    if(posicao > l->qtd || posicao < 0)
        return false;
    else {
        Processo* p = new Processo;
        p->num = num;
        p->movedor = movedor;
        p->tipo_pessoa = tipo_pessoa;
        p->data = data;

        int i = 0;
        Processo* percorredor = l->inicio;
        Processo* ant;
        while (i != posicao) {
            ant = percorredor;
            percorredor = percorredor->prox;
            i++;
        }
        p->prox = percorredor;
        percorredor->ant = p;
        p->ant = ant;
        ant->prox = p;
    }
    l->qtd++;
    return true;

}

Processo* remover_inicio(Lista *&l){
    if(l->qtd == 0) return NULL;
    else{
        Processo* p = l->inicio;
        l->inicio = l->inicio->prox;
        l->qtd--;
        return p;
    }
}

void lista_processos(Lista* l){
    Processo *p = l->inicio;
    while(p != NULL){
        cout << "\nProcesso:\nNúmero do processo: "<< p->num
             << "\nMovedor do processo: " << p->movedor
             << "\nPessoa: " << p->tipo_pessoa
             << "\Data: " << p->data << endl;
        p = p->prox;
    }
}
