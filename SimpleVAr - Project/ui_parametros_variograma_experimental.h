/********************************************************************************
** Form generated from reading UI file 'parametros_variograma_experimental.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARAMETROS_VARIOGRAMA_EXPERIMENTAL_H
#define UI_PARAMETROS_VARIOGRAMA_EXPERIMENTAL_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_Parametros_Variograma_Experimental
{
public:
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QComboBox *cabeca;
    QLabel *label_2;
    QComboBox *rabo;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QSpinBox *nlags;
    QLabel *label_4;
    QDoubleSpinBox *lagsize;
    QLabel *label_5;
    QDoubleSpinBox *linear_tol;
    QHBoxLayout *horizontalLayout;
    QLabel *label_6;
    QSpinBox *ndirecoes;
    QCheckBox *Varpriori;
    QCheckBox *showpar;
    QCheckBox *Todos;
    QProgressBar *progressBar;
    QTableWidget *tabela;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QCustomPlot *customPlot;

    void setupUi(QDialog *Parametros_Variograma_Experimental)
    {
        if (Parametros_Variograma_Experimental->objectName().isEmpty())
            Parametros_Variograma_Experimental->setObjectName(QStringLiteral("Parametros_Variograma_Experimental"));
        Parametros_Variograma_Experimental->resize(1188, 634);
        Parametros_Variograma_Experimental->setMinimumSize(QSize(0, 0));
        QIcon icon;
        icon.addFile(QStringLiteral(":/imagens/SimpleVar.png"), QSize(), QIcon::Normal, QIcon::Off);
        Parametros_Variograma_Experimental->setWindowIcon(icon);
        horizontalLayout_2 = new QHBoxLayout(Parametros_Variograma_Experimental);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        groupBox_3 = new QGroupBox(Parametros_Variograma_Experimental);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        verticalLayout = new QVBoxLayout(groupBox_3);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(groupBox_3);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        cabeca = new QComboBox(groupBox);
        cabeca->setObjectName(QStringLiteral("cabeca"));

        gridLayout_2->addWidget(cabeca, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 0, 2, 1, 1);

        rabo = new QComboBox(groupBox);
        rabo->setObjectName(QStringLiteral("rabo"));

        gridLayout_2->addWidget(rabo, 0, 3, 1, 1);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(groupBox_3);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        nlags = new QSpinBox(groupBox_2);
        nlags->setObjectName(QStringLiteral("nlags"));
        nlags->setMinimum(1);
        nlags->setMaximum(999999);

        gridLayout->addWidget(nlags, 0, 1, 1, 1);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        lagsize = new QDoubleSpinBox(groupBox_2);
        lagsize->setObjectName(QStringLiteral("lagsize"));
        lagsize->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        lagsize->setMinimum(0.01);
        lagsize->setMaximum(1e+10);

        gridLayout->addWidget(lagsize, 1, 1, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        linear_tol = new QDoubleSpinBox(groupBox_2);
        linear_tol->setObjectName(QStringLiteral("linear_tol"));
        linear_tol->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        linear_tol->setMinimum(0.01);
        linear_tol->setMaximum(1e+10);

        gridLayout->addWidget(linear_tol, 2, 1, 1, 1);


        verticalLayout->addWidget(groupBox_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout->addWidget(label_6);

        ndirecoes = new QSpinBox(groupBox_3);
        ndirecoes->setObjectName(QStringLiteral("ndirecoes"));
        ndirecoes->setMinimum(1);
        ndirecoes->setMaximum(100);

        horizontalLayout->addWidget(ndirecoes);


        verticalLayout->addLayout(horizontalLayout);

        Varpriori = new QCheckBox(groupBox_3);
        Varpriori->setObjectName(QStringLiteral("Varpriori"));

        verticalLayout->addWidget(Varpriori);

        showpar = new QCheckBox(groupBox_3);
        showpar->setObjectName(QStringLiteral("showpar"));

        verticalLayout->addWidget(showpar);

        Todos = new QCheckBox(groupBox_3);
        Todos->setObjectName(QStringLiteral("Todos"));

        verticalLayout->addWidget(Todos);

        progressBar = new QProgressBar(groupBox_3);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(0);

        verticalLayout->addWidget(progressBar);


        verticalLayout_2->addWidget(groupBox_3);

        tabela = new QTableWidget(Parametros_Variograma_Experimental);
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
        if (tabela->rowCount() < 1)
            tabela->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tabela->setVerticalHeaderItem(0, __qtablewidgetitem8);
        tabela->setObjectName(QStringLiteral("tabela"));

        verticalLayout_2->addWidget(tabela);

        pushButton = new QPushButton(Parametros_Variograma_Experimental);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout_2->addWidget(pushButton);

        pushButton_2 = new QPushButton(Parametros_Variograma_Experimental);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout_2->addWidget(pushButton_2);


        horizontalLayout_2->addLayout(verticalLayout_2);

        customPlot = new QCustomPlot(Parametros_Variograma_Experimental);
        customPlot->setObjectName(QStringLiteral("customPlot"));
        customPlot->setMinimumSize(QSize(800, 550));
        customPlot->setBaseSize(QSize(800, 800));

        horizontalLayout_2->addWidget(customPlot);


        retranslateUi(Parametros_Variograma_Experimental);

        QMetaObject::connectSlotsByName(Parametros_Variograma_Experimental);
    } // setupUi

    void retranslateUi(QDialog *Parametros_Variograma_Experimental)
    {
        Parametros_Variograma_Experimental->setWindowTitle(QApplication::translate("Parametros_Variograma_Experimental", "Variograma experimental", Q_NULLPTR));
        groupBox_3->setTitle(QString());
        groupBox->setTitle(QApplication::translate("Parametros_Variograma_Experimental", "Vari\303\241veis ", Q_NULLPTR));
        label->setText(QApplication::translate("Parametros_Variograma_Experimental", "Cabe\303\247a", Q_NULLPTR));
        label_2->setText(QApplication::translate("Parametros_Variograma_Experimental", "Rabo ", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("Parametros_Variograma_Experimental", "Par\303\242metros do variograma", Q_NULLPTR));
        label_3->setText(QApplication::translate("Parametros_Variograma_Experimental", "N\303\272mero de Lags", Q_NULLPTR));
        label_4->setText(QApplication::translate("Parametros_Variograma_Experimental", "Tamanho do Lag", Q_NULLPTR));
        label_5->setText(QApplication::translate("Parametros_Variograma_Experimental", "Toler\303\242ncia Linear", Q_NULLPTR));
        label_6->setText(QApplication::translate("Parametros_Variograma_Experimental", "N\303\272mero de Dire\303\247\303\265es", Q_NULLPTR));
        Varpriori->setText(QApplication::translate("Parametros_Variograma_Experimental", "Mostrar vari\303\242ncia a priori dos dados", Q_NULLPTR));
        showpar->setText(QApplication::translate("Parametros_Variograma_Experimental", "Mostrar n\302\260 de pares do variograma experimental", Q_NULLPTR));
        Todos->setText(QApplication::translate("Parametros_Variograma_Experimental", "Todos os variogramas em um gr\303\241fico", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tabela->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Parametros_Variograma_Experimental", "Azimute", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tabela->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Parametros_Variograma_Experimental", "Mergulho", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tabela->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Parametros_Variograma_Experimental", "Tol angular h", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tabela->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("Parametros_Variograma_Experimental", "Tol angular v", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tabela->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("Parametros_Variograma_Experimental", "Banda V", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = tabela->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("Parametros_Variograma_Experimental", "Banda H", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = tabela->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("Parametros_Variograma_Experimental", "Modelo", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = tabela->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("Parametros_Variograma_Experimental", "Cor", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem8 = tabela->verticalHeaderItem(0);
        ___qtablewidgetitem8->setText(QApplication::translate("Parametros_Variograma_Experimental", "1", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Parametros_Variograma_Experimental", "Calcular", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Parametros_Variograma_Experimental", "Salvar Figura", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Parametros_Variograma_Experimental: public Ui_Parametros_Variograma_Experimental {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARAMETROS_VARIOGRAMA_EXPERIMENTAL_H
