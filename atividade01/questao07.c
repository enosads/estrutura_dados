#include <stdio.h>

int main(int argc, char const *argv[]){
    for(int i = 10; i < 100; i++){
        for(int j = 0; j < 100; j++){
            
            if ((i+j)*(i+j) == (i*100)+j) {
                printf("%d\n",(i+j)*(i+j));
            }  
        }
    }
}