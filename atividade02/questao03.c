#include <stdio.h>

int main(void){
    int soma, val;
    soma = 0;
    printf("Digite os valores a serem somados (valor negativo para sair):\n");
    do{
        scanf("%d", &val);
        soma = soma + val;
    }while (val > 0);
        printf("%d\n", soma);
    return 0;
}