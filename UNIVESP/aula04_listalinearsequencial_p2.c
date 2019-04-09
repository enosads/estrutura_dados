#include <stdbool.h>
#include <stdlib.h>

#define MAX 50

typedef int TIPOCHAVE;

typedef struct{
	TIPOCHAVE chave;	
	//Outros campos...
}REGISTRO;

typedef struct{
	REGISTRO A[MAX+1];
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
int buscaSentinela(LISTA *l, TIPOCHAVE ch){
    int i = 0;
    l->A[l->nroElem].chave = ch;
    while(l->A[i].chave != ch) i++;
    if (i == l->nroElem) return -1;
    else return i;
}
int buscaBinaria(LISTA *l, TIPOCHAVE ch){
    int esq = 0;
    int dir = l->nroElem;
    int meio;
    while (esq <= dir){
        meio = (esq + dir)/2;
        if (ch == l->A[meio].chave) return meio;
        else if(ch < l->A[meio].chave) dir = meio-1;
        else esq = meio+1;
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
bool inserirElemListaOrd(LISTA *l, REGISTRO reg){
    if (l->nroElem >= MAX) return false;
    int pos = l->nroElem;
    while(pos > 0 && l->A[pos-1].chave > reg.chave){
        l->A[pos] = l->A[pos-1];
        pos--;
    }
    l->A[pos] = reg;
    l->nroElem++;
}
bool excluirElemLista(TIPOCHAVE ch, LISTA* l){
	int pos = buscaSequencial(l, ch);
	if (pos == -1) return false;
	for (int j = pos; j < l-> nroElem -1; j++) l->A[j] = l->A[j+1];
	l->nroElem--;
	return true;
}
void reinicializarLista(LISTA *l){
	l->nroElem = 0;
}
int main(){
	//Aloca memória para a lista
	LISTA *l = (LISTA *) malloc(sizeof(LISTA));
	//inicializa a lista 
	inicializarLista(l);
	//Exibe qtd de registros armazanados
	printf("Tamanho da lista: %i\n", tamanho(l));
	// criar dois registros
	REGISTRO r1, r2, r3, r4;
	// atribui uma chave para diferenciar os registros
	r1.chave = 1;
	r2.chave = 1234;
	r3.chave = 434;
	r4.chave = 4532;
	inserirElemListaOrd(l, r2);
	inserirElemListaOrd(l, r1);
	inserirElemListaOrd(l, r3);
	inserirElemListaOrd(l, r4);
	printf("Tamanho da lista: %i\n", tamanho(l));
	exibirLista(l);
	///Exibe qtd de registros armazanados
	printf("Tamanho da lista: %i\n", tamanho(l));
	//Busca o indice onde r2 foi armazenado
	printf("O %d registro esta na posicao %i\n", r2.chave,buscaBinaria(l,r2.chave));
	//Exclui r2 da lista
	bool teste = excluirElemLista(r2.chave, l);
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