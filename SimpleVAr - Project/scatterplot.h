#ifndef SCATTERPLOT_H
#define SCATTERPLOT_H

#include <QDialog>

namespace Ui {
class Scatterplot;
}

class Scatterplot : public QDialog
{
    Q_OBJECT

public:
    explicit Scatterplot(QWidget *parent = 0);
    ~Scatterplot();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Scatterplot *ui;
};

#endif // SCATTERPLOT_H
