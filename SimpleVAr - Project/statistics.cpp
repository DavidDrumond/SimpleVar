#include "statistics.h"
#include "ui_statistics.h"
#include "dados.h"
#include "math.h"

statistics::statistics(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statistics)
{
    ui->setupUi(this);

    int j = 0;
    for (int i = var.dimension; i < (var.dimension+var.number_variables); i++){
        ui->cabeca->insertItem(j,var.cabecalho[i]);
        j ++;
    }
}

statistics::~statistics()
{
    delete ui;
}

void statistics::on_pushButton_clicked()
{

    // Determine o índice da variável a ser calculada

    int indice_cabeca = -6;
    int j = 0;
    for (int i = var.dimension; i< (var.dimension+var.number_variables);i++){
        if(ui->cabeca->currentText()== var.cabecalho[i]){
            indice_cabeca = j;
        }
        j++;
    }
    indice_cabeca = indice_cabeca + var.dimension;

    if (indice_cabeca != -6){
        // Determine as estatisticas

        double media = 0;
        double mediana = 0;
        double primeiro_quartil = 0;
        double terceiro_quartil = 0;
        double assimetria = 0;
        double kurtosis = 0;
        double minimo = 0;
        double maximo = 0;
        double variancia = 0;
        double desvio_padrao = 0;

        double soma = 0;
        int n = 0;
        QVector<double> copia;
        for (int i = 0; i <var.variaveis_externas[indice_cabeca].length(); i++ ){
            if (var.variaveis_externas[indice_cabeca][i] != -999.999){
                copia.push_back(var.variaveis_externas[indice_cabeca][i]);
            }
        }
        qSort(copia);
        double tamanho = copia.length();

        int quartil1index = tamanho/4;
        int quartil2index = tamanho/2;
        int quartil3index = tamanho*3/4;

        minimo = copia[0];
        maximo = copia[copia.length()-1];
        primeiro_quartil = copia[quartil1index];
        mediana = copia[quartil2index];
        terceiro_quartil = copia[quartil3index];



        for (int i = 0; i < var.variaveis_externas[indice_cabeca].length(); i++){
            if (var.variaveis_externas[indice_cabeca][i] != -999.999){
                soma = soma + var.variaveis_externas[indice_cabeca][i];
                n++;
            }
        }

        media = soma/n;

        for (int i =0 ; i < var.variaveis_externas[indice_cabeca].length();i++){
            if (var.variaveis_externas[indice_cabeca][i] != -999.999){
                variancia = variancia + (var.variaveis_externas[indice_cabeca][i] - media)*(var.variaveis_externas[indice_cabeca][i] - media)/(n-1);
            }
        }

        desvio_padrao = sqrt(variancia);
        double numerador_kurtosis = 0;
        double denominador_kurtosis = 0;

        for (int i = 0; i < var.variaveis_externas[indice_cabeca].length(); i++){
            if (var.variaveis_externas[indice_cabeca][i] != -999.999){
                assimetria = assimetria + pow((var.variaveis_externas[indice_cabeca][i]- media)/ desvio_padrao,3)/n;
                numerador_kurtosis = numerador_kurtosis + pow(var.variaveis_externas[indice_cabeca][i] - media, 4);
                denominador_kurtosis = denominador_kurtosis + pow(var.variaveis_externas[indice_cabeca][i] - media, 2);
             }
        }

        kurtosis = 1/((double)n)*numerador_kurtosis/denominador_kurtosis-3.0;


        QString resposta= QString::fromUtf8( "-----Estatístisticas------\n")+
                           QString::fromUtf8("Mínimo -->")+QString::number(minimo)+"\n"+
                           QString::fromUtf8("Máximo -->")+QString::number(maximo)+"\n"+
                           "Primeiro quartil -->"+QString::number(primeiro_quartil)+"\n"+
                           "Mediana -->"+QString::number(mediana)+"\n"+
                           "Terceiro quartil -->"+QString::number(terceiro_quartil)+"\n"+
                           "Coeficiente assimetria --->"+QString::number(assimetria)+"\n"+
                           "Curtose --->"+QString::number(kurtosis)+"\n"+
                           QString::fromUtf8("Média aritimética --->")+QString::number(media)+"\n"+
                           QString::fromUtf8("Variância --->")+QString::number(variancia)+"\n"+
                           "Desvio Padrão--->"+QString::number(desvio_padrao)+"\n";

        ui->resultado->setText(resposta);

        double numero_classes = ui->classes->text().toDouble();
        double tamanho_classe = (maximo - minimo)/numero_classes;

        QVector<double> frequencia;
        QVector<double> bins;

        int fchose = 0;
        fchose = ui->frequencia->isChecked();

        int j = 0;
        double min_intervalo = 0;
        double max_intervalo = 0;
        int freq = 0;
        double relacao = 0;
        for (int i = 0; i < copia.length(); i++ ){
            min_intervalo = minimo + tamanho_classe*j;
            max_intervalo = minimo + tamanho_classe*(j+1);
            if (copia[i] >= min_intervalo && copia[i] < max_intervalo){
                freq++;
            }else{
                if (fchose == 0){
                    relacao = freq/(float)(copia.length());
                }
                else{
                    relacao = freq;
                }
                frequencia.push_back(relacao);
                bins.push_back((max_intervalo+min_intervalo)/2);
                freq = 0;
                j++;
                min_intervalo = minimo + tamanho_classe*j;
                max_intervalo = minimo + tamanho_classe*(j+1);
                if (copia[i] >= min_intervalo && copia[i] < max_intervalo){
                    freq++;
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
         ui->customPlot->xAxis->setLabel(var.cabecalho[indice_cabeca]);
         if (fchose == 1){
             ui->customPlot->yAxis->setLabel("Frequencia");
         }else{
             ui->customPlot->yAxis->setLabel("Frequencia Relativa");
         }
         ui->customPlot->xAxis->scaleRange(1.7, ui->customPlot->xAxis->range().center());
         ui->customPlot->yAxis->scaleRange(1.7, ui->customPlot->yAxis->range().center());

         ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);


         ui->customPlot->replot();


    }else{
        QMessageBox *m = new QMessageBox();
        m->setText("Por favor, selecione uma variável");
    }


}

void statistics::on_pushButton_2_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Salvar Imagem"),"",tr("Images (*.png *.xpm *.jpg)"));

    if (fileName != ""){
        ui->customPlot->saveJpg(fileName,0,0,1.0,-1,96);

        QMessageBox msgBox;
        msgBox.setText("Figura Salva");
        msgBox.exec();
    }

}
