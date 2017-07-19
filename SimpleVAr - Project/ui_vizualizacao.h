/********************************************************************************
** Form generated from reading UI file 'vizualizacao.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIZUALIZACAO_H
#define UI_VIZUALIZACAO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_vizualizacao
{
public:
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton_3;
    QHBoxLayout *horizontalLayout_2;
    QCustomPlot *customPlot;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QSpinBox *Mergulho;
    QSlider *verticalSlider;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSlider *horizontalSlider;
    QSpinBox *Azimute;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QSpinBox *nclasses;
    QLabel *label_5;
    QComboBox *cabeca;
    QPushButton *pushButton;
    QTableWidget *tabela;
    QPushButton *pushButton_2;

    void setupUi(QDialog *vizualizacao)
    {
        if (vizualizacao->objectName().isEmpty())
            vizualizacao->setObjectName(QStringLiteral("vizualizacao"));
        vizualizacao->resize(690, 609);
        QIcon icon;
        icon.addFile(QStringLiteral(":/imagens/SimpleVar.png"), QSize(), QIcon::Normal, QIcon::Off);
        vizualizacao->setWindowIcon(icon);
        verticalLayout_3 = new QVBoxLayout(vizualizacao);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        pushButton_3 = new QPushButton(vizualizacao);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout_3->addWidget(pushButton_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        customPlot = new QCustomPlot(vizualizacao);
        customPlot->setObjectName(QStringLiteral("customPlot"));
        customPlot->setMinimumSize(QSize(600, 350));

        horizontalLayout_2->addWidget(customPlot);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_2 = new QLabel(vizualizacao);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        Mergulho = new QSpinBox(vizualizacao);
        Mergulho->setObjectName(QStringLiteral("Mergulho"));
        Mergulho->setEnabled(false);
        Mergulho->setMinimum(-180);
        Mergulho->setMaximum(180);

        verticalLayout->addWidget(Mergulho);


        verticalLayout_2->addLayout(verticalLayout);

        verticalSlider = new QSlider(vizualizacao);
        verticalSlider->setObjectName(QStringLiteral("verticalSlider"));
        verticalSlider->setMinimum(-180);
        verticalSlider->setMaximum(180);
        verticalSlider->setOrientation(Qt::Vertical);

        verticalLayout_2->addWidget(verticalSlider);


        horizontalLayout_2->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(vizualizacao);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        horizontalSlider = new QSlider(vizualizacao);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setMinimumSize(QSize(500, 0));
        horizontalSlider->setMinimum(-360);
        horizontalSlider->setMaximum(360);
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(horizontalSlider);

        Azimute = new QSpinBox(vizualizacao);
        Azimute->setObjectName(QStringLiteral("Azimute"));
        Azimute->setEnabled(false);
        Azimute->setMinimum(-360);
        Azimute->setMaximum(360);

        horizontalLayout->addWidget(Azimute);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_4 = new QLabel(vizualizacao);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_3->addWidget(label_4);

        nclasses = new QSpinBox(vizualizacao);
        nclasses->setObjectName(QStringLiteral("nclasses"));

        horizontalLayout_3->addWidget(nclasses);

        label_5 = new QLabel(vizualizacao);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_3->addWidget(label_5);

        cabeca = new QComboBox(vizualizacao);
        cabeca->setObjectName(QStringLiteral("cabeca"));

        horizontalLayout_3->addWidget(cabeca);

        pushButton = new QPushButton(vizualizacao);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_3->addWidget(pushButton);


        verticalLayout_3->addLayout(horizontalLayout_3);

        tabela = new QTableWidget(vizualizacao);
        if (tabela->columnCount() < 3)
            tabela->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tabela->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tabela->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tabela->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tabela->setObjectName(QStringLiteral("tabela"));

        verticalLayout_3->addWidget(tabela);

        pushButton_2 = new QPushButton(vizualizacao);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout_3->addWidget(pushButton_2);


        retranslateUi(vizualizacao);
        QObject::connect(verticalSlider, SIGNAL(sliderMoved(int)), Mergulho, SLOT(setValue(int)));
        QObject::connect(horizontalSlider, SIGNAL(sliderMoved(int)), Azimute, SLOT(setValue(int)));

        QMetaObject::connectSlotsByName(vizualizacao);
    } // setupUi

    void retranslateUi(QDialog *vizualizacao)
    {
        vizualizacao->setWindowTitle(QApplication::translate("vizualizacao", "Vizualizar Dados", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("vizualizacao", "Restaurar vis\303\243o", Q_NULLPTR));
        label_2->setText(QApplication::translate("vizualizacao", "Mergulho", Q_NULLPTR));
        label->setText(QApplication::translate("vizualizacao", "Azimute", Q_NULLPTR));
        label_4->setText(QApplication::translate("vizualizacao", "N\303\272mero de classes", Q_NULLPTR));
        label_5->setText(QApplication::translate("vizualizacao", "Vari\303\241vel", Q_NULLPTR));
        pushButton->setText(QApplication::translate("vizualizacao", "Atribuir classes", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tabela->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("vizualizacao", "M\303\255nimo", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tabela->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("vizualizacao", "M\303\241ximo", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tabela->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("vizualizacao", "Cor ", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("vizualizacao", "Salvar Figura", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class vizualizacao: public Ui_vizualizacao {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIZUALIZACAO_H
