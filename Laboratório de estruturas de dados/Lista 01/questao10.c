#include <stdio.h>

int main(int argc, char const *argv[])
{
    int busca(int vet[], int n, int x);
    int vetor[50];
    //ler valor do vetor
    int valorDigitado;
    for(int i = 0; i < 50; i++)
    {
        printf("\nValor %d: ", i + 1);
        scanf("%d", &valorDigitado);
        if (valorDigitado == 0) {
            break;
        }else{
            vetor[i] = valorDigitado;
        }
    }
    printf("\nBuscar o numero: ");
    scanf("%d", &valorDigitado);
    int isNumberInList = busca(vetor, 50, valorDigitado);
    if (isNumberInList == 1) {
        printf("O numero %d esta na lista", valorDigitado);
    }else{
        printf("O numero %d nao esta na lista", valorDigitado);
    }
    return 0;
}
int busca(int vet[], int n, int x){
    for(int i = 0; i < n; i++){
        if (x == vet[i]) {
            return 1;
        }
        
    }
    return 0;
}