#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


struct noArvore{
	int dado;
	noArvore * esq;
	noArvore * dir;
};

void imprimir_pre_ordem (noArvore*raiz){
	if(raiz != NULL)
	{		
		cout<<raiz->dado;
		imprimir_pre_ordem(raiz->esq);
		imprimir_pre_ordem(raiz->dir);
	}
	
}

void imprimir_em_ordem(noArvore * raiz)
{
	if(raiz!= NULL)
	{
		imprimir_em_ordem(raiz->esq);
		cout<<raiz->dado;
		imprimir_em_ordem(raiz->dir);
	}	
}

void imprimir_pos_ordem(noArvore*raiz){
	if(raiz!=NULL){
	imprimir_pos_ordem(raiz->esq);
	imprimir_pos_ordem(raiz->dir);
	cout<<raiz->dado;
	}
	
}

void inserir(noArvore *&raiz, int dado){
	if (raiz == NULL)
	{
		raiz = new noArvore;
		raiz->dado = dado;
		raiz->esq = NULL;
		raiz->dir = NULL;
	}
	
		else if (dado < raiz->dado)
		{
		inserir(raiz->esq, dado);
	    }
	    
			else if(dado>raiz->dado)
			{				
			inserir(raiz->dir, dado);
		    }
	
}

int cont (noArvore*raiz){
	if(raiz == NULL){
		return 0;
	}else
	return 1 + cont(raiz->esq) + cont (raiz -> dir);
	
}

int soma (noArvore * raiz){
	if(raiz == NULL){
		return 0;
	}
	else	
	return raiz->dado + soma(raiz->esq) + soma(raiz->dir);
}

int maior (noArvore * raiz){
	if(raiz != NULL){
		if(raiz->dir == NULL){
		return raiz->dado;
	}
		else{
	    return maior(raiz->dir);
	}
	return 0;	
	}
	
	
}

int menor (noArvore * raiz){
	if(raiz != NULL){
		if(raiz->esq == NULL){
		return raiz->dado;
	}else
		return menor(raiz->esq);
	}
	return 0;
}

bool verificar_numero(noArvore * raiz, int dado)
{
	if(raiz){
		
		if(raiz->dado == dado)
			return true;
		else if(dado > raiz->dado)
		{
			return verificar_numero(raiz->dir, dado);	
		}	
		else if(dado < raiz->dado)
		{
			return verificar_numero(raiz->esq, dado);
		}	
		return false;

	}
		
}
// retorna o elemento informado pelo usuario 
noArvore * buscar (noArvore * raiz, int dado){
	
	if(raiz!= NULL){
		
		if(dado<raiz->dado){ // dado menor retorna o que esta na direita;
			
			return buscar(raiz->esq, dado);
		}
		else if(dado > raiz->dado)
		{
			return buscar(raiz->dir, dado);
		}else
		{
			return raiz;
		}	
	}
}

noArvore * Pega_Menor (noArvore *&raiz){
	if(raiz!= NULL){
		if(raiz->esq == NULL){
			noArvore * aux = raiz;
			raiz = aux->dir;
			aux->dir = NULL;
			return aux;
		}
		return Pega_Menor(raiz->esq);
	}
}

void Remover (noArvore *& raiz, int dado){
	if(raiz!= NULL){
		if(dado < raiz->dado){
			Remover(raiz->esq, dado);	
		}		
		else if(dado > raiz->dado){
			Remover(raiz->dir,dado);
		}
		else{
			if(raiz->esq == NULL && raiz->dir == NULL){
				delete raiz;
				raiz = NULL;
			}
			else if(raiz->esq != NULL && raiz->dir == NULL){
				noArvore * aux = raiz;
				raiz = aux->esq;
				delete aux;
			}else if(raiz ->dir != NULL && raiz->esq == NULL){
				noArvore * aux = raiz;
				raiz = aux->dir;
				delete aux;
			}else{
				noArvore * aux = Pega_Menor(aux->dir);
				raiz->dado = aux->dado;
				delete aux;
			}
		}
	}	
}

int altura(noArvore * raiz){
	if(raiz== NULL)
		return -1;
	int ale = altura (raiz->esq);
	int ald = altura (raiz->dir);
	if(ale>ald)
		return 1 + ale;
	return 1+ald;
}
bool balanceada (noArvore * raiz){
	if(raiz == NULL)
		return true;
		int ae = altura(raiz->esq);
		int ad = altura(raiz->dir);
		if((ae - ad)<= 1 && (ae - ad) >=1 &&balanceada(raiz->esq) && balanceada(raiz->dir))
			return true;
		return false;
}
void remover_arvore (noArvore*&raiz){
	if(raiz!=NULL){
		remover_arvore(raiz->esq);
		remover_arvore(raiz->dir);
		delete raiz;
		raiz=NULL;
	}
	
	
}
void criar_vetor(noArvore*raiz,int*vet,int&i){
	if(raiz!=NULL){
		criar_vetor(raiz->esq,vet,i);
		vet[i] = raiz->dado;
		i++;
		criar_vetor(raiz->dir,vet,i);
	}
	
}
void criar_arvore(noArvore*raiz,int*vet,int ini, int fim){
	if(ini<=fim){
		int meio = (ini+fim)/2;
		raiz= new noArvore;
		raiz->dado = vet[meio];
		criar_arvore(raiz->esq,vet,ini,fim);
		criar_arvore(raiz->dir,vet,ini,fim);
	}
}

