#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n, a, b, contador = 0, aux = 1;
    printf("Valor de n: ");
    scanf("%d", &n);
    printf("Valor de a: ");
    scanf("%d", &a);
    printf("Valor de b: ");
    scanf("%d", &b);


    printf("Esses sao os %d primeiros multiplos de %d ou %d: ", n, a, b);
    while( contador != n){
        if (aux%a == 0 || aux%b == 0) {
            printf(" %d ",aux);
            contador++;
        }
        aux++;
    }

    return 0;
}
