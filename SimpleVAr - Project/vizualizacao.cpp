#include "vizualizacao.h"
#include "ui_vizualizacao.h"
#include "dados.h"
#include "math.h"
#include "delegate.h"

QString identificar_virgula3(QString palavra){
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


vizualizacao::vizualizacao(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::vizualizacao)
{
    ui->setupUi(this);

    // encontre o centro

    double xcentro = 0;
    double ycentro = 0;
    double zcentro = 0;



    var.x_rot.clear();
    var.y_rot.clear();
    var.z_rot.clear();

    var.x_rot_c.clear();
    var.y_rot_c.clear();
    var.z_rot_c.clear();

    ui->customPlot->clearPlottables();


    if(var.number_variables > 0){
        if (var.dimension == 1){
            var.x_rot = var.variaveis_externas[0];
            for (int i= 0; i <var.number_dados; i++){
                var.y_rot.push_back(1.000);
                var.z_rot.push_back(1.000);
                var.values_rot.push_back(0.000);
                var.cores_rot.push_back(Qt::black);
            }
        }
        if (var.dimension == 2){
            var.x_rot = var.variaveis_externas[0];
            var.y_rot = var.variaveis_externas[1];
            for (int i= 0; i <var.number_dados; i++){
                var.z_rot.push_back(1.0000);
                var.values_rot.push_back(0.0000);
                var.cores_rot.push_back(Qt::black);
            }

        }
        if (var.dimension == 3){
            var.x_rot = var.variaveis_externas[0];
            var.y_rot = var.variaveis_externas[1];
            var.z_rot = var.variaveis_externas[2];
            for (int i= 0; i <var.number_dados; i++){
                var.values_rot.push_back(0.0000);
                var.cores_rot.push_back(Qt::black);
            }
        }


        for (int i = 0; i < var.x_rot.length(); i++){
            var.x_rot_c.push_back(var.x_rot[i]);
            var.y_rot_c.push_back(var.y_rot[i]);
            var.z_rot_c.push_back(var.z_rot[i]);
        }



        ui->customPlot->addGraph();
        ui->customPlot->graph()->setData(var.x_rot,var.y_rot);
        ui->customPlot->rescaleAxes();
        ui->customPlot->xAxis->scaleRange(1.7, ui->customPlot->xAxis->range().center());
        ui->customPlot->yAxis->scaleRange(1.7, ui->customPlot->yAxis->range().center());
        ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
        ui->customPlot->graph()->setLineStyle(QCPGraph::lsNone);
        ui->customPlot->graph()->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 5));
        ui->customPlot->replot();

        int j = 0;
        for (int i = var.dimension; i < (var.dimension+var.number_variables); i++){
            ui->cabeca->insertItem(j,var.cabecalho[i]);
            j ++;
        }




    }else{
        QMessageBox *m = new QMessageBox();
        m->setText("Por favor, carregue um conjunto de dados");
        m->show();
    }
}

vizualizacao::~vizualizacao()
{
    delete ui;
}

void vizualizacao::on_horizontalSlider_sliderMoved(int position)
{


}

void vizualizacao::on_pushButton_3_clicked()
{

        var.x_rot_c = var.x_rot;
        var.y_rot_c = var.y_rot;
        var.z_rot_c = var.z_rot;

        ui->customPlot->clearPlottables();

        ui->customPlot->addGraph();
        ui->customPlot->graph()->setData(var.x_rot,var.y_rot);
        ui->customPlot->rescaleAxes();
        ui->customPlot->xAxis->scaleRange(1.7, ui->customPlot->xAxis->range().center());
        ui->customPlot->yAxis->scaleRange(1.7, ui->customPlot->yAxis->range().center());
        ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
        ui->customPlot->graph()->setLineStyle(QCPGraph::lsNone);
        ui->customPlot->graph()->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 5));
        ui->customPlot->replot();

        int j = 0;
        for (int i = var.dimension; i < (var.dimension+var.number_variables); i++){
            ui->cabeca->insertItem(j,var.cabecalho[i]);
            j ++;
        }

}

