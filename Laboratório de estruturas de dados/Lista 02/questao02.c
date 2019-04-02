#include <stdio.h>

int main(){
    char pessoa[20];
    char pessoas[15][20] = {"Alinne", "Dalison", "Dennys", "Edberg", "Enos", "Francisco", "Felipe", "Joao", "Lucas", "ozivan", "Pablo", "Samaronia", "Severino", "Tamara", "Washington"};

    printf("Buscar nome: ");
    gets(pessoa);

    for(int i = 0; i < 15; i++){
        if (strcmp(pessoa, pessoas[i]) == 0) {
            printf("%s esta na posicao %d", pessoa, i);
            return 0;
        }
    }
    printf("%s nao esta no vetor", pessoa);
    return 0;
}