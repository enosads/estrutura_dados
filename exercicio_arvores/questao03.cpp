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

void imprimir_arvore(No *raiz){
    if (raiz != NULL) {

      imprimir_arvore(raiz->esq);
      cout << raiz->dado << " ";
      imprimir_arvore(raiz->dir);
    }
}

int qtd_nao_folha(No *raiz){
    if(raiz == NULL || raiz->esq == NULL && raiz->dir == NULL)
        return 0;
    else{
        return 1 + qtd_nao_folha(raiz->esq)+qtd_nao_folha(raiz->dir);
    }
}

int main(int argc, char const *argv[]) {

  No* raiz = criar_arvore();
  inserir(raiz, 3);
  inserir(raiz, 7);
  inserir(raiz, 1);
  inserir(raiz, 2);

  cout <<"Quantidade de nós não-folhas: " << qtd_nao_folha(raiz);
  return 0;
}
