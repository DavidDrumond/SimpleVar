#include "abrir_arquivo.h"
#include "ui_abrir_arquivo.h"
#include "QFileDialog"
#include <QMessageBox>
#include "dados.h"
#include <QVector>
#include <QTextStream>
#include <stdio.h>
#include <QDebug>

abrir_arquivo::abrir_arquivo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::abrir_arquivo)
{
    ui->setupUi(this);
}

abrir_arquivo::~abrir_arquivo()
{
    delete ui;
}

void abrir_arquivo::on_pushButton_clicked()
{

    // Receber os parametros do aruqivo ui


    int nvar = ui->Numero_variaveis->text().toInt();
    int check1 = ui->d1->isChecked();
    int check2 = ui->d2->isChecked();
    int check3 = ui->d3->isChecked();
    int valor1 = 0;

    if (check1 == 1){
        valor1 = 1;
    }
    if (check2 == 1){
        valor1 = 2;
    }
    if (check3 == 1){
        valor1 = 3;
    }

    int valortotal = valor1 + nvar;

    // Abrir o arquivo de dados

    QString filename = QFileDialog::getOpenFileName(this);
    ui->nome_arquivo->setText(filename);


    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "Erro", "Nome de arquivo não selecionado");
    }
    else{
        QString TextoCaixa;
        QTextStream in(&file);


        QString line = in.readLine();
        TextoCaixa = TextoCaixa + "\n" + line;

        var.verificar_arquivo = 1;
        int contador = 0;
        while(!in.atEnd()) {
            line = in.readLine();
            QStringList fields= line.split(QRegExp("\\s+"), QString::SkipEmptyParts);
            if (fields.size() != valortotal){
                 QMessageBox::information(0, "Erro", "Numero de variaveis e a dimensao do espaco nao competem");
                 var.verificar_arquivo = 0;
                 break;
            }
            TextoCaixa = TextoCaixa + "\n" + line;
            contador ++;

        }
        file.close();
        var.number_dados = contador;
        ui->texto->setText(TextoCaixa);
    }







}

void abrir_arquivo::on_pushButton_2_clicked()
{

    if (var.verificar_arquivo == 1){

            var.variaveis_externas.clear();
            var.cabecalho.clear();

            QString filename = ui->nome_arquivo->text();
            QString remover = ui->remover->text();
            int nvar = ui->Numero_variaveis->text().toInt();
            int check1 = ui->d1->isChecked();
            int check2 = ui->d2->isChecked();
            int check3 = ui->d3->isChecked();
            int valor1 = 0;

            if (check1 == 1){
                valor1 = 1;
            }
            if (check2 == 1){
                valor1 = 2;
            }
            if (check3 == 1){
                valor1 = 3;
            }

            var.number_variables = nvar;
            var.dimension = valor1;

            QFile file(filename);
            if(!file.open(QIODevice::ReadOnly)) {
                QMessageBox::information(0, "error", file.errorString());
            }
            else{

                QTextStream in(&file);
                QString line = in.readLine();
                QStringList fields= line.split(QRegExp("\\s+"), QString::SkipEmptyParts);
                QVector<QString> cabecalho;
                for (int i = 0; i < fields.size(); i++){
                    cabecalho.append(fields[i]);
                }
                var.cabecalho = cabecalho;

                for (int j = 0; j < (var.dimension+ var.number_variables);j++){
                    QVector<double> valores;
                    while(!in.atEnd()) {
                        QString line = in.readLine();
                        QStringList fields= line.split(QRegExp("\\s+"), QString::SkipEmptyParts);
                        QString dado = fields[j];
                        if (dado == remover){
                            valores.push_back(-999.999);
                        }
                        else{
                            valores.push_back(dado.toDouble());
                        }
                    }
                    var.variaveis_externas.push_back(valores);
                    file.close();
                    file.open(QIODevice::ReadOnly);
                    line = in.readLine();
                }
                file.close();
                QMessageBox::information(0, "Aviso", "Dados importados com sucesso");
                this->close();

            }
            }else{
              QMessageBox *m = new QMessageBox();
              m->setText("Por favor recarregue o arquivo de dados!!!");
              m->show();
            }

}


