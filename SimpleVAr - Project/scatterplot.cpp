#include "scatterplot.h"
#include "ui_scatterplot.h"
#include "dados.h"
#include <math.h>
#define _USE_MATH_DEFINES
#include <cmath>


bool double_equals2(double a, double b, double epsilon = 0.001)
{
    return std::abs(a - b) < epsilon;
}

Scatterplot::Scatterplot(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Scatterplot)
{
    ui->setupUi(this);
    int j = 0;
    qDebug() << var.dimension << var.number_variables << var.cabecalho;
    for (int i = var.dimension; i < (var.dimension+var.number_variables); i++){
        ui->cabeca->insertItem(j, var.cabecalho[i]);
        ui->rabo->insertItem(j, var.cabecalho[i]);
        j ++;
    }
}

Scatterplot::~Scatterplot()
{
    delete ui;
}

double beta(double y){
    double somatorio = 0;
    double razao = 0;
    double razao2 =0;
    double expoente2 = 0;
    double pow1 = 0;
    double pow2 = 0;
    expoente2 = y-1;
    for (int i= 0 ; i< 1000000;i++){
        razao = i/1000000.00;
        razao2 = 1 -razao;
        if (razao2 == 0){
            pow1 = 0;
        }else{
            pow1 =pow(razao2, expoente2);

        }
        if (razao == 0){
            pow2 =0;
        }else{
            pow2 =1/pow(razao, 0.5);
        }
        somatorio = somatorio + pow1*pow2*1/1000000.00;
    }
    return somatorio;
}

double tdistribution (double n, double alfa){
    double prob = 0;
    double tvalue = 0;
    double b = beta(n/2);
    double j = 0;
    double expoente = (n+1)/2;
    for (int i = -1500000; i < 1500000; i++){
        j = i/100000.00;
        prob= prob + 1/(sqrt(n)*b*pow((1+pow(j,2)/n),expoente))*1/100000;
        if (prob >= alfa){
            tvalue =j;
            break;
        }
    }
    qDebug() << n;
    qDebug() << b;
    qDebug() << tvalue;
    return tvalue;
}



