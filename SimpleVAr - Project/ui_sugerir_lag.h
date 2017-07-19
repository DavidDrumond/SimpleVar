/********************************************************************************
** Form generated from reading UI file 'sugerir_lag.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUGERIR_LAG_H
#define UI_SUGERIR_LAG_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_sugerir_lag
{
public:
    QVBoxLayout *verticalLayout;
    QCustomPlot *customPlot;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *n_classes;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *Todas_distancias;
    QRadioButton *radioButton_2;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QDoubleSpinBox *minimo;
    QLabel *label_3;
    QDoubleSpinBox *maximo;
    QTextBrowser *resultado;
    QPushButton *pushButton;

    void setupUi(QDialog *sugerir_lag)
    {
        if (sugerir_lag->objectName().isEmpty())
            sugerir_lag->setObjectName(QStringLiteral("sugerir_lag"));
        sugerir_lag->resize(435, 617);
        verticalLayout = new QVBoxLayout(sugerir_lag);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        customPlot = new QCustomPlot(sugerir_lag);
        customPlot->setObjectName(QStringLiteral("customPlot"));
        customPlot->setMinimumSize(QSize(0, 350));

        verticalLayout->addWidget(customPlot);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(sugerir_lag);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        n_classes = new QSpinBox(sugerir_lag);
        n_classes->setObjectName(QStringLiteral("n_classes"));
        n_classes->setMinimum(3);

        horizontalLayout->addWidget(n_classes);


        verticalLayout->addLayout(horizontalLayout);

        groupBox = new QGroupBox(sugerir_lag);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        Todas_distancias = new QRadioButton(groupBox);
        Todas_distancias->setObjectName(QStringLiteral("Todas_distancias"));

        horizontalLayout_2->addWidget(Todas_distancias);

        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        horizontalLayout_2->addWidget(radioButton_2);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(sugerir_lag);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        horizontalLayout_3 = new QHBoxLayout(groupBox_2);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        minimo = new QDoubleSpinBox(groupBox_2);
        minimo->setObjectName(QStringLiteral("minimo"));
        minimo->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        horizontalLayout_3->addWidget(minimo);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        maximo = new QDoubleSpinBox(groupBox_2);
        maximo->setObjectName(QStringLiteral("maximo"));
        maximo->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        maximo->setMaximum(1e+11);
        maximo->setValue(1e+11);

        horizontalLayout_3->addWidget(maximo);


        verticalLayout->addWidget(groupBox_2);

        resultado = new QTextBrowser(sugerir_lag);
        resultado->setObjectName(QStringLiteral("resultado"));

        verticalLayout->addWidget(resultado);

        pushButton = new QPushButton(sugerir_lag);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);


        retranslateUi(sugerir_lag);

        QMetaObject::connectSlotsByName(sugerir_lag);
    } // setupUi

    void retranslateUi(QDialog *sugerir_lag)
    {
        sugerir_lag->setWindowTitle(QApplication::translate("sugerir_lag", "Calular dist\303\242ncias", Q_NULLPTR));
        label->setText(QApplication::translate("sugerir_lag", "N\303\272mero de classes", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("sugerir_lag", "Tipo", Q_NULLPTR));
        Todas_distancias->setText(QApplication::translate("sugerir_lag", "Todas as distancias", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("sugerir_lag", "Dist\303\242ncia do ponto mais pr\303\263ximo", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("sugerir_lag", "Filtro", Q_NULLPTR));
        label_2->setText(QApplication::translate("sugerir_lag", "M\303\255nimo", Q_NULLPTR));
        label_3->setText(QApplication::translate("sugerir_lag", "M\303\241ximo", Q_NULLPTR));
        pushButton->setText(QApplication::translate("sugerir_lag", "Calcular", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class sugerir_lag: public Ui_sugerir_lag {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUGERIR_LAG_H
