#ifndef PARAMETROS_VARIOGRAMA_EXPERIMENTAL_H
#define PARAMETROS_VARIOGRAMA_EXPERIMENTAL_H

#include <QDialog>
#include <QLineEdit>
#include <QDoubleValidator>


namespace Ui {
class Parametros_Variograma_Experimental;
}


class Parametros_Variograma_Experimental : public QDialog
{
    Q_OBJECT



public:
    explicit Parametros_Variograma_Experimental(QWidget *parent = 0);
    ~Parametros_Variograma_Experimental();



private slots:



    void on_ndirecoes_valueChanged(int arg1);
    void botao_apertado();
    void on_clicked_buttom();

    void on_tabela_cellPressed(int row, int column);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Parametros_Variograma_Experimental *ui;
};

#endif // PARAMETROS_VARIOGRAMA_EXPERIMENTAL_H
