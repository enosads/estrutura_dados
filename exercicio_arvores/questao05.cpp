
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

bool saoIguais(No *a1, No *a2){
  if(a1 == NULL && a2 == NULL)
    return true;
  else if (a1 != NULL && a2 != NULL && a1->dado == a2->dado)
    return true && saoIguais(a1->esq, a2->esq) && saoIguais(a1->dir, a2->dir);
  else return false;
}


int main(int argc, char const *argv[]) {

  //Altere os dados inseridos nas duas arvores para verificar se são iguais
  No* a1 = criar_arvore();
  inserir(a1, 4);
  inserir(a1, 4);
  inserir(a1, 2);


  No* a2 = criar_arvore();
  inserir(a2, 4);
  inserir(a2, 4);
  inserir(a2, 2);
  inserir(a2, 10);


  bool igual = saoIguais(a1, a2);
  cout << "As arvores são iguais? " << igual;
  return 0;
}
