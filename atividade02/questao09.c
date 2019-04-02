#include <stdio.h>
#define PI 3.14159265

void menu(){
    printf("\nO que deseja fazer?\n");
    printf("1 - Calcular e exibir a area de um circulo\n");
    printf("2 - Calcular e exibir a area de um triangulo\n");
    printf("3 - Calcular e exibir a area de um quadrado\n");
    printf("4 - Calcular e exibir a area de um retangulo\n");
    printf("5 - Finalizar a aplicacao\n: ");
}
void circulo(){
    float raio, area;
    printf("\nRaio: ");
    scanf("%f", &raio);
    area = PI * (raio * raio);
    printf("\nA area do circulo e %.2f\n", area);
}
void triangulo(){
    float base, altura, area;
    printf("\nBase: ");
    scanf("%f", &base);
    printf("Altura: ");
    scanf("%f", &altura);
    area = (base*altura)/2;
    printf("\nA area do triangulo e %.2f\n", area);
}
void quadrado(){
    float lado, area;
    printf("\nLado: ");
    scanf("%f", &lado);
    area = lado*lado;
    printf("\nA area do quadrado e %.2f\n", area);
}
void retangulo(){
    float base, altura, area;
    printf("\nBase: ");
    scanf("%f", &base);
    printf("Altura: ");
    scanf("%f", &altura);
    area = base*altura;
    printf("\nA area do retangulo e %.2f\n", area);
}
int main(){
    int opcao;
    do{
        menu();
        scanf("%d", &opcao);
        switch (opcao){
            case 1: circulo(); break;
            case 2: triangulo();  break;
            case 3: quadrado(); break;
            case 4: retangulo(); break;
            case 5: printf("\nSaindo do programa..."); break;
            default: printf("\nOPCAO INVALIDA!\n"); break;
        }
    }while(opcao != 5);
    return 0;
}