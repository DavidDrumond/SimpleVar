#ifndef DISTANCIA_H
#define DISTANCIA_H

#include <QDialog>

namespace Ui {
class Distancia;
}

class Distancia : public QDialog
{
    Q_OBJECT

public:
    explicit Distancia(QWidget *parent = 0);
    ~Distancia();

private:
    Ui::Distancia *ui;
};

#endif // DISTANCIA_H
