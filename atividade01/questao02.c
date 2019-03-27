#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n, raiz, repetir = 1;
    int raiz_quadrada(int n);

    while(repetir == 1){
        printf("Deseja calcular a raiz de qual numero: ");
        scanf("%d", &n);
        raiz = raiz_quadrada(n);
        printf("\nA raiz de %i e %i\n", n, raiz);
        printf("\nCalcular outra raiz?\n1 para sim\n0 para nao\n:");

		scanf("%i", &repetir);
    }
    return 0;
}
int raiz_quadrada(int n){
    int aux = 1, raiz = 0;
    while(n > 0){
        raiz++;
        n -= aux;
        aux+=2;
    }
    if (n < 0) {
        printf("\nA raiz nao e exata! O resultado do calulo nao esta correto!");
    }
    return raiz;
}
