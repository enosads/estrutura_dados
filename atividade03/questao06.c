#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int matricula;
    char *nome;
    float u1;
    float u2;
    float media;
} Aluno;

typedef struct{
    Aluno alunos[15];
} Lista;


void insertionSort(Lista *l, int n){
    float media;
    Aluno aux;
    for(int i = 1; i < n; i++){
        media = l->alunos[i].media;
        aux = l->alunos[i];
        int j = i - 1;
        while(j >= 0 && l->alunos[j].media < media){
            l->alunos[j + 1] = l->alunos[j];
            j--;
        }
        l->alunos[j + 1] = aux;
    }
}

int main(){
    Lista *l = (Lista*) malloc(sizeof(Lista));
    char nomes[15][20] = {"Dennys Angelim", "Diego Barboza", "Ozivan Brito", "Dalison Carvalho", "Lucas Fernandes", "Severino Gomes", "Samaronia Lacerda", "Edberg Martins", "Felipe Maykon", "Alinne Oliveira", "Tamara Ramalho", "Washington Santos", "Joao Victor", "Joao Pedro", "Enos Andrade"};
    float u1[15] = {7.1, 7.5, 7.8, 7.4, 8.8, 8.65, 9.5, 8.1, 7.3, 10, 9, 8.7, 7.5, 8.5, 10};
    float u2[15] = {8, 8.5, 9, 7.5, 7.1, 8.8, 8.5, 7, 7.7, 9.2, 8.3, 8.9, 9.5, 7, 10};
    for(int i = 0; i < 15; i++){
        l->alunos[i].matricula = 2019101 + i;
        l->alunos[i].nome = nomes[i];
        l->alunos[i].u1 = u1[i];
        l->alunos[i].u2 = u2[i];
        l->alunos[i].media = (u1[i] + u2[i]) / 2;
    }
    insertionSort(l, 15);

    for(int i = 0; i < 10; i++){
        printf("\n=========== %do Lugar ===========\nNome: %s\nMatricula: %d\nMedia: %.1f\n", (i+1), l->alunos[i].nome, l->alunos[i].matricula, l->alunos[i].media);
    }
}
