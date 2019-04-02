void selectionSort (int tam, int *vetor){ // Recebe tamanho e vetor
    int menor; // Pra armazenar o indice que tem o menor valor 
    int aux; //Pra auxiliar na troca

    //Os valores são trocados um por um, primeiro o menor valor vai para indice 0, depois o segundo menor valor valor vai para o indice 1 e assim até o final
    for(int i = 0; i < tam-1; i++){ //Os dois ultimos valores são ordenados ao mesmo tempo, por isso tam-1

        //busca o menor elemento no array
       menor = i;    
       for(int j = i+1; j < tam; j++){
           if (vetor[j] < vetor[menor]) {
               menor = j;
           }
    }
    //Faz a troca, da mesma forma que acontece no Bubble Sort
    aux = vetor[i]; 
    vetor[i] = vetor[menor];
    vetor[menor] = aux;
   }
}

int main(int argc, char const *argv[])
{
    printf("hello, world");
    return 0;
}

