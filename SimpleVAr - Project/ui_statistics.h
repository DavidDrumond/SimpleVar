/********************************************************************************
** Form generated from reading UI file 'statistics.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATISTICS_H
#define UI_STATISTICS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_statistics
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *cabeca;
    QCustomPlot *customPlot;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpinBox *classes;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *frequencia;
    QRadioButton *radioButton;
    QTextEdit *resultado;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *statistics)
    {
        if (statistics->objectName().isEmpty())
            statistics->setObjectName(QStringLiteral("statistics"));
        statistics->resize(498, 694);
        QIcon icon;
        icon.addFile(QStringLiteral(":/imagens/SimpleVar.png"), QSize(), QIcon::Normal, QIcon::Off);
        statistics->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(statistics);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(statistics);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        cabeca = new QComboBox(statistics);
        cabeca->setObjectName(QStringLiteral("cabeca"));

        horizontalLayout->addWidget(cabeca);


        verticalLayout->addLayout(horizontalLayout);

        customPlot = new QCustomPlot(statistics);
        customPlot->setObjectName(QStringLiteral("customPlot"));
        customPlot->setMinimumSize(QSize(400, 300));

        verticalLayout->addWidget(customPlot);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(statistics);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        classes = new QSpinBox(statistics);
        classes->setObjectName(QStringLiteral("classes"));
        classes->setMinimum(3);
        classes->setMaximum(999999999);

        horizontalLayout_2->addWidget(classes);


        verticalLayout->addLayout(horizontalLayout_2);

        groupBox = new QGroupBox(statistics);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout_3 = new QHBoxLayout(groupBox);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        frequencia = new QRadioButton(groupBox);
        frequencia->setObjectName(QStringLiteral("frequencia"));
        frequencia->setChecked(true);

        horizontalLayout_3->addWidget(frequencia);

        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        horizontalLayout_3->addWidget(radioButton);


        verticalLayout->addWidget(groupBox);

        resultado = new QTextEdit(statistics);
        resultado->setObjectName(QStringLiteral("resultado"));
        resultado->setMinimumSize(QSize(0, 200));

        verticalLayout->addWidget(resultado);

        pushButton = new QPushButton(statistics);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(statistics);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);


        retranslateUi(statistics);

        QMetaObject::connectSlotsByName(statistics);
    } // setupUi

    void retranslateUi(QDialog *statistics)
    {
        statistics->setWindowTitle(QApplication::translate("statistics", "Estat\303\255stica Univariada", Q_NULLPTR));
        label->setText(QApplication::translate("statistics", "Vari\303\241vel ", Q_NULLPTR));
        label_2->setText(QApplication::translate("statistics", "N\303\272mero de Classes", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("statistics", "Tipo do histograma", Q_NULLPTR));
        frequencia->setText(QApplication::translate("statistics", "Frequ\303\252ncia", Q_NULLPTR));
        radioButton->setText(QApplication::translate("statistics", "Frequ\303\252ncia relativa", Q_NULLPTR));
        pushButton->setText(QApplication::translate("statistics", "Calcular", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("statistics", "Salvar Figura", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class statistics: public Ui_statistics {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATISTICS_H
