// ARVORES BINARIAS DE BUSCA (BST)
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include <fstream>

using namespace std;


struct noBiblioteca{
	
	int isbn;
	string nome;
	string autor;
	boolean dis;
	noBiblioteca * esq;
	noBiblioteca * dir; 
};

     void inserir (noBiblioteca *& Raiz, int isbn, string nome, string autor, boolean dis )
     {
     	if (Raiz == NULL)
     	{
     		Raiz = new noBiblioteca;
     		Raiz -> isbn = isbn;
			Raiz -> nome = nome;
			Raiz -> autor = autor;
			Raiz -> dis =  dis;
			Raiz -> esq = NULL;
			Raiz -> dir = NULL;
		}else
		{
			if (isbn < Raiz -> isbn)
			{
				inserir(Raiz->esq, isbn, nome, autor,dis);
			}else
		    {
			   if(isbn > Raiz -> isbn)
			   {
				  inserir(Raiz->dir, isbn, nome, autor, dis);
			   }
		    } 
	    }
    }

 noBiblioteca * localizar_menor(noBiblioteca *& Raiz)
 {
 	if (Raiz != NULL)
 	{
 		if (Raiz -> esq == NULL)
 		{
 			noBiblioteca * aux = Raiz;
 			Raiz = aux -> dir;
 			aux -> dir = NULL;
 			return aux;
 			
		}
 		return localizar_menor(Raiz -> esq);
	}
 }


 void remover(noBiblioteca*&Raiz,int isbn)
 {
   if(Raiz!=NULL)
   {
     if(isbn<Raiz->isbn)
	 {	
      remover(Raiz->esq,isbn);
      }else 
	  {
	  	if (isbn > Raiz -> isbn)
		{
      	remover(Raiz-> dir, isbn);
    	}else
    	{
    		if (Raiz ->esq == NULL && Raiz -> dir == NULL)
    		{
    			delete Raiz;
    			Raiz == NULL;
			}else
			{
				if (Raiz -> esq != NULL && Raiz -> dir == NULL)
				{
					noBiblioteca * aux = Raiz;
					Raiz = aux -> esq;
					delete aux;
				}else
				{
					if (Raiz -> dir != NULL && Raiz -> esq == NULL)
					{
						noBiblioteca * aux = Raiz;
					    Raiz = aux -> dir;
					    delete aux;
					}else
					{
						noBiblioteca * aux =NULL;
						aux = localizar_menor (Raiz -> dir);
						Raiz -> isbn = aux -> isbn;
						delete aux;
					}
				}
			}
		}
	  }
   }
 }
 

 noBiblioteca * buscar(noBiblioteca * Raiz, int dado)
 {
 	if (Raiz != NULL)
 	{
 		if (dado <  Raiz -> isbn)
 		{
 			return buscar (Raiz -> esq, dado);
		}else
		{
			if (dado > Raiz -> isbn)
			{
				return buscar (Raiz -> dir, dado);
			}else
			{
				return Raiz;
			}
		}	
	}	
 }
 
