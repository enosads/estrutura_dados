#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "telainserir.h"


struct DataProcesso{
    int num;
    QString movedor;
    QString tipo_pessoa;
    QString data;
};

struct Processo{
    DataProcesso* dados;
    Processo* ant;
    Processo* prox;
};

struct Lista{
    int qtd;
    Processo* inicio;
    Processo* fim;
};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Lista* naoClassificados;
    Lista* fisicos;
    Lista* juridicos;

private slots:
    void on_btn_inserir_clicked();
    void update_list_nao_classificados();
    void update_list_fisicos();
    void update_list_juridicos();

    void on_btn_classificar_clicked();

    void on_btn_atender_fisico_clicked();

    void on_btn_atender_juridico_clicked();

    void on_btn_listar_clicked();

private:
    Ui::MainWindow *ui;
    TelaInserir* tela_inserir;

};

#endif // MAINWINDOW_H
