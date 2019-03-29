#include<stdio.h>

int fibonacci (int x){
	if (x==0 || x==1){
		return x;
	}
	else{
		return fibonacci(x-1)+fibonacci(x-2);
	}
}
int main(){
	int x;
    do{
        printf("Digite um numero (numero negativo para sair): ");
	    scanf("%d", &x);
        if (x < 0) {
            break;
        }
	    printf("O %d numero da sequencia de fibonacci e: %d\n", x, fibonacci(x));
    }while(x >= 0);
	return 0;
}