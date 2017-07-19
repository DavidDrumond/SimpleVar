#include "modelagem_variograma.h"
#include "ui_modelagem_variograma.h"
#include "dados.h"
#include <QMessageBox>
#include <math.h>
#define _USE_MATH_DEFINES
#include <cmath>
#include "delegate.h"

Modelagem_Variograma::Modelagem_Variograma(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Modelagem_Variograma)
{
    ui->setupUi(this);

    ui->tabela->setItemDelegate(new Delegate);

    ui->tabela->setRowCount(1);


    QComboBox* combo = new QComboBox();
    combo->addItem("Exponencial");
    combo->addItem("Gaussiano");
    combo->addItem("Esférico");


    ui->tabela->setItem(0,7, new QTableWidgetItem);
    ui->tabela->setCellWidget(0, 7,combo);


    ui->Grafico_prop->setRowCount(static_cast<int>(var.numero_variogramas));


    for (int i = 0 ; i < var.numero_variogramas; i++){
        for (int j= 0; j < 3; j++){
            if (j ==0){
                ui->Grafico_prop->setItem(i,j,new QTableWidgetItem);
                QLabel * label = new QLabel();
                label->setText(QString::number(i+1));
                ui->Grafico_prop->setCellWidget(i,j,label);
            }

            if (j==1){
                ui->Grafico_prop->setItem(i,j,new QTableWidgetItem);
                QComboBox* combo2 = new QComboBox();
                combo2->addItem("Dissimilaridade");
                combo2->addItem("Similaridade");
                ui->Grafico_prop->setCellWidget(i, j,combo2);
            }
            if (j==2){
                ui->Grafico_prop->setItem(i,j,new QTableWidgetItem);
                QComboBox* combo3 = new QComboBox();
                combo3->addItem("Não");
                combo3->addItem("Sim");
                ui->Grafico_prop->setCellWidget(i, j,combo3);
            }

        }
    }


    // PRINTAR OS VARIOGRAMAS




    QVector<QCPScatterStyle::ScatterShape> shapes;
    shapes << QCPScatterStyle::ssCross;
    shapes << QCPScatterStyle::ssPlus;
    shapes << QCPScatterStyle::ssCircle;
    shapes << QCPScatterStyle::ssDisc;
    shapes << QCPScatterStyle::ssSquare;
    shapes << QCPScatterStyle::ssDiamond;
    shapes << QCPScatterStyle::ssStar;
    shapes << QCPScatterStyle::ssTriangle;
    shapes << QCPScatterStyle::ssTriangleInverted;
    shapes << QCPScatterStyle::ssCrossSquare;
    shapes << QCPScatterStyle::ssPlusSquare;
    shapes << QCPScatterStyle::ssCrossCircle;
    shapes << QCPScatterStyle::ssPlusCircle;
    shapes << QCPScatterStyle::ssPeace;
    shapes << QCPScatterStyle::ssCustom;

    int tipo_ponto = 0;
    int k = 0;
    int p = 0;

    if (var.numero_variogramas !=0 ){

            int var_aceito = ui->Varpriori->isChecked();
            int show_par = ui->showpar->isChecked();

            ui->customPlot->plotLayout()->clear();

            for (int i = 0; i < var.numero_variogramas; i++){

                QPen pena;
                pena.setColor(var.cores[i]);


                QPen pena2;
                pena2.setColor(Qt::green);
                pena2.setStyle(Qt::DashDotLine);
                QString titulo = (QString::fromUtf8("\u03C6") +" (h) - Azm: " + QString::number(var.v_azimutes[i][0]) + " - Dip: " +QString::number(var.v_dips[i][0]) );

                if (k == 3){
                    k = 0;
                    p++;
                    p++;
                    p++;
                }
                if (tipo_ponto >13 ){
                    tipo_ponto = 0;
                }


                QCPTextElement *title = new QCPTextElement(ui->customPlot);
                title->setText(titulo);
                title->setFont(QFont("sans", 7, QFont::Bold));
                ui->customPlot->plotLayout()->addElement(p, k, title);

                QCPAxisRect* r = new QCPAxisRect(ui->customPlot);
                ui->customPlot->plotLayout()->addElement(p+1, k, r);

                if (show_par == 1){
                    for (int j=0; j < var.var_pares[i].length();j++){
                        QCPItemText *pares_texto = new QCPItemText(ui->customPlot);

                        pares_texto->setClipToAxisRect(true);
                        pares_texto->setClipAxisRect(r);
                        pares_texto->position->setAxisRect(r);
                        pares_texto->position->setAxes(r->axis(QCPAxis::atBottom), r->axis(QCPAxis::atLeft));
                        pares_texto->position->setType(QCPItemPosition::ptPlotCoords);
                        pares_texto->position->setCoords(var.v_lags[i][j],(var.v_continuidades[i][j]+0.5));
                        pares_texto->setRotation(-40);
                        pares_texto->setText(QString::number(var.var_pares[i][j]));
                        pares_texto->setFont(QFont(font().family(), 10));
                    }
                }



                QCPTextElement *title2  = new QCPTextElement(ui->customPlot);
                title2->setText("H");
                title2->setFont(QFont("sans",7, QFont::Bold));
                ui->customPlot->plotLayout()->addElement(p+2,k,title2);

                QCPGraph *Grafico = ui->customPlot->addGraph(r->axis(QCPAxis::atBottom), r->axis(QCPAxis::atLeft));
                ui->customPlot->graph()->setScatterStyle(QCPScatterStyle(shapes.at(tipo_ponto), 10));


                Grafico->setName(titulo);
                Grafico->setData(var.v_lags[i],var.v_continuidades[i]);
                if (var_aceito == 1){

                    QCPGraph *Grafico2 = ui->customPlot->addGraph(r->axis(QCPAxis::atBottom), r->axis(QCPAxis::atLeft));
                    ui->customPlot->graph()->setScatterStyle(QCPScatterStyle(shapes.at(0), 1));

                    Grafico2->setData(var.v_lags[i],var.v_var_priori[i]);
                    Grafico2->setName("Variancia a Priori");
                    Grafico2->setPen(pena2);
                }

                Grafico->rescaleAxes();
                Grafico->setPen(pena);

                ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

                tipo_ponto++;
                k++;
            }

            ui->customPlot->replot();
    }
    else{
        QMessageBox *box = new QMessageBox();
        box->setText("Variograma experimental não calculado");
        box->show();
    }
}

