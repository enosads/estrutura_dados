#include <string>
#include <iostream>
#include "pilha.h"

using namespace std;

struct No{
  string dado;
  No* prox;
};

struct Pilha{
  No* topo;
  int qtd;
};

Pilha* criar_pilha(){
  Pilha* pilha = new Pilha;
  pilha->topo = NULL;
  pilha->qtd = 0;
};

bool estaVazio(Pilha *pilha){
  if(pilha->qtd == 0) return true;
  return false;
}

string espiar_topo(Pilha *pilha){
  return pilha->topo->dado;
}

string desempilhar(Pilha *&pilha) {
  string dado;

  if(!estaVazio(pilha)) {
    dado = pilha->topo->dado;
    No *aux = pilha->topo;
    pilha->topo = pilha->topo->prox;
    delete aux;
    pilha->qtd--;
    return dado;
   }else return NULL;
}

void empilhar(Pilha *&pilha, string dado) {
  No* no = new  No;
  no->dado = dado;
  no->prox = pilha->topo;
  pilha->topo = no;
  pilha->qtd++;
}
