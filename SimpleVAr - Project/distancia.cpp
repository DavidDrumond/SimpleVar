#include "distancia.h"
#include "ui_distancia.h"

Distancia::Distancia(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Distancia)
{
    ui->setupUi(this);
}

Distancia::~Dialog()
{
    delete ui;
}
