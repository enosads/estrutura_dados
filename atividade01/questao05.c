#include <stdio.h>

int main(int argc, char const *argv[])
{
	char nome[30];
	float salario, prestacao;

	printf("Nome: ");
	scanf("%s", &nome);
	printf("Salario bruto: ");
	scanf("%f", &salario);
	printf("Valor da prestacao do emprestimo: ");
	scanf("%f", &prestacao);
	printf("Enos, voce teve o ");
	if (prestacao <= 0.3f * salario)
		printf("credito concedido\n");
	else
		printf("credito negado\n" );
	return 0;
}