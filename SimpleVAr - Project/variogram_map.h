#ifndef VARIOGRAM_MAP_H
#define VARIOGRAM_MAP_H

#include <QDialog>

namespace Ui {
class Variogram_Map;
}

class Variogram_Map : public QDialog
{
    Q_OBJECT

public:
    explicit Variogram_Map(QWidget *parent = 0);
    ~Variogram_Map();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Variogram_Map *ui;
};

#endif // VARIOGRAM_MAP_H
