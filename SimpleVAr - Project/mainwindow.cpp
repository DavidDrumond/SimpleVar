#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "abrir_arquivo.h"
#include "outliers.h"
#include "variogram_map.h"
#include "parametros_variograma_experimental.h"
#include "modelagem_variograma.h"
#include "scatterplot.h"
#include "statistics.h"
#include "sugerir_lag.h"
#include "vizualizacao.h"




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap pix (":/imagens/SimpleVar2.png");
    ui->emptylabel->setPixmap(pix);

    //fourier_transform f;





}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionDados_triggered()
{
    abrir_arquivo *abrir = new abrir_arquivo(this);
    abrir->show();
    abrir->exec();

}

void MainWindow::on_actionOutliers_triggered()
{
    Outliers *abrir = new Outliers(this);
    abrir->show();
    abrir->exec();
}

void MainWindow::on_actionVariogram_Map_triggered()
{
    Variogram_Map *var = new Variogram_Map(this);
    var->show();
    var->exec();
}

void MainWindow::on_actionVariograma_Experimental_triggered()
{
    Parametros_Variograma_Experimental *par = new Parametros_Variograma_Experimental(this);
    par->show();
    par->exec();
}

void MainWindow::on_actionModelo_de_Continuidade_Espacial_triggered()
{
    Modelagem_Variograma *model = new Modelagem_Variograma(this);
    model->show();
    model->exec();

}

void MainWindow::on_actionScatter_Plot_triggered()
{
    Scatterplot *scar = new Scatterplot(this);
    scar->show();
    scar->exec();

}

void MainWindow::on_actionEstat_stica_Univariada_triggered()
{
    statistics *s = new statistics(this);
    s->show();
    s->exec();
}

void MainWindow::on_actionCalcular_dist_ncias_triggered()
{
    sugerir_lag *s = new sugerir_lag(this);
    s->show();
    s->exec();
}

void MainWindow::on_actionVizualizar_Dados_triggered()
{
    vizualizacao *v = new vizualizacao(this);
    v->show();
    v->exec();
}
