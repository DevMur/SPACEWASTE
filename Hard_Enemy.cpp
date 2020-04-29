#include "Hard_Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> // rand() -> really large int
#include "Game.h"

extern Game * game;


//this needs a timer check.
Hard_Enemy::Hard_Enemy(QGraphicsItem *parent){

    int random_number = rand() % 700; //size of display
    setPos(random_number,0);

    setPixmap(QPixmap(":/images/e3.png")); //now it's a crug
    setTransformOriginPoint(50,50); //they can either have bigger badder versions
    setRotation(180);
    setScale(0.05);

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move_hard()));
    timer->start(50);
    //switcher = 2;
    attack_pattern = rand()%3;
}

void Hard_Enemy::move_hard(){
    if (attack_pattern == 0)
    {
        if (this->x() > game->player->x())
        {
            setPos(x()-7.5,y()+7.5);
        }
        else
        {
            setPos(x()+7.5,y()+7.5);
        }
    }
    else if (attack_pattern == 1)
    {
        if (this->y() >= (scene()->height()/4)-10 && this->y() <= (scene()->height()/4)+10)
        {
            if (this->x() > game->player->x())
            {
                setPos(x()-10,y()+0.25);
            }
            else
            {
                setPos(x()+10,y()+0.25);
            }
        }
        else
        {
            setPos(x(),y()+30);
        }
    }
    else if (attack_pattern == 2)
    {
        if (this->left == -1)
        {
            if (this->x() > 400)
            {
                this->left = 1;
            }
            else
            {
                this->left = 0;
            }
        }
        else
        {
            if (left)
            {
                setPos(x()-5,y()+20);
            }
            else
            {
                setPos(x()+5,y()+20);
            }
        }
    }

    // destroy enemy when it goes out of the screen
    if (pos().y() > 800){
        scene()->removeItem(this);
        delete this;
    }
}
