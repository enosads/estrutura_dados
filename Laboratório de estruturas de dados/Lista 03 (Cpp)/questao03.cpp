#include <iostream>
#include <string.h>

using namespace std;

struct Contato{
  string nome;
  string telefone;
  string aniversario;
};

struct Elemento{
  Contato info;
  Elemento *prox;
};

struct Lista{
  int qtd;
  Elemento* inicio;
};

void cria_agenda(Lista *&l){
  l->inicio = NULL;
  l->qtd = 0;
}

void insere_contato(Lista *&l, Contato c){
  Elemento* ant = NULL;
  Elemento* atual = l->inicio;
  Elemento* novo = new Elemento;
  novo->info = c;
  for (int i = 0; i < l->qtd; i++) {
    if (novo->info.nome.compare(atual->info.nome) <= 0) break;
    ant = atual;
    atual = atual->prox;
  }
  if (ant == NULL) {
    novo->prox = l->inicio;
    l->inicio = novo;
  }else{
    novo->prox = ant->prox;
    ant->prox = novo;
  }
  l->qtd++;
}

void lista_contatos(Lista *l){
  cout << "\n------------------- LISTAR CONTATOS -------------------\n";
  Elemento *e = l->inicio;
  int i = 1;
  if(l->qtd > 0){
    while(e != NULL){
      cout << i << " - Nome: " << e->info.nome << " - Telefone: " << e->info.telefone << " - Aniversario: " << e->info.aniversario << endl;
      e = e->prox;
      i++;
    }
  }else{
    cout << "Voce ainda nao inseriu contatos na agenda\n";
  }
}

Elemento* busca_contato(Lista *l, string busca, int *n){
  Elemento *e = l->inicio;
  for (int i = 0; i < l->qtd; i++) {
    if (e->info.nome.compare(busca) == 0) {
      *n = i+1;
      return e;
    }
    e = e->prox;
  }
  return NULL;
}

void remove_contato(Lista *&l, Elemento *e){
  Elemento *ant = NULL;
  Elemento *atual = l->inicio;
  while (atual != NULL && atual != e) {
    ant = atual;
    atual = atual->prox;
  }
  if (ant == NULL) l->inicio = atual->prox;
  else ant->prox = atual->prox;
  free(atual);
  l->qtd--;
}

void remove_duplicados(Lista *&l){
  cout << "\n------------------- REMOVER CONTATOS DUPLICADOS -------------------\n";
  if (l->qtd <= 1) {
    cout << "\nNenhum contato duplicado!\n";
    return;
  }
  Elemento *e = l->inicio;
  Elemento *prox = e->prox;
  int qtd = 0;
  while (e != NULL) {
    while (prox != NULL) {
      if (e->info.nome.compare(prox->info.nome) == 0 && e->info.telefone.compare(prox->info.telefone) == 0 && e->info.aniversario.compare(prox->info.aniversario) == 0) {
        Elemento *aux = prox;
        remove_contato(l, prox);
        prox = aux->prox;
        qtd++;
      }else prox = prox->prox;
    }
    e = e->prox;
    if(e->prox == NULL) break;
    prox = e->prox;
  }
  cout << "\n" <<qtd<< " contatos foram removidos\n";
}

//implementação
void inserirContato(Lista *l){
  cout << "\n------------------- INSERIR CONTATO -------------------\n";
  Contato contato;
  string nome, telefone, aniversario;
  cout << "Nome: ";
  cin >> contato.nome;
  cout << "Telefone: ";
  cin >> contato.telefone;
  cout << "Data em que faz aniversario: ";
  cin >> contato.aniversario;
  insere_contato(l, contato);
  cout << "\nContato inserido com sucesso!\n";
}

Elemento* buscarContato(Lista *l){
  cout << "\n------------------- BUSCAR CONTATO -------------------\n";
  string busca;
  cout << "Nome do contato: ";
  cin >> busca;
  int n;
  Elemento *resposta = busca_contato(l, busca, &n);
  if (resposta == NULL) {
    cout << "\nContato nao encontrado!\n";
  }else{
    cout << "\nO contato esta na posicao " << n << " da agenda\n";
    cout << n << " - Nome: " << resposta->info.nome << " - Telefone: " << resposta->info.telefone << " - Aniversario: " << resposta->info.aniversario << "\n";
  }
  return resposta;
}

void removerContato(Lista *l){
  if (l->qtd == 0) {
    cout << "\nVoce ainda nao inseriu contatos na agenda\n";
    return;
  }
  Elemento *e = buscarContato(l);
  if(e == NULL) return;
  int resposta = -1;
  cout << "\n------------------- REMOVER CONTATO -------------------\n";
  do{
    cout << "\nDeseja realmente remover o contato? [1 - SIM / 0 - NAO]: ";
    cin >> resposta;
    if(resposta != 1 && resposta != 0)
      cout << "\nOPCAO INVALIDA!\n";
  }while (resposta != 1 && resposta != 0);
  if(resposta == 0) cout << "O contato nao foi removido\n";
  else{
    remove_contato(l, e);
    cout << "O contato foi removido\n";
  }
}

void editarContato(Lista *l){
  if(l->qtd == 0){
      cout << "\nVoce ainda nao inseriu contatos na agenda\n";
      return;
  }
  Elemento *e = buscarContato(l);
  if(e == NULL) return;
  int resposta = -1;
  cout << "\n------------------- EDITAR CONTATO -------------------\n";
  remove_contato(l, e);
  Contato contato;
  string nome, telefone, aniversario;
  cout << "Nome: ";
  cin >> contato.nome;
  cout << "Telefone: ";
  cin >>contato.telefone;
  cout << "Data de aniversario: ";
  cin >> contato.aniversario;
  insere_contato(l, contato);
  cout << "\nContato editado com sucesso!\n";
}

void menu(){
    cout << "\n------------------- MENU -------------------\n";
    cout << "1 - Inserir contato\n";
    cout << "2 - Listar contatos\n";
    cout << "3 - Buscar contatos\n";
    cout << "4 - Editar contato\n";
    cout << "5 - Remover contato\n";
    cout << "6 - Remover contatos duplicados\n";
    cout << "7 - Sair do programa\n: ";
}
int main(){
  Lista* l = new Lista;
  cria_agenda(l);
  int resposta;
  do{
      menu();
      cin >> resposta;
      switch (resposta){
          case 1: inserirContato(l); break;
          case 2: lista_contatos(l); break;
          case 3: buscarContato(l); break;
          case 4: editarContato(l); break;
          case 5: removerContato(l); break;
          case 6: remove_duplicados(l); break;
          case 7: cout << "\nSaindo do programa..."; break;
          default: cout << "\nOPCAO INVALIDA!\n"; break;
      }
  }while(resposta != 7);
  return 0;
}
