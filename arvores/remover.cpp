
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

void inserir(No *&raiz, float dado){
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

void imprimir_pre(No *raiz){
    if (raiz != NULL) {
      cout << raiz->dado << " ";
      imprimir_pre(raiz->esq);
      imprimir_pre(raiz->dir);
    }
}

No* get_menor(No *&raiz){
  if(raiz->esq == NULL){
    No* aux = raiz;
    raiz = raiz->dir;
    return aux;
  }else
    return get_menor(raiz->esq);
}

bool remover(No *&raiz, int valor){
  if(raiz == NULL) return false;
  else if(valor < raiz->dado)
    return remover(raiz->esq, valor);
  else if(valor > raiz->dado)
    return remover(raiz->dir, valor);
  else
    if(raiz->esq == NULL && raiz->dir == NULL){
      delete raiz;
      raiz = NULL;
    }else if(raiz->dir == NULL){
      No* aux = raiz;
      raiz = raiz->esq;
      delete aux;
    }else if (raiz->esq == NULL){
      No* aux = raiz;
      raiz = raiz->dir;
      delete aux;
    }else{
      No* aux = get_menor(raiz->dir);
      raiz->dado = aux->dado;
      delete aux;
    }
    return true;
}

int main() {
  No *no = criar_arvore();
  inserir(no, 7);
  inserir(no, 3);
  inserir(no, 10);
  inserir(no, 1);
  inserir(no, 5);
  inserir(no, 8);
  inserir(no, 9);
  inserir(no, 12);
  inserir(no, 11);
  cout << "Arvore completa: ";
  imprimir_pre(no);
  cout << endl;

  cout << "Nó 1 (folha) removido: ";
  remover(no, 1);
  imprimir_pre(no);
  cout << endl;

  cout << "Nó com 3 (1 filho) removido: " ;
  remover(no, 3);
  imprimir_pre(no);
  cout << endl;

  cout << "Nó 10 (2 filho) removido: "; 
  remover(no, 10);
  imprimir_pre(no);


  return 0;
}
