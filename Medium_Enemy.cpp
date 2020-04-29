#include "Medium_Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include <QtMath>
// rand() -> really large int
#include "Game.h"

extern Game * game;

Medium_Enemy::Medium_Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    //set random x position
    int random_number = rand() % 700; //size of display
    setPos(random_number,0);

    setPixmap(QPixmap(":/images/e2.jpeg")); //now it's a crug
    setTransformOriginPoint(50,50); //they can either have bigger badder versions
    setRotation(180);
    setScale(0.05);

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move_medium()));
    timer->start(50);
    //switcher=1;
    switcher = rand()%3;
}

void Medium_Enemy::move_medium(){

    if (this->switcher == 0)
    {
        if (this->x() >= game->player->x()+50)
        {
            setPos(x()-5,y()+1);
        }
        else
        {
            setPos(x()+5,y()+1);
        }
    }
    else if (this->switcher == 1)
    {
        if (((this->y() > 0 && this->y() <= 10) ||
            (this->y() > 200 && this->y() <= 300) ||
            (this->y() > 400 && this->y() <= 500) ||
            (this->y() > 600 && this->y() <= 700) ||
            (this->y() > 800 && this->y() <= 900))
            && this->x()+5 <= 800)
        {
            setPos(x()+5,y()+5);
        }
        else
        {
            if (this->x()-5 <= 0)
            {
                setPos(x(),y()+5);
            }
            else
            {
                setPos(x()-5,y()+5);
            }
        }
    }
    else if (this->switcher == 2)
    {
        if (this->x() < scene()->width()/3 && this->y() < scene()->height()/3)
        {
            setPos(x()+7,y()+7);
        }
        else if (this->x() > scene()->width()/3 && this->x() < scene()->width()/3*2 && this->y() < scene()->height()/3)
        {
            setPos(x(),y()+7);
        }
        else if (this->y() > scene()->height()/3 && this->y() > scene()->height()/3*2)
        {
            setPos(x()-7,y()+7);
        }
        else
        {
            setPos(x(),y()+10);
        }
    }
    // destroy enemy when it goes out of the screen
    if (pos().y() > 800){
        scene()->removeItem(this);
        delete this;
    }
}
