#include <stdio.h>

int fatorial(int x) {
    if ((x==1) || (x==0)) return 1;
    else  return fatorial(x-1)*x;
}

int main(){
    int n;
    printf("Informe um numero: ");
    scanf("%d", &n);
    printf("%d! e %d", n, fatorial(n));
    return 0;
}