#include <stdio.h>
    
int main(int argc, char const *argv[])
{
    int x, y, *p;
    y = 0;
    p = &y; // endereço de y atribuido a p
    x = 4;
    (*p)++; //Conteúdo apontado por *p é incrementado em 1, ou seja, y que valia 0 passa a valer 1
    x--; // x é decrementado e passa a valer 3 
    (*p) += x; /* valor apontado por p(y) é incrementado no valor de x (y = y + x),
                ou seja, y valia 1 foi somado com x(3) e passa a valer 4*/

    //RESPOSTA: x = 3, y = 4, e p = endereço de y 

    return 0;
}
