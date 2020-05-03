#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>

#include "Enemy.h"
#include "Game.h"

extern Game * game;

Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

    if (game->endGame == false)
    {
        int random_number = rand() % 800;
        setPos(random_number,0);

        setPixmap(QPixmap(":/images/Crug.png"));
        setTransformOriginPoint(50,50);
        setRotation(180);
        setScale(0.05);

        QTimer * timer = new QTimer(this);
        connect(timer,SIGNAL(timeout()),this,SLOT(move_easy()));
        timer->start(50);
    }
}

void Enemy::move_easy()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        if (typeid(*(colliding_items[i])) == typeid(Player))
        {
            game->health->decrease();

            if (game->health->getHealth() == 0)
            {
                game->GameOver();
            }
            scene()->removeItem(this);
            delete this;
            break;
        }
    }
    if (game->endGame == true && this->y() < 300)
    {
        setPos(200, y()+5);
    }
    else if (game->endGame == false && for_boss == false)
    {
        setPos(x(),y()+5);
    }
    else if (for_boss == true && game->endGame == false)
    {
        if (this->y() < 400)
        {
            setPos(x(), y()+5);
        }
    }

    if (pos().y() > 800){
        scene()->removeItem(this);
        delete this;
    }
}


