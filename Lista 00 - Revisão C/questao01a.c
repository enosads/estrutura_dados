#include <stdio.h>

int main(int argc, char const *argv[])
{
	//cria o vetor com 30 posicoes e variavel para o calculo da media
	int vetor[30], media = 0;

	//loop que pede os 30 valores e armazema em ordem de digitacao no vetor
	printf("Digite 30 numeros\n\n");
	for (int i = 0; i < 30; ++i)
	{
		printf("Numero %i: ", i+1);
		scanf("%i", &vetor[i]);

		/* cada da loop a variavel media é incrementada para depois ser feita
		 a divisão por 30 */
		media += vetor[i]; 
	}
	//aqui é feita a divisao
	media/=30;
	//exibe a media no terminal
	printf("\nA media vale %i\n", media);

	/*outro laco de 30 repeticoes, dessa vez para verificar quais valores sao 
	 superiores a media, e imprimi-los no terminal*/
	printf("Valores acima da media: ");
	for (int i = 0; i < 30; ++i)
		if (vetor[i] > media)
			printf("%i ", vetor[i]);

	return 0;
}