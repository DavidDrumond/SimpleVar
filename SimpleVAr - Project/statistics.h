#ifndef STATISTICS_H
#define STATISTICS_H

#include <QDialog>

namespace Ui {
class statistics;
}

class statistics : public QDialog
{
    Q_OBJECT

public:
    explicit statistics(QWidget *parent = 0);
    ~statistics();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::statistics *ui;
};

#endif // STATISTICS_H
