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
	
int menu ()
    {
    	int op;
    	system("cls");
		cout <<"\n ____   MENU DA AVL         _____"<<endl;
		cout <<"|                                  |"<<endl;
		cout <<"|   1 - INSERIR ELEMENTO           |"<<endl;
		cout <<"|   2 - ALTURA                     |"<<endl;
		cout <<"|   3 - IMPRIMIR                   |"<<endl;
	    cout <<"|   4 - SAIR                       |"<<endl;   
		cout <<"|                                  |"<<endl;                  
		cout <<"| Escolha uma das opcoes ...       |"<<endl;
		cout <<"|__________________________________|"<<endl;
		cin>> op;
		system("cls");
		return op;
	}
    
    void programa (noArvore * Raiz)
    { 
        
		    int a =1, x, isbn;
			int dado;
		    string autor;
		    bool dis;
			while (a != 0)
			{
				switch (menu())
				{
				    case 1:
					    x = 1;
					    dis = true; 
					    cout<<"**********  INSERIR ELEMENTOS  ***********"<<endl;
					    while ( x == 1)
					    {
					       cout<< "  Informe o elemento: ";
						   cin >> dado; 
						   inserir_avl (Raiz, dado);
						   cout<<"\n"<<endl;
						   imprimir_pre_ordem (Raiz);
						   
						   	cout<<"\n\n Ainda deseja inserir ???  1 = sim "<<endl;
							cin >> x;
							system("cls");	
						}
						  cout <<" Sua Arvore Final: \n"<<endl;
						  imprimir_pre_ordem (Raiz);
						  getch();
				    	a=1;
				    	break;
				    
				    case 2:
				    	cout<<"**********  ALTURA  ***********"<<endl;
				    	cout<<"\n\n altura da arvore: "<<altura (Raiz)<<endl;
				    	getch();
				    	a=1;
				    	break;
				    
				     case 3:
				     	cout<<"\a\n\n**********  IMPRIMINDO  ***********\n"<<endl;
				     	cout<<" Processo pre-ordem.\n"<<endl;
				     	
				     	imprimir_pre_ordem (Raiz);
				     	getch(); 
				     	
				         a=1;
				        break;
				        
				        
				     case 4:
				    		cout<<"\n   O PROGRAMA ESTA SENDO ENCERRADO !!!\a\n\n";
						    cout<< " Deseja realmente encerrar ? '1'- sim , '0'- nao"<<endl;
						    cin >> x;
						    if (x == 0)
							{
								a=1;
							}
							else
						    {
						    	if (x == 1)
								{
									for (int i=5; i >=0; i--)
									{
										system ("cls");
										cout <<"  O PROGRAMA SERA ENCERRADO EM : 0"<< i <<" segundos"<<endl;
										Sleep (1000);
									}
									a=0;
								}
								else
							    {
							       cout<<"\n Opcao invalida !!!\a"<<endl;
							       getch();
								   a=1;	
							    }
							
							}
				    	break;
				    	
				    	
				    default:
				    	 cout<<"\n   OPCAO INVALIDA !!!\a\a"<<endl;
					     getch();
					     a=1;
				    break;
				}	
		   }
	}
	
	void iniciar_programa (noArvore * Raiz)
	{
		cout <<"\a    O PROGRAMA ESTA SENDO INICIADO !!!\a\n\n";
		getch();
		for (int i=0; i <=2; i++)
		{
			system ("cls");
			Sleep  (5);
			cout <<"\n   Carregando .  "<<endl;
			Sleep (200);
			system ("cls");
	    	cout <<"\n   Carregando . . "<<endl;
			Sleep (200);
			system ("cls");
			cout <<"\n   Carregando . . ."<<endl;
			Sleep (200);
			if( i == 2)
			{   
			    system("cls");
			    programa(Raiz);
		    }
		}
	}
 

int main()
{
	noArvore * Raiz = NULL;	
	iniciar_programa (Raiz);	
}

