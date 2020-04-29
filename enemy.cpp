#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>

#include "Enemy.h"
#include "Game.h"

extern Game * game;

Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

    //set random x position
    int random_number = rand() % 800; //size of display
    setPos(random_number,0);

    setPixmap(QPixmap(":/images/Crug.png")); //now it's a L1 enemy
    setTransformOriginPoint(50,50); //they can either have bigger badder versions
    setRotation(180);
    setScale(0.05);

    // make/connect a timer to move the enemy every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move_easy()));

    // start the timer
    timer->start(50);
}

void Enemy::move_easy()
{
    setPos(x(),y()+5);

    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        //qDebug("condition wrong");
        if (typeid(*(colliding_items[i])) == typeid(Player))
        {
            if (game->health->getHealth()-1 == -1)
            {
                //TODO:End game
            }
            qDebug("HIT");
            game->health->decrease();
            scene()->removeItem(this);
            delete this;
            break;
        }
    }

    // destroy enemy when it goes out of the screen
    if (pos().y() > 800){
        scene()->removeItem(this);
        delete this;
    }
}


