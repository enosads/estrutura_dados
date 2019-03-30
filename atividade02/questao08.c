#include <stdio.h>

int fatorial(int x) {
    if ((x==1) || (x==0)) return 1;
    else  return fatorial(x-1)*x;
}

int main(){
    int a, b, combinacao;
    printf("Primeiro numero: ");
    scanf("%d", &a);
    if (a <= 0){
        printf("'A' nao pode ser igual a 0!");
        return;
    }
    printf("Segundo numero: ");
    scanf("%d", &b);
    if (b <= 0){
        printf("'B' nao pode ser igual a 0!");
        return;
    }
    if (a >= b) {
        combinacao = fatorial(a)/(fatorial(b) * fatorial(a-b));
    }else{
        combinacao = fatorial(b)/(fatorial(a) * fatorial(b-a));
    }
    
    printf("C(a, b)! = %d", combinacao);
    return 0;
}