#include "parametros_variograma_experimental.h"
#include "ui_parametros_variograma_experimental.h"
#include "dados.h"
#include "qcustomplot.h"
#include <QColordialog>
#include <QMessageBox>
#include <math.h>
#define _USE_MATH_DEFINES
#include <cmath>
#include "delegate.h"




Parametros_Variograma_Experimental::Parametros_Variograma_Experimental(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Parametros_Variograma_Experimental)
{
    ui->setupUi(this);

    int j = 0;
    for (int i = var.dimension; i < (var.dimension+var.number_variables); i++){
        ui->cabeca->insertItem(j,var.cabecalho[i]);
        ui->rabo->insertItem(j,var.cabecalho[i]);
        j ++;
    }

    ui->tabela->setItemDelegate(new Delegate);

    ui->tabela->setRowCount(1);


    QComboBox* combo = new QComboBox();
    combo->addItem("Variograma");
    combo->addItem("Covariograma");
    combo->addItem("Correlograma");


    ui->tabela->setItem(0,7, new QTableWidgetItem);
    ui->tabela->item(0,7)->setBackground(Qt::black);
    ui->tabela->setCellWidget(0, 6,combo);






}

Parametros_Variograma_Experimental::~Parametros_Variograma_Experimental()
{
    delete ui;
}

void Parametros_Variograma_Experimental::on_ndirecoes_valueChanged(int arg1)
{
    int numero_linhas = ui->ndirecoes->text().toInt();
    ui->tabela->setRowCount(numero_linhas);

    for (int i = 0; i < numero_linhas; i++){

        QComboBox* combo = new QComboBox();
        combo->addItem("Variograma");
        combo->addItem("Covariograma");
        combo->addItem("Correlograma");


        ui->tabela->setItem(i,7, new QTableWidgetItem);
        ui->tabela->item(i,7)->setBackground(Qt::black);
        ui->tabela->setCellWidget(i, 6,combo);


    }
}

void Parametros_Variograma_Experimental::on_clicked_buttom(){

}

void Parametros_Variograma_Experimental::botao_apertado(){



}

