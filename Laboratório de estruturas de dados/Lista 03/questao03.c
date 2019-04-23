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
    int i = 1;
    if(l->qtd > 0){
        while(e != NULL){
            printf("%d - Nome: %s - Telefone: %s - Aniversario: %s\n", i, e->info.nome, e->info.telefone, e->info.aniversario);
            e = e->prox;
            i++;
        }
    }else{
        printf("Voce ainda nao inseriu contatos na agenda\n");
    }
}

Elemento* busca_contato(Lista *l, char busca[30], int* n){
    Elemento *e = l->inicio;
    for (int i = 0; i < l->qtd; i++) {
        if(strcmp(e->info.nome, busca) == 0){
            *n = i+1;
            return e;
        }
        e = e->prox;
    }
    return NULL;
}

void remove_contato(Lista *l, Elemento *e){
    Elemento *ant = NULL;
    Elemento *atual = l->inicio;
    while (atual != NULL && atual != e) {
        ant = atual;
        atual = atual->prox;
    }
    if (ant == NULL) l->inicio = atual->prox;
    else ant->prox = atual->prox;
    free(atual);
    l->qtd--;
}

void remove_duplicados(Lista *l){ //Falta Corrigir esta funcao
    if (l->qtd <= 1) {
        printf("\nNenhum contato duplicado!\n");
        return;
    }
    Elemento *e = l->inicio;
    Elemento *prox = e->prox;
    int qtd = 0;
    int fim = l->inicio;
    for (int i = 0; i < fim; i++) {
        for (int j = 0; i < fim -1; i++) {
            if (strcmp(e->info.nome, prox->info.nome) == 0){
                Elemento *aux = prox;
                remove_contato(l, prox);
                prox = aux->prox;
                qtd++;
            }
            prox = prox->prox;
            if (prox == NULL || e == NULL)break;
        }
        e = e->prox;
        if (prox == NULL || e == NULL)break;
    }
    printf("\n%d contatos foram removidos\n", qtd);
}

//Impementacao
void inserirContato(Lista *l){
    printf("\n------------------- INSERIR CONTATO -------------------\n");
    Contato contato;
    char nome[30], telefone[30], aniversario[30];
    printf("Nome: "); setbuf(stdin, NULL);
    gets(contato.nome);
    printf("Telefone: "); setbuf(stdin, NULL);
    gets(contato.telefone);
    printf("Data de aniversario: "); setbuf(stdin, NULL);
    gets(contato.aniversario);
    insere_contato(l, contato);
    printf("\nContato inserido com sucesso!\n");
}

Elemento* buscarContato(Lista *l){
    printf("\n------------------- BUSCAR CONTATO -------------------\n");
    char busca[30];
    printf("Nome do contato: "); setbuf(stdin, NULL);
    gets(busca);
    int n;
    Elemento* resposta = busca_contato(l, busca, &n);
    if (resposta == NULL) {
        printf("\nContato nao encontrado\n");
    }else{
        printf("\nO contato esta na posicao %d da agenda\n", n);
        printf("%d - Nome: %s - Telefone: %s - Aniversario: %s\n", n, resposta->info.nome, resposta->info.telefone, resposta->info.aniversario);
    }
    return resposta;
}

void removerContato(Lista *l){
    if(l->qtd == 0){
        printf("\nVoce ainda nao inseriu contatos na agenda\n");
        return;
    }
    Elemento *e = buscarContato(l);
    if(e == NULL) return;
    int resposta = -1;
    printf("\n------------------- REMOVER CONTATO -------------------\n");
    do{
        printf("\nDeseja realmente remover o contato? [1 - SIM / 0 - NAO]: ");
        scanf("%d",&resposta);
        if(resposta != 1 && resposta != 0) printf("\nOPCAO INVALIDA!\n");
    }while(resposta != 1 && resposta != 0);
    if (resposta == 0) printf("O contato nao foi removido\n");
    else{
        remove_contato(l, e);
        printf("O contato foi removido\n");
    }
}

void editarContato(Lista *l){
    if(l->qtd == 0){
        printf("\nVoce ainda nao inseriu contatos na agenda\n");
        return;
    }
    Elemento *e = buscarContato(l);
    if(e == NULL) return;
    int resposta = -1;
    printf("\n------------------- EDITAR CONTATO -------------------\n");
    remove_contato(l, e);
    Contato contato;
    char nome[30], telefone[30], aniversario[30];
    printf("Nome: "); setbuf(stdin, NULL);
    gets(contato.nome);
    printf("Telefone: "); setbuf(stdin, NULL);
    gets(contato.telefone);
    printf("Data de aniversario: "); setbuf(stdin, NULL);
    gets(contato.aniversario);
    insere_contato(l, contato);
    printf("\nContato editado com sucesso!\n");
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
            case 3: buscarContato(l); break;
            case 4: editarContato(l); break;
            case 5: removerContato(l); break;
            case 6: remove_duplicados(l); break;
            default: printf("\nOPCAO INVALIDA!\n"); break;
        }
    }while(resposta != 0);
    return 0;
}
