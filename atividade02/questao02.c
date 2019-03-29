#include<stdio.h>

struct pessoa{
	char nome[50];
	float peso, altura;
};

struct pessoa p[2];
int main(){
    int i;
    for (i=0;i<2;i++){
        setbuf(stdin,NULL);
        printf("Digite seu nome: ");
        gets(p[i].nome);
        setbuf(stdin,NULL);
        printf("Digite seu peso: ");
        scanf("%f", &p[i].peso);
        setbuf(stdin,NULL);
        printf("Digite sua altura: ");
        scanf("%f", &p[i].altura);
    }

    if(p[0].peso < p[1].peso){
        printf("%s e mais pesado(a)!\n", p[1].nome);
    }else if (p[1].peso < p[0].peso) {
        printf("%s e mais pesado(a)!\n", p[0].nome);
    }

    if (p[0].peso == p[1].peso) {
        printf("%s tem o mesmo peso de %s\n", p[0].nome, p[1].nome);
    }else{
        printf("%s nao tem o mesmo peso de %s\n", p[0].nome, p[1].nome);
    }

    if (p[0].altura>p[1].altura) {
        printf("%s e mais alto(a)!\n", p[0].nome);
    }else if (p[1].altura < p[0].altura) {
        printf("%s e mais alto(a)!\n", p[1].nome);
    }else{
        printf("Essas pessoas tem a mesma altura!\n");
    }
}