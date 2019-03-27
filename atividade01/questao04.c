#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n;
    printf("Valor: ");
    scanf("%i", &n);

    if (n%3 == 0 && n%7 == 0)
        printf("Divisivel por 3 e 7");
    else
        printf("Nao divisivel por 3 e 7");
    return 0;
}
