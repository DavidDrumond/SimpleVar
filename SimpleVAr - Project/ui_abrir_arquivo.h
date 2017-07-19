/********************************************************************************
** Form generated from reading UI file 'abrir_arquivo.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABRIR_ARQUIVO_H
#define UI_ABRIR_ARQUIVO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_abrir_arquivo
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QSpinBox *Numero_variaveis;
    QRadioButton *d1;
    QRadioButton *d2;
    QRadioButton *d3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *nome_arquivo;
    QPushButton *pushButton;
    QTextBrowser *texto;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *remover;
    QPushButton *pushButton_2;

    void setupUi(QDialog *abrir_arquivo)
    {
        if (abrir_arquivo->objectName().isEmpty())
            abrir_arquivo->setObjectName(QStringLiteral("abrir_arquivo"));
        abrir_arquivo->resize(498, 453);
        QIcon icon;
        icon.addFile(QStringLiteral(":/imagens/SimpleVar.png"), QSize(), QIcon::Normal, QIcon::Off);
        abrir_arquivo->setWindowIcon(icon);
        verticalLayout_2 = new QVBoxLayout(abrir_arquivo);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        groupBox = new QGroupBox(abrir_arquivo);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_4->addWidget(label_2);

        Numero_variaveis = new QSpinBox(groupBox);
        Numero_variaveis->setObjectName(QStringLiteral("Numero_variaveis"));

        horizontalLayout_4->addWidget(Numero_variaveis);

        d1 = new QRadioButton(groupBox);
        d1->setObjectName(QStringLiteral("d1"));

        horizontalLayout_4->addWidget(d1);

        d2 = new QRadioButton(groupBox);
        d2->setObjectName(QStringLiteral("d2"));

        horizontalLayout_4->addWidget(d2);

        d3 = new QRadioButton(groupBox);
        d3->setObjectName(QStringLiteral("d3"));

        horizontalLayout_4->addWidget(d3);


        verticalLayout->addLayout(horizontalLayout_4);


        verticalLayout_2->addWidget(groupBox);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(abrir_arquivo);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        nome_arquivo = new QLineEdit(abrir_arquivo);
        nome_arquivo->setObjectName(QStringLiteral("nome_arquivo"));

        horizontalLayout_2->addWidget(nome_arquivo);

        pushButton = new QPushButton(abrir_arquivo);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_2->addWidget(pushButton);


        verticalLayout_2->addLayout(horizontalLayout_2);

        texto = new QTextBrowser(abrir_arquivo);
        texto->setObjectName(QStringLiteral("texto"));

        verticalLayout_2->addWidget(texto);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(abrir_arquivo);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        remover = new QLineEdit(abrir_arquivo);
        remover->setObjectName(QStringLiteral("remover"));

        horizontalLayout_3->addWidget(remover);

        pushButton_2 = new QPushButton(abrir_arquivo);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_3->addWidget(pushButton_2);


        verticalLayout_2->addLayout(horizontalLayout_3);


        retranslateUi(abrir_arquivo);

        QMetaObject::connectSlotsByName(abrir_arquivo);
    } // setupUi

    void retranslateUi(QDialog *abrir_arquivo)
    {
        abrir_arquivo->setWindowTitle(QApplication::translate("abrir_arquivo", "Importar dados", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("abrir_arquivo", "GroupBox", Q_NULLPTR));
        label_2->setText(QApplication::translate("abrir_arquivo", "N\303\272mero de Vari\303\241veis", Q_NULLPTR));
        d1->setText(QApplication::translate("abrir_arquivo", "Dados 1D - (X)", Q_NULLPTR));
        d2->setText(QApplication::translate("abrir_arquivo", "Dados 2D -(XY)", Q_NULLPTR));
        d3->setText(QApplication::translate("abrir_arquivo", "Dados 3D - (XYZ)", Q_NULLPTR));
        label->setText(QApplication::translate("abrir_arquivo", "Novo Arquivo", Q_NULLPTR));
        pushButton->setText(QApplication::translate("abrir_arquivo", "...", Q_NULLPTR));
        label_3->setText(QApplication::translate("abrir_arquivo", "Remover Valores que contenham", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("abrir_arquivo", "Importar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class abrir_arquivo: public Ui_abrir_arquivo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABRIR_ARQUIVO_H
