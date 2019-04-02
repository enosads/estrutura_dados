//O bubbleSort recebe como parâmetros o tamanho e o ponteiro para o vetor
void bubbleSort(int tamanho, int *vetor){
    //Variavel aux pra armazenar temporariamente um dos números a serem trocados
    int aux; 
    //Este primeiro loop tem como objetivo verificar quantas vezes será preciso fazer o loop interno. A quantidade vai depender do tamanho do vetor, visto que a cada loop externo o maior número do vetor é colocado no último índice. E por isso ele é ignorado no loop seguinte.
    for(int fim = tamanho-1; fim > 1; fim--){
        //Este loop interno faz as verificações e, caso necessário, as trocas
        for(int index = 0; index < fim; index++){
            //Verifica se o valor do vetor no index corrente(vetor[index]) é maior que o posterior(vetor[index+1]). Caso verdadeiro fará a troca de posição.
            if (vetor[index] > vetor[index+1]) {
                // aux armazenará o valor armazenado no índice corrente
                aux = vetor[index]; 
                //O valor do índice posterior será a atribuido ao corrente
                vetor[index] = vetor[index+1]; 
                // O valor da variavel aux, que armazena o valor original do corente, será atribuído ao posterior
                vetor[index+1] = aux; 
            }
        }
    }
}