bool balanceamento_statico(noArvore*&raiz){
	if(!balanceada(raiz)){
		int tam = cont(raiz);
		int*vet = new int[tam];
		int i = 0;
		criar_vetor(raiz,vet,i);
		remover_arvore(raiz);
		criar_arvore(raiz,vet,0,tam-1);
		delete [] vet;
	}
	}




void menu (){
	
	cout<<" 1 - Inserir"<<endl;
	cout<<" 2 - Em ordem"<<endl;
	cout<<" 3 - Pre ordem"<<endl;
	cout<<" 4 - Pos ordem"<<endl;
	cout<<" 5 - Soma"<<endl;
	cout<<" 6 - Numero de nos"<<endl;
	cout<<" 7 - Maior numero da arvore"<<endl;
	cout<<" 8 - Menor numero da arvore"<<endl;
	cout<<" 9 - Verificar numero da arvore"<<endl;
	cout<<"10 - Mostrar numeros presentes na arvore"<<endl;
	cout<<"11 - Buscar elemento na arvore"<<endl;
	cout<<"12 - Remover elemento na Arvore"<<endl;
	cout<<"13 - balanceamento statico"<<endl;
	cout<<"14 - altura"<<endl;
	cout<<" 0 - Sair"<<endl;
	
}

void mostrar_arvore(noArvore*raiz){
	
	cout<<"Numeros da arvore: "	;
	if(raiz == NULL)
		cout<<"arvore vazia";
		else
		imprimir_em_ordem(raiz);	
}

void opcoes (noArvore* raiz, int op){
 int  valor;
 noArvore * aux;
		while (op != 0)
	{
		switch(op)
		{
			case 1:
				char parada;
				cout<<"Deseja adicionar um numero a arvore?s ou n?"<<endl;
				cin>>parada;
					while(parada =='s')
					{
					cout<<"Informe um valor: ";
					cin>>valor;
					inserir(raiz,valor);
					cout<<"Deseja adicionar um numero a arvore?s ou n?"<<endl;
					cin>>parada;
					system("cls");
					}
			
			break;
				
			case 2:
				cout<<"Em ordem : ";
				imprimir_em_ordem(raiz);
				cout<<endl;
				system("pause");
				system("cls");
				
			break;
				
			case 3:
				cout<<"Pre ordem : ";
				imprimir_pos_ordem(raiz);
				cout<<endl;
				system("pause");
				system("cls");
			
			
			break;
				
			case 4:
				cout<<"Pos ordem : ";
				imprimir_pre_ordem(raiz);				
				cout<<endl;
				system("pause");
				system("cls");
				
			break;
				
			case 5:
			cout<<"A soma e: "<<soma(raiz)<<endl;
			system("pause");
			system("cls");
			
			break;
			
			case 6:
				cout<<"A quantidade de nos e "<<cont(raiz)<<endl;
				system("pause");
				system("cls");
				
			break;
			
			case 7:
				cout<<"O maior numero e: " <<maior(raiz)<<endl;
				system("pause");
				system("cls");	
			break;
			
			case 8:
				cout<<"O menor numero e :" <<menor(raiz)<<endl;		
				system("pause");
				system("cls");	
			break;	
			
			case 9:
				cout<<"Informe um numero para verificar se existe"<<endl;
				cin>>valor;
				
				if(verificar_numero(raiz, valor)){
					cout<<"- Valor existe -"<<endl;
					cout<<endl;
				}
					else
						cout<<"- Valor Inexistente -"<<endl;
						cout<<endl;
				system("pause");
				system("cls");
			break;
			
			case 10:
				mostrar_arvore(raiz);
				cout<<endl;
				system("pause");
				system("cls");
			case 11:
				cout<<"Informe o numero"<<endl;
				cout<<"NUMERO: ";
				cin>>valor;
				cout<<"-----------------------"<<endl;
				aux = buscar(raiz,valor);
				if(aux)
				{
				cout<<"NUMERO  : "<<aux->dado<<endl;
			
				}else
					cout<<"Nao existe"<<endl;
				
				cout<<"-----------------------"<<endl;
				break;
			break;
			case 12:
				cout<<"Informe um elemento para deletar"<<endl;
				cin>>valor;
				aux = buscar(raiz,valor);
				if(aux){
					Remover(raiz,valor);
					cout<<"Valor deleteado"<<endl;
				}
					
					else
					cout<<"Valor não existe"<<endl;
				break;
					
			case 13:
				balanceamento_statico(raiz);
			break;
			case 14:
				cout<<altura(raiz);
				cout<<endl;
				system("pause");
				break;	
		}
	
	menu();
    cin>>op;
		
	}
	
	
}

void inicializar (noArvore* raiz){
	int op;
	menu();	
	cin>>op;
	opcoes(raiz,op);
}

int main(int argc, char** argv) {
	noArvore * raiz = NULL;
	inicializar(raiz);
		for (int n=0; n<=100; n++) {
   					 cout <<"Saindo em : "<< n << "% ";
   					 system("cls");
 	}
 		
			
	
EXIT_SUCCESS;	
}
