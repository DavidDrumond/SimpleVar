#ifndef MODELAGEM_VARIOGRAMA_H
#define MODELAGEM_VARIOGRAMA_H

#include <QDialog>

namespace Ui {
class Modelagem_Variograma;
}

class Modelagem_Variograma : public QDialog
{
    Q_OBJECT

public:
    explicit Modelagem_Variograma(QWidget *parent = 0);
    ~Modelagem_Variograma();

private slots:
    void on_n_estruturas_valueChanged(int arg1);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Modelagem_Variograma *ui;
};

#endif // MODELAGEM_VARIOGRAMA_H
