#include <stdio.h>
#define alturaMaxima 225

typedef struct{
	int altura;
	int peso;
}PesoAltura;

int main(){
	PesoAltura pessoa1;
	pessoa1.peso = 80;
	pessoa1.altura = 185;
	printf("Peso: %i\nAltura: %i\n", pessoa1.peso, pessoa1.altura);
	if(pessoa1.altura > alturaMaxima) printf("Altura acima da m�xima.\n");
	else printf("Altura abaixo da m�xima.\n");
	return 0;
}