bool emprestar (noBiblioteca * Raiz, int dado)
 {
 	noBiblioteca * aux = buscar(Raiz, dado);
 	if (aux != NULL)
	 {
 		aux -> dis = false;
 		return true;	
	 }else{
	 	return false;
	 }	
 }
 
 bool devolver (noBiblioteca * Raiz, int dado)
 {
 	noBiblioteca * aux = buscar(Raiz, dado);
 	if (aux != NULL)
	 {
 		aux -> dis = true;
 		return true;	
	 }else{
	 	return false;
	 }	
 }
 
 bool imprimir_um (noBiblioteca * Raiz){
 	
 	if (Raiz != NULL)
	 {
	 	
     cout<<"\n nome : "<<      Raiz -> nome
		 <<"\n autor : "<<     Raiz -> autor
		 <<"\n codigo : "<<    Raiz -> isbn;
		 if(Raiz -> dis == true)
			{
			cout<< "\n Disponivel: sim";
			}else{
			cout<< "\n Disponivel: nao";
			}
 			return true;
	 }else
	 {
	    cout<<" Livro nao encontrado \a\a\a!!!"<<endl;
	    return false;
	 }	
 } 
 
 
 // ARQUIVOS EM C++: armazena e le arquivo no inicio e termino do programa
  void leitura (noBiblioteca *& raiz)
   {
   	    ifstream arql ("texto.txt");
   	    string autor;
   	    string titulo;
   	    int isbn;
   	    bool dis;
   	     while (!arql.eof())
   	     {
   	     	arql >> isbn;
   	     	arql >> autor;
   	     	arql >> titulo;
   	     	arql >> dis;
   	     	inserir (raiz, isbn,titulo,autor,dis);
		 }
		 arql.close();
   }
   
   void escrita (noBiblioteca * raiz)
   {
   	  if (raiz != NULL)
   	  {
   	  	  ofstream arqe ("texto.txt",ios::app);
   	  	  arqe << raiz -> isbn <<endl;
   	  	  arqe << raiz -> autor <<endl;
   	  	  arqe << raiz -> nome <<endl;
   	  	  arqe << raiz -> dis <<endl;
   	  	  arqe.close();
		  
		  escrita (raiz -> esq);	  
		  escrita (raiz -> dir);
	  }
   }   
 
    int menu ()
    {
    	int op;
    	system("cls");
		cout <<"\n ____   MENU DA BIBLIOTECA   _____"<<endl;
		cout <<"|                                  |"<<endl;
		cout <<"|   1 - CADASTRAR LIVRO            |"<<endl;
		cout <<"|   2 - REMOVER LIVRO              |"<<endl;
		cout <<"|   3 - BUSCAR LIVRO               |"<<endl;
		cout <<"|   4 - EMPRESTAR LIVRO            |"<<endl;
		cout <<"|   5 - DEVOLVER LIVRO             |"<<endl;
	    cout <<"|   6 - SAIR                       |"<<endl;   
		cout <<"|                                  |"<<endl;                  
		cout <<"| Escolha uma das opcoes ...       |"<<endl;
		cout <<"|__________________________________|"<<endl;
		cin>> op;
		system("cls");
		return op;
	}
    
    void programa (noBiblioteca * Raiz)
    { 
        
		    int a =1, x, isbn;
			string nome;
		    string autor;
			boolean dis;
			while (a != 0)
			{
				switch (menu())
				{
				    case 1:
					    x = 1;
					    dis = true; 
					    cout<<"**********  CADASTRANDO LIVROS  ***********"<<endl;
					    while ( x == 1)
					    {
					       cout<< "  Informe o titulo: ";
						   cin >>nome; 
						   cout<< "  Informe o codigo: ";
						   cin >>isbn; 
						   cout<< "  Informe o autor: ";
						   cin >>autor;
						   if(dis == true)
						   {
						   	cout<< "  Disponivel: sim";
						   }else{
						   	cout<< "  Disponivel: nao";
						   }
						   inserir (Raiz, isbn, nome, autor, dis);
						   
						   	cout<<"\n\n Ainda deseja inserir ???  1 = sim "<<endl;
							cin >> x;
							system("cls");	
						}
				    	a=1;
				    	break;
				    	
				    case 2:
				    cout <<"\n ***** REMOVENDO LIVRO ***** \n"<<endl;
						x = 1;
						while( x == 1)
						{ 
						    cout<<" Insira o codigo do livro "<<endl;
							cin >> isbn;
							boolean c = imprimir_um(buscar(Raiz, isbn));
							getch(); 
							if (c == false)
							{
								break;
							} 
								for (int i=0; i <=100; i++)
								{
									system ("cls");
									cout <<" Removendo : "<< i <<" %"<<endl;
									Sleep (100);
									if( i == 100)
									{   
									    remover (Raiz, isbn);
										cout<<"\n Elemento remvido com sucesso !!! \n\a\a"<<endl;
								    }
								}
							getch();
								
							cout<<" Ainda deseja remover ???  1 = sim "<<endl;
							cin >> x;
							system("cls");	
					    }
				    	a=1;
				    	break;
				    
				    case 3:
				    	cout<<"**********  BUSCANDO UM LIVRO  ***********"<<endl;
				    	x = 1;
						while( x == 1)
						{ 
						    cout<<" Insira o codigo do livro "<<endl;
							cin >> isbn;
								for (int i=0; i <=2; i++)
								{
									system ("cls");
									Sleep  (5);
									cout <<"\n   Buscando .  "<<endl;
									Sleep (500);
									system ("cls");
							    	cout <<"\n   Buscando . . "<<endl;
									Sleep (500);
									system ("cls");
									cout <<"\n   Buscando . . ."<<endl;
									Sleep (500);
									if( i == 2)
									{   
									    system("cls");
									    boolean c = imprimir_um(buscar(Raiz, isbn));
										getch(); 
										if (c == false)
										{
											break;
										} 
								    }
								}
								
							cout<<"\n Deseja continuar a busca ???  1 = sim "<<endl;
							cin >> x;
							system("cls");	
					    }
				    	a=1;
				    	break;
				    	
				    case 4:
				    	cout<<"**********  EMPRESTAR LIVRO  ***********"<<endl;
				    	x = 1;
						while( x == 1)
						{ 
						    cout<<" Insira o codigo do livro "<<endl;
							cin>> isbn;
							boolean c = imprimir_um(buscar(Raiz, isbn));
							getch(); 
							if (c == false)
							{
								break;
							} 
							 
								for (int i=0; i <=100; i++)
								{
									system ("cls");
									cout <<" processando : "<< i <<" %"<<endl;
									Sleep (20);
									if( i == 100)
									{   
									    emprestar (Raiz, isbn);
										cout<<"\n Realizado com sucesso !!! \n\a\a"<<endl;
								    }
								}
							getch();
								
							cout<<"\n Deseja continuar os emprestimos???  1 = sim "<<endl;
							cin >> x;
							system("cls");	
					    }
				    	a=1;
				    	break;
				    	
				    case 5:
				    	cout<<"**********  DEVOLVER LIVRO  ***********"<<endl;
				    	x = 1;
						while( x == 1)
						{ 
						    cout<<" Insira o codigo do livro "<<endl;
							cin>> isbn;
						    boolean c = imprimir_um(buscar(Raiz, isbn));
							getch(); 
							if (c == false)
							{
								break;
							} 
								for (int i=0; i <=100; i++)
								{
									system ("cls");
									cout <<" processando : "<< i <<" %"<<endl;
									Sleep (20);
									if( i == 100)
									{   
									    devolver (Raiz, isbn);
										cout<<"\n Realizado com sucesso !!! \n\a\a"<<endl;
								    }
								}
							getch();
								
							cout<<"\n Deseja continuar processando devolucoes???  1 = sim "<<endl;
							cin >> x;
							system("cls");	
					    }
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
										escrita (Raiz);
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
	
	void iniciar_programa (noBiblioteca * Raiz)
	{
		cout <<"\a    O PROGRAMA ESTA SENDO INICIADO !!!\a\n\n";
		getch();
		for (int i=0; i <=2; i++)
		{
			system ("cls");
			Sleep  (5);
			cout <<"\n   Carregando .  "<<endl;
			Sleep (400);
			system ("cls");
	    	cout <<"\n   Carregando . . "<<endl;
			Sleep (400);
			system ("cls");
			cout <<"\n   Carregando . . ."<<endl;
			Sleep (400);
			if( i == 2)
			{   
			    system("cls");
			    leitura (Raiz);
			    programa(Raiz);
		    }
		}
	}
 

int main()
{
	noBiblioteca * Raiz = NULL;	
	iniciar_programa (Raiz);	
}

