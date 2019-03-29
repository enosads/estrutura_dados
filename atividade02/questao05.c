#include<stdio.h>

int primo(int n){
    int contador = 1;
    for(int i = 2; i <= n; i++){
        if (n % i == 0) {
            contador++;
        }
    }
    if (contador == 2) {
        return 1;
    }
    return 0;
}

int main(){
    int primo(int n);
    int n1, n2;
    printf("Informe o intervalo \nDe: ");
    scanf("%d", &n1);
    printf("ate: ");
    scanf("%d", &n2);
    
    printf("Numeros primos: ");
    if (n1 <= n2) {
        for(int i = n1; i <= n2; i++){
            if(primo(i)){
                printf("%d ", i);
            }
        }
    }else{
        for(int i = n2; i <= n1; i++){
            if(primo(i)){
                printf("%d ", i);
            }
        }
    }
	return 0;
}