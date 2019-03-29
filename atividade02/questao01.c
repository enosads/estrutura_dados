#include <stdio.h>

int main(int argc, char const *argv[]){
    printf("N          10*N          100*N          1000*N\n");
    for(int i = 0; i < 5; i++){
        printf("%d          %d            %d            %d\n", i+1, (i+1)*10, (i+1)*100, (i+1)*1000);
    }
    return 0;
}   