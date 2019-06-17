#include <iostream>

using namespace std;

#define TAM 20 // Constante que define a qtd de elemetos na tabela

struct Registro{
  int dado; // também é chave que será usada para gerar  hash
  Registro* prox;
  //outros campos
};

struct Tabela{
  Registro* registros[TAM];
};

int gerar_hash(int chave){
  return chave%TAM;
}

void inserir(Tabela *tabela, int dado){
  //gera o hash do local em que deve ser inserido o registro
  int hash = gerar_hash(dado);

  //Se ainda não existir registro na lista da hash criada, cria lista e insere o registro
  Registro* registro = new Registro;
  registro->dado = dado;
  registro->prox = NULL;
  if(tabela->registros[hash]  == NULL){
    tabela->registros[hash] = registro;
  }else{ //Já existe registro para o hash criado
    Registro* perc = tabela->registros[hash];
    Registro* ant = NULL;
    while(perc != NULL){ // percorre até encontar o final da lista, onde deve ser inserido o novo registro
      ant = perc;
      perc = perc->prox;
    }
    perc = registro;
    ant->prox = registro;
   }
}

void imprimir_tabela(Tabela *tabela){
  for(int i = 0; i < TAM; i++){
    cout << "HASH " << i << ": ";
    Registro* perc = tabela->registros[i];
    while(perc != NULL){
      cout << perc->dado << " ";
      perc = perc->prox;
    }
    cout << endl;
  }
}

Tabela* criar_tabela(){
  Tabela* tabela = new Tabela;
  for(int i = 0; i < TAM; i++)
    tabela->registros[i] = NULL;
  return tabela;
}

bool remover(Tabela *tabela, int dado){
  int hash = gerar_hash(dado);
  Registro* perc = tabela->registros[hash];
  Registro* ant = NULL;
  while(perc != NULL && perc->dado != dado){
    ant = perc;
    perc = perc->prox;
  }
  if (perc == NULL) return false;
  if(ant == NULL){
    tabela->registros[hash] = perc->prox;
  }else{
    ant->prox = perc->prox;
  }
  delete perc;
  return true;
}

int main() {
  Tabela* tabela = criar_tabela();
  inserir(tabela, 10);
  inserir(tabela, 20);
  inserir(tabela, 30);
  inserir(tabela, 1);
  inserir(tabela, 1000);
  inserir(tabela, 34);
  inserir(tabela, 21);
  inserir(tabela, 6);
  inserir(tabela, 2);

  imprimir_tabela(tabela);
  remover(tabela, 30);
  imprimir_tabela(tabela);

  return 0;
}
