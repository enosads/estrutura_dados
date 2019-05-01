#include <iostream>

using namespace std;

struct Elemento {
  int info;
  Elemento *prox;
};

void  criar_lista(Elemento *&l){
  l = NULL;
};

void inserir_inicio(Elemento *&l, int info){
  Elemento *novo = new Elemento;
  novo->info = info;
  novo->prox = l;
  l = novo;
}

void imprimir_lista(Elemento *l){
  printf("Lista: \"");
  while (l != NULL) {
    cout << l->info << " ";
    l = l->prox;
  }
  cout << "\"\n";
}

bool esta_vazia(Elemento *l){
  if(l == NULL) return true;
  return false;
}

Elemento* busca_sequencial(Elemento *l, int info){
    Elemento* atual = l;
    while(atual != NULL){
        if(atual->info == info) return atual;
        atual = atual->prox;
    }
    return NULL;
}

bool excluir_elemento(Elemento *&l, int info){
    Elemento* ant = NULL;
    Elemento* i = l;
    while(i != NULL && i->info != info){
        ant = i;
        i = i->prox;
    }
    if(i == NULL) return false; // O elemento não existe;
    if(ant == NULL) l = i->prox;
    else ant->prox = i->prox;
    free(i);
    return true;
}

void excluir_lista(Elemento *&l){
    Elemento* e = l;
    while(e != NULL){
        Elemento* apagar = e; //Variável auxiliar
        e = e->prox;
        free(apagar);
    }
    l = NULL;
}

void verificar_lista(Elemento *l){
    if(esta_vazia(l)) cout << "A lista esta vazia!\n";
    else cout << "A lista nao esta vazia!\n";
    imprimir_lista(l);
}

int main (){
  Elemento *l = new Elemento;
  cout << "Lista criada!\n";
  criar_lista(l);
  verificar_lista(l);

  cout << "\nInserindo os elementos\n";
  inserir_inicio(l, 7);
  inserir_inicio(l, 14);
  inserir_inicio(l, 33);
  verificar_lista(l);

  if (excluir_elemento(l, 14)) cout << "\nElemento 14 excluido\n";
  else cout << "\nElemento 14 nao excluido\n";
  verificar_lista(l);

  cout << "\nExcluindo lista\n";
  excluir_lista(l);
  verificar_lista(l);
}
