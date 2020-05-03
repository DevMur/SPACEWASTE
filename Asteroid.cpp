#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>

#include "Asteroid.h"
#include "Game.h"

extern Game * game;

Asteroid::Asteroid(QGraphicsItem *parent)
{
    for_boss = false;
    if (game->endGame == false)
    {
        int random_number = rand() % 800;
        setPos(random_number,0);

        setPixmap(QPixmap(":/images/asteroid.jpeg"));
        setTransformOriginPoint(50,50);
        setRotation(180);
        setScale(0.25);


        QTimer * timer = new QTimer(this);
        connect(timer,SIGNAL(timeout()),this,SLOT(move_asteroid()));
        timer->start(100);
    }
}

void Asteroid::move_asteroid()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        if (typeid(*(colliding_items[i])) == typeid(Player))
        {
            qDebug("BIG HIT");
            game->GameOver();
            scene()->removeItem(this);
            delete this;
            break;
        }
    }

    if(for_boss == false){setPos(x(),y()+1);}
    else
    {
        int lrc = rand()%3;
        if (lrc == 0)
        {
            setPos(x()-2.5,y()+5);
        }
        else if (lrc == 1)
        {
            setPos(x()+2.5,y()+5);
        }
        else
        {
            setPos(x(), y()+7.5);
        }
    }

    if (pos().y() > 800)
    {
        scene()->removeItem(this);
        delete this;
    }
}



