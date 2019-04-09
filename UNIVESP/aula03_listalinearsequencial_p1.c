#include <stdbool.h>

#define MAX 50

typedef int TIPOCHAVE;

typedef struct{
	TIPOCHAVE chave;	
	//Outros campos...
}REGISTRO;

typedef struct{
	REGISTRO A[MAX];
	int nroElem;
}LISTA;

void inicializarLista(LISTA* l){
	l->nroElem = 0;
}

int tamanho(LISTA *l){
	return l->nroElem;
}

void exibirLista(LISTA *l){
	int i;
	printf("Lista: \" ");

	for (int i = 0; i < l->nroElem; ++i)
		printf("%i ", l->A[i].chave);
	

	printf("\"\n");
}

int buscaSequencial(LISTA *l, TIPOCHAVE ch){
    int i = 0;
	while (i < l->nroElem){
		if (ch == l->A[i].chave) return i;
		else i++;
	}
	return -1; 
}

bool inserirElemLista(LISTA *l, REGISTRO reg, int i){
	if ((l->nroElem == MAX) || (i < 0) || (i > l->nroElem))
		return false;
	for (int j = l->nroElem; j > i;  j--)
		l->A[j] = l->A[j-1];

	l->A[i] = reg;
	l->nroElem++;
	return true;
}

bool excluirElemLista(TIPOCHAVE ch, LISTA* l){
	int pos = buscaSequencial(l, ch);
	if (pos == -1) return false;
	for (int j = pos; j < l-> nroElem -1; j++){
		l->A[j] = l->A[j+1];
	}
	l->nroElem--;
	return true;
}

void reinicializarLista(LISTA *l){
	l->nroElem = 0;
}

int main(int argc, char const *argv[])
{
	//Aloca memória para a lista
	LISTA *l = (LISTA *) malloc(sizeof(LISTA));
	//inicializa a lista 
	inicializarLista(l);
	//Exibe qtd de registros armazanados
	printf("Tamanho da lista: %i\n", tamanho(l));
	// criar dois registros
	REGISTRO r1, r2;
	// atribui uma chave para diferenciar os registros
	r1.chave = 1;
	r2.chave = 1234;
	//inseri o registro r1 5 vezes na lista na posicao 0 
	inserirElemLista(l, r1, 0);
	inserirElemLista(l, r1, 0);
	inserirElemLista(l, r1, 0);
	inserirElemLista(l, r1, 0);
	inserirElemLista(l, r1, 0);
	//inseri o registro r2 na lista na posicao 4
	inserirElemLista(l, r2, 4);
	///Exibe qtd de registros armazanados
	printf("Tamanho da lista: %i\n", tamanho(l));
	//Busca o indice onde r2 foi armazenado
	printf("O registro esta na posicao %i\n",buscaSequencial(l,1234));
	//Exclui r2 da lista
	bool teste = excluirElemLista(1234, l);
	//testa se r2 foi realmente estava na lista e se foi excluido
	if (teste == 1)	
	{
		printf("Elemento excluido\n");
	}else{
		printf("Elemento nao excluido\n");
	}
	///Exibe qtd de registros armazanados
	printf("Tamanho da lista: %i\n", tamanho(l));
	//Reinicia lista 
	reinicializarLista(l);
	///Exibe qtd de registros armazanados
	printf("Tamanho da lista, depois de reinicializada: %i\n", tamanho(l));
	return 0;
}
