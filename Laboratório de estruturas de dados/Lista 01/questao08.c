#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "Portuguese");
    int maximo;
    int vetor[] = {12, 43, 15, -456, 38, 1, 44, 9, 45, 34, 35, 42, 23, 3, 4, 2,
     33, 17, 20, 1042, 27, 12, 1500, 12, 15, 44, 42, 100, 127, 0, -200}; //vetor pre definido

    for(int i = 0; i < sizeof(vetor)/sizeof(int); i++){
        if (i  == 0) {
            maximo = vetor[i];
        }else{
            if (vetor[i] > maximo) {
                maximo = vetor[i];
            }
            
        }

    }
    printf("O valor maximo do vetor e %d.", maximo);
    
    
    

    return 0;
}