void vizualizacao::on_verticalSlider_sliderMoved(int position)
{

}

void vizualizacao::on_nclasses_valueChanged(int arg1)
{
    ui->tabela->setItemDelegate(new Delegate);

    int n_linhas =ui->nclasses->text().toInt();
    ui->tabela->setRowCount(n_linhas);

    for (int i =0; i < n_linhas; i++){
       ui->tabela->setItem(i,2, new QTableWidgetItem);
       ui->tabela->item(i,2)->setBackground(Qt::black);
    }







}

void vizualizacao::on_tabela_cellPressed(int row, int column)
{
    if (column == 2){
        QColor color = QColorDialog::getColor(Qt::white, this,"Selecione sua cor");
        QModelIndexList selecionados = ui->tabela->selectionModel()->selectedIndexes();
        QModelIndex item = selecionados.at(0);
        int row2 = item.row();
        ui->tabela->item(row2,column)->setBackgroundColor(color);
     }
}

void vizualizacao::on_pushButton_clicked()
{
    int indice_cabeca = -6;
    int j = 0;
    for (int i = var.dimension; i< (var.dimension+var.number_variables);i++){
        if(ui->cabeca->currentText()== var.cabecalho[i]){
            indice_cabeca = j;
            j++;
        }
    }
    indice_cabeca = indice_cabeca + var.dimension;

    // Pegue os valores da user interface

    QVector<double> min;
    QVector<double> max;
    QVector<QColor> cores;


    // Teste da tabela do qtablewidget teste -> se existe um valor, teste2 -> se o valor e numerico

    bool teste = true;


    ui->customPlot->clearPlottables();

    int n = ui->nclasses->text().toInt();

    for (int i = 0; i< n; i++){
        for (int j=0; j< 1; j++){
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

    if (teste == true && indice_cabeca != -6){
        QString entrada;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < 8; j++){
                switch(j){
                    case 0:
                        entrada = identificar_virgula3(ui->tabela->item(i,j)->text());
                        min.push_back(entrada.toDouble());
                        break;
                    case 1:
                        entrada = identificar_virgula3(ui->tabela->item(i,j)->text());
                        max.push_back(entrada.toDouble());
                        break;
                    case 2:
                        QColor cor;
                        cor = ui->tabela->item(i,j)->backgroundColor();
                        cores.push_back(cor);
                        break;
                }

            }
        }

        QVector <QVector <double>> filtrosx;
        QVector <QVector <double>> filtrosy;
        for (int j = 0; j < n; j++){
            QVector<double> filtrox;
            QVector<double> filtroy;
            for (int i = 0; i < var.variaveis_externas[indice_cabeca].length(); i++){
                if (var.variaveis_externas[indice_cabeca][i] >= min[j] && var.variaveis_externas[indice_cabeca][i] < max[j] ){
                    if (var.variaveis_externas[indice_cabeca][i] != -999.999){
                        filtrox.push_back(var.x_rot[i]);
                        filtroy.push_back(var.y_rot[i]);
                    }
                }
            }
            filtrosx.push_back(filtrox);
            filtrosy.push_back(filtroy);
        }

        var.min = min;
        var.max = max;
        var.filtrosx = filtrosx;
        var.filtrosy = filtrosy;
        var.cores_v =cores;


        for (int j = 0; j < n; j++){
            QPen pena;
            QString name = QString::number(min[j])+"---"+QString::number(max[j]);
            pena.setColor(cores[j]);
            ui->customPlot->legend->setVisible(true);
            ui->customPlot->addGraph();
            ui->customPlot->graph()->setData(filtrosx[j],filtrosy[j]);
            ui->customPlot->graph()->setName(name);
            ui->customPlot->graph()->setPen(pena);
            ui->customPlot->rescaleAxes();
            ui->customPlot->xAxis->scaleRange(1.7, ui->customPlot->xAxis->range().center());
            ui->customPlot->yAxis->scaleRange(1.7, ui->customPlot->yAxis->range().center());
            ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
            ui->customPlot->graph()->setLineStyle(QCPGraph::lsNone);
            ui->customPlot->graph()->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 5));
            ui->customPlot->replot();
        }




    }
}

