#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include <cstdio>

using namespace std;

const int m = 26;

struct contato {
	string nome, tel;
	contato * prox;
};

struct indice {
	char letra;
	contato*ini;
	contato*fim;
};

int hashing (string nome){
	char let = tolower (nome[0]);
	return (int (let)- int ('a'))% m;
}

void inicializar (indice *& agenda){
	for (int i=0; i<m; i++){
	agenda[i].ini = NULL;
	agenda[i].fim = NULL;
	agenda[i].letra = char(i+int ('a'));
 }
}

void inserir (indice *& agenda, string nome, string tel){
contato * novo = new contato;
novo -> nome = nome;
novo -> tel = tel;
novo -> prox = NULL;
int i = hashing (nome);

if(agenda[i].ini == NULL){
	agenda[i].ini = novo;
	agenda[i].fim = novo;
	
}else{
	agenda[i].fim->prox = novo;
	agenda[i].fim = novo;
	}		
}

void imprimir (indice * agenda)
{	
	for (int i=0; i<m; i++)
	{
		contato * perc = agenda[i].ini;
		while(perc != NULL)
		{
		  cout<<"nome: "<<perc -> nome<<endl;
		  cout<<"telefone: "<<perc -> tel<<endl;
		  cout<<endl;
		
		  perc = perc -> prox;
		}
   }
}



contato * buscar (indice * agenda, string nome)
{
   int i = hashing (nome);
   contato * perc = agenda[i].ini;
   while (perc != NULL)
   {
   	  if (perc -> nome == nome)
   	  {
   	  	return perc;
	  }
	  perc = perc -> prox;
   }
}

void buscar_indice (indice * agenda, char let)
{
    int i = (int (let) - int ('a')) %m;
    contato * perc = agenda[i].ini;
    
   while (perc != NULL)
   {
      cout<<"nome: "<<perc -> nome<<endl;
	  cout<<"telefone: "<<perc -> tel<<"\n\n"<<endl;
	  perc = perc -> prox;
   }
}
	
int menu ()
    {
    	int op;
    	system("cls");
		cout <<"\n ____   MENU DA AVL         _____"<<endl;
		cout <<"|                                  |"<<endl;
		cout <<"|   1 - INSERIR CONTATO            |"<<endl;
		cout <<"|   2 - IMPRIMIR TODO              |"<<endl;
		cout <<"|   3 - BUSCAR CONTATO             |"<<endl;
		cout <<"|   4 - BUSCAR INDICE              |"<<endl;
	    cout <<"|   0 - SAIR                       |"<<endl;   
		cout <<"|                                  |"<<endl;                  
		cout <<"| Escolha uma das opcoes ...       |"<<endl;
		cout <<"|__________________________________|"<<endl;
		cin>> op;
		system("cls");
		return op;
	}
    
    void programa (indice * agenda)
    { 
        
		    int a =1, x;
		    string nome, telefone;
		    bool dis;
			while (a != 0)
			{
				switch (menu())
				{
				    case 1:
					    x = 1; 
					    cout<<"**********  INSERIR ELEMENTOS  ***********"<<endl;
					    while ( x == 1)
					    {
					       cout<< "  Informe o nome: ";
						   cin >> nome; 
						   cout<< "  Informe o telefone: ";
						   cin >> telefone; 
						   inserir (agenda, nome, telefone);

						   	cout<<"\n\n Ainda deseja inserir ???  1 = sim "<<endl;
							cin >> x;
							system("cls");	
						}
						  cout <<" Sua Agenda Final: \a\n"<<endl;
						  imprimir (agenda);
						  getch();
				    	a=1;
				    	break;
				    
				    case 2:
				    	cout<<"**********  IMPRIMIR  ***********\n\n\a"<<endl;
				    	imprimir (agenda);
				    	getch();
				    	a=1;
				    	break;
				    
				     case 3:
				     	cout<<"\a\n\n**********  BUSCAR  ***********\n"<<endl;
				     	cout<<" Informe o contato"<<endl;
				     	cin>>nome;
					     for (int i=0; i <=2; i++)
							{
								system ("cls");
								Sleep  (5);
								cout <<"\n   Buscando .  "<<endl;
								Sleep (200);
								system ("cls");
						    	cout <<"\n   Buscando . . "<<endl;
								Sleep (200);
								system ("cls");
								cout <<"\n   Buscando . . ."<<endl;
								Sleep (200);
								if( i == 2)
								{   
								    system("cls");
								    cout<<" Busca concluida !!! \n\a"<<endl;
									contato * aux = buscar (agenda, nome);
									if (aux != NULL){
										cout<<" Nome: "<< aux->nome<<endl;
										cout<<" Telefone: "<< aux->tel<<endl;
									}else{
										cout<<" Contato inexistente !!!"<<endl;
									}
									
							    }
							}
				     	getch(); 
				     	
				         a=1;
				        break;
				        
				    case 4:
				         	char letra;
				     	cout<<"\a\n\n**********  BUSCAR  ***********\n"<<endl;
				     	cout<<" Informe a letra: "<<endl;
				     	cin>>letra;
					     for (int i=0; i <=2; i++)
							{
								system ("cls");
								Sleep  (5);
								cout <<"\n   Buscando .  "<<endl;
								Sleep (200);
								system ("cls");
						    	cout <<"\n   Buscando . . "<<endl;
								Sleep (200);
								system ("cls");
								cout <<"\n   Buscando . . ."<<endl;
								Sleep (200);
								if( i == 2)
								{   
								    system("cls");
								    cout<<" Busca concluida !!! \n\a"<<endl;
									buscar_indice (agenda, letra);
							    }
							}
				     	getch(); 
				         a=1;
				        break;
				    
				     case 0:
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
	
	void iniciar_programa (indice * agenda)
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
			    programa(agenda);
		   }
		}
	}
 

int main()
{
	indice * agenda = new indice[m];
	inicializar (agenda);
	iniciar_programa (agenda);	
}
