/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionDados;
    QAction *actionOutliers;
    QAction *actionVariogram_Map;
    QAction *actionVariograma_Experimental;
    QAction *actionModelo_de_Continuidade_Espacial;
    QAction *actionScatter_Plot;
    QAction *actionEstat_stica_Univariada;
    QAction *actionCalcular_dist_ncias;
    QAction *actionVizualizar_Dados;
    QWidget *centralWidget;
    QLabel *emptylabel;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QMenuBar *menuBar;
    QMenu *menuNovo;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 198);
        MainWindow->setMinimumSize(QSize(400, 198));
        MainWindow->setMaximumSize(QSize(400, 198));
        QIcon icon;
        icon.addFile(QStringLiteral(":/imagens/SimpleVar.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionDados = new QAction(MainWindow);
        actionDados->setObjectName(QStringLiteral("actionDados"));
        actionOutliers = new QAction(MainWindow);
        actionOutliers->setObjectName(QStringLiteral("actionOutliers"));
        actionVariogram_Map = new QAction(MainWindow);
        actionVariogram_Map->setObjectName(QStringLiteral("actionVariogram_Map"));
        actionVariograma_Experimental = new QAction(MainWindow);
        actionVariograma_Experimental->setObjectName(QStringLiteral("actionVariograma_Experimental"));
        actionModelo_de_Continuidade_Espacial = new QAction(MainWindow);
        actionModelo_de_Continuidade_Espacial->setObjectName(QStringLiteral("actionModelo_de_Continuidade_Espacial"));
        actionScatter_Plot = new QAction(MainWindow);
        actionScatter_Plot->setObjectName(QStringLiteral("actionScatter_Plot"));
        actionEstat_stica_Univariada = new QAction(MainWindow);
        actionEstat_stica_Univariada->setObjectName(QStringLiteral("actionEstat_stica_Univariada"));
        actionCalcular_dist_ncias = new QAction(MainWindow);
        actionCalcular_dist_ncias->setObjectName(QStringLiteral("actionCalcular_dist_ncias"));
        actionVizualizar_Dados = new QAction(MainWindow);
        actionVizualizar_Dados->setObjectName(QStringLiteral("actionVizualizar_Dados"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        emptylabel = new QLabel(centralWidget);
        emptylabel->setObjectName(QStringLiteral("emptylabel"));
        emptylabel->setGeometry(QRect(10, 20, 160, 107));
        emptylabel->setMinimumSize(QSize(160, 107));
        emptylabel->setMaximumSize(QSize(160, 107));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(237, 10, 91, 20));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(11);
        font.setBold(true);
        font.setItalic(false);
        font.setUnderline(true);
        font.setWeight(75);
        label_2->setFont(font);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(200, 40, 191, 20));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(200, 60, 171, 20));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(200, 90, 181, 16));
        QFont font1;
        font1.setItalic(true);
        label_4->setFont(font1);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(200, 110, 181, 16));
        label_5->setFont(font1);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 21));
        menuNovo = new QMenu(menuBar);
        menuNovo->setObjectName(QStringLiteral("menuNovo"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuNovo->menuAction());
        menuNovo->addAction(actionDados);
        menuNovo->addAction(actionOutliers);
        menuNovo->addAction(actionVariogram_Map);
        menuNovo->addAction(actionVariograma_Experimental);
        menuNovo->addAction(actionModelo_de_Continuidade_Espacial);
        menuNovo->addAction(actionScatter_Plot);
        menuNovo->addAction(actionEstat_stica_Univariada);
        menuNovo->addAction(actionCalcular_dist_ncias);
        menuNovo->addAction(actionVizualizar_Dados);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Simple Var", Q_NULLPTR));
        actionDados->setText(QApplication::translate("MainWindow", "Importar Dados", Q_NULLPTR));
        actionOutliers->setText(QApplication::translate("MainWindow", "Gr\303\241fico de caixa e outliers ", Q_NULLPTR));
        actionVariogram_Map->setText(QApplication::translate("MainWindow", "Mapa de Variogramas", Q_NULLPTR));
        actionVariograma_Experimental->setText(QApplication::translate("MainWindow", "Continuidade Espacial Experimental", Q_NULLPTR));
        actionModelo_de_Continuidade_Espacial->setText(QApplication::translate("MainWindow", "Modelo de Continuidade Espacial", Q_NULLPTR));
        actionScatter_Plot->setText(QApplication::translate("MainWindow", "Gr\303\241fico de Dispers\303\243o", Q_NULLPTR));
        actionEstat_stica_Univariada->setText(QApplication::translate("MainWindow", "Estat\303\255stica Univariada", Q_NULLPTR));
        actionCalcular_dist_ncias->setText(QApplication::translate("MainWindow", "Calcular dist\303\242ncias", Q_NULLPTR));
        actionVizualizar_Dados->setText(QApplication::translate("MainWindow", "Vizualizar Dados", Q_NULLPTR));
        emptylabel->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "SIMPLE VAR", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Um programa simples de an\303\241lise", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "descritiva espacial (2017)", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Autor: David Alvarenga Drumond", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "david.engminas.ufmg@gmail.com", Q_NULLPTR));
        menuNovo->setTitle(QApplication::translate("MainWindow", "Novo", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
