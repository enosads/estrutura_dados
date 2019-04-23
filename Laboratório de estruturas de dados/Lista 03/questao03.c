#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[30];
    char telefone[30];
    char aniversario[30];
} Contato;

typedef struct elemento{
    Contato info;
    struct elemento *prox;
} Elemento;

typedef struct{
    int qtd;
    Elemento* inicio;
} Lista;

void cria_agenda(Lista *l){
    l->inicio = NULL;
    l->qtd = 0;
}

void insere_contato (Lista *l, Contato c){
    Elemento* ant = NULL;
    Elemento* atual = l->inicio;
    Elemento* e = (Elemento*) malloc(sizeof(Elemento));
    e->info = c;
    for(int i = -1; i < l->qtd -1; i++){
      if (strcmp(e->info.nome, atual->info.nome) <= 0) break;
      ant = atual;
      atual = atual->prox;
    }
    if (ant == NULL) {
        e->prox = l->inicio;
        l->inicio = e;
    }else{
        e->prox = ant->prox;
        ant->prox = e;
    }
    l->qtd++;
}

void lista_contatos(Lista *l){
    printf("\n------------------- LISTAR CONTATOS -------------------\n");
    Elemento *e = l->inicio;
    if(l->qtd > 0){
        while(e != NULL){
           printf("Contato: %s - Telefone: %s - Aniversario: %s\n", e->info.nome, e->info.telefone, e->info.aniversario);
            e = e->prox;
        }
    }else{
        printf("Voce ainda nao cadastrou contatos na agenda\n");
    }
}

void menu(){
    printf("\n------------------- MENU -------------------\n");
    printf("1 - Inserir contato\n");
    printf("2 - Listar contatos\n");
    printf("3 - Buscar contatos\n");
    printf("4 - Editar contato\n");
    printf("5 - Remover contato\n");
    printf("6 - Remover contatos duplicados\n");
    printf("0 - Sair do programa\n: ");
}

void inserirContato(Lista *l){
    printf("\n------------------- INSERIR CONTATO -------------------\n");
    Contato contato;
    char nome[30], telefone[30], aniversario[30];
    printf("Nome: "); setbuf(stdin, NULL);
    gets(nome);
    printf("Telefone: "); setbuf(stdin, NULL);
    gets(telefone);
    printf("Data de aniversario: "); setbuf(stdin, NULL);
    gets(aniversario);
    strcpy(contato.nome, nome);
    strcpy(contato.telefone, telefone);
    strcpy(contato.aniversario, aniversario);
    insere_contato(l, contato);
    printf("\nContato inserido com sucesso!\n");
}

int main(){
    Lista* l = (Lista*) malloc(sizeof(Lista));
    cria_agenda(l);
    int resposta;
    do{
        menu();
        scanf("%d", &resposta);
        switch (resposta){
            case 0: printf("\nSaindo do programa..."); break;
            case 1: inserirContato(l); break;
            case 2: lista_contatos(l); break;
            default: printf("\nOPCAO INVALIDA!\n"); break;
        }
    }while(resposta != 0);
    return 0;
}
