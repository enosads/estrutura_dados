#include<stdio.h>

int main(){
	float lado1, lado2, lado3;
	
	printf("Digite um valor para o lado 1: ");
	scanf("%f", &lado1);
	printf("Digite um valor para o lado 2: ");
	scanf("%f", &lado2);
	printf("Digite um valor para o lado 3: ");
	scanf("%f", &lado3);
	
	if(((lado1+lado2)>lado3) && ((lado1+lado3)>lado2) && ((lado2+lado3)>lado1) ){
		if(lado1== lado2 && lado1==lado3){
			printf("e equilatero!");
		}else if(lado1==lado2 || lado1==lado3 || lado2==lado3){
			printf("e isoceles!");
		}else if(lado1!=lado2!=lado3 && lado1!=lado3){
			printf("e escaleno!");
		}
	}else{
		printf("Nao e triangulo!");
	}
}