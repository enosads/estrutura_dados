#include <iostream>
#define MAX 50

using namespace std;

struct Pilha {
  int n;
  float vet[MAX];
};

Pilha* criar_pilha(){
  Pilha* pilha = new Pilha;
  pilha->n = 0;
  return pilha;
};

bool estaVazio(Pilha *pilha){
  if(pilha == NULL || pilha->n == 0) return true;
  return false;
}

void empilhar(Pilha *pilha, float dado) {
  if(pilha == NULL){
    cout << "Inicialize a pilha" << endl;
    return;
  }
  if(pilha->n == MAX){
    cout << "Pilha cheia" << endl;
    return;
  }
  pilha->vet[pilha->n] = dado;
  pilha->n++;
}

void liberar_pilha(Pilha *pilha){
  if(pilha == NULL){
    cout << "Inicialize a pilha" << endl;
    return;
  }
  pilha->n = 0;
}

float desempilhar(Pilha *pilha) {
  if(pilha == NULL){
    cout << "Inicialize a pilha" << endl;
    return -1;
  }
  if(estaVazio(pilha)){
    cout << "Pilha vazia" << endl;
    return -1;
  }
  float retorno = pilha->vet[pilha->n-1];
  pilha->n--;
  return retorno;
}

void imprimir(Pilha* pilha){
  if(pilha == NULL){
    cout << "Inicialize a pilha" << endl;
    return;
  }
  cout << "Pilha: ";
  for(int i = pilha->n-1; i >= 0; i--){
    cout << pilha->vet[i] << " ";
  }
}

int main() {
  Pilha* pilha = criar_pilha();
  empilhar(pilha, 99.9);
  empilhar(pilha, 2);
  empilhar(pilha, 3);
  empilhar(pilha, 9);

  imprimir(pilha);
  cout << "\nDesempilhado: " << desempilhar(pilha) << endl;
  imprimir(pilha);
  cout << "\nDesempilhado: " << desempilhar(pilha) << endl;
  imprimir(pilha);
  liberar_pilha(pilha);
  cout << endl;
  imprimir(pilha);
  return 0;
}
