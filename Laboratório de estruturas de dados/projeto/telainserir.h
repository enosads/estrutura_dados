#ifndef TELAINSERIR_H
#define TELAINSERIR_H

#include <QDialog>


namespace Ui {
class TelaInserir;
}

class TelaInserir : public QDialog
{
    Q_OBJECT

public:
    explicit TelaInserir(QWidget *parent = nullptr);
    ~TelaInserir();

private slots:
    void on_btn_cancelar_clicked();


    void on_btn_inserir_clicked();

    void on_rb_escolha_toggled(bool checked);

private:
    Ui::TelaInserir *ui;
};

#endif // TELAINSERIR_H
