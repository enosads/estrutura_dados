#include <stdio.h>
int votos1, votos2, votos3, brancos, nulos, votantes;

void menu(){
    printf("\nO que deseja fazer? \n");
    printf("1 - Votar\n");
    printf("2 - Mostrar resultados\n");
    printf("3 - Comecar nova votacao\n");
    printf("0 - Sair do programa\n: ");
}
void votar(){
    int voto;
    printf("\nEm quem deseja votar?\n");
    printf("1 - Candidato 1\n");
    printf("2 - Candidato 2\n");
    printf("3 - Candidato 3\n");
    printf("4 - Votar nulo\n");
    printf("0 - Votar branco\n: ");
    scanf("%d", &voto);

    switch (voto){
        case 1: votos1++; votantes++; break;
        case 2: votos2++; votantes++; break;
        case 3: votos3++; votantes++; break;
        case 4: nulos++; votantes++; break;
        case 0: brancos++; votantes++; break;
        default: printf("\nVOTO INVALIDO"); break;
    }
}
void resultados(){
    printf("\nResultado da eleicao: \n\n");
    printf("Alunos votantes: %d\n", votantes);
    printf("Candidato 1: %d votos\n", votos1);
    printf("Candidato 2: %d votos\n", votos2);        
    printf("Candidato 3: %d votos\n", votos3);
    printf("Branco: %d votos\n", brancos);
    printf("Nulo: %d votos\n", nulos);
}
void zerarUrna(){
    votos1 = 0; votos2 = 0; votos3 = 0;  brancos = 0; nulos = 0; votantes = 0;
    printf("\nOs votos na urma foram zerados\n");
}
int main(){
    int opcao;
    do{
        menu();
        scanf("%d", &opcao);
        switch (opcao){
            case 1: votar(); break;
            case 2: resultados(); break;
            case 3: zerarUrna(); break;
            case 0: printf("\nSaindo do programa..."); break;
            default: printf("OPCAO INVALIDA!"); break;
        }
    } while (opcao!=0);
    return 0;
}