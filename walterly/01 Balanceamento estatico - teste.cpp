// BALANCEAMENTO ESTÁTICO DE ARVORE
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <windows.h>

using namespace std;
//Nó da arvore
   struct noArvore
   {
	  int dado;
	  noArvore * dir;
	  noArvore * esq;
   };

 
   
   
   //Insere um elemento na arvore...
   void inserir (noArvore *& Raiz, int dado)
   {
   	   if (Raiz == NULL)
	   {
   		   Raiz = new noArvore;
   		   Raiz -> dado = dado;
   		   Raiz -> esq = NULL;
   		   Raiz -> dir = NULL;
   	   }else
   	   {
   	   	  if (dado < Raiz -> dado)
   	   	  {
   	   	  	  inserir (Raiz -> esq, dado);
   	   	  }else
   	   	  {
   	   	  	  if (dado > Raiz -> dado)
   	   	  	  {
   	   	  	  	 inserir (Raiz -> dir, dado);
   	   	  	  }
   	   	  }
   	   }
   }
   
    int contar (noArvore * Raiz)
   {
	   	if (Raiz == NULL)
		{
	   		return 0;
	   	}else
		{
			return 1 + contar (Raiz -> esq) + contar (Raiz -> dir);
	   	}
   }
   
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
   
    bool balanceada (noArvore * raiz)
    {
    	if (raiz == NULL)
    	{
    		return true;
		}
		int AE = altura (raiz -> esq);
		int AD = altura (raiz -> dir);
		
		if ((AE - AD) <= 1 && (AE - AD) >= -1 
		&& balanceada (raiz -> esq) && balanceada (raiz -> dir))
		{
		    return true;	
		}
		return false;
	}
	
	void  criar_vetor (noArvore * raiz, int * vet, int & i){
		if (raiz != NULL)
		{
			criar_vetor (raiz -> esq, vet, i);
			vet [i] = raiz -> dado;
			i++;
			criar_vetor (raiz -> dir, vet, i);
		}
	}
	
	void remover_arvore (noArvore *& raiz){
		
		if (raiz != NULL){
		  remover_arvore (raiz->esq);
		  remover_arvore (raiz->dir);
		  delete raiz;
		  raiz = NULL;
		}
	}
	
	void criar_arvore (noArvore *& raiz, int * vet, int ini, int fim){
		
		if (ini <= fim){
			int meio = (ini+fim)/2;
			raiz = new noArvore;
			raiz -> dado = vet [meio];
			raiz -> esq = NULL;
			raiz -> dir = NULL; 
			criar_arvore (raiz->esq, vet, ini, meio-1); 
			criar_arvore (raiz->dir, vet, meio+1, fim);	
		}	
	}
	
	
	void balanceamento_estatico (noArvore *& raiz){
		if (!balanceada (raiz)){
			
			int tam = contar(raiz);
			int * vet = new int [tam];
			int i = 0;
			criar_vetor (raiz, vet, i);
			remover_arvore (raiz);
			criar_arvore (raiz, vet, 0, tam-1);
			delete [] vet;
		}	
	}
	
	
	void imprimir_em_ordem(noArvore * Raiz)
   {
   	if (Raiz != NULL)
	   {
	   		imprimir_em_ordem(Raiz->esq);
	   		cout<< " . " <<Raiz->dado;
	   		imprimir_em_ordem(Raiz->dir);	
       }
   } 
   
   	void imprimir_pre_ordem(noArvore * Raiz)
   {
   	if (Raiz != NULL)
	   {
	   		
	   		cout<< " . " <<Raiz->dado;
			imprimir_pre_ordem(Raiz->esq);
	   		imprimir_pre_ordem(Raiz->dir);	
       }
   } 

int main ()
{
	noArvore * Raiz = NULL;
	 
	 inserir (Raiz, 10);
	 inserir (Raiz, 21);
	 inserir (Raiz, 35);
	 inserir (Raiz, 42);
	 inserir (Raiz, 56);
	 imprimir_em_ordem (Raiz);
	 cout<<endl;
	 balanceamento_estatico (Raiz);
	 cout<<endl;
	 cout<<" Balanceamento estatico"<<endl;
	 imprimir_em_ordem (Raiz);
	  cout<<endl;
	 imprimir_pre_ordem (Raiz);
	 cout<<endl;	
}
