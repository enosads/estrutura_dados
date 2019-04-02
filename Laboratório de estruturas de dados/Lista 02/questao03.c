#include <stdio.h>
#include <stdlib.h>

struct aluno{
    char nome[20]; 
    int matricula; 
}; 

int main(){
    
    struct aluno alunos[3];
    
    or(int i = 0; i < 3; i++){
        printf("Aluno %d\n", i+1);
	    printf("Nome: ");
        setbuf(stdin,NULL);
        gets(alunos[i].nome);
        printf("matricula: ");
        scanf("%d", &alunos[i].matricula);
    }  f 
    
    char aluno[20];
    printf("Buscar aluno: ");
    setbuf(stdin, NULL);
    gets(aluno);

    for(int i = 0; i < 6; i++){
        if (strcmp(alunos, alunos[i].nome) == 0) {
            printf("%s esta na posicao %d", aluno, i);
            return 0;
        }
    }
    printf("%s nao esta no vetor", aluno);    
    return 0;
}