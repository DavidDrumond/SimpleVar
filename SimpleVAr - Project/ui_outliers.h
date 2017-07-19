/********************************************************************************
** Form generated from reading UI file 'outliers.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OUTLIERS_H
#define UI_OUTLIERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_Outliers
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QComboBox *cabecalho;
    QCustomPlot *customPlot;
    QTableWidget *outliers;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QDialog *Outliers)
    {
        if (Outliers->objectName().isEmpty())
            Outliers->setObjectName(QStringLiteral("Outliers"));
        Outliers->resize(471, 643);
        QIcon icon;
        icon.addFile(QStringLiteral(":/imagens/SimpleVar.png"), QSize(), QIcon::Normal, QIcon::Off);
        Outliers->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(Outliers);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton = new QPushButton(Outliers);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        cabecalho = new QComboBox(Outliers);
        cabecalho->setObjectName(QStringLiteral("cabecalho"));

        horizontalLayout->addWidget(cabecalho);


        verticalLayout->addLayout(horizontalLayout);

        customPlot = new QCustomPlot(Outliers);
        customPlot->setObjectName(QStringLiteral("customPlot"));
        customPlot->setMinimumSize(QSize(150, 300));

        verticalLayout->addWidget(customPlot);

        outliers = new QTableWidget(Outliers);
        outliers->setObjectName(QStringLiteral("outliers"));

        verticalLayout->addWidget(outliers);

        pushButton_2 = new QPushButton(Outliers);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(Outliers);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);


        retranslateUi(Outliers);

        QMetaObject::connectSlotsByName(Outliers);
    } // setupUi

    void retranslateUi(QDialog *Outliers)
    {
        Outliers->setWindowTitle(QApplication::translate("Outliers", "Outliers", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Outliers", "Escolha a vari\303\241vel ", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Outliers", "Remova o outlier selecionado na tabela", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("Outliers", "Salvar Figura", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Outliers: public Ui_Outliers {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OUTLIERS_H
