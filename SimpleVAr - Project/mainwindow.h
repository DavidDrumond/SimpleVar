#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:




    void on_actionDados_triggered();

    void on_actionOutliers_triggered();

    void on_actionVariogram_Map_triggered();

    void on_actionVariograma_Experimental_triggered();

    void on_actionModelo_de_Continuidade_Espacial_triggered();

    void on_actionScatter_Plot_triggered();

    void on_actionEstat_stica_Univariada_triggered();

    void on_actionCalcular_dist_ncias_triggered();

    void on_actionVizualizar_Dados_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
