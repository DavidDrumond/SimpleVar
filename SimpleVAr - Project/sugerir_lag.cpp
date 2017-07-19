#include "sugerir_lag.h"
#include "ui_sugerir_lag.h"
#include "dados.h"
#include "math.h"


sugerir_lag::sugerir_lag(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sugerir_lag)
{
    ui->setupUi(this);
}

sugerir_lag::~sugerir_lag()
{
    delete ui;
}

void sugerir_lag::on_pushButton_clicked()
{
    QVector<double> distancias;
    double dimension  = var.dimension;
    double d = 0;
    double tamanho = var.variaveis_externas[0].length();
    double min_distancia = 0;
    double minimof = ui->minimo->value();
    double maximof = ui->maximo->value();
    QVector<double> min_vec_dist;

    int t_check = ui->Todas_distancias->isChecked();


    if (dimension ==1){
        for (int i = 0; i < tamanho-1; i++){
            for (int j = i+1; j<tamanho; j++){
                d = pow(var.variaveis_externas[0][i] - var.variaveis_externas[0][j],2);
                if (d > minimof && d < maximof){
                    distancias.push_back(sqrt(d));
                 }
                if (j == 1 && i ==0){
                    min_distancia =pow(var.variaveis_externas[0][i] - var.variaveis_externas[0][j],2);
                }
                if (d < min_distancia){
                    min_distancia = d;
                }
            }
        if (min_distancia > minimof && min_distancia < maximof){
            min_vec_dist.push_back(min_distancia);
        }
      }
    }

    if (dimension ==2){
        for (int i = 0; i < tamanho-1; i++){
            for (int j = i+1; j<tamanho; j++){
                d = pow(var.variaveis_externas[0][i] - var.variaveis_externas[0][j],2) + pow(var.variaveis_externas[1][i] - var.variaveis_externas[1][j],2);            
                if (d > minimof && d < maximof){
                    distancias.push_back(sqrt(d));
                }
                if (j == 1 && i ==0){
                    min_distancia =pow(var.variaveis_externas[0][i] - var.variaveis_externas[0][j],2) + pow(var.variaveis_externas[1][i] - var.variaveis_externas[1][j],2);
                }
                if (d < min_distancia){
                    min_distancia = d;
                }

            }
            if (min_distancia > minimof && min_distancia < maximof){
                min_vec_dist.push_back(min_distancia);
            }
        }
    }

    if (dimension == 3){
        for (int i = 0; i < tamanho-1; i++){
            for (int j = i+1; j<tamanho; j++){
                d = pow(var.variaveis_externas[0][i] - var.variaveis_externas[0][j],2) + pow(var.variaveis_externas[1][i] - var.variaveis_externas[1][j],2) +pow(var.variaveis_externas[2][i] - var.variaveis_externas[2][j],2) ;
                if (d > minimof && d < maximof){
                    distancias.push_back(sqrt(d));
                }
                if (j == 1 && i ==0){
                    min_distancia =pow(var.variaveis_externas[0][i] - var.variaveis_externas[0][j],2) + pow(var.variaveis_externas[1][i] - var.variaveis_externas[1][j],2) +pow(var.variaveis_externas[2][i] - var.variaveis_externas[2][j],2);
                }
                if (d < min_distancia){
                    min_distancia = d;
                }
            }
            if (min_distancia > minimof && min_distancia < maximof){
                min_vec_dist.push_back(min_distancia);
            }
        }
    }

    qSort(distancias);
    qSort(min_vec_dist);
    double n = 0;
    if (t_check == 1){
        n =distancias.length();
    }else{
        n =min_vec_dist.length();
    }
    double media = 0;
    double maximo;
    double minimo;

    if (t_check == 1){

        media = 0;
        maximo = distancias[n-1];
        minimo = distancias[0];
        for (int i =0; i <distancias.length();i++){
            media = media + distancias[i]/n;
        }

    }else{
        media = 0;
        maximo = min_vec_dist[n-1];
        minimo = min_vec_dist[0];
        for (int i =0; i <min_vec_dist.length();i++){
            media = media + min_vec_dist[i]/n;
        }

    }




    QString resposta=  QString::fromUtf8( "-----Estatístisticas------\n")+
                       QString::fromUtf8("Mínimo -->")+QString::number(minimo)+"\n"+
                       QString::fromUtf8("Máximo -->")+QString::number(maximo)+"\n"+
                       QString::fromUtf8("Média -->")+QString::number(media)+"\n";
    ui->resultado->setText(resposta);


    double numero_classes = ui->n_classes->text().toDouble();
    double tamanho_classe = (maximo - minimo)/numero_classes;
    QVector<double> frequencia;
    QVector<double> bins;


    if (t_check == 1){
        int j = 0;
        double min_intervalo =0;
        double max_intervalo=0;
        int freq = 0;
        double relacao = 0;
        for (int i = 0; i < distancias.length(); i++ ){
            min_intervalo = minimo + tamanho_classe*j -1;
            max_intervalo = minimo + tamanho_classe*(j+1)+1;
            if (distancias[i] >= min_intervalo && distancias[i] < max_intervalo){
                freq++;
            }else{
                relacao = freq;
                frequencia.push_back(relacao);
                bins.push_back((max_intervalo+min_intervalo)/2);
                freq = 0;
                j++;
                min_intervalo = minimo + tamanho_classe*j;
                max_intervalo = minimo + tamanho_classe*(j+1);
                if (distancias[i] >= min_intervalo && distancias[i] < max_intervalo){
                    freq++;
                }
            }
        }
     }else{
        int j = 0;
        double min_intervalo =0;
        double max_intervalo=0;
        int freq = 0;
        double relacao = 0;
        for (int i = 0; i < min_vec_dist.length(); i++ ){
            min_intervalo = minimo + tamanho_classe*j;
            max_intervalo = minimo + tamanho_classe*(j+1);
            if (min_vec_dist[i] >= min_intervalo && min_vec_dist[i] < max_intervalo){
                freq++;
            }else{
                relacao = freq;
                frequencia.push_back(relacao);
                bins.push_back((max_intervalo+min_intervalo)/2);
                freq = 0;
                j++;
                min_intervalo = minimo + tamanho_classe*j;
                max_intervalo = minimo + tamanho_classe*(j+1);
                if (min_vec_dist[i] >= min_intervalo && min_vec_dist[i] < max_intervalo){
                    freq++;
                }
            }
        }
      }


    double maxima_frequencia = 0;

    for (int i=0; i < frequencia.length();i++){
        if (frequencia[i] > maxima_frequencia){
            maxima_frequencia = frequencia[i];
        }
    }


    ui->customPlot->clearPlottables();
    ui->customPlot->addGraph();

    QCPBars *bars2 = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
    bars2->setWidth(tamanho_classe);
    bars2->setData(bins,frequencia);
    bars2->setBrush(QColor(10, 100, 50, 70));


     ui->customPlot->graph()->rescaleAxes();
     ui->customPlot->yAxis->setRange(0,maxima_frequencia);
     ui->customPlot->xAxis->setRange(0, maximo);
     ui->customPlot->xAxis->setLabel("Distancias");
     ui->customPlot->yAxis->setLabel("Frequencia");
     ui->customPlot->xAxis->scaleRange(1.7, ui->customPlot->xAxis->range().center());
     ui->customPlot->yAxis->scaleRange(1.7, ui->customPlot->yAxis->range().center());

     ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);


     ui->customPlot->replot();








}
