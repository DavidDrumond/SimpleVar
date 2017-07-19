/********************************************************************************
** Form generated from reading UI file 'variogram_map.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VARIOGRAM_MAP_H
#define UI_VARIOGRAM_MAP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_Variogram_Map
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QComboBox *Propr_cabeca;
    QLabel *label_5;
    QComboBox *Prop_rabo;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpinBox *Azimute;
    QLabel *label_13;
    QSpinBox *Mergulho;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *label_7;
    QLabel *label_6;
    QSpinBox *Lag_size;
    QSpinBox *nLag;
    QSpinBox *Min_npares;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QSpinBox *Ncelulas;
    QLabel *label_8;
    QSpinBox *Grau_refinamento;
    QLabel *label_9;
    QComboBox *Gradient_type;
    QPushButton *pushButton;
    QProgressBar *progressBar;
    QCustomPlot *customPlot;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Variogram_Map)
    {
        if (Variogram_Map->objectName().isEmpty())
            Variogram_Map->setObjectName(QStringLiteral("Variogram_Map"));
        Variogram_Map->resize(492, 739);
        QIcon icon;
        icon.addFile(QStringLiteral(":/imagens/SimpleVar.png"), QSize(), QIcon::Normal, QIcon::Off);
        Variogram_Map->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(Variogram_Map);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox_2 = new QGroupBox(Variogram_Map);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        horizontalLayout = new QHBoxLayout(groupBox_2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout->addWidget(label_4);

        Propr_cabeca = new QComboBox(groupBox_2);
        Propr_cabeca->setObjectName(QStringLiteral("Propr_cabeca"));

        horizontalLayout->addWidget(Propr_cabeca);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout->addWidget(label_5);

        Prop_rabo = new QComboBox(groupBox_2);
        Prop_rabo->setObjectName(QStringLiteral("Prop_rabo"));

        horizontalLayout->addWidget(Prop_rabo);


        verticalLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(Variogram_Map);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_3);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(groupBox_3);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        Azimute = new QSpinBox(groupBox_3);
        Azimute->setObjectName(QStringLiteral("Azimute"));
        Azimute->setMinimum(-360);
        Azimute->setMaximum(360);

        horizontalLayout_2->addWidget(Azimute);

        label_13 = new QLabel(groupBox_3);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout_2->addWidget(label_13);

        Mergulho = new QSpinBox(groupBox_3);
        Mergulho->setObjectName(QStringLiteral("Mergulho"));
        Mergulho->setMinimum(-360);
        Mergulho->setMaximum(360);

        horizontalLayout_2->addWidget(Mergulho);


        verticalLayout->addWidget(groupBox_3);

        groupBox = new QGroupBox(Variogram_Map);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 0, 5, 1, 1);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 0, 3, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 0, 0, 1, 1);

        Lag_size = new QSpinBox(groupBox);
        Lag_size->setObjectName(QStringLiteral("Lag_size"));
        Lag_size->setMaximum(999999);

        gridLayout->addWidget(Lag_size, 0, 4, 1, 1);

        nLag = new QSpinBox(groupBox);
        nLag->setObjectName(QStringLiteral("nLag"));
        nLag->setMaximum(999999);

        gridLayout->addWidget(nLag, 0, 1, 1, 1);

        Min_npares = new QSpinBox(groupBox);
        Min_npares->setObjectName(QStringLiteral("Min_npares"));
        Min_npares->setMaximum(99999999);

        gridLayout->addWidget(Min_npares, 0, 6, 1, 1);


        verticalLayout->addWidget(groupBox);

        groupBox_4 = new QGroupBox(Variogram_Map);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        horizontalLayout_3 = new QHBoxLayout(groupBox_4);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(groupBox_4);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        Ncelulas = new QSpinBox(groupBox_4);
        Ncelulas->setObjectName(QStringLiteral("Ncelulas"));
        Ncelulas->setMinimum(5);
        Ncelulas->setMaximum(2000);
        Ncelulas->setValue(50);

        horizontalLayout_3->addWidget(Ncelulas);

        label_8 = new QLabel(groupBox_4);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_3->addWidget(label_8);

        Grau_refinamento = new QSpinBox(groupBox_4);
        Grau_refinamento->setObjectName(QStringLiteral("Grau_refinamento"));
        Grau_refinamento->setMinimum(10);
        Grau_refinamento->setMaximum(350);

        horizontalLayout_3->addWidget(Grau_refinamento);

        label_9 = new QLabel(groupBox_4);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_3->addWidget(label_9);

        Gradient_type = new QComboBox(groupBox_4);
        Gradient_type->setObjectName(QStringLiteral("Gradient_type"));

        horizontalLayout_3->addWidget(Gradient_type);


        verticalLayout->addWidget(groupBox_4);

        pushButton = new QPushButton(Variogram_Map);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        progressBar = new QProgressBar(Variogram_Map);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(0);

        verticalLayout->addWidget(progressBar);

        customPlot = new QCustomPlot(Variogram_Map);
        customPlot->setObjectName(QStringLiteral("customPlot"));
        customPlot->setMinimumSize(QSize(350, 350));

        verticalLayout->addWidget(customPlot);

        pushButton_2 = new QPushButton(Variogram_Map);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);


        retranslateUi(Variogram_Map);

        QMetaObject::connectSlotsByName(Variogram_Map);
    } // setupUi

    void retranslateUi(QDialog *Variogram_Map)
    {
        Variogram_Map->setWindowTitle(QApplication::translate("Variogram_Map", "Mapa de Variogramas", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("Variogram_Map", "Vari\303\241veis", Q_NULLPTR));
        label_4->setText(QApplication::translate("Variogram_Map", "Propriedade da cabe\303\247a", Q_NULLPTR));
        label_5->setText(QApplication::translate("Variogram_Map", "Propriedade do rabo", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("Variogram_Map", "Dire\303\247\303\243o do Norte do plano considerado", Q_NULLPTR));
        label->setText(QApplication::translate("Variogram_Map", "Azimute ", Q_NULLPTR));
        label_13->setText(QApplication::translate("Variogram_Map", "Mergulho", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("Variogram_Map", "Par\303\242metros do mapa de variogramas", Q_NULLPTR));
        label_3->setText(QApplication::translate("Variogram_Map", "Min npares         ", Q_NULLPTR));
        label_7->setText(QApplication::translate("Variogram_Map", "Tamanho  lag", Q_NULLPTR));
        label_6->setText(QApplication::translate("Variogram_Map", "n lags", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("Variogram_Map", "GroupBox", Q_NULLPTR));
        label_2->setText(QApplication::translate("Variogram_Map", "N\303\272mero de c\303\251lulas ", Q_NULLPTR));
        label_8->setText(QApplication::translate("Variogram_Map", "Grau de refinamento", Q_NULLPTR));
        label_9->setText(QApplication::translate("Variogram_Map", "Escala de Cor", Q_NULLPTR));
        Gradient_type->clear();
        Gradient_type->insertItems(0, QStringList()
         << QApplication::translate("Variogram_Map", "Grayscale", Q_NULLPTR)
         << QApplication::translate("Variogram_Map", "Hot", Q_NULLPTR)
         << QApplication::translate("Variogram_Map", "Cold", Q_NULLPTR)
         << QApplication::translate("Variogram_Map", "Polar", Q_NULLPTR)
         << QApplication::translate("Variogram_Map", "Hues", Q_NULLPTR)
         << QApplication::translate("Variogram_Map", "Spectrum", Q_NULLPTR)
        );
        pushButton->setText(QApplication::translate("Variogram_Map", "Calcular Mapa de Variogramas", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Variogram_Map", "Salvar Figura", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Variogram_Map: public Ui_Variogram_Map {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VARIOGRAM_MAP_H
