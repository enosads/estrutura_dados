/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *btn_inserir;
    QPushButton *btn_classificar;
    QPushButton *btn_atender_fisico;
    QPushButton *btn_atender_juridico;
    QPushButton *btn_listar;
    QListWidget *list_nao_classificados;
    QListWidget *list_fisicos;
    QListWidget *list_juridicos;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(534, 363);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 1, 2, 1, 1);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 1, 5, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 1, 4, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        btn_inserir = new QPushButton(centralWidget);
        btn_inserir->setObjectName(QString::fromUtf8("btn_inserir"));
        btn_inserir->setAutoDefault(true);
        btn_inserir->setFlat(false);

        verticalLayout_2->addWidget(btn_inserir);

        btn_classificar = new QPushButton(centralWidget);
        btn_classificar->setObjectName(QString::fromUtf8("btn_classificar"));
        btn_classificar->setAutoDefault(true);
        btn_classificar->setFlat(false);

        verticalLayout_2->addWidget(btn_classificar);

        btn_atender_fisico = new QPushButton(centralWidget);
        btn_atender_fisico->setObjectName(QString::fromUtf8("btn_atender_fisico"));
        btn_atender_fisico->setAutoDefault(true);
        btn_atender_fisico->setFlat(false);

        verticalLayout_2->addWidget(btn_atender_fisico);

        btn_atender_juridico = new QPushButton(centralWidget);
        btn_atender_juridico->setObjectName(QString::fromUtf8("btn_atender_juridico"));
        btn_atender_juridico->setAutoDefault(true);
        btn_atender_juridico->setFlat(false);

        verticalLayout_2->addWidget(btn_atender_juridico);

        btn_listar = new QPushButton(centralWidget);
        btn_listar->setObjectName(QString::fromUtf8("btn_listar"));
        btn_listar->setAutoDefault(true);
        btn_listar->setFlat(false);

        verticalLayout_2->addWidget(btn_listar);


        gridLayout->addLayout(verticalLayout_2, 2, 0, 1, 1);

        list_nao_classificados = new QListWidget(centralWidget);
        list_nao_classificados->setObjectName(QString::fromUtf8("list_nao_classificados"));

        gridLayout->addWidget(list_nao_classificados, 2, 2, 1, 1);

        list_fisicos = new QListWidget(centralWidget);
        list_fisicos->setObjectName(QString::fromUtf8("list_fisicos"));

        gridLayout->addWidget(list_fisicos, 2, 4, 1, 1);

        list_juridicos = new QListWidget(centralWidget);
        list_juridicos->setObjectName(QString::fromUtf8("list_juridicos"));

        gridLayout->addWidget(list_juridicos, 2, 5, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 534, 22));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(btn_inserir, btn_classificar);
        QWidget::setTabOrder(btn_classificar, btn_atender_fisico);
        QWidget::setTabOrder(btn_atender_fisico, btn_atender_juridico);
        QWidget::setTabOrder(btn_atender_juridico, btn_listar);
        QWidget::setTabOrder(btn_listar, list_nao_classificados);
        QWidget::setTabOrder(list_nao_classificados, list_fisicos);
        QWidget::setTabOrder(list_fisicos, list_juridicos);

        retranslateUi(MainWindow);

        btn_inserir->setDefault(false);
        btn_classificar->setDefault(false);
        btn_atender_fisico->setDefault(false);
        btn_atender_juridico->setDefault(false);
        btn_listar->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QApplication::translate("MainWindow", "N\303\243o classificados", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Jur\303\255dicos", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "F\303\255sicos", nullptr));
        btn_inserir->setText(QApplication::translate("MainWindow", "Inserir", nullptr));
        btn_classificar->setText(QApplication::translate("MainWindow", "Classificar", nullptr));
        btn_atender_fisico->setText(QApplication::translate("MainWindow", "Atender f\303\255sico", nullptr));
        btn_atender_juridico->setText(QApplication::translate("MainWindow", "Atender jur\303\255dico", nullptr));
        btn_listar->setText(QApplication::translate("MainWindow", "Listar processos", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
