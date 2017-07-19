#ifndef VIZUALIZACAO_H
#define VIZUALIZACAO_H

#include <QDialog>

namespace Ui {
class vizualizacao;
}

class vizualizacao : public QDialog
{
    Q_OBJECT

public:
    explicit vizualizacao(QWidget *parent = 0);
    ~vizualizacao();

private slots:
    void on_horizontalSlider_sliderMoved(int position);

    void on_pushButton_3_clicked();

    void on_verticalSlider_sliderMoved(int position);

    void on_nclasses_valueChanged(int arg1);

    void on_tabela_cellPressed(int row, int column);

    void on_pushButton_clicked();

    void on_Azimute_valueChanged(const QString &arg1);

    void on_Mergulho_valueChanged(int arg1);

    void on_pushButton_2_clicked();

private:
    Ui::vizualizacao *ui;
};

#endif // VIZUALIZACAO_H