QString identificar_virgula(QString palavra){
    QString retorno = "";
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



void Parametros_Variograma_Experimental::on_tabela_cellPressed(int row, int column)
{
        if (column == 7){
            QColor color = QColorDialog::getColor(Qt::white, this,"Selecione sua cor");
            QModelIndexList selecionados = ui->tabela->selectionModel()->selectedIndexes();
            QModelIndex item = selecionados.at(0);
            int row2 = item.row();
            ui->tabela->item(row2,column)->setBackgroundColor(color);
         }

}

void Parametros_Variograma_Experimental::on_pushButton_clicked()
{

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

        // Pegue os valores da user interface
        int numero_variogramas = ui->ndirecoes->text().toInt();
        double lagdistance = ui->lagsize->value();
        double linear_tol = ui->linear_tol->value();
        double nlags = ui->nlags->text().toDouble();
        int var_aceito = ui->Varpriori->isChecked();
        int show_par = ui->showpar->isChecked();
        int todos = ui->Todos->isChecked();

        if (linear_tol > 0.5*lagdistance){
            QMessageBox *m = new QMessageBox;
            m->setText("Um valor de tolerância linear maior que metade do tamanho do lag pode produzir valores indesejados. Reestabelecendo a tolerância máxima.");
            m->show();
            linear_tol = 0.5*lagdistance;
        }

        QVector<double> azm;
        QVector<double> dip;
        QVector<double> htol;
        QVector<double> vtol;
        QVector<double> bandh;
        QVector<double> bandv;
        QVector<QString> modelo;
        QVector<QColor> cores;


        // Teste da tabela do qtablewidget teste -> se existe um valor, teste2 -> se o valor e numerico

        bool teste = true;


        ui->customPlot->plotLayout()->clear();

        for (int i = 0; i< numero_variogramas; i++){
            for (int j=0; j< 6; j++){
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


        if (teste == true ){
            QString entrada;
            for (int i = 0; i < numero_variogramas; i++){
                for (int j = 0; j < 8; j++){
                    switch(j){
                        case 0:
                            entrada = identificar_virgula(ui->tabela->item(i,j)->text());
                            azm.push_back(entrada.toDouble());
                            break;
                        case 1:
                            entrada = identificar_virgula(ui->tabela->item(i,j)->text());
                            dip.push_back(entrada.toDouble());
                            break;
                        case 2:
                            entrada = identificar_virgula(ui->tabela->item(i,j)->text());
                            htol.push_back(entrada.toDouble());
                            break;
                        case 3:
                            entrada = identificar_virgula(ui->tabela->item(i,j)->text());
                            vtol.push_back(entrada.toDouble());
                            break;
                        case 4:
                            entrada = identificar_virgula(ui->tabela->item(i,j)->text());
                            bandv.push_back(entrada.toDouble());
                            break;
                        case 5:
                            entrada = identificar_virgula(ui->tabela->item(i,j)->text());
                            bandh.push_back(entrada.toDouble());
                            break;
                        case 7:
                            QColor cor;
                            cor = ui->tabela->item(i,j)->backgroundColor();
                            cores.push_back(cor);
                            break;

                    }
                    if (j == 6){

                        QComboBox *myCB = qobject_cast<QComboBox*>(ui->tabela->cellWidget(i,j));
                        modelo.push_back(myCB->currentText());

                    }
                }
            }

            ui->progressBar->setValue(10);

            if (indice_cabeca != -6 || indice_rabo != - 6){

                QVector < QVector<double>> v_continuidades;
                QVector < QVector<double>> v_lags;
                QVector < QVector<double>> v_lags_variancia;
                QVector < QVector<double>> v_azimutes;
                QVector < QVector <double>> v_dips;
                QVector < QVector <double>> v_var_priori;
                QVector < QVector <double>> var_pares;

                // Calcule a variancia a priori do problema

                double variancia_a_priori =0;
                double media_cabeca =0;
                double media_rabo = 0;
                double soma_cabeca= 0;
                double soma_rabo =0 ;
                int ndados = 0;

                double variancia1 = 0;
                double variancia2 = 0;


                for (int i = 0 ; i < var.variaveis_externas[indice_cabeca].length(); i ++){
                    if (var.variaveis_externas[indice_cabeca][i] != -999.999 && var.variaveis_externas[indice_rabo][i] != -999.999){
                        soma_cabeca = soma_cabeca + var.variaveis_externas[indice_cabeca][i];
                        soma_rabo = soma_rabo + var.variaveis_externas[indice_rabo][i];
                        ndados++;
                     }
                }
                media_cabeca = soma_cabeca/ndados;
                media_rabo = soma_rabo/ndados;

                variancia_a_priori = 0;
                for(int i =0; i < var.variaveis_externas[indice_cabeca].length();i++){
                    if (var.variaveis_externas[indice_cabeca][i] != -999.999 && var.variaveis_externas[indice_rabo][i] != -999.999){
                        variancia_a_priori = variancia_a_priori + (var.variaveis_externas[indice_cabeca][i] - media_cabeca)*(var.variaveis_externas[indice_rabo][i] - media_rabo)/ndados;
                        variancia1 = variancia1 + (var.variaveis_externas[indice_cabeca][i] - media_cabeca)*(var.variaveis_externas[indice_cabeca][i] - media_cabeca)/ndados;
                        variancia2 =  variancia2  + (var.variaveis_externas[indice_rabo][i] - media_rabo)*(var.variaveis_externas[indice_rabo][i] - media_rabo)/ndados;
                     }
               }

                for ( int direcao = 0; direcao < numero_variogramas; direcao++){
                        // Converta tolerancias se elas forem iguais a zero

                        double lineartolerance = linear_tol ;
                        double hband = bandh[direcao];
                        double vband = bandv[direcao];
                        double htolerance = htol[direcao];
                        double vtolerance = vtol[direcao];

                        double dmaximo = (nlags +0.5)*lagdistance;


                        // Converta os valores de tolerancia em radianos

                        htolerance = htolerance*M_PI/180.00;
                        vtolerance = vtolerance*M_PI/180.00;
                        // Determine as projecoes do dip e do azimute

                        htolerance = cos(htolerance);
                        vtolerance = cos(vtolerance);

                        QVector<double> xhrot;
                        QVector<double> yhrot;
                        QVector<double> zhrot;
                        QVector<double> xttrot;
                        QVector<double> yttrot;
                        QVector<double> zttrot;

                        double xrot = 0;
                        double yrot = 0;
                        double zrot = 0;


                        // Atribua as variáveis espaciais

                        int tamanho =  var.variaveis_externas[0].size();
                        for (int i=0; i< tamanho; i++){

                            double zh = 0;
                            double yh = 0;
                            if (var.dimension == 1){
                                yh = 0;
                            }
                            else{
                                yh = var.variaveis_externas[1][i];
                            }
                            if (var.dimension == 2){
                               zh = 0;
                            }
                            else{
                               zh = var.variaveis_externas[2][i];
                            }

                            xrot = var.variaveis_externas[0][i];
                            yrot = yh;
                            zrot = zh;

                            xhrot.push_back(xrot);
                            yhrot.push_back(yrot);
                            zhrot.push_back(zrot);
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

                    double dx =0;
                    double dy=0;
                    double dz=0;
                    double dh=0;


                    for (int t=0; t < xhrot.length(); t++){
                        for (int h=0; h< xhrot.length(); h++){
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

                                    cabeca.push_back(var.variaveis_externas[indice_cabeca][h]);
                                    cabeca2.push_back(var.variaveis_externas[indice_rabo][h]);
                                    rabo2.push_back(var.variaveis_externas[indice_rabo][t]);
                                    rabo.push_back(var.variaveis_externas[indice_cabeca][t]);

                                    distanciay.push_back(dy);
                                    distanciax.push_back(dx);
                                    distanciaz.push_back(dz);
                                    distanciah.push_back(dh);
                                    distanciaxy.push_back(sqrt(dy*dy + dx*dx));
                                }
                            }
                        }
                    }

                    ui->progressBar->setValue(40);

                    // CALCULE TODOS OS VALORES DE COS E SENO ADMISSIVEIS AO AZIMUTE


                    double cos_Azm =0;
                    double sin_Azm = 0;
                    double sin_Dip = 0;
                    double cos_Dip = 0;
                    double valor = 0;
                    double valor2 = 0;

                    valor = azm[direcao];
                    cos_Azm = cos((90.00-valor)*M_PI/180.00);
                    sin_Azm = sin((90.00-valor)*M_PI/180.00);

                    valor2 =dip[direcao];
                    cos_Dip = cos(M_PI/180.00*(90-valor2));
                    sin_Dip = sin(M_PI/180.00*(90-valor2));



                    QVector <QVector<double>> distancias_admissiveis;
                    QVector <QVector<double>> azimute_admissiveis;
                    QVector <QVector<double>> dip_admissiveis;
                    QVector <QVector<double>> v_valores_admissiveis_h;
                    QVector <QVector<double>> v_valores_admissiveis_t;
                    QVector <QVector<double>> v_valores_admissiveis_h2;
                    QVector <QVector<double>> v_valores_admissiveis_t2;
                    QVector<double> pares;



                    double lag = 0;
                    int par = 0;
                    double limitemin = 0;
                    double limitemax = 0;



                    double check_azimute= 0;
                    double check_dip= 0;
                    double check_bandh= 0;
                    double check_bandv= 0;



                    // CALCULE OS PONTOS ADMISSIVEIS

                    for (int l= 0; l< nlags; l++){

                        QVector<double> valores_admissiveis_h;
                        QVector<double> valores_admissiveis_t;
                        QVector<double> valores_admissiveis_h2;
                        QVector<double> valores_admissiveis_t2;
                        QVector<double> distancia_admissivel;
                        QVector<double> azimute_admissivel;
                        QVector<double> dip_admissivel;

                        lag = lagdistance*(l+1);
                        par = 0;
                        limitemin = lag - lineartolerance;
                        limitemax = lag + lineartolerance;

                        for (int p = 0; p < distanciah.size(); p++){
                            if (distanciah[p] > limitemin && distanciah[p] < limitemax){
                                if (distanciaxy[p] > 0){
                                    check_azimute = (distanciax[p]*cos_Azm +distanciay[p]*sin_Azm)/distanciaxy[p];
                                }
                                else{
                                    check_azimute = 1.00;
                                }
                                if (check_azimute >= htolerance){
                                    check_bandh = (cos_Azm*distanciay[p]) - (sin_Azm*distanciax[p]);
                                    check_bandh = fabs(check_bandh);
                                    if (check_bandh < hband){
                                        if(distanciah[p] > 0.000){
                                           check_dip = (fabs(distanciaxy[p])*sin_Dip + distanciaz[p]*cos_Dip)/distanciah[p];
                                        }
                                        else{
                                           check_dip = 0.000;
                                        }
                                        check_dip = fabs(check_dip);
                                        if (check_dip >= vtolerance){
                                            check_bandv = sin_Dip*distanciaz[p] - cos_Dip*fabs(distanciaxy[p]);
                                            check_bandv = fabs(check_bandv);
                                            if (check_bandv < vband){
                                                valores_admissiveis_h.push_back(cabeca[p]);
                                                valores_admissiveis_t.push_back(rabo[p]);
                                                valores_admissiveis_h2.push_back(cabeca2[p]);
                                                valores_admissiveis_t2.push_back(rabo2[p]);
                                                distancia_admissivel.push_back(distanciah[p]);
                                                par = par + 1;
                                                azimute_admissivel.push_back(azm[direcao]);
                                                dip_admissivel.push_back(dip[direcao]);
                                            }
                                         }
                                       }
                                    }
                                }
                             }

                           if (valores_admissiveis_h.size() > 0){

                                v_valores_admissiveis_h.push_back(valores_admissiveis_h);
                                v_valores_admissiveis_h2.push_back(valores_admissiveis_h2);
                                v_valores_admissiveis_t2.push_back(valores_admissiveis_t2);
                                v_valores_admissiveis_t.push_back(valores_admissiveis_t);
                                distancias_admissiveis.push_back(distancia_admissivel);
                                pares.push_back(par);
                                azimute_admissiveis.push_back(azimute_admissivel);
                                dip_admissiveis.push_back(dip_admissivel);
                            }
                       }

                ui->progressBar->setValue(60);

                 // Calcule os variogramas experimentais

                QVector <double> continuidade;
                QVector <double> lag_adm;
                QVector <double> azimute_adm;
                QVector <double> dip_adm;
                QVector <double> var_a_priori;

                // Variogram

                if (modelo[direcao] == "Variograma"){
                    for ( int i = 0; i <v_valores_admissiveis_h.length();i++){
                        QVector <double> flutuantet;
                        QVector <double> flutuanteh;
                        QVector <double> flutuanteh2;
                        QVector <double> flutuantet2;
                        QVector <double> flutuanted;
                        QVector <double> flutuantea;
                        QVector <double> flutuantedip;
                        flutuanteh = v_valores_admissiveis_h[i];
                        flutuanteh2= v_valores_admissiveis_h2[i];
                        flutuantet = v_valores_admissiveis_t[i];
                        flutuantet2 = v_valores_admissiveis_t2[i];
                        flutuanted = distancias_admissiveis[i];
                        flutuantea= azimute_admissiveis[i];
                        flutuantedip = dip_admissiveis[i];
                        double soma = 0;
                        double lagmedio =0;
                        double agmedio =0;
                        double dgmedio = 0;
                        for (int j = 0; j < flutuanteh.size();j ++){
                            soma = soma + (flutuanteh[j] - flutuantet[j])*(flutuanteh2[j]-flutuantet2[j])/(2*pares[i]);
                        }
                        continuidade.push_back(soma);
                        for (int z = 0; z < flutuanteh.size();z ++){
                            lagmedio = lagmedio + flutuanted[z]/flutuanted.length();
                        }
                        lag_adm.push_back(lagmedio);
                        for (int g=0; g< flutuantea.length(); g++){
                            agmedio = agmedio + flutuantea[g]/flutuantea.length();
                        }
                        azimute_adm.push_back(agmedio);
                        for ( int t= 0; t < flutuantedip.length(); t++){
                            dgmedio = dgmedio + flutuantedip[t]/flutuantedip.length();
                        }
                        dip_adm.push_back(dgmedio);
                    }
                 }



                // Covariogram
                if (modelo[direcao] == "Covariograma"){
                    for ( int i = 0; i <v_valores_admissiveis_h.length();i++){
                        QVector <double> flutuantet;
                        QVector <double> flutuanteh;
                        QVector <double> flutuanteh2;
                        QVector <double> flutuantet2;
                        QVector <double> flutuanted;
                        QVector <double> flutuantea;
                        QVector <double> flutuantedip;
                        int par_var = 0;
                        flutuanteh = v_valores_admissiveis_h[i];
                        flutuanteh2= v_valores_admissiveis_h2[i];
                        flutuantet = v_valores_admissiveis_t[i];
                        flutuantet2 = v_valores_admissiveis_t2[i];
                        flutuanted = distancias_admissiveis[i];
                        flutuantea= azimute_admissiveis[i];
                        flutuantedip = dip_admissiveis[i];
                        par_var= pares[i];
                        double soma = 0;
                        double lagmedio =0;
                        double agmedio =0;
                        double dgmedio = 0;
                        double somah = 0;
                        double somat = 0;
                        double mediah = 0;
                        double mediat =0;
                        for (int d =0; d< flutuanteh.length(); d++){
                            somah = somah + flutuanteh[d];
                        }
                        mediah = somah/flutuanteh.length();
                        for (int t=0; t< flutuantet.length(); t++){
                            somat = somat + flutuantet[t];
                        }
                        mediat = somat/flutuantet.length();
                        for (int j=0; j < flutuanteh.length(); j++){
                            soma = soma + (((flutuanteh[j] - mediah)*(flutuantet[j] - mediat))/(par_var));
                        }
                        continuidade.push_back(soma);
                        for (int z =0; z < flutuanted.length(); z++){
                            lagmedio = lagmedio + flutuanted[z]/flutuanted.length();
                        }
                        lag_adm.push_back(lagmedio);
                        for ( int g=0; g < flutuantea.length(); g++){
                            agmedio = agmedio + flutuantea[g]/flutuantea.length();
                        }
                        azimute_adm.push_back(agmedio);
                        for ( int y=0; y < flutuantedip.length(); y++){
                            dgmedio = dgmedio + flutuantedip[y]/flutuantedip.length();
                        }
                        dip_adm.push_back(dgmedio);
                    }
                }

                // Correlogram
                if (modelo[direcao] == "Correlograma"){
                    for ( int i = 0; i <v_valores_admissiveis_h.length();i++){
                        QVector <double> flutuantet;
                        QVector <double> flutuanteh;
                        QVector <double> flutuanteh2;
                        QVector <double> flutuantet2;
                        QVector <double> flutuanted;
                        QVector <double> flutuantea;
                        QVector <double> flutuantedip;
                        int par_var = 0;
                        flutuanteh = v_valores_admissiveis_h[i];
                        flutuanteh2= v_valores_admissiveis_h2[i];
                        flutuantet = v_valores_admissiveis_t[i];
                        flutuantet2 = v_valores_admissiveis_t2[i];
                        flutuanted = distancias_admissiveis[i];
                        flutuantea= azimute_admissiveis[i];
                        flutuantedip = dip_admissiveis[i];
                        par_var= pares[i];
                        double soma = 0;
                        double lagmedio =0;
                        double agmedio =0;
                        double dgmedio = 0;
                        double somah = 0;
                        double somat = 0;
                        double mediah = 0;
                        double mediat =0;
                        double varh = 0;
                        double vart = 0;
                        double diferencah = 0;
                        double diferencat = 0;
                        for (int d =0; d< flutuanteh.length(); d++){
                            somah = somah + flutuanteh[d];
                        }
                        mediah = somah/flutuanteh.length();
                        for (int t; t< flutuantet.length(); t++){
                            somat = somat + flutuantet[t];
                        }
                        mediat = somat/flutuantet.length();
                        for (int u=0; u < flutuanteh.length(); u++){
                            diferencah = flutuanteh[u]*flutuanteh[u] + diferencah;
                        }
                        varh = sqrt(diferencah/flutuanteh.length()-mediah*mediah);
                        for (int m=0; m < flutuanteh.length();m++){
                            diferencat = flutuantet[m]*flutuantet[m] + diferencat;
                        }
                        vart = sqrt((diferencat)/flutuantet.length()-mediat*mediat);
                        for (int j =0; j < flutuanteh.length(); j++){
                                if (vart > 0 && varh >0 ){
                                    soma = soma + (flutuanteh[j] - mediah)*(flutuantet[j] - mediat)/(par_var*vart*varh);
                                }
                        }
                        continuidade.push_back(soma);
                        for (int z =0; z <flutuanted.length();z++){
                            lagmedio = lagmedio + flutuanted[z]/flutuanted.length();
                        }
                        lag_adm.push_back(lagmedio);
                        for (int g = 0; g < flutuantea.length(); g++){
                            agmedio = agmedio + flutuantea[g]/flutuantea.length();
                        }
                        azimute_adm.push_back(agmedio);
                        for (int y = 0; y < flutuantedip.length(); y++){
                            dgmedio = dgmedio + flutuantedip[y]/flutuantedip.length();
                        }
                        dip_adm.push_back(dgmedio);
                      }
                   }

                QVector<double> lags_variancia;

                if (lag_adm.length() > 0){
                    for (int i = 0; i < (lag_adm[lag_adm.length()-1]+5*lagdistance); i++){
                        lags_variancia.push_back(i);
                        if (modelo[direcao] == "Correlograma"){
                            var_a_priori.append(1-variancia_a_priori/(variancia1*variancia2));
                        }
                        else{
                            var_a_priori.append(variancia_a_priori);
                        }

                    }
                 }

                var_pares.append(pares);
                v_var_priori.append(var_a_priori);
                v_continuidades.push_back(continuidade);
                v_lags.push_back(lag_adm);
                v_azimutes.push_back(azimute_adm);
                v_dips.push_back(dip_adm);
                v_lags_variancia.push_back(lags_variancia);

                }

                ui->progressBar->setValue(80);

                // ATRIBUIR OS VARIOGRAMAS EXPERIMENTAIS PARA O OBJETO VAR

                var.var_pares = var_pares;
                var.v_var_priori = v_var_priori;
                var.v_continuidades = v_continuidades;
                var.v_lags = v_lags;
                var.v_azimutes = v_azimutes;
                var.v_dips = v_dips;
                var.numero_variogramas = numero_variogramas;
                var.cores = cores;
                var.max_lag_distance = lagdistance*nlags;
                var.v_lags_variancia = v_lags_variancia;

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

                if (todos != 1){
                        for (int i = 0; i < numero_variogramas; i++){

                            QPen pena;
                            pena.setColor(cores[i]);


                            QPen pena2;
                            pena2.setColor(Qt::green);
                            pena2.setStyle(Qt::DashDotLine);
                            QString titulo;
                            if (v_azimutes[i].length() > 0){
                                titulo = (QString::fromUtf8("\u03C6") +" (h) - Azm: " + QString::number(v_azimutes[i][0]) + " - Dip: " +QString::number(v_dips[i][0]) );
                            }
                            else{
                                titulo = "";
                            }

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
                                for (int j=0; j < var_pares[i].length();j++){
                                    QCPItemText *pares_texto = new QCPItemText(ui->customPlot);

                                    pares_texto->setClipToAxisRect(true);
                                    pares_texto->setClipAxisRect(r);
                                    pares_texto->position->setAxisRect(r);
                                    pares_texto->position->setAxes(r->axis(QCPAxis::atBottom), r->axis(QCPAxis::atLeft));
                                    pares_texto->position->setType(QCPItemPosition::ptPlotCoords);

                                    pares_texto->position->setCoords(v_lags[i][j],(v_continuidades[i][j]+fabs(v_continuidades[i][j]-v_var_priori[i][j])/20));
                                    pares_texto->setRotation(-40);
                                    pares_texto->setText(QString::number(var_pares[i][j]));
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
                            if (v_continuidades[i].length() > 0){
                                Grafico->setData(v_lags[i],v_continuidades[i]);
                            }
                            if (var_aceito == 1){

                                QCPGraph *Grafico2 = ui->customPlot->addGraph(r->axis(QCPAxis::atBottom), r->axis(QCPAxis::atLeft));
                                ui->customPlot->graph()->setScatterStyle(QCPScatterStyle(shapes.at(0), 1));

                                if (v_var_priori[i].length() > 0){
                                    Grafico2->setData(v_lags_variancia [i],v_var_priori[i]);
                                }
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

                    QCPTextElement *title = new QCPTextElement(ui->customPlot);
                    title->setText("Modelo de Continuidade Espacial");
                    title->setFont(QFont("sans", 12, QFont::Bold));
                    ui->customPlot->plotLayout()->addElement(0, 0, title);

                    QCPAxisRect* r = new QCPAxisRect(ui->customPlot);
                    ui->customPlot->plotLayout()->addElement(1, 0, r);



                    QCPTextElement *title2  = new QCPTextElement(ui->customPlot);
                    title2->setText("H");
                    title2->setFont(QFont("sans",7, QFont::Bold));
                    ui->customPlot->plotLayout()->addElement(2,0,title2);

                    ui->customPlot->rescaleAxes();


                    QCPLegend *legend1 = new QCPLegend();
                    QCPLayoutInset * xLayout = r->insetLayout();
                    xLayout->addElement((QCPLayoutElement*) legend1, Qt::AlignBottom|Qt::AlignRight);


                    int maior_lag = 0 ;
                    if(v_lags_variancia [0].length() >0){
                        double primeiro = v_lags_variancia [0][v_lags_variancia [0].length()-1];
                        for (int i = 0; i < numero_variogramas; i++){
                            int tamanho = v_lags_variancia .length();
                            double maior = v_lags_variancia [i][tamanho-1];
                            if (maior > primeiro){
                                primeiro = maior;
                                maior_lag++;
                            }

                        }
                    }

                    for (int i = 0; i < numero_variogramas; i++){
                            QPen pena;
                            pena.setColor(cores[i]);


                            if (show_par == 1){
                                for (int j=0; j < var_pares[i].length();j++){
                                    QCPItemText *pares_texto = new QCPItemText(ui->customPlot);

                                    pares_texto->setClipToAxisRect(true);
                                    pares_texto->setClipAxisRect(r);
                                    pares_texto->position->setAxisRect(r);
                                    pares_texto->position->setAxes(r->axis(QCPAxis::atBottom), r->axis(QCPAxis::atLeft));
                                    pares_texto->position->setType(QCPItemPosition::ptPlotCoords);
                                    pares_texto->position->setCoords(v_lags[i][j],(v_continuidades[i][j]+fabs(v_continuidades[i][j]-v_var_priori[i][j])/20));
                                    pares_texto->setRotation(-40);
                                    pares_texto->setText(QString::number(var_pares[i][j]));
                                    pares_texto->setFont(QFont(font().family(), 10));
                                }
                            }

                            QCPGraph *Grafico = ui->customPlot->addGraph(r->axis(QCPAxis::atBottom), r->axis(QCPAxis::atLeft));
                            ui->customPlot->graph()->setScatterStyle(QCPScatterStyle(shapes.at(tipo_ponto), 10));
                            if (v_continuidades[i].length()>0){
                                Grafico->setData(v_lags[i],v_continuidades[i]);
                                QString nome = (QString::fromUtf8("\u03C6") +" (h) - Azm: " + QString::number(v_azimutes[i][0]) + " - Dip: " +QString::number(v_dips[i][0]) );
                                Grafico->setPen(pena);
                                Grafico->setName(nome);
                            }

                            tipo_ponto++;


                     }

                    if (var_aceito == 1){
                        QCPGraph *Grafico2 = ui->customPlot->addGraph(r->axis(QCPAxis::atBottom), r->axis(QCPAxis::atLeft));
                        ui->customPlot->graph()->setScatterStyle(QCPScatterStyle(shapes.at(0), 1));
                        Grafico2->setData(v_lags[maior_lag],v_var_priori[maior_lag]);
                        Grafico2->setName("Variancia a priori");
                        QPen pena2;
                        pena2.setColor(Qt::green);
                        pena2.setStyle(Qt::DashDotLine);
                        Grafico2->setPen(pena2);
                    }


                    ui->customPlot->rescaleAxes();
                    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
                    ui->customPlot->replot();
                }
             }
            else{
                QMessageBox msgBox;
                msgBox.setText("As propriedades nao foram selecionadas");
                msgBox.exec();
            }


        }

        ui->progressBar->setValue(100);

}


void Parametros_Variograma_Experimental::on_pushButton_2_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Salvar Imagem"),"",tr("Images (*.png *.xpm *.jpg)"));

    if (fileName != ""){
        ui->customPlot->saveJpg(fileName,0,0,1.0,-1,96);

        QMessageBox msgBox;
        msgBox.setText("Figura Salva");
        msgBox.exec();
    }


}
