#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int N = 3; // Dimenssão da matriz


int main(int argc, char const *argv[])
{
    int matriz[3][3];
    printf("Preencha a matriz:\n");
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){

            printf("(%d, %d): ", i+1, j+1);
            scanf("%d", &matriz[i][j]);
        }
        printf("\n");
    }
    int matriz_identidade(int mat[][N], int n); 

    int eMatrizIdentidade = matriz_identidade(matriz, 3);

    if (eMatrizIdentidade) {
        printf("\nE uma matriz identidade!");
    }else
    {
        printf("Nao e uma matriz identidade");
    }
    
}
int matriz_identidade(int mat[][N], int n){
    for(int i = 0; i < n; i++ ){
        for(int j =0; j < n; j++){
            if (i!=j && mat[i][j]!=0) {
                return 0;                
            }
            if (i==j && mat[i][j]!=1) {
                return 0;
            }
        }
    }
    return 1;
}