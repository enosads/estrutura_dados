#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "QDebug"

Lista* criar_lista(){
    Lista* lista = new Lista;
    lista->qtd = 0;
    lista->inicio = NULL;
    lista->fim = NULL;
    return lista;
}

void inserir_inicio(Lista *&l, DataProcesso* dp){
    Processo* p = new Processo;
    p->dados = dp;

    p->prox = l->inicio;
    p->ant = NULL;
    l->inicio = p;
    if(l->qtd > 0)
        l->inicio->ant = p;
    else
        l->fim = p;
    l->qtd++;
    qDebug() << "Inserido no inicio";
}
void inserir_fim(Lista *&l, DataProcesso* dp){
    Processo* p = new Processo;
    p->dados = dp;
    p->prox = NULL;
    if(l->qtd == 0){
        l->inicio = p;
        l->fim = p;
        p->ant = NULL;
    }else{
        p->ant = l->fim;
        l->fim->prox = p;
        l->fim = p;
    }
    l->qtd++;
    qDebug() << "Inserido no fim";
}

bool inserir_escolha(Lista *&l, DataProcesso* dp, int pos){
    if(pos > l->qtd+1)
        return false;
    else{
        Processo* p = new Processo;
        p->dados = dp;
        Processo* iterador = l->inicio;
        Processo* ant  = NULL;
        int i = 1;
        if(pos == 1){
            p->prox = l->inicio;
            p->ant = NULL;
            l->inicio = p;
            if(l->qtd > 0)
                l->inicio->ant = p;
            else
                l->fim = p;
        }else{
            while(i != pos){
                ant = iterador;
                iterador = iterador->prox;
                i++;
            }
            p->prox = iterador;
            p->ant = ant;
            ant->prox = p;
            if(pos == l->qtd+1){
                l->fim = p;
            }
        }

        l->qtd++;
        qDebug() << "Inserido na posicao " << pos;
        return true;
    }
}

DataProcesso* remover_inicio(Lista *&l){
    if(l->qtd == 0)
        return NULL;
    else{
        Processo* p = l->inicio;
        DataProcesso* dp = p->dados;
        l->inicio = p->prox;
        if(l->inicio != NULL)
            l->inicio->ant = NULL;
        delete p;
        l->qtd--;
        return  dp;
    }
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Gerenciador de processos");
    naoClassificados = criar_lista();
    fisicos = criar_lista();
    juridicos = criar_lista();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_inserir_clicked()
{

    tela_inserir = new TelaInserir(this);
    tela_inserir->exec();

    if(tela_inserir->property("salvar") == true){
        DataProcesso* dp = new DataProcesso;
        dp->num = tela_inserir->property("num").toInt();
        dp->movedor = tela_inserir->property("movedor").toString();
        dp->tipo_pessoa = tela_inserir->property("tipo_pessoa").toString();
        dp->data = tela_inserir->property("data").toString();
        QString opcao = tela_inserir->property("opcao").toString();

        if(opcao == "inicio"){
            inserir_inicio(naoClassificados, dp);
        }else if (opcao == "fim"){
            inserir_fim(naoClassificados, dp);
        }else{
            int posicao = tela_inserir->property("posicao").toInt();
            bool inserido = inserir_escolha(naoClassificados, dp, posicao);
            if(!inserido){
                QMessageBox::critical(this, "ATENÇÃO", "O processo não pode ser inserido na posição indicada");
                return;
            }
        }
        update_list_nao_classificados();
    }
    return;
}
void MainWindow::update_list_nao_classificados(){
    Processo *processo = naoClassificados->inicio;
    ui->list_nao_classificados->clear();
    while(processo != NULL){
        QString item = QString::number(processo->dados->num);
        ui->list_nao_classificados->addItem(item);
        processo = processo->prox;
    }
}
void MainWindow::update_list_fisicos(){
    Processo *processo = fisicos->inicio;
    ui->list_fisicos->clear();
    while(processo != NULL){
        QString item = QString::number(processo->dados->num);
        ui->list_fisicos->addItem(item);
        processo = processo->prox;
    }
}
void MainWindow::update_list_juridicos(){
    Processo *processo = juridicos->inicio;
    ui->list_juridicos->clear();
    while(processo != NULL){
        QString item = QString::number(processo->dados->num);
        ui->list_juridicos->addItem(item);
        processo = processo->prox;
    }
}

void MainWindow::on_btn_classificar_clicked()
{
    while(naoClassificados->qtd != 0){
        DataProcesso* dados = remover_inicio(naoClassificados);
        if(dados != NULL){
            if(dados->tipo_pessoa == "Física"){
                inserir_fim(fisicos, dados);
            }
            else
                inserir_fim(juridicos, dados);
        }
    }
    update_list_nao_classificados();
    update_list_fisicos();
    update_list_juridicos();
}

void MainWindow::on_btn_atender_fisico_clicked()
{
    DataProcesso* dp = remover_inicio(fisicos);
    QString msg;
    if(dp == NULL){
        msg = "Não há mais processos para serem atendidos na lista de processos de pessoas físicas.\n\n"
              "Verifique se há processos não classificados.";
        QMessageBox::warning(this, "Atendimento de processo", msg);
    }else{
        msg = "O processo número "+ QString::number(dp->num) + " foi atendido.\n\nDados do processo:\n\nNúmero: "+ QString::number(dp->num)+
                "\nQuem moveu: "+dp->movedor +"\nPessoa: "+dp->tipo_pessoa+"\nData: "+dp->data;
        QMessageBox::information(this, "Atendimento de processo", msg);
        update_list_fisicos();
    }
}

void MainWindow::on_btn_atender_juridico_clicked()
{
    DataProcesso* dp = remover_inicio(juridicos);
    QString msg;
    if(dp == NULL){
        msg = "Não há mais processos para serem atendidos na lista de processos de pessoas jurídicas.\n\n"
              "Verifique se há processos não classificados.";
        QMessageBox::warning(this, "Atendimento de processo", msg);
    }else{
        msg = "O processo número "+ QString::number(dp->num) + " foi atendido.\n\nDados do processo:\n\nNúmero: "+ QString::number(dp->num)+
                "\nQuem moveu: "+dp->movedor +"\nPessoa: "+dp->tipo_pessoa+"\nData: "+dp->data;
        QMessageBox::information(this, "Atendimento de processo", msg);
        update_list_fisicos();
    }
}
