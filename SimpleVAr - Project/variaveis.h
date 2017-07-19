#ifndef VARIAVEIS_H
#define VARIAVEIS_H
#include <QVector>
#include <QColor>


class Variaveis
{
public:
    Variaveis();
    int number_variables;
    int dimension;
    int number_dados;
    QVector<QVector <double>> variaveis_externas;
    QVector <QString> cabecalho;

    int numero_variogramas;
    QVector <QColor> cores;
    QVector < QVector<double>> v_continuidades;
    QVector < QVector<double>> v_lags;
    QVector < QVector<double>> v_azimutes;
    QVector < QVector <double>> v_dips;
    QVector < QVector <double>> v_var_priori;
    QVector <QVector<double>> v_lags_variancia;
    QVector < QVector <double>> var_pares;
    double max_lag_distance;

    QVector< double> x_rot;
    QVector<double> y_rot;
    QVector <double> z_rot;
    QVector <double> values_rot;
    QVector <double> cores_rot;

    QVector< double> x_rot_c;
    QVector<double> y_rot_c;
    QVector <double> z_rot_c;

    double xcentro;
    double ycentro;
    double zcentro;

    double xminimo;
    double xmaximo;
    double yminimo;
    double ymaximo;

    int verificar_arquivo;

    QVector <double> min;
    QVector <double> max;
    QVector <QVector <double>> filtrosx;
    QVector <QVector <double>> filtrosy;
    QVector <QColor> cores_v;

};

#endif // VARIAVEIS_H
