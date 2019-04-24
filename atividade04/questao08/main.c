#include "filaestudante.h"

int main(){
	Fila f = criafila();
	char nomes[15][20] = {"Dennys Angelim", "Diego Barboza", "Ozivan Brito", "Dalison Carvalho", "Lucas Fernandes", "Severino Gomes", "Samaronia Lacerda", "Edberg Martins", "Felipe Maykon", "Alinne Oliveira", "Tamara Ramalho", "Washington Santos", "Joao Victor", "Joao Pedro", "Enos Andrade"};
    float u1[15] = {7.1, 7.5, 7.8, 7.4, 8.8, 8.65, 9.5, 8.1, 7.3, 10, 9, 8.7, 7.5, 8.5, 10};
    float u2[15] = {8, 8.5, 9, 7.5, 7.1, 8.8, 8.5, 7, 7.7, 9.2, 8.3, 8.9, 9.5, 7, 10};
    int i;
    //inclusao de estudates
    for(i = 14; i >= 0; i--){
    	Estudante e;
        e.matricula = 2019101 + i;
        e.nome = nomes[i];
        e.u1 = u1[i];
        e.u2 = u2[i];
        e.media = (u1[i] + u2[i]) / 2;
        colocanafila(&f, e);
    }
    imprimirfila(&f);
    printf("\nTamanho antes da remocao: %d\n",f.total);
    Estudante e = tiradafila(&f);
    imprimirfila(&f);
    printf("\n=========== Estudante removido ===========\nNome: %s\nMatricula: %d\nMedia: %.1f\n", e.nome, e.matricula, e.media);
    printf("\nTamanho depois da remocao: %d\n",f.total);
}
