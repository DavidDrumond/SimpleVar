#include "variogram_map.h"
#include "ui_variogram_map.h"
#include "dados.h"
#include <math.h>
#define _USE_MATH_DEFINES
#include <cmath>

Variogram_Map::Variogram_Map(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Variogram_Map)
{
    ui->setupUi(this);

    int j = 0;
    for (int i = var.dimension; i < (var.dimension+var.number_variables); i++){
        ui->Propr_cabeca->insertItem(j,var.cabecalho[i]);
        ui->Prop_rabo->insertItem(j,var.cabecalho[i]);
        j ++;
    }
}

Variogram_Map::~Variogram_Map()
{
    delete ui;
}



void Variogram_Map::on_pushButton_clicked()
{

    ui->progressBar->setValue(0);

    int indice_cabeca;
    int indice_rabo;
    int j = 0;
    for (int i = var.dimension; i< (var.dimension+var.number_variables);i++){
        if(ui->Propr_cabeca->currentText()== var.cabecalho[i]){
            indice_cabeca = j;
        }
        if(ui->Prop_rabo->currentText() == var.cabecalho[i]){
            indice_rabo = j;
        }
        j++;
    }
    indice_cabeca = indice_cabeca + var.dimension;
    indice_rabo = indice_rabo + var.dimension;

    // Importe os valores da user interface

    double azimute = ui->Azimute->text().toDouble();
    double dip =  ui->Mergulho->text().toDouble();
    int nlags = ui->nLag->text().toInt();
    double lagdistance = ui->Lag_size->text().toDouble();
    int nminpar = ui->Min_npares->text().toInt();
    QString gradiente_tipo = ui->Gradient_type->currentText();
    int grau_refinamento = ui->Grau_refinamento->text().toInt();
    int n_celulas = ui->Ncelulas->text().toInt();


    // Defina o algoritmo utilizado para fazer o varmap:

        // Converta tolerancias se elas forem iguais a zero

        double lineartolerance = lagdistance/2 ;
        double hband = lagdistance/2;
        double htolerance = 20;
        double dmaximo = (nlags +0.5)*lagdistance;




        // Converta os valores de tolerancia em radianos

        htolerance = htolerance*M_PI/180.00;

        // Determine as projecoes do dip e do azimute

        htolerance = cos(htolerance);

        QVector<double> xhrot;
        QVector<double> yhrot;
        QVector<double> zhrot;
        QVector<double> xttrot;
        QVector<double> yttrot;
        QVector<double> zttrot;

        double xrot = 0;
        double yrot = 0;
        double yrot2 = 0;
        double zrot = 0;

        qDebug() << var.dimension;

        if (var.dimension>= 2){

            qDebug() << "what is happen";
            int tamanho =  var.variaveis_externas[0].size();
            for (int i=0; i< tamanho; i++){
                // Rotacione primeiramente no azimute
                double zh = 0;
                if (var.dimension == 2){
                   zh = 0;
                }
                else{
                   zh = var.variaveis_externas[2][i];
                }

                xrot = cos(azimute*M_PI/180.00)*var.variaveis_externas[0][i] - sin(azimute*M_PI/180.00)*var.variaveis_externas[1][i];
                yrot = sin(azimute*M_PI/180.00)*var.variaveis_externas[0][i] + cos(azimute*M_PI/180.00)*var.variaveis_externas[1][i];
                yrot2 = cos(dip*M_PI/180.00)*yrot - sin(dip*M_PI/180.00)*zh;
                zrot = sin(dip*M_PI/180.00)*yrot + cos(dip*M_PI/180.00)*zh;

                xhrot.append(xrot);
                yhrot.append(yrot2);
                zhrot.append(zrot);
            }
            xttrot = xhrot ;
            yttrot = yhrot ;
            zttrot = zhrot ;



        ui->progressBar->setValue(30);

        // DEFINA TODAS AS DISTANCIAS ECUCLIDIANAS POSSIVEIS

        QVector<double> cabeca;
        QVector<double> rabo;
        QVector<double> cabeca2;
        QVector<double> rabo2;
        QVector<double> distanciah;
        QVector<double> distanciaxy;
        QVector<double> distanciax;
        QVector<double> distanciay;
        QVector<double> distanciaz;

        double dx;
        double dy;
        double dz;
        double dh;

        for (int t=0; t < xhrot.size(); t++){
            for (int h=0; h< xhrot.size(); h++){
                dx = xhrot[h]-xttrot[t];
                dy= yhrot[h]-yttrot[t];
                dz = zhrot[h]-zttrot[t];
                dh = sqrt(dy*dy + dx*dx + dz*dz);

                if (dh <= dmaximo){
                    if (var.variaveis_externas[indice_cabeca][h] == -999.999 ||
                        var.variaveis_externas[indice_rabo][h] == -999.999 ||
                        var.variaveis_externas[indice_rabo][t] == -999.999 ||
                        var.variaveis_externas[indice_cabeca][t] == -999.999 ){

                    }
                    else{
                        cabeca.append(var.variaveis_externas[indice_cabeca][h]);
                        cabeca2.append(var.variaveis_externas[indice_rabo][h]);
                        rabo2.append(var.variaveis_externas[indice_rabo][t]);
                        rabo.append(var.variaveis_externas[indice_cabeca][t]);

                        distanciay.append(dy);
                        distanciax.append(dx);
                        distanciaz.append(dz);
                        distanciah.append(dh);
                        distanciaxy.append(sqrt(dy*dy + dx*dx));
                    }
                }
            }
        }

        qDebug() << "cabeca" << cabeca;

        ui->progressBar->setValue(40);

        // CALCULE TODOS OS VALORES DE COS E SENO ADMISSIVEIS AO AZIMUTE


        QVector<double> cos_Azimute;
        QVector<double> sin_Azimute;
        double cos_Azm;
        double sin_Azm;
        double sin_Dip;
        double cos_Dip;
        double valor;

        for (int a=0 ; a < 18; a++){
            valor = a*20;
            cos_Azm = cos((90.00-valor)*M_PI/180.00);
            sin_Azm = sin((90.00-valor)*M_PI/180.00);
            cos_Azimute.append(cos_Azm);
            sin_Azimute.append(sin_Azm);
        }

        cos_Dip = cos(M_PI/180.00*(90));
        sin_Dip = sin(M_PI/180.00*(90));



        QVector <QVector<double>> distancias_admissiveis;
        QVector <QVector<double>> azimute_admissiveis;
        QVector <QVector<double>> v_valores_admissiveis_h;
        QVector <QVector<double>> v_valores_admissiveis_t;
        QVector <QVector<double>> v_valores_admissiveis_h2;
        QVector <QVector<double>> v_valores_admissiveis_t2;
        QVector<double> pares;



        double lag;
        int par;
        double limitemin;
        double limitemax;


        double azm;
        double check_azimute;
        double check_bandh;



        // CALCULE OS PONTOS ADMISSIVEIS
        for (int a = 0; a< 18; a++){
            // reestabelca o valor do norte retirando novamente o azimute
            azm = a*20*M_PI/180.00;
            for (int l= 0; l< nlags; l++){

                QVector<double> valores_admissiveis_h;
                QVector<double> valores_admissiveis_t;
                QVector<double> valores_admissiveis_h2;
                QVector<double> valores_admissiveis_t2;
                QVector<double> distancia_admissivel;
                QVector<double> azimute_admissivel;

                lag = lagdistance*(l+1);
                par = 0;
                limitemin = lag - lineartolerance;
                limitemax = lag + lineartolerance;

                for (int p = 0; p < distanciah.size(); p++){
                    if (distanciah[p] > limitemin && distanciah[p] < limitemax){
                        if (distanciaxy[p] > 0.000){
                            check_azimute = (distanciax[p]*cos_Azimute[a] +distanciay[p]*sin_Azimute[a])/distanciaxy[p];
                        }
                        else{
                            check_azimute = 1.00;
                        }


                        if (check_azimute >= htolerance){
                            check_bandh = (cos_Azimute[a]*distanciay[p]) - (sin_Azimute[a]*distanciax[p]);
                            check_bandh = fabs(check_bandh);
                            if (check_bandh < hband){
                                    valores_admissiveis_h.append(cabeca[p]);
                                    valores_admissiveis_t.append(rabo[p]);
                                    valores_admissiveis_h2.append(cabeca2[p]);
                                    valores_admissiveis_t2.append(rabo2[p]);
                                    distancia_admissivel.append(distanciah[p]);
                                    par = par + 1;
                                    azimute_admissivel.append(azm);                             
                            }
                        }
                     }
                   }
                   if (valores_admissiveis_h.size() > 0){
                        if (par > nminpar){
                            v_valores_admissiveis_h.append(valores_admissiveis_h);
                            v_valores_admissiveis_h2.append(valores_admissiveis_h2);
                            v_valores_admissiveis_t2.append(valores_admissiveis_t2);
                            v_valores_admissiveis_t.append(valores_admissiveis_t);
                            distancias_admissiveis.append(distancia_admissivel);
                            pares.append(par);
                            azimute_admissiveis.append(azimute_admissivel);
                        }
                    }
               }
        }


        ui->progressBar->setValue(50);

        // CALCULE O VARIOGRAMA


        QVector <double> continuidade;
        QVector <double> lag_adm;
        QVector <double> azimute_adm;

        QVector <double> flutuantet;
        QVector <double> flutuanteh;
        QVector <double> flutuanteh2;
        QVector <double> flutuantet2;
        QVector <double> flutuanted;
        QVector <double> flutuantea;

        double soma = 0;
        double lagmedio =0;
        double agmedio =0;

        for (int i = 0; i< v_valores_admissiveis_h.size(); i++){
            flutuantet.clear();
            flutuanteh.clear();
            flutuanteh2.clear();
            flutuantet2.clear();
            flutuanted.clear();
            flutuantea.clear();
            flutuantet = v_valores_admissiveis_t[i];
            flutuanteh = v_valores_admissiveis_h[i];
            flutuanteh2= v_valores_admissiveis_h2[i];
            flutuantet2 = v_valores_admissiveis_t2[i];
            flutuanted = distancias_admissiveis[i];
            flutuantea= azimute_admissiveis[i];
            soma = 0;
            lagmedio =0;
            agmedio =0;
            for (int j = 0; j < flutuanteh.size(); j++){
                soma = soma + (flutuanteh[j] - flutuantet[j])*(flutuanteh2[j]-flutuantet2[j])/(2.00*pares[i]);
            }
            for (int z = 0; z < flutuanted.size(); z++){
                lagmedio = lagmedio + flutuanted[z]/flutuanted.size();
            }
            for (int g = 0; g < flutuantea.size(); g++){
                agmedio = agmedio + flutuantea[g]/flutuantea.size();
            }

            continuidade.append(soma);
            azimute_adm.append(agmedio);
            lag_adm.append(lagmedio);

         }

        ui->progressBar->setValue(60);

        QVector<double> xvalues;
        QVector<double> yvalues;



        for (int i = 0; i< continuidade.size(); i++){
            xvalues.append(lag_adm[i]*sin(azimute_adm[i]));
            yvalues.append(lag_adm[i]*cos(azimute_adm[i]));
        }

        ui->customPlot->addGraph();
        ui->customPlot->clearPlottables();
        ui->customPlot->clearItems();
        ui->customPlot->clearMask();
        ui->customPlot->clearFocus();


        // CONFIGURE O EIXO DO MAPA
        ui->customPlot->setInteractions(QCP::iRangeDrag|QCP::iRangeZoom); // this will also allow rescaling the color scale by dragging/zooming
        ui->customPlot->axisRect()->setupFullAxesBox(true);
        ui->customPlot->xAxis->setLabel("x");
        ui->customPlot->yAxis->setLabel("y");

            // SET O QCPCOLORMAP
            QCPColorMap *colorMap = new QCPColorMap(ui->customPlot->xAxis, ui->customPlot->yAxis);
            int nx = n_celulas;
            int ny = n_celulas;
            colorMap->data()->setSize(nx, ny);
            colorMap->data()->setRange(QCPRange(-lagdistance*nlags, lagdistance*nlags), QCPRange(-lagdistance*nlags, lagdistance*nlags)); // and span the coordinate range -4..4 in both key (x) and value (y) dimensions


            double x, y;
            double distance;

            // Pegando os valores do x e y do grid

            QVector<double> xgrid;
            QVector<double> ygrid;
            for (int xIndex=0; xIndex<nx; ++xIndex)
            {
              for (int yIndex=0; yIndex<ny; ++yIndex)
              {
                    colorMap->data()->cellToCoord(xIndex, yIndex, &x, &y);
                    xgrid.append(x);
                    ygrid.append(y);
               }
             }

            // Interpolando os valores no grid

            QVector<double> interpolados;
            double distancia_eixo;


            for (int i= 0; i< xgrid.size(); i++){
                int soma_valores = 0;
                int contagem = 0;
                for (int j = 0; j< xvalues.size(); j++){
                   distance = sqrt((xgrid[i] - xvalues[j])*(xgrid[i] - xvalues[j]) + (ygrid[i] - yvalues[j])*(ygrid[i] - yvalues[j]));
                   distancia_eixo = sqrt(xgrid[i]*xgrid[i] +ygrid[i]*ygrid[i]);
                   distancia_eixo = 1.3*distancia_eixo*sin(20*M_PI/180.00);
                   if (distance < distancia_eixo){
                       soma_valores = soma_valores + continuidade[j];
                       contagem = contagem + 1;
                   }
                }
                if (contagem == 0){
                    interpolados.append(soma_valores/1);
                }
                else{
                   interpolados.append(soma_valores/contagem);
                }
            }

            ui->progressBar->setValue(70);


            int p = 0;
            for (int xIndex=0; xIndex<nx; ++xIndex)
            {
              for (int yIndex=0; yIndex<ny; ++yIndex)
              {
                colorMap->data()->cellToCoord(xIndex, yIndex, &x, &y);
                colorMap->data()->setCell(xIndex, yIndex, interpolados[p]);
                p++;
              }
            }

            ui->progressBar->setValue(80);

            // ADICIONE UMA ESCALA DE COR


            // DETERMINE O GRADIENTE DE COR DO MAPA


            ui->customPlot->plotLayout()->removeAt(1);

            if (gradiente_tipo == "Grayscale"){


                QCPColorScale *colorScale = new QCPColorScale(ui->customPlot);
                QCPColorGradient *gradiente = new QCPColorGradient(QCPColorGradient::gpGrayscale);
                gradiente->setLevelCount(grau_refinamento);
                colorMap->setGradient(*gradiente);
                colorScale->setGradient(*gradiente);

                ui->customPlot->plotLayout()->addElement(0, 1, colorScale); // add it to the right of the main axis rect
                colorScale->setType(QCPAxis::atRight); // scale shall be vertical bar with tick/axis labels right (actually atRight is already the default)
                colorMap->setColorScale(colorScale); // associate the color map with the color scale
                colorScale->axis()->setLabel("Mapa de Variogramas");

                colorMap->rescaleDataRange();

                QCPMarginGroup *marginGroup = new QCPMarginGroup(ui->customPlot);
                ui->customPlot->axisRect()->setMarginGroup(QCP::msBottom|QCP::msTop, marginGroup);
                colorScale->setMarginGroup(QCP::msBottom|QCP::msTop, marginGroup);


            }

            if (gradiente_tipo == "Hot"){


                QCPColorScale *colorScale = new QCPColorScale(ui->customPlot);
                QCPColorGradient *gradiente = new QCPColorGradient(QCPColorGradient::gpHot);
                gradiente->setLevelCount(grau_refinamento);
                colorMap->setGradient(*gradiente);
                colorScale->setGradient(*gradiente);

                ui->customPlot->plotLayout()->addElement(0, 1, colorScale); // add it to the right of the main axis rect
                colorScale->setType(QCPAxis::atRight); // scale shall be vertical bar with tick/axis labels right (actually atRight is already the default)
                colorMap->setColorScale(colorScale); // associate the color map with the color scale
                colorScale->axis()->setLabel("Mapa de Variogramas");


                colorMap->rescaleDataRange();

                QCPMarginGroup *marginGroup = new QCPMarginGroup(ui->customPlot);
                ui->customPlot->axisRect()->setMarginGroup(QCP::msBottom|QCP::msTop, marginGroup);
                colorScale->setMarginGroup(QCP::msBottom|QCP::msTop, marginGroup);


            }

            if (gradiente_tipo == "Cold"){


                QCPColorScale *colorScale = new QCPColorScale(ui->customPlot);
                QCPColorGradient *gradiente = new QCPColorGradient(QCPColorGradient::gpCold);
                gradiente->setLevelCount(grau_refinamento);
                colorMap->setGradient(*gradiente);
                colorScale->setGradient(*gradiente);

                ui->customPlot->plotLayout()->addElement(0, 1, colorScale); // add it to the right of the main axis rect
                colorScale->setType(QCPAxis::atRight); // scale shall be vertical bar with tick/axis labels right (actually atRight is already the default)
                colorMap->setColorScale(colorScale); // associate the color map with the color scale
                colorScale->axis()->setLabel("Mapa de Variogramas");

                colorMap->rescaleDataRange();

                QCPMarginGroup *marginGroup = new QCPMarginGroup(ui->customPlot);
                ui->customPlot->axisRect()->setMarginGroup(QCP::msBottom|QCP::msTop, marginGroup);
                colorScale->setMarginGroup(QCP::msBottom|QCP::msTop, marginGroup);

            }

            if (gradiente_tipo == "Polar"){

                QCPColorScale *colorScale = new QCPColorScale(ui->customPlot);
                QCPColorGradient *gradiente = new QCPColorGradient(QCPColorGradient::gpPolar);
                gradiente->setLevelCount(grau_refinamento);
                colorMap->setGradient(*gradiente);
                colorScale->setGradient(*gradiente);

                ui->customPlot->plotLayout()->addElement(0, 1, colorScale); // add it to the right of the main axis rect
                colorScale->setType(QCPAxis::atRight); // scale shall be vertical bar with tick/axis labels right (actually atRight is already the default)
                colorMap->setColorScale(colorScale); // associate the color map with the color scale
                colorScale->axis()->setLabel("Mapa de Variogramas");

                colorMap->rescaleDataRange();

                QCPMarginGroup *marginGroup = new QCPMarginGroup(ui->customPlot);
                ui->customPlot->axisRect()->setMarginGroup(QCP::msBottom|QCP::msTop, marginGroup);
                colorScale->setMarginGroup(QCP::msBottom|QCP::msTop, marginGroup);

            }

            if (gradiente_tipo == "Hues"){

                 QCPColorScale *colorScale = new QCPColorScale(ui->customPlot);
                QCPColorGradient *gradiente = new QCPColorGradient(QCPColorGradient::gpHues);
                gradiente->setLevelCount(grau_refinamento);
                colorMap->setGradient(*gradiente);
                colorScale->setGradient(*gradiente);

                ui->customPlot->plotLayout()->addElement(0, 1, colorScale); // add it to the right of the main axis rect
                colorScale->setType(QCPAxis::atRight); // scale shall be vertical bar with tick/axis labels right (actually atRight is already the default)
                colorMap->setColorScale(colorScale); // associate the color map with the color scale
                colorScale->axis()->setLabel("Mapa de Variogramas");


                colorMap->rescaleDataRange();

                QCPMarginGroup *marginGroup = new QCPMarginGroup(ui->customPlot);
                ui->customPlot->axisRect()->setMarginGroup(QCP::msBottom|QCP::msTop, marginGroup);
                colorScale->setMarginGroup(QCP::msBottom|QCP::msTop, marginGroup);



            }

            if (gradiente_tipo == "Spectrum"){

                QCPColorScale *colorScale = new QCPColorScale(ui->customPlot);

                QCPColorGradient *gradiente = new QCPColorGradient(QCPColorGradient::gpSpectrum);
                gradiente->setLevelCount(grau_refinamento);
                colorMap->setGradient(*gradiente);
                colorScale->setGradient(*gradiente);

                ui->customPlot->plotLayout()->addElement(0, 1, colorScale); // add it to the right of the main axis rect
                colorScale->setType(QCPAxis::atRight); // scale shall be vertical bar with tick/axis labels right (actually atRight is already the default)
                colorMap->setColorScale(colorScale); // associate the color map with the color scale
                colorScale->axis()->setLabel("Mapa de Variogramas");

                colorMap->rescaleDataRange();

                QCPMarginGroup *marginGroup = new QCPMarginGroup(ui->customPlot);
                ui->customPlot->axisRect()->setMarginGroup(QCP::msBottom|QCP::msTop, marginGroup);
                colorScale->setMarginGroup(QCP::msBottom|QCP::msTop, marginGroup);

            }



            ui->customPlot->rescaleAxes();
            ui->customPlot->replot();
            ui->customPlot->show();

        }

        ui->progressBar->setValue(100);


}

void Variogram_Map::on_pushButton_2_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Salvar Imagem"),"",tr("Images (*.png *.xpm *.jpg)"));

    if (fileName != ""){
        ui->customPlot->saveJpg(fileName,0,0,1.0,-1,96);

        QMessageBox msgBox;
        msgBox.setText("Figura Salva");
        msgBox.exec();
    }

}
