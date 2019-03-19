#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "Portuguese");
    int busca;
    int vetor[] = {12, 43, 15, 38, 1, 44, 9, 45, 34, 35, 42, 23, 3, 4, 2, 33, 17, 20, 40, 27}; //vetor pre definido
    printf("Buscar o numero: ");
    scanf("%d", &busca);
    for(int i = 0; i < sizeof(vetor)/sizeof(int); i++){
        if (busca  == vetor[i]) {
            printf("O numero buscado esta na posicao %d do vetor", i);
            return;
        }
    }
    printf("Esse numero nao esta na lista");

    return 0;
}
