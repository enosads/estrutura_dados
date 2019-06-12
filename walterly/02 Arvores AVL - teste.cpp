// BALANCEAMENTO DINAMICO - AVL
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <windows.h>

using namespace std;
//Nó da arvore
   struct noArvore
   {
	  int dado;
	  int eq;
	  noArvore * dir;
	  noArvore * esq;
   };
   
 

    int altura(noArvore * raiz){
    	
		if(raiz == NULL)
		{
			return -1;
		}
		int ale = altura (raiz->esq);
		int ald = altura (raiz->dir);
		if(ale>ald)
		{
			return 1 + ale;
		}
		return 1+ald;
   } 
   
   	void rotacao_direita(noArvore *& raiz)
	{	
		noArvore *q, *temp;
		q = raiz->esq;
		temp = q->dir;
		q->dir = raiz;
		raiz->esq = temp;
		q->eq = altura(q->dir)-altura(q->esq); //Atualiza o eq
		raiz->eq = altura(raiz->dir)-altura(raiz->esq); //Atualiza o eq
		raiz = q; //Atualiza a raiz
    }
    
    void rotacao_esquerda(noArvore *& raiz)
	{	
		noArvore *q, *temp;
		q = raiz->dir;
		temp = q->esq;
		q->esq = raiz;
		raiz->dir = temp;
		q->eq = altura(q->dir)-altura(q->esq); //Atualiza o eq
		raiz->eq = altura(raiz->dir)-altura(raiz->esq); //Atualiza o eq
		raiz = q; //Atualiza a raiz
    }
    

    void inserir_avl (noArvore *& raiz, int dado){
    	
    	if (raiz == NULL){
    		
    		raiz = new noArvore;
    		raiz -> dado = dado;
    		raiz -> esq = NULL;
    		raiz -> dir = NULL;
    		raiz -> eq = 0;
		}else{
			if (dado < raiz->dado){
				inserir_avl (raiz -> esq, dado);
				
				raiz->eq = altura (raiz -> dir) - altura (raiz->esq);// atualiza o fator de equilibrio
				 if (raiz->eq == -2){
				 	if(raiz->esq->eq == -1){
				 		rotacao_direita (raiz);
					 }else{
					 	rotacao_esquerda (raiz->esq);
					 	rotacao_direita (raiz); 
					 }
				 }  
			}else{
				if (dado > raiz->dado){
					inserir_avl(raiz -> dir, dado);
					
				 raiz->eq = altura (raiz -> dir)-altura (raiz->esq);// atualiza o fator de equilibrio
				 if (raiz->eq == 2){
				 	if(raiz->dir->eq == 1){//anterior: raiz -> esq -> eq == 1
				 		rotacao_esquerda (raiz);
					 }else{
					 	rotacao_direita (raiz->dir);//anterior: raiz -> esq
					 	rotacao_esquerda (raiz); 
					 }
				 } 
				}
			}
		}	
	}
	

    void imprimir_pre_ordem (noArvore * raiz){
    	
    	if (raiz != NULL)
		{
    		cout<< raiz -> dado << " - ";
    		imprimir_pre_ordem (raiz->esq);
    		imprimir_pre_ordem (raiz->dir);
		}	
	}






int main ()
{
	noArvore * raiz  = NULL;

	
	inserir_avl (raiz, 8);
	imprimir_pre_ordem (raiz);
	cout<<endl;
	cout<<endl;
	inserir_avl (raiz, 12);
	imprimir_pre_ordem (raiz);
	cout<<endl;
	cout<<endl;
	inserir_avl (raiz, 4);
	imprimir_pre_ordem (raiz);
	cout<<endl;
	cout<<endl;
	inserir_avl (raiz, 15);
	imprimir_pre_ordem (raiz);
	cout<<endl;
	cout<<endl;
	inserir_avl (raiz, 9);
	imprimir_pre_ordem (raiz);
	cout<<endl;
	cout<<endl;
	inserir_avl (raiz, 10);
	cout<<endl;
	cout<<endl;
	imprimir_pre_ordem (raiz);
	
}

