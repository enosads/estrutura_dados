#include <stdio.h>

int main(int argc, char const *argv[])
{
    int minimo;
    int vetor[] = {12, 43, 15, -456, 38, 1, 44, 9, 45, 34, 35, 42, 23, 3, 4, 2,
     33, 17, 20, 1042, 27, 12, 1500, 12, 15, 44, 42, 100, 127, 0, -200}; //vetor pre definido

    for(int i = 0; i < sizeof(vetor)/sizeof(int); i++){
        if (i  == 0) {
            minimo = vetor[i];
        }else{
            if (vetor[i] < minimo) {
                minimo = vetor[i];
            }
        }
    }
    printf("O valor minimo do vetor e %d.", minimo);
    
    return 0;
}
