#include <stdio.h>

void imprime_primeiro(int *vet){
    printf("Valor: %d\n", vet[0]);
}

int main(int argc, char const *argv[])
{
    int vet[5] = {1, 2, 3, 4, 5};
    imprime_primeiro(vet);
    return 0;
}

/*RESPOSTA: Imprime o primeiro dado armazenado no vetor vet, ou seja, 1.

    Obs: Apesar de o operador & não esta sendo usado, um array é sempre um 
        ponteiro para o primeiro dado do mesmo, logo o parâmetro para a 
        função imprime_primeiro() está sendo passado por referência.*/
