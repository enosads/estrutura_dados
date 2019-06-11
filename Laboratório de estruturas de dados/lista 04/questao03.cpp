#include <iostream>
using namespace std;

struct no {
  float info;
  struct no* prox;
};

struct pilha {
  no* prim;
};

pilha* criar_pilha(){
  pilha* p = new pilha;
  p->prim = NULL;
  return p;
};

void empilhar(pilha *&pilha, float dado) {
  no* novo = new  no;
  novo->info = dado;
  novo->prox = pilha->prim;
  pilha->prim = novo;
}

float desempilhar(pilha *&pilha) {
  float dado;
  if(pilha != NULL && pilha->prim != NULL) {
    dado = pilha->prim->info;
    no *aux = pilha->prim;
    pilha->prim = pilha->prim->prox;
    delete aux;
    return dado;
  }else{
    cout << "Pilha vazia";
    return -1;
  }
}

void imprimir(pilha *pilha){
  if(pilha == NULL){
    cout << "Inicialize a pilha";
    return;
  }
  cout << "Pilha: ";
  no* perc = pilha->prim;
  while(perc != NULL){
    cout << perc->info << " ";
    perc =perc->prox;
  }
}

bool buscar(pilha* p, float valor){
  if(p == NULL) return false;
  no* perc = p->prim;
  while(perc != NULL && perc->info != valor)
    perc =perc->prox;
  if(perc == NULL) return false;
  return true;
}

int main() {
  pilha* p = criar_pilha();
  empilhar(p, 2);
  empilhar(p, 3);
  empilhar(p, 6);
  empilhar(p, 10);
  empilhar(p, 6);
  imprimir(p);
  cout << "\nDesempilhado: " << desempilhar(p) << endl;
  imprimir(p);
  cout << "\nDesempilhado: " << desempilhar(p) << endl;
  imprimir(p);
  cout << "\nO 2 está na pilha? " << buscar(p, 2);
  cout << "\nO 99 está na pilha? " << buscar(p, 99);



  return 0;
}
