// BALANCEAMENTO ESTÁTICO DE ARVORES BST
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
 // Verifica e retorna a altura da arvore... 
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
    
// Verifica se a arvore está balanceada ou nao...

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
	
   //cria um vetor com os elementos da arvore...
	
	void  criar_vetor (noArvore * raiz, int * vet, int & i){
		if (raiz != NULL)
		{
			criar_vetor (raiz -> esq, vet, i);
			vet [i] = raiz -> dado;
			i++;
			criar_vetor (raiz -> dir, vet, i);
		}
	}
	
// Apos criado o vetor, remove a antiga arvore...
	
	void remover_arvore (noArvore *& raiz){
		
		if (raiz != NULL){
		  remover_arvore (raiz->esq);
		  remover_arvore (raiz->dir);
		  delete raiz;
		  raiz = NULL;
		}
	}

// cria uma nova arvore a partir do vetor criado da antiga arvore 
	
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
	
// controla o processo de criar o vetor, remover a antiga arvore, criar uma nova arvore balanceada e deletar o vetor.	
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
	
// imprime os elementos da arvore pelo metoda "em ordem"
	
	void imprimir_em_ordem(noArvore * Raiz)
   {
   	if (Raiz != NULL)
	   {
	   		imprimir_em_ordem(Raiz->esq);
	   		cout<< " . " <<Raiz->dado;
	   		imprimir_em_ordem(Raiz->dir);	
       }
   } 
   
// imprime os elementos da arvore pelo metoda "pre ordem"

   void imprimir_pre_ordem(noArvore * Raiz)
   {
   	if (Raiz != NULL)
	   {	
	   		cout<< " . " <<Raiz->dado;
	   		imprimir_pre_ordem(Raiz->esq);
	   		imprimir_pre_ordem(Raiz->dir);	
       }
   } 




int menu ()
    {
    	int op;
    	system("cls");
		cout <<"\n ____   MENU DA BIBLIOTECA   _____"<<endl;
		cout <<"|                                  |"<<endl;
		cout <<"|   1 - INSERIR ELEMENTO           |"<<endl;
		cout <<"|   2 - CONTAR ELEMENTOS           |"<<endl;
		cout <<"|   3 - ALTURA                     |"<<endl;
		cout <<"|   4 - BALANCEAMENTO ESTATICO     |"<<endl;
		cout <<"|   5 - IMPRIMIR                   |"<<endl;
	    cout <<"|   6 - SAIR                       |"<<endl;   
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
						   inserir (Raiz, dado);
						   
						   	cout<<"\n\n Ainda deseja inserir ???  1 = sim "<<endl;
							cin >> x;
							system("cls");	
						}
						  cout <<" Sua Arvore: "<<endl;
						  imprimir_pre_ordem (Raiz);
						  getch();
				    	a=1;
				    	break;
				    	
				    case 2:
				    cout <<"\n ***** CONTANDO ELEMENTOS ***** \n"<<endl;
					       for (int i=0; i <=2; i++)
							{
								system ("cls");
								Sleep  (5);
								cout <<"\n   Contando .  "<<endl;
								Sleep (500);
								system ("cls");
						    	cout <<"\n   Contando . . "<<endl;
								Sleep (500);
								system ("cls");
								cout <<"\n   Contando . . ."<<endl;
								Sleep (500);
								if( i == 2)
								{   
								    system("cls");
								    cout<< "A Arvore possui: "<<contar(Raiz)<<" elementos"<<endl;
								    getch();
							    }
							}
				    	a=1;
				    	break;
				    
				    case 3:
				    	cout<<"**********  ALTURA  ***********"<<endl;
				    	cout<<"\n\n altura da arvore: "<<altura (Raiz)<<endl;
				    	getch();
				    	a=1;
				    	break;
				    
				    	
				    case 4:
				    	cout<<"**********  BALANCEAMENTO ESTATICO  ***********"<<endl;
				    	for (int i=0; i <=2; i++)
							{
								system ("cls");
								Sleep  (5);
								cout <<"\n   Balanceando .  "<<endl;
								Sleep (300);
								system ("cls");
						    	cout <<"\n   Balanceando . . "<<endl;
								Sleep (300);
								system ("cls");
								cout <<"\n   Balanceando . . ."<<endl;
								Sleep (300);
								if( i == 2)
								{   
								    system("cls");
								    balanceamento_estatico (Raiz);
								    
								    cout <<" Exibindo modificacoes: \n"<<endl;
								    cout<<" Pre ordem: ";imprimir_pre_ordem (Raiz);
								    cout<<"\n\n Em ordem: ";imprimir_em_ordem (Raiz);
								    getch();
							    }
						   }
				    	
				    	a=1;
				    	break;
				     case 5:
				     	cout<<"\a\n**********  IMPRIMINDO EM ORDEM  ***********\n\n"<<endl;
				     	
				     	imprimir_em_ordem (Raiz);
				     	getch(); 
				     	
				     	cout<<"**********  IMPRIMINDO PRE ORDEM  ***********\n\n"<<endl;
				     	
				     	imprimir_pre_ordem (Raiz);
				     	getch(); 
				     	
				         a=1;
				        break;
				     case 6:
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