Modelagem_Variograma::~Modelagem_Variograma()
{
    delete ui;
}


QString identificar_virgula2(QString palavra){
    QString retorno;
    for (int i = 0; i < palavra.length(); i++){
         if (palavra[i] == ','){
             retorno = retorno + ".";
         }
         else{
             retorno = retorno + palavra[i];
         }
    }
    return retorno;

}


void Modelagem_Variograma::on_n_estruturas_valueChanged(int arg1)
{
    int numero_linhas = ui->n_estruturas->text().toInt();
    ui->tabela->setRowCount(numero_linhas);

    for (int i = 0; i < numero_linhas; i++){

        QComboBox* combo = new QComboBox();
        combo->addItem("Exponencial");
        combo->addItem("Gaussiano");
        combo->addItem("Esférico");

        ui->tabela->setItem(i,7, new QTableWidgetItem);
        ui->tabela->setCellWidget(i, 7,combo);
    }
}

void Modelagem_Variograma::on_pushButton_clicked()
{
    if (var.numero_variogramas != 0){

        int numero_estruturas = ui->n_estruturas->text().toInt();
        bool teste = true;
        bool teste2 = true;

        for (int i = 0; i< numero_estruturas; i++){
            for (int j=0; j< 7; j++){
                if (!ui->tabela->item(i,j) || ui->tabela->item(i,j)->text().isEmpty()){
                    teste= false;
                }
            }
        }


        if(teste == false){
            QMessageBox msgBox;
            msgBox.setText("Uma das celulas da tabela esta vazia");
            msgBox.exec();
        }

        if (teste == true && teste2 == true){


            double efeito_pepita = ui->Efeito_Pepita->value();


            QVector<double> azm;
            QVector<double> dip;
            QVector<double> plunge;
            QVector<double> max_range;
            QVector<double> med_range;
            QVector<double> min_range;
            QVector<double> contribuicao;
            QVector<QString> modelo;
            QVector<QString> classe;
            QVector<QString> inverter;

            QString entrada;
            for (int i = 0; i < numero_estruturas; i++){
                for (int j = 0; j < 8; j++){
                    switch(j){
                        case 0:
                            entrada = identificar_virgula2(ui->tabela->item(i,j)->text());
                            azm.push_back(entrada.toDouble());
                            break;
                        case 1:
                            entrada = identificar_virgula2(ui->tabela->item(i,j)->text());
                            dip.push_back(entrada.toDouble());
                            break;
                        case 2:
                            entrada = identificar_virgula2(ui->tabela->item(i,j)->text());
                            plunge.push_back(entrada.toDouble());
                            break;
                        case 3:
                            entrada = identificar_virgula2(ui->tabela->item(i,j)->text());
                            max_range.push_back(entrada.toDouble());
                            break;
                        case 4:
                            entrada = identificar_virgula2(ui->tabela->item(i,j)->text());
                            med_range.push_back(entrada.toDouble());
                            break;
                        case 5:
                            entrada = identificar_virgula2(ui->tabela->item(i,j)->text());
                            min_range.push_back(entrada.toDouble());
                            break;
                        case 6:
                            entrada = identificar_virgula2(ui->tabela->item(i,j)->text());
                            contribuicao.push_back(entrada.toDouble());

                    }
                    if (j == 7){

                        QComboBox *myCB = qobject_cast<QComboBox*>(ui->tabela->cellWidget(i,j));
                        modelo.push_back(myCB->currentText());

                    }
                }                
            }

            for (int i = 0; i < var.numero_variogramas; i++){
                for (int j = 1; j < 3; j++){
                    if (j == 1){
                        QComboBox *myCB = qobject_cast<QComboBox*>(ui->Grafico_prop->cellWidget(i,j));
                        classe.push_back(myCB->currentText());
                    }
                    if (j == 2){
                        QComboBox *myCB = qobject_cast<QComboBox*>(ui->Grafico_prop->cellWidget(i,j));
                        inverter.push_back(myCB->currentText());
                    }
                }
            }

            // Determinar os alcances para cada estrtutura e para cada variograma experimental

            QVector<QVector<double>> alcances;

            for (int i =0 ; i < numero_estruturas; i++){
                QVector<double> alcance;
                for (int j=0; j < var.numero_variogramas; j++){
                    double z = sin(var.v_dips[j][0]*M_PI/180);
                    double x = cos(var.v_dips[j][0]*M_PI/180)*sin(var.v_azimutes[j][0]*M_PI/180);
                    double y = cos(var.v_dips[j][0]*M_PI/180)*cos(var.v_azimutes[j][0]*M_PI/180);

                    double alfa = (azm[i])*M_PI/180;
                    double beta = (dip[i])*M_PI/180;
                    double gamma = (plunge[i])*M_PI/180;

                    // ROTACIONE NO AZIMUTE

                    double xrot1 = x*cos(alfa) - y*sin(alfa);
                    double yrot1 = x*sin(alfa) + y*cos(alfa);
                    double zrot1 = z;

                    // ROTACIONE NO MERGULHO

                    double xrot2 = xrot1;
                    double yrot2 = yrot1*cos(beta) -zrot1*sin(beta);
                    double zrot2 = yrot1*sin(beta) +zrot1*cos(beta);

                    // ROTACIONE NO PLUNGE

                    double xrot3 = xrot2*cos(gamma)- zrot2*sin(gamma);
                    double yrot3 = yrot2;
                    double zrot3 = xrot2*sin(gamma) +zrot2*cos(gamma);

                    yrot3 = yrot3*max_range[i];
                    xrot3 = xrot3*med_range[i];
                    zrot3 = zrot3*min_range[i];

                    double range = sqrt(yrot3*yrot3 +xrot3*xrot3 +zrot3*zrot3);
                    alcance.append(range);

                }
                alcances.append(alcance);
            }

            // Defina o vetor de lags para o modelo

            QVector<double> lag_distance;
            for (int i = 0; i < 500; i++){
                lag_distance.push_back(var.max_lag_distance/500*i);
            }

            // Calcule os modelos de variograma para cada estrutura e para cada variograma

            QVector<QVector <double>> Variogram_models;




            for (int j=0; j < var.numero_variogramas; j++){
                    QVector<double> Variogram_model;
                    for (int p=0; p < 500; p++){
                        double soma = 0;
                        for (int i =0 ; i < numero_estruturas; i++){

                            if (alcances[i][j] > 0){
                                if (modelo[i] == "Exponencial" && classe[j] == "Dissimilaridade"){
                                    soma = soma + (contribuicao[i]*(1-exp(-3*lag_distance[p]/alcances[i][j])));
                                }
                                if (modelo[i] == "Exponencial" && classe[j] == "Similaridade"){
                                    soma = soma + (contribuicao[i]*(exp(-3*lag_distance[p]/alcances[i][j])));
                                }
                                if (modelo[i] == "Gaussiano" && classe[j] == "Dissimilaridade"){
                                    soma = soma + (contribuicao[i]*(1-exp(-3*lag_distance[p]*lag_distance[p]/(alcances[i][j]*alcances[i][j]))));
                                }
                                if (modelo[i] == "Gaussiano" && classe[j] == "Similaridade"){
                                    soma = soma + (contribuicao[i]*(exp(-3*lag_distance[p]*lag_distance[p]/(alcances[i][j]*alcances[i][j]))));
                                }
                                 if (modelo[i] == "Esférico" && classe[j] == "Dissimilaridade"){
                                     if (lag_distance[p] < alcances[i][j]){
                                        soma = soma + contribuicao[i]*(1.5*lag_distance[p]/alcances[i][j] - 0.5*pow((lag_distance[p]/alcances[i][j]),3));
                                     }
                                     else{
                                         soma = contribuicao[i];
                                     }

                                 }
                                 if (modelo[i] == "Esférico" && classe[j] == "Similaridade"){
                                     if (lag_distance[p] < alcances[i][j]){
                                        soma = soma + contribuicao[i]*(1 - 1.5*lag_distance[p]/alcances[i][j] + 0.5*pow((lag_distance[p]/alcances[i][j]),3));
                                     }
                                     else{
                                         soma = 0;
                                     }

                                 }
                            }
                        }
                        soma =soma +efeito_pepita;
                        Variogram_model.push_back(soma);
                    }
                    Variogram_models.append(Variogram_model);
              }

            qDebug() << Variogram_models;


              //   PLOTE OS MODELOS DE VARIOGRAMA

            // PRINTAR OS VARIOGRAMAS

            QVector<QCPScatterStyle::ScatterShape> shapes;
            shapes << QCPScatterStyle::ssCross;
            shapes << QCPScatterStyle::ssPlus;
            shapes << QCPScatterStyle::ssCircle;
            shapes << QCPScatterStyle::ssDisc;
            shapes << QCPScatterStyle::ssSquare;
            shapes << QCPScatterStyle::ssDiamond;
            shapes << QCPScatterStyle::ssStar;
            shapes << QCPScatterStyle::ssTriangle;
            shapes << QCPScatterStyle::ssTriangleInverted;
            shapes << QCPScatterStyle::ssCrossSquare;
            shapes << QCPScatterStyle::ssPlusSquare;
            shapes << QCPScatterStyle::ssCrossCircle;
            shapes << QCPScatterStyle::ssPlusCircle;
            shapes << QCPScatterStyle::ssPeace;
            shapes << QCPScatterStyle::ssCustom;

            int tipo_ponto = 0;
            int k = 0;
            int p = 0;

            int var_aceito = ui->Varpriori->isChecked();
            int show_par = ui->showpar->isChecked();

            ui->customPlot->plotLayout()->clear();

            for (int i = 0; i < var.numero_variogramas; i++){

                QPen pena;
                pena.setColor(var.cores[i]);


                QPen pena2;
                pena2.setColor(Qt::green);
                pena2.setStyle(Qt::DashDotLine);

                QPen pena3;
                pena3.setColor(Qt::blue);
                pena3.setStyle(Qt::SolidLine);


                QString titulo = (QString::fromUtf8("\u03C6") +" (h) - Azm: " + QString::number(var.v_azimutes[i][0]) + " - Dip: " +QString::number(var.v_dips[i][0]) );

                if (k == 3){
                    k = 0;
                    p++;
                    p++;
                    p++;
                }
                if (tipo_ponto >13 ){
                    tipo_ponto = 0;
                }


                QCPTextElement *title = new QCPTextElement(ui->customPlot);
                title->setText(titulo);
                title->setFont(QFont("sans", 7, QFont::Bold));
                ui->customPlot->plotLayout()->addElement(p, k, title);

                QCPAxisRect* r = new QCPAxisRect(ui->customPlot);
                ui->customPlot->plotLayout()->addElement(p+1, k, r);



                QCPGraph *Grafico = ui->customPlot->addGraph(r->axis(QCPAxis::atBottom), r->axis(QCPAxis::atLeft));
                ui->customPlot->graph()->setScatterStyle(QCPScatterStyle(shapes.at(tipo_ponto), 10));
                Grafico->setPen(pena);

                QVector<double> invertido;
                if (inverter[i] == "Não"){
                    if(var.v_continuidades[i].length() > 0){
                        Grafico->setData(var.v_lags[i],var.v_continuidades[i]);
                    }
                }
                else{

                    for (int h =0; h<var.v_continuidades[i].length();h++){
                        invertido.push_back(var.v_var_priori[i][0] - var.v_continuidades[i][h]);
                    }
                    Grafico->setData(var.v_lags[i],invertido);
                }

                if (show_par == 1){
                    for (int j=0; j < var.var_pares[i].length();j++){
                        QCPItemText *pares_texto = new QCPItemText(ui->customPlot);

                        pares_texto->setClipToAxisRect(true);
                        pares_texto->setClipAxisRect(r);
                        pares_texto->position->setAxisRect(r);
                        pares_texto->position->setAxes(r->axis(QCPAxis::atBottom), r->axis(QCPAxis::atLeft));
                        pares_texto->position->setType(QCPItemPosition::ptPlotCoords);

                        if (inverter[i] == "Não"){
                            pares_texto->position->setCoords(var.v_lags[i][j],(var.v_continuidades[i][j]+0.5));
                        }else{
                             pares_texto->position->setCoords(var.v_lags[i][j],(invertido[j]));
                        }
                        pares_texto->setRotation(-40);
                        pares_texto->setText(QString::number(var.var_pares[i][j]));
                        pares_texto->setFont(QFont(font().family(), 10));
                    }
                }



                QCPTextElement *title2  = new QCPTextElement(ui->customPlot);
                title2->setText("H");
                title2->setFont(QFont("sans",7, QFont::Bold));
                ui->customPlot->plotLayout()->addElement(p+2,k,title2);


                QCPGraph *Grafico3 = ui->customPlot->addGraph(r->axis(QCPAxis::atBottom), r->axis(QCPAxis::atLeft));
                Grafico3->setPen(pena3);


                Grafico->setName(titulo);




                if(Variogram_models[i].length() > 0){
                    Grafico3->setData(lag_distance,Variogram_models[i]);
                }

                if (var_aceito == 1){

                    QCPGraph *Grafico2 = ui->customPlot->addGraph(r->axis(QCPAxis::atBottom), r->axis(QCPAxis::atLeft));
                    ui->customPlot->graph()->setScatterStyle(QCPScatterStyle(shapes.at(0), 1));

                    if (var.v_var_priori[i].length() > 0){
                        Grafico2->setData(var.v_lags_variancia[i],var.v_var_priori[i]);
                    }
                    Grafico2->setName("Variancia a Priori");
                    Grafico2->setPen(pena2);
                }

                Grafico->rescaleAxes();



                ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);





                tipo_ponto++;
                k++;
            }

            ui->customPlot->replot();


        }

    }
    else{
        QMessageBox *msg = new QMessageBox();
        msg->setText("Por favor, calcule o variograma experimental!");
        msg->show();
    }
}

void Modelagem_Variograma::on_pushButton_2_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Salvar Imagem"),"",tr("Images (*.png *.xpm *.jpg)"));

    if (fileName != ""){
        ui->customPlot->saveJpg(fileName,0,0,1.0,-1,96);

        QMessageBox msgBox;
        msgBox.setText("Figura Salva");
        msgBox.exec();
    }
}
