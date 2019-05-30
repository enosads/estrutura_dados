
#include <iostream>

using namespace std;

struct No{
    float dado;
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

void imprimir_arvore(No *raiz){
    if (raiz != NULL) {
      cout << raiz->dado << " ";
      imprimir_arvore(raiz->esq);
      imprimir_arvore(raiz->dir);
    }
}

int qtd_nos(No *raiz){
  if (raiz == NULL)
    return 0;
  else return 1 + qtd_nos(raiz->esq) + qtd_nos(raiz->dir);
}

float soma_nos(No *raiz){
  if(raiz == NULL)
    return 0;
  else return raiz->dado + soma_nos(raiz->esq) + soma_nos(raiz->dir);
}

float media_nos(No *raiz){
  return soma_nos(raiz) / qtd_nos(raiz);
}

int main(int argc, char const *argv[]) {
  No* raiz = criar_arvore();
  inserir(raiz, 4.5);
  inserir(raiz, 6);
  inserir(raiz, 4.5);
  imprimir_arvore(raiz);


  cout << "\nMédia dos nós: " << media_nos(raiz);

  return 0;
}
