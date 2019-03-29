#include <stdio.h>

int fatorial(int x) {
    if ((x==1) || (x==0)) return 1;
    else  return fatorial(x-1)*x;
}
int par(int x){
    return !(x % 2);
}
int main(){
    float x, s=0;
    printf("Informe o valor de x: ");
    scanf("%f", &x);
    for(int i =1; i < 10; i++){
        if (par(i)){
            s-= x/fatorial(i);
        }else{
            s+= x/fatorial(i);
        }
    }
    printf("O valor de S e: %f", s);
    return 0;
}