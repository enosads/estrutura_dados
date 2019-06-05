#ifndef LISTA_H
#define LISTA_H

#include <string>

using namespace std;

struct Processo{
    int num;
    string movedor;
    char tipo_pessoa;
    string data;
    Processo* ant;
    Processo* prox;
};

struct Lista{
    Processo* inicio;
    Processo* fim;
    int qtd;
};

Lista* criar_lista();

void inserir_inicio(Lista* l, int num, string movedor, char tipo_pessoa, string data);
void inserir_fim(Lista *l, int num, string movedo, char tipo_pessoa, string data);
bool inserir_posicao(Lista *l, int posicao, int num, string movedor, char tipo_pessoa, string data);
Processo* remover_inicio(Lista *l);

#endif // LISTA_H
