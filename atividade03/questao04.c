#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int mat;//Matricula do aluno
    char *nome;//nome do aluno
    float nota;//valor da nota
} Aluno;

//Lista estática
typedef struct {
    int qtdeAlunos;//quantidade de alunos
    Aluno alunos[30];
} Lista;

int menorNota(Lista *l){
    int posicao = 0;
    if (l->qtdeAlunos > 0){
        for(int i = 1; i < l->qtdeAlunos; i++){
            if (l->alunos[i].nota < l->alunos[posicao].nota) {
                posicao = i;
            }
        }
        return posicao;
    }
    return -1;
}

int main(){
    Lista *l = (Lista*) malloc(sizeof(Lista));
    l->qtdeAlunos = 4;
    char nomes[4][10]={"Enos", "Alinne", "Irineu", "Danilo"};
    for(int i = 3; i >= 0; i--){
        l->alunos[i].nome = nomes[i];
        l->alunos[i].mat = 20191 + i;
        l->alunos[i].nota = (i+1)*2;
    }

    int posicao = menorNota(l);
    if (posicao != -1) {
        printf("\nAluno com a menor nota \n");
        printf("Nome: %s\n", l->alunos[posicao].nome);
        printf("Matricula: %d\n", l->alunos[posicao].mat);
        printf("Nota: %.1f\n", l->alunos[posicao].nota);

    }else printf("A lista esta vazia");
}
