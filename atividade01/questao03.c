#include <stdio.h>

typedef struct consumidor    
{
    int tipo;
    int codigo;
    float qtdkwh;
}Consumidor;

int main(int argc, char const *argv[])
{
    int tipo = -1, aux=0, qtdConsumidores = 0;
    Consumidor consumidores[30];

    //Adicionar consumidores
    while(tipo!=0 && aux < 30){
        Consumidor consumidor;

        //Codigo para receber o tipo
        do{
            printf("\nEscolha o tipo de consumidor\n\n");
            printf("1 - Residencial\n");
            printf("2 - Comercial\n");
            printf("3 - Industrial\n");
            printf("0 - Mostrar relatorio e sair do programa\n:");
            scanf("%d", &consumidor.tipo);
            if (consumidor.tipo > 3 || consumidor.tipo < 0) {
                printf("\nOPCAO INVALIDA!\n");
            }
            
        }while(consumidor.tipo > 3 || consumidor.tipo < 0);
        
        if (consumidor.tipo == 0) {
            break;
        }
        
        //Codigo para receber codigo do consumidor
        printf("\nCodigo do consumidor: ");
        scanf("%d", &consumidor.codigo);
        
        //Codigo para receber consumo
        printf("\nQuantidade de kWh consumidos no mes: ");
        scanf("%f", &consumidor.qtdkwh);

        //Salvar Consumidor na lista
        consumidores[aux] = consumidor;
        qtdConsumidores++;
        aux++;

    }
    //Mostrar dados requeridos e finalizar programa
    printf("\n=============== Relatorio ===============\n");

    //Menor consumo Residencial
    Consumidor *menorConsumoResidencial = NULL;

    for(int i = 0; i < qtdConsumidores; i++)
    {
        if (consumidores[i].tipo == 1) {
            if (menorConsumoResidencial == NULL){
                menorConsumoResidencial = &consumidores[i];
            }
            else
                if (consumidores[i].qtdkwh < menorConsumoResidencial->qtdkwh) 
                    menorConsumoResidencial = &consumidores[i];
        }
    }
    if(menorConsumoResidencial != NULL){
        printf("\nMenor consumo residencial\n");
        printf("Codigo: %d\n", menorConsumoResidencial->codigo);
        printf("Consumo: %.1fkWh\n", menorConsumoResidencial->qtdkwh);
    }else
    {
        printf("\nNao houve consumo residencial\n");
    }
    //maior consumo Comercial
    Consumidor *maiorConsumoComercial = NULL;

    for(int i = 0; i < qtdConsumidores; i++)
    {
        if (consumidores[i].tipo == 2) {
            if (maiorConsumoComercial == NULL){
                maiorConsumoComercial = &consumidores[i];
            }
            else
                if (consumidores[i].qtdkwh > maiorConsumoComercial->qtdkwh) 
                    maiorConsumoComercial = &consumidores[i];
        }  
    }
    if (maiorConsumoComercial != NULL) {
        printf("\nMaior consumo comercial\n");
        printf("Codigo: %d\n", maiorConsumoComercial->codigo);
        printf("Consumo: %.1fkWh\n", maiorConsumoComercial->qtdkwh);
    }else{
        printf("\nNao houve consumo comercial\n");
    }
    //Media consumo industrial
    float mediaConsumoIndustrial;
    int qtdIndustrial = 0;

    for(int i = 0; i < qtdConsumidores; i++)
    {
        if (consumidores[i].tipo == 3) {
            qtdIndustrial++;
            mediaConsumoIndustrial+=consumidores[i].qtdkwh;
        }
    }
    mediaConsumoIndustrial /=qtdIndustrial;
    printf("\nMedia de consumo Comercial: %.1fkWh\n\n", mediaConsumoIndustrial);
    
    return 0;
}