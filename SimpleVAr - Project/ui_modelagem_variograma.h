/********************************************************************************
** Form generated from reading UI file 'modelagem_variograma.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODELAGEM_VARIOGRAMA_H
#define UI_MODELAGEM_VARIOGRAMA_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_Modelagem_Variograma
{
public:
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QCheckBox *Varpriori;
    QCheckBox *showpar;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDoubleSpinBox *Efeito_Pepita;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpinBox *n_estruturas;
    QTableWidget *tabela;
    QTableWidget *Grafico_prop;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QCustomPlot *customPlot;

    void setupUi(QDialog *Modelagem_Variograma)
    {
        if (Modelagem_Variograma->objectName().isEmpty())
            Modelagem_Variograma->setObjectName(QStringLiteral("Modelagem_Variograma"));
        Modelagem_Variograma->resize(921, 714);
        QIcon icon;
        icon.addFile(QStringLiteral(":/imagens/SimpleVar.png"), QSize(), QIcon::Normal, QIcon::Off);
        Modelagem_Variograma->setWindowIcon(icon);
        horizontalLayout_3 = new QHBoxLayout(Modelagem_Variograma);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        groupBox = new QGroupBox(Modelagem_Variograma);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        Varpriori = new QCheckBox(groupBox);
        Varpriori->setObjectName(QStringLiteral("Varpriori"));

        verticalLayout->addWidget(Varpriori);

        showpar = new QCheckBox(groupBox);
        showpar->setObjectName(QStringLiteral("showpar"));

        verticalLayout->addWidget(showpar);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        Efeito_Pepita = new QDoubleSpinBox(groupBox);
        Efeito_Pepita->setObjectName(QStringLiteral("Efeito_Pepita"));
        Efeito_Pepita->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        horizontalLayout->addWidget(Efeito_Pepita);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        n_estruturas = new QSpinBox(groupBox);
        n_estruturas->setObjectName(QStringLiteral("n_estruturas"));
        n_estruturas->setMinimum(1);

        horizontalLayout_2->addWidget(n_estruturas);


        verticalLayout->addLayout(horizontalLayout_2);

        tabela = new QTableWidget(groupBox);
        if (tabela->columnCount() < 8)
            tabela->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tabela->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tabela->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tabela->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tabela->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tabela->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tabela->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tabela->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tabela->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        tabela->setObjectName(QStringLiteral("tabela"));

        verticalLayout->addWidget(tabela);

        Grafico_prop = new QTableWidget(groupBox);
        if (Grafico_prop->columnCount() < 3)
            Grafico_prop->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        Grafico_prop->setHorizontalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        Grafico_prop->setHorizontalHeaderItem(1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        Grafico_prop->setHorizontalHeaderItem(2, __qtablewidgetitem10);
        Grafico_prop->setObjectName(QStringLiteral("Grafico_prop"));

        verticalLayout->addWidget(Grafico_prop);


        verticalLayout_2->addWidget(groupBox);

        pushButton = new QPushButton(Modelagem_Variograma);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout_2->addWidget(pushButton);

        pushButton_2 = new QPushButton(Modelagem_Variograma);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout_2->addWidget(pushButton_2);


        horizontalLayout_3->addLayout(verticalLayout_2);

        customPlot = new QCustomPlot(Modelagem_Variograma);
        customPlot->setObjectName(QStringLiteral("customPlot"));
        customPlot->setMinimumSize(QSize(600, 600));

        horizontalLayout_3->addWidget(customPlot);


        retranslateUi(Modelagem_Variograma);

        QMetaObject::connectSlotsByName(Modelagem_Variograma);
    } // setupUi

    void retranslateUi(QDialog *Modelagem_Variograma)
    {
        Modelagem_Variograma->setWindowTitle(QApplication::translate("Modelagem_Variograma", "Modelagem Variograma", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("Modelagem_Variograma", "GroupBox", Q_NULLPTR));
        Varpriori->setText(QApplication::translate("Modelagem_Variograma", "Mostrar Vari\303\242ncia a Priori", Q_NULLPTR));
        showpar->setText(QApplication::translate("Modelagem_Variograma", "Mostrar Pares Variograma Experimental", Q_NULLPTR));
        label->setText(QApplication::translate("Modelagem_Variograma", "Efeito Pepita", Q_NULLPTR));
        label_2->setText(QApplication::translate("Modelagem_Variograma", "N\303\272mero de estruturas", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tabela->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Modelagem_Variograma", "Azimute", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tabela->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Modelagem_Variograma", "Mergulho", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tabela->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Modelagem_Variograma", "Plunge", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tabela->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("Modelagem_Variograma", "Max alcance", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tabela->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("Modelagem_Variograma", "Med alcance", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = tabela->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("Modelagem_Variograma", "Min alacance", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = tabela->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("Modelagem_Variograma", "Contribui\303\247\303\243o", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = tabela->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("Modelagem_Variograma", "Modelo", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem8 = Grafico_prop->horizontalHeaderItem(0);
        ___qtablewidgetitem8->setText(QApplication::translate("Modelagem_Variograma", "Gr\303\241fico", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem9 = Grafico_prop->horizontalHeaderItem(1);
        ___qtablewidgetitem9->setText(QApplication::translate("Modelagem_Variograma", "Classe", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem10 = Grafico_prop->horizontalHeaderItem(2);
        ___qtablewidgetitem10->setText(QApplication::translate("Modelagem_Variograma", "Inverter Eixo", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Modelagem_Variograma", "Modelar", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Modelagem_Variograma", "Salvar Imagem", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Modelagem_Variograma: public Ui_Modelagem_Variograma {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODELAGEM_VARIOGRAMA_H
