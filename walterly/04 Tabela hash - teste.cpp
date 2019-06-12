#include <iostream>
#include <cstdlib>
#include <conio.h>

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

int main ()
{
	indice * agenda = new indice [m];
	inicializar (agenda);
	inserir (agenda, "walter", "4444-0000");
	inserir (agenda, "a", "0000-0000");
	inserir (agenda, "z", "0000-0000");
	inserir (agenda, "e", "0000-0000");
	cout<<"\n\a"<<endl;
	imprimir (agenda);
	cout<<"\n\a"<<endl;
	contato * aux = buscar (agenda, "walter");
	cout<<" busca conluida!!!\n\n"<< aux->nome<<"\n"<<aux->tel;
}

