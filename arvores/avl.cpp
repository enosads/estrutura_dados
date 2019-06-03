#include <iostream>

using namespace std;

struct No{
  int dado;
  No* esq;
  No* dir;
  int fe;
};

No* criar_arvore(){
  No* no = new No;
  no = NULL;
  return no;
}

void imprimir_pre(No *raiz){
    if (raiz != NULL) {
      cout << raiz->dado << " ";
      imprimir_pre(raiz->esq);
      imprimir_pre(raiz->dir);
    }
}

void rotacao_esquerda(No *&raiz){
  No * q;
  q = raiz->dir;
  raiz->dir = q->esq;
  q->esq = raiz;
  raiz = q;
}

void rotacao_direita(No *&raiz){
  No *q;
  q = raiz->esq;
  raiz->esq = q->dir;
  q->dir = raiz;
  raiz = q;
}

bool inserir_avl(No *&raiz, int valor){
  if (raiz == NULL){
    raiz = new No;
    raiz->dado = valor;
    raiz->esq = NULL;
    raiz->dir = NULL;
    raiz->fe = 0;
    return true;
  }
  else
    if(valor < raiz->dado){
      if(inserir_avl(raiz->esq, valor)){
        switch (raiz->fe) {
          case 1: raiz->fe = 0; return false;
          case 0: raiz->fe = -1; return true;
          case -1:
            if(raiz->esq->fe == -1)
              rotacao_direita(raiz);
            else{
              rotacao_esquerda(raiz->esq);
              rotacao_direita(raiz);
              raiz->fe = 0;
              return false;
            }
        }
      }
    }else{
      if(valor > raiz->dado){
        if (inserir_avl(raiz->dir, valor)) {
          switch (raiz->fe) {
            case -1: raiz->fe = 0; return false;
            case 0: raiz->fe = 1; return true;
            case 1:
              if(raiz->dir->fe == 1)
                rotacao_esquerda(raiz);
              else{
                rotacao_direita(raiz->dir);
                rotacao_esquerda(raiz);
              }
              raiz->fe = 0;
              return false;
          }
        }
      }
    }
}

int main() {
  No* raiz = criar_arvore();
  inserir_avl(raiz, 8);
  inserir_avl(raiz, 6);
  inserir_avl(raiz, 10);
  inserir_avl(raiz, 9);
  inserir_avl(raiz, 12);
  inserir_avl(raiz, 14);
  imprimir_pre(raiz);



  return 0;
}
