#include <stdio.h>
#include <malloc.h>
#define alturaMaxima 225

typedef struct{
	int altura;
	int peso;
}PesoAltura;

int main(){
	PesoAltura* pessoa1 = (PesoAltura*) malloc(sizeof(PesoAltura));
	pessoa1->peso = 80;
	pessoa1->altura = 185;
	printf("Peso: %i\nAltura: %i\n", pessoa1->peso, pessoa1->altura);
	if(pessoa1->altura > alturaMaxima) printf("Altura acima da maxima.\n");
	else printf("Altura abaixo da maxima.\n");
	return 0;
}
