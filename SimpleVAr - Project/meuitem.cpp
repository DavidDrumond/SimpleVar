#include "meuitem.h"
#include "mainwindow.cpp"
#include <QBrush>

/*

meuitem::meuitem()
{
    angle = qrand()%360;
    setRotation(angle);
    speed =5;
    int StartX = 0;
    int StartY = 0;

    if (qrand()%1)
    {
        StartX = qrand()%200;
        StartY = qrand()%200;
    }
    else{

            StartX = qrand()%-100;
            StartY = qrand()%-100;

    }
    setPos(mapToParent(StartX,StartY));


}

QRectF meuitem::boundingRect() const
{
    return QRect(0,0,20,20);
}

void meuitem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    QRectF rect = boundingRect();
    QBrush Brush(Qt::gray);

    if (scene()->collidingItems(this).isEmpty()){
        Brush.setColor(Qt::gray);
    }
    else{
        Brush.setColor(Qt::green);
        Docollision();
    }
    painter->fillRect(rect,Brush);
    painter->drawRect(rect);

}

void meuitem::advance(int phase)
{
    if(!phase) return;
    QPointF location = this->pos();
    setPos(mapToParent(0,-speed));

}

void meuitem::Docollision()
{

}

*/
