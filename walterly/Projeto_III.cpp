#include <iostream>

using namespace std;

int contador=0;

struct vertice{
	
	int num;
	struct aresta * adj;
	vertice * prox;
	bool visitado;	
};

struct aresta{
	aresta * prox;
	vertice * destino;
	int peso;
};

void inicializar(vertice *& vi){
	vi = NULL;
}

vertice * buscar_vertice(vertice * vi, int num){

	if (vi != NULL){
		if (vi->num == num){
			return vi;
		}else{
			return buscar_vertice(vi->prox, num);
		}	
	}
	return NULL;	
}

void adicionar_vertice(vertice *& vi, int num){

	if (vi==NULL){
		vi = new vertice;
		vi->num = num;
		vi->adj = NULL;
		vi->prox= NULL;
		vi->visitado = false;	
	}else{
		adicionar_vertice(vi->prox, num);
	}
}

 void andar_aresta (aresta *& adj, vertice *& v1){
 	
 	 aresta * novo = new aresta;
     novo->prox = NULL;
 	if(adj == NULL){
 		novo->destino= v1;
 		adj = novo;
	 }else{
	 	andar_aresta (adj->prox, v1);
	 }
 }
 

void adicionar_aresta(vertice *& vi, int x, int y){
	
	vertice* v = buscar_vertice(vi,x);
	vertice* v1 = buscar_vertice(vi,y);
	andar_aresta (v->adj, v1);	
}


int verificar_profundidade(vertice *& vi){
	
	if (vi != NULL){
				
		vi->visitado = true;
		aresta* adj = vi->adj;
		
		while (adj != NULL){
			if (adj->destino->visitado == false){
				
				verificar_profundidade(adj -> destino);
			}
			adj = adj->prox;
		}	
	}
}

int  verificar(vertice * vi){
  if (vi != NULL){
  	if (vi->visitado == true){
  		contador++;
	}
  	verificar(vi->prox);
  }
  return contador;	
}




int main ()
{
   
    int V, A, Ao, Ad, n=1;
    
     while (1){
     	vertice* vi;
     	inicializar(vi);
    	cin>>V;
    	cin>>A;
    	if (V==0 && A==0){
    		break;
		}
		
		for (int i=1;i<=V; i++){
		  adicionar_vertice	(vi, i);
		}
		for(int i=1; i<=A; i++){
			cin>>Ao;
			cin>>Ad;
			if (Ao == 0 && Ad == 0){
				break;
			}
			adicionar_aresta(vi, Ao, Ad);
			adicionar_aresta(vi, Ad, Ao);
		}
    	
    	verificar_profundidade(vi);
    	int cont = verificar(vi);
    	if (cont == V){
    		cout<<"Teste "<<n<<"\nnormal\n\n";
		}else{
		  cout<<"Teste "<<n<<"\nfalha\n\n";
	    }
   	    n++;
   	    contador = 0;
	}
}

