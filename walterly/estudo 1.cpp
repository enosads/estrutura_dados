#include <iostream>
#include <cstdlib>
#include <conio.h>

using namespace std;


struct vertice{
	char label;
	vertice* prox;
	bool visitado;
	struct aresta* adj;
	
	
};

struct aresta{
	vertice* destino;
	aresta* prox;
};

struct fila{
	vertice* dado;
	fila* prox;
	
};

void criar_fila(fila*& head){
	head - NULL;
}

void enfileirar(vertice* dado, fila *& head){
	if(head == NULL){
		fila* novo = new fila;
		novo->dado = dado;
		novo->prox = NULL;
		head = novo;
	}else{
		enfileirar(dado, head->prox);
	}
}

vertice* desenfileirar(fila*& head){
	vertice* dado = head->dado;
	fila* aux = head;
	head = head->prox;
	delete aux;
	return dado;
}

void inicializar(vertice*& vi){
	vi = NULL;
}

void adicionar_vertice(vertice*& vi, char label){
	
	if (vi == NULL){
		
		vi = new vertice;
		vi->label = label;
		vi->visitado = false;
		vi->prox = NULL;
		vi->adj = NULL;
		
	}else{
		adicionar_vertice(vi->prox, label);
	}
}

vertice* buscar_vertice(vertice* vi, char label){
	
	if(vi != NULL){
		if(vi->label == label){
			return vi;
		}else{
			return buscar_vertice(vi->prox, label);
		}
	}
	return NULL;
}

void andar_aresta(aresta*& adj, vertice*& y){
	
	aresta* novo = new aresta;
	novo->prox = NULL;
	if(adj == NULL){
		novo->destino = y;
		adj = novo;
	}else{
		andar_aresta (adj->prox, y);
	}
}

void adicionar_aresta(vertice*& vi, char x, char y){
	vertice* v = buscar_vertice(vi, x);
	vertice* v2 = buscar_vertice(vi, y);
	andar_aresta(v->adj, v2);	
}

void imprimir_profundidade(vertice* vi){
	if (vi != NULL){
		
		cout<<vi->label<<" - ";
		vi->visitado = false;
		aresta* adj = vi->adj;
		
		while(adj != NULL){
			if(adj->destino->visitado == false){
				
				imprimir_profundidade(adj->destino);
			}
		  adj = adj->prox;	
		}
	}
}

void imprimir_amplitude(vertice*vi){
	
	fila* head;
	criar_fila(head);
	cout<<vi->label<<" - ";
	vi->visitado = true;
	enfileirar(vi, head);
	
	while(head != NULL){
		vertice* v = desenfileirar(head);
		aresta* adj = v->adj;
		
		while(adj != NULL){
			if (adj->destino->visitado != true){
				enfileirar(adj->destino, head);
				cout<<adj->destino->label<<" - ";
				adj->destino->visitado = true;
			}
			adj = adj -> prox;
		}
	}
}




int main ()
{
   vertice* vi;
   inicializar(vi);
   adicionar_vertice(vi, 'a');
   adicionar_vertice(vi, 'b');
   adicionar_vertice(vi, 'c');
   
   adicionar_aresta(vi, 'a', 'b');
   adicionar_aresta(vi, 'a', 'c');
   
   imprimir_profundidade(vi);
   cout<<"\n\n"<<endl;
   imprimir_amplitude(vi);
}












