#include <QTimer>
#include <QGraphicsScene>
#include <QList>

#include "Megaleg.h"
#include "Game.h"

extern Game * game;

Megaleg::Megaleg(QGraphicsItem *parent)
{
    //int xpos = scene()->width()/2;
    setPos(300, 0);
//qDebug("created");
    setPixmap(QPixmap(":/images/Megaleg.jpeg"));
    setTransformOriginPoint(50,50);
    setScale(0.25);
//qDebug("almost created");
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(movement()));
    timer->start(50);

//qDebug("actually created");
}

void Megaleg::movement()
{
    //qDebug("moving");
    if (this->y() < scene()->height()/3)
    {
        setPos(x(), y()+0.25);
    }
}
