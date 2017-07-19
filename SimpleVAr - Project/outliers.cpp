#include "outliers.h"
#include "ui_outliers.h"
#include "dados.h"
#include "stdio.h"

bool double_equals(double a, double b, double epsilon = 0.001)
{
    return std::abs(a - b) < epsilon;
}

Outliers::Outliers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Outliers)
{
    ui->setupUi(this);
    int j = 0;
    qDebug() << var.dimension << var.number_variables << var.cabecalho;
    for (int i = var.dimension; i < (var.dimension+var.number_variables); i++){
        ui->cabecalho->insertItem(j, var.cabecalho[i]);
        j ++;
    }

}

Outliers::~Outliers()
{
    delete ui;
}

void Outliers::on_pushButton_clicked()
{


    ui->outliers->setRowCount(0);
    ui->outliers->setColumnCount(0);

    if (ui->cabecalho->currentText().isEmpty() != 1){
        int indice = 0;
        for (int i = 0; i < var.cabecalho.length(); i++){
            if (var.cabecalho[i] == ui->cabecalho->currentText()){
                indice = i;

            }
        }  

        qDebug() << var.cabecalho[indice];
        // faca uma copia dos valores filtrados

        QVector < double> copy ;

        for  (int i = 0; i < var.variaveis_externas[indice].length(); i++){
            if (var.variaveis_externas[indice][i] != -999.999){
                copy.push_back(var.variaveis_externas[indice][i]);
            }

        }


        qSort (copy);
        int tamanho = copy.length() -1;

        // defina os quartis e os valores outliers

        int quartil1index = tamanho/4;
        int quartil2index = tamanho/2;
        int quartil3index = tamanho*3/4;

        double intervalo_interquartil = copy[quartil3index] - copy[quartil1index];

        ui->outliers->setColumnCount(var.cabecalho.length() + 1);


        QStringList novo_cabecalho;
        novo_cabecalho<<"Indice";
        for (int i = 0; i < var.cabecalho.length(); i++){
            novo_cabecalho << var.cabecalho[i];
        }

        ui->outliers->setHorizontalHeaderLabels(novo_cabecalho);

        int nout = 0;
        for(int i=0; i < var.variaveis_externas[indice].length(); i++){
            if (var.variaveis_externas[indice][i] < copy[quartil1index] - 1.5*intervalo_interquartil ||
                var.variaveis_externas[indice][i] > copy[quartil3index] + 1.5*intervalo_interquartil){
                if (var.variaveis_externas[indice][i] != -999.999) {
                    nout++;
                }
            }

        }

         ui->outliers->setRowCount(nout);


        int p = 0;
        for(int i=0; i < var.variaveis_externas[indice].length(); i++){
            if (var.variaveis_externas[indice][i] < copy[quartil1index] - 1.5*intervalo_interquartil ||
                var.variaveis_externas[indice][i] > copy[quartil3index] + 1.5*intervalo_interquartil){
                ui->outliers->setItem(p,0,new QTableWidgetItem(QString::number(i)));
                bool ok = false;
                for (int j = 0; j < var.cabecalho.length(); j++){
                    if (var.variaveis_externas[indice][i] != -999.999) {
                        ui->outliers->setItem(p,(j+1),new QTableWidgetItem(QString::number(var.variaveis_externas[j][i])));
                        ok = true;
                    }
                }
                if (ok == true){
                    p++;
                }


            }
        }

        ui->customPlot->addGraph();


        ui->customPlot->clearPlottables();
        QCPStatisticalBox *statistical = new QCPStatisticalBox(ui->customPlot->xAxis, ui->customPlot->yAxis);
        QBrush boxBrush(QColor(60, 60, 255, 100));
        boxBrush.setStyle(Qt::Dense6Pattern); // make it look oldschool
        statistical->setBrush(boxBrush);



        // specify data:
        statistical->data().data()->clear();
        statistical->data().clear();
        statistical->addData(1, (copy[quartil1index] - 1.5*intervalo_interquartil) , copy[quartil1index], copy[quartil2index], copy[quartil3index],(copy[quartil3index] + 1.5*intervalo_interquartil),copy);

        // prepare manual x axis labels:
        ui->customPlot->xAxis->setSubTicks(false);
        ui->customPlot->xAxis->setTickLength(0, 4);
        ui->customPlot->xAxis->setTickLabelRotation(20);
        QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
        textTicker->addTick(1, var.cabecalho[indice]);
        ui->customPlot->xAxis->setTicker(textTicker);

        // prepare axes:
        ui->customPlot->yAxis->setLabel("Valores");
        ui->customPlot->rescaleAxes();
        ui->customPlot->xAxis->scaleRange(1.7, ui->customPlot->xAxis->range().center());
        ui->customPlot->yAxis->scaleRange(1.7, ui->customPlot->yAxis->range().center());
        ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

        ui->customPlot->replot();

    }
}

