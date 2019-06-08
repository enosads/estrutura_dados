#include "telainserir.h"
#include "ui_telainserir.h"
#include "QMessageBox"
#include "mainwindow.h"

TelaInserir::TelaInserir(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TelaInserir)
{
    ui->setupUi(this);
    setWindowTitle("Inserir novo processo");
    ui->txt_num->setFocus();
    ui->txt_data->setDate(QDate::currentDate());
}

TelaInserir::~TelaInserir()
{
    delete ui;
}

void TelaInserir::on_btn_cancelar_clicked()
{
    setProperty("salvar", false);
    close();
}


void TelaInserir::on_btn_inserir_clicked()
{
    //Validar campo número
    if(ui->txt_num->text().isEmpty()){
        QMessageBox::warning(this, "ATENÇÃO!", "O campo 'Número' está vazio. Preencha-o.");
        ui->txt_num->setFocus();
        return;
    }
    else{
        bool isNumeric;
        setProperty("num", ui->txt_num->text().toInt(&isNumeric, 10));
        if(!isNumeric){
            QMessageBox::warning(this, "ATENÇÃO!", "Digite apenas número no campo 'Número'.");
            ui->txt_num->clear();
            ui->txt_num->setFocus();
            return;
        }

    }
    //Validar campo movedor
    if(ui->txt_movedor->text().isEmpty()){
        QMessageBox::warning(this, "ATENÇÃO!", "O campo 'Quem move' está vazio. Preencha-o.");
        ui->txt_movedor->setFocus();
        return;
    }else{
        setProperty("movedor", ui->txt_movedor->text());
    }
    //obter tipo de pessoa
    setProperty("tipo_pessoa", ui->combo_pessoa->currentText());

    //Obter data
    setProperty("data", ui->txt_data->date().toString());

    //Opção de salvamento
    if(ui->rb_inicio->isChecked())
        setProperty("opcao", "inicio");
    else if (ui->rb_fim->isChecked())
        setProperty("opcao", "fim");
    else if (ui->rb_escolha->isChecked()){
        if(ui->txt_posicao->text().isEmpty()){
            QMessageBox::warning(this, "ATENÇÃO!", "Na inserção em um local definido é precisso preencher o campo 'Posição'. Preencha-o.");
            ui->txt_posicao->setFocus();
            return;
        }else{
            bool isNumeric;
            setProperty("posicao", ui->txt_posicao->text().toInt(&isNumeric, 10));
            if(!isNumeric){
                QMessageBox::warning(this, "ATENÇÃO!", "Digite apenas números no campo 'Posição'.");
                ui->txt_posicao->clear();
                ui->txt_posicao->setFocus();
                return;
            }else if(property("posicao") < 1){
                QMessageBox::warning(this, "ATENÇÃO!", "Digite apenas números POSITIVOS no campo 'Posição'.");
                ui->txt_posicao->clear();
                ui->txt_posicao->setFocus();
                return;
            }

        }
    }
    else {
        ui->gb_inserir->setFocus();
        QMessageBox::warning(this, "ATENÇÃO!", "Selecione onde deseja inserir o processo");
        return;
    }
    setProperty("salvar", true);
    close();
}

void TelaInserir::on_rb_escolha_toggled(bool checked)
{
    if(checked){
        ui->txt_posicao->setEnabled(true);
        ui->lbl_posicao->setEnabled(true);
    }else{
        ui->txt_posicao->setEnabled(false);
        ui->lbl_posicao->setEnabled(false);
    }
}
