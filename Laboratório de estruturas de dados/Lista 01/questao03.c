#include <stdio.h>

void imprime_primeiro(int *vet){
    printf("Valor: %d\n", vet[0]);
}

int main(int argc, char const *argv[])
{
    int vet[5] = {1, 2, 3, 4, 5};
    imprime_primeiro(&vet[2]);
    return 0;
}

//RESPOSTA: Imprime o terceiro dado armazenado no vetor vet, ou seja, 3.