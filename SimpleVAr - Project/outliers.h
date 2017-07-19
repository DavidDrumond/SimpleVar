#ifndef OUTLIERS_H
#define OUTLIERS_H

#include <QDialog>

namespace Ui {
class Outliers;
}

class Outliers : public QDialog
{
    Q_OBJECT

public:
    explicit Outliers(QWidget *parent = 0);
    ~Outliers();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Outliers *ui;
};

#endif // OUTLIERS_H
