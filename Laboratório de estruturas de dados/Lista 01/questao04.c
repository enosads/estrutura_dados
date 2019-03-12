#include <stdio.h>

int* metade_final(int *vet, int n){
    return &vet[(int)(n/2)]; /* como ta sendo feito um cast para int, no caso de n ser um numero impar,
                                será considerada apenas a parte interira */
}

int main(void)
{
    int vet[6] = {1, 2, 3, 4, 5,6};
    int *v = metade_final(vet, 6);
    printf("Valor: %d\n", v[0]);
    return 0;
}

//RESPOSTA: Imprimirá o primeiro número da segunda metade da lista, no caso: 4.