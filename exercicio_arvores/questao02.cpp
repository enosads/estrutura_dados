#include <iostream>

using namespace std;

struct No{
    int dado;
    No *esq;
    No *dir;
};

No* criar_arvore(){
  No* no = new No;
  no = NULL;
  return no;
}

void inserir(No *&raiz, int dado){
  if (raiz == NULL) {
    raiz = new No;
    raiz->dado = dado;
    raiz->esq = NULL;
    raiz->dir = NULL;
  }else if (dado < raiz->dado) {
    inserir(raiz->esq, dado);
  }else
    inserir(raiz->dir, dado);
}

void espelhar(No *raiz){
  if (raiz != NULL) {
    espelhar(raiz->esq);
    espelhar(raiz->dir);
    No *aux = raiz->esq;
    raiz->esq = raiz->dir;
    raiz->dir = aux;
  }
}

void imprimir_arvore(No *raiz){
    if (raiz != NULL) {
      cout << raiz->dado << " ";
      imprimir_arvore(raiz->esq);
      imprimir_arvore(raiz->dir);
    }
}

int main(int argc, char const *argv[]) {
  No* raiz = criar_arvore();
  inserir(raiz, 3);
  inserir(raiz, 7);
  inserir(raiz, 9);
  inserir(raiz, 2);
  inserir(raiz, 8);
  inserir(raiz, 5);

  cout << "Antes de espelhar: ";
  imprimir_arvore(raiz);
  cout <<"\nDepois de espelhar: ";
  espelhar(raiz);

  imprimir_arvore(raiz);
  return 0;
}
