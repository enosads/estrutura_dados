/********************************************************************************
** Form generated from reading UI file 'telainserir.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TELAINSERIR_H
#define UI_TELAINSERIR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TelaInserir
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btn_cancelar;
    QPushButton *btn_inserir;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *txt_num;
    QLabel *label_4;
    QLineEdit *txt_movedor;
    QLabel *label_2;
    QComboBox *combo_pessoa;
    QLabel *label_3;
    QGroupBox *gb_inserir;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *rb_inicio;
    QRadioButton *rb_fim;
    QRadioButton *rb_escolha;
    QDateEdit *txt_data;
    QLineEdit *txt_posicao;
    QLabel *lbl_posicao;

    void setupUi(QDialog *TelaInserir)
    {
        if (TelaInserir->objectName().isEmpty())
            TelaInserir->setObjectName(QStringLiteral("TelaInserir"));
        TelaInserir->resize(399, 352);
        gridLayout = new QGridLayout(TelaInserir);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout->addItem(verticalSpacer_2, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout->addItem(verticalSpacer, 3, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        btn_cancelar = new QPushButton(TelaInserir);
        btn_cancelar->setObjectName(QStringLiteral("btn_cancelar"));
        btn_cancelar->setAutoDefault(false);

        horizontalLayout->addWidget(btn_cancelar);

        btn_inserir = new QPushButton(TelaInserir);
        btn_inserir->setObjectName(QStringLiteral("btn_inserir"));

        horizontalLayout->addWidget(btn_inserir);


        gridLayout->addLayout(horizontalLayout, 2, 1, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(TelaInserir);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        txt_num = new QLineEdit(TelaInserir);
        txt_num->setObjectName(QStringLiteral("txt_num"));

        formLayout->setWidget(0, QFormLayout::FieldRole, txt_num);

        label_4 = new QLabel(TelaInserir);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_4);

        txt_movedor = new QLineEdit(TelaInserir);
        txt_movedor->setObjectName(QStringLiteral("txt_movedor"));

        formLayout->setWidget(1, QFormLayout::FieldRole, txt_movedor);

        label_2 = new QLabel(TelaInserir);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        combo_pessoa = new QComboBox(TelaInserir);
        combo_pessoa->setObjectName(QStringLiteral("combo_pessoa"));

        formLayout->setWidget(2, QFormLayout::FieldRole, combo_pessoa);

        label_3 = new QLabel(TelaInserir);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_3);

        gb_inserir = new QGroupBox(TelaInserir);
        gb_inserir->setObjectName(QStringLiteral("gb_inserir"));
        verticalLayout_2 = new QVBoxLayout(gb_inserir);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        rb_inicio = new QRadioButton(gb_inserir);
        rb_inicio->setObjectName(QStringLiteral("rb_inicio"));

        verticalLayout_2->addWidget(rb_inicio);

        rb_fim = new QRadioButton(gb_inserir);
        rb_fim->setObjectName(QStringLiteral("rb_fim"));

        verticalLayout_2->addWidget(rb_fim);

        rb_escolha = new QRadioButton(gb_inserir);
        rb_escolha->setObjectName(QStringLiteral("rb_escolha"));

        verticalLayout_2->addWidget(rb_escolha);


        formLayout->setWidget(5, QFormLayout::FieldRole, gb_inserir);

        txt_data = new QDateEdit(TelaInserir);
        txt_data->setObjectName(QStringLiteral("txt_data"));

        formLayout->setWidget(4, QFormLayout::FieldRole, txt_data);

        txt_posicao = new QLineEdit(TelaInserir);
        txt_posicao->setObjectName(QStringLiteral("txt_posicao"));
        txt_posicao->setEnabled(false);

        formLayout->setWidget(6, QFormLayout::FieldRole, txt_posicao);

        lbl_posicao = new QLabel(TelaInserir);
        lbl_posicao->setObjectName(QStringLiteral("lbl_posicao"));
        lbl_posicao->setEnabled(false);

        formLayout->setWidget(6, QFormLayout::LabelRole, lbl_posicao);


        gridLayout->addLayout(formLayout, 1, 1, 1, 1);

        QWidget::setTabOrder(txt_num, txt_movedor);
        QWidget::setTabOrder(txt_movedor, combo_pessoa);
        QWidget::setTabOrder(combo_pessoa, txt_data);
        QWidget::setTabOrder(txt_data, rb_inicio);
        QWidget::setTabOrder(rb_inicio, rb_fim);
        QWidget::setTabOrder(rb_fim, rb_escolha);
        QWidget::setTabOrder(rb_escolha, txt_posicao);
        QWidget::setTabOrder(txt_posicao, btn_cancelar);
        QWidget::setTabOrder(btn_cancelar, btn_inserir);

        retranslateUi(TelaInserir);

        QMetaObject::connectSlotsByName(TelaInserir);
    } // setupUi

    void retranslateUi(QDialog *TelaInserir)
    {
        TelaInserir->setWindowTitle(QApplication::translate("TelaInserir", "Dialog", Q_NULLPTR));
        btn_cancelar->setText(QApplication::translate("TelaInserir", "Cancelar", Q_NULLPTR));
        btn_inserir->setText(QApplication::translate("TelaInserir", "Inserir", Q_NULLPTR));
        label->setText(QApplication::translate("TelaInserir", "N\303\272mero", Q_NULLPTR));
        label_4->setText(QApplication::translate("TelaInserir", "Quem move", Q_NULLPTR));
        label_2->setText(QApplication::translate("TelaInserir", "Pessoa", Q_NULLPTR));
        combo_pessoa->clear();
        combo_pessoa->insertItems(0, QStringList()
         << QApplication::translate("TelaInserir", "F\303\255sica", Q_NULLPTR)
         << QApplication::translate("TelaInserir", "Jur\303\255dica", Q_NULLPTR)
        );
        label_3->setText(QApplication::translate("TelaInserir", "Data", Q_NULLPTR));
        gb_inserir->setTitle(QApplication::translate("TelaInserir", "Onde inserir?", Q_NULLPTR));
        rb_inicio->setText(QApplication::translate("TelaInserir", "in\303\255cio da lista", Q_NULLPTR));
        rb_fim->setText(QApplication::translate("TelaInserir", "fim da lista", Q_NULLPTR));
        rb_escolha->setText(QApplication::translate("TelaInserir", "escolher local", Q_NULLPTR));
        lbl_posicao->setText(QApplication::translate("TelaInserir", "Posi\303\247\303\243o", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TelaInserir: public Ui_TelaInserir {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TELAINSERIR_H
