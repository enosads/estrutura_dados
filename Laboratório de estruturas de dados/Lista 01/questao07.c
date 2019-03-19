#include <stdio.h>

int main(int argc, char const *argv[])
{
    int busca;
    int posicao = 0;
    int contador = 0;
    int vetor[] = {12, 43, 15, 38, 1, 44, 9, 45, 34, 35, 42, 23, 3, 4, 2,
     33, 17, 20, 40, 27, 12, 45, 12, 15, 44, 42, 34}; //vetor pre definido

    printf("Buscar o numero: ");
    scanf("%d", &busca);
    int i;
    for(i = 0; i < sizeof(vetor)/sizeof(int); i++){
        if (busca  == vetor[i]) {
            contador++;
            posicao = i;
        }
    }
    if (posicao == 0) {
        printf("Esse numero nao esta na lista");
    }else{
        printf("O numero buscado aparece %d vezes na lista\nA ultima ocorrencia esta na posicao %d do vetor", contador,i);
    }
    return 0;
}
