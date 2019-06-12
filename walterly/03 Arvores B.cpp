#include <iostream>
#include <stdlib.h>

using namespace std;

const int M = 2;
const int MAX_CHAVES = 2 * M; //Quantidade m�xima de chaves
const int MAX_FILHOS = (2 * M)+1; //Quantidade m�xima de filhos
const int MIN_OCUP = M; //Ocupa��o m�nima em cada n�

struct ArvoreB {
     int num_chaves; //Quantidades de chaves contida no n�
     int chaves[MAX_CHAVES]; //Chaves armazenadas no n�
     ArvoreB *filhos[MAX_FILHOS]; //Ponteiro para os filhos
};

/*
	* Criar o main;
	* Inserir alguns elementos;
	* Criar o m�todo de impress�o em ordem.
*/


int busca_binaria(ArvoreB *no, int info){
	int meio, i, f;
	i = 0;
	f = no->num_chaves-1;

	while (i <= f){
		meio = (i + f)/2;
		if (no->chaves[meio] == info)
			return(meio); //Encontrou. Retorna a pos���o em que a chave est�.
		else if(no->chaves[meio] > info)
			f = meio - 1;
		else
			i = meio + 1;
	}
	return(i); //N�o encontrou. Retorna a posi��o do ponteiro para o filho.
}

//Insere uma chave e o ponteiro para o filho da direita em um n�
void insere_chave(ArvoreB *raiz, int info, ArvoreB *filhodir){
     int k, pos;

  	//busca para obter a posi��o ideal para inserir a nova chave
  	pos = busca_binaria(raiz, info);
  	k = raiz->num_chaves;

  	//realiza o remanejamento para manter as chaves ordenadas
	while (k > pos && info < raiz->chaves[k-1]){
		raiz->chaves[k] = raiz->chaves[k-1];
		raiz->filhos[k+1] = raiz->filhos[k];
		k--;
	}
	//insere a chave na posi��o ideal
	raiz->chaves[pos] = info;
	raiz->filhos[pos+1] = filhodir;
	raiz->num_chaves++;
}

//Realiza a busca do n� para inserir a chave e faz as subdivis�es quando necess�rias
ArvoreB *insere(ArvoreB *raiz, int info, bool *h, int *info_retorno){
	int i, j, pos, info_mediano; //auxiliar para armazenar a chave que ir� subir para o pai
	ArvoreB *temp, *filho_dir; //ponteiro para o filho � direita da chave

	if (raiz == NULL){
		//O n� anterior � o ideal para inserir a nova chave (chegou em um n� folha)
		*h = true;
		*info_retorno = info;
		return(NULL);
   	}else{
		pos = busca_binaria(raiz,info);
        if (raiz->num_chaves > pos && raiz->chaves[pos] == info){
			cout << "Chave j� contida na �rvore";
			*h = false;
		}else{
			//desce na �rvore at� encontrar o n� folha para inserir a chave.
			filho_dir = insere(raiz->filhos[pos],info,h,info_retorno);
			if (*h){ //Se true deve inserir a info_retorno no n�.
				if (raiz->num_chaves < MAX_CHAVES){ //Tem espa�o na p�gina
					insere_chave(raiz, *info_retorno, filho_dir);
					*h = false;
				}else{ //Overflow. Precisa subdividir
					ArvoreB * temp = new ArvoreB();
					temp->num_chaves = 0;

					//inicializa filhos com NULL
					for (i = 0; i < MAX_FILHOS; i++)
						temp->filhos[i] = NULL;

					//elemento mediano que vai subir para o pai
					info_mediano = raiz->chaves[MIN_OCUP];

					//insere metade do n� raiz no temp (efetua subdivis�o)
					temp->filhos[0] = raiz->filhos[MIN_OCUP+1];
					for (i = MIN_OCUP + 1; i < MAX_CHAVES; i++)
						insere_chave(temp, raiz->chaves[i], raiz->filhos[i+1]);

					//atualiza n� raiz.
					for (i = MIN_OCUP; i<MAX_CHAVES; i++){
						raiz->chaves[i] = 0;
						raiz->filhos[i+1] = NULL;
					}
					raiz->num_chaves = MIN_OCUP;

					//Verifica em qual n� ser� inserida a nova chave
					if (pos <= MIN_OCUP)
						insere_chave(raiz, *info_retorno, filho_dir);
					else
						insere_chave(temp, *info_retorno, filho_dir);

					//retorna o mediano para inser�-lo no n� pai e o temp como filho direito do mediano.
					*info_retorno = info_mediano;
					return(temp);
                }
            }
        }
    }
}

void *insere_arvoreB(ArvoreB *&raiz, int info){
	bool h;
	int info_retorno, i;
	ArvoreB *filho_dir, *nova_raiz;

	filho_dir = insere(raiz,info,&h,&info_retorno);
	if (h){ //Aumetar� a altura da �rvore
		nova_raiz = new ArvoreB;
		nova_raiz->num_chaves = 1;
		nova_raiz->chaves[0] = info_retorno;
		nova_raiz->filhos[0] = raiz;
		nova_raiz->filhos[1] = filho_dir;
		for (i = 2; i <= MAX_CHAVES; i++)
			nova_raiz->filhos[i] = NULL;
		raiz = nova_raiz;
	}
}

bool pesquisa(ArvoreB * raiz, int x){
    if (raiz == NULL)
        return false;
    else{
        int i = 1;
        while ((i < raiz->num_chaves) && (x > raiz->chaves[i]))
            i++;
        if (x == raiz->chaves[i])
            return true;
        else if (x < raiz->chaves[i])
            return pesquisa(raiz->filhos[i-1], x);
        else
            return pesquisa(raiz->filhos[i], x);
    }
}

int main ()
{
	
	
ArvoreB * raiz = NULL;
 
inserir_arvoreB(raiz, 2);
 
inserir_arvoreB(raiz, 2);
 
inserir_arvoreB(raiz, 2);	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
