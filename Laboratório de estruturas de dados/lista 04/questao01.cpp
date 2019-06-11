#include <iostream>

using namespace std;

struct Lista {
	int info;
	Lista* ant;
	Lista* prox;
};

Lista* criar_lista(){
  Lista* lista = new Lista;
  lista = NULL;
  return lista;
}

void inserir_inicio(Lista *&l, int info){
  Lista* novo = new Lista;
  novo->info = info;
  novo->prox = l;
	novo->ant = NULL;
	if(l != NULL)
		l->ant = novo;
  l = novo;
}

bool is_vazia(Lista *l){
  if(l == NULL)return true;
  return false;
}

Lista* buscar(Lista *l, int info){
  while(l != NULL && l->info != info)
    l = l->prox;
	return l;
}

bool remover(Lista *&l, int valor){
	Lista* p;
	Lista *aux = buscar(l, valor);
	if(l != NULL && aux != NULL){
		if(aux->prox != NULL)
			aux->prox->ant = aux->ant;
		if(aux->ant != NULL)
			aux->ant->prox = aux->prox;
		else
			l = aux->prox;
		delete aux;
		return true;
	}
	return false;

}

void imprimir(Lista *l){
  cout << "Lista: ";
  while(l != NULL){
    cout << l->info << " ";
    l =l->prox;
  }
}

int main() {
  Lista* l = criar_lista();
  imprimir(l);
  cout << "\nA lista esta vazia: " << is_vazia(l) << endl;
  inserir_inicio(l, 4);
  inserir_inicio(l, 6);
  inserir_inicio(l, 7);
  imprimir(l);
  bool deletado = remover(l, 6);
  cout << "\nO 6 foi deletado? "<< deletado;
  cout << endl;
  imprimir(l);
  return 0;
}