void vizualizacao::on_Azimute_valueChanged(const QString &arg1)
{
    double azimute = ui->Azimute->text().toDouble();
    double dip = ui->Mergulho->text().toDouble();
    double x = 0;
    double y = 0;
    double y2 = 0;
    double z = 0;
    for (int i = 0; i < var.x_rot.length(); i++){
       x =  cos(azimute*M_PI/180.00)*var.x_rot_c[i] - sin(azimute*M_PI/180.00)*var.y_rot_c[i];
       y = sin(azimute*M_PI/180.00)*var.x_rot_c[i] + cos(azimute*M_PI/180.00)*var.y_rot_c[i];
       y2 = cos(dip*M_PI/180.00)*y - sin(dip*M_PI/180.00)*var.z_rot_c[i];
       z = sin(dip*M_PI/180.00)*y+ cos(dip*M_PI/180.00)*var.z_rot_c[i];

       var.x_rot[i] = x;
       var.y_rot[i] = y2;
       var.z_rot[i] = z;

    }

    QVector <QVector <double>> filtrosx;
    QVector <QVector <double>> filtrosy;



    int indice_cabeca = -6;
    int j = 0;
    for (int i = var.dimension; i< (var.dimension+var.number_variables);i++){
        if(ui->cabeca->currentText()== var.cabecalho[i]){
            indice_cabeca = j;
            j++;
        }
    }
    indice_cabeca = indice_cabeca + var.dimension;

    if (indice_cabeca != -6){
        if (var.min.length() > 0){
            for (int j = 0; j < ui->nclasses->text().toInt(); j++){
                QVector<double> filtrox;
                QVector<double> filtroy;
                for (int i = 0; i < var.variaveis_externas[indice_cabeca].length(); i++){
                    if (var.variaveis_externas[indice_cabeca][i] >= var.min[j] && var.variaveis_externas[indice_cabeca][i] < var.max[j] ){
                        if (var.variaveis_externas[indice_cabeca][i] != -999.999){
                            filtrox.push_back(var.x_rot[i]);
                            filtroy.push_back(var.y_rot[i]);
                        }
                    }
                }
                filtrosx.push_back(filtrox);
                filtrosy.push_back(filtroy);
            }
          }
      }


    if(filtrosx.length() == 0){
        ui->customPlot->clearPlottables();
        ui->customPlot->addGraph();
        ui->customPlot->graph()->setData(var.x_rot,var.y_rot);
        ui->customPlot->rescaleAxes();
        ui->customPlot->xAxis->scaleRange(1.7, ui->customPlot->xAxis->range().center());
        ui->customPlot->yAxis->scaleRange(1.7, ui->customPlot->yAxis->range().center());
        ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
        ui->customPlot->graph()->setLineStyle(QCPGraph::lsNone);
        ui->customPlot->graph()->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 5));
        ui->customPlot->replot();
    }
    if(filtrosx.length() > 0){
        ui->customPlot->clearPlottables();
        for (int j = 0; j < ui->nclasses->text().toInt(); j++){
            QPen pena;
            QString name = QString::number(var.min[j])+"---"+QString::number(var.max[j]);
            pena.setColor(var.cores_v[j]);
            ui->customPlot->legend->setVisible(true);
            ui->customPlot->addGraph();
            ui->customPlot->graph()->setData(filtrosx[j],filtrosy[j]);
            ui->customPlot->graph()->setName(name);
            ui->customPlot->graph()->setPen(pena);
            ui->customPlot->rescaleAxes();
            ui->customPlot->xAxis->scaleRange(1.7, ui->customPlot->xAxis->range().center());
            ui->customPlot->yAxis->scaleRange(1.7, ui->customPlot->yAxis->range().center());
            ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
            ui->customPlot->graph()->setLineStyle(QCPGraph::lsNone);
            ui->customPlot->graph()->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 5));
            ui->customPlot->replot();
        }
     }
}

