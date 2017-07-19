#ifndef SUGERIR_LAG_H
#define SUGERIR_LAG_H

#include <QDialog>

namespace Ui {
class sugerir_lag;
}

class sugerir_lag : public QDialog
{
    Q_OBJECT

public:
    explicit sugerir_lag(QWidget *parent = 0);
    ~sugerir_lag();

private slots:
    void on_pushButton_clicked();

private:
    Ui::sugerir_lag *ui;
};

#endif // SUGERIR_LAG_H
