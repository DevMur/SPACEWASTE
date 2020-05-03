#include <QTimer>
#include <QTime>
#include <QGraphicsScene>
#include <QList>
#include <QThread>
#include <QCoreApplication>

#include "Megaleg.h"
#include "Enemy.h"
#include "Medium_Enemy.h"
#include "Hard_Enemy.h"
#include "Asteroid.h"
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
    if (this->y() < scene()->height()/6)
    {
        setPos(x(), y()+5.25); //turn 5 into 0 after testing
    }
}

void Megaleg::delay()
{
    QTime dieTime= QTime::currentTime().addSecs(3);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void Megaleg::attack_one()
{
    delay();

    Asteroid * wall_of_asteroids[8];
    for (int i = 0; i < 8; i++)
    {
        wall_of_asteroids[i] = new Asteroid();
        wall_of_asteroids[i]->for_boss = true;
        wall_of_asteroids[i]->setPos(i * 100, y());
        scene()->addItem(wall_of_asteroids[i]);

    }
}
