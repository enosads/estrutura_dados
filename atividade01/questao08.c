#include <stdio.h>

int main(int argc, char const *argv[]){
    float a1, a2, a3, media;

    //Recebe nota das avaliacoes do usuario
    printf("Informe as notas de tuas avaliacoes:\nAvaliacao 1: ");
    scanf("%f", &a1);
    printf("Avaliacao 2: ");
    scanf("%f", &a2);
    printf("Avaliacao 3: ");
    scanf("%f", &a3);
    
    //Faz o calculo da media e exibe
    media = (a1 + a2 + a3)/3;
    printf("A media e %.1f\n", media);

    //Calcular a situacao do aluno
    printf("Situacao: ");
    if (media >= 7) {
        printf("APROVADO");
    }else{
        if (media >= 5) {
            printf("RECUPERACAO"); 
        }else{
            printf("REPROVADO");
        }
    }
}