void Outliers::on_pushButton_2_clicked()
{

    QModelIndexList selecionados = ui->outliers->selectionModel()->selectedIndexes();

    int row = 0 ;

    bool permitido = false;
    if (selecionados.isEmpty() == false) {
        QModelIndex item = selecionados.at(0);
        row = item.row();
        permitido =true;
    }

    if (permitido == true){
                for (int i = 0; i < var.variaveis_externas[0].size(); i++ ){
                    bool teste = false;
                    for (int j= 0; j < var.number_variables; j++){
                        int nindice = j+var.dimension +1;
                        int nindice2 = j+var.dimension;
                        double valor = ui->outliers->model()->data(ui->outliers->model()->index(row,nindice)).toDouble();
                        qDebug()<< "valor tabela" << valor << "valor variavel" <<  var.variaveis_externas[nindice2][i];
                        if ( double_equals(valor,var.variaveis_externas[nindice2][i])){
                            teste = true;
                            qDebug() << "ok";

                        }
                    }
                    if (teste == true){
                        for(int p= 0; p < var.variaveis_externas.size(); p++){
                            var.variaveis_externas[p].remove(i);
                        }
                    }
                }


                ui->outliers->setRowCount(0);
                ui->outliers->setColumnCount(0);

                if (ui->cabecalho->currentText().isEmpty() != 1){
                    int indice = 0;
                    for (int i = 0; i < var.cabecalho.length(); i++){
                        if (var.cabecalho[i] == ui->cabecalho->currentText()){
                            indice = i;

                        }
                    }

                    qDebug() << var.cabecalho[indice];
                    // faca uma copia dos valores filtrados

                    QVector < double> copy ;

                    for  (int i = 0; i < var.variaveis_externas[indice].length(); i++){
                        if (var.variaveis_externas[indice][i] != -999.999){
                            copy.push_back(var.variaveis_externas[indice][i]);
                        }

                    }


                    qSort (copy);
                    int tamanho = copy.length() -1;

                    // defina os quartis e os valores outliers

                    int quartil1index = tamanho/4;
                    int quartil2index = tamanho/2;
                    int quartil3index = tamanho*3/4;

                    double intervalo_interquartil = copy[quartil3index] - copy[quartil1index];

                    ui->outliers->setColumnCount(var.cabecalho.length() + 1);


                    QStringList novo_cabecalho;
                    novo_cabecalho<<"Indice";
                    for (int i = 0; i < var.cabecalho.length(); i++){
                        novo_cabecalho << var.cabecalho[i];
                    }

                    ui->outliers->setHorizontalHeaderLabels(novo_cabecalho);

                    int nout = 0;
                    for(int i=0; i < var.variaveis_externas[indice].length(); i++){
                        if (var.variaveis_externas[indice][i] < copy[quartil1index] - 1.5*intervalo_interquartil ||
                            var.variaveis_externas[indice][i] > copy[quartil3index] + 1.5*intervalo_interquartil){
                            if (var.variaveis_externas[indice][i] != -999.999) {
                                nout++;
                            }
                        }

                    }

                     ui->outliers->setRowCount(nout);


                    int p = 0;
                    for(int i=0; i < var.variaveis_externas[indice].length(); i++){
                        if (var.variaveis_externas[indice][i] < copy[quartil1index] - 1.5*intervalo_interquartil ||
                            var.variaveis_externas[indice][i] > copy[quartil3index] + 1.5*intervalo_interquartil){
                            ui->outliers->setItem(p,0,new QTableWidgetItem(QString::number(i)));
                            bool ok = false;
                            for (int j = 0; j < var.cabecalho.length(); j++){
                                if (var.variaveis_externas[indice][i] != -999.999) {
                                    ui->outliers->setItem(p,(j+1),new QTableWidgetItem(QString::number(var.variaveis_externas[j][i])));
                                    ok = true;
                                }
                            }
                            if (ok == true){
                                p++;
                            }

                        }
                    }

                    ui->customPlot->addGraph();


                    ui->customPlot->clearPlottables();
                    QCPStatisticalBox *statistical = new QCPStatisticalBox(ui->customPlot->xAxis, ui->customPlot->yAxis);
                    QBrush boxBrush(QColor(60, 60, 255, 100));
                    boxBrush.setStyle(Qt::Dense6Pattern); // make it look oldschool
                    statistical->setBrush(boxBrush);



                    // specify data:
                    statistical->data().data()->clear();
                    statistical->data().clear();
                    statistical->addData(1, (copy[quartil1index] - 1.5*intervalo_interquartil) , copy[quartil1index], copy[quartil2index], copy[quartil3index],(copy[quartil3index] + 1.5*intervalo_interquartil),copy);

                    // prepare manual x axis labels:
                    ui->customPlot->xAxis->setSubTicks(false);
                    ui->customPlot->xAxis->setTickLength(0, 4);
                    ui->customPlot->xAxis->setTickLabelRotation(20);
                    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
                    textTicker->addTick(1, var.cabecalho[indice]);
                    ui->customPlot->xAxis->setTicker(textTicker);

                    // prepare axes:
                    ui->customPlot->yAxis->setLabel("Valores");
                    ui->customPlot->rescaleAxes();
                    ui->customPlot->xAxis->scaleRange(1.7, ui->customPlot->xAxis->range().center());
                    ui->customPlot->yAxis->scaleRange(1.7, ui->customPlot->yAxis->range().center());
                    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

                    ui->customPlot->replot();
               }
     }else{
        QMessageBox *mensagem = new QMessageBox();
        mensagem->setText("Por favor selecione um item para ser removido");
        mensagem->show();
    }
}

void Outliers::on_pushButton_3_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Salvar Imagem"),"",tr("Images (*.png *.xpm *.jpg)"));

    if (fileName != ""){
        ui->customPlot->saveJpg(fileName,0,0,1.0,-1,96);

        QMessageBox msgBox;
        msgBox.setText("Figura Salva");
        msgBox.exec();
    }


}
