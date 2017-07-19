#include "variaveis.h"
#include <QVector>
#include <QColor>

Variaveis::Variaveis()
{
    int number_variables = 0;
    int dimension = 0;
    int number_dados = 0;
    QVector<QVector <double>> variaveis_externas;
    QVector <QString> cabecalho;

    QVector < QVector<double>> v_continuidades;
    QVector < QVector<double>> v_lags;
    QVector < QVector<double>> v_azimutes;
    QVector < QVector <double>> v_dips;
    QVector < QVector <double>> v_var_priori;
    QVector < QVector <double>> var_pares;
    QVector <QVector<double>> v_lags_variancia;
    int numero_variogramas = 0;
    double max_lag_distance = 0;
    QVector<QColor> cores;

    QVector< double> x_rot;
    QVector<double> y_rot;
    QVector <double> z_rot;

    QVector< double> x_rot_c;
    QVector<double> y_rot_c;
    QVector <double> z_rot_c;


    double xcentro = 0;
    double ycentro = 0;
    double zcentro = 0;

    double xminimo = 0;
    double xmaximo = 0;
    double yminimo = 0;
    double ymaximo = 0;

    int verificar_arquivo;

    double min = 0;
    double max = 0;
    QVector <QVector <double>> filtrosx;
    QVector <QVector <double>> filtrosy;
    QVector <QColor> cores_v;

}
