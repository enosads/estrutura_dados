
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
      cout << raiz->dado << " ";
      imprimir_arvore(raiz->esq);
      imprimir_arvore(raiz->dir);
    }
}

No* pai(No *raiz, int dado){
  if (raiz == NULL || raiz->esq == NULL && raiz->dir == NULL)
    return NULL;
  else if((raiz->esq != NULL && raiz->esq->dado == dado) ||
  (raiz->dir != NULL && raiz->dir->dado == dado))
    return raiz;
  else if(dado < raiz->dado)
    return pai(raiz->esq, dado);
  else
    return pai(raiz->dir, dado);
}

int main(int argc, char const *argv[]) {

  No* raiz = criar_arvore();
  inserir(raiz, 4);
  inserir(raiz, 9);
  inserir(raiz, 2);
  inserir(raiz, 1);

  imprimir_arvore(raiz);

  No* noPai = new No;
  noPai = NULL;
  int busca = 9; // altere o valor pra testar outros pais
  noPai = pai(raiz,  busca);
  if (noPai != NULL)
    cout <<"\nO pai do "<< busca <<" é o " << noPai->dado;
  else
    cout << "\nO dado buscado não está na árvore ou é o nó raiz";
  return 0;
}