void vizualizacao::on_Mergulho_valueChanged(int arg1)
{
    double azimute = ui->Azimute->text().toDouble();
    double dip = ui->Mergulho->text().toDouble();
    double x, y;
    double y2, z;
    for (int i = 0; i < var.x_rot.length(); i++){
       x =  cos(azimute*M_PI/180.00)*var.x_rot_c[i] - sin(azimute*M_PI/180.00)*var.y_rot_c[i];
       y = sin(azimute*M_PI/180.00)*var.x_rot_c[i] + cos(azimute*M_PI/180.00)*var.y_rot_c[i];
       y2 = cos(dip*M_PI/180.00)*y - sin(dip*M_PI/180.00)*var.z_rot_c[i];
       z = sin(dip*M_PI/180.00)*y+ cos(dip*M_PI/180.00)*var.z_rot_c[i];

       var.x_rot[i] = x;
       var.y_rot[i] = y2;
       var.z_rot[i] = z;

    }

    QVector <QVector <double>> filtrosx;
    QVector <QVector <double>> filtrosy;



    int indice_cabeca = -6;
    int j = 0;
    for (int i = var.dimension; i< (var.dimension+var.number_variables);i++){
        if(ui->cabeca->currentText()== var.cabecalho[i]){
            indice_cabeca = j;
            j++;
        }
    }
    indice_cabeca = indice_cabeca + var.dimension;

    if (indice_cabeca != -6){
        if (var.min.length() > 0){
            for (int j = 0; j < ui->nclasses->text().toInt(); j++){
                QVector<double> filtrox;
                QVector<double> filtroy;
                for (int i = 0; i < var.variaveis_externas[indice_cabeca].length(); i++){
                    if (var.variaveis_externas[indice_cabeca][i] >= var.min[j] && var.variaveis_externas[indice_cabeca][i] < var.max[j] ){
                        if (var.variaveis_externas[indice_cabeca][i] != -999.999){
                            filtrox.push_back(var.x_rot[i]);
                            filtroy.push_back(var.y_rot[i]);
                        }
                    }
                }
                filtrosx.push_back(filtrox);
                filtrosy.push_back(filtroy);
            }
          }
      }


    if(filtrosx.length() == 0){
        ui->customPlot->clearPlottables();
        ui->customPlot->addGraph();
        ui->customPlot->graph()->setData(var.x_rot,var.y_rot);
        ui->customPlot->rescaleAxes();
        ui->customPlot->xAxis->scaleRange(1.7, ui->customPlot->xAxis->range().center());
        ui->customPlot->yAxis->scaleRange(1.7, ui->customPlot->yAxis->range().center());
        ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
        ui->customPlot->graph()->setLineStyle(QCPGraph::lsNone);
        ui->customPlot->graph()->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 5));
        ui->customPlot->replot();
    }
    if(filtrosx.length() > 0){
        ui->customPlot->clearPlottables();
        for (int j = 0; j < ui->nclasses->text().toInt(); j++){
            QPen pena;
            QString name = QString::number(var.min[j])+"---"+QString::number(var.max[j]);
            pena.setColor(var.cores_v[j]);
            ui->customPlot->legend->setVisible(true);
            ui->customPlot->addGraph();
            ui->customPlot->graph()->setData(filtrosx[j],filtrosy[j]);
            ui->customPlot->graph()->setName(name);
            ui->customPlot->graph()->setPen(pena);
            ui->customPlot->rescaleAxes();
            ui->customPlot->xAxis->scaleRange(1.7, ui->customPlot->xAxis->range().center());
            ui->customPlot->yAxis->scaleRange(1.7, ui->customPlot->yAxis->range().center());
            ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
            ui->customPlot->graph()->setLineStyle(QCPGraph::lsNone);
            ui->customPlot->graph()->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 5));
            ui->customPlot->replot();
        }
     }
}

void vizualizacao::on_pushButton_2_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Salvar Imagem"),"",tr("Images (*.png *.xpm *.jpg)"));

    if (fileName != ""){
        ui->customPlot->saveJpg(fileName,0,0,1.0,-1,96);

        QMessageBox msgBox;
        msgBox.setText("Figura Salva");
        msgBox.exec();
    }
}
