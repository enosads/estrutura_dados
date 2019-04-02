#include <stdio.h>

int main(){
    int n, numerador = 1;
    float s;

    printf("Informe o valor de n: ");
    scanf("%d", &n);

    for(int i = n; i >= 1; i--){
        s += numerador/i;
        numerador++;
    }
    printf("O valor de S e: %f", s);
    return 0;
}
