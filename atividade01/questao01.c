#include <stdio.h>

int main(int argc, char const *argv[])
{	
	//variavel ano e continuar para controlar o loop
	int ano, continuar = 1; 

	// enquanto a resposta do usuario ao final do calculo for igual a 1, o algoritmo sera repetido
	while(continuar == 1){ 

		//Pede um ano pelo teclado
		printf("\nDigite um ano: "); 

		// armazena o ano digitado na variavel ano
		scanf("%i", &ano); 

		// faz o teste para verificar se um ano e bissexto e imprimi a resposta
		if (ano % 4 == 0 && ano % 100 != 0 || ano % 400 == 0) 
			printf("\n%i e bissexto!\n", ano);
		else
			printf("\n%i nao e bissexto!\n", ano);

		//pergunta se o usuario quer repetir o teste com outro ano
		printf("\nTestar outro ano?\n1 para sim\n0 para nao\n:");
		
		//armazenar a resposta na variavel de controle continuar
		scanf("%i", &continuar);
	}
	return 0;
}