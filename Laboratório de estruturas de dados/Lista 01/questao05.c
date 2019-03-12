#include <stdio.h>

int main(void)
{
    int vet[6] = {1, 2, 3, 4, 5,6};
    printf("Valor1: %d\n", vet); //Será impresso o endereço de memoria apontado por ver
    printf("Valor2: %d\n", *vet); //Será impresso o primeiro dado armazenado no vetor vet: 1
    printf("Valor3: %d\n", *(vet+2)); //Será impresso o terceiro dado armazenado no vetor vet: 3
    return 0;
}

//RESPOSTA: Será impresso, respectivamente: endereco de vet, 1 e 3.