#ifndef ABRIR_ARQUIVO_H
#define ABRIR_ARQUIVO_H

#include <QDialog>

namespace Ui {
class abrir_arquivo;
}

class abrir_arquivo : public QDialog
{
    Q_OBJECT

public:
    explicit abrir_arquivo(QWidget *parent = 0);
    ~abrir_arquivo();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();


private:
    Ui::abrir_arquivo *ui;
};

#endif // ABRIR_ARQUIVO_H