void Scatterplot::on_pushButton_clicked()
{

    // leia o nível de confiabilidade

    double nconfiabilidade = ui->confiabilidade->value();

    //  Pegue o indice dos valores da cabeca e do rabo dos variogramas

    int indice_cabeca = -6;
    int indice_rabo = -6;
    int j = 0;
    for (int i = var.dimension; i< (var.dimension+var.number_variables);i++){
        if(ui->cabeca->currentText()== var.cabecalho[i]){
            indice_cabeca = j;
        }
        if(ui->rabo->currentText() == var.cabecalho[i]){
            indice_rabo = j;
        }
        j++;
    }
    indice_cabeca = indice_cabeca + var.dimension;
    indice_rabo = indice_rabo + var.dimension;

    if (indice_cabeca != -6 || indice_rabo != -6){
            // Faca a regressao linear entre os indices

            double somax = 0;
            double maximox = 0;
            double maximoy = 0;
            double somay = 0 ;
            double somax_quadrado = 0;
            double somax_y = 0;
            double somay_quadrado = 0;
            double n = var.variaveis_externas[indice_cabeca].length();
            int n_usados = 0;

            for (int i= 0; i < n; i++){
                if ( var.variaveis_externas[indice_cabeca][i] != -999.999 && var.variaveis_externas[indice_rabo][i] != -999.999){
                    somax = somax + var.variaveis_externas[indice_cabeca][i];
                    somay = somay + var.variaveis_externas[indice_rabo][i];
                    somax_quadrado = somax_quadrado + var.variaveis_externas[indice_cabeca][i]*var.variaveis_externas[indice_cabeca][i];
                    somay_quadrado = somay_quadrado  + var.variaveis_externas[indice_rabo][i]*var.variaveis_externas[indice_rabo][i];
                    somax_y = somax_y + var.variaveis_externas[indice_cabeca][i]*var.variaveis_externas[indice_rabo][i];
                    n_usados ++;
                    if (var.variaveis_externas[indice_cabeca][i]  > maximox){
                        maximox = var.variaveis_externas[indice_cabeca][i];
                    }
                    if (var.variaveis_externas[indice_rabo][i] >  maximoy){
                        maximoy = var.variaveis_externas[indice_rabo][i];
                    }
                }

            }

            double mediax = somax/n_usados;
            double mediay = somay/n_usados;
            double beta1 = (somax_y - (somax*somay/n_usados))/(somax_quadrado - somax*somax/n_usados);
            double beta0 = (mediay - beta1*mediax);

            double correlacao = 0;
            double varx = 0;
            double vary = 0;
            for (int i= 0; i < n; i++){
                if ( var.variaveis_externas[indice_cabeca][i] != -999.999 && var.variaveis_externas[indice_rabo][i] != -999.999){
                    varx = varx + (var.variaveis_externas[indice_cabeca][i] - mediax)*(var.variaveis_externas[indice_cabeca][i] - mediax)/n_usados;
                    vary = vary + (var.variaveis_externas[indice_rabo][i] - mediay)*(var.variaveis_externas[indice_rabo][i] - mediay)/n_usados;
                    correlacao = correlacao + (var.variaveis_externas[indice_cabeca][i] - mediax)*(var.variaveis_externas[indice_rabo][i] - mediay)/n_usados;
                }
            }
            varx = sqrt(varx);
            vary = sqrt(vary);
            double coef_correl = correlacao/(varx*vary);

            QString saida = "Reta regredida : " +QString::number(beta1) + "X + "+QString::number(beta0) + " -> coeficiente de Pearson -> "+QString::number(coef_correl);
            ui->texto->setText(saida);

            // Encontre os intervalos de seguranca da regressao

            QVector<double> limite_superior;
            QVector<double> limite_inferior;
            QVector<double> regressao;
            QVector<double> filtrado;
            QVector<double> filtradoy;

            double varcondicional = sqrt((somay_quadrado - beta0*somay - beta1*somax_y)/(n_usados-2));
            double tstudent = tdistribution((n_usados-2),(nconfiabilidade/2));
            double parte = 0;
            double l_superior, l_inferior;
            QVector<int> indices_retirados;
            for (int i= 0; i < n; i++){
                if ( var.variaveis_externas[indice_cabeca][i] != -999.999 && var.variaveis_externas[indice_rabo][i] != -999.999){
                    parte = tstudent*varcondicional*sqrt(1+1/n_usados +powf((var.variaveis_externas[indice_cabeca][i]-mediax),2)/(somax_quadrado - n_usados*mediax*mediax));
                    l_superior =var.variaveis_externas[indice_cabeca][i]*beta1 + beta0 + parte  ;
                    l_inferior =var.variaveis_externas[indice_cabeca][i]*beta1 + beta0 - parte;
                    limite_superior.push_back(l_superior);
                    limite_inferior.push_back(l_inferior);
                    if (var.variaveis_externas[indice_rabo][i] < l_superior ||var.variaveis_externas[indice_rabo][i] > l_inferior){
                        indices_retirados.push_back(i);
                    }
                    regressao.push_back(var.variaveis_externas[indice_cabeca][i]*beta1 + beta0);
                    filtrado.push_back(var.variaveis_externas[indice_cabeca][i]);
                    filtradoy.push_back(var.variaveis_externas[indice_rabo][i]);
                }
            }

            // Adicionar cabeçalho com indices

            QStringList novo_cabecalho;
            novo_cabecalho<<"Indice";
            for (int i = 0; i < var.cabecalho.length(); i++){
                novo_cabecalho << var.cabecalho[i];
            }

            ui->outliers->setColumnCount(var.cabecalho.length()+1);
            ui->outliers->setHorizontalHeaderLabels(novo_cabecalho);

            // Adicionar valores retirados
            int indice = 0;
            ui->outliers->setRowCount(indices_retirados.length());
            for (int i=0 ; i < indices_retirados.length(); i++){
                ui->outliers->setItem(i,0,new QTableWidgetItem(QString::number(i)));
                for (int j = 0; j < var.cabecalho.length(); j++){
                    indice = indices_retirados[i];
                    ui->outliers->setItem(i,(j+1),new QTableWidgetItem(QString::number(var.variaveis_externas[j][indice])));
                }
            }

            QPen pena1, pena2;
            pena1.setColor(Qt::red);
            pena2.setColor(Qt::green);

            ui->customPlot->clearPlottables();

            ui->customPlot->addGraph();
            ui->customPlot->graph()->setData(filtrado,limite_superior);
            ui->customPlot->graph()->setPen(pena1);
            ui->customPlot->addGraph();
            ui->customPlot->graph()->setPen(pena1);
            ui->customPlot->graph()->setData(filtrado,limite_inferior);
            ui->customPlot->graph()->setPen(pena1);
            ui->customPlot->addGraph();
            ui->customPlot->graph()->setData(filtrado,regressao);
            ui->customPlot->addGraph();
            ui->customPlot->graph()->setData(filtrado, filtradoy);
            ui->customPlot->graph()->setLineStyle(QCPGraph::lsNone);
            ui->customPlot->graph()->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 5));
            ui->customPlot->graph()->setPen(pena2);
            ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
            ui->customPlot->graph()->rescaleAxes();
            ui->customPlot->xAxis->setLabel(var.cabecalho[indice_cabeca]);
            ui->customPlot->yAxis->setLabel(var.cabecalho[indice_rabo]);
            ui->customPlot->xAxis->scaleRange(1.7, ui->customPlot->xAxis->range().center());
            ui->customPlot->yAxis->scaleRange(1.7, ui->customPlot->yAxis->range().center());
            ui->customPlot->replot();
       }else{
            QMessageBox *m = new QMessageBox();
            m->setText("Por favor, selecione uma variável para o cálculo");
            m->show();
       }


}

