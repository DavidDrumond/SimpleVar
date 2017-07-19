/********************************************************************************
** Form generated from reading UI file 'scatterplot.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCATTERPLOT_H
#define UI_SCATTERPLOT_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_Scatterplot
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QComboBox *cabeca;
    QLabel *label_2;
    QComboBox *rabo;
    QCustomPlot *customPlot;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QDoubleSpinBox *confiabilidade;
    QPushButton *pushButton;
    QTextEdit *texto;
    QTableWidget *outliers;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Scatterplot)
    {
        if (Scatterplot->objectName().isEmpty())
            Scatterplot->setObjectName(QStringLiteral("Scatterplot"));
        Scatterplot->resize(533, 695);
        QIcon icon;
        icon.addFile(QStringLiteral(":/imagens/SimpleVar.png"), QSize(), QIcon::Normal, QIcon::Off);
        Scatterplot->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(Scatterplot);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(Scatterplot);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        cabeca = new QComboBox(Scatterplot);
        cabeca->setObjectName(QStringLiteral("cabeca"));

        horizontalLayout_2->addWidget(cabeca);

        label_2 = new QLabel(Scatterplot);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        rabo = new QComboBox(Scatterplot);
        rabo->setObjectName(QStringLiteral("rabo"));

        horizontalLayout_2->addWidget(rabo);


        verticalLayout->addLayout(horizontalLayout_2);

        customPlot = new QCustomPlot(Scatterplot);
        customPlot->setObjectName(QStringLiteral("customPlot"));
        customPlot->setMinimumSize(QSize(485, 350));
        customPlot->setMaximumSize(QSize(16777215, 400));

        verticalLayout->addWidget(customPlot);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_3 = new QLabel(Scatterplot);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        confiabilidade = new QDoubleSpinBox(Scatterplot);
        confiabilidade->setObjectName(QStringLiteral("confiabilidade"));
        confiabilidade->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        confiabilidade->setMinimum(0.01);
        confiabilidade->setMaximum(1);
        confiabilidade->setValue(0.05);

        horizontalLayout->addWidget(confiabilidade);


        verticalLayout->addLayout(horizontalLayout);

        pushButton = new QPushButton(Scatterplot);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        texto = new QTextEdit(Scatterplot);
        texto->setObjectName(QStringLiteral("texto"));
        texto->setMaximumSize(QSize(16777215, 50));

        verticalLayout->addWidget(texto);

        outliers = new QTableWidget(Scatterplot);
        outliers->setObjectName(QStringLiteral("outliers"));

        verticalLayout->addWidget(outliers);

        pushButton_3 = new QPushButton(Scatterplot);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(Scatterplot);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);


        retranslateUi(Scatterplot);

        QMetaObject::connectSlotsByName(Scatterplot);
    } // setupUi

    void retranslateUi(QDialog *Scatterplot)
    {
        Scatterplot->setWindowTitle(QApplication::translate("Scatterplot", "Gr\303\241fico de Dispers\303\243o", Q_NULLPTR));
        label->setText(QApplication::translate("Scatterplot", "X", Q_NULLPTR));
        label_2->setText(QApplication::translate("Scatterplot", "Y", Q_NULLPTR));
        label_3->setText(QApplication::translate("Scatterplot", "N\303\255vel de cofiabilidade", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Scatterplot", "Calcular", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("Scatterplot", "Remover outliers", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Scatterplot", "Salvar Figura", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Scatterplot: public Ui_Scatterplot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCATTERPLOT_H
