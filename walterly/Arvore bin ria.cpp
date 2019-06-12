#include <iostream>
#include <conio.h>
#include <cstdlib>
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
   
   
   //Imprime com o procedimento pré-ordem...
   void imprimir_pre_ordem (noArvore * Raiz)
   {
   	if (Raiz != NULL)
	   {
	   		cout<< " . " <<Raiz->dado;
	   		imprimir_pre_ordem(Raiz->esq);
	   		imprimir_pre_ordem(Raiz->dir);	
       }
   } 
   
   
   //Imprime com o procedimento em-ordem...
   void imprimir_em_ordem(noArvore * Raiz)
   {
   	if (Raiz != NULL)
	   {
	   		imprimir_em_ordem(Raiz->esq);
	   		cout<< " . " <<Raiz->dado;
	   		imprimir_em_ordem(Raiz->dir);	
       }
   } 
   
   //Imprime com o procedimento pós-ordem...
   void imprimir_pos_ordem(noArvore * Raiz)
   {
   	if (Raiz != NULL)
	   {
	   	    imprimir_pos_ordem(Raiz->esq);
	   	    imprimir_pos_ordem(Raiz->dir);
			cout<< " . " <<Raiz->dado;	
       }
   } 
   
   //Retorna a quntidade de nós da arvore...
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
   
   //Retorna a soma de todos os nós da arvore...
   int somar (noArvore * Raiz)
   {
   	  if (Raiz == NULL)
   	  {
   	  	 return 0;
   	  }else
   	  {
   	  	 return Raiz -> dado + somar (Raiz ->esq) + somar (Raiz -> dir);
   	  }
   }
   
   // Busca e retorna true se o elemento existir na arvore...
   /*noArvore * buscar (noArvore * Raiz, int num)
   {
   	   if ( Raiz != NULL && num == Raiz -> dado )
   	   {
   	   	   return raiz;
   	   }else
   	   { 
   	   	  if (num < Raiz -> dado)
   	   	  {
   	   	  	  return buscar (Raiz -> esq, num);
   	   	  }else
   	   	  {
   	   	  	  if (num > Raiz -> dado)
   	   	  	  {
   	   	  	  	return buscar (Raiz -> dir, num);
   	   	  	  }
   	   	  }
	   }
   }*/
   
   // Retorna o maior nó da arvore...
   int maior (noArvore * Raiz)
   {
		if (Raiz -> dir != NULL)
		{
			maior (Raiz -> dir);
		}else
		{
		    return Raiz -> dado;
		}
   }
   
    int menor (noArvore * Raiz)
   {
		if (Raiz -> esq != NULL)
		{
		    return maior (Raiz -> esq);
		}else
		{
			return Raiz -> dado;
		}
   }
   
   //Remove um elemento da arvore;
   
   noArvore * localizar_menor (noArvore *& Raiz)
   {
   	  if (Raiz != NULL)
   	  {
   	  	if (Raiz -> esq == NULL)
   	  	{
   	  		noArvore * aux = Raiz;
   	  		Raiz = aux -> dir;
   	  		aux -> dir == NULL;
   	  		return aux;	
		}
		return localizar_menor(Raiz -> esq);
	  }
   }
   
   void remover (noArvore *& Raiz, int dado)
   {
   	    if (Raiz != NULL)
   	    {
   	     	if (dado < Raiz -> dado)
   	    	{
   	    		remover (Raiz -> esq, dado);
		    }else
		    {
		    	if (dado > Raiz -> dado)
		    	{
		    		remover (Raiz -> dir, dado);
				}else
				{
					if (Raiz -> esq == NULL && Raiz -> dir == NULL)
					{
						delete Raiz ;
						Raiz = NULL;	
					}else
					{
						if (Raiz -> esq != NULL && Raiz -> dir == NULL)
						{
							noArvore * aux = Raiz;
							Raiz = aux -> esq;
							delete aux;
						}else
						{
							if (Raiz -> dir != NULL && Raiz -> esq == NULL)
							{
								noArvore * aux = Raiz;
								Raiz = aux -> dir;
								delete aux;	
							}else
							{
								noArvore * aux = localizar_menor(Raiz -> dir);
								Raiz -> dado = aux -> dado;
								delete aux;	
							}
						}
					}	
				}
			}
		}
   }
   
//CÓDIGO PRINCIPAL 
int main ()
{
   noArvore * raiz = NULL;
   
   inserir (raiz, 2);
   inserir (raiz, 3);
   inserir (raiz, 0);
   inserir (raiz, 7);
   inserir (raiz, 1);
   inserir (raiz, 5);
   imprimir_pre_ordem (raiz);
   cout<<endl;
   cout<<endl;
   imprimir_em_ordem  (raiz);
   cout<<endl;
   cout<<endl;
   imprimir_pos_ordem (raiz);
   cout<<"\n"<<endl;
   cout<< "---------- DADOS DA ARVORE -----------------"<<endl;
   cout<<endl;
   cout<<" Quantidade de elementos: "<<contar (raiz)<<endl;
   cout<<" \n"<<endl;
   cout<<" A soma dos elementos: "<< somar (raiz) <<endl;
   cout<<" \n"<<endl;
   cout<<" O maior elemento: "<< maior (raiz) <<endl;
   cout<<" \n"<<endl;
   cout<<" O menor elemento: "<< menor (raiz) <<endl;
    
    
   
   
   
  
   
   
}