void Scatterplot::on_pushButton_3_clicked()
{
    QModelIndexList selecionados = ui->outliers->selectionModel()->selectedIndexes();

    if (selecionados.isEmpty() == false){
        QModelIndex item = selecionados.at(0);
        int row = item.row();

        for (int i = 0; i < var.variaveis_externas[0].size(); i++ ){
            bool teste = false;
            for (int j= 0; j < var.number_variables; j++){
                int nindice = j+var.dimension +1;
                int nindice2 = j+var.dimension;
                double valor = ui->outliers->model()->data(ui->outliers->model()->index(row,nindice)).toDouble();
                qDebug()<< "valor tabela" << valor << "valor variavel" <<  var.variaveis_externas[nindice2][i];
                if ( double_equals2(valor,var.variaveis_externas[nindice2][i])){
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

        // leia o nível de confiabilidade

        double nconfiabilidade = ui->confiabilidade->value();

        //  Pegue o indice dos valores da cabeca e do rabo dos variogramas

        int indice_cabeca = -6;
        int indice_rabo = -6;
        int j = 0;
        for (int i = var.dimension; i< (var.dimension+var.number_variables);i++){
            if(ui->cabeca->currentText()== var.cabecalho[i]){
                indice_cabeca = j;
            }
            if(ui->rabo->currentText() == var.cabecalho[i]){
                indice_rabo = j;
            }
            j++;
        }
        indice_cabeca = indice_cabeca + var.dimension;
        indice_rabo = indice_rabo + var.dimension;


        // Faca a regressao linear entre os indices

        double somax = 0;
        double maximox = 0;
        double maximoy = 0;
        double somay = 0 ;
        double somax_quadrado = 0;
        double somax_y = 0;
        double somay_quadrado = 0;
        double n = var.variaveis_externas[indice_cabeca].length();
        int n_usados = 0;

        for (int i= 0; i < n; i++){
            if ( var.variaveis_externas[indice_cabeca][i] != -999.999 && var.variaveis_externas[indice_rabo][i] != -999.999){
                somax = somax + var.variaveis_externas[indice_cabeca][i];
                somay = somay + var.variaveis_externas[indice_rabo][i];
                somax_quadrado = somax_quadrado + var.variaveis_externas[indice_cabeca][i]*var.variaveis_externas[indice_cabeca][i];
                somay_quadrado = somay_quadrado  + var.variaveis_externas[indice_rabo][i]*var.variaveis_externas[indice_rabo][i];
                somax_y = somax_y + var.variaveis_externas[indice_cabeca][i]*var.variaveis_externas[indice_rabo][i];
                n_usados ++;
                if (var.variaveis_externas[indice_cabeca][i]  > maximox){
                    maximox = var.variaveis_externas[indice_cabeca][i];
                }
                if (var.variaveis_externas[indice_rabo][i] >  maximoy){
                    maximoy = var.variaveis_externas[indice_rabo][i];
                }
            }

        }

        double mediax = somax/n_usados;
        double mediay = somay/n_usados;
        double beta1 = (somax_y - (somax*somay/n_usados))/(somax_quadrado - somax*somax/n_usados);
        double beta0 = (mediay - beta1*mediax);

        double correlacao = 0;
        double varx = 0;
        double vary = 0;
        for (int i= 0; i < n; i++){
            if ( var.variaveis_externas[indice_cabeca][i] != -999.999 && var.variaveis_externas[indice_rabo][i] != -999.999){
                varx = varx + (var.variaveis_externas[indice_cabeca][i] - mediax)*(var.variaveis_externas[indice_cabeca][i] - mediax)/n_usados;
                vary = vary + (var.variaveis_externas[indice_rabo][i] - mediay)*(var.variaveis_externas[indice_rabo][i] - mediay)/n_usados;
                correlacao = correlacao + (var.variaveis_externas[indice_cabeca][i] - mediax)*(var.variaveis_externas[indice_rabo][i] - mediay)/n_usados;
            }
        }
        varx = sqrt(varx);
        vary = sqrt(vary);
        double coef_correl = correlacao/(varx*vary);

        QString saida = "Reta regredida : " +QString::number(beta1) + "X + "+QString::number(beta0) + " -> coeficiente de Pearson -> "+QString::number(coef_correl);
        ui->texto->setText(saida);

        // Encontre os intervalos de seguranca da regressao

        QVector<double> limite_superior;
        QVector<double> limite_inferior;
        QVector<double> regressao;
        QVector<double> filtrado;
        QVector<double> filtradoy;

        double varcondicional = sqrt((somay_quadrado - beta0*somay - beta1*somax_y)/(n_usados-2));
        double tstudent = tdistribution((n_usados-2),(nconfiabilidade/2));
        double parte = 0;
        double l_superior, l_inferior;
        QVector<int> indices_retirados;
        for (int i= 0; i < n; i++){
            if ( var.variaveis_externas[indice_cabeca][i] != -999.999 && var.variaveis_externas[indice_rabo][i] != -999.999){
                parte = tstudent*varcondicional*sqrt(1+1/n_usados +powf((var.variaveis_externas[indice_cabeca][i]-mediax),2)/(somax_quadrado - n_usados*mediax*mediax));
                l_superior =var.variaveis_externas[indice_cabeca][i]*beta1 + beta0 + parte  ;
                l_inferior =var.variaveis_externas[indice_cabeca][i]*beta1 + beta0 - parte;
                limite_superior.push_back(l_superior);
                limite_inferior.push_back(l_inferior);
                if (var.variaveis_externas[indice_rabo][i] < l_superior ||var.variaveis_externas[indice_rabo][i] > l_inferior){
                    indices_retirados.push_back(i);
                }
                regressao.push_back(var.variaveis_externas[indice_cabeca][i]*beta1 + beta0);
                filtrado.push_back(var.variaveis_externas[indice_cabeca][i]);
                filtradoy.push_back(var.variaveis_externas[indice_rabo][i]);
            }
        }

        // Adicionar cabeçalho com indices

        QStringList novo_cabecalho;
        novo_cabecalho<<"Indice";
        for (int i = 0; i < var.cabecalho.length(); i++){
            novo_cabecalho << var.cabecalho[i];
        }

        ui->outliers->setColumnCount(var.cabecalho.length()+1);
        ui->outliers->setHorizontalHeaderLabels(novo_cabecalho);

        // Adicionar valores retirados
        int indice = 0;
        ui->outliers->setRowCount(indices_retirados.length());
        for (int i=0 ; i < indices_retirados.length(); i++){
            ui->outliers->setItem(i,0,new QTableWidgetItem(QString::number(i)));
            for (int j = 0; j < var.cabecalho.length(); j++){
                indice = indices_retirados[i];
                ui->outliers->setItem(i,(j+1),new QTableWidgetItem(QString::number(var.variaveis_externas[j][indice])));
            }
        }

        QPen pena1, pena2;
        pena1.setColor(Qt::red);
        pena2.setColor(Qt::green);

        ui->customPlot->clearPlottables();

        ui->customPlot->addGraph();
        ui->customPlot->graph()->setData(filtrado,limite_superior);
        ui->customPlot->graph()->setPen(pena1);
        ui->customPlot->addGraph();
        ui->customPlot->graph()->setPen(pena1);
        ui->customPlot->graph()->setData(filtrado,limite_inferior);
        ui->customPlot->graph()->setPen(pena1);
        ui->customPlot->addGraph();
        ui->customPlot->graph()->setData(filtrado,regressao);
        ui->customPlot->addGraph();
        ui->customPlot->graph()->setData(filtrado, filtradoy);
        ui->customPlot->graph()->setLineStyle(QCPGraph::lsNone);
        ui->customPlot->graph()->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 5));
        ui->customPlot->graph()->setPen(pena2);
        ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
        ui->customPlot->graph()->rescaleAxes();
        ui->customPlot->xAxis->setLabel(var.cabecalho[indice_cabeca]);
        ui->customPlot->yAxis->setLabel(var.cabecalho[indice_rabo]);
        ui->customPlot->xAxis->scaleRange(1.7, ui->customPlot->xAxis->range().center());
        ui->customPlot->yAxis->scaleRange(1.7, ui->customPlot->yAxis->range().center());
        ui->customPlot->replot();
      }else{
        QMessageBox *m = new QMessageBox();
        m->setText("Por favor, selecione um item para ser retirado");
        m->show();
      }


}

void Scatterplot::on_pushButton_2_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Salvar Imagem"),"",tr("Images (*.png *.xpm *.jpg)"));

    if (fileName != ""){
        ui->customPlot->saveJpg(fileName,0,0,1.0,-1,96);

        QMessageBox msgBox;
        msgBox.setText("Figura Salva");
        msgBox.exec();
    }
}
